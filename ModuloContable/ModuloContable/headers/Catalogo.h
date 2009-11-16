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
#include "../../Basico/Basico_global.h"
#include "../../Basico/basico.h"
#include "../headers/Fecha.h"
#include <string>
#include <map>
#include <list>


using namespace std;
using namespace basico;
namespace contabilidad {

class Cuenta;
class Subcuenta;
class RegistroSistemaContable;


class MODULOCONTABLESHARED_EXPORT Catalogo {
  public:
     Catalogo(Fecha fechaCreacion, basico::Unidad *unidad, RegistroSistemaContable *reg);

     Catalogo(Unidad *_unidad, RegistroSistemaContable *reg);

     Cuenta * getCuenta(string nombreCuenta);

     Subcuenta * getSubCuenta(string nombreCuenta);

     void setFechaActualizacion(Fecha fechaActualizacion);

     void setFechaCreacion(Fecha fechaCreacion);

     void crearRubro(string nombreRubro, string descripcion, bool nueva, int id);

     Subcuenta * crearCategoria(string nombreMadre, string nombreCategoria, string descripcion, int id);

     Subcuenta * crearCategoria(string nombreMadre, string nombreCategoria, int codigo, string descripcion, int id, bool nueva);

      int getCodCatCuenta(string nombreCuenta, int base);

     list<string> getHijosCuenta(string nombreCuenta);

     map<int, string> getHijosCuentaCodigos(string nombreCuenta);

     list<string> getHijosCatalogo();

     void setID(int id);

     int getID();


  public:
    Fecha fechaUltimaActualizacion;

    Fecha fechaCreacion;


  public:
    RegistroSistemaContable *almacenado_en;

    Unidad *unidad;

    int id;

    std::map<string,Cuenta*> myCuenta;

};
}
#endif
