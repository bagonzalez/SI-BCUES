
#include "../../Persistencia/persistencia_global.h"
#include "../../Persistencia/persistencia.h"
#include <iostream>
#include "../headers/Catalogo.h"
#include "../headers/Cuenta.h"
#include "../headers/Subcuenta.h"
#include "../headers/RegistroSistemaContable.h"

namespace contabilidad {

Catalogo::Catalogo(Fecha fechaCreacion, Unidad *_unidad, RegistroSistemaContable *reg){
    this->almacenado_en=reg;
    this->unidad=_unidad;

    Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->almacenado_en );
    servicioPersistencia->guarda(this);

    this->setFechaCreacion(fechaCreacion);
    /*this->crearRubro("Activos", "Activos de la Empresa");
    this->crearRubro("Pasivos",  "Pasivos de la Empresa");
    this->crearRubro("Capital",  "Capital de la Empresa");
    this->crearRubro("Ingresos",  "Ingresos");
    this->crearRubro("Gastos",  "Gastos");

    this->crearCategoria("Activos", "Caja", 11, "Caja");
    this->crearCategoria("Activos", "Inventario", 12, "Inventario");

    this->crearCategoria("Inventario", "Inmuebles", 12020, "Inmuebles");
    this->crearCategoria("Inventario", "Instalaciones", 12030, "Instalaciones");
    this->crearCategoria("Inventario", "Mobiliario y equipo de Oficina", 12040, "oFICINA");
    this->crearCategoria("Inventario", "Mobiliario y equipo de enseñanza", 12050, "Hola");
    this->crearCategoria("Inventario", "Mobiliario para servicios directos", 12060, "Hola");
    this->crearCategoria("Inventario", "Maquinaria y equipo", 12070, "Hola");
    this->crearCategoria("Inventario", "Equipo de Transporte", 12080, "Hola");
    this->crearCategoria("Inventario", "Material Bibliografico", 12090, "Hola");
    this->crearCategoria("Inventario", "Herramientas", 12100, "Hola");

    this->crearCategoria("Activos", "Bancos", 13, "Inventario");
    this->getSubCuenta("Bancos")->crearSubCuenta("Banco Salvadoreno", cuenta, 13001, "El banco que ya no existe");
    this->getSubCuenta("Bancos")->crearSubCuenta("Banco Cuscatlan", cuenta, 13002, "El banco que ya no existe");
    this->getSubCuenta("Bancos")->crearSubCuenta("Banco HSBC", cuenta, 13002, "El banco que ya no existe");

    this->crearCategoria("Gastos", "Inversiones en Activos Fijos", 51, "Hola");
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Mobiliario", cuenta, 51001, "Hola");
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Maquinaria y Equipos", cuenta, 51002, "eQUIPOS" );
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Equipos Médicos y de Laboratorio", cuenta, 51003, "Hola");
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Equipos Informáticos", cuenta, 51004, "Hola");
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Libros y Colecciones", cuenta, 51005, "Hola");

    std::cout << this->getSubCuenta("Inmuebles")->getcodigoCuenta()<<std::endl;
    std::cout << this->getSubCuenta("Instalaciones")->getcodigoCuenta()<<std::endl;*/
}

Catalogo::Catalogo(Unidad *_unidad, RegistroSistemaContable *reg){
    this->unidad=_unidad;
    this->almacenado_en=reg;
    Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->almacenado_en);
    servicioPersistencia->cargar(this);   

    /*this->crearCategoria("Activos", "Caja", 11, "Caja", 0, true);
    this->crearCategoria("Activos", "Inventario", 12, "Inventario", 0, true);*/

   /*this->crearCategoria("Inventario", "Inmuebles", 12020, "Inmuebles", 0, true );
    this->crearCategoria("Inventario", "Instalaciones", 12030, "Instalaciones", 0, true);*/
    /*this->crearCategoria("Inventario", "Mobiliario y equipo de Oficina", 12040, "oFICINA", 0, true);
    this->crearCategoria("Inventario", "Mobiliario y equipo de enseñanza", 12050, "Hola", 0, true);
    this->crearCategoria("Inventario", "Mobiliario para servicios directos", 12060, "Hola", 0, true);
    this->crearCategoria("Inventario", "Maquinaria y equipo", 12070, "Hola", 0, true);
    this->crearCategoria("Inventario", "Equipo de Transporte", 12080, "Hola", 0, true);
    this->crearCategoria("Inventario", "Material Bibliografico", 12090, "Hola", 0, true);
    this->crearCategoria("Inventario", "Herramientas", 12100, "Hola", 0, true);*/

    /*this->crearCategoria("Activos", "Bancos", 13, "Inventario", 0, true);
    this->getSubCuenta("Bancos")->crearSubCuenta("Banco Salvadoreno", cuenta, 13001, "El banco que ya no existe", 0, true);
    this->getSubCuenta("Bancos")->crearSubCuenta("Banco Cuscatlan", cuenta, 13002, "El banco que ya no existe", 0, true);
    this->getSubCuenta("Bancos")->crearSubCuenta("Banco HSBC", cuenta, 13002, "El banco que ya no existe", 0, true);*/

    /*this->crearCategoria("Gastos", "Inversiones en Activos Fijos", 51, "Hola", 0, true);*/
    /*this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Mobiliario", cuenta, 51001, "Hola", 0, true);
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Maquinaria y Equipos", cuenta, 51002, "eQUIPOS", 0, true );
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Equipos Médicos y de Laboratorio", cuenta, 51003, "Hola", 0, true);
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Equipos Informáticos", cuenta, 51004, "Hola", 0, true);
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Libros y Colecciones", cuenta, 51005, "Hola", 0, true);*/
}


Cuenta * Catalogo::getCuenta(string nombreCuenta) {

        Cuenta *cuenta=NULL;

        for
        (
                map<string, Cuenta*>::iterator it =  myCuenta.begin();
                it != myCuenta.end();
                ++it
        )
        {
                    if(it->first==nombreCuenta)
                        cuenta=it->second;

        }
        return cuenta;
}

Subcuenta * Catalogo::getSubCuenta(string nombreCuenta) {

        Subcuenta *cuenta=NULL;
        for
        (
                map<string, Cuenta*>::iterator it =  myCuenta.begin();
                it != myCuenta.end();
                ++it
        )
        {
                if((it->second)->getSubCuenta(nombreCuenta)!=NULL)
                     cuenta=(it->second)->getSubCuenta(nombreCuenta);
        }

        return cuenta;
}

void Catalogo::setFechaActualizacion(Fecha fechaActualizacion) {

    this->fechaUltimaActualizacion=fechaActualizacion;    
}

void Catalogo::setFechaCreacion(Fecha fechaCreacion) {

    this->fechaCreacion=fechaCreacion;
}

void Catalogo::crearRubro(string nombreRubro, string descripcion, bool cnueva, int id) {
    Cuenta  *nueva;   
    int codigoRubro=this->myCuenta.size()+1;
    nueva=new Cuenta(nombreRubro, codigoRubro, rubro, descripcion, this, cnueva, id );
    nueva->cuentaMadre=NULL;
    nueva->setID(id);
    myCuenta[nombreRubro]=nueva;    
    nueva->myCatalogo=this;
}


Subcuenta * Catalogo::crearCategoria(string nombreMadre, string nombreCategoria, int codigo, string descripcion, int id, bool _nueva) {
    Cuenta *madre;
    Subcuenta *subMadre;
    madre=this->getCuenta(nombreMadre);
    if(madre==NULL)
    {
        subMadre=this->getSubCuenta(nombreMadre);
        if(subMadre!=NULL)
            return subMadre->crearSubCuenta(nombreCategoria, categoria, codigo, descripcion, id, _nueva);
    }
    else
       return  madre->crearSubCuenta(nombreCategoria, categoria, codigo, descripcion, id, _nueva);

    return NULL;
}


int Catalogo::getCodCatCuenta(string nombreCuenta, int base) {
    int codigoCatalogo;
    string nombreMadre;
    Subcuenta *cuenta;
    Cuenta *rubro;
    cuenta=this->getSubCuenta(nombreCuenta);    
    rubro=this->getCuenta(nombreCuenta);

    if(cuenta!=NULL){
       nombreMadre=cuenta->cuentaMadre->getNombreCuenta();
       return codigoCatalogo=cuenta->getcodigoCuenta()*base+getCodCatCuenta(nombreMadre, base*10);
    }

    if(rubro!=NULL){
        codigoCatalogo=rubro->getcodigoCuenta()*base;
    }

    return codigoCatalogo;
}

list<string> Catalogo::getHijosCuenta(string nombreCuenta){
    Cuenta *cuenta=this->getCuenta(nombreCuenta);
    Subcuenta *subcuenta=this->getSubCuenta(nombreCuenta);
    list<string> listHijos;

    if(cuenta!=NULL){
        listHijos=cuenta->getListaHijos();
    }

    if(subcuenta!=NULL){
        listHijos=subcuenta->getListaHijos();
    }
    return listHijos;
}

map<int, string> Catalogo::getHijosCuentaCodigos(string nombreCuenta){
    Cuenta *cuenta=this->getCuenta(nombreCuenta);
    Subcuenta *subcuenta=this->getSubCuenta(nombreCuenta);
    map<int, string> listHijos;

    if(cuenta!=NULL){
        listHijos=cuenta->getCodigosHijos();
    }

    if(subcuenta!=NULL){
        listHijos=subcuenta->getCodigosHijos();
    }
    return listHijos;
}



list<string> Catalogo::getHijosCatalogo(){

    list<string> listHijos;

    for
    (
                map<string, Cuenta*>::iterator it =  myCuenta.begin();
                it != myCuenta.end();
                ++it
    )
    {
                    listHijos.push_back(it->first);

    }
    return listHijos;
}

void Catalogo::setID(int _id){
    this->id=_id;
}

int Catalogo::getID(){
    return this->id;
}


}
