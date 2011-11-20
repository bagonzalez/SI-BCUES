#include <QMessageBox>

#include "manttoinventario.h"
#include "ui_manttoinventario.h"
#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"

ManttoInventario::ManttoInventario(int idUnidad_, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManttoInventario)
{
    ui->setupUi(this);
    servicioPersistencia=new Persistencia(idUnidad_);
    idUnidad=idUnidad_;
    this->crearTabla();
}

ManttoInventario::~ManttoInventario()
{
    delete ui;
}

void ManttoInventario::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ManttoInventario::on_modeloTabla_activated(QModelIndex index)
{
     QString marcaSelecc=index.data(0).toString();
     QString id;

     /*QSqlQuery consulta("SELECT idMarca FROM marca WHERE nombreMarca='"+marcaSelecc+"'", QSqlDatabase::database("sibcues"));
     while(consulta.next()){
         id=consulta.value(0).toString();
         this->idMarca=id.toInt();
         this->marca=marcaSelecc;
     }

     QSqlQueryModel *model2 = new QSqlQueryModel;
     model2->setQuery("SELECT modelo FROM modelo WHERE idMarca="+id, QSqlDatabase::database("sibcues"));
     if (model2->lastError().isValid())
        qDebug() << model2->lastError();

     model2->setHeaderData(0, Qt::Horizontal, QObject::tr("Nombre modelo"));
     m_ui->tablaModelo->horizontalHeader()->resizeSection(0, 350);
     m_ui->tablaModelo->setModel(model2);
     m_ui->tablaModelo->setSelectionBehavior ( QAbstractItemView::SelectRows);
     m_ui->tablaModelo->alternatingRowColors();

     m_ui->tablaModelo->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
     connect(m_ui->tablaModelo->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(on_tablaModelo_activated(QModelIndex)));*/
}

void ManttoInventario::on_botonAgregar_clicked()
{
    QAbstractItemModel  *model=ui->modeloTabla->model();
    int anio;


    anio=ui->anio->date().year();
    int filas=model->rowCount();
    int anioTabla;
    bool existe=false;


    for(int i=0; i<=filas; i++){
       anioTabla=model->index(i,1).data(0).toInt();
       if(anioTabla==anio)
           existe=true;
    }

    if(!existe){
        this->servicioPersistencia->ingresarInventario(anio, this->idUnidad);
        QMessageBox::information(this, tr("Ingreso de Inventario"),
        tr("Sus datos Fueron almacenados correctamente"),QMessageBox::Ok, QMessageBox::Ok);

        crearTabla();

    }
}

void ManttoInventario::on_botonMenos_clicked()
{

    QAbstractItemModel  *model=ui->modeloTabla->model();
    int fila=ui->modeloTabla->currentIndex().row();
    int idInventario=model->index(fila,0).data(0).toInt();
    int filas=model->rowCount();

    this->servicioPersistencia->eliminarInventario(idInventario);
    this->crearTabla();

    model=ui->modeloTabla->model();

    int filasNuevas=model->rowCount();

    if(filas==filasNuevas){
        QMessageBox::warning(this, tr("Ingreso de Inventario"),
        tr("El inventario no puede ser eliminado debido a que posee registros"),QMessageBox::Ok, QMessageBox::Ok);
    }
}

void ManttoInventario::crearTabla(){

    //connect(ui->modeloTabla, SIGNAL(clicked(QModelIndex)), this, SLOT(on_modeloTabla_activated(QModelIndex)));
    //connect(ui->modeloTabla, SIGNAL(entered(QModelIndex)), this, SLOT(on_modeloTabla_activated(QModelIndex)));

    ui->modeloTabla->addAction(ui->insertRowAction);
    ui->modeloTabla->addAction(ui->deleteRowAction);
    ui->modeloTabla->addAction(ui->modificarRowAction);

     QSqlQueryModel *model = new QSqlQueryModel(ui->modeloTabla);

     model->setQuery("SELECT idInventario, anioInventario FROM inventario "
                     " WHERE idUnidad="+QString::number(idUnidad)+"  "
                     " ORDER BY anioInventario DESC", QSqlDatabase::database("sibcues"));

      if (model->lastError().isValid())
        qDebug() << model->lastError();

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id."));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Año"));

     //model->setEditStrategy(QSqlTableModel::OnRowChange);

     ui->modeloTabla->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
     ui->modeloTabla->setSelectionMode(QAbstractItemView::SingleSelection);
     ui->modeloTabla->setSelectionBehavior ( QAbstractItemView::SelectRows);

     ui->modeloTabla->alternatingRowColors();
     ui->modeloTabla->setModel(model);

     //ui->modeloTabla->horizontalHeader()->resizeSection(1, 350);


     connect(ui->modeloTabla->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(on_modeloTabla_activated(QModelIndex)));
     connect(ui->modeloTabla->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(currentChanged()));

     //connect(ui->btmAgregarMarca, SIGNAL(clicked()), this, SLOT(on_insertRowAction_triggered()));
     //connect(m_ui->btmEliminarMarca, SIGNAL(clicked()), this, SLOT(on_deleteRowAction_triggered()));
     //connect(m_ui->btmModificarMarca, SIGNAL(clicked()), this, SLOT(on_modificarRowAction_triggered()));
     //updateActions();

}
