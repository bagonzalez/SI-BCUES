#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableView>
#include <QTableWidgetItem>
#include "libs/md5wrapper.h"

using namespace std;

#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"


MainWindow::MainWindow(int idUnidad, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

    Persistencia::Persistencia *servicioPersistencia=new Persistencia(idUnidad);
    servicioPersistencia->crearConexion();


    QSqlQuery consulta("SELECT nombreUnidad FROM unidad", QSqlDatabase::database("sibcues"));
    QStringList unidades;
    QStringList roles;
    roles << "administrador" << "contador" << "tecnico";
    while (consulta.next()) {
         QVariant o(consulta.value(0).toString());
         unidades << o.toString();
    }
    ui->setupUi(this);
    ui->comboBox->addItems(unidades);
    ui->comboBox_2->addItems(roles);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    QString nombre, apellido, login, password, passwordC,unidad, rol;
    login=ui->loginLine->text();
    password=ui->passLine->text();
    passwordC=ui->passCLine->text();
    nombre=ui->nameLine->text();
    apellido=ui->lasNLine->text();
    unidad=ui->comboBox->currentText();
    rol=ui->comboBox_2->currentText();
    if(login.isEmpty()){
        QMessageBox::critical(this,tr("Login"),tr("Ingrese el login"),QMessageBox::Ok);
    }else{
        QString consulta, cmpLogin;
        consulta="SELECT login FROM usuario WHERE login= ";
        consulta+="'";consulta+=login;consulta+="';";
        QSqlQuery query(consulta,  QSqlDatabase::database("sibcues"));
        while (query.next()) {
            QVariant o(query.value(0).toString());
            cmpLogin=o.toString();
        }
        if(login==cmpLogin){
            QMessageBox::critical(this,tr("Login"),tr("Esa sesion ya esta en uso,\nutilize otra porfavor"),QMessageBox::Ok);
        }else{

        if(nombre.isEmpty()){
            QMessageBox::critical(this,tr("Nombre"),tr("Ingrese el nombre del usuario"),QMessageBox::Ok);
        }else{
            if(apellido.isEmpty()){
                QMessageBox::critical(this,tr("Apellido"),tr("Ingrese el apellido del usuario"),QMessageBox::Ok);
            }else{
                if(password.isEmpty()){
                    QMessageBox::critical(this,tr("Contrasena"),tr("Debe de ingresar una contrasena"),QMessageBox::Ok);
                }else{
                    if(passwordC.isEmpty()){
                        QMessageBox::critical(this,tr("Confirmacion"),tr("Debe de confirmar la contrasena"),QMessageBox::Ok);
                    }else{
                        if(password!=passwordC){
                            QMessageBox::critical(this,tr("Contrasena Erronea"),tr("La contrasena no coincide,\nVerifique porfavor"),QMessageBox::Ok);
                        }else{
                            QString idUnidad, ingresarUsuario, consulta;
                            md5wrapper md5;
                            std::string temp = md5.getHashFromString(password.toStdString());            
                            QString passDB=temp.c_str();
                            consulta="SELECT idUnidad FROM unidad WHERE nombreUnidad= ";
                            consulta+="'";consulta+=unidad;consulta+="';";
                            QSqlQuery query(consulta,  QSqlDatabase::database("sibcues"));
                            while (query.next()) {
                                QVariant o(query.value(0).toString());
                                idUnidad=o.toString();
                            }
                            ingresarUsuario="INSERT INTO usuario(nombre, apellido, login, contrasenia, idUnidad, rol) VALUES(";
                            ingresarUsuario+="'",ingresarUsuario+=nombre,ingresarUsuario+="','";
                            ingresarUsuario+=apellido,ingresarUsuario+="','";
                            ingresarUsuario+=login,ingresarUsuario+="','";
                            ingresarUsuario+=passDB,ingresarUsuario+="',";
                            ingresarUsuario+=idUnidad,ingresarUsuario+=",'";
                            ingresarUsuario+=rol,ingresarUsuario+="');";
                            QSqlQuery ingresando(ingresarUsuario,  QSqlDatabase::database("sibcues"));
                            QMessageBox::information(this,tr("Ingreso Exitoso"),tr("El usuario fue ingresado exitosamente"),QMessageBox::Ok);
                            ui->loginLine->clear();
                            ui->passLine->clear();
                            ui->passCLine->clear();
                            ui->nameLine->clear();
                            ui->lasNLine->clear();
                        }
                    }
                    }
                }
            }
        }
    }
}

void MainWindow::on_pushButton_2_clicked(){
    ui->loginLine->clear();
    ui->passLine->clear();
    ui->passCLine->clear();
    ui->nameLine->clear();
    ui->lasNLine->clear();

    this->close();
}

void MainWindow::on_pushButton_3_clicked(){
    int row=ui->tableWidget_2->rowCount();
    if(row!=0){
        while(row!=0)
        {
            ui->tableWidget_2->removeRow(row);
            row--;
        }
    }
    QString consultaUsuario,login,nombre,apellido,idUnidad,rol, consultaUnidad;
    consultaUsuario="SELECT login,nombre,apellido,idUnidad,rol FROM usuario;";
    QSqlQuery query(consultaUsuario,  QSqlDatabase::database("sibcues"));
    while (query.next()) {
        login=query.value(0).toString();
        nombre=query.value(1).toString();
        apellido=query.value(2).toString();
        idUnidad=query.value(3).toString();
        rol=query.value(4).toString();

        ui->tableWidget_2->insertRow(row);

        QTableWidgetItem *itemLogin = new QTableWidgetItem(login);
        ui->tableWidget_2->setItem(row,0,itemLogin);
        QTableWidgetItem *itemNombre = new QTableWidgetItem(nombre);
        ui->tableWidget_2->setItem(row,1,itemNombre);
        QTableWidgetItem *itemApellido = new QTableWidgetItem(apellido);
        ui->tableWidget_2->setItem(row,2,itemApellido);
        consultaUnidad="SELECT nombreUnidad FROM unidad WHERE idUnidad= ";
        consultaUnidad+="'";consultaUnidad+=idUnidad;consultaUnidad+="';";
        QSqlQuery queryUnidad(consultaUnidad,  QSqlDatabase::database("sibcues"));
        while (queryUnidad.next()) {
            QVariant o(queryUnidad.value(0).toString());
            QTableWidgetItem *itemUnidad = new QTableWidgetItem(o.toString());
            ui->tableWidget_2->setItem(row,3,itemUnidad);
        }
        QTableWidgetItem *itemRol= new QTableWidgetItem(rol);
        ui->tableWidget_2->setItem(row,4,itemRol);
        row++;
        ui->tableWidget_2->setRowCount(row);
    }
}

void MainWindow::on_pushButton_4_clicked(){
    QTableWidgetItem *delUser= ui->tableWidget_2->item(ui->tableWidget_2->currentRow(),0);
    QString userDel = delUser->text();
    QString delQuery;
    delQuery = "DELETE FROM usuario WHERE login = '";
    delQuery+=userDel,delQuery+="';";
    QSqlQuery queryDel(delQuery,  QSqlDatabase::database("sibcues"));
    ui->tableWidget_2->removeRow(ui->tableWidget_2->currentRow());
    QMessageBox::information(this,tr("Eliminacion exitosa"),tr("El usuario fue eliminado exitosamente"),QMessageBox::Ok);
}
