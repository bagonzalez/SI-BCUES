
#include "../headers/EspecificacionBien.h"
#include "../headers/CatalogoActivoFijo.h"

#include "../../../Basico/headers/Usuario.h"
#include "../headers/IngresoClaseCatalogo.h"
#include "../headers/ActualizacionCatalogo.h"

namespace moduloinventario {

    EspecificacionBien::EspecificacionBien(int _id, Clase *claseAsig){
         this->idEspecificacion=_id;         
         this->clase=claseAsig;
    }

int EspecificacionBien::getIdEspecificacion(){
    return this->idEspecificacion;
}

Clase * EspecificacionBien::getClase(){
    return this->clase;
}
}



