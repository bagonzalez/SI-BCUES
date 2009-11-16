#include "VentanaPrincipalContables.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

VentanaPrincipalContables::VentanaPrincipalContables(RegistroSistemaContable *reg, RegistroCatalogo *regCat,  basico::Registro  *registroBasico, moduloinventario::InventarioActivoFijo *_inventario)
{
	ui.setupUi(this);
	registro=reg;
        this->registroCatalogo=regCat;        
        this->show();        
        this->move(10,5);
        this->regBasico=registroBasico;
        this->inventario=_inventario;

        Fecha *fech=new Fecha(5, 10, 2009);

        QString configuracion=QString::QString("configuacion.conf");

        QFile file(configuracion);

        if(!file.exists())
        {
             iniciarConfiguracion();
        }
        else{

                    int id;
                    QFile file(configuracion);
                    if (!file.open(QFile::ReadOnly | QFile::Text)) {
                        QMessageBox::warning(this, tr("Aplicacion"),
                              tr("No se puede leer %1:\n%2.")
                              .arg(configuracion)
                              .arg(file.errorString()));
                        return;
                    }

                    QTextStream in(&file);
                    QApplication::setOverrideCursor(Qt::WaitCursor);
                    id=in.readLine(3).toInt();
                    QApplication::restoreOverrideCursor();
                    this->regBasico->crearUnidad(id);
                    this->registro=new RegistroSistemaContable(*fech, this->regBasico);
                    this->registro->crearPeriodoContable(*fech, *fech);

                    this->registro->crearCatalogo(*fech, true);

                    this->registroCatalogo=new RegistroCatalogo(regBasico->getUsuario(), this->registro);
                    this->registroCatalogo->cargarCatalogo();

                    this->inventario->cargarInventario(this->registroCatalogo);


                    accesoUsuario=new AccesoUsuario(this->regBasico, this);
                    on_actionLogear_activated();
        }
        //int diasFinPeriodo=QDate::QDate().currentDate().daysTo(registro->getFechaFinPeriodo());
        //ui.MensajePeriodo->setText("Faltan "+QVariant::QVariant(diasFinPeriodo).toString()+" dias para finalizar el periodo.");
}

VentanaPrincipalContables::~VentanaPrincipalContables(){}

void VentanaPrincipalContables::on_actionContabilidad_activated(){
    /*if(unidad->isUsuarioAdministrador() || unidad->isUsuarioContador()){
        catalogo=new ContGeneral(registro);
	catalogo->show();
	catalogo->setFocus();
        catalogo->setVisible(true);
    }else
    {
       QMessageBox msgBox;
       msgBox.setText("No tiene permiso, debe ser usuario autenticado.");
       msgBox.exec();       
    }*/

    catalogo=new ContGeneral(registro);
    catalogo->show();
    catalogo->setFocus();
    catalogo->setVisible(true);

}

void VentanaPrincipalContables::on_actionSistema_de_Costeo_activated(){    


        catalogoAF=new CatalogoActivoFijoGUI (registroCatalogo, registro, this->regBasico);
        catalogoAF->show();
        catalogoAF->setFocus();
        catalogoAF->setVisible(true);


    /*if(unidad->isUsuarioAdministrador()||unidad->isUsuarioTecnico()){
        catalogoAF=new CatalogoActivoFijoGUI (registroCatalogo, registro);
        catalogoAF->show();
        catalogoAF->setFocus();
        catalogoAF->setVisible(true);
    }else
    {
       QMessageBox msgBox;
       msgBox.setText("No tiene permiso, debe ser usuario autenticado. ");
       msgBox.exec();
    }*/
}

void VentanaPrincipalContables::on_actionLogear_activated(){
    accesoUsuario->move(300, 250);
    accesoUsuario->show();
    accesoUsuario->setVisible(true);
    accesoUsuario->setFocus();

}

void VentanaPrincipalContables::on_actionMaterialBilbliografico_activated(){

     NCReport *report = new NCReport();
     report->reset(true);     
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/ingresoBienesAF.xml");
     NCReportParameter *par = new NCReportParameter( "idIngreso", "13" );
     report->addParameter( par );



     report->runReportToPreview();

      QString error=report->lastErrorMsg();
      std::cout<< error.toStdString();

      NCReportPreviewWindow *pv = new NCReportPreviewWindow();
      pv->setReport( report );
      pv->setOutput( (NCReportPreviewOutput*) report->output() );
      pv->setWindowModality(Qt::ApplicationModal );
      pv->setAttribute( Qt::WA_DeleteOnClose );
      pv->show();
  }

void VentanaPrincipalContables::on_actionConsultaIngreso_activated(){
    this->consultaIngresoBien=new ConsultaIngreso();
    consultaIngresoBien->show();
    consultaIngresoBien->setFocus();
    consultaIngresoBien->setVisible(true);
}

void VentanaPrincipalContables::iniciarConfiguracion(){
    this->primerInicio=new PrimerInicio(this->regBasico);
    primerInicio->show();
    primerInicio->setFocus();
    primerInicio->setVisible(true);

}


void VentanaPrincipalContables::on_actionIngresoActivoFijo_activated(){
    this->ingresoBienesAF=new ingresoBienes(registroCatalogo, registro, this->regBasico, this->inventario);
    ingresoBienesAF->show();
    ingresoBienesAF->setFocus();
    ingresoBienesAF->setVisible(true);
}

void VentanaPrincipalContables::on_actionTrasladoActivoFijo_activated(){
    this->descargoBienesAF=new DescargoBienes(registroCatalogo, registro, this->regBasico, this->inventario);
    descargoBienesAF->show();
    descargoBienesAF->setFocus();
    descargoBienesAF->setVisible(true);
}





