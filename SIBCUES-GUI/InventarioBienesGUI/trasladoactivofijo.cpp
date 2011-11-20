#include "trasladoactivofijo.h"
#include "ui_trasladoactivofijo.h"


#include <QCompleter>
#include <QMessageBox>

TrasladoActivoFijo::TrasladoActivoFijo(RegistroCatalogo *_regCatalogo, contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, InventarioActivoFijo *_inventario, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::TrasladoActivoFijo)
{
    m_ui->setupUi(this);

     this->registroContable=regC;



    //this->registroCatalogo=_regCatalogo;
    this->registroCatalogo=new RegistroCatalogo(registroBasico->getUsuario(), regC);

    this->regBasico=registroBasico;
    this->inventario=_inventario;


    this->valorTotal=0.0;

    servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);
    servicioPersistencia->crearConexion();

    std::map<int, string> listaUnidades=servicioPersistencia->cargarNombreUnidades(this->regBasico->getUnidad()->id);

    for
    (
            map<int, string>::iterator it = listaUnidades.begin();
            it != listaUnidades.end();
                ++it
     ){
          m_ui->unidadRecibe->addItem(QString(it->second.c_str()), QVariant::QVariant(it->first));
    }


    m_ui->temporal->setChecked(true);

    QMap<int, QString> listaAnioInventa=servicioPersistencia->getInventariosFijos();

    for(QMap<int, QString>::iterator it = listaAnioInventa.begin();
        it != listaAnioInventa.end();
        ++it
    ){

            m_ui->anioInventario->addItem(QString(it.value()), QVariant::QVariant(it.key()));
    }

    QStringList labels;
        labels << tr("Cuenta") << tr("Clase") <<tr("Especifico")  << tr("Correlativo") <<  tr("Descripcion del Bien") << tr("Marca") <<  tr("Modelo") << tr("Serie") << tr("Fecha Adq.") << tr("Valor") ;
        m_ui->tablaBienes->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        m_ui->tablaBienes->setSelectionBehavior ( QAbstractItemView::SelectRows);
        m_ui->tablaBienes->setColumnCount(10);
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

        completer();

         fila=0;
}

TrasladoActivoFijo::~TrasladoActivoFijo()
{
    delete m_ui;
}


void TrasladoActivoFijo::on_anioInventario_currentIndexChanged ( ){
    string anio=QString(m_ui->anioInventario->currentText()).toStdString() ;
    this->registroCatalogo->cargarCatalogo(this->servicioPersistencia->getIDInvFijo(anio));
    this->inventario->cargarInventario(registroCatalogo,this->regBasico->getUnidad()->id, anio);
}


void TrasladoActivoFijo::changeEvent(QEvent *e)
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

void TrasladoActivoFijo::on_cancelar_pressed(){
    this->close();
}



void TrasladoActivoFijo::completer(){
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


void TrasladoActivoFijo::on_cuentaNO_editingFinished (){

    QList<QString> myQString;

    m_ui->cuentaAsignada->setText(QString::fromStdString(this->listaCodigosCuentas[m_ui->cuentaNO->text().toStdString()].c_str()  ));

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

void TrasladoActivoFijo::on_claseNO_editingFinished (){
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

void TrasladoActivoFijo::on_correlativoNO_editingFinished (){
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

void TrasladoActivoFijo::limpiar(){
    m_ui->descripcion->clear();
    m_ui->serie->clear();
    m_ui->modelo->clear();
    m_ui->marca->clear();
    m_ui->valorBien->clear();
    m_ui->cuentaAsignada->clear();
    m_ui->nombreEspecifico->clear();
    m_ui->cuentaNO->clear();
    m_ui->claseNO->clear();
    m_ui->correlativoNO->clear();

}

void TrasladoActivoFijo::on_botonAgregarBien_pressed(){

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
    m_ui->correlativoNO->clear();
    m_ui->cuentaNO->setFocus();

}


void TrasladoActivoFijo::on_botonEliminarBien_pressed(){
    if(m_ui->tablaBienes->currentItem()!=NULL)
    {
                int filaActual=m_ui->tablaBienes->currentRow();
                float valor=m_ui->tablaBienes->item(filaActual, 9)->data(0).toString().toFloat();

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


void TrasladoActivoFijo::on_finalizarTransaccion_pressed(){
    this->estadoTraslado="finalizado";
    trasladar();

}

void TrasladoActivoFijo::trasladar(){
    QMessageBox msgBox;
    msgBox.setText("Traslado de Bienes");
    msgBox.setInformativeText("¿Desea guardar y terminar la transaccion?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);

    msgBox.setDefaultButton(QMessageBox::Save);

    int ret = msgBox.exec();

    switch (ret) {
        case QMessageBox::Save:{

            QDateTime HoraFecha=QDateTime::currentDateTime();

            QString Horatran, Fechatran, observaciones, unidadRecibe, tipoTraslado;

            Horatran=HoraFecha.time().toString(Qt::ISODate);
            Fechatran=HoraFecha.date().toString(Qt::ISODate);
            observaciones=m_ui->observaciones->text();
            unidadRecibe=m_ui->unidadRecibe->currentText();


             if(m_ui->temporal->isChecked())
                 tipoTraslado="temporal";
             if(m_ui->definitivo->isChecked())
                 tipoTraslado="definitivo";




            int oidUnidadRecibe=servicioPersistencia->oidUnidad(unidadRecibe);


            int codTraslado=servicioPersistencia->guardarTrasladoBienes( oidUnidadRecibe, tipoTraslado, "activofijo", Fechatran, Horatran, observaciones, this->estadoTraslado, this->m_ui->codigoTraslado->text());

            for
            (
               map<int, Bien*>::iterator it = listaBienes.begin();
               it != listaBienes.end();
                ++it
            ){
                 servicioPersistencia->cambiaEstadoTrasladado(it->second);
                 it->second->setDescargado();
                 servicioPersistencia->crearlineaTraslado(it->second->oid, codTraslado );
            }

            QMessageBox msgBox;
            msgBox.information(0,"Traslado de Bienes","Trasladado con exito!. ");

            for(int i=m_ui->tablaBienes->rowCount() -1; i>=0; i--)
            {
                this->m_ui->tablaBienes->removeRow(i);
            }
            this->fila=0;
            this->m_ui->finalizarTransaccion->setDisabled(true);


            //CAMBIAR POR ANIO
            //this->inventario->cargarInventario(this->registroCatalogo, this->regBasico->getUnidad()->idInventario);


            NCReport *report = new NCReport();
            report->reset(true);
            report->setReportSource( NCReportSource::File  );
            report->setReportFile("Reportes/trasladoBienesAF.xml");
            report->addParameter( "idTraslado", QVariant(codTraslado) );

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

void TrasladoActivoFijo::on_consultaBien_pressed()
{
    ConsultaBienes *consultaBienes=new ConsultaBienes(this->registroCatalogo, this->registroContable, this->regBasico, this->inventario);
    consultaBienes->exec();
    int idBien=consultaBienes->getBienSeleccionado();

    //Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);

    QList<QString> lista=servicioPersistencia->getDatosBien(idBien);

    m_ui->cuentaNO->setText(lista.at(0));    
    this->on_cuentaNO_editingFinished();
    m_ui->claseNO->setText(lista.at(1));    
    this->on_claseNO_editingFinished();
    m_ui->correlativoNO->setText(lista.at(2));
    this->on_correlativoNO_editingFinished();

}



void TrasladoActivoFijo::on_guardarTraslado_pressed()
{
    this->estadoTraslado="enproceso";
    trasladar();
}
