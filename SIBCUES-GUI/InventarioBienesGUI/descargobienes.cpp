#include "descargobienes.h"
#include "ui_descargobienes.h"


#include <QCompleter>
#include <QMessageBox>
#include <QSqlQuery>

DescargoBienes::DescargoBienes(RegistroCatalogo *_regCatalogo, contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, InventarioActivoFijo *_inventario, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::DescargoBienes)
{
    m_ui->setupUi(this);
    this->setWindowFlags(Qt::Window);

    this->registroContable=regC;
    //this->registroCatalogo=_regCatalogo;
    this->registroCatalogo=new RegistroCatalogo(registroBasico->getUsuario(), regC);

    //CARGAR EL CATALOGO CON EL AÑO
    //this->registroCatalogo->cargarCatalogo();

    this->regBasico=registroBasico;
    this->inventario=_inventario;

    this->valorTotal=0.0;

    m_ui->finalizarTransaccion->setDisabled(true);

    servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);

    QMap<int, QString> listaAnioInventa=servicioPersistencia->getInventariosFijos();

    for(QMap<int, QString>::iterator it = listaAnioInventa.begin();
        it != listaAnioInventa.end();
        ++it
    ){

            m_ui->anioInventario->addItem(QString(it.value()), QVariant::QVariant(it.key()));
    }

    QStringList labels;
        labels << tr("Cuenta") << tr("Clase") <<tr("Especifico")  << tr("Correlativo") <<  tr("Descripcion del Bien") << tr("Marca") <<  tr("Modelo") << tr("Serie") << tr("Fecha Adq.") << tr("Valor ($)") <<tr("idBien") ;
        m_ui->tablaBienes->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
        m_ui->tablaBienes->setSelectionBehavior ( QAbstractItemView::SelectRows);
        m_ui->tablaBienes->setColumnCount(11);
        m_ui->tablaBienes->setHorizontalHeaderLabels(labels);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(0, 50);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(1, 50);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(2, 60);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(3, 60);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(4, 240);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(5, 80);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(6, 80);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(7, 100);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(8, 80);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(9, 80);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(10, 80);
        m_ui->tablaBienes->hideColumn(10);

        fila=0;

}

void DescargoBienes::cargarInventario(string anio){

    this->inventario->cargarInventario(registroCatalogo,this->regBasico->getUnidad()->id, anio);
    completer();
}


DescargoBienes::~DescargoBienes()
{
    delete m_ui;
}

void DescargoBienes::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void DescargoBienes::on_anioInventario_currentIndexChanged ( ){
    string anio=QString(m_ui->anioInventario->currentText()).toStdString() ;
    this->registroCatalogo->cargarCatalogo(this->servicioPersistencia->getIDInvFijo(anio));
    this->cargarInventario(anio);
}


void DescargoBienes::on_cancelar_pressed(){
    this->close();
}



void DescargoBienes::completer(){
    QList<QString> myQString;

    listaCodigosCuentas=this->registroContable->getHijosCatalogo();
    myQString.clear();

    for
    (
            map<string, string>::iterator it = listaCodigosCuentas.begin();
            it != listaCodigosCuentas.end();
                ++it
     ){
          if(it->first!="12090")
           myQString.push_back(QString::fromStdString(it->first));
    }

    QCompleter *completer2 = new QCompleter(myQString, this);
    completer2->setCaseSensitivity(Qt::CaseInsensitive);
    m_ui->cuentaNO->setCompleter(completer2);
}


void DescargoBienes::on_cuentaNO_editingFinished (){

    QList<QString> myQString;

    m_ui->cuentaAsignada->setText(QString(  this->listaCodigosCuentas[m_ui->cuentaNO->text().toStdString()].c_str()  ));

    list<string> listaClases=this->registroCatalogo->getClases( m_ui->cuentaAsignada->text().toStdString());

    for
    (
        list<string>::iterator from = listaClases.begin();
        from != listaClases.end();
        ++from
    ){
            myQString.push_back(QString(QVariant::QVariant((*from).c_str()).toString()));
    }        

    QCompleter *completer2 = new QCompleter(myQString, this);
    completer2->setCaseSensitivity(Qt::CaseInsensitive);
    m_ui->claseNO->setCompleter(completer2);
}

void DescargoBienes::on_claseNO_editingFinished (){
    string nombreClase=m_ui->claseNO->text().toStdString();
    string cuentaAsignada=m_ui->cuentaAsignada->text().toStdString();

    if(this->registroCatalogo->getClase(nombreClase, cuentaAsignada)!=NULL){

        //m_ui->nombreEspecifico->setText(QString::QString(this->registroCatalogo->getClase(nombreClase, cuentaAsignada)->idEspecifico->nombreCuenta.c_str()));
        //m_ui->especificoNO->setText(QString::fromStdString(this->registroCatalogo->getClase(nombreClase, cuentaAsignada)->idEspecifico->getcodigoCuenta()));

        QList<QString> myQString;

        list<string> listaCorrelativos=this->inventario->getCorrelativosAF(nombreClase, cuentaAsignada);

        for
        (
            list<string>::iterator from = listaCorrelativos.begin();
            from != listaCorrelativos.end();
            ++from
        ){
            myQString.push_back(QString(QVariant::QVariant((*from).c_str()).toString()));
        }

        QCompleter *completer2 = new QCompleter(myQString, this);
        completer2->setCaseSensitivity(Qt::CaseInsensitive);
        m_ui->correlativoNO->setCompleter(completer2);
    }
}

void DescargoBienes::on_correlativoNO_editingFinished (){
    string nombreClase=m_ui->claseNO->text().toStdString();
    string cuentaAsignada=m_ui->cuentaAsignada->text().toStdString();
    string correlativo=m_ui->correlativoNO->text().toStdString();
    string marca, modelo, especifico, nombreEspecifico;


    Bien *bien=this->inventario->getBienAF(nombreClase, cuentaAsignada, correlativo);

    if(bien!=NULL){
        m_ui->valorBien->setValue(bien->getValor());
        m_ui->descripcion->setText(QString::QString(bien->getEspecAF()->getDescipcion().c_str()));
        m_ui->serie->setText(QString::QString(bien->getSerie().c_str()));

        //Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);
        modelo=servicioPersistencia->getModelo(bien->idModelo);
        marca=servicioPersistencia->getMarca(bien->idMarca);
        especifico=servicioPersistencia->getEspecifico(bien->idEspecifico);
        nombreEspecifico=servicioPersistencia->getNombreEspecifico(especifico);

        m_ui->modelo->setText(QString::fromStdString(modelo));
        m_ui->marca->setText(QString::fromStdString(marca));
        m_ui->especificoNO->setText(QString::fromStdString(especifico));
        m_ui->nombreEspecifico->setText(QString::fromStdString(nombreEspecifico));


        m_ui->fechaAquisicion->setDate(QDate::QDate(bien->fechaAdquisicion->getAnio(), bien->fechaAdquisicion->getMes(), bien->fechaAdquisicion->getDia()));


    }else{
        limpiar();
    }

}

void DescargoBienes::limpiar(){
    m_ui->descripcion->clear();
    m_ui->serie->clear();
    m_ui->modelo->clear();
    m_ui->marca->clear();
    m_ui->valorBien->clear();
    m_ui->nombreEspecifico->clear();
    m_ui->cuentaAsignada->clear();
    m_ui->cuentaNO->clear();
    m_ui->claseNO->clear();
    m_ui->cuentaNO->setFocus();

}

void DescargoBienes::setTabla(int idDescargo, QList<QTableWidgetItem *> items){
    columna=0;
    m_ui->tablaBienes->insertRow(fila);

    int totalFilas=(items.size()/10 -1);

    for(int i=0; i< items.size() ; ++i ){
        m_ui->tablaBienes->setItem(fila, columna, items.at(i));
        columna++;
        if(columna > 10 && fila < totalFilas){
            fila++;
            columna=0;
            m_ui->tablaBienes->insertRow(fila);
        }
    }

    fila=m_ui->tablaBienes->rowCount();
    for(int i=0; i<fila; i++){
        this->valorTotal=this->valorTotal+m_ui->tablaBienes->model()->index(i, 9).data(0).toFloat();
    }

    m_ui->totalIngreso->setText(QString("$ %1").arg(valorTotal, 0, 'f', 2));


    nuevoIngreso=false;
    this->idDescargo=idDescargo;

    QString SQL="SELECT `codigoDescargo`, `motivoDescargo`, `observaciones` FROM descargobienes WHERE idDescargo="+QString::number(idDescargo);
    QSqlQuery query(QSqlDatabase::database("sibcues"));;
    query.exec(SQL);

    while(query.next()){
        m_ui->codigoDescargo->setText(query.value(0).toString());
        m_ui->motivo->setText(query.value(1).toString());
        m_ui->observaciones->setText(query.value(2).toString());
    }

    m_ui->finalizarTransaccion->setEnabled(true);
}

void DescargoBienes::on_botonAgregarBien_pressed(){

    string nombreClase=m_ui->claseNO->text().toStdString();
    string cuentaAsignada= m_ui->cuentaAsignada->text().toStdString();
    string numCuenta=m_ui->cuentaNO->text().toStdString();
    string marca=m_ui->marca->text().toStdString();
    string modelo=m_ui->modelo->text().toStdString();
    string serie=m_ui->serie->text().toStdString();
    string correlativo=m_ui->correlativoNO->text().toStdString();
    QString fechaAdqui=m_ui->fechaAquisicion->date().toString(Qt::ISODate);
    float valor=m_ui->valorBien->value();
    Bien *bien;
    bool existe=false;

    if(!m_ui->cuentaAsignada->text().isEmpty() && !m_ui->claseNO->text().isEmpty() && !m_ui->nombreEspecifico->text().isEmpty()){

        m_ui->finalizarTransaccion->setEnabled(true);

        if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
         {
            bien=this->inventario->getBienAF(nombreClase, cuentaAsignada, correlativo);

            for
            (
               map<int, Bien*>::iterator it = listaBienes.begin();
               it != listaBienes.end();
                ++it
            ){
                if( (it->second->getEspecAF()->getClase()->getCuentaAsignada())==cuentaAsignada && (it->second->getEspecAF()->getClase()->getNombreClase()) == nombreClase ){
                   if(it->second->correlativo==correlativo){
                        existe=true;
                    }
                }
            }


            if(!existe){

                this->listaBienes[bien->oid]=bien;

                m_ui->botonEliminarBien->setEnabled(true);
                columna=0;
                m_ui->tablaBienes->insertRow(fila);

                QTableWidgetItem *newCuenta = new QTableWidgetItem(QString(numCuenta.c_str()));

                m_ui->tablaBienes->setItem(fila, columna, newCuenta);

                columna++;

                QTableWidgetItem *newClase = new QTableWidgetItem(QString(nombreClase.c_str()));

                m_ui->tablaBienes->setItem(fila, columna, newClase);


                moduloinventario::EspecificacionBien *espec=this->registroCatalogo->getEspecificacion(nombreClase , cuentaAsignada );

                columna++;

                QTableWidgetItem *newEspecifico = new QTableWidgetItem(m_ui->especificoNO->text());
                m_ui->tablaBienes->setItem(fila, columna, newEspecifico);

                columna++;

                QTableWidgetItem *newCorrelativo = new QTableWidgetItem(m_ui->correlativoNO->text());

                m_ui->tablaBienes->setItem(fila, columna, newCorrelativo);


                columna++;


                QTableWidgetItem *newDescripcion = new QTableWidgetItem(QString(espec->descripcion.c_str()));

                m_ui->tablaBienes->setItem(fila, columna, newDescripcion);

                columna++;

                QTableWidgetItem *newMarca = new QTableWidgetItem(QString(marca.c_str()));

                m_ui->tablaBienes->setItem(fila, columna, newMarca);

                columna++;

                QTableWidgetItem *newModelo = new QTableWidgetItem(QString(modelo.c_str()));

                m_ui->tablaBienes->setItem(fila, columna, newModelo);

                columna++;

                QTableWidgetItem *newSerie = new QTableWidgetItem(QString(serie.c_str()));

                m_ui->tablaBienes->setItem(fila, columna, newSerie );

                columna++;

                QTableWidgetItem *newFechaAdq = new QTableWidgetItem(fechaAdqui);

                m_ui->tablaBienes->setItem(fila, columna, newFechaAdq );

                columna++;

                QTableWidgetItem *newValorBien= new QTableWidgetItem(QString::number(valor));

                m_ui->tablaBienes->setItem(fila, columna, newValorBien );

                columna++;

                QTableWidgetItem *newIDBIEN= new QTableWidgetItem("0");
                m_ui->tablaBienes->setItem(fila, columna, newIDBIEN );

                this->valorTotal=this->valorTotal+valor;
                m_ui->totalIngreso->setText(QString("$ %1").arg(this->valorTotal, 0, 'f', 2));
                fila++;
            }
            else{
                  QMessageBox msgBox;
                  msgBox.warning(0, "Error","    El bien ya se encuentra en la lista!.   ");
            }
        }
    }
    this->limpiar();

}


void DescargoBienes::on_botonEliminarBien_pressed(){
    if(m_ui->tablaBienes->currentItem()!=NULL)
    {
                int filaActual=m_ui->tablaBienes->currentRow();
                float valor=m_ui->tablaBienes->item(filaActual, 9)->data(0).toString().toFloat();

                int codBien=m_ui->tablaBienes->item(filaActual, 10)->data(0).toInt();

                if(codBien!=0){
                    QString SQL="DELETE FROM lineaDescargoAF WHERE lineaDescargoAF.idBien =  "+QString::number(codBien);
                    QSqlQuery query(QSqlDatabase::database("sibcues"));;
                    query.exec(SQL);
                    query.clear();

                    SQL="UPDATE bienactivofijo SET bienactivofijo.estadoBien='activo' WHERE bienactivofijo.idBien =  "+QString::number(codBien);
                    query.exec(SQL);
                }

                string nombreClase=m_ui->tablaBienes->item(filaActual, 1)->data(0).toString().toStdString();
                string cuentaAsignada=this->listaCodigosCuentas[m_ui->tablaBienes->item(filaActual, 0)->data(0).toString().toStdString()];
                string correlativo=m_ui->tablaBienes->item(filaActual, 3)->data(0).toString().toStdString();

                Bien *bien=this->inventario->getBienAF(nombreClase, cuentaAsignada, correlativo);
                this->listaBienes.erase(bien->oid);
                m_ui->tablaBienes->removeRow (filaActual);
                
                this->valorTotal=this->valorTotal-valor;
                m_ui->totalIngreso->setText(QString("$ %1").arg(this->valorTotal, 0, 'f', 2));
                fila--;
    }
    else
    {
        QMessageBox::information(this, tr("Eliminar Fila"),
        tr("Seleccione una fila para poder eliminar!"), QMessageBox::Ok, QMessageBox::Ok);
    }
}

void DescargoBienes::on_finalizarTransaccion_pressed(){
    this->estadoDescargo="finalizado";
    this->descargar();
}

void DescargoBienes::descargar(){

    QMessageBox msgBox;
    msgBox.setText("Descargo de Bienes");
    msgBox.setInformativeText("¿Desea guardar y terminar la transaccion?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);

    msgBox.setDefaultButton(QMessageBox::Save);

    int ret = msgBox.exec();

    switch (ret) {
        case QMessageBox::Save:{

            QDateTime HoraFecha=QDateTime::currentDateTime();

            QString Horatran, Fechatran, observaciones, motivo;

            Horatran=HoraFecha.time().toString(Qt::ISODate);
            Fechatran=HoraFecha.date().toString(Qt::ISODate);
            observaciones=m_ui->observaciones->text();
            motivo=m_ui->motivo->text();

            int codDescargo;

            //Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);

            if(this->nuevoIngreso){
                codDescargo=servicioPersistencia->guardarDescargoBienes(Fechatran, Horatran,   observaciones,  motivo, "activofijo", m_ui->codigoDescargo->text(), this->estadoDescargo);
            }
            else{
                servicioPersistencia->actualizarDescargoBienes(this->idDescargo, observaciones,  motivo, m_ui->codigoDescargo->text(), estadoDescargo );
                codDescargo=this->idDescargo;
            }

            for
            (
               map<int, Bien*>::iterator it = listaBienes.begin();
               it != listaBienes.end();
                ++it
            ){
                 servicioPersistencia->cambiaEstadoDescargado(it->second);
                 it->second->setDescargado();
                 servicioPersistencia->crearlineaDescargoAF(it->second->oid, codDescargo );
            }

             QMessageBox msgBox;
             msgBox.information(0,"Descargo de Bienes","Descargado con exito!. ");

             for(int i=m_ui->tablaBienes->rowCount() -1; i>=0; i--)
             {
                 this->m_ui->tablaBienes->removeRow(i);
             }
             this->fila=0;
             this->m_ui->finalizarTransaccion->setDisabled(true);

             string anio=QString(m_ui->anioInventario->currentText()).toStdString() ;
             this->inventario->cargarInventario(this->registroCatalogo, this->regBasico->getUnidad()->idInventario, anio);

             NCReport *report = new NCReport();
             report->reset(true);
             report->setReportSource( NCReportSource::File  );
             report->setReportFile("Reportes/descargoBienesAF.xml");
             //NCReportParameter *par = new NCReportParameter( "idDescargo", codDescargo);
             report->addParameter( "idDescargo", QVariant(codDescargo) );
             //report->addParameter( par );

             report->runReportToPreview();
             QString error=report->lastErrorMsg();
             std::cout<< error.toStdString();

             NCReportPreviewWindow *pv = new NCReportPreviewWindow();
             pv->setReport( report );
             pv->setOutput( (NCReportPreviewOutput*) report->output() );
             pv->setWindowModality(Qt::ApplicationModal );
             pv->setAttribute( Qt::WA_DeleteOnClose );
             pv->show();
             this->close();

            }
            break;

      case QMessageBox::Cancel:{
                  QMessageBox msgBox;
                  QMessageBox::information(this,"Descargo de Bienes del Inventario","Puede continuar ingresando transacciones", QMessageBox::Ok);

            }
            break;
       default:
            break;
    }
}

void DescargoBienes::on_consultaBien_pressed()
{
    ConsultaBienes *consultaBienes=new ConsultaBienes(this->registroCatalogo, this->registroContable, this->regBasico, this->inventario);
    consultaBienes->exec();    

    int idBien=consultaBienes->getBienSeleccionado();

    consultaBienes->~ConsultaBienes();

    //servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);
    QList<QString> lista=servicioPersistencia->getDatosBien(idBien);

    m_ui->cuentaNO->setText(lista.at(0));
    this->on_cuentaNO_editingFinished();
    m_ui->claseNO->setText(lista.at(1));
    this->on_claseNO_editingFinished();
    m_ui->correlativoNO->setText(lista.at(2));
    this->on_correlativoNO_editingFinished();
}

void DescargoBienes::on_guardarTraslado_pressed()
{
    this->estadoDescargo="enproceso";
    this->descargar();
}
