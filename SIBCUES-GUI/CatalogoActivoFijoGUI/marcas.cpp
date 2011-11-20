
#include <QMessageBox>
#include "marcas.h"
#include "ui_marcas.h"


#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"


marcas::marcas(int idUnidad, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::marcas)
{
    m_ui->setupUi(this);

    connect(m_ui->tablaMarcas, SIGNAL(clicked(QModelIndex)), this, SLOT(on_tablaMarcas_activated(QModelIndex)));
    connect(m_ui->tablaMarcas, SIGNAL(entered(QModelIndex)), this, SLOT(on_tablaMarcas_activated(QModelIndex)));

    m_ui->tablaMarcas->addAction(m_ui->insertRowAction);
    m_ui->tablaMarcas->addAction(m_ui->deleteRowAction);
    m_ui->tablaMarcas->addAction(m_ui->modificarRowAction);

    Persistencia::Persistencia *servicioPersistencia=new Persistencia(idUnidad);

     QSqlTableModel *model = new QSqlTableModel(m_ui->tablaMarcas, QSqlDatabase::database("sibcues"));
     //model->setQuery("SELECT nombreMarca FROM marca;");
     if (model->lastError().isValid())
        qDebug() << model->lastError();

     model->setTable("marca");
     model->select();
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre de Marca"));
     model->setEditStrategy(QSqlTableModel::OnRowChange);
     m_ui->tablaMarcas->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);

     m_ui->tablaMarcas->setModel(model);     
     m_ui->tablaMarcas->alternatingRowColors();
     m_ui->tablaMarcas->hideColumn(0);
     m_ui->tablaMarcas->horizontalHeader()->resizeSection(1, 350);
     m_ui->tablaMarcas->setSelectionMode(QAbstractItemView::SingleSelection);

     connect(m_ui->tablaMarcas->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(on_tablaMarcas_activated(QModelIndex)));
     connect(m_ui->tablaMarcas->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(currentChanged()));

     connect(m_ui->btmAgregarMarca, SIGNAL(clicked()), this, SLOT(on_insertRowAction_triggered()));
     connect(m_ui->btmEliminarMarca, SIGNAL(clicked()), this, SLOT(on_deleteRowAction_triggered()));
     connect(m_ui->btmModificarMarca, SIGNAL(clicked()), this, SLOT(on_modificarRowAction_triggered()));
     updateActions();
}

marcas::~marcas()
{
    delete m_ui;
}

void marcas::changeEvent(QEvent *e)
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


void marcas::on_btmSeleccionar_clicked()
{
    this->close();
}

void marcas::on_btmCancelar_clicked()
{
    this->close();
}

void marcas::on_tablaMarcas_activated(QModelIndex index)
{
     QString marcaSelecc=index.data(0).toString();
     QString id;

     QSqlQuery consulta("SELECT idMarca FROM marca WHERE nombreMarca='"+marcaSelecc+"'", QSqlDatabase::database("sibcues"));
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
     connect(m_ui->tablaModelo->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(on_tablaModelo_activated(QModelIndex)));
}


void marcas::on_tablaModelo_activated(QModelIndex index)
{
     QString modeloSelecc=index.data(0).toString();
     QString id;

     QSqlQuery consulta("SELECT idModelo FROM modelo WHERE modelo='"+modeloSelecc+"'", QSqlDatabase::database("sibcues"));
     while(consulta.next()){
         id=consulta.value(0).toString();
         this->idModelo=id.toInt();
         this->modelo=modeloSelecc;
     }
}

int marcas::getIDMarca(){
    return this->idMarca;
}

QString marcas::getMarca(){
    return this->marca;
}

QString marcas::getModelo(){
    return this->modelo;
}

int marcas::getIDModelo(){
    return this->idModelo;
}

void marcas::on_btmAgregarMarca_clicked()
{
}

void marcas::insertRow(){
    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(m_ui->tablaMarcas->model());
     if (!model)
         return;
     QModelIndex insertIndex = m_ui->tablaMarcas->currentIndex();
     int row = insertIndex.row() == -1 ? 0 : insertIndex.row();
     model->insertRow(row);
     insertIndex = model->index(row, 0);
     m_ui->tablaMarcas->setCurrentIndex(insertIndex);
     m_ui->tablaMarcas->edit(insertIndex);
}


void marcas::deleteRow(){
     QSqlTableModel *model = qobject_cast<QSqlTableModel *>(m_ui->tablaMarcas->model());
     if (!model)
         return;

     model->setEditStrategy(QSqlTableModel::OnManualSubmit);

     QModelIndexList currentSelection = m_ui->tablaMarcas->selectionModel()->selectedIndexes();
     for (int i = 0; i < currentSelection.count(); ++i) {
        /* if (currentSelection.at(i).column() != 0)
             continue;*/
         model->removeRow(currentSelection.at(i).row());
         std::cout << "Eliminando...";
     }

     model->submitAll();
     model->setEditStrategy(QSqlTableModel::OnRowChange);
     updateActions();
}


void marcas::updateActions(){
     bool enableIns = qobject_cast<QSqlTableModel *>(m_ui->tablaMarcas->model());
     bool enableDel = enableIns && m_ui->tablaMarcas->currentIndex().isValid();

     m_ui->insertRowAction->setEnabled(enableIns);
     m_ui->deleteRowAction->setEnabled(enableDel);
}


void marcas::on_btmAgregarModelo_clicked()
{
     //this->idMarca;

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel *>(m_ui->tablaModelo->model());
     if (!model)
         return;
     QModelIndex insertIndex = m_ui->tablaModelo->currentIndex();
     int row = insertIndex.row() == -1 ? 0 : insertIndex.row();
     model->insertRow(row);     
     insertIndex = model->index(row, 0);
     m_ui->tablaModelo->setCurrentIndex(insertIndex);
     m_ui->tablaModelo->edit(insertIndex);
}

void marcas::modificarFila()
{
    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(m_ui->tablaMarcas->model());
     if (!model)
         return;

     /*QModelIndexList currentSelection = m_ui->tablaMarcas->selectionModel()->selectedIndexes();
     for (int i = 0; i < currentSelection.count(); ++i) {       
         m_ui->tablaMarcas->edit(currentSelection.at(i));
     }*/

     QModelIndex insertIndex = m_ui->tablaModelo->currentIndex();
     m_ui->tablaMarcas->edit(insertIndex);
     model->submitAll();
     updateActions();
}

