#include "ingresobienesbiblio.h"
#include "ui_ingresobienesbiblio.h"
#include <QCompleter>
#include <QMessageBox>

#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"

IngresoBienesBiblio::IngresoBienesBiblio( RegistroCatalogo *_regCatalogo, contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, InventarioActivoFijo *_inventario, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::IngresoBienesBiblio)
{
    m_ui->setupUi(this);
    this->registroContable=regC;
    //this->registroCatalogo=_regCatalogo;
    this->registroCatalogo=new RegistroCatalogo(registroBasico->getUsuario(), regC);
        //CARGAR EL CATALOGO CON EL AÑO
    //this->registroCatalogo->cargarCatalogo();

    this->regBasico=registroBasico;
    this->inventario=_inventario;

    m_ui->finalizarTransaccion->setDisabled(true);


    m_ui->fondoGeneral->setChecked(true);


    m_ui->fechaAcuerdo->setDate(QDateTime::currentDateTime().date());
    m_ui->fechaAdquisicion->setDate(QDateTime::currentDateTime().date());
    m_ui->fechaFactura->setDate(QDateTime::currentDateTime().date());


    servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);

    QMap<int, QString> listaAnioInventa=servicioPersistencia->getInventariosBiblio();

    for(QMap<int, QString>::iterator it = listaAnioInventa.begin();
        it != listaAnioInventa.end();
        ++it
    ){

            m_ui->anioInventario->addItem(QString(it.value()), QVariant::QVariant(it.key()));
    }

    m_ui->anioInventario->setCurrentIndex(listaAnioInventa.size()-1);


    std::map<int, string> listaProveedores=servicioPersistencia->cargarProveedores();

    for
    (
            map<int, string>::iterator it = listaProveedores.begin();
            it != listaProveedores.end();
                ++it
     ){
          m_ui->nombreProveedor->addItem(QString(it->second.c_str()), QVariant::QVariant(it->first));
    }



        QStringList labels;
        labels << tr("Cuenta") << tr("Clase") <<tr("Especifico") <<  tr("Titulo") << tr("Autor") <<tr("Descripcion") << tr("ISBN")  << tr("Fecha Adq.") << tr("Valor") ;
        m_ui->tablaBienes->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
        m_ui->tablaBienes->setSelectionBehavior ( QAbstractItemView::SelectRows);
        m_ui->tablaBienes->setColumnCount(10);
        m_ui->tablaBienes->setHorizontalHeaderLabels(labels);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(0, 50);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(1, 50);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(2, 60);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(3, 260);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(4, 100);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(5, 100);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(6, 100);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(7, 80);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(8, 80);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(9, 80);

        completer();
        fila=0;
        m_ui->tablaBienes->setColumnHidden(9, true);

}

IngresoBienesBiblio::~IngresoBienesBiblio()
{
    delete m_ui;
}

void IngresoBienesBiblio::changeEvent(QEvent *e)
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

void IngresoBienesBiblio::on_anioInventario_currentIndexChanged ( ){
    string anio=QString(m_ui->anioInventario->currentText()).toStdString() ;
    this->registroCatalogo->cargarCatalogo(this->servicioPersistencia->getIDInvMB(QString::fromStdString(anio)));
    this->inventario->cargarInventario(registroCatalogo,this->regBasico->getUnidad()->id, anio);
}

void IngresoBienesBiblio::on_cancelar_pressed(){
    this->close();
}

void IngresoBienesBiblio::completer(){
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
   
    m_ui->numeroCuenta->setText(QString("12090"));
    m_ui->cuentaAsignada->setText(QString(  this->listaCodigosCuentas[m_ui->numeroCuenta->text().toStdString()].c_str()));
}

void IngresoBienesBiblio::on_nombreClase_editingFinished (){

    string nombreClase=m_ui->nombreClase->text().toStdString();
    string cuentaAsignada= m_ui->cuentaAsignada->text().toStdString();

    if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
    {
        moduloinventario::EspecificacionBien *espec=this->registroCatalogo->getEspecificacion(nombreClase , cuentaAsignada );
        m_ui->descripcion->setText(QString( espec->getDescipcion().c_str()));
        m_ui->descripcion->setReadOnly(true);
        m_ui->nombreEspecifico->setReadOnly(true);
    }else{
        m_ui->descripcion->clear();
    }
}

void IngresoBienesBiblio::limpiar(){
    m_ui->nombreClase->clear();    
    m_ui->descripcion->clear();
    m_ui->cuentaAsignada->clear();
    m_ui->nombreEspecifico->clear();
    m_ui->numeroCuenta->clear();
    m_ui->valorBien->clear();
    completer();
}


/*** DEFINIENDO OPERACIONES EN TABLA */

void IngresoBienesBiblio::on_botonAgregarBien_pressed(){


    string nombreClase=m_ui->nombreClase->text().toStdString();
    string cuentaAsignada= m_ui->cuentaAsignada->text().toStdString();
    string numCuenta=m_ui->numeroCuenta->text().toStdString();

    QString titulo=m_ui->titulo->text();
    QString isbn=m_ui->isbn->text();

    QString fechaAdqui=m_ui->fechaAdquisicion->date().toString(Qt::ISODate);
    float valor=m_ui->valorBien->value();

    if(!m_ui->cuentaAsignada->text().isEmpty() && !m_ui->nombreClase->text().isEmpty() && !m_ui->nombreEspecifico->text().isEmpty()){

        m_ui->finalizarTransaccion->setEnabled(true);

        if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
         {
            m_ui->botonEliminarBien->setEnabled(true);
            columna=0;
            m_ui->tablaBienes->insertRow(fila);

            QTableWidgetItem *newCuenta = new QTableWidgetItem(QString(numCuenta.c_str()));

            /*if(fila%2!=0)
                newCuenta->setBackground( QBrush::QBrush (QColor(211, 239, 255, 127) ));*/

            m_ui->tablaBienes->setItem(fila, columna, newCuenta);

            columna++;

            QTableWidgetItem *newClase = new QTableWidgetItem(QString(nombreClase.c_str()));            
            m_ui->tablaBienes->setItem(fila, columna, newClase);


            moduloinventario::EspecificacionBien *espec=this->registroCatalogo->getEspecificacion(nombreClase , cuentaAsignada );

            columna++;

            QTableWidgetItem *newEspecifico = new QTableWidgetItem(m_ui->numEspecifico->text());
            m_ui->tablaBienes->setItem(fila, columna, newEspecifico);

            columna++;

            QTableWidgetItem *newTitulo = new QTableWidgetItem(titulo);

            m_ui->tablaBienes->setItem(fila, columna, newTitulo);

            columna++;

            QTableWidgetItem *newAutor = new QTableWidgetItem("");

            m_ui->tablaBienes->setItem(fila, columna, newAutor);

            columna++;

            QTableWidgetItem *newDescripcion = new QTableWidgetItem(QString(espec->descripcion.c_str()));

            m_ui->tablaBienes->setItem(fila, columna, newDescripcion);

            columna++;

            QTableWidgetItem *newISBN = new QTableWidgetItem(isbn);

            m_ui->tablaBienes->setItem(fila, columna, newISBN);

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
    }
}

void IngresoBienesBiblio::on_botonEliminarBien_pressed(){

    if(m_ui->tablaBienes->currentItem()!=NULL)
    {
                int filaActual=m_ui->tablaBienes->currentRow();
                float valor=m_ui->tablaBienes->item(filaActual, 8)->data(0).toString().toFloat();
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

void IngresoBienesBiblio::on_nuevoBien_pressed(){
    limpiar();
}


void IngresoBienesBiblio::on_finalizarTransaccion_pressed(){

    QMessageBox msgBox;
    msgBox.setText("Ingreso de Transacciones.");
    msgBox.setInformativeText("¿Desea guardar y terminar la transaccion?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec(), codigoIngreso=0;

    switch (ret) {
        case QMessageBox::Save:{

                QDateTime HoraFecha=QDateTime::currentDateTime();

                Fecha *_fechaTran=new Fecha(HoraFecha.date().day(), HoraFecha.date().month(), HoraFecha.date().year());

                /*Variables del bien*/
                string nombreClase, cuentaAsignada;
                float valor=0.0;
                Fecha *fechaAdquisicion;
                QString fechaAq, especifico;
                QDate fAdquisicion;

                /**Variables Generales*/
                QString facturaProveedor, noCEF, fechaFactura, noCSU, fechaCSU, proveedor, numeroIngreso;
                QString fuentedeFondos, observaciones, tipoBien, Horatran, Fechatran, titulo, isbn;

                int inventarioMB=QVariant(m_ui->anioInventario->itemData(m_ui->anioInventario->currentIndex())).toInt();
                numeroIngreso=m_ui->numeroIngreso->text();
                facturaProveedor=m_ui->noFactura->text();
                noCEF=m_ui->CEF->text();
                fechaFactura=m_ui->fechaFactura->date().toString(Qt::ISODate);
                noCSU=m_ui->numeroAcuerdoCSU->text();
                fechaCSU=m_ui->fechaAcuerdo->date().toString(Qt::ISODate);
                proveedor=m_ui->nombreProveedor->currentText();
                observaciones=m_ui->observaciones->text();
                tipoBien=QString("matbibliografico");
                Horatran=HoraFecha.time().toString(Qt::ISODate);
                Fechatran=HoraFecha.date().toString(Qt::ISODate);


                if(m_ui->fondoGeneral->isChecked())
                    fuentedeFondos="fondogeneral";
                if(m_ui->fondosPropios->isChecked())
                    fuentedeFondos="fondospropios";
                 if(m_ui->fondosPropios->isChecked())
                    fuentedeFondos="donado";


                QString estadoIngreso="finalizado";


                codigoIngreso=servicioPersistencia->guardarIngresoBienes(Fechatran, proveedor, noCEF, facturaProveedor, fechaFactura, noCSU , fechaCSU, fuentedeFondos, observaciones, tipoBien, Horatran, estadoIngreso, numeroIngreso );

                /**Objeto Bien*/
                //Bien *bien;
                int codBien;


                for(int i=0; i< m_ui->tablaBienes->rowCount(); i++)
                {
                    QString codCuenta=m_ui->tablaBienes->item(i, 0)->data(0).toString();
                    cuentaAsignada=QString(this->listaCodigosCuentas[m_ui->tablaBienes->item(i, 0)->data(0).toString().toStdString()].c_str() ).toStdString();
                    nombreClase=m_ui->tablaBienes->item(i, 1)->data(0).toString().toStdString();
                    especifico=m_ui->tablaBienes->item(i, 2)->data(0).toString();
                    titulo=m_ui->tablaBienes->item(i, 3)->data(0).toString();

                    isbn=m_ui->tablaBienes->item(i, 6)->data(0).toString();
                    fechaAq=m_ui->tablaBienes->item(i, 7)->data(0).toString();
                    valor=m_ui->tablaBienes->item(i, 8)->data(0).toString().toFloat();                    

                    QString correlativo, codigoBien;
                    QString codigUnidad=QString::fromStdString(this->regBasico->getUnidad()->codigoP1())+QString::fromStdString(this->regBasico->getUnidad()->codigoP2());;

                    //fAdquisicion=m_ui->tablaBienes->item(i, 7)->data(0).toDate();
                    //fechaAdquisicion=new Fecha(fAdquisicion.day(), fAdquisicion.month(), fAdquisicion.year() );

                    cout << "asignada" << cuentaAsignada;

                    if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
                    {
                        moduloinventario::EspecificacionBien *espec=this->registroCatalogo->getEspecificacion(nombreClase , cuentaAsignada );
                        //bien=this->inventario->crearBien(fechaAdquisicion, espec, valor, 1, true);
                        //bien->estadoBien=1;

                        cout << "paso aki" ;


                        /*if(m_ui->tablaBienes->item(i, 9)->data(0).toInt()==0){

                        }*/

                        servicioPersistencia->getIDInvMB(m_ui->anioInventario->currentText());

                        QList<QString> listaCorrelativos=servicioPersistencia->getListaCorelativosDisponiblesMB(espec->oid_especbien);
                        //bien->correlativo=listaCorrelativos.takeFirst().toStdString();
                        correlativo=listaCorrelativos.takeFirst();

                        codigoBien=codCuenta+"-"+codigUnidad+"-"+QString::fromStdString(nombreClase)+"-"+correlativo+"-"+especifico;
                        codBien=servicioPersistencia->guardarBien(espec, correlativo,  valor, fechaAq, titulo, isbn, especifico,codigoBien );
                        servicioPersistencia->crearlineaIngresoMB(codBien, codigoIngreso );

                        //bien->oid=codBien;
                        //cout <<  "El oid " <<bien->oid;

                        //bien->idTitulo=servicioPersistencia->oidTitulo(titulo, isbn);
                        //bien->idAutor=servicioPersistencia->oidTituloAutor(titulo, isbn);
                    }
                }

                  QMessageBox msgBox;
                  msgBox.information(0,"Captura de Datos","    Ingresado con exito!.   ");

                  for(int i=m_ui->tablaBienes->rowCount() -1; i>=0; i--)
                  {
                      this->m_ui->tablaBienes->removeRow(i);
                  }
                  this->fila=0;
                  this->m_ui->finalizarTransaccion->setDisabled(true);

                     NCReport *report = new NCReport();
                     report->reset(true);
                     report->setReportSource( NCReportSource::File  );
                     report->setReportFile("Reportes/ingresoBienesBiblio.xml");

                     report->addParameter( "idIngreso", QVariant(codigoIngreso) );

                     //NCReportParameter *par = new NCReportParameter( "idIngreso", codigoIngreso);
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
            }
            break;

      case QMessageBox::Cancel:{
                  QMessageBox msgBox;
                  msgBox.setText("    Puede continuar ingresando transacciones   ");
                  msgBox.exec();

            }
            break;
       default:
            break;
    }
}


void IngresoBienesBiblio::on_buscarCuentaInventario_clicked()
{
    CatalogoActivoFijoGUI *catalogoAF=new CatalogoActivoFijoGUI (this->registroCatalogo, this->registroContable, this->regBasico);
    catalogoAF->show();
    catalogoAF->exec();

    if(this->registroContable->getDireccionCuenta(catalogoAF->getMadre().toStdString())!=NULL){
        m_ui->numeroCuenta->setText(QString::fromStdString(this->registroContable->getDireccionCuenta(catalogoAF->getMadre().toStdString())->getcodigoCuenta()));
        m_ui->nombreClase->setText(catalogoAF->getClase());
    }
}

void IngresoBienesBiblio::on_buscarEspecifico_clicked()
{
    Fecha *fech=new Fecha(5, 10, 2009);
    this->regEspecificos=new RegistroSistemaContable(this->regBasico);
    regEspecificos->crearPeriodoContable(*fech, *fech);
    /*Revisar*/
    regEspecificos->crearCatalogo(*fech, true, false);

    CatalogoContable *catalogoEs=new CatalogoContable(this->regEspecificos);
    catalogoEs->exec();

    m_ui->numEspecifico->setText(catalogoEs->getCodigoCuenta());
    m_ui->nombreEspecifico->setText(catalogoEs->getNombreCuenta());
}

void IngresoBienesBiblio::on_buscarTitulo_clicked()
{
    mantenimientoTitulo *dialogoTitulo=new mantenimientoTitulo(this->regBasico->getUnidad()->id);
    dialogoTitulo->exec();

    m_ui->titulo->setText(dialogoTitulo->getTitulo());
    m_ui->isbn->setText(dialogoTitulo->getISBN());
}
