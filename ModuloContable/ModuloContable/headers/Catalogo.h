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


#ifndef _CATALOGO_H
#define _CATALOGO_H


#include "../../ModuloContable_global.h"
#include "../../../Basico/Basico_global.h"
#include "../../../Basico/basico.h"
#include "../headers/Fecha.h"
#include <string>
#include <map>
#include <list>


using namespace std;
using namespace basico;
namespace contabilidad
{

    class Cuenta;
    class Subcuenta;
    class RegistroSistemaContable;


    class MODULOCONTABLESHARED_EXPORT Catalogo
    {
    public:
        Catalogo(Fecha fechaCreacion, basico::Unidad *unidad, RegistroSistemaContable *reg, bool inventario);

        Catalogo(Unidad *_unidad, RegistroSistemaContable *reg, bool inventario);

        Cuenta * getCuenta(string codigoCuenta);

        Subcuenta * getSubCuenta(string nombreCuenta);

        Subcuenta * getSubCuentaCod(string codigo);

        void crearRubro(string nombreRubro, string descripcion, bool nueva, int id, string codigoRubro, string tipoDes);

        Subcuenta * crearCategoria(string codigoMadre, string nombreCategoria, string codigo, string descripcion, int id, bool nueva, string tipoCuenta, string tipoDest);

        int getCodCatCuenta(string nombreCuenta, int base);

        list<string> getHijosCuenta(string nombreCuenta);

        map<string, string> getHijosCuentaCodigos(string nombreCuenta);

        map<string, string> getNombreDescripcionHijos(string nombreCuenta);

        map<string, string> getHijosCatalogo();

        void setID(int id);

        int getID();




    public:
        RegistroSistemaContable *almacenado_en;

        Unidad *unidad;

        int id;

        std::map<string,Cuenta*> myCuenta;

    };
}
#endif
