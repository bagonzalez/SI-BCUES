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

#include <string>
#include "../../ModuloCatalogo_global.h"
#include "clase.h"


namespace moduloinventario {
class CatalogoActivoFijo;
class Bien;
class IngresoClaseCatalogo;
class ActualizacionCatalogo;

class MODULOCATALOGOSHARED_EXPORT EspecificacionBien {

  public:

    EspecificacionBien(int _id, Clase *claseAsig);

    int getIdEspecificacion();

    Clase * getClase();

  protected:   

    int idEspecificacion;




  public:

    int oid_especbien;

    CatalogoActivoFijo *catalogoActFijo;

    Clase *clase;

    //basico::Usuario *usuario ;

    IngresoClaseCatalogo *ingCatalogo ;

    ActualizacionCatalogo *actCatalogo ;   

};
}

#endif
