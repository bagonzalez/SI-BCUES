#include "../../Persistencia/persistencia_global.h"
#include "../../Persistencia/persistencia.h"

#include "../headers/clase.h"


namespace moduloinventario {

    Clase::Clase(Subcuenta *cuentaAsignada, Subcuenta *idEspecifico, string nombreClase, int idClase){
        this->cuentaAsignada=cuentaAsignada;
        this->idEspecifico=idEspecifico;
        this->nombreClase=nombreClase;
        this->idClase=idClase;
    }

    void Clase::guardar(){
          Persistencia::Persistencia *servicioPersistencia=new Persistencia();
          servicioPersistencia->guarda(this);
    }

    string Clase::getNombreClase(){
        return this->nombreClase;
    }

    Subcuenta * Clase::getEspecifico(){
         return this->idEspecifico;
    }

    string Clase::getCuentaAsignada(){
        contabilidad::Cuenta *cuenta=this->cuentaAsignada->cuentaMadre;

        return cuenta->getNombreCuenta();
    }

    int Clase::getCodigoClase(){
        return this->idClase;
    }

    void Clase::setOID(){
         Persistencia::Persistencia *servicioPersistencia=new Persistencia();
         servicioPersistencia->setID(this);
    }

    void Clase::setOID(int _oid){
        this->oid=_oid;
    }

    int Clase::getOID(){
        return this->oid;
    }

}
