#include "../headers/RegistroCatalogo.h"
#include "../headers/IngresoClaseCatalogo.h"

using namespace std;

namespace moduloinventario
{

    RegistroCatalogo::RegistroCatalogo(basico::Usuario *_usuario, contabilidad::RegistroSistemaContable *_regContable)
    {
        this->crearCatalogo();
        this->usuario=_usuario;
        this->regContable=_regContable;
    }

    int RegistroCatalogo::crearIngreso(Fecha *_fechaIngreso, Tiempo *_horaIngreso)
    {
        int codigoIngreso=contenedorIngresos.size()+1;
        contenedorIngresos[codigoIngreso]=new IngresoClaseCatalogo(_fechaIngreso, _horaIngreso, codigoIngreso, this, this->usuario);
        contenedorIngresos[codigoIngreso]->setOID();
        return contenedorIngresos[codigoIngreso]->getCodigoIngreso();
    }

    int RegistroCatalogo::crearClase(Subcuenta *cuentaAsignada, string nombreClase)
    {
        int idClase=contenedorClases.size()+1;
        contenedorClases[idClase]=new Clase(cuentaAsignada, nombreClase, idClase);               
        return contenedorClases[idClase]->getCodigoClase();
    }

    void RegistroCatalogo::crearEspec(contabilidad::Subcuenta *cuentaAsignada,  int codIngreso, string clase)
    {
        int codClase=this->crearClase(cuentaAsignada,  clase);
        EspecificacionBien *nueva=this->catalogoActivoFijo->crearEspec(contenedorClases[codClase]);
        this->contenedorIngresos[codIngreso]->crearEspecActivoF(nueva);
    }

    EspecificacionBien * RegistroCatalogo::cargarEspec(contabilidad::Cuenta *cuentaAsignada, string clase)
    {
        int idClase=contenedorClases.size()+1;
        Clase *nuevaClase=new Clase(cuentaAsignada, clase, idClase);
        contenedorClases[idClase]=nuevaClase;        
        EspecificacionBien *nueva=this->catalogoActivoFijo->crearEspec(contenedorClases[idClase]);
        return nueva;
    }

    void RegistroCatalogo::crearCatalogo()
    {
        this->catalogoActivoFijo=new CatalogoActivoFijo(this);
    }

    void RegistroCatalogo::cargarCatalogo(int invAFijo)
    {
        this->catalogoActivoFijo->cargarCatalogo(invAFijo);
    }

    std::list<string> RegistroCatalogo::getDescripciones()
    {
        return this->catalogoActivoFijo->getDescripciones();
    }

    bool RegistroCatalogo::existeDescripcion(string descripcion)
    {
        return this->catalogoActivoFijo->existeDescripcion(descripcion);
    }

    EspecificacionBien * RegistroCatalogo::getEspecificacion(string clase, string cuentaAsignada)
    {
        return this->catalogoActivoFijo->getEspecificacion(clase, cuentaAsignada);
    }


    EspecificacionBien * RegistroCatalogo::getEspecificacion(int oid)
    {
        return this->catalogoActivoFijo->getEspecificacion(oid);
    }



    bool RegistroCatalogo::existeClase(string nombreClase, string cuentaAsignada)
    {

        if (this->getEspecificacion(nombreClase, cuentaAsignada) != NULL)
            return true;

        return false;
    }

    std::list<string> RegistroCatalogo::getClases(string cuentaAsignada)
    {

        std::list<string> listaClases;

        for
        (
            map<int, Clase*>::iterator it = contenedorClases.begin();
            it != contenedorClases.end();
            ++it
        )
        {
            if (cuentaAsignada==(it->second)->getCuentaAsignada())
            {                
                listaClases.push_back((it->second)->getNombreClase());
            }
        }
        return listaClases;

    }

    Clase * RegistroCatalogo::getClase(string nombreClase, string cuentaAsignada )
    {

        for
        (
            map<int, Clase*>::iterator it = contenedorClases.begin();
            it != contenedorClases.end();
            ++it
        )
        {
            if (cuentaAsignada==(it->second)->getCuentaAsignada())
            {
                return (it->second);
            }
        }
        return NULL;

    }

}
