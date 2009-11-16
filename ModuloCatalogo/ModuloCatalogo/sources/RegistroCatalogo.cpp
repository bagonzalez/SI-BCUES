#include "../headers/RegistroCatalogo.h"
#include "../headers/IngresoClaseCatalogo.h"

using namespace std;

namespace moduloinventario {

RegistroCatalogo::RegistroCatalogo(basico::Usuario *_usuario, contabilidad::RegistroSistemaContable *_regContable){
    this->crearCatalogo();
    this->usuario=_usuario;    
    this->regContable=_regContable;
}

int RegistroCatalogo::crearIngreso(Fecha *_fechaIngreso, Tiempo *_horaIngreso){
    int codigoIngreso=contenedorIngresos.size()+1;
    contenedorIngresos[codigoIngreso]=new IngresoClaseCatalogo(_fechaIngreso, _horaIngreso, codigoIngreso, this, this->usuario);
    contenedorIngresos[codigoIngreso]->setOID();
    return contenedorIngresos[codigoIngreso]->getCodigoIngreso();
}

int RegistroCatalogo::crearClase(Subcuenta *cuentaAsignada, Subcuenta *idEspecifico, string nombreClase){
    int idClase=contenedorClases.size()+1;
    contenedorClases[idClase]=new Clase(cuentaAsignada, idEspecifico, nombreClase, idClase);
    contenedorClases[idClase]->guardar();
    contenedorClases[idClase]->setOID();
    return contenedorClases[idClase]->getCodigoClase();
}

void RegistroCatalogo::introducirInformacion(string autor, string titulo, string apellidos, int codIngreso,  string descripcion, string isbn){
    this->contenedorIngresos[codIngreso]->introducirInformacionMB( autor, titulo, apellidos, descripcion, isbn);
}

void RegistroCatalogo::introducirInformacion(int codIngreso, string descripcion, string marca, string modelo ){
    this->contenedorIngresos[codIngreso]->introducirInformacionAF( descripcion, marca, modelo);
}

void RegistroCatalogo::crearEspecMatBiblio(contabilidad::Subcuenta *cuentaAsignada, Subcuenta *idEspecifico, int codIngreso, string clase){
   int codClase=this->crearClase(cuentaAsignada, idEspecifico, clase);

   EspecMaterialBibliografico *nueva= this->catalogoActivoFijo->crearEspecMaterialBibliografico(contenedorClases[codClase]);
   this->contenedorIngresos[codIngreso]->crearEspecMatBiblio(nueva);
}

void RegistroCatalogo::crearEspecActivoF(contabilidad::Subcuenta *cuentaAsignada, Subcuenta *idEspecifico, int codIngreso, string clase){
     int codClase=this->crearClase(cuentaAsignada, idEspecifico, clase);

    EspecActivoFijo *nueva=this->catalogoActivoFijo->crearEspecActivoFijo(contenedorClases[codClase]);
    this->contenedorIngresos[codIngreso]->crearEspecActivoF(nueva);
}

EspecActivoFijo * RegistroCatalogo::cargarEspecActivoF(contabilidad::Subcuenta *cuentaAsignada, Subcuenta *idEspecifico, string clase, int oidClase){
    int idClase=contenedorClases.size()+1;
    Clase *nuevaClase=new Clase(cuentaAsignada, idEspecifico, clase, idClase);
    contenedorClases[idClase]=nuevaClase;    
    nuevaClase->setOID(oidClase);    
    EspecActivoFijo *nueva=this->catalogoActivoFijo->crearEspecActivoFijo(contenedorClases[idClase]);
    return nueva;
}

EspecMaterialBibliografico * RegistroCatalogo::cargarEspecMB(contabilidad::Subcuenta *cuentaAsignada, Subcuenta *idEspecifico, string clase, int oidClase){

    int idClase=contenedorClases.size()+1;
    Clase *nuevaClase=new Clase(cuentaAsignada, idEspecifico, clase, idClase);
    contenedorClases[idClase]=nuevaClase;
    nuevaClase->setOID(oidClase);
    EspecMaterialBibliografico *nueva=this->catalogoActivoFijo->crearEspecMaterialBibliografico(contenedorClases[idClase]);
    return nueva;
}

void RegistroCatalogo::crearCatalogo(){
    this->catalogoActivoFijo=new CatalogoActivoFijo(this);
}

void RegistroCatalogo::cargarCatalogo(){
    this->catalogoActivoFijo->cargarCatalogo();
}



std::list<string> RegistroCatalogo::getDescripciones(){
    return this->catalogoActivoFijo->getDescripciones();
}

std::list<string> RegistroCatalogo::getMarcas(string nombreDescripcion){
    return this->catalogoActivoFijo->getMarcas(nombreDescripcion);
}

std::list<string> RegistroCatalogo::getModelos(string nombreMarca){
    return this->catalogoActivoFijo->getModelos(nombreMarca);
}

bool RegistroCatalogo::existeDescripcion(string descripcion){
    return this->catalogoActivoFijo->existeDescripcion(descripcion);
}

EspecActivoFijo * RegistroCatalogo::getEspecificacion(string clase, string cuentaAsignada){
    return this->catalogoActivoFijo->getEspecificacion(clase, cuentaAsignada);
}


EspecActivoFijo * RegistroCatalogo::getEspecificacion(int oid){
    return this->catalogoActivoFijo->getEspecificacion(oid);
}

EspecMaterialBibliografico * RegistroCatalogo::getEspecificacionMB(string clase, string cuentaAsignada){
    return this->catalogoActivoFijo->getEspecificacionMB(clase, cuentaAsignada);
}

void RegistroCatalogo::setMarca(string marca, EspecActivoFijo *espec){
    espec->setMarca(marca);
}

void RegistroCatalogo::setModelo(string marca, string modelo, EspecActivoFijo *espec){
    espec->setModelo(marca, modelo);
}


bool RegistroCatalogo::existeClase(string nombreClase, string cuentaAsignada){

    if(this->getEspecificacion(nombreClase, cuentaAsignada) != NULL)
        return true;

    if(this->getEspecificacionMB(nombreClase, cuentaAsignada) != NULL)
        return true;

   return false;
}

std::list<string> RegistroCatalogo::getClases(string cuentaAsignada){

    std::list<string> listaClases;

     for
     (
                map<int, Clase*>::iterator it = contenedorClases.begin();
                it != contenedorClases.end();
                ++it
     ){
                    if(cuentaAsignada==(it->second)->getCuentaAsignada()){
                        listaClases.push_back((it->second)->getNombreClase());
                    }
     }
     return listaClases;

}

Clase * RegistroCatalogo::getClase(string nombreClase, string cuentaAsignada ){

     for
     (
                map<int, Clase*>::iterator it = contenedorClases.begin();
                it != contenedorClases.end();
                ++it
     ){
                    if(cuentaAsignada==(it->second)->getCuentaAsignada()){
                        return (it->second);
                    }
     }
     return NULL;

}

}
