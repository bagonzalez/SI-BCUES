#include "dialogobuscarcuenta.h"
#include "ui_dialogobuscarcuenta.h"

dialogoBuscarCuenta::dialogoBuscarCuenta(RegistroSistemaContable *regC, bool _codigo, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::dialogoBuscarCuenta)
{
    m_ui->setupUi(this);
    this->regContable=regC;
    this->codigo=_codigo;

    QStringList labels;

    if(codigo)
        labels << tr("Nombre") << tr("Codigo") << tr("Descripcion");
    else
        labels << tr("Rubro") << tr("Clase") << tr("Descripcion");


    m_ui->tablaResultado->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
    m_ui->tablaResultado->setSelectionBehavior ( QAbstractItemView::SelectRows);
    m_ui->tablaResultado->setColumnCount(3);

    m_ui->tablaResultado->setHorizontalHeaderLabels(labels);
    m_ui->tablaResultado->horizontalHeader()->resizeSection(0, 100);
    m_ui->tablaResultado->horizontalHeader()->resizeSection(1, 100);
    m_ui->tablaResultado->horizontalHeader()->resizeSection(2, 200);
}

dialogoBuscarCuenta::~dialogoBuscarCuenta()
{
    delete m_ui;
}

void dialogoBuscarCuenta::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void dialogoBuscarCuenta::on_btmBuscar_clicked()
{
    QString busqueda=m_ui->textoABuscar->text();
    map<string, string> listaHijos=this->regContable->getHijosCatalogo();

    m_ui->tablaResultado->clearContents();
    m_ui->tablaResultado->setRowCount(0);

    int fila=0;

    for
    (
        map<string, string>::iterator et = listaHijos.begin();
        et != listaHijos.end();
        ++et
    )
    {        
        this->crearTablaR(et->first, fila, QString::fromStdString(et->second));
    }
     m_ui->labelResultados->setText("Resultados: "+QString::number(m_ui->tablaResultado->rowCount())+" encontrados");
}

void dialogoBuscarCuenta::on_btmSeleccionar_clicked()
{
    if(m_ui->tablaResultado->currentItem()!=NULL){
        int fila=m_ui->tablaResultado->currentRow();
        this->nombreMadre=m_ui->tablaResultado->item(fila, 0)->data(0).toString().toStdString();
        this->nombreCuenta=m_ui->tablaResultado->item(fila, 1)->data(0).toString().toStdString();
        this->close();
    }
}

string dialogoBuscarCuenta::getNombreCuenta(){
    return this->nombreCuenta;
}

void dialogoBuscarCuenta::crearTablaR(string nombreCuenta, int fila, QString nombreMadre)
{
    map<string, string> listaHijos;

    if(codigo)
        listaHijos=this->regContable->getHijosCuentaCodigos(nombreCuenta);
    else
        listaHijos=this->regContable->getNombreDescripcionHijos(nombreCuenta);

    QString busqueda=m_ui->textoABuscar->text();
    QString descripcion;    


    for
    (
        map<string, string>::iterator et = listaHijos.begin();
        et != listaHijos.end();
        ++et
    )
    {
        if(codigo)
        {
            descripcion=QString::fromStdString(this->regContable->getDireccionSubCuenta(et->second)->descripcion);            
            nombreMadre=QString::fromStdString(this->regContable->getDireccionSubCuenta(et->second)->cuentaMadre->nombreCuenta);
        }else
        {
            descripcion=QString::fromStdString(et->second);
        }

        if(descripcion.contains(busqueda, Qt::CaseInsensitive)){
            m_ui->tablaResultado->insertRow(fila);

            QTableWidgetItem *cuentaMadre=new QTableWidgetItem(nombreMadre);
            m_ui->tablaResultado->setItem(fila, 0, cuentaMadre);
            QTableWidgetItem *cuenta=new QTableWidgetItem(QString(et->first.c_str()));
            m_ui->tablaResultado->setItem(fila, 1, cuenta);
            QTableWidgetItem *descrip=new QTableWidgetItem(descripcion);
            m_ui->tablaResultado->setItem(fila, 2, descrip);
            fila++;
        }
        if(codigo)
            this->crearTablaR(et->first, fila, nombreMadre);
        else
            this->crearTablaR(et->first, fila, nombreMadre);
    }
}

void dialogoBuscarCuenta::on_tablaResultado_itemSelectionChanged()
{
    QString busqueda=m_ui->textoABuscar->text();
    QList<QTableWidgetItem *> lista=m_ui->tablaResultado->selectedItems();

    for (int i = 0; i < lista.size(); ++i){
        m_ui->textoMarcado->setText(lista.at(i)->data(0).toString());
        m_ui->textoMarcado->find(busqueda, QTextDocument::FindWholeWords);
    }
}

string dialogoBuscarCuenta::getMadre(){
    return this->nombreMadre;
}
