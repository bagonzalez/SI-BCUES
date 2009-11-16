#include <QCompleter>
#include <QStringList>
#include <QMessageBox>
#include "ingresobienes.h"
#include "ui_ingresobienes.h"


#include "../../Persistencia/persistencia_global.h"
#include "../../Persistencia/persistencia.h"


ingresoBienes::ingresoBienes( RegistroCatalogo *_regCatalogo, contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, InventarioActivoFijo *_inventario, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::ingresoBienes)
{
    m_ui->setupUi(this);

    this->registroContable=regC;
    this->registroCatalogo=_regCatalogo;
    this->regBasico=registroBasico;
    this->inventario=_inventario;
    this->valorTotal=0.0;

    m_ui->nombreDpto->setText(QString(this->regBasico->getNombreUnidad().c_str()));
    QString codP1=QString(this->regBasico->codigoUnidadP1().c_str());
    QString codP2=QString(this->regBasico->codigoUnidadP2().c_str());
    m_ui->nombreUnidad->setText(codP1+ " "+ codP2);


    Persistencia::Persistencia *servicioPersistencia=new Persistencia();
    std::map<int, string> listaSectores=servicioPersistencia->cargarSectores();


    for
    (
            map<int, string>::iterator it = listaSectores.begin();
            it != listaSectores.end();
                ++it
     ){
          m_ui->sectorDestino->addItem(QString(it->second.c_str()), QVariant::QVariant(it->first));
    }

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
        labels << tr("Cuenta") << tr("Clase") <<tr("Especifico") <<  tr("Descripcion del Bien") << tr("Marca") <<  tr("Modelo") << tr("Serie") << tr("Fecha Adq.") << tr("Valor") ;
        m_ui->tablaBienes->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
        m_ui->tablaBienes->setSelectionBehavior ( QAbstractItemView::SelectRows);
        m_ui->tablaBienes->setColumnCount(9);
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

        completer();

        fila=0;

}

ingresoBienes::~ingresoBienes()
{
    delete m_ui;
}

void ingresoBienes::changeEvent(QEvent *e)
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


void ingresoBienes::completer(){
    QList<QString> myQString;

    listaCodigosCuentas=this->registroContable->getHijosCuentaCodigos("Inventario");
    myQString.clear();

    for
    (
            map<int, string>::iterator it = listaCodigosCuentas.begin();
            it != listaCodigosCuentas.end();
                ++it
     ){
          if(it->first!=12090)
           myQString.push_back(QString(QVariant::QVariant(it->first).toString()));
    }

    QCompleter *completer2 = new QCompleter(myQString, this);
    completer2->setCaseSensitivity(Qt::CaseInsensitive);
    m_ui->numeroCuenta->setCompleter(completer2);
}


void ingresoBienes::on_numeroCuenta_editingFinished (){
    m_ui->cuentaAsignada->setText(QString(  this->listaCodigosCuentas[m_ui->numeroCuenta->text().toInt()].c_str()  ));
}



void ingresoBienes::on_nombreClase_editingFinished (){

    string nombreClase=m_ui->nombreClase->text().toStdString();
    string cuentaAsignada= m_ui->cuentaAsignada->text().toStdString();

    if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
    {
        moduloinventario::EspecActivoFijo *espec=this->registroCatalogo->getEspecificacion(nombreClase , cuentaAsignada );
        m_ui->descripcion->setText(QString( espec->getDescipcion().c_str()));
        m_ui->descripcion->setReadOnly(true);
        m_ui->nombreEspecifico->setText(QString::number(espec->clase->idEspecifico->codigoCuenta)+" "+QString( espec->clase->idEspecifico->nombreCuenta.c_str() ));
        m_ui->nombreEspecifico->setReadOnly(true);

        QList<string> lista=QList<string>::fromStdList(espec->getMarcas());
        m_ui->marca->clear();
        for (int i = 0; i < lista.size(); ++i){
            m_ui->marca->addItem(QString(lista.at(i).c_str()), QVariant::QVariant(i));
        }
    }
}


void ingresoBienes::on_marca_currentIndexChanged (){

    string _marca=QString(m_ui->marca->currentText()).toStdString() ;
    QList<string> lista=QList<string>::fromStdList( this->registroCatalogo->getModelos(_marca));
    QList<QString> myQString;
    m_ui->modelo->clear();

    for (int i = 0; i < lista.size(); ++i){
         m_ui->modelo->addItem(QString(lista.at(i).c_str()), QVariant::QVariant(i));
    }
}

void ingresoBienes::limpiar(){    
    m_ui->nombreClase->clear();
    m_ui->numeroAcuerdoCSU->clear();
    m_ui->descripcion->clear();    
    m_ui->marca->clear();
    m_ui->modelo->clear();
    m_ui->cuentaAsignada->clear();
    m_ui->serie->clear();
    m_ui->nombreEspecifico->clear();
    m_ui->numeroCuenta->clear();
    m_ui->CEF->clear();
    m_ui->valorBien->clear();
    completer();
}



/*** DEFINIENDO OPERACIONES EN TABLA */

void ingresoBienes::on_botonAgregarBien_pressed(){

    string nombreClase=m_ui->nombreClase->text().toStdString();
    string cuentaAsignada= m_ui->cuentaAsignada->text().toStdString();
    string numCuenta=m_ui->numeroCuenta->text().toStdString();
    string marca=m_ui->marca->currentText().toStdString();
    string modelo=m_ui->modelo->currentText().toStdString();
    string serie=m_ui->serie->text().toStdString();
    QString fechaAdqui=m_ui->fechaAdquisicion->date().toString(Qt::ISODate);
    float valor=m_ui->valorBien->value();

    if(!m_ui->cuentaAsignada->text().isEmpty() && !m_ui->nombreClase->text().isEmpty() && !m_ui->nombreEspecifico->text().isEmpty()){

        if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
         {
            m_ui->botonEliminarBien->setEnabled(true);
            columna=0;
            m_ui->tablaBienes->insertRow(fila);

            QTableWidgetItem *newCuenta = new QTableWidgetItem(QString(numCuenta.c_str()));
            if(fila%2!=0)
                newCuenta->setBackground( QBrush::QBrush (QColor(211, 239, 255, 127) ));
            m_ui->tablaBienes->setItem(fila, columna, newCuenta);

            columna++;

            QTableWidgetItem *newClase = new QTableWidgetItem(QString(nombreClase.c_str()));
            if(fila%2!=0)
                newClase->setBackground( QBrush::QBrush (QColor(211, 239, 255, 127) ));
            m_ui->tablaBienes->setItem(fila, columna, newClase);


            moduloinventario::EspecActivoFijo *espec=this->registroCatalogo->getEspecificacion(nombreClase , cuentaAsignada );

            columna++;

            QTableWidgetItem *newEspecifico = new QTableWidgetItem(QString::number(espec->clase->idEspecifico->codigoCuenta));
            if(fila%2!=0)
                newEspecifico->setBackground( QBrush::QBrush (QColor(211, 239, 255, 127)));
            m_ui->tablaBienes->setItem(fila, columna, newEspecifico);

            columna++;

            QTableWidgetItem *newDescripcion = new QTableWidgetItem(QString(espec->descripcion.c_str()));
            if(fila%2!=0)
                newDescripcion->setBackground( QBrush::QBrush (QColor(211, 239, 255, 127) ));
            m_ui->tablaBienes->setItem(fila, columna, newDescripcion);

            columna++;

            QTableWidgetItem *newMarca = new QTableWidgetItem(QString(marca.c_str()));
            if(fila%2!=0)
                newMarca->setBackground( QBrush::QBrush (QColor(211, 239, 255, 127) ));
            m_ui->tablaBienes->setItem(fila, columna, newMarca);

            columna++;

            QTableWidgetItem *newModelo = new QTableWidgetItem(QString(modelo.c_str()));
            if(fila%2!=0)
                newModelo->setBackground( QBrush::QBrush (QColor(211, 239, 255, 127) ));
            m_ui->tablaBienes->setItem(fila, columna, newModelo);

            columna++;

            QTableWidgetItem *newSerie = new QTableWidgetItem(QString(serie.c_str()));
            if(fila%2!=0)
                newSerie->setBackground( QBrush::QBrush (QColor(211, 239, 255, 127) ));
            m_ui->tablaBienes->setItem(fila, columna, newSerie );

            columna++;

            QTableWidgetItem *newFechaAdq = new QTableWidgetItem(fechaAdqui);
            if(fila%2!=0)
                newFechaAdq->setBackground( QBrush::QBrush (QColor(211, 239, 255, 127) ));
            m_ui->tablaBienes->setItem(fila, columna, newFechaAdq );

            columna++;

            QTableWidgetItem *newValorBien= new QTableWidgetItem(QString::number(valor));
            if(fila%2!=0)
                newValorBien->setBackground( QBrush::QBrush (QColor(211, 239, 255, 127) ));
            m_ui->tablaBienes->setItem(fila, columna, newValorBien );

            this->valorTotal=this->valorTotal+valor;
            m_ui->totalIngreso->setText(QString("$ %1").arg(this->valorTotal, 0, 'f', 2));
            fila++;
        }
    }

}

void ingresoBienes::on_botonEliminarBien_pressed(){

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

void ingresoBienes::on_nuevoBien_pressed(){
    limpiar();
}


void ingresoBienes::on_finalizarTransaccion_pressed(){

    QMessageBox msgBox;
    msgBox.setText("Ingreso de Transacciones.");
    msgBox.setInformativeText("¿Desea guardar y terminar la transaccion?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret) {
        case QMessageBox::Save:{

                QDateTime HoraFecha=QDateTime::currentDateTime();

                Fecha *_fechaTran=new Fecha(HoraFecha.date().day(), HoraFecha.date().month(), HoraFecha.date().year());

                /*Variables del bien*/
                string nombreClase, cuentaAsignada;
                float valor=0.0;                
                Fecha *fechaAdquisicion;
                QString fechaAq;
                QDate fAdquisicion;

                /**Variables Generales*/
                QString facturaProveedor, noCEF, fechaFactura, noCSU, fechaCSU, proveedor;
                QString fuentedeFondos, observaciones, tipoBien, Horatran, Fechatran, serie, marca, modelo;

                facturaProveedor=m_ui->noFactura->text();
                noCEF=m_ui->CEF->text();
                fechaFactura=m_ui->fechaFactura->date().toString(Qt::ISODate);
                noCSU=m_ui->numeroAcuerdoCSU->text();
                fechaCSU=m_ui->fechaAcuerdo->date().toString(Qt::ISODate);
                proveedor=m_ui->nombreProveedor->currentText();
                observaciones=m_ui->observaciones->text();
                tipoBien=QString("activofijo");
                Horatran=HoraFecha.time().toString(Qt::ISODate);
                Fechatran=HoraFecha.date().toString(Qt::ISODate);


                int sector=m_ui->sectorDestino->currentIndex();


                if(m_ui->fondoGeneral->isChecked())
                    fuentedeFondos="fondogeneral";
                if(m_ui->fondosPropios->isChecked())
                    fuentedeFondos="fondospropios";
                 if(m_ui->fondosPropios->isChecked())
                    fuentedeFondos="donado";

                Persistencia::Persistencia *servicioPersistencia=new Persistencia();
                int codigoIngreso=servicioPersistencia->guardarIngresoBienes(Fechatran, proveedor, noCEF, facturaProveedor, fechaFactura, noCSU , fechaCSU, fuentedeFondos, observaciones, tipoBien, Horatran);


                /**Objeto Bien*/
                Bien *bien;
                int codBien;


                for(int i=0; i< m_ui->tablaBienes->rowCount(); i++)
                {

                    cuentaAsignada=QString(this->listaCodigosCuentas[m_ui->tablaBienes->item(i, 0)->data(0).toInt()].c_str() ).toStdString();              
                    nombreClase=m_ui->tablaBienes->item(i, 1)->data(0).toString().toStdString();
                    valor=m_ui->tablaBienes->item(i, 8)->data(0).toString().toFloat();

                    fechaAq=m_ui->tablaBienes->item(i, 7)->data(0).toString();
                    fAdquisicion=m_ui->tablaBienes->item(i, 7)->data(0).toDate();
                    fechaAdquisicion=new Fecha(fAdquisicion.day(), fAdquisicion.month(), fAdquisicion.year() );
                    marca=m_ui->tablaBienes->item(i, 4)->data(0).toString();
                    modelo=m_ui->tablaBienes->item(i, 5)->data(0).toString();
                    serie=m_ui->tablaBienes->item(i, 6)->data(0).toString();
                    if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
                    {
                        moduloinventario::EspecActivoFijo *espec=this->registroCatalogo->getEspecificacion(nombreClase , cuentaAsignada );
                        bien=this->inventario->crearBien(espec, valor, fechaAdquisicion);
                        bien->setSerie(serie.toStdString());
                        bien->setSector(sector);
                        codBien=servicioPersistencia->guardarBien(espec, QString(bien->correlativo.c_str()), serie, valor, fechaAq, sector, modelo);
                        servicioPersistencia->crearlineaIngreso(codBien, codigoIngreso, espec );
                        bien->oid=codBien;
                        bien->idModelo=servicioPersistencia->oidModelo(modelo);
                    }
                }

                  QMessageBox msgBox;
                  msgBox.information(0,"Captura de Datos","    Ingresado con exito!.   ");                  

                  //for(int i=ui.asientosContables->rowCount() -1; i>=0; i--)
                  //{
                    //  this->ui.asientosContables->removeRow(i);
                  //}
                  //this->fila=0;
                  //this->ui.finalizar->setDisabled(true);
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





