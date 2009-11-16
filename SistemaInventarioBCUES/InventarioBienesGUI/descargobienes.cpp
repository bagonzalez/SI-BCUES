#include "descargobienes.h"
#include "ui_descargobienes.h"

#include "../../Persistencia/persistencia_global.h"
#include "../../Persistencia/persistencia.h"

#include <QCompleter>
#include <QMessageBox>

DescargoBienes::DescargoBienes(RegistroCatalogo *_regCatalogo, contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, InventarioActivoFijo *_inventario, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::DescargoBienes)
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

    QStringList labels;
        labels << tr("Cuenta") << tr("Clase") <<tr("Especifico")  << tr("Correlativo") <<  tr("Descripcion del Bien") << tr("Marca") <<  tr("Modelo") << tr("Serie") << tr("Fecha Adq.") << tr("Valor") ;
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



void DescargoBienes::completer(){
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
    m_ui->cuentaNO->setCompleter(completer2);
}


void DescargoBienes::on_cuentaNO_editingFinished (){

    QList<QString> myQString;

    m_ui->cuentaAsignada->setText(QString(  this->listaCodigosCuentas[m_ui->cuentaNO->text().toInt()].c_str()  ));

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
    m_ui->nombreEspecifico->setText(QString::QString(this->registroCatalogo->getClase(nombreClase, cuentaAsignada)->idEspecifico->nombreCuenta.c_str()));
    m_ui->especificoNO->setText(QString::number(this->registroCatalogo->getClase(nombreClase, cuentaAsignada)->idEspecifico->getcodigoCuenta()));

    QList<QString> myQString;

    list<string> listaCorrelativos=this->inventario->getCorrelativos(nombreClase, cuentaAsignada);

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

void DescargoBienes::on_correlativoNO_editingFinished (){
    string nombreClase=m_ui->claseNO->text().toStdString();
    string cuentaAsignada=m_ui->cuentaAsignada->text().toStdString();
    string correlativo=m_ui->correlativoNO->text().toStdString();
    string marca, modelo;


    Bien *bien=this->inventario->getBien(nombreClase, cuentaAsignada, correlativo);

    if(bien!=NULL){
        m_ui->valorBien->setValue(bien->getValor());
        m_ui->descripcion->setText(QString::QString(bien->getEspecAF()->getDescipcion().c_str()));
        m_ui->serie->setText(QString::QString(bien->getSerie().c_str()));

        Persistencia::Persistencia *servicioPersistencia=new Persistencia();
        modelo=servicioPersistencia->getModelo(bien->idModelo);
        marca=servicioPersistencia->getMarca(bien->idModelo);
        m_ui->modelo->setText(QString::QString(modelo.c_str()));
        m_ui->marca->setText(QString::QString(marca.c_str()));        
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

        if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
         {
            bien=this->inventario->getBien(nombreClase, cuentaAsignada, correlativo);

            for
            (
                list<Bien*>::iterator from = this->listaBienes.begin();
                from != this->listaBienes.end();
                ++from
            ){

               if( ((*from)->getEspecAF()->getClase()->getCuentaAsignada())==cuentaAsignada && ((*from)->getEspecAF()->getClase()->getNombreClase()) == nombreClase ){
                    if((*from)->correlativo==correlativo)
                        existe=true;
                }
            }

            if(!existe){

                this->listaBienes.push_back(bien);

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

                QTableWidgetItem *newCorrelativo = new QTableWidgetItem(m_ui->correlativoNO->text());
                if(fila%2!=0)
                    newCorrelativo->setBackground( QBrush::QBrush (QColor(211, 239, 255, 127)));
                m_ui->tablaBienes->setItem(fila, columna, newCorrelativo);


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
            else{
                  QMessageBox msgBox;
                  msgBox.warning(0, "Error","    El bien ya se encuentra en la lista!.   ");

            }
        }
    }
}


