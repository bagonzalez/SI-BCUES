//#include "../../Persistencia/persistencia_global.h"
//#include "../../Persistencia/persistencia.h"

#include "../headers/clase.h"
#include <iostream>

namespace moduloinventario
{

    Clase::Clase(Cuenta *cuentaAsignada, string nombreClase, int idClase)
    {
        this->cuentaAsignada=cuentaAsignada;        
        this->nombreClase=nombreClase;
        this->idClase=idClase;

        //std::cout << "se crea" << nombreClase << cuentaAsignada << idClase;
    }

    string Clase::getNombreClase()
    {
        return this->nombreClase;
    }

    string Clase::getCuentaAsignada()
    {        
        return this->cuentaAsignada->getNombreCuenta();
    }

    int Clase::getCodigoClase()
    {
        return this->idClase;
    }
}
