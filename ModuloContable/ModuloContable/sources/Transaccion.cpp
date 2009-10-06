
#include "../headers/Transaccion.h"
#include "../headers/Subcuenta.h"
#include "../headers/Cuenta.h"
#include "../headers/LineaDeTransaccion.h"
#include "../headers/PeriodoContable.h"
#include "../headers/RegistroSistemaContable.h"
namespace contabilidad {

Transaccion::Transaccion(int codigo, int periodoActual){

    this->codigoTransaccion=codigo;
    this->periodo=periodoActual;
    
}

int Transaccion::getCodigoTransaccion() {

        return this->codigoTransaccion;
}

void Transaccion::crearLineadeTransaccion(float importe, bool esCargo, Subcuenta * cuenta) {


        if(myLineaDeTransaccion.empty())
        {
                myLineaDeTransaccion[1]=new LineaDeTransaccion(importe,  esCargo, cuenta);
        }
        else
        {
                myLineaDeTransaccion[myLineaDeTransaccion.size()+1]=new LineaDeTransaccion(importe, esCargo, cuenta);

        }
}

void Transaccion::crearLineadeTransaccion(float importe, bool esCargo, Cuenta * cuenta) {


        if(myLineaDeTransaccion.empty())
        {
                myLineaDeTransaccion[1]=new LineaDeTransaccion(importe,  esCargo, cuenta);
        }
        else
        {
                myLineaDeTransaccion[myLineaDeTransaccion.size()+1]=new LineaDeTransaccion(importe, esCargo, cuenta);
        }
}

void Transaccion::setFechaTransaccion(Fecha *_fechaTransaccion) {
    this->fechaTransaccion=_fechaTransaccion;
}

void Transaccion::setHoraTransaccion(Tiempo *_horaTransaccion) {
    this->horaTransaccion=_horaTransaccion;
}

}
