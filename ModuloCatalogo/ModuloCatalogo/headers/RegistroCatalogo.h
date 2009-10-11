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


#ifndef _REGISTROCATALOGO_H
#define _REGISTROSISTEMACONTABLE_H

#include <iostream>
#include <map>
#include "../../ModuloCatalogo_global.h"
#include "../../../ModuloContable/ModuloContable/headers/Tiempo.h"
#include "../../../ModuloContable/ModuloContable/headers/Fecha.h"
#include "../../../ModuloContable/ModuloContable/headers/RegistroSistemaContable.h"
#include "../headers/EspecMaterialBibliografico.h"
#include "../headers/EspecActivoFijo.h"
#include "CatalogoActivoFijo.h"

namespace moduloinventario {

class IngresoClaseCatalogo;

class MODULOCATALOGOSHARED_EXPORT RegistroCatalogo {

  public:
    RegistroCatalogo();

    int crearIngreso(Fecha *_fechaIngreso, Tiempo *_horaIngreso);

    void crearEspecMatBiblio(contabilidad::Subcuenta *cuentaAsignada, int codIngreso, string clase);

    void crearEspecActivoF(contabilidad::Subcuenta *cuentaAsignada, int codIngreso, string clase);

    void introducirInformacion(string autor, string titulo, string isbn,  int codIngreso);

    void introducirInformacion( int codIngreso, string descripcion, string marca, string modelo);

    void crearCatalogo();

    void setMarca(string marca, EspecActivoFijo *);

    void setModelo(string marca, string modelo, EspecActivoFijo *espec);

    bool existeDescripcion(string descripcion);

    std::list<string> getDescripciones();

    std::list<string> getMarcas(string nombreDescripcion);

    std::list<string> getModelos(string nombreMarca);

    EspecActivoFijo * getEspecificacion(string clase);

    EspecMaterialBibliografico * getEspecificacionMB(string clase);



  private:

    CatalogoActivoFijo *catalogoActivoFijo;

    std::map<int, IngresoClaseCatalogo*> contenedorIngresos;

};
}

#endif
