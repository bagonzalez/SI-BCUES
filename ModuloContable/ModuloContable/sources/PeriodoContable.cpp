
#include "../headers/PeriodoContable.h"
#include "../headers/Transaccion.h"
#include "../headers/RegistroSistemaContable.h"

namespace contabilidad {
PeriodoContable::PeriodoContable(Fecha _fechaInicio, Fecha _fechaFin, int _idPeriodo, RegistroSistemaContable *registro){
    this->fechaInicio=_fechaInicio;
    this->fechaFin=_fechaFin;
    this->idPeriodo=_idPeriodo;
    this->regSistemaContable=registro;
}

Fecha PeriodoContable::getFechaInicio() {
    return this->fechaInicio;
}

Fecha PeriodoContable::getFechaFin() {
    return this->fechaFin;
}

int PeriodoContable::getIdPeriodo() {
    return this->idPeriodo;
}

int PeriodoContable::crearTransaccion(Fecha *_fechaTran) {

    int codigoTran=contenedorTransaccion.size()+1;
    contenedorTransaccion[codigoTran]=new Transaccion(codigoTran, this->idPeriodo);
    contenedorTransaccion[codigoTran]->setFechaTransaccion(_fechaTran);
    //contenedorTransaccion[codigoTran]->setHoraTransaccion();
    //contenedorTransaccion[codigoTran]->setTipoTransaccion(0);
    //contenedorTransaccion[codigoTran]->guardarTransaccion();
    return contenedorTransaccion[codigoTran]->getCodigoTransaccion();
}

void PeriodoContable::setFechaInicio(Fecha fecha) {

    
}

void PeriodoContable::setFechaFin(Fecha fechaFin) {

    
}

void PeriodoContable::introducirInformacionTransaccion(float importe, bool esCargo, string nombreCuenta, int codigoTransaccion) {

        Cuenta *cuenta=NULL;
        Subcuenta *sub=NULL;
        cuenta=this->regSistemaContable->getDireccionCuenta(nombreCuenta);

        /*verificar si cuenta no es un rubro o clasificacion*/
        if(cuenta==NULL)
        {
                Transaccion *tran;
                sub=this->regSistemaContable->getDireccionSubCuenta(nombreCuenta);
                tran=contenedorTransaccion[codigoTransaccion];
                tran->crearLineadeTransaccion(importe, esCargo, sub);
        }
        else{

                Transaccion *tran;
                tran=contenedorTransaccion[codigoTransaccion];
                tran->crearLineadeTransaccion(importe, esCargo, cuenta);
        }
}
}
