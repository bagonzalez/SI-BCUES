#ifndef _BIEN_H
#define _BIEN_H


#include "../../ModuloContable/ModuloContable/headers/Fecha.h"

class InventarioActivoFijo;

namespace moduloinventario { class EspecificacionBien; } 
namespace basico { class Usuario; } 

class Bien {
  private:
    InventarioActivoFijo *inventario ;

    moduloinventario::EspecificacionBien *especBien;

    Fecha fechaAdquisicion;

    float valor;

    int idBien;

    basico::Usuario *usuario ;

    //LineasDeDescarga *lineaDescarga ;

    //LineasDeTraslado *lineaTraslado ;

    //LineasDeIngreso *lineaIngreso ;

    //Reporte *reporte ;

    //MaterialesOficina *materialOficina ;

};
#endif
