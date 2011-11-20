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


void Persistencia::guarda(moduloinventario::IngresoClaseCatalogo *ingreso){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    QDateTime HoraFecha=QDateTime::currentDateTime();

    Fecha *fech=ingreso->fechaIngreso;
    Tiempo *tiempo=ingreso->horaIngreso;

    HoraFecha.setDate(QDate::QDate(fech->getAnio(), fech->getMes(), fech->getDia()));
    HoraFecha.setTime(QTime::QTime(tiempo->hora, tiempo->minutos, 0, 0));

    query.prepare("INSERT INTO admin_ingresoclase( idUsuario, fechaIngreso, horaIngreso)" "VALUES (:idUsuario, :fechaIngreso, :horaIngreso);");
    query.bindValue(":idUsuario", QString::number(ingreso->usuario->id));
    query.bindValue(":fechaIngreso",  HoraFecha.date().toString(Qt::ISODate) );
    query.bindValue(":horaIngreso",HoraFecha.time().toString(Qt::ISODate));
    query.exec();
}

void Persistencia::actualizar(moduloinventario::IngresoClaseCatalogo *ingreso, EspecificacionBien *espec){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    string SQL;

    query.clear();

    query.prepare("INSERT INTO especbien( descripcionClase, nombreclase, idEspecCuenta)" "VALUES (:descripcionClase, :nombreclase, :idEspecCuenta);");
    query.bindValue(":descripcionClase", QString::fromStdString(espec->clase->cuentaAsignada->getDescripcion()));
    query.bindValue(":nombreclase", QString::fromStdString(espec->clase->nombreClase));
    query.bindValue(":idEspecCuenta", QString::number(espec->clase->cuentaAsignada->id));
    query.exec();


    query.clear();
    SQL="SELECT LAST_INSERT_ID() FROM `n` LIMIT 1;";
    query.exec(QString(SQL.c_str()));
    while (query.next()){
         espec->oid_especbien=query.value(0).toString().toInt();
    }
    query.clear();
    query.exec("UPDATE admin_ingresoclase set idEspec="+QString::number(espec->oid_especbien)+" WHERE idIngresoClase ="+QString::number(ingreso->oid));
}



QMap<QString, QString> Persistencia::getListaBienesInvBiblio(QString anio, QString clase){

    QMap<QString, QString> mapa;
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    QString SQL;

    SQL=" SELECT espec.idEspec, nombreClase, correlativo, descripcionClase from "
    " bienbibliografico bbli "
    " join especbien  espec on bbli.idEspec=espec.idEspec "
    " join invmatbiblio invmb on bbli.idInvBiblio=invmb.idInVBiblio "
    " join inventario inv on invmb.idinventario=inv.idinventario "
    " where anioInventario='"+anio +"'"
    " and nombreClase='"+clase+"'"
    " and estadoBien='activo' "
    " order by nombreClase; ";

    query.exec(SQL);

    QString correlativo;
    while (query.next()){
        clase=query.value(1).toString();
        correlativo=query.value(2).toString();
        mapa.insert(correlativo, clase);
    }

    return mapa;
}



