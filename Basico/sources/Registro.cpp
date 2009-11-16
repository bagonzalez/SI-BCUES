
#include "../headers/Registro.h"
#include "../headers/Unidad.h"
#include "../headers/Usuario.h"


namespace basico {

    Registro::Registro(){
    }

    void Registro::setUsuario(Usuario *_usuario){
        this->usuario=_usuario;
    }

    void Registro::setUnidad(Unidad *_unidad){
        this->unidad=_unidad;        
    }

    string Registro::getLogin(){
        return this->usuario->getLogin();
    }

    string Registro::getPassword(){
        return this->usuario->getPassword();
    }

    rol Registro::getRolUsuario(){
        return this->usuario->getRol();
    }

    string Registro::getNombre(){
        return this->usuario->getNombre();
    }

    string Registro::getApellido(){
        return this->usuario->getApellido();
    }

    int Registro::crearUnidad(string codP1, string codP2, string nombre){
        this->unidad=new Unidad(codP1, codP2, nombre, this);
        return this->unidad->getID();
    }    

    void Registro::crearUnidad(int id){
        this->unidad=new Unidad(id, this);
    }

    Unidad * Registro::getUnidad(){
        return this->unidad;
    }

    Usuario * Registro::getUsuario(){
        return this->usuario;
    }

    bool Registro::logear(string login, string password){
        return this->unidad->logear(login, password);
    }

    string Registro::getNombreUnidad(){
        return this->unidad->getNombreUnidad();
    }

    string Registro::codigoUnidadP1(){
        return this->unidad->codigoP1();
    }

    string Registro::codigoUnidadP2(){
        return this->unidad->codigoP2();
    }

    void Registro::crearUsuario(string nombre, string apellido,  string login, string contrasenia, rol _rolUsuario){
        this->unidad->crearUsuario(nombre, apellido, login, contrasenia, _rolUsuario);
    }

    void Registro::crearUsuario(string nombre, string apellido,  string login, string contrasenia, string _rolUsuario){
        this->unidad->crearUsuario(nombre, apellido, login, contrasenia, _rolUsuario);
    }


} // namespace basico
