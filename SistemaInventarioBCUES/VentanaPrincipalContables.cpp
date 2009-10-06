#include "VentanaPrincipalContables.h"

VentanaPrincipalContables::VentanaPrincipalContables(RegistroSistemaContable *reg, RegistroCatalogo *regCat)
{
	ui.setupUi(this);
	registro=reg;
        this->registroCatalogo=regCat;
        //int diasFinPeriodo=QDate::QDate().currentDate().daysTo(registro->getFechaFinPeriodo());
        //ui.MensajePeriodo->setText("Faltan "+QVariant::QVariant(diasFinPeriodo).toString()+" dias para finalizar el periodo.");
}

VentanaPrincipalContables::~VentanaPrincipalContables(){}

void VentanaPrincipalContables::on_actionContabilidad_activated(){
        catalogo=new ContGeneral(registro);
	catalogo->show();
	catalogo->setFocus();
        catalogo->setVisible(true);
}

void VentanaPrincipalContables::on_actionSistema_de_Costeo_activated(){
        catalogoAF=new CatalogoActivoFijoGUI (registroCatalogo, registro);
        catalogoAF->show();
        catalogoAF->setFocus();
        catalogoAF->setVisible(true);
}

void VentanaPrincipalContables::on_actionAcerca_de_activated(){
        /*acercaDe=new AcercaDe();
	acercaDe->show();
	acercaDe->setFocus();
        acercaDe->setVisible(true);*/
}




