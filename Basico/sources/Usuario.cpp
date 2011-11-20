#include "../headers/Usuario.h"
#include "../headers/Registro.h"
#include "../headers/Unidad.h"


#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"

namespace basico
{
    Usuario::Usuario(string _nombre, string _apellido, string _login, string _contrasenia, rol _rolUsuario, Unidad *_unidad)
    {
        this->nombre=_nombre;
        this->apellido=_apellido;
        this->rolUsuario=_rolUsuario;

        switch (rolUsuario)
        {

        case basico::administrador:
        {
            this->rolU="administrador";
        }
        break;

        case basico::tecnico:
        {
            this->rolU="tecnico";
        }
        break;

        case basico::contador:
        {
            this->rolU="contador";
        }
        break;
        }
        this->login=_login;
        this->contrasenia=_contrasenia;
        this->unidad=_unidad;

        Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->unidad->registro);
        servicioPersistencia->guardarUsuario(this, _unidad->id );
    }

    Usuario::Usuario(string _nombre, string _apellido, string _login, string _contrasenia, string _rolUsuario, Unidad *_unidad, int _id)
    {

        this->nombre=_nombre;
        this->apellido=_apellido;
        this->rolU=_rolUsuario;
        this->id=_id;

        if (this->rolU=="administrador")
            this->rolUsuario=basico::administrador;
        if (this->rolU=="contador")
            this->rolUsuario=basico::contador;
        if (this->rolU=="tecnico")
            this->rolUsuario=basico::tecnico;

        this->login=_login;
        this->contrasenia=_contrasenia;
        this->unidad=_unidad;
    }

    string Usuario::getLogin()
    {
        return this->login;
    }

    rol Usuario::getRol()
    {
        return this->rolUsuario;
    }

    string Usuario::getPassword()
    {
        return this->contrasenia;
    }

    string Usuario::getNombre()
    {
        return this->nombre;
    }

    string Usuario::getApellido()
    {
        return this->apellido;
    }

    int Usuario::getID()
    {
        return this->id;
    }

} // namespace basico
