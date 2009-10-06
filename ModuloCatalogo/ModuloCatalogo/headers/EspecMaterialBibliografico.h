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
#include <string>
using namespace std;
namespace moduloinventario {

class EspecMaterialBibliografico : public EspecificacionBien {

public:
    EspecMaterialBibliografico(int _id, Subcuenta *cuentaAsig);

    void setAutor(string _autor);

    void setTitulo(string _titulo);

    void setISBN(string _isbn);

  private:
    string autor;

    std::map<int, string> titulo;

    string isbn;

};
}

#endif
