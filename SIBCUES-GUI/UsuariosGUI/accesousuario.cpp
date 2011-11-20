#include "accesousuario.h"
#include "ui_accesousuario.h"
#include "../gestionUsuarios/libs/md5wrapper.h"
#include <iostream>
#include <string>
#include <QMessageBox>

using namespace std;

AccesoUsuario::AccesoUsuario(basico::Registro *_registroBasico, QMainWindow *ventanaprin, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::AccesoUsuario)
{
    m_ui->setupUi(this);    
    this->aceptado=false;    
    this->registroBasico=_registroBasico;
    this->ventana=ventanaprin;
    m_ui->login->setFocus();
}

AccesoUsuario::~AccesoUsuario()
{
    delete m_ui;
}

bool AccesoUsuario::getAceptado(){
    return this->aceptado;
}

void AccesoUsuario::on_boton_accepted(){
    this->login= m_ui->login->text().toStdString();
    //this->password= m_ui->password->text().toStdString();
    md5wrapper md5;
    std::string temp = md5.getHashFromString(m_ui->password->text().toStdString());

    std::cout << "Clave-->"<< temp;

    this->password=temp;

    if(this->registroBasico->logear(this->login, this->password)){
        m_ui->login->clear();
        m_ui->password->clear();
        aceptado=true;        
        this->close();
        this->ventana->setWindowTitle(QString("Sistema de Inventario -")+QString(this->registroBasico->getNombreUnidad().c_str())+QString("- Bienvenido/a ")+
                                      QString(this->registroBasico->getNombre().c_str())+QString(" ")+
                                      QString(this->registroBasico->getApellido().c_str()));
    }
    else{        
        m_ui->login->clear();
        m_ui->password->clear();        

         QMessageBox msgBox;
         msgBox.setText("No se encontro el usuario, o se ha ingresado una contraseña incorrecta.");
         msgBox.exec();
    }
}

void AccesoUsuario::on_boton_rejected (){    
    m_ui->login->clear();
    m_ui->password->clear();
    this->close();
    //this->parentWidget()->close();
}

void AccesoUsuario::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
