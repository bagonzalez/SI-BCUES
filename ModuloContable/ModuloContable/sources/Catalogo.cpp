#include "../Persistencia/Persistencia_global.h"
#include "../Persistencia/persistencia.h"
#include <iostream>
#include "../headers/Catalogo.h"
#include "../headers/Cuenta.h"
#include "../headers/Subcuenta.h"
#include "../headers/RegistroSistemaContable.h"

namespace contabilidad
{

    Catalogo::Catalogo(Fecha fechaCreacion, Unidad *_unidad, RegistroSistemaContable *reg, bool inventario)
    {
        if(!inventario){
            this->almacenado_en=reg;
            this->unidad=_unidad;
            Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->almacenado_en );
            servicioPersistencia->guardarCatalogoContable(this);
        }        

    }

    Catalogo::Catalogo(Unidad *_unidad, RegistroSistemaContable *reg, bool inventario)
    {
        this->unidad=_unidad;
        this->almacenado_en=reg;

        if(!inventario)
        {
            Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->almacenado_en);
            servicioPersistencia->cargarCatalogoContable(this, "agrupacionecomica");
        }else{
            Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->almacenado_en);
            servicioPersistencia->cargarCatalogoContable(this, "inventario");
        }
    }

    Cuenta * Catalogo::getCuenta(string codigoCuenta)
    {
        Cuenta *cuenta=NULL;

        for
        (
            map<string, Cuenta*>::iterator it =  myCuenta.begin();
            it != myCuenta.end();
            ++it
        )
        {
            if(((Cuenta*)it->second)->getcodigoCuenta()==codigoCuenta)
                cuenta=it->second;

        }
        return cuenta;
    }

    Subcuenta * Catalogo::getSubCuenta(string nombreCuenta)
    {
        Subcuenta *cuenta=NULL;
        for
        (
            map<string, Cuenta*>::iterator it =  myCuenta.begin();
            it != myCuenta.end();
            ++it
        )
        {
            if ((it->second)->getSubCuenta(nombreCuenta)!=NULL)
                cuenta=(it->second)->getSubCuenta(nombreCuenta);
        }
        return cuenta;
    }

    Subcuenta * Catalogo::getSubCuentaCod(string codigo){
        Subcuenta *cuenta=NULL;
        for
        (
            map<string, Cuenta*>::iterator it =  myCuenta.begin();
            it != myCuenta.end();
            ++it
        )
        {
            if ((it->second)->getSubCuentaCod(codigo)!=NULL)
                cuenta=(it->second)->getSubCuentaCod(codigo);
        }
        return cuenta;
    }


    void Catalogo::crearRubro(string nombreRubro, string descripcion, bool cnueva, int id, string codigoRubro, string tipoDest)
    {
        Cuenta  *nueva;

        contabilidad::tipoDestino destino;

        if(tipoDest=="ingreso")
            destino=contabilidad::ingreso;
        if(tipoDest=="gasto")
            destino=contabilidad::gasto;


        nueva=new Cuenta(nombreRubro, codigoRubro, contabilidad::agrupacionecomica, descripcion, this, cnueva, id, destino  );
        nueva->cuentaMadre=NULL;        
        nueva->setID(id);
        nueva->myCatalogo=this;
        nueva->cargarHijos(this->id);
        myCuenta[nombreRubro]=nueva;        
    }


    Subcuenta * Catalogo::crearCategoria(string codigoMadre, string nombreCategoria, string codigo, string descripcion, int id, bool _nueva, string tipoCue, string tipoDest)
    {
        Cuenta *madre;
        Subcuenta *subMadre;
        madre=this->getCuenta(codigoMadre);

        contabilidad::tipoCuenta tipo;
        contabilidad::tipoDestino destino;

        if(tipoCue=="agrupacionecomica")
            tipo=contabilidad::agrupacionecomica;
        if(tipoCue=="rubro")
            tipo=contabilidad::rubro;
        if(tipoCue=="cuenta")
            tipo=contabilidad::cuenta;
        if(tipoCue=="especificos")
            tipo=contabilidad::especificos;
        if(tipoCue=="inventario")
            tipo=contabilidad::inventario;


        if(tipoDest=="ingreso")
            destino=contabilidad::ingreso;
        if(tipoDest=="gasto")
            destino=contabilidad::gasto;

        if (madre==NULL)
        {
            subMadre=this->getSubCuentaCod(codigoMadre);
            if (subMadre!=NULL)
                return subMadre->crearSubCuenta(nombreCategoria, tipo, codigo, descripcion, id, _nueva, destino);
        }
        else
            return  madre->crearSubCuenta(nombreCategoria,tipo, codigo, descripcion, id, _nueva, destino);

        return NULL;
    }


    int Catalogo::getCodCatCuenta(string nombreCuenta, int base)
    {
        /*int codigoCatalogo;
        string nombreMadre;
        Subcuenta *cuenta;
        Cuenta *rubro;
        cuenta=this->getSubCuenta(nombreCuenta);
        rubro=this->getCuenta(nombreCuenta);

        if (cuenta!=NULL)
        {
            nombreMadre=cuenta->cuentaMadre->getNombreCuenta();
            return codigoCatalogo=cuenta->getcodigoCuenta()*base+getCodCatCuenta(nombreMadre, base*10);
        }

        if (rubro!=NULL)
        {
            codigoCatalogo=rubro->getcodigoCuenta()*base;
        }

        return codigoCatalogo;*/
        return 0;
    }

    list<string> Catalogo::getHijosCuenta(string nombreCuenta)
    {
        Cuenta *cuenta=this->getCuenta(nombreCuenta);
        Subcuenta *subcuenta=this->getSubCuenta(nombreCuenta);
        list<string> listHijos;

        if (cuenta!=NULL)
        {
            listHijos=cuenta->getListaHijos();
        }

        if (subcuenta!=NULL)
        {
            listHijos=subcuenta->getListaHijos();
        }
        return listHijos;
    }
    
    map<string, string> Catalogo::getNombreDescripcionHijos(string nombreCuenta)
    {
        Cuenta *cuenta=this->getCuenta(nombreCuenta);
        Subcuenta *subcuenta=this->getSubCuenta(nombreCuenta);
        map<string, string> listHijos;

        if (cuenta!=NULL)
        {
            listHijos=cuenta->getNombreDescripcionHijos();
        }

        if (subcuenta!=NULL)
        {
            listHijos=subcuenta->getNombreDescripcionHijos();
        }
        return listHijos;
    }

    map<string, string> Catalogo::getHijosCuentaCodigos(string nombreCuenta)
    {
        Cuenta *cuenta=this->getCuenta(nombreCuenta);
        Subcuenta *subcuenta=this->getSubCuentaCod(nombreCuenta);
        map<string, string> listHijos;

        if (cuenta!=NULL)
        {
            listHijos=cuenta->getCodigosHijos();
        }

        if (subcuenta!=NULL)
        {
            listHijos=subcuenta->getCodigosHijos();
        }
        return listHijos;
    }



    map<string, string> Catalogo::getHijosCatalogo()
    {

        map<string, string> listHijos;

        for
        (
            map<string, Cuenta*>::iterator it =  myCuenta.begin();
            it != myCuenta.end();
            ++it
        )
        {
            listHijos[it->second->getcodigoCuenta()]=it->first;
        }
        return listHijos;
    }

    void Catalogo::setID(int _id)
    {
        this->id=_id;
    }

    int Catalogo::getID()
    {
        return this->id;
    }


}
