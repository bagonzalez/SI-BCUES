#include "../../ModuloContable_global.h"
#include <iostream>
#include "../headers/RegistroSistemaContable.h"
#include "../headers/Cuenta.h"
#include "../headers/Subcuenta.h"
#include "../headers/PeriodoContable.h"
#include "../headers/Transaccion.h"
#include "../headers/Catalogo.h"


namespace contabilidad {
RegistroSistemaContable::RegistroSistemaContable(Fecha fechaInicio, basico::Registro *_regBasico){
    this->regBasico=_regBasico;    

}

void RegistroSistemaContable::crearCatalogo(Fecha fechaCreacion, bool existe) {

    if(existe)
        this->catalogo=new Catalogo(this->regBasico->getUnidad(), this);
    else
        this->catalogo=new Catalogo(fechaCreacion, this->regBasico->getUnidad(), this);

}

void RegistroSistemaContable::crearPeriodoContable(Fecha fechaInicio, Fecha fechaFin) {
    this->PeriodoActual=pertenecenPeriodos.size()+1;
    pertenecenPeriodos[this->PeriodoActual]=new PeriodoContable(fechaInicio, fechaFin, this->PeriodoActual, this);
}


int RegistroSistemaContable::totalTansacciones() {
    return (pertenecenPeriodos[this->PeriodoActual]->totalTansacciones());
}

int RegistroSistemaContable::crearTransaccion(Fecha *_fechaTran) {     
    return pertenecenPeriodos[this->PeriodoActual]->crearTransaccion(_fechaTran);
}

void RegistroSistemaContable::introducirInformacionTransaccion(float importe, bool esCargo, string nombreCuenta, int codigoTransaccion) {
    pertenecenPeriodos[this->PeriodoActual]->introducirInformacionTransaccion(importe, esCargo, nombreCuenta, codigoTransaccion);
}

Cuenta * RegistroSistemaContable::getDireccionCuenta(string nombreCuenta) {
    return this->catalogo->getCuenta(nombreCuenta);
}

Subcuenta * RegistroSistemaContable::getDireccionSubCuenta(string nombreCuenta) {
    return this->catalogo->getSubCuenta(nombreCuenta);
}

Subcuenta * RegistroSistemaContable::crearSubCuenta(string madre, string nombreNuevaCuenta, string descripcion){
    this->getDireccionSubCuenta(madre)->crearSubCuenta(nombreNuevaCuenta, cuenta, descripcion);
    return this->getDireccionSubCuenta(nombreNuevaCuenta);
}

Subcuenta * RegistroSistemaContable::crearSubCuenta(string madre, string nombreNuevaCuenta, int codigo, string descripcion, int id, bool nueva){
    this->getDireccionSubCuenta(madre)->crearSubCuenta(nombreNuevaCuenta, cuenta , codigo, descripcion, id, nueva);
    if(nueva)
        this->getDireccionSubCuenta(nombreNuevaCuenta)->setID();
    return this->getDireccionSubCuenta(nombreNuevaCuenta);
}

void RegistroSistemaContable::crearRubro(string nombreRubro, string descripcion, bool nueva, int id){
    this->catalogo->crearRubro(nombreRubro,  descripcion, nueva, id);
}


Subcuenta * RegistroSistemaContable::crearCategoria(string nombreMadre, string nombreCategoria, int codigo, string descripcion, int id, bool nueva){
    Subcuenta *categoria=this->catalogo->crearCategoria(nombreMadre, nombreCategoria, codigo, descripcion, id, nueva);
    if(nueva)
        this->getDireccionSubCuenta(nombreCategoria)->setID();

    return categoria;
}

float RegistroSistemaContable::getSaldoCuenta(string nombreCuenta){

    Cuenta *cuenta= this->getDireccionCuenta(nombreCuenta);
    Subcuenta *subcuenta=this->getDireccionSubCuenta(nombreCuenta);

    if(cuenta!=NULL){
        return cuenta->getSaldo();
    }
    if(subcuenta!=NULL){
        return subcuenta->getSaldo();
    }
    return 0.0;
}

list<string> RegistroSistemaContable::getHijosCuenta(string nombreCuenta){
    list<string> listaHijos;
    listaHijos=this->catalogo->getHijosCuenta(nombreCuenta);
    return listaHijos;
}

map<int, string> RegistroSistemaContable::getHijosCuentaCodigos(string nombreCuenta){
    map<int, string> listaHijos;
    listaHijos=this->catalogo->getHijosCuentaCodigos(nombreCuenta);
    return listaHijos;
}

list<string> RegistroSistemaContable::getHijosCatalogo(){
    list<string> listaHijos;
    listaHijos=this->catalogo->getHijosCatalogo();
    return listaHijos;
}

int RegistroSistemaContable::getTipoCuenta(string nombreCuenta){

    Cuenta *cuenta= this->getDireccionCuenta(nombreCuenta);
    Subcuenta *subcuenta=this->getDireccionSubCuenta(nombreCuenta);

    if(cuenta!=NULL){
        return cuenta->getTipoC();
    }
    if(subcuenta!=NULL){
        return subcuenta->getTipoC();
    }
    return 0;

}

int RegistroSistemaContable::getCodCatCuenta(string nombreCuenta){
    return this->catalogo->getCodCatCuenta(nombreCuenta, 1);
}

}



