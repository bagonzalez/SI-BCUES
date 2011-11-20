#ifndef CLASE_H
#define CLASE_H



#include "../../../ModuloContable/ModuloContable/headers/Cuenta.h"
#include "../../../ModuloContable/ModuloContable/headers/Subcuenta.h"
#include "../../ModuloCatalogo_global.h"
#include <string>
namespace moduloinventario
{

    using namespace contabilidad;

    class MODULOCATALOGOSHARED_EXPORT Clase
    {

    public:
        Clase( Cuenta *cuentaAsignada, string nombreClase, int idClase);

        string getNombreClase();
        string getCuentaAsignada();        
        int getCodigoClase();

    public:
        Cuenta *cuentaAsignada;
        int idClase;        
        string nombreClase;

    };
}


#endif // CLASE_H
