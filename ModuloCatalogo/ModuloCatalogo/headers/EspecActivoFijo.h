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

#ifndef MODULOINVENTARIO_ESPECACTIVOFIJO_H
#define MODULOINVENTARIO_ESPECACTIVOFIJO_H


#include "EspecificacionBien.h"
#include <string>
#include <map>


using namespace std;

namespace moduloinventario {

    struct fabricante{
        string marca;
        std::list<string> modelo;
    };

class EspecActivoFijo : public EspecificacionBien {
  public:
    EspecActivoFijo(int _id, Subcuenta *cuentaAsig, string clase);

    void setDescripcion(string _descripcion);
    void setMarca(string _marca);
    void setModelo(string marca, string _modelo);
    void setSerie(string _serie);
    string getDescipcion();


    std::list<string> getMarcas();
    std::list<string> getModelos(string marca);


  private:
    string descripcion;    
    std::list<fabricante*> _fabricante;

    string serie;

};
}
#endif
