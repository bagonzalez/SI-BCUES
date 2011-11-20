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
#include <QMap>

Persistencia::Persistencia(int IDUnidad){
    this->IDUnidad=IDUnidad;
    this->crearConexion();    
}

Persistencia::Persistencia( Registro *registro)
{

    this->registroBasico=registro;
    this->crearConexion();
}

Persistencia::Persistencia(RegistroSistemaContable *regContable){
    this->IDUnidad=regContable->regBasico->getUnidad()->id;
    this->regContable=regContable;
    this->crearConexion();
}

Persistencia::Persistencia(RegistroCatalogo *regCatalogo){
    this->IDUnidad=regCatalogo->usuario->unidad->id;
    this->regCatalogo=regCatalogo;
}



void Persistencia::setID(moduloinventario::IngresoClaseCatalogo *ingreso){
     QSqlQuery query(QSqlDatabase::database("sibcues"));

     string SQL="SELECT LAST_INSERT_ID() FROM `admin_ingresoclase` LIMIT 1;";
     query.exec(QString(SQL.c_str()));

     while (query.next()){
         ingreso->oid=query.value(0).toString().toInt();
     }
}


QList<QString>  Persistencia::getListaCorelativosDisponiblesAF(int idEspec){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    QString SQL, correlativoString;

    QList<QString> listaCorrelativosNoAsignado;

    SQL="SELECT bienactivofijo.correlativo FROM bienactivofijo WHERE  idInvAF="+QString::number(this->idInventarioActivoFijo)+" AND idEspec="+QString::number(idEspec);
    query.exec(SQL);


    for(int i=1; i<=9999 ; i++){
        if(i%10000>0 && i/10000==0){
             correlativoString=QString::number(i);
         }

         if(i%1000>0  && i/1000==0){
             correlativoString="0"+QString::number(i);
         }

         if(i%100>0 && i/100==0 ){
             correlativoString="00"+QString::number(i);
         }

         if(i%10>0 && i/10==0 ){
             correlativoString="000"+QString::number(i);
         }
         listaCorrelativosNoAsignado.push_back(correlativoString);
    }

    while(query.next()){
        listaCorrelativosNoAsignado.removeOne(query.value(0).toString());
    }

    /*for (int i = 0; i < listaCorrelativosNoAsignado.size(); ++i){
        std::cout << listaCorrelativosNoAsignado.at(i).toStdString() << endl;
    }*/

    return listaCorrelativosNoAsignado;
}

QList<QString>  Persistencia::getListaCorelativosDisponiblesMB(int idEspec){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    QString SQL, correlativoString;

    QList<QString> listaCorrelativosNoAsignado;

    SQL="SELECT bienbibliografico.correlativo FROM bienbibliografico WHERE  idInvBiblio="+QString::number(this->idInventarioBibliografico)+" AND correlativo NOT LIKE 'Asign.'   AND idEspec="+QString::number(idEspec);
    query.exec(SQL);


    for(int i=1; i<=99999 ; i++){

        if(i%100000>0 && i/100000==0){
            correlativoString=QString::number(i);
        }


        if(i%10000>0 && i/10000==0){
            correlativoString="0"+QString::number(i);
        }

         if(i%1000>0 && i/1000==0){
             correlativoString="00"+QString::number(i);
         }

         if(i%100>0  && i/100==0){
             correlativoString="000"+QString::number(i);
         }

         if(i%10>0 && i/10==0 ){
             correlativoString="0000"+QString::number(i);
         }

         listaCorrelativosNoAsignado.push_back(correlativoString);

         std::cout << correlativoString.toStdString();


    }

    while(query.next()){
        listaCorrelativosNoAsignado.removeOne(query.value(0).toString());
    }

    /*for (int i = 0; i < listaCorrelativosNoAsignado.size(); ++i){
        std::cout << listaCorrelativosNoAsignado.at(i).toStdString() << endl;
    }*/

    return listaCorrelativosNoAsignado;
}






std::map<int, string> Persistencia::cargarSectores(){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    std::map<int, string> listaSectores;


    QString SQL="SELECT `idSector`, `descripcionSector`  FROM `sectores` WHERE sectores.idUnidad="+QString::number(this->IDUnidad);
    query.exec(SQL);
    while (query.next()){
          listaSectores[query.value(0).toInt()]=query.value(1).toString().toStdString();
    }
    return listaSectores;
}

std::map<int, string> Persistencia::cargarProveedores(){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    std::map<int, string> listaProveedores;

    string SQL="SELECT `idProveedor`, `nombreProveedor`  FROM `Proveedor`";
    query.exec(SQL.c_str());
    while (query.next()){
          listaProveedores[query.value(0).toInt()]=query.value(1).toString().toStdString();
    }
    return listaProveedores;
}

int Persistencia::guardarIngresoBienes(QString FechaIngreso, QString proveedor, QString noCEF, QString facturaProveedor, QString fechaFactura, QString noCSU , QString fechaCSU, QString fuentedeFondos, QString observaciones, QString tipoBien, QString HoraIngreso, QString estadoIngreso, QString codigoIngreso){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int idProveedor=0, idIng=0;

    QString SQL="SELECT idProveedor FROM Proveedor WHERE nombreProveedor='"+proveedor+"';";
    query.exec(SQL);
    while (query.next()){
          idProveedor=query.value(0).toInt();
    }
    
    if(idProveedor==0){
       query.clear();
       query.exec("INSERT INTO Proveedor (nombreProveedor) VALUES ('"+proveedor+"');");

        query.clear();
        SQL="SELECT LAST_INSERT_ID() FROM `proveedor` LIMIT 1;";
        query.exec(QString(SQL));
        while (query.next()){
                 idProveedor=query.value(0).toString().toInt();
        }
    }

    SQL="INSERT INTO ingresobienes (idInventario, idProveedor, fechaIngreso, cefNo, facturaNo, fechaFactura, acuerdoCSU_NO, fechaAcuerdo, fuenteIngreso, observaciones, tipoBienIngresado, estadoIngreso, horaIngreso, codigoIngreso)  VALUES (";
    SQL+=QString::number(this->idInventarioGeneral), SQL+=",";
    SQL+=QString::number(idProveedor), SQL+=",";
    SQL+="'",SQL+=FechaIngreso,SQL+="',";
    SQL+="'",SQL+=noCEF,SQL+="',";
    SQL+="'",SQL+=facturaProveedor,SQL+="',";
    SQL+="'",SQL+=fechaFactura,SQL+="',";
    SQL+="'",SQL+=noCSU,SQL+="',";
    SQL+="'",SQL+=fechaCSU,SQL+="',";
    SQL+="'",SQL+=fuentedeFondos,SQL+="',";
    SQL+="'",SQL+=observaciones,SQL+="',";
    SQL+="'",SQL+=tipoBien,SQL+="',";
    SQL+="'",SQL+=estadoIngreso,SQL+="',";
    SQL+="'",SQL+=HoraIngreso,SQL+="',";
    SQL+="'",SQL+=codigoIngreso,SQL+="');";
    query.exec(SQL);

    std::cout << endl << SQL.toStdString() << endl;
    QSqlError error=query.lastError();
    std::cout << error.text().toStdString();

     query.clear();
     SQL="SELECT LAST_INSERT_ID() FROM `ingresobienes` LIMIT 1;";
     query.exec(QString(SQL));
     while (query.next()){
                 idIng=query.value(0).toString().toInt();
     }
     return idIng;
}


void Persistencia::actualizarIngresoBienes(int idIngreso, QString proveedor, QString noCEF, QString facturaProveedor, QString fechaFactura, QString noCSU , QString fechaCSU, QString fuentedeFondos, QString observaciones, QString estadoIngreso, QString codigoIngreso){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int idProveedor=0, idIng=0;

    QString SQL="SELECT idProveedor FROM Proveedor WHERE nombreProveedor='"+proveedor+"';";
    query.exec(SQL);
    while (query.next()){
          idProveedor=query.value(0).toInt();
    }

    if(idProveedor==0){
       query.clear();       
       query.exec("INSERT INTO Proveedor (nombreProveedor) VALUES ('"+proveedor+"');");
        query.clear();
        SQL="SELECT LAST_INSERT_ID() FROM `proveedor` LIMIT 1;";
        query.exec(QString(SQL));
        while (query.next()){
                 idProveedor=query.value(0).toString().toInt();
        }
    }

    SQL="UPDATE `ingresobienes` SET";
    SQL+="`cefNo` = '"+noCEF+"', ";
    SQL+="`facturaNo` = '"+facturaProveedor+"', ";
    SQL+="`fechaFactura` = '"+fechaFactura+"', ";
    SQL+="`acuerdoCSU_NO` = '"+noCSU+"', ";
    SQL+="`fechaAcuerdo` = '"+ fechaCSU+ "', ";
    SQL+="`fuenteIngreso` = '"+fuentedeFondos+"', ";
    SQL+="`observaciones` = '"+observaciones+"', ";
    SQL+="`codigoIngreso` = '"+codigoIngreso+"', ";
    SQL+="`idProveedor`  = "+QString::number(idProveedor)+", ";
    SQL+="`estadoIngreso` = '"+estadoIngreso+"' WHERE `ingresobienes`.`idIngreso` = "+QString::number(idIngreso);

    query.clear();
    query.exec(SQL);

}


void Persistencia::actualizarBien(int idBien, EspecificacionBien *espec, QString serie, float valor, QString fAdquisicion, int sector, QString modelo, QString marca, QString codESpecifco, QString estadoBien){
    QSqlQuery query(QSqlDatabase::database("sibcues"));

    int idModelo=0, idMarca=0, idEspecifico=0;

    QString SQL="SELECT idModelo FROM modelo WHERE modelo='"+modelo+"';";
    query.exec(SQL);
    while (query.next()){
          idModelo=query.value(0).toInt();
    }

    query.clear();
    SQL="SELECT idMarca FROM marca WHERE nombreMarca='"+marca+"';";
    query.exec(SQL);
    while (query.next()){
          idMarca=query.value(0).toInt();
    }

    query.clear();
    SQL="SELECT idEspecCuenta FROM especcuenta WHERE codigoCuenta='"+codESpecifco+"';";
    query.exec(SQL);
    while (query.next()){
          idEspecifico=query.value(0).toInt();
    }

    SQL="DELETE FROM lineaIngresoAF WHERE lineaIngresoAF.idBien =  "+QString::number(idBien);
    query.exec(SQL);

    SQL="UPDATE `bienactivofijo` SET ";
    SQL+="`idEspec` = '"+QString::number(espec->oid_especbien)+"', ";
    SQL+="`idEspecifico` = '"+QString::number(idEspecifico)+"', ";


    if(idMarca!=0)
        SQL+="`idMarca` = '"+QString::number(idMarca)+"', ";
    else
        SQL+="`idMarca` = NULL",SQL+=",";

    if(idModelo!=0)
        SQL+="`idModelo` = '"+QString::number(idModelo)+"', ";
    else
        SQL+="`idModelo` =  NULL",SQL+=",";

    SQL+="`idSector` = '"+ QString::number(sector)+ "', ";
    SQL+="`fechaAdquisicion` = '"+fAdquisicion+"', ";
    SQL+="`valor` = '"+QString::number(valor)+"', ";    
    SQL+="`serie` = '"+serie+"', ";    
    SQL+="`estadoBien` = '"+estadoBien+"' WHERE `bienactivofijo`.`idBien` = "+QString::number(idBien);


    query.clear();
    query.exec(SQL);    
    std::cout << query.lastError().text().toStdString();


}

int Persistencia::guardarBien(EspecificacionBien *espec, QString correlativo, QString serie, float valor, QString fAdquisicion, int sector, QString modelo, QString marca, QString codESpecifco,QString codigoBien, QString estadoBien, int idInventarioAF){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int idModelo=0, idBien=0, idMarca=0, idEspecifico=0;

    QString SQL="SELECT idModelo FROM modelo WHERE modelo='"+modelo+"';";
    query.exec(SQL);
    while (query.next()){
          idModelo=query.value(0).toInt();          
    }

    query.clear();
    SQL="SELECT idMarca FROM marca WHERE nombreMarca='"+marca+"';";
    query.exec(SQL);
    while (query.next()){
          idMarca=query.value(0).toInt();
    }

    query.clear();
    SQL="SELECT idEspecCuenta FROM especcuenta WHERE codigoCuenta='"+codESpecifco+"';";
    query.exec(SQL);
    while (query.next()){
          idEspecifico=query.value(0).toInt();
    }

    query.clear();
    SQL="INSERT INTO bienactivofijo (idEspec, idInvAF , fechaAdquisicion , valor , idSector , estadoBien , serie , correlativo ,  idModelo, idMarca, codigo, idEspecifico) VALUES (";

    SQL+=QString::number(espec->oid_especbien),SQL+=", ";
    SQL+=QString::number(idInventarioAF),SQL+=", "; //query.bindValue(":idInvAF", QString::number(1));
    SQL+="'", SQL+=fAdquisicion,SQL+="',";
    SQL+=QString::number(valor),SQL+=",";
    SQL+=QString::number(sector),SQL+=",";
    SQL+="'", SQL+=estadoBien,SQL+="',";
    SQL+="'", SQL+=serie,SQL+="',";
    SQL+="'", SQL+=correlativo,SQL+="',";

    if(idModelo!=0)
        SQL+=QString::number(idModelo),SQL+=",";
    else
        SQL+="NULL",SQL+=",";

    if(idMarca!=0)
        SQL+=QString::number(idMarca),SQL+=",";
    else
        SQL+="NULL",SQL+=",";

    SQL+="'", SQL+=codigoBien,SQL+="',";

    SQL+=QString::number(idEspecifico),SQL+=");";

    bool exitoso=query.exec(SQL);

    if(!exitoso)
        this->ROLLBACK();

    std::cout << endl << endl << SQL.toStdString() <<endl;


    QSqlError error=query.lastError();
    std::cout << error.text().toStdString();

     query.clear();
     SQL="SELECT LAST_INSERT_ID() FROM `bienactivofijo` LIMIT 1;";
     query.exec(QString(SQL));
     while (query.next()){
            idBien=query.value(0).toInt();
     }
     return idBien;
}


int Persistencia::guardarBien(EspecificacionBien *espec, QString correlativo, float valor, QString fAdquisicion, QString titulo, QString isbn, QString especifico, QString codigo){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int idTitulo=0, idAutor=0, idBien=0, idEspecifico=0, idSector=1;
    QString SQL="SELECT idTitulo  FROM titulo WHERE tituloObra='"+titulo+"'    ;";
    query.exec(SQL);
    while (query.next()){
          idTitulo=query.value(0).toInt();          
    }


    query.exec(SQL);

    std::cout << query.lastQuery().toStdString();


    query.clear();
    SQL="SELECT idEspecCuenta FROM especcuenta WHERE codigoCuenta='"+especifico+"';";
    query.exec(SQL);
    while (query.next()){
          idEspecifico=query.value(0).toInt();
    }
    query.exec(SQL);

    query.clear();

     SQL="INSERT INTO bienbibliografico (idTitulo, idEspec, idInvBiblio, idEspecifico, idSector, fechaAdquisicion, valor, estadoBien, correlativo, codigo, codInterno) "
         " VALUES( "+QString::number(idTitulo)+", "+QString::number(espec->oid_especbien)+", "+QString::number(this->idInventarioBibliografico)+", "
         " "+QString::number(idEspecifico)+", "+QString::number(idSector)+", '"+fAdquisicion+"', "+QString::number(valor)+", 'activo', '"+correlativo+"', '"+codigo+"', ' ')";

     query.exec(SQL);

     std::cout << query.lastQuery().toStdString();



     std::cout << query.lastError().text().toStdString();


     query.clear();
     SQL="SELECT LAST_INSERT_ID() FROM `bienbibliografico` LIMIT 1;";
     query.exec(QString(SQL));
     while (query.next()){
            idBien=query.value(0).toString().toInt();
     }
     return idBien;
}

bool Persistencia::crearlineaIngresoAF(int codBien, int codigoIngreso){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int idMarca=0, idModelo=0, idEspecifico=0, idEspec=0, idSector=0, idInvAF=0;
    bool ok;

    QString SQL="SELECT idInvAF, idSector, idEspec, idEspecifico, idModelo, idMarca  FROM bienactivofijo WHERE idBien="+QString::number(codBien);
    query.exec(SQL);
    while (query.next()){        
        idInvAF=query.value(0).toInt();
        idSector=query.value(1).toInt();
        idEspec=query.value(2).toInt();
        idEspecifico=query.value(3).toInt();
        idModelo=query.value(4).toInt();
        idMarca=query.value(5).toInt();
    }

    query.clear();
    SQL="INSERT INTO lineaIngresoAF(idIngreso, idEspecifico, idEspec, idSector, idInvAF, idBien) VALUES (";
    SQL+=QString::number(codigoIngreso),SQL+=", ";    
    SQL+=QString::number(idEspecifico),SQL+=", ";
    SQL+=QString::number(idEspec),SQL+=", ";
    SQL+=QString::number(idSector),SQL+=", ";
    SQL+=QString::number(idInvAF),SQL+=", ";
    SQL+=QString::number(codBien),SQL+=");";
    ok=query.exec(SQL);

    if(!ok)
        this->ROLLBACK();


    std::cout << endl << endl << SQL.toStdString() <<endl;

    QSqlError error=query.lastError();
    std::cout << error.text().toStdString();    
    return ok;

}


bool Persistencia::crearlineaIngresoMB(int codBien, int codigoIngreso){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int idTitulo=0,  idEspecifico=0, idEspec=0, idSector=0, idInvMB=0;
    bool ok;

    QString SQL="SELECT idInvBiblio, idSector, idEspec, idEspecifico, idTitulo   FROM bienbibliografico WHERE idBien="+QString::number(codBien);
    query.exec(SQL);
    while (query.next()){
        idInvMB=query.value(0).toInt();
        idSector=query.value(1).toInt();
        idEspec=query.value(2).toInt();
        idEspecifico=query.value(3).toInt();        
        idTitulo=query.value(4).toInt();
    }

    query.clear();
    SQL="INSERT INTO lineaingresobibliografico(idIngreso, idEspecifico, idEspec, idSector, idInvBiblio, idBien) VALUES (";
    SQL+=QString::number(codigoIngreso),SQL+=", ";
    SQL+=QString::number(idEspecifico),SQL+=", ";
    SQL+=QString::number(idEspec),SQL+=", ";
    SQL+=QString::number(idSector),SQL+=", ";
    SQL+=QString::number(idInvMB),SQL+=", ";
    SQL+=QString::number(codBien),SQL+=");";
    ok=query.exec(SQL);

    if(!ok)
        this->ROLLBACK();


    std::cout << endl << endl << SQL.toStdString() <<endl;

    QSqlError error=query.lastError();
    std::cout << error.text().toStdString();
    return ok;

}


/*void Persistencia::crearlineaIngreso(int codBien, int codigoIngreso, EspecificacionBien *espec){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    query.clear();
    query.prepare("INSERT INTO lineaingreso(idEspecificacion ,idBien ,idIngreso)" "VALUES (:idEspecificacion, :idBien, :idIngreso);");
    query.bindValue(":idEspecificacion", QString::number(espec->oid_especbien));
    query.bindValue(":idBien", QString::number(codBien));
    query.bindValue(":idIngreso", QString::number(codigoIngreso));
    query.exec();
}*/


string Persistencia::getModelo(int oidModelo){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    string modelo;

    QString SQL="SELECT modelo FROM modelo WHERE idModelo="+QString::number(oidModelo)+";";
    query.exec(SQL);
    while (query.next()){        
          modelo=query.value(0).toString().toStdString();
    }
    return modelo;
}


QString Persistencia::getTitulo(int idTitulo){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    QString titulo;

    QString SQL="SELECT tituloObra FROM titulo WHERE idTitulo="+QString::number(idTitulo);
    query.exec(SQL);
    while (query.next()){
          titulo=query.value(0).toString();
    }
    return titulo;
}


QString Persistencia::getISBN(int idTitulo, int idAutor){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    QString isbn;

    QString SQL="SELECT isbn FROM titulo WHERE idTitulo="+QString::number(idTitulo)+" AND idAutor="+QString::number(idAutor)+";";
    query.exec(SQL);
    while (query.next()){
          isbn=query.value(0).toString();
    }
    return isbn;
}


QString Persistencia::getAutor(int idTitulo){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    QString autor;

    QString SQL=" select group_concat(nombreAutor separator ' * ') autores "
    " from titulo join obrade on obrade.idTitulo=titulo.idTitulo "
    " join autor on autor.idAutor=obrade.idAutor "
    " where titulo.idTitulo="+QString::number(idTitulo);
    query.exec(SQL);

    while (query.next()){
          autor=query.value(0).toString();
    }
    return autor;
}

QString Persistencia::getApellido(int idAutor){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    QString apellido;

    QString SQL="SELECT apellidoAutor FROM autor WHERE idAutor="+QString::number(idAutor)+";";
    query.exec(SQL);
    while (query.next()){
          apellido=query.value(0).toString();
    }
    return apellido;
}

string Persistencia::getMarca(int oidMarca){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    string marca;

    QString SQL="SELECT nombreMarca FROM marca WHERE idMarca="+QString::number(oidMarca)+";";
    query.exec(SQL);
    while (query.next()){        
          marca=query.value(0).toString().toStdString();
    }
    return marca;
}

string Persistencia::getEspecifico(int oidEspecifico){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    string especifico;

    QString SQL="SELECT codigoCuenta FROM especcuenta WHERE idEspecCuenta="+QString::number(oidEspecifico)+";";
    query.exec(SQL);
    while (query.next()){
          especifico=query.value(0).toString().toStdString();
    }
    return especifico;
}


string Persistencia::getNombreEspecifico(string codEspec){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    string especifico;

    QString SQL="SELECT nombreCuenta FROM especcuenta WHERE codigoCuenta='"+QString::fromStdString(codEspec)+"';";
    query.exec(SQL);
    while (query.next()){
          especifico=query.value(0).toString().toStdString();
    }
    return especifico;
}



int Persistencia::oidModelo(QString modelo){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int idModelo=0;
    QString SQL="SELECT idModelo FROM modelo WHERE modelo='"+modelo+"';";
    query.exec(SQL);
    while (query.next()){
          idModelo=query.value(0).toInt();
    }
    return idModelo;

}


int Persistencia::oidTitulo(QString titulo, QString isbn){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int idTitulo=0, idAutor=0;
    QString SQL="SELECT idTitulo, idAutor  FROM titulo WHERE titulo='"+titulo+"' AND isbn='"+isbn+"';";
    query.exec(SQL);
    while (query.next()){
          idTitulo=query.value(0).toInt();
          idAutor=query.value(1).toInt();
    }
    return idTitulo;
}

int Persistencia::oidTituloAutor(QString titulo, QString isbn){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int  idAutor=0;
    QString SQL="SELECT idAutor  FROM titulo WHERE titulo='"+titulo+"' AND isbn='"+isbn+"';";
    query.exec(SQL);
    while (query.next()){
          idAutor=query.value(0).toInt();
    }
    return idAutor;
}


void Persistencia::cargarBienesInventario(InventarioActivoFijo *inventario, RegistroCatalogo *regCatalogo, string anioInventario)
{
     QSqlQuery query(QSqlDatabase::database("sibcues"));
    int idEspec, idBien, idModelo, estado, idMarca, idEspecifico;
    float valor;
    QDate fechaAdquisicion;
    string correlativo, serial;
    Bien *bien=NULL;
    Fecha *fecha;
    moduloinventario::EspecificacionBien *especAF;
    moduloinventario::EspecificacionBien *especMB;

    inventario->limpiarContenedor();


    //QString estadoBien, SQL="SELECT `idEspec`, `fechaAdquisicion`, `valor`, `idBien`, `serie`, `correlativo`, `idModelo`, `estadoBien`, `idMarca`, `idEspecifico`   FROM `bienactivofijo` WHERE `idInvAF`="+QString::number(this->idInventarioActivoFijo)+" ORDER BY `idBien` ";

    QString estadoBien, SQL=
    "SELECT bien.idEspec, bien.fechaAdquisicion, bien.valor, bien.idBien, bien.serie, "
    "       bien.correlativo, bien.idModelo, bien.estadoBien, "
    "       bien.idMarca, bien.idEspecifico   "
    "FROM bienactivofijo bien,  invactivofijo invaf, inventario inv "
    "WHERE bien.idInvAF=invaf.idInvAF "
    " AND invaf.idInventario=inv.idInventario "
    " AND inv.anioInventario='"+QString::fromStdString(anioInventario)+"'  "
    " ORDER BY `idBien` ";



    query.exec(SQL);
    while (query.next()){
          idEspec=query.value(0).toInt();
          fechaAdquisicion=query.value(1).toDate();          
          valor=query.value(2).toString().toFloat();
          idBien=query.value(3).toString().toInt();
          serial=query.value(4).toString().toStdString();
          correlativo=query.value(5).toString().toStdString();          

          idModelo=query.value(6).toString().toInt();
          estadoBien=query.value(7).toString();

          idMarca=query.value(8).toInt();
          idEspecifico=query.value(9).toInt();

           if(estadoBien=="activo"){
              estado=1;
          }
          else{
              if(estadoBien=="descargado"){
                  estado=2;
              }
              else{
                  estado=3;
              }
          }

          fecha=new Fecha(fechaAdquisicion.day(), fechaAdquisicion.month(), fechaAdquisicion.year());
          especAF=regCatalogo->getEspecificacion(idEspec);
          bien=inventario->crearBien(especAF, valor, fecha, estado, false);
          bien->correlativo=correlativo;
          //bien->setSector(sector);
          bien->oid=idBien;
          bien->fechaAdquisicion=fecha;
          bien->idModelo=idModelo;
          bien->idMarca=idMarca;
          bien->idEspecifico=idEspecifico;
          bien->setSerie(serial);
      }

    SQL=" SELECT invaf.idInvAF, invmb.idInvBiblio       "
        " FROM   invactivofijo invaf, inventario inv, invmatbiblio invmb "
        " WHERE  invaf.idInventario=inv.idInventario "
        " AND invmb.idInventario=inv.idInventario "
        " AND inv.idUnidad="+QString::number(this->IDUnidad)+
        " AND inv.anioInventario='"+QString::fromStdString(anioInventario)+"' ";

     query.exec(SQL);
     while (query.next()){
            this->idInventarioActivoFijo=query.value(0).toInt();
            this->idInventarioBibliografico=query.value(1).toInt();
     }

     //DESCOMENTADO

    /*int idTitulo;

    SQL="SELECT `idEspec`, `fechaAdquisicion`, `valor`, `idBien`, `idTitulo`, `correlativo`, `estadoBien`  FROM `bienbibliografico` WHERE `idInvBiblio`="+QString::number(this->idInventarioBibliografico)+" ORDER BY `idBien` ";

    query.exec(SQL);
    while (query.next()){
          idEspec=query.value(0).toInt();
          fechaAdquisicion=query.value(1).toDate();
          valor=query.value(2).toString().toFloat();
          idBien=query.value(3).toString().toInt();
          idTitulo=query.value(4).toString().toInt();
          correlativo=query.value(5).toString().toStdString();

          estadoBien=query.value(6).toString();

           if(estadoBien=="activo"){
              estado=1;             
          }
          else{
              if(estadoBien=="descargado"){
                  estado=2;                  
              }
              else{
                  estado=3;                  
              }
          }

          fecha=new Fecha(fechaAdquisicion.day(), fechaAdquisicion.month(), fechaAdquisicion.year());
          especMB=regCatalogo->getEspecificacion(idEspec);
          bien=inventario->crearBien( fecha, especMB, valor, estado, false);
          bien->correlativo=correlativo;
          //bien->setSector(sector);
          bien->oid=idBien;
          bien->fechaAdquisicion=fecha;
          bien->idTitulo=idTitulo;          
    }*/
}


int Persistencia::getIDInvFijo(string anioInventario){

    QSqlQuery query(QSqlDatabase::database("sibcues"));

    QString SQL=" SELECT invaf.idInvAF       "
        " FROM   invactivofijo invaf, inventario inv "
        " WHERE  invaf.idInventario=inv.idInventario "
        " AND inv.idUnidad="+QString::number(this->IDUnidad)+
        " AND inv.anioInventario='"+QString::fromStdString(anioInventario)+"' ";

    query.exec(SQL);
    while (query.next()){
           this->idInventarioActivoFijo=query.value(0).toInt();
    }

    return this->idInventarioActivoFijo;
}

int Persistencia::getIDInvMB(QString anioInventario){

    QSqlQuery query(QSqlDatabase::database("sibcues"));

    QString SQL="SELECT invmb.idInvBiblio   "
                " FROM   invmatbiblio invmb, inventario inv "
                " WHERE  invmb.idInventario=inv.idInventario  "
                " AND inv.idUnidad="+QString::number(this->IDUnidad)+
                " AND inv.anioInventario='"+anioInventario+"' ";


    query.exec(SQL);
    while (query.next()){
           this->idInventarioBibliografico=query.value(0).toInt();
    }

    return this->idInventarioBibliografico;
}

int Persistencia::getIdInvAF(){
    return this->idInventarioActivoFijo;
}

int Persistencia::getIdInvBiblio(){
    return this->idInventarioBibliografico;
}

void Persistencia::cambiaEstadoDescargado(Bien *bien){

    QSqlQuery query(QSqlDatabase::database("sibcues"));

   if(bien->getEspecAF()!=NULL){
        QString SQL="UPDATE `bienactivofijo` SET `estadoBien` = 'descargado' WHERE `bienactivofijo`.`idBien` ="+QString::number(bien->oid);
        query.exec(SQL);
    }
}

void Persistencia::cambiaEstadoDescargadoMB(Bien *bien){

    QSqlQuery query(QSqlDatabase::database("sibcues"));

    QString SQL="UPDATE `bienbibliografico` SET `estadoBien` = 'descargado' WHERE `bienbibliografico`.`idBien` ="+QString::number(bien->oid);
    query.exec(SQL);

}



int Persistencia::guardarDescargoBienes(QString FechaDescargo,  QString HoraDescargo,  QString observaciones, QString motivo, QString tipoBien, QString codigoDescargo, QString estadoDescargo ){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int  idDes=0;


    QString SQL="INSERT INTO descargobienes (codigoDescargo, idInventario, fechaDescargo , horaDescargo , observaciones ,motivoDescargo ,tipoBienDescargo, estadoDescargo) VALUES (";
    SQL+="'"+codigoDescargo+"', ";
    SQL+=QString::number(this->idInventarioGeneral)+", ";
    SQL+="'"+FechaDescargo+"', ";
    SQL+="'"+HoraDescargo+"', ";
    SQL+="'"+observaciones+"', ";
    SQL+="'"+motivo+"', ";
    SQL+="'"+tipoBien+"', ";
    SQL+="'"+estadoDescargo+"') ";
    query.exec(SQL);

    query.clear();
    SQL="SELECT LAST_INSERT_ID() FROM `descargobienes` LIMIT 1;";
    query.exec(QString(SQL));
    while (query.next()){
                 idDes=query.value(0).toString().toInt();
    }

    return idDes;
}


bool Persistencia::actualizarDescargoBienes(int idDescargo, QString observaciones, QString motivo, QString codigoDescargo, QString estadoDescargo ){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int  idDes=0;

    QString SQL="UPDATE `descargobienes` SET ";
    SQL+="`observaciones` = '"+observaciones+"', ";
    SQL+="`motivoDescargo` = '"+motivo+"', ";
    SQL+="`codigoDescargo` = '"+codigoDescargo+"', ";
    SQL+="`estadoDescargo` = '"+estadoDescargo+"' WHERE `descargobienes`.`idDescargo` = "+QString::number(idDescargo);

    bool ok=query.exec(SQL);
    return ok;


}




void Persistencia::crearlineaDescargoAF(int codBien, int codigoDescargo){

    QSqlQuery query(QSqlDatabase::database("sibcues"));

    int idEspecifico=0, idEspec=0, idSector=0, idInvAF=0;
    bool ok;

    QString SQL="SELECT idInvAF, idSector, idEspec, idEspecifico FROM bienactivofijo WHERE idBien="+QString::number(codBien);
    query.exec(SQL);
    while (query.next()){
        idInvAF=query.value(0).toInt();
        idSector=query.value(1).toInt();
        idEspec=query.value(2).toInt();
        idEspecifico=query.value(3).toInt();
    }

    SQL="INSERT INTO lineaDescargoAF( idDescargo, idEspecifico,  idEspec, idSector, idInvAF, idBien ) VALUES (";
    SQL+=QString::number(codigoDescargo)+", ";
    SQL+=QString::number(idEspecifico)+", ";
    SQL+=QString::number(idEspec)+", ";
    SQL+=QString::number(idSector)+", ";
    SQL+=QString::number(idInvAF)+", ";
    SQL+=QString::number(codBien)+")";
    ok=query.exec(SQL);
}

void Persistencia::crearlineaDescargoMB(int codBien, int codigoDescargo){
    QSqlQuery query(QSqlDatabase::database("sibcues"));

    int idEspecifico=0, idEspec=0, idSector=0, idInvBiblio=0;
    bool ok;

    QString SQL="SELECT idInvBiblio, idSector, idEspec, idEspecifico FROM bienbibliografico WHERE idBien="+QString::number(codBien);
    query.exec(SQL);
    while (query.next()){
        idInvBiblio=query.value(0).toInt();
        idSector=query.value(1).toInt();
        idEspec=query.value(2).toInt();
        idEspecifico=query.value(3).toInt();
    }

    SQL="INSERT INTO lineadescargomb( idDescargo, idEspecifico,  idEspec, idSector, idInvBiblio, idBien ) VALUES (";
    SQL+=QString::number(codigoDescargo)+", ";
    SQL+=QString::number(idEspecifico)+", ";
    SQL+=QString::number(idEspec)+", ";
    SQL+=QString::number(idSector)+", ";
    SQL+=QString::number(idInvBiblio)+", ";
    SQL+=QString::number(codBien)+")";
    ok=query.exec(SQL);
}



std::map<int, string> Persistencia::cargarNombreUnidades(int oidUnidad){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    std::map<int, string> listaUnidades;

    QString SQL="SELECT idUnidad, nombreUnidad  FROM unidad WHERE idUnidad!="+QString::number(oidUnidad);
    query.exec(SQL);
    while (query.next()){
          listaUnidades[query.value(0).toInt()]=query.value(1).toString().toStdString();
    }
    return listaUnidades;
}


std::map<int, string> Persistencia::cargarNombreUnidades(){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    std::map<int, string> listaUnidades;

    QString SQL="SELECT idUnidad, nombreUnidad  FROM unidad";
    query.exec(SQL);
    while (query.next()){
          listaUnidades[query.value(0).toInt()]=query.value(1).toString().toStdString();
    }
    return listaUnidades;
}



int Persistencia::guardarTrasladoBienes( int unidadRecibe,  QString tipoTraslado, QString tipoBien, QString FechaTraslado, QString HoraTraslado, QString observaciones, QString estadoDescargo, QString codigoTraslado){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int  idTraslado=0;

    QString SQL="INSERT INTO trasladobienes (idInventario , unidadRecibe, tipoTraslado, tipoBienTraslado, fechaTraslado, horaTraslado, estadoTraslado, observaciones, codTraslado ) "
                "VALUES (";
    SQL+=" "+QString::number(this->idInventarioGeneral);
    SQL+=", "+QString::number(unidadRecibe);
    SQL+=", '"+tipoTraslado+"'";
    SQL+=", '"+tipoBien+"'";
    SQL+=", '"+FechaTraslado+"'";
    SQL+=", '"+HoraTraslado+"'";
    SQL+=", '"+estadoDescargo+"'";
    SQL+=", '"+observaciones+"'";
    SQL+=", '"+codigoTraslado+"' )";
    query.exec(SQL);

    std::cout << query.lastError().text().toStdString();

    query.clear();

    SQL="SELECT LAST_INSERT_ID() FROM `trasladobienes` LIMIT 1;";
    query.exec(QString(SQL));
    while (query.next()){
                idTraslado=query.value(0).toString().toInt();
    }
    return idTraslado;
}


int Persistencia::oidUnidad(QString unidad){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    int idUnidad=0;
    QString SQL="SELECT idUnidad FROM unidad WHERE nombreUnidad='"+unidad+"';";
    query.exec(SQL);
    while (query.next()){
          idUnidad=query.value(0).toInt();
    }
    return idUnidad;
}

void Persistencia::cambiaEstadoTrasladado(Bien *bien){

    if(bien->getEspecAF()!=NULL){
        QSqlQuery query(QSqlDatabase::database("sibcues"));
        QString SQL="UPDATE `bienactivofijo` SET `estadoBien` = 'trasladado' WHERE `bienactivofijo`.`idBien` ="+QString::number(bien->oid);
        query.exec(SQL);
    }


}

void Persistencia::cambiaEstadoTrasladadoMB(Bien *bien){
        QSqlQuery query(QSqlDatabase::database("sibcues"));
        QString SQL="UPDATE `bienbibliografico` SET `estadoBien` = 'trasladado' WHERE `bienbibliografico`.`idBien` ="+QString::number(bien->oid);
        query.exec(SQL);
}

void Persistencia::crearlineaTraslado(int codBien, int codigoTraslado){
    QSqlQuery query(QSqlDatabase::database("sibcues"));

    int idEspecifico=0, idEspec=0, idSector=0, idInvAF=0;
    bool ok;

    QString SQL="SELECT idInvAF, idSector, idEspec, idEspecifico FROM bienactivofijo WHERE idBien="+QString::number(codBien);
    query.exec(SQL);
    while (query.next()){
        idInvAF=query.value(0).toInt();
        idSector=query.value(1).toInt();
        idEspec=query.value(2).toInt();
        idEspecifico=query.value(3).toInt();
    }

    SQL="INSERT INTO lineaTrasladoAF( idTraslado, idEspecifico,  idEspec, idSector, idInvAF, idBien ) VALUES (";
    SQL+=QString::number(codigoTraslado)+", ";
    SQL+=QString::number(idEspecifico)+", ";
    SQL+=QString::number(idEspec)+", ";
    SQL+=QString::number(idSector)+", ";
    SQL+=QString::number(this->idInventarioActivoFijo)+", ";
    SQL+=QString::number(codBien)+")";
    ok=query.exec(SQL);
}

void Persistencia::crearlineaTrasladoMB(int codBien, int codigoTraslado){
    QSqlQuery query(QSqlDatabase::database("sibcues"));

    int idEspecifico=0, idEspec=0, idSector=0, idInvBiblio=0;
    bool ok;

    QString SQL="SELECT idInvBiblio, idSector, idEspec, idEspecifico FROM bienbibliografico WHERE idBien="+QString::number(codBien);
    query.exec(SQL);
    while (query.next()){
        idInvBiblio=query.value(0).toInt();
        idSector=query.value(1).toInt();
        idEspec=query.value(2).toInt();
        idEspecifico=query.value(3).toInt();
    }

    SQL="INSERT INTO lineatrasladomb( idTraslado, idEspecifico,  idEspec, idSector, idInvBiblio, idBien ) VALUES (";
    SQL+=QString::number(codigoTraslado)+", ";
    SQL+=QString::number(idEspecifico)+", ";
    SQL+=QString::number(idEspec)+", ";
    SQL+=QString::number(idSector)+", ";
    SQL+=QString::number(idInvBiblio)+", ";
    SQL+=QString::number(codBien)+")";
    ok=query.exec(SQL);

}



bool Persistencia::crearConexion()
{
    QString servidor;
    QString base;
    QString usuario;
    int puerto=3306;
    QString contraseniaDB;
    QString unidad;

    //QSqlDatabase::removeDatabase("QMYSQL");
    //QSqlDatabase::removeDatabase("QSQLITE");

    QSqlDatabase::database("en_memoria_db", false).close();
    QSqlDatabase::removeDatabase("en_memoria_db");

    /*QSqlDatabase::database("sibcues", false).close();
    QSqlDatabase::removeDatabase("sibcues");*/

    QSqlDatabase db=QSqlDatabase::database("sibcues");


    if(!db.isOpen()){
        {
           QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "en_memoria_db");
           db.setDatabaseName("config.db");
           if (!db.open()) {
           }

           QSqlQuery query(QSqlDatabase::database("en_memoria_db"));
           QString SQL="SELECT `host` , `base` , `usuario` , `puerto` , `contraseniaDB` , `unidad`  FROM `configuracion` WHERE `id` =1";
           query.exec(SQL);

           while (query.next()){
               servidor=query.value(0).toString();
               base=query.value(1).toString();
               usuario=query.value(2).toString();
               puerto=query.value(3).toString().toInt();
               contraseniaDB=query.value(4).toString();
               unidad=query.value(5).toString();
               this->IDUnidad=unidad.toInt();
           }
           query.clear();
        }
        QSqlDatabase::database("en_memoria_db", false).close();
        QSqlDatabase::removeDatabase("en_memoria_db");

        db =QSqlDatabase::addDatabase("QMYSQL", "sibcues");
        if ( !db.isValid() ) {
           QMessageBox::warning( 0, "Error de Base de Datos", QObject::tr("No se pudo cargar el driver. Solicite servicio técnico") );
           return false;
        }
         db.setHostName(servidor);
         db.setPort(puerto);
         db.setDatabaseName(base);
         db.setUserName(usuario);
         db.setPassword(contraseniaDB);

         if ( !db.open() ) {
            QMessageBox::warning( 0, "Error en Aplicacion", QObject::tr("No se puede conectar a la base: Solicite servicio técnico ")+db.lastError().databaseText() );
            return false;
        }

    }else{
        this->idInventarioGeneral=0;
        this->idInventarioBibliografico=0;
        this->idInventarioActivoFijo=0;
        this->idCatalogoCont=0;

        QString SQL="SELECT catalogocontable.idCatalogoContable, inventario.idInventario, invactivofijo.idInvAF, invmatbiblio.idInvBiblio FROM unidad ";
                SQL+="LEFT JOIN catalogocontable ON catalogocontable.idUnidad=unidad.idUnidad ";
                SQL+="LEFT JOIN inventario ON inventario.idUnidad=unidad.idUnidad ";
                SQL+="LEFT JOIN invactivofijo ON invactivofijo.idInventario=inventario.idInventario ";
                SQL+="LEFT JOIN invmatbiblio ON invmatbiblio.idInventario=inventario.idInventario WHERE unidad.idUnidad="+QString::number(this->IDUnidad);

        QSqlQuery query(QSqlDatabase::database("sibcues"));
        query.exec(SQL);

        //std::cout << SQL.toStdString() << endl << query.lastError().text().toStdString();

        while(query.next()){
            this->idCatalogoCont=query.value(0).toInt();
            this->idInventarioGeneral=query.value(1).toInt();
            this->idInventarioActivoFijo=query.value(2).toInt();
            this->idInventarioBibliografico=query.value(3).toInt();
        }
    }
    return db.isOpen();
}




void Persistencia::cerrarConeccion(){
   QSqlDatabase db = QSqlDatabase::database();
   db.close();
   db.~QSqlDatabase();
}


bool Persistencia::BEGIN(){
    QSqlDatabase db=QSqlDatabase::database("sibcues");

    bool ok=false;

    if(db.isOpen()){
        ok=db.transaction();
    }
    return ok;
}

bool Persistencia::COMMINT(){
    QSqlDatabase db=QSqlDatabase::database("sibcues");

    bool ok=false;
     if(db.isOpen()){
         QSqlDatabase::database("sibcues").exec("commit");
         ok=db.commit();
     }
     return ok;
}

bool Persistencia::ROLLBACK(){
    QSqlDatabase db=QSqlDatabase::database("sibcues");
    bool ok=false;
    if(db.isOpen()){
         ok=db.rollback();
         std::cout << db.lastError().text().toStdString();
    }
    return ok;
}

QList<QString> Persistencia::getDatosBien(int idBien){

   QSqlQuery query(QSqlDatabase::database("sibcues"));
   QString codigoCuenta,nombreClase, correlativo;
   QList<QString> lista;


   QString SQL="SELECT especcuenta.codigoCuenta, especbien.nombreClase, bienactivofijo.correlativo FROM bienactivofijo ";
   SQL+="LEFT JOIN  especbien ON especbien.idEspec=bienactivofijo.idEspec ";
   SQL+="LEFT JOIN  especcuenta ON especcuenta.idEspecCuenta=especbien.idEspecCuenta ";

   SQL+=" WHERE idInvAF="+QString::number(this->idInventarioActivoFijo)+" AND bienactivofijo.idBien="+QString::number(idBien);

   query.exec(SQL);
   while (query.next()){
       codigoCuenta=query.value(0).toString();
       nombreClase=query.value(1).toString();
       correlativo=query.value(2).toString();
       lista.push_back(codigoCuenta);
       lista.push_back(nombreClase);
       lista.push_back(correlativo);
   }
   return lista;

}

void Persistencia::ingresarInventario(int anio, int unidad ){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    query.clear();

    int idInventario;

    QString SQL="INSERT INTO inventario(idUnidad, anioInventario)"
        " VALUES ("+QString::number(unidad)+" , '"+QString::number(anio)+"' );";

    query.exec(SQL);

    SQL="SELECT LAST_INSERT_ID() FROM `inventario` LIMIT 1;";
    query.exec(QString(SQL));

    while (query.next()){
       idInventario=query.value(0).toString().toInt();
    }

    SQL="INSERT INTO invactivofijo(idInventario)"
        "VALUES ("+QString::number(idInventario) +" );";

    query.exec(SQL);

    SQL="INSERT INTO invmatbiblio(idInventario)"
        "VALUES ("+QString::number(idInventario) +" );";

    query.exec(SQL);

}



void Persistencia::eliminarInventario(int idInventario ){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    query.clear();



    QString SQL="DELETE FROM invactivofijo "
                " WHERE idInventario = "+QString::number(idInventario);

    query.exec(SQL);

     SQL="DELETE FROM invmatbiblio "
                " WHERE idInventario = "+QString::number(idInventario);

    query.exec(SQL);

     SQL="DELETE FROM inventario "
                " WHERE idInventario = "+QString::number(idInventario);

    query.exec(SQL);
}


/*Permite obtener una lista de los anios de inventarios activos fijos de una determinada unidad*/

QMap<int, QString>  Persistencia::getInventariosFijos(){
    QSqlQuery query(QSqlDatabase::database("sibcues"));
    QMap<int, QString> lista;
    QString anio;
    int id;

    QString SQL="SELECT inv.anioInventario, iaf.idInvAF "
                " FROM "
                " invactivofijo iaf "
                " LEFT JOIN inventario inv ON iaf.idInventario = inv.idInventario "
                " LEFT JOIN unidad uni ON uni.idUnidad = inv.idUnidad "
                " WHERE  uni.idUnidad="+QString::number(this->IDUnidad)+"  "
                " ORDER BY anioInventario ";

    /*QString SQL="SELECT anioInventario, idInvAF  FROM invactivofijo "
                    " LEFT JOIN inventario ON invactivofijo.idInventario = inventario.idInventario LEFT JOIN unidad ON unidad.idUnidad = inventario.idUnidad "
                    " WHERE unidad.idUnidad="+QString::number(this->IDUnidad)+"  "
                    " ORDER BY anioInventario";*/

    query.exec(SQL);

    cout << endl << endl << SQL.toStdString() << endl;

    while (query.next()){
        anio=query.value(0).toString();
        id=query.value(1).toInt();
        lista.insert(id, anio);
    }
    return lista;
}

QMap<int, QString>  Persistencia::getInventariosBiblio(){

    QSqlQuery query(QSqlDatabase::database("sibcues"));
    QMap<int, QString> lista;
    QString anio;
    int id;


    QString SQL="SELECT inv.anioInventario, iab.idInvBiblio "
                " FROM "
                " invmatbiblio iab "
                " LEFT JOIN inventario inv ON iab.idInventario = inv.idInventario "
                " LEFT JOIN unidad uni ON uni.idUnidad = inv.idUnidad "
                " WHERE  uni.idUnidad="+QString::number(this->IDUnidad)+"  "
                " ORDER BY anioInventario";


    query.exec(SQL);
    while (query.next()){
        anio=query.value(0).toString();
        id=query.value(1).toInt();
        lista.insert(id, anio);
    }
    return lista;
}

Bien * Persistencia::getBienMB(QString anioInventario, QString cuenta, QString correlativo, QString clase ){

    QSqlQuery query(QSqlDatabase::database("sibcues"));


    QString especifico, descripcionClase, descripcionEspecifico;

    int idTitulo, idAutor, idBien;
    float valor;

    QDate fecha;


    QString SQL="SELECT "
                " espec.idEspec, nombreClase, correlativo, "
                " descripcionClase, bbli.idTitulo, obra.idAutor, "
                " (select codigoCuenta from especcuenta "
                 " where idEspecCuenta=bbli.idEspecifico)  especifico, "
                 " bbli.valor, "
                 " bbli.fechaAdquisicion, "
                 " (select nombreCuenta  from especcuenta "
                 " where idEspecCuenta=bbli.idEspecifico)  nombreEspecifico, "
                 " bbli.idBien "
                " from bienbibliografico bbli "
                " join especbien  espec on bbli.idEspec=espec.idEspec "
                " join invmatbiblio invmb on bbli.idInvBiblio=invmb.idInVBiblio  "
                " join inventario inv on invmb.idinventario=inv.idinventario "
                " join obrade obra on bbli.idTitulo=obra.idTitulo "
                " where anioInventario='"+anioInventario+"'  and nombreClase='"+clase+"'  and correlativo='"+correlativo+"'";

    query.exec(SQL);
    while (query.next()){
        descripcionClase=query.value(3).toString();
        idTitulo=query.value(4).toInt();
        idAutor=query.value(5).toInt();
        valor=query.value(7).toFloat();
        especifico=query.value(6).toString();
        fecha=query.value(8).toDate();
        descripcionEspecifico=query.value(9).toString();
        idBien=query.value(10).toInt();
    }


    Bien *bien=new Bien();
    bien->setidTitulo(idTitulo);
    bien->idAutor=idAutor;
    bien->setValor(valor);
    bien->setEspecifico(especifico.toStdString());
    bien->setDescripcionClase(descripcionClase.toStdString());
    Fecha *fechaAdquisicion=new Fecha(fecha.day(), fecha.month(), fecha.year());
    bien->setFechaAdquisicion(fechaAdquisicion);
    bien->setNombreEspecifico(descripcionEspecifico.toStdString());
    bien->setOID(idBien);
    return bien;

}
