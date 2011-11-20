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

#ifndef _TRANSACCION_H
#define _TRANSACCION_H


#include "Fecha.h"
#include "Tiempo.h"
#include <map>

namespace contabilidad
{

    class Subcuenta;
    class Cuenta;
    class LineaDeTransaccion;
    class PeriodoContable;
    class RegistroSistemaContable;

    class Transaccion
    {
    public:
        Transaccion(int codigo, int periodoActual);

        int getCodigoTransaccion();

        void crearLineadeTransaccion(float importe, bool esCargo, Subcuenta * cuenta);

        void crearLineadeTransaccion(float importe, bool esCargo, Cuenta * cuenta);

        void setFechaTransaccion(Fecha *fechaTransaccion);

        void setHoraTransaccion(Tiempo *horaTransaccion);

    private:

        Fecha *fechaTransaccion;

        Tiempo *horaTransaccion;

        int codigoTransaccion;

        int tipotransaccion;

        int periodo;


    public:
        std::map<int,LineaDeTransaccion*> myLineaDeTransaccion;

        PeriodoContable * contiene;

        RegistroSistemaContable * registra;

    };
}
#endif
