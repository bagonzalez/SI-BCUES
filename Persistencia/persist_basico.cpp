#include "persistencia.h"
#include <QSqlQuery>

#include <QFile>
#include <QTextStream>
#include <QSqlDatabase>
#include <QtGui/QMessageBox>
#include <QSqlError>
#include <QVariant>
#include <QString>
#include <QDate>
#include <iostream>

void Persistencia::guardarUnidad( basico::Unidad *unidad){

     //*-*-*
     //Almacenamos en la base de datos la instancia unidad
     //*-*-*

     QString SQL;
     SQL= "INSERT INTO unidad (idUnidadP1 , idUnidadP2 ,  directorUnidad, jefaturaUnidad, nombreUnidad) VALUES ( '";
     SQL+=QString::fromStdString(unidad->codigoP1())+"', '";
     SQL+=QString::fromStdString(unidad->codigoP2())+"', '";
     SQL+=QString::fromStdString(unidad->director)+"', '";
     SQL+=QString::fromStdString(unidad->jefeAF)+"', '";
     SQL+=QString::fromStdString(unidad->getNombreUnidad())+"');";

     QSqlQuery(SQL, QSqlDatabase::database("sibcues"));     
         
     QSqlQuery query(QSqlDatabase::database("sibcues"));

     //*-*-*
     //Obtenemos el identificador en la tabla y lo guardamos
     //*-*-*

     SQL="SELECT LAST_INSERT_ID() FROM `unidad` LIMIT 1;";
     query.exec(QString(SQL));

     while (query.next()){
        unidad->id=query.value(0).toString().toInt();
     }

     //*-*-*-*
     //Procedemos a crear los distintos catalogos contables e inventarios que poseera la unidad
     //*-*-*-*

     query.clear();
     SQL="INSERT INTO `inventario` (`idUnidad`) VALUES ("+QString::number(unidad->id)+");";
     query.exec(SQL);

     SQL="SELECT LAST_INSERT_ID() FROM `inventario` LIMIT 1;";
     query.exec(QString(SQL));

     while (query.next()){
        unidad->idInventario=query.value(0).toString().toInt();
     }
     query.clear();


     SQL="INSERT INTO `invactivofijo` (`idInventario`) VALUES ("+QString::number(unidad->idInventario)+");";
     query.exec(SQL);

     query.clear();
     SQL="INSERT INTO `invmatbiblio` (`idInventario`) VALUES ("+QString::number(unidad->idInventario)+");";
     query.exec(SQL);


     SQL="INSERT INTO `catalogocontable` (`idUnidad`) VALUES ("+QString::number(unidad->id)+");";
     query.exec(SQL);
     SQL="SELECT LAST_INSERT_ID() FROM `catalogocontable` LIMIT 1;";
     query.exec(QString(SQL));

     while (query.next()){
        unidad->idCatalogo=query.value(0).toString().toInt();
     }
}

void Persistencia::cargarUnidad( basico::Unidad *unidad){

     string SQL;

     QString id=QString(QVariant::QVariant(unidad->id).toString());
     SQL="SELECT `idUnidadP1`, `idUnidadP2`, `nombreUnidad` FROM `unidad` WHERE `idUnidad`="+id.toStdString();
     QSqlQuery query(QSqlDatabase::database("sibcues", false));     

     query.exec(QString(SQL.c_str()));

     while (query.next()){
         unidad->setCodigo(query.value(0).toString().toStdString(), query.value(1).toString().toStdString());
         unidad->setNombreUnidad(query.value(2).toString().toStdString());
     }



     /*QSqlQuery query( QSqlDatabase::database("sibcues", false) );
     query.prepare("CALL getUnidad(?)");
     query.bindValue(0, unidad->id);

     if (!query.exec())
     {
          //qDebug() << "addstory() failed: " << query.lastError().text();
      }else{
          while (query.next()){
              unidad->setCodigo(query.value(0).toString().toStdString(), query.value(1).toString().toStdString());
              unidad->setNombreUnidad(query.value(2).toString().toStdString());
          }
      }*/


     this->registroBasico->setUnidad(unidad);


     query.clear();

     SQL="SELECT `idInventario` FROM `inventarioactivofijo` WHERE `idUnidad` ="+id.toStdString();
     query.exec(QString(SQL.c_str()));

     while (query.next()){
         unidad->idInventario=query.value(0).toInt();
     }


     query.clear();

     SQL="SELECT `nombre`, `apellido`, `login`, `contrasenia`, `rol`, `idUsuario` FROM `usuario` WHERE `idUnidad` ="+id.toStdString();
     query.exec(QString(SQL.c_str()));



     while (query.next()){         
         this->registroBasico->crearUsuario(query.value(0).toString().toStdString(), query.value(1).toString().toStdString(),
                                            query.value(2).toString().toStdString(), query.value(3).toString().toStdString(),
                                            query.value(4).toString().toStdString(),query.value(5).toInt());
     }

 }


void Persistencia::guardarUsuario( Usuario *usuario, int oidunidad)
{
    string SQL;

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    query.prepare("INSERT INTO usuario(nombre, apellido, login, contrasenia, idUnidad, rol )" "VALUES(:nombre, :apellido, :login, :contrasenia, :idUnidad, :rol)");
    query.bindValue(":nombre", QString(usuario->nombre.c_str()));
    query.bindValue(":apellido", QString( usuario->apellido.c_str() ));
    query.bindValue(":login", QString(usuario->login.c_str() ));
    query.bindValue(":contrasenia", QString(usuario->contrasenia.c_str()));
    query.bindValue(":idUnidad", QString::number(oidunidad));

    query.bindValue(":rol", QString(usuario->rolU.c_str()));
    query.exec();
}


