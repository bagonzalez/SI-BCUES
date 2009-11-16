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


#ifndef MODULOINVENTARIO_ESPECMATERIALBIBLIOGRAFICO_H
#define MODULOINVENTARIO_ESPECMATERIALBIBLIOGRAFICO_H


#include "../headers/EspecificacionBien.h"
#include "../../ModuloCatalogo_global.h"
#include <string>

using namespace std;
namespace moduloinventario {

    struct autor{
        string nombreAutor;
        string apellidoAutor;        

        std::map<string, string> listaTitulos;
        std::map<int, string> otrosTitulos;
    };

class MODULOCATALOGOSHARED_EXPORT EspecMaterialBibliografico : public EspecificacionBien {

public:
    EspecMaterialBibliografico(int _id, Clase *claseAsig);

    void setAutor(string _autor, string _apellidoAutor);

    void setTitulo(string _autor, string _apellidos, string _titulo, string isbn );

    void setDescripcion(string _descripcion);

    string getDescripcion();

    std::map <string, string> getTitulos(string _autor, string _apellidos);

    std::map <int, string> getOtrosTitulos(string _autor, string _apellidos);

    std::list <string> getNAutores();

    std::list <string> getApellidosAutores();



  public:

    string descripcion;

    int oid;

    std::list<autor*> contedorAutores;

};
}

#endif
