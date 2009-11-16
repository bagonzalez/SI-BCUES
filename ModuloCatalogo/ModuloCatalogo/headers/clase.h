#ifndef CLASE_H
#define CLASE_H



#include "../../../ModuloContable/ModuloContable/headers/Cuenta.h"
#include "../../../ModuloContable/ModuloContable/headers/Subcuenta.h"
#include "../../ModuloCatalogo_global.h"
#include <string>
namespace moduloinventario {

using namespace contabilidad;

class MODULOCATALOGOSHARED_EXPORT Clase {

    public:
        Clase( Subcuenta *cuentaAsignada, Subcuenta *idEspecifico, string nombreClase, int idClase);

        string getNombreClase();
        string getCuentaAsignada();
        Subcuenta * getEspecifico();
        int getCodigoClase();
        void setOID();
        void setOID(int oid);
        int getOID();
        void guardar();


    public:
         Subcuenta *cuentaAsignada;
         Subcuenta *idEspecifico;
         int idClase;
         int oid;
         string nombreClase;

};

}


#endif // CLASE_H
