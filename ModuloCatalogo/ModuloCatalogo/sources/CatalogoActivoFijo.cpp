#include "../headers/CatalogoActivoFijo.h"
#include "../../../Basico/headers/Unidad.h"
#include "../headers/EspecificacionBien.h"
#include <iostream>


#include "../Persistencia/Persistencia_global.h"
#include "../Persistencia/persistencia.h"

using namespace std;
namespace moduloinventario
{

    CatalogoActivoFijo::CatalogoActivoFijo(RegistroCatalogo *_regCatalogo)
    {
        this->regCatalogo=_regCatalogo;
    }

    void CatalogoActivoFijo::cargarCatalogo(int invAFijo)
    {
        this->contenedorEspec.clear();
        Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regCatalogo->regContable);
        servicioPersistencia->cargarCatalogoAF(this, invAFijo);
    }

    EspecificacionBien * CatalogoActivoFijo::crearEspec(moduloinventario::Clase *claseAsignada)
    {

        int codigoNuevaEspec=this->contenedorEspec.size()+1;
        EspecificacionBien *nueva=new EspecificacionBien(codigoNuevaEspec,claseAsignada );
        contenedorEspec[codigoNuevaEspec]=nueva;
        return nueva;
    }



    std::list<string> CatalogoActivoFijo::getDescripciones()
    {

        std::list<string> listaDescripciones;

        for
        (
            map<int, EspecificacionBien*>::iterator it =  contenedorEspec.begin();
            it != contenedorEspec.end();
            ++it
        )
        {
            listaDescripciones.push_back(it->second->getDescipcion());
        }

        return listaDescripciones;

    }




    bool CatalogoActivoFijo::existeDescripcion(string descripcion)
    {
        bool existe=false;
        for
        (
            map<int, EspecificacionBien*>::iterator it =  contenedorEspec.begin();
            it != contenedorEspec.end();
            ++it
        )
        {
            if (it->second->getDescipcion()==descripcion)
            {
                return true;
            }
        }
        return existe;
    }

    EspecificacionBien * CatalogoActivoFijo::getEspecificacion(string clase, string cuentaAsignada)
    {
        for
        (
            map<int, EspecificacionBien*>::iterator it =  contenedorEspec.begin();
            it != contenedorEspec.end();
            ++it
        )
        {

            if (it->second->getClase()->getCuentaAsignada() == cuentaAsignada )
            {

                if (it->second->getClase()->getNombreClase()==clase)
                {
                    return it->second;
                }
            }
        }
        return NULL;

    }


    EspecificacionBien * CatalogoActivoFijo::getEspecificacion(int oid)
    {
        for
        (
            map<int, EspecificacionBien*>::iterator it =  contenedorEspec.begin();
            it != contenedorEspec.end();
            ++it
        )
        {

            if (it->second->oid_especbien == oid )
            {
                return it->second;
            }
        }
        return NULL;

    }




}
