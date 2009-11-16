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


#ifndef BASICO_UNIDAD_H
#define BASICO_UNIDAD_H

#include <list>
#include <string>

#include "../Basico_global.h"
#include "Usuario.h"

namespace basico { class Registro; } 
namespace basico { class SistemaInventario; } 
using namespace std;

namespace basico {

class  Unidad {

    public:
    Unidad(string codigoUnidadP1,string codigoUnidadp2, string nombre, Registro *registro);

    Unidad(int id,  Registro *registro);

    void setUsuario();
    void crearUsuario(string nombre, string apellido,  string login, string contrasenia, rol _rolUsuario);
    void crearUsuario(string nombre, string apellido,  string login, string contrasenia, string _rolUsuario);
    void setUsuarioRegistro(Usuario *usuario);
    bool logear(string login, string password);

    Registro * Unidad::getRegistro();
    bool isUsuarioTecnico();
    bool isUsuarioContador();
    bool isUsuarioAdministrador();
    string getNombreUsuario();
    string getApellidoUsuario();
    string getNombreUnidad();
    int getID();
    string  codigoP1();
    string codigoP2();

    void cargar();

    public:
    int id;
    string idUnidadP1;
    string idUnidadP2;
    Registro *registro;
    SistemaInventario *sistemaInventario ;
    string nombreUnidad;
    std::list< Usuario*>  contenedorUsuarios;




};

} // namespace basico
#endif
