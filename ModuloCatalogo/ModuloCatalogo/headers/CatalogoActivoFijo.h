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


#ifndef MODULOINVENTARIO_CATALOGOACTIVOFIJO_H
#define MODULOINVENTARIO_CATALOGOACTIVOFIJO_H


#include "../../../ModuloContable/ModuloContable/headers/Subcuenta.h"
#include "EspecificacionBien.h"
#include <map>
#include <list>


//namespace basico { class Unidad; }
namespace contabilidad
{
    class Subcuenta;
}
namespace moduloinventario
{
    class EspecificacionBien;
    class RegistroCatalogo;

    class CatalogoActivoFijo
    {

    public:
        CatalogoActivoFijo(RegistroCatalogo *regCatalogo);

        EspecificacionBien * crearEspec(moduloinventario::Clase *claseAsignada);

        std::list<string> getDescripciones();       
        bool existeDescripcion(string descripcion);

        EspecificacionBien * getEspecificacion(string clase, string cuentaAsignada);
        EspecificacionBien * getEspecificacion(int oid);


        void cargarCatalogo(int invAFijo);


        RegistroCatalogo *regCatalogo;

    private:
        //basico::Unidad *unidad ;

        std::map<int, EspecificacionBien*> contenedorEspec;





    };

}
#endif
