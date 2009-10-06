
#include "../headers/EspecificacionBien.h"
#include "../headers/CatalogoActivoFijo.h"
#include "../../../ModuloInventario/headers/Bien.h"
#include "../../../Basico/headers/Usuario.h"
#include "../headers/IngresoClaseCatalogo.h"
#include "../headers/ActualizacionCatalogo.h"

namespace moduloinventario {
int EspecificacionBien::getIdEspecificacion(){
    return this->idEspecificacion;
}

string EspecificacionBien::getClase(){
    return this->clase;
}
}



