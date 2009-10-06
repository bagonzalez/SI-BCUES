
#include "../headers/Cuenta.h"
#include "../headers/Subcuenta.h"
#include "../headers/Catalogo.h"

namespace contabilidad {

Cuenta::Cuenta(string _nombreCuenta, int _codigoCuenta){

    this->nombreCuenta=_nombreCuenta;
    this->codigoCuenta=_codigoCuenta;
    this->debe=this->haber=0.0;
}

Cuenta::~Cuenta(){
}

Cuenta::Cuenta(string _nombre, int _codigo, tipoCuenta x){

    this->nombreCuenta=_nombre;
    this->codigoCuenta=_codigo;
    this->debe=this->haber=0.0;
    this->tipoC=x;
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

Subcuenta * Cuenta::crearSubCuenta(string nombreSubcuenta, tipoCuenta x) {

        Subcuenta  *nueva;
        int codigoSubcuenta=this->crearCodigo();
        nueva=new Subcuenta(nombreSubcuenta, codigoSubcuenta, this);
        nueva->tipoC=x;
        mySubcuenta[nombreSubcuenta]=nueva;
        return nueva;
}

Subcuenta * Cuenta::crearSubCuenta(string nombreSubcuenta, tipoCuenta x, int codigo) {
        Subcuenta  *nueva;
        nueva=new Subcuenta(nombreSubcuenta, codigo, this);
        nueva->tipoC=x;
        mySubcuenta[nombreSubcuenta]=nueva;
        return nueva;
}

int Cuenta::crearCodigo(){
    int codigo=1;
    if(!mySubcuenta.empty())
    {
        for
        (
             map<string, Subcuenta*>::iterator et = mySubcuenta.begin();
             et != mySubcuenta.end();
             ++et
        ){
              if((et->second)->getcodigoCuenta()>=codigo)
                  codigo++;
              else
                  return  codigo;
          }
     }

    return codigo;
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

}
