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

#ifndef SUBCUENTA_H
#define SUBCUENTA_H



#include "Cuenta.h"
#include "../../ModuloContable_global.h"
#include <string>
#include <vector>
using namespace std;
namespace contabilidad
{

    class MODULOCONTABLESHARED_EXPORT Subcuenta : public Cuenta
    {
    public:
        Subcuenta(string nombreCuenta, string codSubcuenta, Cuenta * madre, string descripcion, Catalogo *catalogo, int id, bool nueva, tipoCuenta x, tipoDestino tipoDes);

        Subcuenta(string nombreSubcuenta, string codigoSubcuenta, Cuenta * madre, string descripcion, Catalogo *catalogo);

        virtual ~Subcuenta();

    private:
        int codigoSubCuenta;


        std::vector<Subcuenta*> mySubcuenta;

    };
}
#endif
