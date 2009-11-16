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

   Bien * crearBien(EspecActivoFijo *_especBien, float _valor, Fecha *_fechaAdquisicion);

   Bien * crearBien(EspecMaterialBibliografico *_especBien, float _valor, Fecha *_fechaAdquisicion);


   string correlativo(string nombreClase, bool activofijo);

   std::list<string>  getCorrelativos(string clase, string cuentaAsignada);

   Bien * getBien(string clase, string cuentaAsignada, string correlativo);

   void cargarInventario(moduloinventario::RegistroCatalogo *regCatalogo);


  private:

    std::map<int, Bien*> contenedorBienes;


/*
    Ingreso * ;

    TrasladoBienes * ;

    DescargoBienes * ;*/

};
}
#endif
