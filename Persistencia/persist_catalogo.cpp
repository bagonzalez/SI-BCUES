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

void Persistencia::cargarCatalogoAF(CatalogoActivoFijo *catalogo, int invAFijo){

    QSqlQuery query(QSqlDatabase::database("sibcues")), query2(QSqlDatabase::database("sibcues"));

    QString SQL;
    string descripcion, nombreClase, codigoCuenta;
    Cuenta *cuentaAsignada;
    moduloinventario::EspecificacionBien *especAF;
    int oidEspecBien;
    float cantidad=0;

    this->idInventarioActivoFijo=invAFijo;

    //SQL="CALL getEspecificacionBien()";
    SQL="SELECT especbien.nombreClase , especbien.descripcionClase, "
        " especbien.idEspec,  especcuenta.codigoCuenta FROM especbien "
        " LEFT JOIN especcuenta ON especbien.idEspecCuenta= especcuenta.idEspecCuenta; ";

    query.exec(SQL);

    while (query.next()){
        nombreClase=query.value(0).toString().toStdString();
        descripcion=query.value(1).toString().toStdString();
        oidEspecBien=query.value(2).toString().toInt();
        codigoCuenta=query.value(3).toString().toStdString();

        cuentaAsignada=this->regContable->getDireccionCuenta(codigoCuenta);
        cuentaAsignada->crearSubCuenta(nombreClase, contabilidad::inventario, "0", descripcion, oidEspecBien, false, contabilidad::ingreso);

        SQL=" SELECT SUM(bienactivofijo.valor) FROM  "
            "  especbien LEFT JOIN bienactivofijo ON bienactivofijo.idEspec=especbien.idEspec "
            "  LEFT JOIN invactivofijo ON invactivofijo.idInvAF=bienactivofijo.idInvAF "
            "  WHERE bienactivofijo.estadoBien='activo' "
            "  AND bienactivofijo.idEspec="+QString::number(oidEspecBien);

        //SQL=QString::QString("CALL getTotalEspecificacion(%1,  %2, @outval1)").arg(QString::number(this->idInventarioActivoFijo), QString::number(oidEspecBien));
        query2.exec(SQL);
        //query2.exec("select @outval1");

        while(query2.next()){
            cantidad=query2.value(0).toFloat();
        }

        if(cantidad==0){

            SQL=" SELECT SUM(bbiblio.valor) "
            " FROM especbien "
            " LEFT JOIN bienbibliografico bbiblio ON bbiblio.idEspec=especbien.idEspec "
            " LEFT JOIN invmatbiblio ON invmatbiblio.idInvBiblio=bbiblio.idInvBiblio "
            " WHERE bbiblio.estadoBien='activo' "            
            " AND bbiblio.idEspec="+QString::number(oidEspecBien);

            query2.clear();

            query2.exec(SQL);
            while(query2.next()){
                cantidad=query2.value(0).toFloat();
            }
        }



        cuentaAsignada->getSubCuenta(nombreClase)->cargarCuenta(cantidad);

        especAF=catalogo->regCatalogo->cargarEspec(cuentaAsignada, nombreClase);
        especAF->oid_especbien=oidEspecBien;
        especAF->setDescripcion(descripcion);

        cantidad=0;
    }
}



