#include "../headers/RegistroCatalogo.h"
#include "../headers/IngresoClaseCatalogo.h"

using namespace std;
namespace moduloinventario {

RegistroCatalogo::RegistroCatalogo(){
    this->crearCatalogo();
}

int RegistroCatalogo::crearIngreso(Fecha *_fechaIngreso, Tiempo *_horaIngreso){
    int codigoIngreso=contenedorIngresos.size()+1;
    contenedorIngresos[codigoIngreso]=new IngresoClaseCatalogo(_fechaIngreso, _horaIngreso, codigoIngreso, this);
    //contenedorIngresos[codigoIngreso]->setFechaTransaccion(_fechaTran);
    return contenedorIngresos[codigoIngreso]->getCodigoIngreso();
}

void RegistroCatalogo::introducirInformacion(string autor, string titulo, string isbn, int codIngreso){
    this->contenedorIngresos[codIngreso]->introducirInformacion( autor, titulo, isbn);
}

void RegistroCatalogo::introducirInformacion(string descripcion, string marca, string modelo, string serie,  int codIngreso){
    this->contenedorIngresos[codIngreso]->introducirInformacion( descripcion, marca, modelo, serie);
}

void RegistroCatalogo::crearEspecMatBiblio(contabilidad::Subcuenta *cuentaAsignada, int codIngreso, string clase){
   EspecMaterialBibliografico *nueva= this->catalogoActivoFijo->crearEspecMaterialBibliografico(cuentaAsignada, clase);
   this->contenedorIngresos[codIngreso]->crearEspecMatBiblio(nueva);
}

void RegistroCatalogo::crearEspecActivoF(contabilidad::Subcuenta *cuentaAsignada, int codIngreso, string clase){
    EspecActivoFijo *nueva=this->catalogoActivoFijo->crearEspecActivoFijo(cuentaAsignada, clase);
    this->contenedorIngresos[codIngreso]->crearEspecActivoF(nueva);
}



void RegistroCatalogo::crearCatalogo(){
    this->catalogoActivoFijo=new CatalogoActivoFijo();
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

EspecActivoFijo * RegistroCatalogo::getEspecificacion(string clase){
    return this->catalogoActivoFijo->getEspecificacion(clase);
}

EspecMaterialBibliografico * RegistroCatalogo::getEspecificacionMB(string clase){
    return this->catalogoActivoFijo->getEspecificacionMB(clase);
}

void RegistroCatalogo::setMarca(string marca, EspecActivoFijo *espec){
    espec->setMarca(marca);
}

void RegistroCatalogo::setModelo(string marca, string modelo, EspecActivoFijo *espec){
    espec->setModelo(marca, modelo);
}
}
