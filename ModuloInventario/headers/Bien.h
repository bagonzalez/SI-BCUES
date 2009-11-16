#ifndef _BIEN_H
#define _BIEN_H

#include "../../ModuloContable/ModuloContable_global.h"
#include "../../ModuloContable/modulocontable.h"
#include "../../ModuloCatalogo/ModuloCatalogo_global.h"
#include "../../ModuloCatalogo/modulocatalogo.h"
#include "../../Basico/Basico_global.h"
#include "../../Basico/basico.h"

#include "../moduloinventario_global.h"
#include "InventarioActivoFijo.h"

using namespace basico;
using namespace contabilidad;
using namespace moduloinventario;

namespace moduloinventario {


class MODULOINVENTARIOSHARED_EXPORT Bien {

  public:

    Bien(EspecActivoFijo *especFijo, float valor, Fecha *_fechaAdquisicion, string correlativo);
    Bien(EspecMaterialBibliografico *especBiblio, float valor, Fecha *_fechaAdquisicion, string correlativo);

    int oid;
    void setOID(int oid);

    void setSector(int idSector);

    void setidTitulo(int idTitulo);

    void setidModelo(int idModelo);
    void setSerie(string _serie);

    int getTipoBien();

    float getValor();

    string getSerie();


    EspecActivoFijo * getEspecAF();
    EspecMaterialBibliografico * getEspecMB();

    string correlativo;

    int idModelo;
    int idTitulo;

    Fecha *fechaAdquisicion;

  private:
    //InventarioActivoFijo *inventario ;
    moduloinventario::EspecActivoFijo *especFijo;
    moduloinventario::EspecMaterialBibliografico *especBiblio;
    float valor;
    int idBien;
    int idSectorDestino;
    string serie;

    // 1 Bibliografico;
    // 0 Activo Fijo;
    int tipoBien;

    //LineasDeDescarga *lineaDescarga ;
    //LineasDeTraslado *lineaTraslado ;
    //LineasDeIngreso *lineaIngreso ;
    //Reporte *reporte ;
    //MaterialesOficina *materialOficina ;

};
}
#endif
