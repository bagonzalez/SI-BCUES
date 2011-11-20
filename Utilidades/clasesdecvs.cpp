#include "clasesdecvs.h"
#include "ui_clasesdecvs.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <iostream>
#include <QTextStream>
#include <QStringList>
#include <QFile>
#include <QDate>

clasesdecvs::clasesdecvs(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::clasesdecvs)
{
    ui->setupUi(this);

        QSqlDatabase db =QSqlDatabase::addDatabase("QMYSQL");


         db.setHostName("localhost");
         db.setPort(3306);
         db.setDatabaseName("sibcuesv2");
         db.setUserName("root");
         db.setPassword("");
         db.open();






         //****************************************************************************************
         //** Utilizado para poder cargar el catalogo de activo fijo
         //** Se carga la cuenta de inventario a la que haran referencia las distintas cuentas
         //****************************************************************************************

         /*

         QSqlQuery consulta;
         consulta.exec("SELECT idEspecCuenta, nombreCuenta FROM especcuenta WHERE tipocuenta='inventario'");

         while(consulta.next()){             
             ui->comboBox->addItem(consulta.value(1).toString(), consulta.value(0).toInt());
         }*/

         //*****************************************************************************************
         //** Hasta aqui el manejo del  catalogo de inventario
         //*****************************************************************************************
}

clasesdecvs::~clasesdecvs()
{
    delete ui;
}



void clasesdecvs::on_pushButton_clicked()
{
     //****************************************************************************************
     //** Utilizado para poder cargar el catalogo de activo fijo desde archivos de texto
     //** Se carga la cuenta de inventario a la que haran referencia las distintas cuentas
     //** NombreClase\tDecripcion
     //****************************************************************************************

     /*QSqlQuery consulta;
     QString seleccion=ui->comboBox->currentText();
     int idEspecCuenta;

     consulta.exec("SELECT idEspecCuenta FROM EspecCuenta WHERE nombreCuenta='"+seleccion+"' AND tipoCuenta='inventario';");
     while(consulta.next()){
         idEspecCuenta=consulta.value(0).toInt();
     }

     QFile file("AF12100.txt");
     file.open(QIODevice::ReadOnly);

     QTextStream in(&file);
     while (!in.atEnd()) {
         QString line = in.readLine();
         QStringList fields = line.split("\t");
         if (fields.size() >= 2) {

             QString clase = fields.takeFirst();
             QString descripcion = fields.takeFirst();
             if(!descripcion.isEmpty()){
                 std::cout << clase.toStdString() << descripcion.toStdString();

                 consulta.prepare("INSERT INTO especbien(nombreClase, descripcion, idEspecCuenta)" "VALUES(:nombreClase, :descripcion, :idEspecCuenta)");
                 consulta.bindValue(":nombreClase", clase);
                 consulta.bindValue(":descripcion", descripcion);
                 consulta.bindValue(":idEspecCuenta", idEspecCuenta );
                 consulta.exec();
             }
         }
     }*/

     //*****************************************************************************************
     //** Hasta aqui el manejo del  catalogo de inventario
     //*****************************************************************************************

     //****************************************************************************************
     //** Utilizado para poder cargar desde archivos de texto los nombres de autor
     //** En forma tabular debe de estructurara este archivo
     //** NombreAutor\tApellido\tNacimiento\tDefuncion
     //****************************************************************************************

     /*QSqlQuery consulta;
     QFile file("autor.txt");
     file.open(QIODevice::ReadOnly);

     QTextStream in(&file);

     while (!in.atEnd()) {
         QString line = in.readLine();
         QStringList fields = line.split("\t");
         if (fields.size() >= 1) {
             QString nombreAutor = fields.takeFirst();
             QString apellidoAutor = fields.takeFirst();
             QString nacimiento = fields.takeFirst();
             QString defuncion=fields.takeFirst();


             if((!nombreAutor.isEmpty()) && nombreAutor!="s/a" ){

                 QString apellidoNombre=nombreAutor;

                 if(!apellidoAutor.isEmpty())
                    apellidoNombre=nombreAutor+", "+apellidoAutor;


                 std::cout << apellidoNombre.toStdString();
                 consulta.prepare("INSERT INTO autor(nombreAutor, anioNacimiento, anioDefuncion)" "VALUES(:nombreAutor, :anioNacimiento, :anioDefuncion)");
                 consulta.bindValue(":nombreAutor", apellidoNombre);
                 consulta.bindValue(":anioNacimiento", nacimiento.toInt());
                 consulta.bindValue(":anioDefuncion", defuncion.toInt());
                 consulta.exec();
             }
         }
     }*/


    /*QString nombre="\"Bruno Alberto Gonzalez \"el chico\"\"";
         int tam=nombre.size();
         nombre.remove(tam-1, 1);
         nombre.remove(0, 1);
    //nombre.remove('"');
    ui->label->setText(nombre);*/

    //****************************************************************************
    // Introducir las relaciones de los titulos con autores
    //*****************************************************************************

     /*QSqlQuery consulta;
     QFile file("autorTituloSinDuplucados.txt");
     file.open(QIODevice::ReadOnly);

     QTextStream in(&file);

     int idAutor=0, idTitulo=-1;
     QString line;
     QStringList fields;
     QString tituloObra;
     QString apellidoAutor;
     QString nombreAutor;
     QString apellidoNombre;


     while (!in.atEnd()) {
         line = in.readLine();
         fields = line.split("\t");
         if (fields.size() >= 2) {

             tituloObra = fields.takeFirst();
             int tam=tituloObra.size();
             tituloObra.remove(tam-1, 1);
             tituloObra.remove(0, 1);

             apellidoAutor = fields.takeFirst();
             nombreAutor="";
             nombreAutor = fields.takeFirst();





                 if(nombreAutor.isEmpty())
                    apellidoNombre=apellidoAutor;
                 else
                    apellidoNombre=apellidoAutor+", "+nombreAutor;

                 if(apellidoAutor!="s/a"){
                     consulta.exec("SELECT idAutor FROM autor WHERE nombreAutor=\""+apellidoNombre+"\"");
                     while(consulta.next()){
                        idAutor=consulta.value(0).toInt();
                     }
                 }

                 consulta.clear();
                 consulta.exec("SELECT idTitulo FROM titulo WHERE tituloObra=\""+tituloObra+"\"");
                 while(consulta.next()){
                        idTitulo=consulta.value(0).toInt();
                 }

                 //********************
                 //Introducir un titulo
                 //********************

                //*if(idTitulo==-1){
                //     consulta.clear();
                //     consulta.prepare("INSERT INTO titulo(tituloObra)" "VALUES(:tituloObra)");
                //     consulta.bindValue(":tituloObra", tituloObra);
                //consulta.exec();

                //     consulta.clear();
                //     consulta.exec("SELECT LAST_INSERT_ID() FROM `titulo` LIMIT 1;");
                //     while (consulta.next()){
                //         idTitulo=consulta.value(0).toInt();
                //   }
                //}

                 consulta.clear();

                 consulta.prepare("INSERT INTO obrade(idAutor, idTitulo)" "VALUES(:idAutor, :idTitulo)");
                 consulta.bindValue(":idAutor", QString::number(idAutor));
                 consulta.bindValue(":idTitulo", QString::number(idTitulo));
                 consulta.exec();

                 std::cout << tituloObra.toStdString();                 

         }
     }*/

    //*****************************
    //Fin de relaciones y titulos
    //*****************************


     QSqlQuery consulta;
     QFile file("m5Modificado.txt");
     file.open(QIODevice::ReadOnly);

     QTextStream in(&file);


     QString line;
     QStringList fields;

     QString cuentaInventario;
     QString codigoUnidadP1;
     QString codigoUnidadP2;
     QString clase;
     QString correlativo;
     QString especifico;
     QString tituloObra;
     QString codInterno;
     QDate   fechaAdquisicion;
     QString   valor;
     QString codigoBien;

     int idSector=1;
     int idInventarioMat=1;
     int idEspecifico=363;

     int idTitulo=-1;
     int idEspecBien;


     while (!in.atEnd()) {

         line = in.readLine();
         fields = line.split("\t");

         if (fields.size() >= 2) {
             cuentaInventario=fields.takeFirst();
             codigoUnidadP1=fields.takeFirst();
             codigoUnidadP2=fields.takeFirst();
             clase=fields.takeFirst();
             correlativo=fields.takeFirst();
             especifico=fields.takeFirst();

             tituloObra = fields.takeFirst();
             int tam=tituloObra.size();
             tituloObra.remove(tam-1, 1);
             tituloObra.remove(0, 1);

             codInterno=fields.takeFirst();
             fechaAdquisicion=QDate::fromString(fields.takeFirst(), "dd/MM/yyyy");

             //ui->label->setText( fechaAdquisicion.toString(Qt::ISODate));

             valor=fields.takeFirst();

             codigoBien=cuentaInventario+"-"+codigoUnidadP1+"-"+codigoUnidadP2+"-"+clase+"-"+correlativo+"-"+especifico;

             consulta.exec("SELECT idEspec FROM EspecBien left join especcuenta on especbien.idEspeccuenta=especcuenta.idespeccuenta WHERE especcuenta.codigoCuenta='"+cuentaInventario+"' AND especbien.nombreClase='"+clase+"';");
             while(consulta.next()){
                 idEspecBien=consulta.value(0).toInt();
             }

             consulta.clear();
             consulta.exec("SELECT idTitulo FROM titulo WHERE tituloObra=\""+tituloObra+"\"");
             while(consulta.next()){
                        idTitulo=consulta.value(0).toInt();
             }


             consulta.clear();
             consulta.prepare("INSERT INTO bienbibliografico (idTitulo, idEspec, idInvBiblio, idEspecCuenta, idSector, fechaAdquisicion, valor, estadoBien, correlativo, codigo, codInterno)" "VALUES( :idTitulo, :idEspec, :idInvBiblio, :idEspecCuenta, :idSector, :fechaAdquisicion, :valor, :estadoBien, :correlativo, :codigo, :codInterno)");
             consulta.bindValue(":idTitulo", QString::number(idTitulo));
             consulta.bindValue(":idEspec", QString::number(idEspecBien));
             consulta.bindValue(":idInvBiblio", QString::number(idInventarioMat));
             consulta.bindValue(":idEspecCuenta", QString::number(idEspecifico));
             consulta.bindValue(":idSector", QString::number(idSector));

             consulta.bindValue(":fechaAdquisicion", fechaAdquisicion.toString(Qt::ISODate));
             consulta.bindValue(":valor", valor);
             consulta.bindValue(":estadoBien", "activo");
             consulta.bindValue(":correlativo", correlativo);
             consulta.bindValue(":codigo", codigoBien);
             consulta.bindValue(":codInterno", codInterno);

             consulta.exec();


         }
     }
}
