
#include "../headers/SistemaInventario.h"
#include "../headers/Unidad.h"

namespace basico {

    SistemaInventario::SistemaInventario(){


    }

    void SistemaInventario::crearUnidad(string codigoP1, string codigoP2, string nombre, Registro *reg){
        Unidad  *nueva;
        nueva=new Unidad(codigoP1, codigoP2, nombre, reg);
        this->myUnidades[codigoP1]=nueva;
    }


} // namespace basico
