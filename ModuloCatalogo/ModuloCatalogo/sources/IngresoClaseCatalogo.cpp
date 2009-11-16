
#include "../../Persistencia/persistencia_global.h"
#include "../../Persistencia/persistencia.h"

#include "../headers/IngresoClaseCatalogo.h"
#include "../headers/EspecificacionBien.h"
#include "../../../Basico/headers/Usuario.h"


namespace moduloinventario {

IngresoClaseCatalogo::IngresoClaseCatalogo(Fecha *_fechaIngreso, Tiempo *_horaIngreso, int _idIngreso, RegistroCatalogo *reg, basico::Usuario *_usuario){
    this->fechaIngreso=_fechaIngreso;
    this->horaIngreso=_horaIngreso;
    this->idIngreso=_idIngreso;
    this->registro=reg;
    this->usuario=_usuario;

    Persistencia::Persistencia *servicioPersistencia=new Persistencia();
    servicioPersistencia->guarda(this);
}

void IngresoClaseCatalogo::setOID(){

    Persistencia::Persistencia *servicioPersistencia=new Persistencia();
    servicioPersistencia->setID(this);
}

int IngresoClaseCatalogo::getCodigoIngreso(){
    return this->idIngreso;
}

void  IngresoClaseCatalogo::crearEspecActivoF(EspecActivoFijo *espec){
    this->especActFijo=espec;
    Persistencia::Persistencia *servicioPersistencia=new Persistencia();    
    servicioPersistencia->actualizar(this, espec);
}

void IngresoClaseCatalogo::crearEspecMatBiblio(EspecMaterialBibliografico *espec){
    this->especMatBibliografico=espec;
    Persistencia::Persistencia *servicioPersistencia=new Persistencia();
    servicioPersistencia->actualizar(this, espec);
}

void IngresoClaseCatalogo::introducirInformacionMB(string autor, string titulo, string apellido,  string descripcion, string isbn){
    this->especMatBibliografico->setAutor(autor, apellido);
    this->especMatBibliografico->setTitulo(autor, apellido, titulo, isbn);
    this->especMatBibliografico->setDescripcion(descripcion);

    Persistencia::Persistencia *servicioPersistencia=new Persistencia();
    servicioPersistencia->guardarInfo(this->especMatBibliografico, autor, titulo, apellido, descripcion, isbn );
}

void  IngresoClaseCatalogo::introducirInformacionAF(string descripcion, string marca, string modelo){
    this->especActFijo->setDescripcion(descripcion);
    this->especActFijo->setMarca(marca);
    this->especActFijo->setModelo(marca, modelo);
    Persistencia::Persistencia *servicioPersistencia=new Persistencia();
    servicioPersistencia->guardarInfo(this->especActFijo, marca, modelo, descripcion);
}
}
