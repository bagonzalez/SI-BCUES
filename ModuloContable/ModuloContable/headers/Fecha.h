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

#ifndef _FECHA_H
#define _FECHA_H
#include "../../ModuloContable_global.h"
using namespace std;


class MODULOCONTABLESHARED_EXPORT Fecha
{
public:
    Fecha();

    Fecha(int _dia, int _mes, int _anio);

    int getMes();
    void setMes(int _mes);

    int getDia();
    void setDia(int _dia);

    int getAnio();
    void setAnio(int _anio);

    void imprimirFecha();

private:
    int dia;

    int mes;

    int anio;



};
#endif
