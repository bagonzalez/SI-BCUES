#include <iostream>
#include "../headers/Catalogo.h"
#include "../headers/Cuenta.h"
#include "../headers/Subcuenta.h"
#include "../headers/RegistroSistemaContable.h"

namespace contabilidad {

Catalogo::Catalogo(Fecha fechaCreacion){

    this->setFechaCreacion(fechaCreacion);
    this->crearRubro("Activos");
    this->crearRubro("Pasivos");
    this->crearRubro("Capital");
    this->crearRubro("Ingresos");
    this->crearRubro("Gastos");

    this->crearCategoria("Activos", "Caja");
    this->crearCategoria("Activos", "Inventario");

    this->crearCategoria("Inventario", "Inmuebles");
    this->crearCategoria("Inventario", "Instalaciones");
    this->crearCategoria("Inventario", "Mobiliario y equipo de Oficina");
    this->crearCategoria("Inventario", "Mobiliario y equipo de enseñanza");
    this->crearCategoria("Inventario", "Mobiliario para servicios directos");
    this->crearCategoria("Inventario", "Maquinaria y equipo");
    this->crearCategoria("Inventario", "Equipo de Transporte");
    this->crearCategoria("Inventario", "Material Bibliografico");
    this->crearCategoria("Inventario", "Herramientas");

    this->crearCategoria("Gastos", "Inversiones en Activos Fijos");
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Mobiliario", cuenta);
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Maquinaria y Equipos", cuenta);
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Equipos Médicos y de Laboratorio", cuenta);
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Equipos Informáticos", cuenta);
    this->getSubCuenta("Inversiones en Activos Fijos")->crearSubCuenta("Libros y Colecciones", cuenta);

    // std::cout << this->getCodCatCuenta("", 1) <<std::endl;
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

void Catalogo::crearRubro(string nombreRubro) {
    Cuenta  *nueva;   
    int codigoRubro=this->myCuenta.size()+1;
    nueva=new Cuenta(nombreRubro, codigoRubro, rubro);    
    nueva->cuentaMadre=NULL;
    myCuenta[nombreRubro]=nueva;    
    nueva->myCatalogo=this;
}

Subcuenta * Catalogo::crearCategoria(string nombreMadre, string nombreCategoria) {
    Cuenta *madre;
    Subcuenta *subMadre;
    madre=this->getCuenta(nombreMadre);
    if(madre==NULL)
    {
        subMadre=this->getSubCuenta(nombreMadre);
        if(subMadre!=NULL)
            return subMadre->crearSubCuenta(nombreCategoria, categoria);
    }
    else
       return  madre->crearSubCuenta(nombreCategoria, categoria);

    return NULL;
}

Subcuenta * Catalogo::crearCategoria(string nombreMadre, string nombreCategoria, int codigo) {
    Cuenta *madre;
    Subcuenta *subMadre;
    madre=this->getCuenta(nombreMadre);
    if(madre==NULL)
    {
        subMadre=this->getSubCuenta(nombreMadre);
        if(subMadre!=NULL)
            return subMadre->crearSubCuenta(nombreCategoria, categoria, codigo);
    }
    else
       return  madre->crearSubCuenta(nombreCategoria, categoria, codigo);

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

}
