
#include "..\headers\Subcuenta.h"
namespace contabilidad {

Subcuenta::Subcuenta(string nombreCuenta, int codSubcuenta, Cuenta * madre): Cuenta(nombreCuenta, codSubcuenta)
{
    this->cuentaMadre=madre;
}

Subcuenta::~Subcuenta(){
}

}
