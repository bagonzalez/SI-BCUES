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


#include "../headers/Fecha.h"
#include <string>
#include <map>
#include <list>

using namespace std;

namespace contabilidad {
class Cuenta;
class Subcuenta;
class RegistroSistemaContable;


class Catalogo {
  public:
     Catalogo(Fecha fechaCreacion);

     Cuenta * getCuenta(string nombreCuenta);

     Subcuenta * getSubCuenta(string nombreCuenta);

     void setFechaActualizacion(Fecha fechaActualizacion);

     void setFechaCreacion(Fecha fechaCreacion);

     void crearRubro(string nombreRubro);

     Subcuenta * crearCategoria(string nombreMadre, string nombreCategoria);

     Subcuenta * crearCategoria(string nombreMadre, string nombreCategoria, int codigo);

      int getCodCatCuenta(string nombreCuenta, int base);

     list<string> getHijosCuenta(string nombreCuenta);

     list<string> getHijosCatalogo();


  private:
    Fecha fechaUltimaActualizacion;

    Fecha fechaCreacion;


  public:
    RegistroSistemaContable * almacenado_en;

    std::map<string,Cuenta*> myCuenta;

};
}
#endif
