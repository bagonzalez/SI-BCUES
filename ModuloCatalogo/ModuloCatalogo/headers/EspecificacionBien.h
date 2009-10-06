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

#ifndef MODULOINVENTARIO_ESPECIFICACIONBIEN_H
#define MODULOINVENTARIO_ESPECIFICACIONBIEN_H

#include "../../../ModuloContable/ModuloContable/headers/Cuenta.h"
#include <string>


namespace moduloinventario {
using namespace contabilidad;
class CatalogoActivoFijo;
class Bien;
namespace basico { class Usuario; } 
class IngresoClaseCatalogo;
class ActualizacionCatalogo;

class EspecificacionBien {

  public:
    Subcuenta *cuentaAsignada;

    int idEspecificacion;

    int getIdEspecificacion();

    string getClase();

    string clase;

  private:
    CatalogoActivoFijo *catalogoActFijo;   

    basico::Usuario *usuario ;    

    IngresoClaseCatalogo *ingCatalogo ;

    ActualizacionCatalogo *actCatalogo ;   

};
}

#endif
