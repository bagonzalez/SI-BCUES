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

#ifndef _REGISTROSISTEMACONTABLE_H
#define _REGISTROSISTEMACONTABLE_H

#include "../../ModuloContable_global.h"
#include "Fecha.h"
#include "Tiempo.h"
#include <string>
#include <map>
#include <list>
using namespace std;

namespace contabilidad {

class Cuenta;
class Subcuenta;
class PeriodoContable;
class Transaccion;
class Catalogo;

class MODULOCONTABLESHARED_EXPORT RegistroSistemaContable {
  public:
    RegistroSistemaContable(Fecha fechaInicio);

    void crearCatalogo(Fecha fechaCreacion, bool existe);

    void crearPeriodoContable(Fecha fechaInicio, Fecha fechaFin);

    int crearTransaccion(Fecha *_fechaTran);

    Subcuenta * crearSubCuenta(string madre, string nombreNuevaCuenta);

    Subcuenta * crearSubCuenta(string madre, string nombreNuevaCuenta, int codigo);

    void introducirInformacionTransaccion(float importe, bool esCargo, string nombreCuenta, int codigoTransaccion);

    Cuenta * getDireccionCuenta(string nombreCuenta);

    float getSaldoCuenta(string cuenta);

    Subcuenta * getDireccionSubCuenta(string nombreCuenta);

    void crearRubro(string nombreRubro);

    int getTipoCuenta(string nombreCuenta);

    Subcuenta * crearCategoria(string nombreMadre, string nombreCategoria);

    Subcuenta * crearCategoria(string nombreMadre, string nombreCategoria, int codigo);

    std::list<string> getHijosCuenta(string NombreCuenta);

    std::list<string> getHijosCatalogo();

    int getCodCatCuenta(string nombreCuenta);


  private:
    bool primeraVez;

    Fecha fechaInicio_Sistema;

    int idControlador;

    int duracionPeriodo;

    string nombreContador;

    int PeriodoActual;


  public:
    std::map<int,PeriodoContable*> pertenecenPeriodos;  

    Catalogo * catalogo;


};
}
#endif
