/***************************************************************************
 *   Copyright (C) 2009 by Bruno Gonzalez                                  *
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

#ifndef MODULOINVENTARIO_INGRESOCLASECATALOGO_H
#define MODULOINVENTARIO_INGRESOCLASECATALOGO_H

#include <string>
#include "../../../ModuloContable/ModuloContable/headers/Fecha.h"
#include "../../../ModuloContable/ModuloContable/headers/Tiempo.h"
#include "EspecificacionBien.h"
#include "EspecMaterialBibliografico.h"
#include "EspecActivoFijo.h"

namespace moduloinventario {
namespace basico { class Usuario; }
class RegistroCatalogo;
class IngresoClaseCatalogo {

  public:
    IngresoClaseCatalogo(Fecha *_fechaIngreso, Tiempo *_horaIngreso, int idIngreso, RegistroCatalogo *reg);

    int getCodigoIngreso();

    void crearEspecActivoF(EspecActivoFijo *);

    void crearEspecMatBiblio(EspecMaterialBibliografico *);

    void introducirInformacionMB(string autor, string titulo, string isbn);

    void introducirInformacionAF(string descripcion, string marca, string modelo);


  private:

    Fecha *fechaIngreso;

    Tiempo *horaIngreso;

    EspecMaterialBibliografico *especMatBibliografico;

    EspecActivoFijo *especActFijo;

    basico::Usuario *usuario;

    RegistroCatalogo *registro;

     int idIngreso;

};
}

#endif
