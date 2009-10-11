
#include "../headers/IngresoClaseCatalogo.h"
#include "../headers/RegistroCatalogo.h"
#include "../headers/EspecificacionBien.h"
#include "../../../Basico/headers/Usuario.h"

namespace moduloinventario {

IngresoClaseCatalogo::IngresoClaseCatalogo(Fecha *_fechaIngreso, Tiempo *_horaIngreso, int _idIngreso, RegistroCatalogo *reg){
    this->fechaIngreso=_fechaIngreso;
    this->horaIngreso=_horaIngreso;
    this->idIngreso=_idIngreso;
    this->registro=reg;
}

int IngresoClaseCatalogo::getCodigoIngreso(){
    return this->idIngreso;
}

void  IngresoClaseCatalogo::crearEspecActivoF(EspecActivoFijo *espec){
    this->especActFijo=espec;
}

void IngresoClaseCatalogo::crearEspecMatBiblio(EspecMaterialBibliografico *espec){
    this->especMatBibliografico=espec;
}

void IngresoClaseCatalogo::introducirInformacionMB(string autor, string titulo, string isbn){
    this->especMatBibliografico->setAutor(autor);
    this->especMatBibliografico->setTitulo(titulo);
    this->especMatBibliografico->setISBN(isbn);
}

void  IngresoClaseCatalogo::introducirInformacionAF(string descripcion, string marca, string modelo){
    this->especActFijo->setDescripcion(descripcion);
    this->especActFijo->setMarca(marca);
    this->especActFijo->setModelo(marca, modelo);       
}
}
