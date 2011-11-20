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

#ifndef _PERIODOCONTABLE_H
#define _PERIODOCONTABLE_H

#include "../headers/Transaccion.h"
#include "../headers/RegistroSistemaContable.h"

#include "Fecha.h"
#include <map>
namespace contabilidad
{
    class Transaccion;
    class RegistroSistemaContable;

    class PeriodoContable
    {
    public:
        PeriodoContable(Fecha fechaInicio, Fecha fechaFin, int idPeriodo, RegistroSistemaContable *registro);

        Fecha getFechaInicio();

        Fecha getFechaFin();

        int getIdPeriodo();

        int crearTransaccion(Fecha *_fechaTrans);

        void introducirInformacionTransaccion(float importe, bool esCargo, string nombreCuenta, int codigoTransaccion);

        int totalTansacciones();

    private:
        void setFechaInicio(Fecha fecha);

        void setFechaFin(Fecha fechaFin);

        Fecha fechaInicio;

        Fecha fechaFin;

        int idPeriodo;


    public:
        std::map<int,Transaccion*> contenedorTransaccion;

        RegistroSistemaContable *regSistemaContable;

    };
}
#endif
