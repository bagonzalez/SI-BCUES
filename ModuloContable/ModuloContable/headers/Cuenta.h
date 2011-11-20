/***************************************************************************
 *   Copyright (C) 2008-2009 by Bruno Gonzalez                             *
 *   El Salvador                                                           *
 *   bruno2d@linux.ues.edu.sv                                              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifndef _CUENTA_H
#define _CUENTA_H



using namespace std;
#include <map>
#include <list>
#include <string>
#include "../../ModuloContable_global.h"

namespace contabilidad
{
    class Subcuenta;
    class Catalogo;


    enum tipoCuenta
    {
        agrupacionecomica,
        rubro,
        cuenta,
        especificos,
        inventario
    };

    enum tipoDestino
    {
        ingreso,
        gasto
    };

    class MODULOCONTABLESHARED_EXPORT Cuenta
    {
    public:
        Cuenta(string _nombreCuenta, string _codigoCuenta, string descripcion, Catalogo *catalogo, int id, Cuenta *_cuentaMadre, tipoCuenta x, tipoDestino _tipoDes  );

        Cuenta(string _nombreCuenta, string _codigoCuenta, string _descripcion, Catalogo *catalogo);

        virtual ~Cuenta();

        Cuenta(string _nombre, string _codigo, tipoCuenta x, string descripcion, Catalogo *catalogo , bool nueva, int _id, contabilidad::tipoDestino _tipoDes);

        void cargarCuenta(float cantidadImporte);

        void abonarCuenta(float cantidadImporte);

        void setSaldarCuenta();

        void cargarHijos(int idCatalogo);

        float getSaldo();

        void ajustarCuenta(float cantidadAjustar);

        string getNombreCuenta();

        bool getSaldada();

        virtual float getDebe();

        void setTipoC();

        void setTipoDes();

        bool existeCodigoSubcuenta(int codigo);

        virtual float getHaber();

        virtual string getDescripcion();

        string getcodigoCuenta();

        Subcuenta * crearSubCuenta(string nombreSubcuenta, tipoCuenta x, string descricion);

        Subcuenta * crearSubCuenta(string nombreSubcuenta, tipoCuenta x, string codigo, string descricion, int id, bool nueva, tipoDestino destino);

        Subcuenta * getSubCuenta(string nombreCuenta);

        Subcuenta * getSubCuentaCod(string codigo);

        tipoCuenta getTipoC();

        tipoDestino getTipoDes();

        std::list<string> getListaHijos();

        map<string, string> getCodigosHijos();

        map<string, string> getNombreDescripcionHijos();

        Cuenta * cuentaMadre;

        void setID();

        void setID(int id);

        int getID();

    public:
        virtual void setNombreCuenta(string _nombreCuenta);

        float debe;

        float haber;

        string codigoCuenta;

        string nombreCuenta;

        string descripcion;

        bool cuentaSaldada;

        tipoCuenta tipoC;

        tipoDestino tipoDes;

        string tipoCuent;

        string tipoDestString;

        map<string,Subcuenta*> mySubcuenta;

        int id;

    public:
        Catalogo * myCatalogo;

    };

}
#endif
