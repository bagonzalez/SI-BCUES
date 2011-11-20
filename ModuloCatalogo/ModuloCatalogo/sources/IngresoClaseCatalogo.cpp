#include "../Persistencia/Persistencia_global.h"
#include "../Persistencia/persistencia.h"

#include "../headers/IngresoClaseCatalogo.h"
#include "../headers/EspecificacionBien.h"
#include "../../../Basico/headers/Usuario.h"


namespace moduloinventario
{

    IngresoClaseCatalogo::IngresoClaseCatalogo(Fecha *_fechaIngreso, Tiempo *_horaIngreso, int _idIngreso, RegistroCatalogo *reg, basico::Usuario *_usuario)
    {
        this->fechaIngreso=_fechaIngreso;
        this->horaIngreso=_horaIngreso;
        this->idIngreso=_idIngreso;
        this->registro=reg;
        this->usuario=_usuario;

        /*Persistencia::Persistencia *servicioPersistencia=new Persistencia();
        servicioPersistencia->guarda(this);*/
    }

    void IngresoClaseCatalogo::setOID()
    {

        /*Persistencia::Persistencia *servicioPersistencia=new Persistencia();
        servicioPersistencia->setID(this);*/
    }

    int IngresoClaseCatalogo::getCodigoIngreso()
    {
        return this->idIngreso;
    }

    void  IngresoClaseCatalogo::crearEspecActivoF(EspecificacionBien *espec)
    {
        this->especActFijo=espec;
        /*Persistencia::Persistencia *servicioPersistencia=new Persistencia();
        servicioPersistencia->actualizar(this, espec);*/
    }

}
