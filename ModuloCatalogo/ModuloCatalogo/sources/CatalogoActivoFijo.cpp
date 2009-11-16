
#include "../headers/CatalogoActivoFijo.h"
#include "../../../Basico/headers/Unidad.h"
#include "../headers/EspecificacionBien.h"
#include <iostream>


#include "../../Persistencia/persistencia_global.h"
#include "../../Persistencia/persistencia.h"

using namespace std;
namespace moduloinventario {

CatalogoActivoFijo::CatalogoActivoFijo(RegistroCatalogo *_regCatalogo){
    this->regCatalogo=_regCatalogo;
}

void CatalogoActivoFijo::cargarCatalogo(){
    Persistencia::Persistencia *servicioPersistencia=new Persistencia();
    servicioPersistencia->cargar(this);
}

EspecActivoFijo * CatalogoActivoFijo::crearEspecActivoFijo(moduloinventario::Clase *claseAsignada){

    int codigoNuevaEspec=this->contenedorEspecAF.size()+1;
    EspecActivoFijo *nueva=new EspecActivoFijo(codigoNuevaEspec,claseAsignada );
    contenedorEspecAF[codigoNuevaEspec]=nueva;
    return nueva;
}

EspecMaterialBibliografico * CatalogoActivoFijo::crearEspecMaterialBibliografico(Clase *claseAsignada){
    int codigoNuevaEspec=contenedorEspecMB.size()+1;
    EspecMaterialBibliografico *nueva=new EspecMaterialBibliografico(codigoNuevaEspec, claseAsignada);
    contenedorEspecMB[codigoNuevaEspec]=nueva;
    return nueva;
}

std::list<string> CatalogoActivoFijo::getDescripciones(){

    std::list<string> listaDescripciones;

    for
    (
          map<int, EspecActivoFijo*>::iterator it =  contenedorEspecAF.begin();
          it != contenedorEspecAF.end();
          ++it
    )
    {
              listaDescripciones.push_back(it->second->getDescipcion());              
    }

    return listaDescripciones;

}


std::list<string> CatalogoActivoFijo::getMarcas(string nombreDescripcion){
    std::list<string> listaMarcas;
    std::list<string> lista;

    for
    (
          map<int, EspecActivoFijo*>::iterator it =  contenedorEspecAF.begin();
          it != contenedorEspecAF.end();
          ++it
    )
    {
              if(it->second->getDescipcion()==nombreDescripcion){
                  lista= (it->second->getMarcas());
                  for
                  (
                   list<string>::iterator from = lista.begin();
                   from != lista.end();
                   ++from
                   )
                   listaMarcas.push_back(*from);
               }
    }

    return listaMarcas;
}

std::list<string> CatalogoActivoFijo::getModelos(string nombreMarca){

    std::list<string> listaModelos;
    std::list<string> lista;

    for
    (
          map<int, EspecActivoFijo*>::iterator it =  contenedorEspecAF.begin();
          it != contenedorEspecAF.end();
          ++it
    )
    {
              lista=(it->second->getModelos(nombreMarca));
              for
              (
                   list<string>::iterator from = lista.begin();
                   from != lista.end();
                   ++from
               ){
                       listaModelos.push_back(*from);
               }

    }
    return listaModelos;

}

bool CatalogoActivoFijo::existeDescripcion(string descripcion){
    bool existe=false;
    for
    (
          map<int, EspecActivoFijo*>::iterator it =  contenedorEspecAF.begin();
          it != contenedorEspecAF.end();
          ++it
    )
    {
              if(it->second->getDescipcion()==descripcion){
                  return true;
              }
    }
    return existe;

}

EspecActivoFijo * CatalogoActivoFijo::getEspecificacion(string clase, string cuentaAsignada){
    for
    (
          map<int, EspecActivoFijo*>::iterator it =  contenedorEspecAF.begin();
          it != contenedorEspecAF.end();
          ++it
    )
    {

          if(it->second->getClase()->getCuentaAsignada() == cuentaAsignada ){

              if(it->second->getClase()->getNombreClase()==clase){
                  return it->second;
              }
          }
    }
    return NULL;

}


EspecActivoFijo * CatalogoActivoFijo::getEspecificacion(int oid){
    for
    (
          map<int, EspecActivoFijo*>::iterator it =  contenedorEspecAF.begin();
          it != contenedorEspecAF.end();
          ++it
    )
    {

          if(it->second->oid_especbien == oid ){
              return it->second;
          }
    }
    return NULL;

}

EspecMaterialBibliografico * CatalogoActivoFijo::getEspecificacionMB(string clase, string cuentaAsignada){


    for
    (
          map<int, EspecMaterialBibliografico*>::iterator it =  contenedorEspecMB.begin();
          it != contenedorEspecMB.end();
          ++it
    )
    {

          if(it->second->getClase()->getCuentaAsignada() == cuentaAsignada ){


              if(it->second->getClase()->getNombreClase()==clase){
                  return it->second;
              }
          }
    }
    return NULL;

}

}
