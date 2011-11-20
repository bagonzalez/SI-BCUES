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
#include "../../../Basico/Basico_global.h"
#include "../../../Basico/basico.h"
#include "Fecha.h"
#include "Tiempo.h"
#include <string>
#include <map>
#include <list>
using namespace std;

namespace contabilidad
{

    using namespace basico;

    class Cuenta;
    class Subcuenta;
    class PeriodoContable;
    class Transaccion;
    class Catalogo;

    class MODULOCONTABLESHARED_EXPORT RegistroSistemaContable
    {
    public:
        RegistroSistemaContable( basico::Registro *_regBasico);

        ~RegistroSistemaContable();

        void crearCatalogo(Fecha fechaCreacion, bool existe, bool inventario);        

        void crearPeriodoContable(Fecha fechaInicio, Fecha fechaFin);

        int crearTransaccion(Fecha *_fechaTran);

        Subcuenta * crearSubCuenta(string madre, string nombreNuevaCuenta, string descricion);

        Subcuenta * crearSubCuenta(string madre, string nombreNuevaCuenta, string codigo, string descricion, int id, bool nueva);

        void introducirInformacionTransaccion(float importe, bool esCargo, string nombreCuenta, int codigoTransaccion);

        Cuenta * getDireccionCuenta(string nombreCuenta);

        float getSaldoCuenta(string cuenta);

        Subcuenta * getDireccionSubCuenta(string nombreCuenta);

        Subcuenta * getSubCuentaCod(string codigo);

        void crearRubro(string nombreRubro, string descripcion, bool nueva, int id, string codigo, string tipoDes);

        int getTipoCuenta(string nombreCuenta);

        Subcuenta * crearCategoria(string nombreMadre, string nombreCategoria, string codigo, string descripcion, int id, bool neuva, string tipoCuent, string tipoDestino);

        std::list<string> getHijosCuenta(string NombreCuenta);

        map<string, string> getHijosCuentaCodigos(string NombreCuenta);

        map<string, string> getNombreDescripcionHijos(string nombreCuenta);

        std::map<string, string> getHijosCatalogo();

        int getCodCatCuenta(string nombreCuenta);

        int totalTansacciones();




    private:
        bool primeraVez;        

        int idControlador;

        int duracionPeriodo;

        string nombreContador;

        int PeriodoActual;


    public:
        std::map<int,PeriodoContable*> pertenecenPeriodos;

        Catalogo * catalogo;

        basico::Registro *regBasico;


    };
}
#endif
