
#include "../headers/CatalogoActivoFijo.h"
#include "../../../Basico/headers/Unidad.h"
#include "../headers/EspecificacionBien.h"

using namespace std;
namespace moduloinventario {

CatalogoActivoFijo::CatalogoActivoFijo(){    

}

EspecActivoFijo * CatalogoActivoFijo::crearEspecActivoFijo(contabilidad::Subcuenta *cuentaAsignada, string clase){

    int codigoNuevaEspec=this->contenedorEspecAF.size()+1;
    EspecActivoFijo *nueva=new EspecActivoFijo(codigoNuevaEspec, cuentaAsignada, clase);
    contenedorEspecAF[codigoNuevaEspec]=nueva;
    return nueva;
}

EspecMaterialBibliografico * CatalogoActivoFijo::crearEspecMaterialBibliografico(Subcuenta *cuentaAsignada){
    int codigoNuevaEspec=contenedorEspecMB.size()+1;
    EspecMaterialBibliografico *nueva=new EspecMaterialBibliografico(codigoNuevaEspec, cuentaAsignada);
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

EspecActivoFijo * CatalogoActivoFijo::getEspecificacion(string clase){
    for
    (
          map<int, EspecActivoFijo*>::iterator it =  contenedorEspecAF.begin();
          it != contenedorEspecAF.end();
          ++it
    )
    {
              if(it->second->getClase()==clase){
                  return it->second;
              }
    }
    return NULL;

}

EspecMaterialBibliografico * CatalogoActivoFijo::getEspecificacionMB(string clase){
    for
    (
          map<int, EspecMaterialBibliografico*>::iterator it =  contenedorEspecMB.begin();
          it != contenedorEspecMB.end();
          ++it
    )
    {
              if(it->second->getClase()==clase){
                  return it->second;
              }
    }
    return NULL;

}

}
