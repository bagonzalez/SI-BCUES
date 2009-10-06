
#include <iostream>
#include "../headers/LineaDeTransaccion.h"
#include "../headers/Cuenta.h"
#include "../headers/Subcuenta.h"

namespace contabilidad {

LineaDeTransaccion::LineaDeTransaccion(float importe, bool esCargo, Cuenta * cuenta){

        if(esCargo)
                cuenta->cargarCuenta(importe);
        else
                cuenta->abonarCuenta(importe);

        std::cout << "Afectando Cuenta: " << cuenta->getNombreCuenta() << "  Saldo -->" << cuenta->getSaldo() << std::endl;

        nombreCuenta=cuenta->getNombreCuenta();

}

LineaDeTransaccion::LineaDeTransaccion(float importe, bool esCargo, Subcuenta * cuenta){

        if(esCargo)
                cuenta->cargarCuenta(importe);
        else
                cuenta->abonarCuenta(importe);

        std::cout << "Saldo -->" << cuenta->getSaldo() << std::endl;

        nombreCuenta=cuenta->getNombreCuenta();
}

float LineaDeTransaccion::getImporte() {

    return 0.0;
}

float LineaDeTransaccion::getCargo() {

    return 0.0;
}

int LineaDeTransaccion::getCodCuentaAfectada() {

    return 0;
}

void LineaDeTransaccion::setImporte(float cantidadImporte) {

    
}

void LineaDeTransaccion::setCargo(bool esCargo) {

    
}

void LineaDeTransaccion::setCodCuenta(int codigoCuenta) {

    
}
}
