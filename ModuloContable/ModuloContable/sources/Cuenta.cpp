
#include "../Persistencia/Persistencia_global.h"
#include "../Persistencia/persistencia.h"

#include "../headers/Cuenta.h"
#include "../headers/Subcuenta.h"
#include "../headers/Catalogo.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace contabilidad
{

    Cuenta::Cuenta(string _nombreCuenta, string _codigoCuenta, string _descripcion, Catalogo *catalogo, int _id, Cuenta *_cuentaMadre, contabilidad::tipoCuenta x, tipoDestino _tipoDes    )
    {
        this->id=_id;
        this->cuentaMadre=_cuentaMadre;
        this->nombreCuenta=_nombreCuenta;
        this->codigoCuenta=_codigoCuenta;
        this->debe=this->haber=0.0;
        this->descripcion=_descripcion;
        this->myCatalogo=catalogo;
        this->tipoC=x;
        this->setTipoC();
        this->tipoDes=_tipoDes;
        this->setTipoDes();
    }

    Cuenta::Cuenta(string _nombreCuenta, string _codigoCuenta, string _descripcion, Catalogo *catalogo)
    {
        this->nombreCuenta=_nombreCuenta;
        this->codigoCuenta=_codigoCuenta;
        this->debe=this->haber=0.0;
        this->descripcion=_descripcion;
        this->myCatalogo=catalogo;
        this->tipoC=inventario;
    }


    Cuenta::~Cuenta()
    {
    }

    Cuenta::Cuenta(string _nombre, string _codigo, tipoCuenta x, string _descripcion, Catalogo *catalogo , bool nueva, int _id, contabilidad::tipoDestino _tipoDes)
    {

        this->nombreCuenta=_nombre;
        this->codigoCuenta=_codigo;
        this->debe=this->haber=0.0;
        this->tipoC=x;
        this->descripcion=_descripcion;
        this->myCatalogo=catalogo;
        this->tipoDes=_tipoDes;
        this->setTipoDes();

        this->id=_id;

        setTipoC();

        if (nueva)
        {
            Persistencia::Persistencia *servicioPersistencia=new Persistencia(catalogo->unidad->id);
            servicioPersistencia->guardarCuenta(this);

        }

    }

    void Cuenta::cargarHijos(int idCatalogo){
        Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->myCatalogo->unidad->id);
        servicioPersistencia->cargarCuentas(this, idCatalogo);
    }

    void Cuenta::setTipoDes(){
        switch (this->tipoDes)
        {

        case contabilidad::ingreso:
        {
            this->tipoDestString="ingreso";
        }
        break;

        case contabilidad::gasto:
        {
            this->tipoDestString="gasto";
        }
        break;

        }
    }

    void Cuenta::setTipoC()
    {        

        switch (this->tipoC)
        {

        case contabilidad::agrupacionecomica:
        {
            this->tipoCuent="agrupacionecomica";
        }
        break;

        case contabilidad::rubro:
        {
            this->tipoCuent="rubro";
        }
        break;

        case contabilidad::cuenta:
        {
            this->tipoCuent="cuenta";
        }
        break;

        case contabilidad::especificos:
        {
            this->tipoCuent="especificos";
        }
        break;

        case contabilidad::inventario:
        {
            this->tipoCuent="inventario";
        }
        break;
        }
    }


    void Cuenta::cargarCuenta(float cantidadImporte)
    {

        if (this->tipoC==especificos || this->tipoC==inventario)
        {
            this->debe=this->debe+cantidadImporte;
        }
    }

    void Cuenta::abonarCuenta(float cantidadImporte)
    {

        if (this->tipoC==especificos || this->tipoC==inventario)
        {
            this->haber=this->haber+cantidadImporte;
        }
    }

    void Cuenta::setSaldarCuenta()
    {

        this->cuentaSaldada=true;
    }

    float Cuenta::getSaldo()
    {

        float saldo=0.0;
        if (this->mySubcuenta.empty())
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


    void Cuenta::ajustarCuenta(float cantidadAjustar)
    {


    }

    string Cuenta::getNombreCuenta()
    {

        return this->nombreCuenta;
    }

    bool Cuenta::getSaldada()
    {

        return false;
    }

    string Cuenta::getcodigoCuenta()
    {
        return this->codigoCuenta;
    }

    Subcuenta * Cuenta::crearSubCuenta(string nombreSubcuenta, tipoCuenta x, string descricion)
    {
        Subcuenta  *nueva;
        /*char codigo[256];
        int tamanoContenedor=this->mySubcuenta.size();
        sprintf(codigo, "%d", tamanoContenedor);*/

        nueva=new Subcuenta(nombreSubcuenta, "0", this, descripcion, this->myCatalogo);
        nueva->tipoC=x;
        nueva->setTipoC();
        mySubcuenta[nombreSubcuenta]=nueva;
        return nueva;
    }

    Subcuenta * Cuenta::crearSubCuenta(string nombreSubcuenta, tipoCuenta x, string codigo, string descricion, int id, bool _nueva, tipoDestino destino)
    {
        Subcuenta  *nueva;
        nueva=new Subcuenta(nombreSubcuenta, codigo, this, descricion, this->myCatalogo, id, _nueva, x, destino);
        mySubcuenta[nombreSubcuenta]=nueva;
        return nueva;
    }


    Subcuenta * Cuenta::getSubCuenta(string nombreCuenta)
    {

        Subcuenta *cuenta=NULL;


        for
        (
            map<string, Subcuenta*>::iterator it = mySubcuenta.begin();
            it != mySubcuenta.end();
            ++it
        )
        {
            if (it->first==nombreCuenta)
                return cuenta=it->second;
        }

        for
        (
            map<string, Subcuenta*>::iterator et = mySubcuenta.begin();
            et != mySubcuenta.end();
            ++et
        )
        {
            if ((et->second)->getSubCuenta(nombreCuenta)!=NULL)
                return cuenta=(et->second)->getSubCuenta(nombreCuenta);
        }

        return cuenta;
    }


    Subcuenta * Cuenta::getSubCuentaCod(string codigo)
    {

        Subcuenta *cuenta=NULL;

        map<string, string> lista=this->getCodigosHijos();

        for
        (
            map<string, string>::iterator it = lista.begin();
            it != lista.end();
            ++it
        )
        {
            if (it->first==codigo)
                return cuenta=mySubcuenta[it->second];
        }

        for
        (
            map<string, Subcuenta*>::iterator et = mySubcuenta.begin();
            et != mySubcuenta.end();
            ++et
        )
        {
            if ((et->second)->getSubCuentaCod(codigo)!=NULL)
                return cuenta=(et->second)->getSubCuentaCod(codigo);
        }

        return cuenta;
    }



    tipoCuenta Cuenta::getTipoC()
    {

        return this->tipoC;
    }

    tipoDestino Cuenta::getTipoDes()
    {
        return this->tipoDes;
    }

    void Cuenta::setNombreCuenta(string _nombreCuenta)
    {

        this->nombreCuenta=_nombreCuenta;
    }

    float Cuenta::getDebe()
    {
        float saldodebe=0.0;
        if (this->tipoC==rubro || this->tipoC==cuenta)
        {
            if (this->mySubcuenta.empty())
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

    float Cuenta::getHaber()
    {
        float saldohaber=0.0;
        if (this->tipoC==rubro||this->tipoC==cuenta)
        {
            if (this->mySubcuenta.empty())
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

    string Cuenta::getDescripcion()
    {
        return this->descripcion;
    }

    std::list<string> Cuenta::getListaHijos()
    {

        list<string> listaHijos;

        for
        (
            map<string, Subcuenta*>::iterator it = mySubcuenta.begin();
            it != mySubcuenta.end();
            ++it
        )
        {
            listaHijos.push_back(it->first);
        }
        return listaHijos;
    }

    std::map<string, string> Cuenta::getCodigosHijos()
    {

        map<string, string> listaHijos;

        for
        (
            map<string, Subcuenta*>::iterator it = mySubcuenta.begin();
            it != mySubcuenta.end();
            ++it
        )
        {
            //std::cout << "Los codigos-->" << it->second->getcodigoCuenta() <<endl;
            listaHijos[it->second->getcodigoCuenta()]=it->second->getNombreCuenta();
        }
        return listaHijos;
    }

    map<string, string> Cuenta::getNombreDescripcionHijos(){

        map<string, string> listaHijos;

        for
        (
            map<string, Subcuenta*>::iterator it = mySubcuenta.begin();
            it != mySubcuenta.end();
            ++it
        )
        {
            listaHijos[it->second->getNombreCuenta()]=it->second->getDescripcion();
        }
        return listaHijos;

    }

    void Cuenta::setID()
    {
        Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->myCatalogo->unidad->id);
        servicioPersistencia->setID(this);

    }

    void Cuenta::setID(int _id)
    {
        this->id=_id;
    }

    int Cuenta::getID()
    {
        return this->id;
    }
}
