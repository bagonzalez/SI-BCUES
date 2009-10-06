#include <QtGui>

#include "nuevaCuenta.h"

 NuevaCuenta::NuevaCuenta(QDialog *parent)
     : QDialog(parent)
 {
     ui.setupUi(this);
     ui.codAutomatico->setChecked(true);
     ui.codigoManual->setEnabled(false);
     manual=false;

 }

 void NuevaCuenta::on_codManual_clicked ()   {
     ui.codigoManual->setEnabled(true);
     this->manual=true;
 }

 bool NuevaCuenta::getManual(){
     return this->manual;
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




