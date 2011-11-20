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


#ifndef BASICO_REGISTRO_H
#define BASICO_REGISTRO_H
#include "../Basico_global.h"
#include "Usuario.h"
#include <string>

namespace basico
{
    class Unidad;
}
namespace moduloinventario
{
    class ActualizacionCatalogo;
}
namespace basico
{
    class Usuario;
}
namespace moduloinventario
{
    class IngresoClaseCatalogo;
}
class DescargoBienes;
using namespace std;
namespace basico
{


    class BASICOSHARED_EXPORT Registro
    {

    public:

        Registro();

        void setUsuario(Usuario *_usuario);

        void setUnidad(Unidad *_unidad);

        bool logear(string login, string password);

        string getLogin();

        string getNombre();

        string getApellido();

        string getPassword();

        int getRolUsuario();

        string getNombreUnidad();

        string codigoUnidadP1();

        string codigoUnidadP2();

        Unidad * getUnidad();

        Usuario * getUsuario();

        int crearUnidad(string, string, string,  string _director, string _jefeAF);

        void crearUsuario(string nombre, string apellido,  string login, string contrasenia, rol _rolUsuario);

        void crearUsuario(string nombre, string apellido,  string login, string contrasenia, string _rolUsuario, int id);

        void crearUnidad(int id);

    private:

        Unidad *unidad;

        Usuario *usuario;

        moduloinventario::ActualizacionCatalogo *actCatalogo ;

        moduloinventario::IngresoClaseCatalogo *ingCatalogo ;

    };

} // namespace basico
#endif
