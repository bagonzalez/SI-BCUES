

#include "../../Persistencia/persistencia_global.h"
#include "../../Persistencia/persistencia.h"

#include "../headers/Cuenta.h"
#include "../headers/Subcuenta.h"
#include "../headers/Catalogo.h"
#include <iostream>

namespace contabilidad {

Cuenta::Cuenta(string _nombreCuenta, int _codigoCuenta, string _descripcion, Catalogo *catalogo, int _id, Cuenta *_cuentaMadre, contabilidad::tipoCuenta x  ){

    this->id=_id;
    this->cuentaMadre=_cuentaMadre;
    this->nombreCuenta=_nombreCuenta;
    this->codigoCuenta=_codigoCuenta;
    this->debe=this->haber=0.0;
    this->descripcion=_descripcion;
    this->myCatalogo=catalogo;
    this->tipoC=x;
    this->setTipoC();
}

Cuenta::Cuenta(string _nombreCuenta, int _codigoCuenta, string _descripcion, Catalogo *catalogo){

    this->nombreCuenta=_nombreCuenta;
    this->codigoCuenta=_codigoCuenta;
    this->debe=this->haber=0.0;
    this->descripcion=_descripcion;
    this->myCatalogo=catalogo;
    this->tipoC=cuenta;


}


Cuenta::~Cuenta(){
}

Cuenta::Cuenta(string _nombre, int _codigo, tipoCuenta x, string _descripcion, Catalogo *catalogo , bool nueva, int _id){

    this->nombreCuenta=_nombre;
    this->codigoCuenta=_codigo;
    this->debe=this->haber=0.0;
    this->tipoC=x;
    this->descripcion=_descripcion;
    this->myCatalogo=catalogo;
    this->id=_id;

    setTipoC();

    if(nueva){
        Persistencia::Persistencia *servicioPersistencia=new Persistencia();
        servicioPersistencia->guarda(this);        

    }
    else{
         Persistencia::Persistencia *servicioPersistencia=new Persistencia();
         servicioPersistencia->cargar(this);         
     }
}

void Cuenta::setTipoC(){

    switch (this->tipoC){

            case contabilidad::rubro:{
                this->tipoCuent="rubro";
            }
                break;

            case contabilidad::categoria:{
                this->tipoCuent="categoria";
            }
                break;

            case contabilidad::cuenta:{
                 this->tipoCuent="cuenta";
            }
                break;
     }
}


void Cuenta::cargarCuenta(float cantidadImporte) {

    if(this->tipoC==cuenta)
    {
        this->debe=this->debe+cantidadImporte;
    }
}

void Cuenta::abonarCuenta(float cantidadImporte) {

    if(this->tipoC==cuenta)
    {
        this->haber=this->haber+cantidadImporte;
    }
}

void Cuenta::setSaldarCuenta() {

    this->cuentaSaldada=true;
}

float Cuenta::getSaldo() {

    float saldo=0.0;
    if(this->mySubcuenta.empty())
    {
        return saldo=(this->debe-this->haber);
    }
    else
    {
        for
        (
                map<string, Subcuenta*>::iterator it = mySubcuenta.begin();
                it != mySubcuenta.end();
                ++it
        )
        saldo=(it->second)->getSaldo()+saldo;        
    }
    return saldo;
}


void Cuenta::ajustarCuenta(float cantidadAjustar) {

    
}

string Cuenta::getNombreCuenta() {

    return this->nombreCuenta;
}

bool Cuenta::getSaldada() {

    return false;
}

int Cuenta::getcodigoCuenta() {

    return this->codigoCuenta;
}

Subcuenta * Cuenta::crearSubCuenta(string nombreSubcuenta, tipoCuenta x, string descricion) {

        Subcuenta  *nueva;
        int codigoSubcuenta=this->mySubcuenta.size();
        nueva=new Subcuenta(nombreSubcuenta, codigoSubcuenta, this, descripcion, this->myCatalogo);
        nueva->tipoC=x;
        nueva->setTipoC();
        mySubcuenta[nombreSubcuenta]=nueva;
        return nueva;
}

Subcuenta * Cuenta::crearSubCuenta(string nombreSubcuenta, tipoCuenta x, int codigo, string descricion, int id, bool _nueva) {
        Subcuenta  *nueva;
        nueva=new Subcuenta(nombreSubcuenta, codigo, this, descricion, this->myCatalogo, id, _nueva, x);
        mySubcuenta[nombreSubcuenta]=nueva;
        return nueva;
}


Subcuenta * Cuenta::getSubCuenta(string nombreCuenta) {

        Subcuenta *cuenta=NULL;

        for
        (
                map<string, Subcuenta*>::iterator it = mySubcuenta.begin();
                it != mySubcuenta.end();
                ++it
        ){
                        if(it->first==nombreCuenta)
                            return cuenta=it->second;

        }

        for
        (
                map<string, Subcuenta*>::iterator et = mySubcuenta.begin();
                et != mySubcuenta.end();
                ++et
         ){
                if((et->second)->getSubCuenta(nombreCuenta)!=NULL)
                        return cuenta=(et->second)->getSubCuenta(nombreCuenta);
         }

        return cuenta;
}



tipoCuenta Cuenta::getTipoC() {

    return this->tipoC;
}

void Cuenta::setNombreCuenta(string _nombreCuenta) {

    this->nombreCuenta=_nombreCuenta;    
}

float Cuenta::getDebe(){
    float saldodebe=0.0;
    if(this->tipoC==categoria){        
        if(this->mySubcuenta.empty())
        {
            return saldodebe=(this->debe-this->haber);
        }
        else
        {
            for
            (
                map<string, Subcuenta*>::iterator it = mySubcuenta.begin();
                it != mySubcuenta.end();
                ++it
             )
             saldodebe=(it->second)->getDebe()+saldodebe;
        }
        return saldodebe;
     }
     return this->debe;
}

float Cuenta::getHaber(){
    float saldohaber=0.0;
    if(this->tipoC==categoria){
        if(this->mySubcuenta.empty())
        {
            return saldohaber=(this->debe-this->haber);
        }
        else
        {
            for
            (
                map<string, Subcuenta*>::iterator it = mySubcuenta.begin();
                it != mySubcuenta.end();
                ++it
             )
             saldohaber=(it->second)->getHaber()+saldohaber;
        }
        return saldohaber;
     }
    return this->haber;
}

string Cuenta::getDescripcion(){
    return this->descripcion;
}

std::list<string> Cuenta::getListaHijos(){

    list<string> listaHijos;    

    for
    (
            map<string, Subcuenta*>::iterator it = mySubcuenta.begin();
            it != mySubcuenta.end();
                ++it
     ){                                   
                    listaHijos.push_back(it->first);
     }
     return listaHijos;
}

std::map<int, string> Cuenta::getCodigosHijos(){

    map<int, string> listaHijos;

    for
    (
            map<string, Subcuenta*>::iterator it = mySubcuenta.begin();
            it != mySubcuenta.end();
                ++it
     ){
                    listaHijos[it->second->getcodigoCuenta()]=it->second->getNombreCuenta();
     }
     return listaHijos;
}

void Cuenta::setID(){
     Persistencia::Persistencia *servicioPersistencia=new Persistencia();
     servicioPersistencia->setID(this);

}

void Cuenta::setID(int _id){
    this->id=_id;
}

int Cuenta::getID(){
    return this->id;
}

}
