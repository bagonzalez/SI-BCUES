#ifndef BASICO_USUARIO_H
#define BASICO_USUARIO_H


namespace basico { class Registro; } 
namespace moduloinventario { class ActualizacionCatalogo; } 
class Bien;
namespace moduloinventario { class EspecificacionBien; } 
namespace moduloinventario { class IngresoClaseCatalogo; } 
namespace basico { class Unidad; } 
class DescargoBienes;

namespace basico {

class Usuario {
  private:
    Registro *registro ;

    moduloinventario::ActualizacionCatalogo *actCatalogo ;

    //::Bien * ;

    moduloinventario::EspecificacionBien *especBien ;

    moduloinventario::IngresoClaseCatalogo *ingCatalogo ;

    //::RegistroVariacionPresupuestaria * ;

    //::EspecificacionCp * ;

    //::VPresupuestaria * ;

    Unidad *unidad ;

    //::DescargoBienes * ;

    //::RegistroReprogramacionPresupuestaria * ;

    //::EspecificacionReprogramacion * ;

    //::EspecificacionCuentaR * ;

    //::VPresupuestaria * ;

    //::EspecificacionCp * ;

    //::ActualizacionReprogramacion * ;

    //::M2 * ;

    //::TrasladoBienes * ;

    //string nombre ;

    //Rol ;

    //::CuentasDeUsuario * ;

    //::Sesion * Posee;

    //::Consulta * ;

    //::IngresoUsuario * ;

};

} // namespace basico
#endif
