#include "../../ModuloContable_global.h"
#include <iostream>
#include "../headers/RegistroSistemaContable.h"
#include "../headers/Cuenta.h"
#include "../headers/Subcuenta.h"
#include "../headers/PeriodoContable.h"
#include "../headers/Transaccion.h"
#include "../headers/Catalogo.h"


namespace contabilidad {
RegistroSistemaContable::RegistroSistemaContable(Fecha fechaInicio){
    this->crearPeriodoContable(fechaInicio, fechaInicio);
    this->crearCatalogo(fechaInicio, true);    


}

void RegistroSistemaContable::crearCatalogo(Fecha fechaCreacion, bool existe) {
    this->catalogo=new Catalogo(fechaCreacion);

    fechaCreacion.imprimirFecha();

}

void RegistroSistemaContable::crearPeriodoContable(Fecha fechaInicio, Fecha fechaFin) {
    this->PeriodoActual=pertenecenPeriodos.size()+1;
    pertenecenPeriodos[this->PeriodoActual]=new PeriodoContable(fechaInicio, fechaFin, this->PeriodoActual, this);
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

Subcuenta * RegistroSistemaContable::crearSubCuenta(string madre, string nombreNuevaCuenta){
    this->getDireccionSubCuenta(madre)->crearSubCuenta(nombreNuevaCuenta, cuenta);
    return this->getDireccionSubCuenta(nombreNuevaCuenta);
}

Subcuenta * RegistroSistemaContable::crearSubCuenta(string madre, string nombreNuevaCuenta, int codigo){
    this->getDireccionSubCuenta(madre)->crearSubCuenta(nombreNuevaCuenta, cuenta , codigo);
    return this->getDireccionSubCuenta(nombreNuevaCuenta);
}

void RegistroSistemaContable::crearRubro(string nombreRubro){
    this->catalogo->crearRubro(nombreRubro);
}

Subcuenta * RegistroSistemaContable::crearCategoria(string nombreMadre, string nombreCategoria){
    return this->catalogo->crearCategoria(nombreMadre, nombreCategoria);
}

Subcuenta * RegistroSistemaContable::crearCategoria(string nombreMadre, string nombreCategoria, int codigo){
    return this->catalogo->crearCategoria(nombreMadre, nombreCategoria, codigo);
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



