#include "persistencia.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QtGui/QMessageBox>
#include <QSqlError>
#include <QVariant>
#include <QString>
#include <QDate>
#include <iostream>


Persistencia::Persistencia(){

}

Persistencia::Persistencia( Registro *registro)
{
    this->registroBasico=registro;
    this->crearConexion();
}

Persistencia::Persistencia(RegistroSistemaContable *regContable){
    this->regContable=regContable;
    this->crearConexion();
}

Persistencia::Persistencia(RegistroCatalogo *regCatalogo){
    this->regCatalogo=regCatalogo;
}

void Persistencia::guarda( basico::Unidad *unidad){
     string SQL;

     SQL= "INSERT INTO `sibcues`.`unidad` (`idUnidadP1` ,`idUnidadP2` , `nombreUnidad`) VALUES ( '"+
          unidad->idUnidadP1+"', '"+unidad->idUnidadP2+"', '"+unidad->nombreUnidad+"');";

     QSqlQuery query;
     query.exec(QString(SQL.c_str()));
     query.clear();

     SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`unidad` LIMIT 1;";
     query.exec(QString(SQL.c_str()));

     while (query.next()){
        unidad->id=query.value(0).toString().toInt();
    }
}

void Persistencia::cargar( basico::Unidad *unidad){
     string SQL;     
     QString id=QString(QVariant::QVariant(unidad->id).toString());
     SQL="SELECT `idUnidadP1`, `idUnidadP2`, `nombreUnidad` FROM `unidad` WHERE `idUnidad`="+id.toStdString();
     QSqlQuery query;
     query.exec(QString(SQL.c_str()));

     while (query.next()){
         unidad->idUnidadP1=query.value(0).toString().toStdString();
         unidad->idUnidadP2=query.value(1).toString().toStdString();
         unidad->nombreUnidad=query.value(2).toString().toStdString();
     }
     this->registroBasico->setUnidad(unidad);

     query.clear();     
     
     SQL="SELECT `nombre`, `apellido`, `login`, `contrasenia`, `rol` FROM `usuario` WHERE `idUnidad` ="+id.toStdString();
     query.exec(QString(SQL.c_str()));

     while (query.next()){
         this->registroBasico->crearUsuario(query.value(0).toString().toStdString(), query.value(1).toString().toStdString(),
                                            query.value(2).toString().toStdString(), query.value(3).toString().toStdString(),
                                            query.value(4).toString().toStdString());
     }

 }


void Persistencia::guarda( Usuario *usuario)
{
    string SQL;

    QSqlQuery query;
    query.prepare("INSERT INTO usuario(nombre, apellido, login, contrasenia, idUnidad, rol )" "VALUES(:nombre, :apellido, :login, :contrasenia, :idUnidad, :rol)");
    query.bindValue(":nombre", QString(usuario->nombre.c_str()));
    query.bindValue(":apellido", QString( usuario->apellido.c_str() ));
    query.bindValue(":login", QString(usuario->login.c_str() ));
    query.bindValue(":contrasenia", QString(usuario->contrasenia.c_str()));
    query.bindValue(":idUnidad", QString::number(usuario->unidad->id));        

    query.bindValue(":rol", QString(usuario->rolU.c_str()));
    query.exec();
}


void Persistencia::cargar(contabilidad::Catalogo *catalogo){
    QString id=QString(QVariant::QVariant(catalogo->unidad->id).toString());
    string SQL="SELECT `fechaUltimaActualizacion`, `fechaCreacion`, `idCatalogo` FROM `catalogo` WHERE `idUnidad`="+id.toStdString();

    QSqlQuery query;
    query.exec(QString(SQL.c_str()));

     while(query.next()){
         //catalogo->fechaUltimaActualizacion=query.value(0).toString().toStdString();
         //catalogo->fechaCreacion=query.value(1).toString().toStdString();
         catalogo->id=query.value(2).toString().toInt();
     }


     query.clear();

     QString idCatalogo=QString(QVariant::QVariant(catalogo->id).toString());
     SQL="SELECT `nombreCuenta`,`descripcion`, `idCuenta`  FROM `cuenta` WHERE `idCatalogo`="+idCatalogo.toStdString()+" AND `tipoCuenta`='rubro'";
     query.exec(QString(SQL.c_str()));
     string nombreRubro;

     bool nueva=false;

     while (query.next()){
         nombreRubro=query.value(0).toString().toStdString();
         catalogo->crearRubro(nombreRubro, query.value(1).toString().toStdString(), nueva, query.value(2).toString().toInt());
     }   
}

void Persistencia::guarda(contabilidad::Catalogo *catalogo){
    QSqlQuery query;

    QDate *fechaCreacion=new QDate(2009, 11, 2);

    query.prepare("INSERT INTO catalogo( fechaUltimaActualizacion, fechaCreacion , idUnidad)" "VALUES ( :fechaUltimaActualizacion, :fechaCreacion, :idUnidad)");
    query.bindValue(":fechaUltimaActualizacion", fechaCreacion->toString(Qt::ISODate));
    query.bindValue(":fechaCreacion", fechaCreacion->toString(Qt::ISODate) );
    query.bindValue(":idUnidad", QString::number(catalogo->unidad->id));
    query.exec();
}


void Persistencia::cargar(contabilidad::Cuenta *cuenta){

    QSqlQuery query;
    string SQL;

    SQL="SELECT `debe` , `haber` , `codigoCuenta` , `nombreCuenta` , `descripcion` , `idCuenta` , `tipoCuenta` FROM `cuenta` WHERE `Cue_idCuenta` ="+QVariant::QVariant(cuenta->id).toString().toStdString()+" AND `idCatalogo` ="+QVariant::QVariant(cuenta->myCatalogo->id).toString().toStdString();

    query.exec(QString(SQL.c_str()));

    string nombreSubcuenta;
    int codigo, id;
    string descripcion, tipoCuenta;
    float debe, haber;
    bool nueva=false;    

     while (query.next()){
         debe=query.value(0).toString().toFloat();
         haber=query.value(1).toString().toFloat();
         codigo=query.value(2).toString().toInt();
         nombreSubcuenta=query.value(3).toString().toStdString();
         descripcion=query.value(4).toString().toStdString();
         id=query.value(5).toString().toInt();
         tipoCuenta=query.value(6).toString().toStdString();

         if(tipoCuenta=="categoria")
            cuenta->crearSubCuenta(nombreSubcuenta, contabilidad::categoria, codigo, descripcion, id, nueva);

         if(tipoCuenta=="cuenta")
            cuenta->crearSubCuenta(nombreSubcuenta, contabilidad::cuenta, codigo, descripcion, id, nueva);

         cuenta->getSubCuenta(nombreSubcuenta)->debe=debe;
         cuenta->getSubCuenta(nombreSubcuenta)->haber=haber;
     }
}


void Persistencia::guarda(contabilidad::Cuenta *cuenta){
    QSqlQuery query;
    query.prepare("INSERT INTO cuenta( idCatalogo, debe, haber, codigoCuenta, nombreCuenta, descripcion, Cue_idCuenta, tipoCuenta)" "VALUES (:idCatalogo, :debe, :haber, :codigoCuenta, :nombreCuenta, :descripcion, :Cue_idCuenta, :tipoCuenta);");

    query.bindValue(":idCatalogo", QString::number(cuenta->myCatalogo->id));
    query.bindValue(":debe", QString::number(cuenta->debe) );
    query.bindValue(":haber",QString::number(cuenta->haber) );
    query.bindValue(":codigoCuenta", QString::number(cuenta->codigoCuenta));
    query.bindValue(":nombreCuenta", QString::QString(cuenta->nombreCuenta.c_str()) );
    query.bindValue(":descripcion", QString::QString(cuenta->descripcion.c_str()));
    query.bindValue(":Cue_idCuenta", QString::QString(cuenta->cuentaMadre->id));
    query.bindValue(":tipoCuenta", QString::QString(cuenta->tipoCuent.c_str()));
    query.exec();
}

void Persistencia::actualizar(contabilidad::Cuenta *cuenta){
        QSqlQuery query;
        query.exec("UPDATE cuenta set debe="+QVariant::QVariant(cuenta->debe).toString()+" WHERE nombreCuenta ='"+QString(cuenta->nombreCuenta.c_str())+"'");
        query.exec("UPDATE cuenta set haber="+QVariant::QVariant(cuenta->haber).toString()+" WHERE nombreCuenta ='"+QString(cuenta->nombreCuenta.c_str())+"'");
}

void Persistencia::cargar(contabilidad::Subcuenta *cuenta){

    QSqlQuery query;
    string SQL;

    SQL="SELECT `debe` , `haber` , `codigoCuenta` , `nombreCuenta` , `descripcion` , `idCuenta` , `tipoCuenta` FROM `cuenta` WHERE `Cue_idCuenta` ="+QVariant::QVariant(cuenta->id).toString().toStdString()+" AND `idCatalogo` ="+QVariant::QVariant(cuenta->myCatalogo->id).toString().toStdString();

    query.exec(QString(SQL.c_str()));

    string nombreSubcuenta;
    int codigo, id;
    string descripcion, tipoCuenta;
    float debe, haber;
    bool nueva=false;

     while (query.next()){

         debe=query.value(0).toString().toFloat();
         haber=query.value(1).toString().toFloat();
         codigo=query.value(2).toString().toInt();
         nombreSubcuenta=query.value(3).toString().toStdString();
         descripcion=query.value(4).toString().toStdString();
         id=query.value(5).toString().toInt();
         std::cout<<nombreSubcuenta << "id-->" <<id <<std::endl;
         tipoCuenta=query.value(6).toString().toStdString();

         if(tipoCuenta=="categoria")
            cuenta->crearSubCuenta(nombreSubcuenta, contabilidad::categoria, codigo, descripcion, id, nueva);

         if(tipoCuenta=="cuenta")
            cuenta->crearSubCuenta(nombreSubcuenta, contabilidad::cuenta, codigo, descripcion, id, nueva);

         cuenta->getSubCuenta(nombreSubcuenta)->debe=debe;
         cuenta->getSubCuenta(nombreSubcuenta)->haber=haber;

     }
     std::cout << cuenta->nombreCuenta << cuenta->id << std::endl;
     std::cout << cuenta->cuentaMadre->nombreCuenta << cuenta->cuentaMadre->id ;

}

void Persistencia::guarda(contabilidad::Subcuenta *cuenta){
    QSqlQuery query;
    query.prepare("INSERT INTO cuenta( idCatalogo, debe, haber, codigoCuenta, nombreCuenta, descripcion, Cue_idCuenta, tipoCuenta)" "VALUES (:idCatalogo, :debe, :haber, :codigoCuenta, :nombreCuenta, :descripcion, :Cue_idCuenta, :tipoCuenta);");

    query.bindValue(":idCatalogo", QString::number(cuenta->myCatalogo->id));
    query.bindValue(":debe", QString::number(cuenta->debe) );
    query.bindValue(":haber",QString::number(cuenta->haber) );
    query.bindValue(":codigoCuenta", QString::number(cuenta->codigoCuenta));
    query.bindValue(":nombreCuenta", QString::QString(cuenta->nombreCuenta.c_str()) );
    query.bindValue(":descripcion", QString::QString(cuenta->descripcion.c_str()));
    query.bindValue(":Cue_idCuenta", QString::number(cuenta->cuentaMadre->id));
    query.bindValue(":tipoCuenta", QString::QString(cuenta->tipoCuent.c_str()));
    query.exec();
}

void Persistencia::setID(contabilidad::Cuenta *cuenta){
     QSqlQuery query;

     string SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`cuenta` LIMIT 1;";
     query.exec(QString(SQL.c_str()));

     while (query.next()){
         cuenta->id=query.value(0).toString().toInt();
     }
}

void Persistencia::setID(moduloinventario::Clase *clase){
     QSqlQuery query;

     string SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`clase` LIMIT 1;";
     query.exec(QString(SQL.c_str()));

     while (query.next()){
         clase->oid=query.value(0).toString().toInt();
     }
}


void Persistencia::setID(moduloinventario::IngresoClaseCatalogo *ingreso){
     QSqlQuery query;

     string SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`ingresoclasecatalogo` LIMIT 1;";
     query.exec(QString(SQL.c_str()));

     while (query.next()){
         ingreso->oid=query.value(0).toString().toInt();
     }
}

void Persistencia::guarda(moduloinventario::IngresoClaseCatalogo *ingreso){

    QSqlQuery query;
    QDateTime HoraFecha=QDateTime::currentDateTime();

    Fecha *fech=ingreso->fechaIngreso;
    Tiempo *tiempo=ingreso->horaIngreso;

    HoraFecha.setDate(QDate::QDate(fech->getAnio(), fech->getMes(), fech->getDia()));
    HoraFecha.setTime(QTime::QTime(tiempo->hora, tiempo->minutos, 0, 0));

    query.prepare("INSERT INTO ingresoclasecatalogo( idUsuario, fechaIngreso, horaIngreso)" "VALUES (:idUsuario, :fechaIngreso, :horaIngreso);");

    query.bindValue(":idUsuario", QString::number(ingreso->usuario->id));
    query.bindValue(":fechaIngreso",  HoraFecha.date().toString(Qt::ISODate) );
    query.bindValue(":horaIngreso",HoraFecha.time().toString(Qt::ISODate));    
    query.exec();

}

void Persistencia::actualizar(moduloinventario::IngresoClaseCatalogo *ingreso, EspecActivoFijo *espec){

    QSqlQuery query;

    query.prepare("INSERT INTO especactivofijo()" "VALUES ();");
    query.exec();

    query.clear();
    string SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`especactivofijo` LIMIT 1;";
    query.exec(QString(SQL.c_str()));
    while (query.next()){
         espec->oid=query.value(0).toString().toInt();
    }

    query.clear();
    query.prepare("INSERT INTO especificacionbien( idEspecAF, idClase, idCatalogoAF)" "VALUES (:idEspecAF, :idClase, :idCatalogoAF);");
    query.bindValue(":idEspecAF", QString::number(espec->oid));
    query.bindValue(":idClase",  QString::number(espec->clase->oid) );
    query.bindValue(":idCatalogoAF",QString::number(1));
    query.exec();

    query.clear();
    SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`especificacionbien` LIMIT 1;";
    query.exec(QString(SQL.c_str()));
    while (query.next()){
         espec->oid_especbien=query.value(0).toString().toInt();
    }



    query.clear();
    query.exec("UPDATE ingresoclasecatalogo set idEspecificacion="+QString::number(espec->oid_especbien)+" WHERE idIngreso ="+QString::number(ingreso->oid));

    //    query.exec("UPDATE ingresoclasecatalogo set idEspecificacion="+QString::number(ingreso->especMatBibliografico->oid_especbien)+" WHERE idIngreso ="+QString::number(ingreso->oid));

}

void Persistencia::actualizar(moduloinventario::IngresoClaseCatalogo *ingreso, EspecMaterialBibliografico *espec){
     QSqlQuery query;

    query.prepare("INSERT INTO especmaterialbibliografico()" "VALUES ();");
    query.exec();

    query.clear();
    string SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`especmaterialbibliografico` LIMIT 1;";
    query.exec(QString(SQL.c_str()));
    while (query.next()){         
         espec->oid=query.value(0).toString().toInt();
    }

    query.clear();
    query.prepare("INSERT INTO especificacionbien( idEspecBiblio, idClase, idCatalogoAF)" "VALUES (:idEspecBiblio, :idClase, :idCatalogoAF);");
    query.bindValue(":idEspecBiblio", QString::number(espec->oid));
    query.bindValue(":idClase",  QString::number(espec->clase->oid) );
    query.bindValue(":idCatalogoAF",QString::number(1));
    query.exec();

    query.clear();
    SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`especificacionbien` LIMIT 1;";
    query.exec(QString(SQL.c_str()));
    while (query.next()){
         espec->oid_especbien=query.value(0).toString().toInt();
    }
    query.clear();
    query.exec("UPDATE ingresoclasecatalogo set idEspecificacion="+QString::number(espec->oid_especbien)+" WHERE idIngreso ="+QString::number(ingreso->oid));    

}


void Persistencia::guarda(moduloinventario::Clase *clase){
    QSqlQuery query;
    query.prepare("INSERT INTO clase( idCatalogo, idCuenta, nombreClase, idEspecifico)" "VALUES (:idCatalogo, :idCuenta, :nombreClase, :idEspecifico);");
    query.bindValue(":idCatalogo", QString::number(clase->cuentaAsignada->myCatalogo->id));
    query.bindValue(":idCuenta", QString::number(clase->cuentaAsignada->id) );
    query.bindValue(":nombreClase",QString::QString(clase->nombreClase.c_str()) );
    query.bindValue(":idEspecifico", QString::number(clase->idEspecifico->id));
    query.exec();
}

void Persistencia::guardarInfo(moduloinventario::EspecMaterialBibliografico *espec, string autor, string titulo, string apellido, string descripcion, string isbn ){

    QSqlQuery query;
    int idAutor=0;

    query.clear();
    query.prepare("INSERT INTO autor( nombreAutor, apellidoAutor)" "VALUES (:nombreAutor, :apellidoAutor);");
    query.bindValue(":nombreAutor", QString::QString(autor.c_str()));
    query.bindValue(":apellidoAutor", QString::QString(apellido.c_str()));
    query.exec();

    query.clear();
    string SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`autor` LIMIT 1;";
    query.exec(QString(SQL.c_str()));
    while (query.next()){
                 idAutor=query.value(0).toString().toInt();
    }

    query.clear();
    query.prepare("INSERT INTO titulo( titulo, isbn, idEspecBiblio, idAutor)" "VALUES (:titulo, :isbn, :idEspecBiblio, :idAutor );");
    query.bindValue(":titulo", QString(titulo.c_str()));
    query.bindValue(":isbn", QString(isbn.c_str()));
    query.bindValue(":idEspecBiblio", QString::number(espec->oid));
    query.bindValue(":idAutor", QString::number(idAutor));
    query.exec();

    query.clear();    
    query.exec("UPDATE especmaterialbibliografico set descripcion='"+QString::QString(descripcion.c_str())+"' WHERE idEspecBiblio ="+QString::number(espec->oid));

}

void Persistencia::actualizarInfo(moduloinventario::EspecActivoFijo *espec, string marca, string modelo){

    QSqlQuery query;
    int idFabricante=-1;
    string SQL="SELECT idFabricante FROM `sibcues`.`fabricante` WHERE marca='"+
               QString(marca.c_str()).toStdString()+"';";
    query.exec(QString(SQL.c_str()));


   while (query.next()){
         idFabricante=query.value(0).toString().toInt();
   }

   if(idFabricante==-1){
    query.clear();
    query.prepare("INSERT INTO fabricante( marca)" "VALUES (:marca);");
    query.bindValue(":marca", QString::QString(marca.c_str()));
    query.exec();

     query.clear();
     string SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`fabricante` LIMIT 1;";
     query.exec(QString(SQL.c_str()));
     while (query.next()){
                 idFabricante=query.value(0).toString().toInt();
     }

     query.clear();
     query.exec("UPDATE fabricante set idEspecAF="+QString::number(espec->oid)+" WHERE idFabricante ="+QString::number(idFabricante));
   }

     query.clear();
     query.prepare("INSERT INTO modelo( modelo, idFabricante)" "VALUES (:modelo, :idFabricante);");
     query.bindValue(":modelo", QString::QString(modelo.c_str()));
     query.bindValue(":idFabricante", QString::number(idFabricante));
     query.exec();
}


void Persistencia::actualizarInfo(moduloinventario::EspecMaterialBibliografico *espec, string autor, string apellido, string titulo,  string isbn ){

    QSqlQuery query;
    int idAutor=-1;
    string SQL="SELECT idAutor FROM `sibcues`.`autor` WHERE `nombreAutor`='"+
               QString(autor.c_str()).toStdString()+"' AND `apellidoAutor`='"+
               QString(apellido.c_str()).toStdString()+"';";

    query.exec(QString(SQL.c_str()));


   while (query.next()){
         idAutor=query.value(0).toString().toInt();
   }

   if(idAutor==-1){   
        query.clear();
        query.prepare("INSERT INTO autor( nombreAutor, apellidoAutor)" "VALUES (:nombreAutor, :apellidoAutor);");
        query.bindValue(":nombreAutor", QString::QString(autor.c_str()));
        query.bindValue(":apellidoAutor", QString::QString(apellido.c_str()));
        query.exec();

        query.clear();
        string SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`autor` LIMIT 1;";
        query.exec(QString(SQL.c_str()));
        while (query.next()){
                 idAutor=query.value(0).toString().toInt();
        }
   }
    query.clear();
    query.prepare("INSERT INTO titulo( titulo, isbn, idEspecBiblio, idAutor)" "VALUES (:titulo, :isbn, :idEspecBiblio, :idAutor );");
    query.bindValue(":titulo", QString(titulo.c_str()));
    query.bindValue(":isbn", QString(isbn.c_str()));
    query.bindValue(":idEspecBiblio", QString::number(espec->oid));
    query.bindValue(":idAutor", QString::number(idAutor));
    query.exec();    
}

void Persistencia::guardarInfo(moduloinventario::EspecActivoFijo *espec, string marca, string modelo, string descripcion){

    QSqlQuery query;
    int idFabricante=0;
    query.clear();
    query.prepare("INSERT INTO fabricante( marca)" "VALUES (:marca);");
    query.bindValue(":marca", QString::QString(marca.c_str()));
    query.exec();

     query.clear();
     string SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`fabricante` LIMIT 1;";
     query.exec(QString(SQL.c_str()));
     while (query.next()){
                 idFabricante=query.value(0).toString().toInt();
     }


    query.clear();
    query.prepare("INSERT INTO modelo( modelo, idFabricante)" "VALUES (:modelo, :idFabricante);");
    query.bindValue(":modelo", QString::QString(modelo.c_str()));
    query.bindValue(":idFabricante", QString::number(idFabricante));
    query.exec();

    query.clear();
    query.exec("UPDATE fabricante set idEspecAF="+QString::number(espec->oid)+" WHERE idFabricante ="+QString::number(idFabricante));
    query.exec("UPDATE especactivofijo set descripcion='"+QString::QString(descripcion.c_str())+"' WHERE idEspecAF ="+QString::number(espec->oid));

}

void Persistencia::cargar(CatalogoActivoFijo *catalogo){
    QSqlQuery query, query2, query3;
    string SQL, SQL2, nombreClase, nombreCuenta, nombreEspecifico;
    string descripcion, marca, modelo, titulo, nombreAutor, apellidos, isbn;
    Subcuenta *cuentaAsignada;
    Subcuenta *especifico;
    moduloinventario::EspecActivoFijo *especAF;
    moduloinventario::EspecMaterialBibliografico *especMB;
    int oidClase, oidEspecBien, oidEspecAF, oidEspecMB, idFabricante, idAutor, idTitulo;


    SQL="SELECT `idEspecificacion` , `idEspecAF` , `idClase` FROM `especificacionbien` WHERE `idCatalogoAF` =1 AND `idEspecAF`>0";
    query.exec(QString(SQL.c_str()));
    while (query.next()){
        oidEspecBien=query.value(0).toString().toInt();
        oidEspecAF=query.value(1).toString().toInt();
        oidClase=query.value(2).toString().toInt();

        query2.clear();
        SQL2="SELECT cuenta.nombreCuenta FROM clase LEFT JOIN cuenta ON clase.idCuenta= cuenta.idCuenta WHERE idClase ="+QString::number(oidClase).toStdString();
        query2.exec(QString(SQL2.c_str()));
        while (query2.next()){
            nombreCuenta=query2.value(0).toString().toStdString();           
        }

        query2.clear();
        SQL2="SELECT clase.nombreClase, cuenta.nombreCuenta FROM clase LEFT JOIN cuenta ON clase.idEspecifico= cuenta.idCuenta WHERE idClase ="+QString::number(oidClase).toStdString();
        query2.exec(QString(SQL2.c_str()));
        while (query2.next()){
            nombreClase=query2.value(0).toString().toStdString();
            nombreEspecifico=query2.value(1).toString().toStdString();            
        }

        cuentaAsignada=catalogo->regCatalogo->regContable->getDireccionSubCuenta(nombreCuenta);
        especifico=catalogo->regCatalogo->regContable->getDireccionSubCuenta(nombreEspecifico);

        especAF=catalogo->regCatalogo->cargarEspecActivoF(cuentaAsignada, especifico, nombreClase, oidClase);
        especAF->oid=oidEspecAF;
        especAF->oid_especbien=oidEspecBien;

        query2.clear();
        SQL2="SELECT `descripcion` FROM `especactivofijo` WHERE `idEspecAF`="+QString::number(oidEspecAF).toStdString();
        query2.exec(QString(SQL2.c_str()));
        while (query2.next()){
            descripcion=query2.value(0).toString().toStdString();           
        }

        especAF->setDescripcion(descripcion);
        query2.clear();
        SQL2="SELECT `marca`, `idFabricante` FROM `fabricante` WHERE `idEspecAF`="+QString::number(oidEspecAF).toStdString();

        query2.exec(QString(SQL2.c_str()));
        while (query2.next()){
            marca=query2.value(0).toString().toStdString();
            idFabricante=query2.value(1).toString().toInt();

            especAF->setMarca(marca);

            SQL2="SELECT `modelo` FROM `modelo` WHERE `idFabricante`="+QString::number(idFabricante).toStdString();
            query3.exec(SQL2.c_str());
            while (query3.next()){
                modelo=query3.value(0).toString().toStdString();
                especAF->setModelo(marca, modelo);
            }
        }    
        

    }

    /***/

    SQL="SELECT `idEspecificacion` , `idEspecBiblio` , `idClase` FROM `especificacionbien` WHERE `idCatalogoAF` =1 AND `idEspecBiblio`>0";
    query.clear();
    query.exec(QString(SQL.c_str()));
    while (query.next()){
        oidEspecBien=query.value(0).toString().toInt();
        oidEspecMB=query.value(1).toString().toInt();
        oidClase=query.value(2).toString().toInt();

        query2.clear();
        SQL2="SELECT cuenta.nombreCuenta FROM clase LEFT JOIN cuenta ON clase.idCuenta= cuenta.idCuenta WHERE idClase ="+QString::number(oidClase).toStdString();
        query2.exec(QString(SQL2.c_str()));
        while (query2.next()){
            nombreCuenta=query2.value(0).toString().toStdString();
        }

        query2.clear();
        SQL2="SELECT clase.nombreClase, cuenta.nombreCuenta FROM clase LEFT JOIN cuenta ON clase.idEspecifico= cuenta.idCuenta WHERE idClase ="+QString::number(oidClase).toStdString();
        query2.exec(QString(SQL2.c_str()));
        while (query2.next()){
            nombreClase=query2.value(0).toString().toStdString();
            nombreEspecifico=query2.value(1).toString().toStdString();
        }

        cuentaAsignada=catalogo->regCatalogo->regContable->getDireccionSubCuenta(nombreCuenta);
        especifico=catalogo->regCatalogo->regContable->getDireccionSubCuenta(nombreEspecifico);

        especMB=catalogo->regCatalogo->cargarEspecMB(cuentaAsignada, especifico, nombreClase, oidClase);
        especMB->oid=oidEspecMB;        
        especMB->oid_especbien=oidEspecBien;

        query2.clear();
        SQL2="SELECT `descripcion` FROM `especmaterialbibliografico` WHERE `idEspecBiblio`="+QString::number(oidEspecMB).toStdString();
        query2.exec(QString(SQL2.c_str()));
        while (query2.next()){
            descripcion=query2.value(0).toString().toStdString();
        }
        especMB->setDescripcion(descripcion);

        query2.clear();
        SQL2="SELECT `titulo`, `idAutor`, `isbn`, `idTitulo` FROM `titulo` WHERE `idEspecBiblio`="+QString::number(oidEspecMB).toStdString();

        query2.exec(QString(SQL2.c_str()));
        while (query2.next()){           

            titulo=query2.value(0).toString().toStdString();
            idAutor=query2.value(1).toString().toInt();
            isbn=query2.value(2).toString().toStdString();            
            idTitulo=query2.value(3).toString().toInt();


            SQL2="SELECT `nombreAutor`, `apellidoAutor`  FROM `autor` WHERE `idAutor`="+QString::number(idAutor).toStdString();
            query3.exec(SQL2.c_str());
            while (query3.next()){
                nombreAutor=query3.value(0).toString().toStdString();
                apellidos=query3.value(1).toString().toStdString();
                especMB->setAutor(nombreAutor, apellidos);
            }

            especMB->setTitulo(nombreAutor, apellidos, titulo, isbn);
        }


    }



}


std::map<int, string> Persistencia::cargarSectores(){
    QSqlQuery query;
    std::map<int, string> listaSectores;


    string SQL="SELECT `idSector`, `descripcionSector`  FROM `sectores`";
    query.exec(SQL.c_str());
    while (query.next()){
          listaSectores[query.value(0).toInt()]=query.value(1).toString().toStdString();
    }
    return listaSectores;
}

std::map<int, string> Persistencia::cargarProveedores(){
    QSqlQuery query;
    std::map<int, string> listaProveedores;

    string SQL="SELECT `idProveedor`, `nombreProveedor`  FROM `proveedor`";
    query.exec(SQL.c_str());
    while (query.next()){
          listaProveedores[query.value(0).toInt()]=query.value(1).toString().toStdString();
    }
    return listaProveedores;
}

int Persistencia::guardarIngresoBienes(QString FechaIngreso, QString proveedor, QString noCEF, QString facturaProveedor, QString fechaFactura, QString noCSU , QString fechaCSU, QString fuentedeFondos, QString observaciones, QString tipoBien, QString HoraIngreso){

    QSqlQuery query;
    int idProveedor=0, idIng=0;

    string SQL="SELECT idProveedor FROM proveedor WHERE nombreProveedor='"+proveedor.toStdString()+"';";
    query.exec(SQL.c_str());
    while (query.next()){
          idProveedor=query.value(0).toInt();
    }

    query.clear();
    query.prepare("INSERT INTO ingresobienes (idProveedor ,fechaIngreso ,cefNo ,facturaNo ,fechaFactura ,acuerdoCSU_NO ,fechaAcuerdo ,fuenteIngreso ,observaciones ,tipoBienIngreso ,horaIngreso)" "VALUES (:idProveedor , :fechaIngreso, :cefNo, :facturaNo, :fechaFactura, :acuerdoCSU_NO, :fechaAcuerdo, :fuenteIngreso, :observaciones,:tipoBienIngreso, :horaIngreso);");
    query.bindValue(":idProveedor ", QString::number(idProveedor));
    query.bindValue(":fechaIngreso", FechaIngreso );
    query.bindValue(":cefNo", noCEF);
    query.bindValue(":facturaNo", facturaProveedor );
    query.bindValue(":fechaFactura", fechaFactura);
    query.bindValue(":acuerdoCSU_NO", noCSU);
    query.bindValue(":fechaAcuerdo", fechaCSU);
    query.bindValue(":fuenteIngreso", fuentedeFondos);
    query.bindValue(":observaciones", observaciones);
    query.bindValue(":tipoBienIngreso", tipoBien);
    query.bindValue(":horaIngreso", HoraIngreso);
    query.exec();

     query.clear();
     SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`ingresobienes` LIMIT 1;";
     query.exec(QString(SQL.c_str()));
     while (query.next()){
                 idIng=query.value(0).toString().toInt();
     }

     return idIng;

}

int Persistencia::guardarBien(EspecActivoFijo *espec, QString correlativo, QString serial, float valor, QString fAdquisicion, int sector, QString modelo){

    QSqlQuery query;
    int idModelo=0, idBien=0;
    QString SQL="SELECT idModelo FROM modelo WHERE modelo='"+modelo+"';";
    query.exec(SQL);
    while (query.next()){
          idModelo=query.value(0).toInt();
    }

    query.clear();
    query.prepare("INSERT INTO bien (idUsuario ,idEspecificacion , idInventario , fechaAdquisicion , valor , idSector , estadoBien , serial , tipoBien , correlativo ,  idModelo)" "VALUES ( :idUsuario, :idEspecificacion, :idInventario, :fechaAdquisicion,  :valor, :idSector , :estadoBien, :serial, :tipoBien, :correlativo, :idModelo );");
    query.bindValue(":idUsuario ", QString::number(1));
    query.bindValue(":idEspecificacion", QString::number(espec->oid_especbien) );
    query.bindValue(":idInventario", QString::number(1));
    query.bindValue(":fechaAdquisicion", fAdquisicion );
    query.bindValue(":valor", QString::number(valor));
    query.bindValue(":idSector", QString::number(sector));
    query.bindValue(":estadoBien", QString("activo"));
    query.bindValue(":serial", serial);
    query.bindValue(":tipoBien", QString("activofijo"));
    query.bindValue(":correlativo", correlativo);
    query.bindValue(":idModelo", QString::number(idModelo));
    query.exec();

     query.clear();
     SQL="SELECT LAST_INSERT_ID() FROM `sibcues`.`bien` LIMIT 1;";
     query.exec(QString(SQL));
     while (query.next()){
            idBien=query.value(0).toString().toInt();
     }
     return idBien;
}

void Persistencia::crearlineaIngreso(int codBien, int codigoIngreso, EspecActivoFijo *espec){
    QSqlQuery query;
    query.clear();
    query.prepare("INSERT INTO lineaingreso(idEspecificacion ,idBien ,idIngreso)" "VALUES (:idEspecificacion, :idBien, :idIngreso);");
    query.bindValue(":idEspecificacion", QString::number(espec->oid_especbien));
    query.bindValue(":idBien", QString::number(codBien));
    query.bindValue(":idIngreso", QString::number(codigoIngreso));
    query.exec();
}


string Persistencia::getModelo(int oidModelo){
    QSqlQuery query;
    string modelo;

    QString SQL="SELECT modelo FROM modelo WHERE idModelo="+QString::number(oidModelo)+";";
    query.exec(SQL);
    while (query.next()){        
          modelo=query.value(0).toString().toStdString();
    }
    return modelo;
}

string Persistencia::getMarca(int oidModelo){
    QSqlQuery query;
    string marca;

    QString SQL="SELECT marca FROM modelo LEFT JOIN fabricante ON fabricante.idFabricante=modelo.idFabricante WHERE idModelo="+QString::number(oidModelo)+";";
    query.exec(SQL);
    while (query.next()){        
          marca=query.value(0).toString().toStdString();
    }
    return marca;
}

int Persistencia::oidModelo(QString modelo){
    QSqlQuery query;
    int idModelo=0;
    QString SQL="SELECT idModelo FROM modelo WHERE modelo='"+modelo+"';";
    query.exec(SQL);
    while (query.next()){
          idModelo=query.value(0).toInt();
    }
    return idModelo;

}


void Persistencia::cargar(InventarioActivoFijo *inventario, RegistroCatalogo *regCatalogo){
     QSqlQuery query;
    int idEspec, idBien, idModelo;
    float valor;
    QDate fechaAdquisicion;
    string correlativo, serial;
    Bien *bien;
    Fecha *fecha;
    moduloinventario::EspecActivoFijo *especAF;

    QString SQL="SELECT `idEspecificacion`, `fechaAdquisicion`, `valor`, `idBien`, `serial`, `correlativo`, `idModelo`  FROM `bien` WHERE `tipoBien`='activofijo' AND `estadoBien`='activo' ORDER BY `idBien`";
    query.exec(SQL);
    while (query.next()){
          idEspec=query.value(0).toInt();
          fechaAdquisicion=query.value(1).toDate();          
          valor=query.value(2).toString().toFloat();
          idBien=query.value(3).toString().toInt();
          serial=query.value(4).toString().toStdString();
          correlativo=query.value(5).toString().toStdString();

          idModelo=query.value(6).toString().toInt();
          fecha=new Fecha(fechaAdquisicion.day(), fechaAdquisicion.month(), fechaAdquisicion.year());
          especAF=regCatalogo->getEspecificacion(idEspec);
          bien=inventario->crearBien(especAF, valor, fecha);
          bien->correlativo=correlativo;
          //bien->setSector(sector);
          bien->oid=idBien;
          bien->fechaAdquisicion=fecha;
          bien->idModelo=idModelo;
          bien->setSerie(serial);
    }
}




bool Persistencia::crearConexion()
{
    QSqlDatabase db = QSqlDatabase::database();

    if(!db.isOpen()){

        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        if ( !db.isValid() ) {
            QMessageBox::warning( 0, "Error de Base de Datos", QObject::tr("No se pudo cargar el driver.") );
            return FALSE;
        }
         db.setHostName("127.0.0.1");
         db.setPort(3306);
         db.setDatabaseName("sibcues");
         db.setUserName("root");
         db.setPassword("root");

        if ( !db.open() ) {
            QMessageBox::warning( 0, "Error en Aplicacion", QObject::tr("No se puede conectar a la base: ")+db.lastError().databaseText() );
            return FALSE;
        }
    }

    return db.open();
}


void Persistencia::cerrarConeccion(){
   QSqlDatabase db = QSqlDatabase::database();
   db.close();
   db.~QSqlDatabase();
}



