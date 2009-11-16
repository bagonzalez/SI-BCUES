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


#ifndef BASICO_USUARIO_H
#define BASICO_USUARIO_H

#include <string>


class DescargoBienes;

using namespace std;
namespace basico {

class Unidad;
enum rol {
  tecnico,
  administrador,
  contador
};

class  Usuario {

  public:
    Usuario(string nombre, string apellido,  string login, string contrasenia, rol _rolUsuario, Unidad *unidad);    
    Usuario(string _nombre, string _apellido, string _login, string _contrasenia, string _rolUsuario, Unidad *_unidad);

    string getLogin();
    string getPassword();
    string getNombre();
    string getApellido();
    int getID();
    rol getRol();


  public:

    int id;
    string nombre;
    string apellido;
    string login;
    string contrasenia;
    rol rolUsuario;

    string rolU;

    Unidad *unidad;


};

} // namespace basico
#endif
