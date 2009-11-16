
#include "../headers/Unidad.h"
#include "../headers/Registro.h"
#include "../headers/Usuario.h"

#include "../../Persistencia/persistencia_global.h"
#include "../../Persistencia/persistencia.h"


namespace basico {
    Unidad::Unidad(string codigoUnidadP1, string codigoUnidadp2, string nombre, Registro *_registro){
        this->idUnidadP1=codigoUnidadP1;
        this->idUnidadP2=codigoUnidadp2;
        this->nombreUnidad=nombre;
        this->registro=_registro;
        this->registro->setUnidad(this);

        Persistencia::Persistencia *servicioPersistencia=new Persistencia(registro);
        servicioPersistencia->guarda(this);
        servicioPersistencia->cerrarConeccion();
    }

    Unidad::Unidad(int _id,  Registro *_registro ){
        this->id=_id;
        this->registro=_registro;
        Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->registro);
        servicioPersistencia->cargar(this);
    }

    void Unidad::crearUsuario(string nombre, string apellido,  string login, string contrasenia, rol _rolUsuario){
         Usuario *nuevo=new basico::Usuario(nombre,apellido, login, contrasenia, _rolUsuario, this);
         this->contenedorUsuarios.push_back(nuevo);
    }

    void Unidad::crearUsuario(string nombre, string apellido,  string login, string contrasenia, string _rolUsuario){
         Usuario *nuevo=new basico::Usuario(nombre,apellido, login, contrasenia, _rolUsuario, this);
         this->contenedorUsuarios.push_back(nuevo);
    }



    void Unidad::setUsuarioRegistro(Usuario *usuario){
        this->registro->setUsuario(usuario);
    }

    bool Unidad::logear(string login, string password){
        for
        (
                list<Usuario*>::iterator from = this->contenedorUsuarios.begin();
                from != this->contenedorUsuarios.end();
                ++from
        ){
            if( ((*from)->getLogin())==login && (*from)->getPassword()==password){
                this->registro->setUsuario((*from));
                return true;
             }
        }
        return false;
    }

    bool Unidad::isUsuarioTecnico(){
        if(this->registro->getRolUsuario()==tecnico)
            return true;
        else
            return false;
    }

    bool Unidad::isUsuarioContador(){
        if(this->registro->getRolUsuario()==contador)
            return true;
        else
            return false;
    }

    bool Unidad::isUsuarioAdministrador(){
        if(this->registro->getRolUsuario()==administrador)
            return true;
        else
            return false;
    }

    string Unidad::getNombreUsuario(){
        return this->registro->getNombre();

    }

    string Unidad::getApellidoUsuario(){
        return this->registro->getApellido();
    }

    Registro * Unidad::getRegistro(){
        return this->registro;
    }

    string Unidad::getNombreUnidad(){
        return this->nombreUnidad;
    }
    string Unidad::codigoP1(){
        return this->idUnidadP1;
    }
    string Unidad::codigoP2(){
        return this->idUnidadP2;
    }

    int Unidad::getID(){
        return this->id;
    }

} // namespace basico
