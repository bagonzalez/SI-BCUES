#include <QtGui>

#include "nuevaCuenta.h"

 NuevaCuenta::NuevaCuenta(QDialog *parent)
     : QDialog(parent)
 {
     ui.setupUi(this);


 }



 void  NuevaCuenta::on_buttonBox_accepted()
 {
	nombreCuenta=ui.lineEdit->text();
	descripcion=ui.textEdit->toPlainText(); 
        this->codigo=ui.codigoManual->text();
 }

 void  NuevaCuenta::on_buttonBox_rejected()
 {
     
 }


QString NuevaCuenta::getDescripcion()
{
	return descripcion;
}


QString NuevaCuenta::getCodigoManual(){
    return this->codigo;
}



QString NuevaCuenta::getNombreCuenta()
{
	return nombreCuenta;
}

void NuevaCuenta::on_radioButton_clicked()
{
    this->tipoDestino="ingreso";

}

void NuevaCuenta::on_radioButton_2_clicked()
{
    this->tipoDestino="gasto";
}

QString NuevaCuenta::getTipoDestino()
{
    return this->tipoDestino;
}
