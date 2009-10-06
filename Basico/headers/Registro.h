#ifndef BASICO_REGISTRO_H
#define BASICO_REGISTRO_H


namespace basico { class Unidad; } 
namespace moduloinventario { class ActualizacionCatalogo; } 
namespace basico { class Usuario; } 
namespace moduloinventario { class IngresoClaseCatalogo; } 
class DescargoBienes;

namespace basico {

class Registro {
  private:
    Unidad *unidad ;

    moduloinventario::ActualizacionCatalogo *actCatalogo ;

    Usuario *usuario;

    moduloinventario::IngresoClaseCatalogo *ingCatalogo ;

    //::DescargoBienes * ;

    //::Requisicion * ;

    //::Reporte * ;

    //::TrasladoBienes * ;

    //::Ingreso * ;

    //Administrador * ;

    //::MaterialesOficina * ;

};

} // namespace basico
#endif
