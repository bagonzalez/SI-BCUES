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


#include "../headers/EspecMaterialBibliografico.h"
#include "../headers/EspecActivoFijo.h"
#include "../../../ModuloContable/ModuloContable/headers/Subcuenta.h"
#include <map>
#include <list>


//namespace basico { class Unidad; }
namespace contabilidad { class Subcuenta; }
namespace moduloinventario {
class EspecificacionBien;
class RegistroCatalogo;

class CatalogoActivoFijo {

  public:
    CatalogoActivoFijo(RegistroCatalogo *regCatalogo);

    EspecActivoFijo * crearEspecActivoFijo(moduloinventario::Clase *claseAsignada);

    EspecMaterialBibliografico * crearEspecMaterialBibliografico(moduloinventario::Clase *claseAsignada);

    std::list<string> getDescripciones();    

    std::list<string> getMarcas(string nombreDescripcion);    
    std::list<string> getModelos(string nombreMarca);
    bool existeDescripcion(string descripcion);

    EspecActivoFijo * getEspecificacion(string clase, string cuentaAsignada);
    EspecActivoFijo * getEspecificacion(int oid);
    EspecMaterialBibliografico * getEspecificacionMB(string clase, string cuentaAsignada);

    void cargarCatalogo();

    std::list<string> * getApellidos();
    std::list<string> * getNombres();
    std::list<string> * getOtrosAutores();

    RegistroCatalogo *regCatalogo;

  private:
    //basico::Unidad *unidad ;

    std::map<int, EspecActivoFijo*> contenedorEspecAF;

    std::map<int, EspecMaterialBibliografico*> contenedorEspecMB;

    int idCatalogo;




};

}
#endif
