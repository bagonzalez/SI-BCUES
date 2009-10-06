#ifndef BASICO_UNIDAD_H
#define BASICO_UNIDAD_H


namespace basico { class Registro; } 
class InventarioActivoFijo;
namespace moduloinventario { class CatalogoActivoFijo; } 
namespace basico { class SistemaInventario; } 
namespace basico { class Usuario; } 

namespace basico {

class Unidad {
  private:
    Registro *registro ;

    //::InventarioActivoFijo * ;

    moduloinventario::CatalogoActivoFijo *catalogoActFijo ;

    int idUnidad;

    SistemaInventario *sistemaInventario ;

    Usuario *unidad ;

    //::Requisicion * ;

    //::EspecificacionReprogramacion * ;

    //::M2 * ;

    //::M3 * ;

    //::M1 * ;

    //::Presupuesto * ;

    //::PresupuestoAprobado * ;

    //::MaterialesOficina * ;

};

} // namespace basico
#endif
