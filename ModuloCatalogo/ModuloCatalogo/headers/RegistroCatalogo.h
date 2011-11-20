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

#include "../../../Basico/Basico_global.h"
#include "../../../Basico/basico.h"

#include "../../../ModuloContable/ModuloContable_global.h"
#include "../../../ModuloContable/modulocontable.h"

#include "../../ModuloCatalogo_global.h"
//#include "../../../ModuloContable/ModuloContable/headers/Tiempo.h"
//#include "../../../ModuloContable/ModuloContable/headers/Fecha.h"
//#include "../../../ModuloContable/ModuloContable/headers/RegistroSistemaContable.h"

#include "clase.h"
#include "IngresoClaseCatalogo.h"
#include "CatalogoActivoFijo.h"

namespace moduloinventario
{

    using namespace basico;
    using namespace contabilidad;



    class MODULOCATALOGOSHARED_EXPORT RegistroCatalogo
    {

    public:


        RegistroCatalogo(basico::Usuario *usuario,  contabilidad::RegistroSistemaContable *_regContable);

        int crearIngreso(Fecha *_fechaIngreso, Tiempo *_horaIngreso);

        int crearClase(Subcuenta *cuentaAsignada, string nombreClase);

        void crearEspec(contabilidad::Subcuenta *cuentaAsignada, int codIngreso, string clase);

        void crearCatalogo();

        bool existeDescripcion(string descripcion);

        std::list<string> getDescripciones();        

        std::list<string> getClases(string cuentaAsignada);

        EspecificacionBien * getEspecificacion(string clase, string cuentaAsignada);
        EspecificacionBien * getEspecificacion(int oid);        
        EspecificacionBien * cargarEspec(contabilidad::Cuenta *cuentaAsignada,  string clase);



        bool existeClase(string nombreClase, string cuentaAsignada);

        void cargarCatalogo(int invAFijo);

        Clase * getClase(string nombreClase, string cuentaAsignada );

        CatalogoActivoFijo *catalogoActivoFijo;

        contabilidad::RegistroSistemaContable *regContable;

        basico::Usuario *usuario;

    private:



        std::map<int, IngresoClaseCatalogo*> contenedorIngresos;

        std::map<int, Clase*> contenedorClases;



    };
}

#endif
