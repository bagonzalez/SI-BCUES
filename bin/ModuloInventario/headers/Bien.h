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

    Bien(EspecificacionBien *especFijo, float valor, Fecha *_fechaAdquisicion, string correlativo, bool nuevo);
    Bien( float valor, EspecificacionBien *especBiblio, Fecha *_fechaAdquisicion, string correlativo, bool nuevo);

    int oid;
    void setOID(int oid);

    void setSector(int idSector);

    void setidTitulo(int idTitulo);

    void setidModelo(int idModelo);
    void setSerie(string _serie);
    void setDescargado();
    void setDescargadoMB();

    int getTipoBien();

    float getValor();

    string getSerie();


    EspecificacionBien * getEspecAF();
    EspecificacionBien * getEspecMB();

    string correlativo;

    int idModelo;
    int idMarca;
    int idEspecifico;
    int idTitulo;
    int idAutor;

    Fecha *fechaAdquisicion;

    int estadoBien;
    // 1 Activo
    // 2 Descargado
    // 3 Trasladado

  private:

    moduloinventario::EspecificacionBien *especFijo;
    moduloinventario::EspecificacionBien *especBiblio;
    float valor;
    int idBien;
    int idSectorDestino;
    string serie;

    // 1 Bibliografico;
    // 0 Activo Fijo;
    int tipoBien;



};
}
#endif
