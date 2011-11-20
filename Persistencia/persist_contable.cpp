#include "persistencia.h"

#include <QFile>
#include <QTextStream>
#include <QSqlDatabase>
#include <QtGui/QMessageBox>
#include <QSqlError>
#include <QVariant>
#include <QString>
#include <QDate>
#include <iostream>
#include <QSqlQuery>

void Persistencia::guardarCatalogoContable(contabilidad::Catalogo *catalogo){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    QString SQL="SELECT idCatalogoContable FROM `CatalogoContable` WHERE idUnidad=";
    SQL+=QString::number(catalogo->unidad->id)+";";
    query.exec(QString(SQL));

     while (query.next()){
         catalogo->id=query.value(0).toString().toInt();
     }
}


void Persistencia::cargarCatalogoContable(contabilidad::Catalogo *catalogo, string tipocuentaMadre){
    QString id=QString::number(catalogo->unidad->id);
    QString SQL="SELECT `idCatalogoContable` FROM `catalogocontable` WHERE `idUnidad`="+id;

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    query.exec(SQL);

     while(query.next()){
         catalogo->id=query.value(0).toString().toInt();
     }

     query.clear();

     QString idCatalogo=QString::number(catalogo->id);

     SQL="SELECT especcuenta.nombreCuenta, especcuenta.descripcion, cuenta.idCuenta, especcuenta.codigoCuenta, cuenta.debe, cuenta.haber, especcuenta.tipoDestino FROM especcuenta LEFT JOIN cuenta ON especcuenta.idEspecCuenta=cuenta.idEspecCuenta WHERE `tipoCuenta`='"+QString::fromStdString(tipocuentaMadre)+"' AND cuenta.idCatalogoContable ="+idCatalogo;

     query.exec(SQL);
     string nombreRubro;

     bool nueva=false;
     while (query.next()){
         nombreRubro=query.value(0).toString().toStdString();
         catalogo->crearRubro(nombreRubro, query.value(1).toString().toStdString(), nueva, query.value(2).toString().toInt(), query.value(3).toString().toStdString(), query.value(6).toString().toStdString() );
     }
}



void Persistencia::cargarCuentas(contabilidad::Cuenta *cuenta, int idCatalogo){

    QSqlQuery query(QSqlDatabase::database("sibcues"));


    string SQL;

    SQL="SELECT cuenta.debe, cuenta.haber , especcuenta.codigoCuenta, especcuenta.nombreCuenta, especcuenta.descripcion, cuenta.idCuenta, especcuenta.tipoCuenta, especcuenta.tipoDestino FROM cuenta LEFT JOIN especcuenta ON especcuenta.idEspecCuenta=cuenta.idEspecCuenta WHERE `Cue_idCuenta` ="+QVariant::QVariant(cuenta->id).toString().toStdString()+" AND `idCatalogoContable` ="+QVariant::QVariant(idCatalogo).toString().toStdString();
    query.exec(QString(SQL.c_str()));

    string nombreSubcuenta;
    string codigo; int id;
    string descripcion, tipoCuenta, tipoDestino;
    float debe, haber;
    bool nueva=false;
    contabilidad::tipoDestino tipoDes;


     while (query.next()){
         debe=query.value(0).toString().toFloat();
         haber=query.value(1).toString().toFloat();
         codigo=query.value(2).toString().toStdString();
         nombreSubcuenta=query.value(3).toString().toStdString();
         descripcion=query.value(4).toString().toStdString();
         id=query.value(5).toString().toInt();
         tipoCuenta=query.value(6).toString().toStdString();
         tipoDestino=query.value(7).toString().toStdString();

         if(tipoDestino=="ingreso")
            tipoDes=contabilidad::ingreso;

         if(tipoDestino=="gasto")
            tipoDes=tipoDes=contabilidad::gasto;

         if(tipoCuenta=="rubro")
            cuenta->crearSubCuenta(nombreSubcuenta, contabilidad::rubro, codigo, descripcion, id, nueva, tipoDes);

         if(tipoCuenta=="cuenta")
            cuenta->crearSubCuenta(nombreSubcuenta, contabilidad::cuenta, codigo, descripcion, id, nueva, tipoDes);

         if(tipoCuenta=="especificos")
            cuenta->crearSubCuenta(nombreSubcuenta, contabilidad::especificos, codigo, descripcion, id, nueva, tipoDes);

         if(tipoCuenta=="inventario")
            cuenta->crearSubCuenta(nombreSubcuenta, contabilidad::inventario, codigo, descripcion, id, nueva, tipoDes);

         cuenta->getSubCuenta(nombreSubcuenta)->debe=debe;
         cuenta->getSubCuenta(nombreSubcuenta)->haber=haber;

         cuenta->setTipoDes();
     }
}


void Persistencia::guardarCuenta(contabilidad::Cuenta *cuenta){
    QSqlQuery query(QSqlDatabase::database("sibcues"));

    int idEspec=0;

    query.prepare("INSERT INTO especcuenta(codigoCuenta, nombreCuenta, descripcion, tipoCuenta, tipoDestino)" "VALUES (:codigoCuenta, :nombreCuenta, :descripcion, :tipoCuenta, :tipoDestino);");
    query.bindValue(":codigoCuenta", QString(cuenta->codigoCuenta.c_str()));
    query.bindValue(":nombreCuenta", QString::QString(cuenta->nombreCuenta.c_str()) );
    query.bindValue(":descripcion", QString::QString(cuenta->descripcion.c_str()));
    query.bindValue(":tipoCuenta", QString::QString(cuenta->tipoCuent.c_str()));
    query.bindValue(":tipoDestino", QString::QString(cuenta->tipoDestString.c_str()));
    query.exec();

    query.clear();
    string SQL="SELECT LAST_INSERT_ID() FROM `especcuenta` LIMIT 1;";
    query.exec(QString(SQL.c_str()));
    while (query.next()){
         idEspec=query.value(0).toString().toInt();
    }

    query.clear();
    query.prepare("INSERT INTO cuenta( idCatalogoContable, debe, haber, Cue_idCuenta, idEspecCuenta)" "VALUES (:idCatalogoContable, :debe, :haber, :Cue_idCuenta, :idEspecCuenta);");
    query.bindValue(":idCatalogoContable", QString::number(cuenta->myCatalogo->id));
    query.bindValue(":debe", QString::number(cuenta->debe) );
    query.bindValue(":haber",QString::number(cuenta->haber) );
    query.bindValue(":Cue_idCuenta", QString::number(cuenta->cuentaMadre->id));
    query.bindValue(":idEspecCuenta", QString::number(idEspec));
    query.exec();

    query.clear();
    SQL="SELECT LAST_INSERT_ID() FROM `cuenta` LIMIT 1;";
    query.exec(QString(SQL.c_str()));

    while (query.next()){
         cuenta->id=query.value(0).toString().toInt();
    }
}

void Persistencia::actualizarCuenta(contabilidad::Cuenta *cuenta){
        QSqlQuery query(QSqlDatabase::database("sibcues"));
        query.exec("UPDATE cuenta set debe="+QVariant::QVariant(cuenta->debe).toString()+" WHERE idCuenta ="+QString::number(cuenta->id)+";");
        query.exec("UPDATE cuenta set haber="+QVariant::QVariant(cuenta->haber).toString()+" WHERE idCuenta ="+QString::number(cuenta->id)+";");
}

void Persistencia::cargarSubcuentas(contabilidad::Subcuenta *cuenta){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    string SQL;

    if(cuenta->getTipoC()!=contabilidad::inventario)
    {

        SQL="SELECT cuenta.debe, cuenta.haber , especcuenta.codigoCuenta, especcuenta.nombreCuenta, especcuenta.descripcion, cuenta.idCuenta, especcuenta.tipoCuenta, especcuenta.tipoDestino FROM cuenta LEFT JOIN especcuenta ON cuenta.idEspecCuenta = especcuenta.idEspecCuenta WHERE `Cue_idCuenta` ="+QVariant::QVariant(cuenta->id).toString().toStdString()+" AND `idCatalogoContable` ="+QVariant::QVariant(cuenta->myCatalogo->id).toString().toStdString();
        query.exec(QString(SQL.c_str()));

        string nombreSubcuenta;
        string codigo; int id;
        string descripcion, tipoCuenta, tipoDestino;
        float debe, haber;
        bool nueva=false;
        contabilidad::tipoDestino tipoDes;

         while (query.next()){

             debe=query.value(0).toString().toFloat();
             haber=query.value(1).toString().toFloat();
             codigo=query.value(2).toString().toStdString();
             nombreSubcuenta=query.value(3).toString().toStdString();
             descripcion=query.value(4).toString().toStdString();
             id=query.value(5).toString().toInt();
             tipoCuenta=query.value(6).toString().toStdString();
             tipoDestino=query.value(7).toString().toStdString();

            if(tipoDestino=="ingreso")
               tipoDes=contabilidad::ingreso;

            if(tipoDestino=="gasto")
               tipoDes=contabilidad::gasto;

              if(tipoCuenta=="rubro")
                cuenta->crearSubCuenta(nombreSubcuenta, contabilidad::rubro, codigo, descripcion, id, nueva, tipoDes);

             if(tipoCuenta=="cuenta")
                cuenta->crearSubCuenta(nombreSubcuenta, contabilidad::cuenta, codigo, descripcion, id, nueva, tipoDes);

             if(tipoCuenta=="especificos")
                cuenta->crearSubCuenta(nombreSubcuenta, contabilidad::especificos, codigo, descripcion, id, nueva, tipoDes);

             if(tipoCuenta=="inventario")
                cuenta->crearSubCuenta(nombreSubcuenta, contabilidad::inventario, codigo, descripcion, id, nueva, tipoDes);

             cuenta->getSubCuenta(nombreSubcuenta)->debe=debe;
             cuenta->getSubCuenta(nombreSubcuenta)->haber=haber;

         }
    }
}

void Persistencia::guardarSubcuenta(contabilidad::Subcuenta *cuenta){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int idEspec=0;

    query.prepare("INSERT INTO especcuenta(codigoCuenta, nombreCuenta, descripcion, tipoCuenta, tipoDestino)" "VALUES (:codigoCuenta, :nombreCuenta, :descripcion, :tipoCuenta, :tipoDestino);");
    query.bindValue(":codigoCuenta", QString(cuenta->codigoCuenta.c_str()));
    query.bindValue(":nombreCuenta", QString::QString(cuenta->nombreCuenta.c_str()) );
    query.bindValue(":descripcion", QString::QString(cuenta->descripcion.c_str()));
    query.bindValue(":tipoCuenta", QString::QString(cuenta->tipoCuent.c_str()));
    query.bindValue(":tipoDestino", QString::QString(cuenta->tipoDestString.c_str()));
    query.exec();

    query.clear();
    string SQL="SELECT LAST_INSERT_ID() FROM `especcuenta` LIMIT 1;";
    query.exec(QString(SQL.c_str()));
    while (query.next()){
         idEspec=query.value(0).toString().toInt();
    }

    query.clear();
    query.prepare("INSERT INTO cuenta( idCatalogoContable, debe, haber, Cue_idCuenta, idEspecCuenta)" "VALUES (:idCatalogoContable, :debe, :haber, :Cue_idCuenta, :idEspecCuenta);");
    query.bindValue(":idCatalogoContable", QString::number(cuenta->myCatalogo->id));
    query.bindValue(":debe", QString::number(cuenta->debe) );
    query.bindValue(":haber",QString::number(cuenta->haber) );
    query.bindValue(":Cue_idCuenta", QString::number(cuenta->cuentaMadre->id));
    query.bindValue(":idEspecCuenta", QString::number(idEspec));
    query.exec();
    query.clear();
    SQL="SELECT LAST_INSERT_ID() FROM `cuenta` LIMIT 1;";
    query.exec(QString(SQL.c_str()));

    while (query.next()){
         cuenta->id=query.value(0).toString().toInt();
    }
}

void Persistencia::setID(contabilidad::Cuenta *cuenta){
     QSqlQuery query(QSqlDatabase::database("sibcues"));

     string SQL="SELECT LAST_INSERT_ID() FROM `cuenta` LIMIT 1;";
     query.exec(QString(SQL.c_str()));

     while (query.next()){
         cuenta->id=query.value(0).toString().toInt();
     }
}


