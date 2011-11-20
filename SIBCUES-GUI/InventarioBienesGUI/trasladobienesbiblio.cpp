#include "trasladobienesbiblio.h"
#include "ui_trasladobienesbiblio.h"

#include <QCompleter>
#include <QMessageBox>



TrasladoBienesBiblio::TrasladoBienesBiblio(RegistroCatalogo *_regCatalogo, contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, InventarioActivoFijo *_inventario, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::TrasladoBienesBiblio)
{
    m_ui->setupUi(this);

     this->registroContable=regC;
    //this->registroCatalogo=_regCatalogo;
    this->registroCatalogo=new RegistroCatalogo(registroBasico->getUsuario(), regC);
        //CARGAR EL CATALOGO CON EL AÑO
    //this->registroCatalogo->cargarCatalogo();

    this->regBasico=registroBasico;
    this->inventario=_inventario;
    this->valorTotal=0.0;

    servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);
    std::map<int, string> listaUnidades=servicioPersistencia->cargarNombreUnidades(this->regBasico->getUnidad()->id);


    for
    (
            map<int, string>::iterator it = listaUnidades.begin();
            it != listaUnidades.end();
                ++it
     ){
          m_ui->unidadRecibe->addItem(QString(it->second.c_str()), QVariant::QVariant(it->first));
    }


    QMap<int, QString> listaAnioInventa=servicioPersistencia->getInventariosBiblio();

    for(QMap<int, QString>::iterator it = listaAnioInventa.begin();
        it != listaAnioInventa.end();
        ++it
    ){

            m_ui->anioInventario->addItem(QString(it.value()), QVariant::QVariant(it.key()));
    }

     m_ui->nombreDpto->setText(QString(this->regBasico->getNombreUnidad().c_str()));
    QString codP1=QString(this->regBasico->codigoUnidadP1().c_str());
    QString codP2=QString(this->regBasico->codigoUnidadP2().c_str());
    m_ui->nombreUnidad->setText(codP1+ " "+ codP2);

    m_ui->temporal->setChecked(true);

      QStringList labels;
        labels << tr("Cuenta") << tr("Clase") <<tr("Especifico")  << tr("Correlativo") <<  tr("Titulo") << tr("Descipcion") <<  tr("Autor") << tr("ISBN") << tr("Fecha Adq.") << tr("Valor") ;
        m_ui->tablaBienes->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
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

TrasladoBienesBiblio::~TrasladoBienesBiblio()
{
    delete m_ui;
}

void TrasladoBienesBiblio::changeEvent(QEvent *e)
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

void TrasladoBienesBiblio::on_cancelar_pressed(){
    this->close();
}



void TrasladoBienesBiblio::completer(){

    listaCodigosCuentas=this->registroContable->getHijosCatalogo();


    m_ui->cuentaNO->setText("12090");

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




void TrasladoBienesBiblio::on_claseNO_editingFinished (){
    //QString nombreClase=m_ui->claseNO->text().toStdString();
    QString clase=m_ui->claseNO->text();

    QMap<QString, QString> bienes;
    bienes=this->servicioPersistencia->getListaBienesInvBiblio(anioInvSelecc, clase);

    QList<QString> myCorrelativos;
    QString correlativo;

    for(QMap<QString, QString>::iterator it = bienes.begin();
        it != bienes.end();
        ++it
    ){
            correlativo=it.value();
            if(clase == correlativo)
                myCorrelativos.push_back(it.key());

            //cout << correlativo.toStdString();
    }

    QCompleter *completer2 = new QCompleter(myCorrelativos, this);
    completer2->setCaseSensitivity(Qt::CaseInsensitive);
    m_ui->correlativoNO->setCompleter(completer2);
}

void TrasladoBienesBiblio::on_correlativoNO_editingFinished (){
    QString nombreClase=m_ui->claseNO->text();
    QString cuentaAsignada=m_ui->cuentaAsignada->text();
    QString correlativo=m_ui->correlativoNO->text();
    QString titulo, nombreAutor, isbn;

    Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);

    Bien *bien=servicioPersistencia->getBienMB(this->anioInvSelecc, cuentaAsignada, correlativo, nombreClase);

    if(bien!=NULL){
        m_ui->valorBien->setValue(bien->getValor());
        m_ui->descripcion->setText(QString::fromStdString(bien->getDescripcionClase()));

        titulo=servicioPersistencia->getTitulo(bien->idTitulo);
        nombreAutor=servicioPersistencia->getAutor(bien->idTitulo);

        isbn=servicioPersistencia->getISBN(bien->idTitulo, bien->idAutor);

        m_ui->titulo->setText(titulo);
        m_ui->nombreAutor->setText(nombreAutor);

        m_ui->isbn->setText(isbn);
        m_ui->especificoNO->setText(QString::fromStdString(bien->getEspecifico()));
        m_ui->fechaAquisicion->setDate(QDate::QDate(bien->fechaAdquisicion->getAnio(), bien->fechaAdquisicion->getMes(), bien->fechaAdquisicion->getDia()));
        m_ui->nombreEspecifico->setText(QString::fromStdString(bien->getNombreEspecifico()));

    }else{
        limpiar();
    }

}

void TrasladoBienesBiblio::limpiar(){
    m_ui->descripcion->clear();
    m_ui->valorBien->clear();

}


void TrasladoBienesBiblio::on_botonAgregarBien_pressed(){

    string nombreClase=m_ui->claseNO->text().toStdString();
    string cuentaAsignada= m_ui->cuentaAsignada->text().toStdString();
    string numCuenta=m_ui->cuentaNO->text().toStdString();

    string correlativo=m_ui->correlativoNO->text().toStdString();
    QString fechaAdqui=m_ui->fechaAquisicion->date().toString(Qt::ISODate);
    float valor=m_ui->valorBien->value();
    Bien *bien;
    bool existe=false;

    if(!m_ui->cuentaAsignada->text().isEmpty() && !m_ui->claseNO->text().isEmpty() && !m_ui->nombreEspecifico->text().isEmpty()){

        m_ui->finalizarTransaccion->setEnabled(true);

            bien=servicioPersistencia->getBienMB(this->anioInvSelecc, QString::fromStdString(cuentaAsignada), QString::fromStdString(correlativo), QString::fromStdString(nombreClase));

            for
            (
               map<int, Bien*>::iterator it = listaBienes.begin();
               it != listaBienes.end();
                ++it
            ){
                if( (it->second->getOID() ==bien->getOID() )){
                        existe=true;
                }
            }

                if(!existe){


                    m_ui->botonEliminarBien->setEnabled(true);
                    columna=0;
                    m_ui->tablaBienes->insertRow(fila);
                    this->listaBienes[bien->oid]=bien;

                    QTableWidgetItem *newCuenta = new QTableWidgetItem(QString(numCuenta.c_str()));

                    m_ui->tablaBienes->setItem(fila, columna, newCuenta);

                    columna++;

                    QTableWidgetItem *newClase = new QTableWidgetItem(QString(nombreClase.c_str()));

                    m_ui->tablaBienes->setItem(fila, columna, newClase);

                    columna++;

                    QTableWidgetItem *newEspecifico = new QTableWidgetItem(m_ui->especificoNO->text());
                    m_ui->tablaBienes->setItem(fila, columna, newEspecifico);

                    columna++;

                    QTableWidgetItem *newCorrelativo = new QTableWidgetItem(m_ui->correlativoNO->text());

                    m_ui->tablaBienes->setItem(fila, columna, newCorrelativo);

                    columna++;

                    QTableWidgetItem *newtTitulo = new QTableWidgetItem(m_ui->titulo->text());

                    m_ui->tablaBienes->setItem(fila, columna, newtTitulo);


                    columna++;


                    QTableWidgetItem *newDescripcion = new QTableWidgetItem(m_ui->descripcion->text());

                    m_ui->tablaBienes->setItem(fila, columna, newDescripcion);


                    columna++;

                    QTableWidgetItem *newAutor = new QTableWidgetItem(m_ui->nombreAutor->text());

                    m_ui->tablaBienes->setItem(fila, columna, newAutor);

                    columna++;

                    QTableWidgetItem *newISBN = new QTableWidgetItem(m_ui->isbn->text());

                    m_ui->tablaBienes->setItem(fila, columna, newISBN );

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

        this->limpiar();
        m_ui->correlativoNO->clear();
        m_ui->correlativoNO->setFocus();

}


void TrasladoBienesBiblio::on_botonEliminarBien_pressed(){
    if(m_ui->tablaBienes->currentItem()!=NULL)
    {
                int filaActual=m_ui->tablaBienes->currentRow();
                float valor=m_ui->tablaBienes->item(filaActual, 9)->data(0).toString().toFloat();

                string nombreClase=m_ui->tablaBienes->item(filaActual, 1)->data(0).toString().toStdString();
                string cuentaAsignada=this->listaCodigosCuentas[m_ui->tablaBienes->item(filaActual, 0)->data(0).toString().toStdString()];
                string correlativo=m_ui->tablaBienes->item(filaActual, 3)->data(0).toString().toStdString();

                Bien *bien=servicioPersistencia->getBienMB(this->anioInvSelecc, QString::fromStdString(cuentaAsignada), QString::fromStdString(correlativo), QString::fromStdString(nombreClase));
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

void TrasladoBienesBiblio::on_anioInventario_currentIndexChanged(QString anio )
{
    anioInvSelecc=anio;

}


void TrasladoBienesBiblio::on_finalizarTransaccion_pressed(){
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


            Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);
            int oidUnidadRecibe=servicioPersistencia->oidUnidad(unidadRecibe);


            this->estadoTraslado="finalizado";

            int codTraslado=servicioPersistencia->guardarTrasladoBienes( oidUnidadRecibe, tipoTraslado, "matbibliografico", Fechatran, Horatran, observaciones, this->estadoTraslado, this->m_ui->codigoTraslado->text());


            for
            (
               map<int, Bien*>::iterator it = listaBienes.begin();
               it != listaBienes.end();
                ++it
            ){
                 servicioPersistencia->cambiaEstadoTrasladadoMB(it->second);
                 //it->second->setDescargadoMB();
                 servicioPersistencia->crearlineaTrasladoMB( it->second->oid, codTraslado );

                 //servicioPersistencia->cambiaEstadoDescargadoMB(it->second);
                 //it->second->setDescargadoMB();
                 //servicioPersistencia->crearlineaDescargoMB(it->second->oid, codDescargo);
            }

                  QMessageBox msgBox;
                  msgBox.information(0,"Traslado de Bienes","Trasladado con exito!. ");

                  for(int i=m_ui->tablaBienes->rowCount() -1; i>=0; i--)
                  {
                      this->m_ui->tablaBienes->removeRow(i);
                  }
                  this->fila=0;
                  this->m_ui->finalizarTransaccion->setDisabled(true);
              //CARGAR EL INVENTARIO
                //this->inventario->cargarInventario(this->registroCatalogo, this->regBasico->getUnidad()->idInventario);

                servicioPersistencia->crearConexion();

                     NCReport *report = new NCReport();
                     report->reset(true);
                     report->setReportSource( NCReportSource::File  );
                     report->setReportFile("Reportes/trasladoBienesBiblio.xml");
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

