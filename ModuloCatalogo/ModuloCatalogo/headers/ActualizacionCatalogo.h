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

#ifndef MODULOINVENTARIO_ACTUALIZACIONCATALOGO_H
#define MODULOINVENTARIO_ACTUALIZACIONCATALOGO_H


#include "../../../ModuloContable/ModuloContable/headers/Fecha.h"
#include "../../../ModuloContable/ModuloContable/headers/Tiempo.h"

namespace moduloinventario {

namespace basico { class Registro; } 
namespace basico { class Usuario; } 
class EspecificacionBien;

class ActualizacionCatalogo {
  private:
    basico::Registro *unidad ;

    basico::Usuario *bien ;

    Fecha fechaActualizacion;

    Tiempo horaActualizacion;

    EspecificacionBien *especBien ;

    int idActualizacion;

};

} // namespace moduloinventario
#endif
