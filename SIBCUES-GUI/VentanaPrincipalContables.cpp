#include "VentanaPrincipalContables.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QTableWidgetItem>

#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"


VentanaPrincipalContables::VentanaPrincipalContables( RegistroCatalogo *regCat,  basico::Registro  *registroBasico, moduloinventario::InventarioActivoFijo *_inventario, QSplashScreen *splash,  QDesktopWidget *desk)
{
        ui.setupUi(this);
        this->desktop=desk;

        this->registroCatalogo=regCat;
        //this->setWindowState(Qt::WindowMaximized);
        this->regBasico=registroBasico;
        this->inventario=_inventario;        
        ui.historialTransacciones->horizontalHeader()->resizeSection(0, 600);

        Fecha *fech=new Fecha(5, 10, 2009);

        QString configuracion=QString::QString("config.db");

        QFile file(configuracion);

        if(!file.exists())
        {
             iniciarConfiguracion();
        }
        else{

                    int id, idCatalogo=1;
                    RegistroSistemaContable *registroContable;
                    /*QFile file(configuracion);
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
                    idCatalogo=in.readLine(3).toInt();
                    QApplication::restoreOverrideCursor();*/
                    {
                        splash->showMessage("Estableciendo Conexiones", Qt::AlignLeft, Qt::white);


                        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "en_memoria_db");
                        db.setDatabaseName("config.db");
                        if (!db.open()) {
                        }

                        QSqlQuery query(QSqlDatabase::database("en_memoria_db"));
                        QString SQL="SELECT `unidad`  FROM `configuracion` WHERE `id` =1";
                        query.exec(SQL);
                        while (query.next()){
                            id=query.value(0).toString().toInt();
                            std::cout << "unidad -->" << id << "fin";
                        }
                        query.clear();
                        db.close();
                        //db=QSqlDatabase::addDatabase("QMYSQL", "sibcues");
                    }
                    QSqlDatabase::removeDatabase("en_memoria_db");

                    splash->showMessage("Cargando unidad y usuarios", Qt::AlignLeft, Qt::white);

                    this->regBasico->crearUnidad(id);
                    //this->regBasico->getUnidad()->idCatalogo=idCatalogo;

                    /*splash->showMessage("Cargando catalogo contable", Qt::AlignLeft, Qt::white);

                    registroContable=new RegistroSistemaContable(this->regBasico);
                    registroContable->crearPeriodoContable(*fech, *fech);*/

                    /*Revisar*/
                    /*registroContable->crearCatalogo(*fech, true, true);

                    registroCatalogo=new RegistroCatalogo(regBasico->getUsuario(), registroContable);

                    splash->showMessage("Cargando catalogo de activo fijo", Qt::AlignLeft, Qt::white);
                    registroCatalogo->cargarCatalogo();
                   //this->regBasico->getUnidad()->idInventario
                    this->inventario->cargarInventario(this->registroCatalogo, 1);*/


                    //registroContable->~RegistroSistemaContable();

                     this->show();
                    accesoUsuario=new AccesoUsuario(this->regBasico, this, this);
                    accesoUsuario->setWindowFlags(Qt::Window);
                    accesoUsuario->setGeometry(     QStyle::alignedRect( Qt::LeftToRight,
                                                    Qt::AlignCenter,
                                                    accesoUsuario->size(),
                                                    this->desktop->availableGeometry()
                                            ));

                    on_actionLogear_activated();
        }
        int diasFinPeriodo=QDate::QDate().currentDate().daysTo(QDate(2009, 12, 15));

        //ui.MensajePeriodo->setText("Faltan "+QVariant::QVariant(diasFinPeriodo).toString()+" dias para finalizar el periodo.");

}

VentanaPrincipalContables::~VentanaPrincipalContables(){}

void VentanaPrincipalContables::on_actionContabilidad_activated(){

    RegistroSistemaContable *registroContable;
    Fecha *fech=new Fecha(5, 10, 2009);
    registroContable=new RegistroSistemaContable(this->regBasico);
    registroContable->crearPeriodoContable(*fech, *fech);

    /*Revisar*/
    registroContable->crearCatalogo(*fech, true, false);

    if(this->regBasico->getUsuario()!=NULL){
        if(this->regBasico->getRolUsuario()==1 || this->regBasico->getRolUsuario()==2){
            catalogo=new CatalogoContable(registroContable);
            catalogo->setWindowFlags(Qt::Dialog);
            catalogo->exec();
            catalogo->~CatalogoContable();

        }else
        {
           QMessageBox msgBox;
           msgBox.setText("No tiene permiso, debe ser usuario autenticado.");
           msgBox.exec();
        }
    }

    registroContable->~RegistroSistemaContable();
}

void VentanaPrincipalContables::on_actionSistema_de_Costeo_activated(){
    RegistroSistemaContable *registroContable;
    Fecha *fech=new Fecha(5, 10, 2009);

    registroContable=new RegistroSistemaContable(this->regBasico);
    registroContable->crearPeriodoContable(*fech, *fech);

    /*Revisar*/
    registroContable->crearCatalogo(*fech, true, true);

    if(this->regBasico->getUsuario()!=NULL){
        if(this->regBasico->getRolUsuario()==1 ){
            catalogoAF=new CatalogoActivoFijoGUI (registroCatalogo, registroContable, this->regBasico);
            catalogoAF->show();
            catalogoAF->setFocus();
            catalogoAF->setVisible(true);
            catalogoAF->exec();

            catalogoAF->~CatalogoActivoFijoGUI();
        }else
        {
           QMessageBox msgBox;
           msgBox.setText("No tiene permiso, debe ser usuario autenticado.");
           msgBox.exec();
        }
    }
    registroContable->~RegistroSistemaContable();
}

void VentanaPrincipalContables::on_actionLogear_activated(){


    accesoUsuario->show();
    accesoUsuario->setVisible(true);    
    accesoUsuario->setFocus();    
}

void VentanaPrincipalContables::on_actionMaterialBilbliografico_activated(){

     Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);
     servicioPersistencia->crearConexion();

     /*NCReport *report = new NCReport();
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/catalogoMB.xml");

     report->runReportToPreview();
      QString error=report->lastErrorMsg();
      std::cout<< error.toStdString();*/

     /* NCReportPreviewWindow *pv = new NCReportPreviewWindow();
      pv->setReport( report );
      pv->setOutput( (NCReportPreviewOutput*) report->output() );
      pv->setWindowModality(Qt::ApplicationModal );
      pv->setAttribute( Qt::WA_DeleteOnClose );
      pv->show();*/

  }

void VentanaPrincipalContables::on_actionConsultaIngreso_activated(){
    if(this->regBasico->getUsuario()!=NULL){
        this->consultaIngresoBien=new ConsultaIngreso(this->regBasico->getUnidad()->id, this);
        consultaIngresoBien->setWindowFlags(Qt::Window);
        consultaIngresoBien->setGeometry(     QStyle::alignedRect( Qt::LeftToRight,
                                        Qt::AlignCenter,
                                        consultaIngresoBien->size(),
                                        this->desktop->availableGeometry()
                                ));

        consultaIngresoBien->show();
        consultaIngresoBien->setFocus();
        consultaIngresoBien->setVisible(true);
    }
}

void VentanaPrincipalContables::iniciarConfiguracion(){

    RegistroSistemaContable *registroContable;
    Fecha *fech=new Fecha(5, 10, 2009);

    registroContable=new RegistroSistemaContable(this->regBasico);
    registroContable->crearPeriodoContable(*fech, *fech);


    this->primerInicio=new PrimerInicio(registroCatalogo, registroContable, this->regBasico, this->inventario);
    primerInicio->show();    
    primerInicio->setFocus();
    primerInicio->setVisible(true);
}


void VentanaPrincipalContables::on_actionIngresoActivoFijo_activated(){

    RegistroSistemaContable *registroContable;
    Fecha *fech=new Fecha(5, 10, 2009);
    registroContable=new RegistroSistemaContable(this->regBasico);
    registroContable->crearPeriodoContable(*fech, *fech);

    /*Revisar*/
    registroContable->crearCatalogo(*fech, true, true);

    if(this->regBasico->getUsuario()!=NULL){
        if(this->regBasico->getRolUsuario()==1 || this->regBasico->getRolUsuario()==2){

            ingresoBienes *ingresoBienesAF=new ingresoBienes(registroContable, this->regBasico, this->inventario, this);
            ingresoBienesAF->setAttribute(Qt::WA_DeleteOnClose);
            ingresoBienesAF->setGeometry(     QStyle::alignedRect( Qt::LeftToRight,
                                                                Qt::AlignCenter,
                                                                ingresoBienesAF->size(),
                                                                this->desktop->availableGeometry()
                                         ));
            ingresoBienesAF->show();

        }else
        {
           QMessageBox msgBox;
           msgBox.setText("No tiene permiso, debe ser usuario autenticado.");
           msgBox.exec();
        }
    }

}

void VentanaPrincipalContables::on_actionTrasladoActivoFijo_activated(){
    RegistroSistemaContable *registroContable;
    Fecha *fech=new Fecha(5, 10, 2009);
    registroContable=new RegistroSistemaContable(this->regBasico);
    registroContable->crearPeriodoContable(*fech, *fech);

    /*Revisar*/
    registroContable->crearCatalogo(*fech, true, true);

      if(this->regBasico->getUsuario()!=NULL){
        if(this->regBasico->getRolUsuario()==1){

            //this->registroCatalogo->cargarCatalogo(this->regBasico->getUnidad()->idCatalogo);

            this->traslado=new TrasladoActivoFijo(registroCatalogo, registroContable, this->regBasico, this->inventario);
            traslado->setGeometry(     QStyle::alignedRect( Qt::LeftToRight,
                                                                Qt::AlignCenter,
                                                                traslado->size(),
                                                                this->desktop->availableGeometry()
                                         ));

            traslado->show();
            traslado->setFocus();
            traslado->setVisible(true);
        }
        else{
           QMessageBox msgBox;
           msgBox.setText("No tiene permiso, debe ser usuario autenticado.");
           msgBox.exec();
        }
    }
}

void VentanaPrincipalContables::on_actionConsulta_de_Descargos_de_Bienes_activated(){
    if(this->regBasico->getUsuario()!=NULL){
        this->consultaDescargo=new ConsultaDescargos(this->regBasico->getUnidad()->id, this);

        consultaDescargo->setWindowFlags(Qt::Window);

        consultaDescargo->setGeometry(     QStyle::alignedRect( Qt::LeftToRight,
                                        Qt::AlignCenter,
                                        consultaDescargo->size(),
                                        this->desktop->availableGeometry()
                                ));

        consultaDescargo->show();
        consultaDescargo->setFocus();
        consultaDescargo->setVisible(true);
    }
}


void VentanaPrincipalContables::on_actionDescargo_activated(){

    RegistroSistemaContable *registroContable;
    Fecha *fech=new Fecha(5, 10, 2009);
    registroContable=new RegistroSistemaContable(this->regBasico);
    registroContable->crearPeriodoContable(*fech, *fech);

    /*Revisar*/
    registroContable->crearCatalogo(*fech, true, true);

    if(this->regBasico->getUsuario()!=NULL){
        if(this->regBasico->getRolUsuario()==1){
            //this->registroCatalogo->cargarCatalogo(this->regBasico->getUnidad()->idCatalogo);
            this->descargoBienesAF=new DescargoBienes(registroCatalogo, registroContable, this->regBasico, this->inventario, this);
            descargoBienesAF->setGeometry(     QStyle::alignedRect( Qt::LeftToRight,
                                                                Qt::AlignCenter,
                                                                descargoBienesAF->size(),
                                                                this->desktop->availableGeometry()
                                         ));



            descargoBienesAF->show();
            descargoBienesAF->setFocus();
            descargoBienesAF->setVisible(true);
        }
        else{
           QMessageBox msgBox;
           msgBox.setText("No tiene permiso, debe ser usuario autenticado.");
           msgBox.exec();
        }
    }
}

void VentanaPrincipalContables::on_actionConsulta_Traslado_de_Bienes_activated(){
    if(this->regBasico->getUsuario()!=NULL){
        this->consultaTraslado=new consultaTraslados(this->regBasico->getUnidad()->id, this);
        consultaTraslado->setWindowFlags(Qt::Window);

        consultaTraslado->setGeometry(     QStyle::alignedRect( Qt::LeftToRight,
                                        Qt::AlignCenter,
                                        consultaTraslado->size(),
                                        this->desktop->availableGeometry()
                                ));


        consultaTraslado->show();
        consultaTraslado->setFocus();
        consultaTraslado->setVisible(true);
    }
}

void VentanaPrincipalContables::on_actionIngresoBibliografico_activated(){

    RegistroSistemaContable *registroContable;
    Fecha *fech=new Fecha(5, 10, 2009);
    registroContable=new RegistroSistemaContable(this->regBasico);
    registroContable->crearPeriodoContable(*fech, *fech);

    /*Revisar*/
    registroContable->crearCatalogo(*fech, true, true);

    if(this->regBasico->getUsuario()!=NULL){
        if(this->regBasico->getRolUsuario()==1){
            //this->registroCatalogo->cargarCatalogo(this->regBasico->getUnidad()->idCatalogo);
            this->ingresoBiblio=new IngresoBienesBiblio(registroCatalogo, registroContable, this->regBasico, this->inventario);
            ingresoBiblio->show();
            ingresoBiblio->setFocus();
            ingresoBiblio->setVisible(true);
        }else{
           QMessageBox msgBox;
           msgBox.setText("No tiene permiso, debe ser usuario autenticado.");
           msgBox.exec();
        }
    }
}


void VentanaPrincipalContables::on_actionDescargo_2_activated(){

    RegistroSistemaContable *registroContable;
    Fecha *fech=new Fecha(5, 10, 2009);
    registroContable=new RegistroSistemaContable(this->regBasico);
    registroContable->crearPeriodoContable(*fech, *fech);

    /*Revisar*/
    registroContable->crearCatalogo(*fech, true, true);

    if(this->regBasico->getUsuario()!=NULL){
        if(this->regBasico->getRolUsuario()==1){
            //this->registroCatalogo->cargarCatalogo(this->regBasico->getUnidad()->idCatalogo);
            this->decargoBienesMB=new DescargoBienesMB(registroCatalogo, registroContable, this->regBasico, this->inventario);
            decargoBienesMB->show();
            decargoBienesMB->setFocus();
            decargoBienesMB->setVisible(true);
        }else{
           QMessageBox msgBox;
           msgBox.setText("No tiene permiso, debe ser usuario autenticado.");
           msgBox.exec();
        }
    }
}

void VentanaPrincipalContables::on_actionTraslado_activated(){

    RegistroSistemaContable *registroContable;
    Fecha *fech=new Fecha(5, 10, 2009);
    registroContable=new RegistroSistemaContable(this->regBasico);
    registroContable->crearPeriodoContable(*fech, *fech);

    /*Revisar*/
    registroContable->crearCatalogo(*fech, true, true);

    if(this->regBasico->getUsuario()!=NULL){
        if(this->regBasico->getRolUsuario()==1){
            //this->registroCatalogo->cargarCatalogo(this->regBasico->getUnidad()->idCatalogo);
            this->trasladoMB=new TrasladoBienesBiblio(registroCatalogo, registroContable, this->regBasico, this->inventario);
            trasladoMB->show();
            trasladoMB->setFocus();
            trasladoMB->setVisible(true);
        }else{
           QMessageBox msgBox;
           msgBox.setText("No tiene permiso, debe ser usuario autenticado.");
           msgBox.exec();
        }
    }

}

void VentanaPrincipalContables::on_catalogoActivoFijo_activated(){

     Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);

     servicioPersistencia->crearConexion();

     NCReport *report = new NCReport();
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/catalogoActivoFijo.xml");

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

void VentanaPrincipalContables::on_catalogoCuenta_activated(){

      Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);

     servicioPersistencia->crearConexion();

     NCReport *report = new NCReport();
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/CtalogoCuenta.xml");

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

void VentanaPrincipalContables::on_consolidadoAF_activated(){
     Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);

     servicioPersistencia->crearConexion();
     NCReport *report = new NCReport();
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/consolidadoBienesAF.xml");

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

void VentanaPrincipalContables::on_actionConsolidade_de_Material_Bibliografico_activated(){

     Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);
     servicioPersistencia->crearConexion();

     NCReport *report = new NCReport();
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/consolidadoBienesBiblio.xml");
     progresoReporte *progreso=new progresoReporte(report);
     progreso->show();
     progreso->execReport();

      QString error=report->lastErrorMsg();
      std::cout<< error.toStdString();

      NCReportPreviewWindow *pv = new NCReportPreviewWindow();
      pv->setReport( report );
      pv->setOutput( (NCReportPreviewOutput*) report->output() );
      pv->setWindowModality(Qt::ApplicationModal );
      pv->setAttribute( Qt::WA_DeleteOnClose );
      pv->show();
}

void VentanaPrincipalContables::on_actionUsuario_activated(){

     Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);

     servicioPersistencia->crearConexion();
     NCReport *report = new NCReport(this);
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/usuarios.xml");

     report->runReportToPreview();     
      QString error=report->lastErrorMsg();
      std::cout<< error.toStdString();

      NCReportPreviewWindow *pv = new NCReportPreviewWindow();
      pv->setReport( report );     
      pv->setOutput( (NCReportPreviewOutput*) report->output() );
      pv->setWindowModality(Qt::ApplicationModal );
      //pv->setAttribute( Qt::WA_DeleteOnClose );
      pv->show();
}

void VentanaPrincipalContables::on_actionGestionUsuario_activated(){
    if(this->regBasico->getUsuario()!=NULL){
        if(this->regBasico->getRolUsuario()==1){
            this->usuariosAdmin=new MainWindow(this->regBasico->getUnidad()->id);
            this->usuariosAdmin->setGeometry( QStyle::alignedRect( Qt::LeftToRight,
                                            Qt::AlignCenter,
                                            usuariosAdmin->size(),
                                            this->desktop->availableGeometry()
                                    ));
            this->usuariosAdmin->show();
        }else{
           QMessageBox msgBox;
           msgBox.setText("No tiene permiso, debe ser usuario autenticado.");
           msgBox.exec();
        }
    }
}

void VentanaPrincipalContables::on_actionManual_usuario_activated(){
    this->manual=new manualUsuario();
    manual->show();
    manual->setFocus();
    manual->setVisible(true);
}

void VentanaPrincipalContables::on_actionPresupuesto_activated(){
    this->variacionPresupuestacia=new VariacionPresupuestaria ();
    this->variacionPresupuestacia->show();
    this->variacionPresupuestacia->setVisible(true);
}

void VentanaPrincipalContables::on_actionMarcas_activated(){
    marcas *marca=new marcas(this->regBasico->getUnidad()->id);
    marca->exec();
}

void VentanaPrincipalContables::on_actionSectores_o_dependencias_activated(){
    SectoresGUI *dialogoSectores=new SectoresGUI(this->regBasico);
    dialogoSectores->exec();
}

void VentanaPrincipalContables::on_actionTitulos_activated(){    
    mantenimientoTitulo *dialogoTitulo=new mantenimientoTitulo(this->regBasico->getUnidad()->id);
    dialogoTitulo->exec();
}

void VentanaPrincipalContables::on_actionIngresos_en_procesos_activated(){

    RegistroSistemaContable *registroContable;
    Fecha *fech=new Fecha(5, 10, 2009);
    registroContable=new RegistroSistemaContable(this->regBasico);
    registroContable->crearPeriodoContable(*fech, *fech);

    /*Revisar*/
    registroContable->crearCatalogo(*fech, true, true);

    IngresoenProceso *dialogoIngresoenProceso=new IngresoenProceso(this->regBasico->getUnidad()->id);
    dialogoIngresoenProceso->setWindowFlags(Qt::SubWindow);
    dialogoIngresoenProceso->exec();

    ingresoBienes *ingresoBienesAF=new ingresoBienes(registroContable, this->regBasico, this->inventario);

    if(dialogoIngresoenProceso->getIdIngreso()!=0){
        this->on_actionIngresoActivoFijo_activated();
        ingresoBienesAF->setTabla(dialogoIngresoenProceso->getIdIngreso(), dialogoIngresoenProceso->getListaItems());
    }
}

void VentanaPrincipalContables::on_actionConsulta_de_Bienes_activated(){

    RegistroSistemaContable *registroContable;
    Fecha *fech=new Fecha(5, 10, 2009);

    registroContable=new RegistroSistemaContable(this->regBasico);
    registroContable->crearPeriodoContable(*fech, *fech);

    /*Revisar*/
    registroContable->crearCatalogo(*fech, true, true);
    ConsultaBienes *dialogoConsultaBienes=new ConsultaBienes(this->registroCatalogo, registroContable, this->regBasico, this->inventario);
    dialogoConsultaBienes->exec();
}

void VentanaPrincipalContables::on_actionDescargos_en_Proceso_activated()
{
    DescargosProceso *descargosProceso=new DescargosProceso(this->regBasico->getUnidad()->id);
    descargosProceso->exec();

    if(descargosProceso->getIdDescargo()!=0){
        this->on_actionDescargo_activated();
        this->descargoBienesAF->setTabla(descargosProceso->getIdDescargo(), descargosProceso->getListaItems());
    }
}


void VentanaPrincipalContables::on_actionInventarios_activated(){
    ManttoInventario *manttoInv=new ManttoInventario(this->regBasico->getUnidad()->id);
    manttoInv->exec();
}

void VentanaPrincipalContables::on_actionReporte_por_sector_activated(){
    BienesporSector *bienes=new BienesporSector(this->regBasico);
    bienes->exec();

}
