
#include "../headers/EspecificacionBien.h"
#include "../headers/CatalogoActivoFijo.h"
#include "../../../ModuloInventario/headers/Bien.h"
#include "../../../Basico/headers/Usuario.h"
#include "../headers/IngresoClaseCatalogo.h"
#include "../headers/ActualizacionCatalogo.h"

namespace moduloinventario {

    EspecificacionBien::EspecificacionBien(int _id, Subcuenta *cuentaAsig, string _clase){
         this->idEspecificacion=_id;
         this->cuentaAsignada=cuentaAsig;
         this->clase=_clase;
    }

int EspecificacionBien::getIdEspecificacion(){
    return this->idEspecificacion;
}

string EspecificacionBien::getClase(){
    return this->clase;
}
}



