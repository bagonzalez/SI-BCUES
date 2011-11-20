#ifndef _INVENTARIOACTIVOFIJO_H
#define _INVENTARIOACTIVOFIJO_H


#include "../../ModuloContable/ModuloContable_global.h"
#include "../../ModuloContable/modulocontable.h"
#include "../../ModuloCatalogo/ModuloCatalogo_global.h"
#include "../../ModuloCatalogo/modulocatalogo.h"
#include "../../Basico/Basico_global.h"
#include "../../Basico/basico.h"

#include "../moduloinventario_global.h"
#include "Bien.h"
#include <map>

class DescargoBienes;

using namespace std;
namespace moduloinventario {

class MODULOINVENTARIOSHARED_EXPORT InventarioActivoFijo {

  public:

   InventarioActivoFijo();

   Bien * crearBien(EspecificacionBien *_especBien, float _valor, Fecha *_fechaAdquisicion, int estado, bool nuevo);

   Bien * crearBien( Fecha *_fechaAdquisicion, EspecificacionBien *_especBien, float _valor, int estado, bool nuevo);


   string correlativoAF(string nombreClase);
   string correlativoMB(string nombreClase);

   std::list<string>  getCorrelativosAF(string clase, string cuentaAsignada);
   std::list<string>  getCorrelativosMB(string clase, string cuentaAsignada);

   Bien * getBienAF(string clase, string cuentaAsignada, string correlativo);
   Bien * getBienMB(string clase, string cuentaAsignada, string correlativo);

   void cargarInventario(moduloinventario::RegistroCatalogo *regCatalogo, int idUnidad);

   void limpiarContenedor();


  private:

    std::map<int, Bien*> contenedorBienesAF;
    std::map<int, Bien*> contenedorBienesMB;



/*
    Ingreso * ;

    TrasladoBienes * ;

    DescargoBienes * ;*/

};
}
#endif
