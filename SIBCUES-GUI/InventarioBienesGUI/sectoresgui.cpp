#include "sectoresgui.h"
#include "ui_sectoresgui.h"

#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>

#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"



SectoresGUI::SectoresGUI(Registro *_regBasico, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::SectoresGUI)
{
    m_ui->setupUi(this);
    this->regBasico=_regBasico;

    Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);

    m_ui->tablaSectores->setItemDelegate(new QSqlRelationalDelegate(m_ui->tablaSectores));


    QSqlRelationalTableModel *model = new QSqlRelationalTableModel(m_ui->tablaSectores, QSqlDatabase::database("sibcues"));
     if (model->lastError().isValid())
        qDebug() << model->lastError();

     model->setTable("sectores");

     model->setRelation(2, QSqlRelation("unidad", "idUnidad", "nombreUnidad"));
     model->setFilter("nombreUnidad='"+QString::fromStdString(this->regBasico->getNombreUnidad())+"'");



     model->select();
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre del Sector"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Unidad"));



     model->setEditStrategy(QSqlRelationalTableModel::OnRowChange);
     m_ui->tablaSectores->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);

     m_ui->tablaSectores->setModel(model);

     m_ui->tablaSectores->alternatingRowColors();
     //m_ui->tablaSectores->hideColumn(0);
     m_ui->tablaSectores->horizontalHeader()->resizeSection(1, 350);
     m_ui->tablaSectores->setSelectionMode(QAbstractItemView::SingleSelection);

     connect(m_ui->tablaSectores->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(on_tablaSectores_activated(QModelIndex)));
     connect(m_ui->btmIngresar, SIGNAL(clicked()), this, SLOT(insertRow()));
     connect(m_ui->btmEliminar, SIGNAL(clicked()), this, SLOT(deleteRow()));
     connect(m_ui->btmEliminar, SIGNAL(clicked()), this, SLOT(modificarFila()));
}

SectoresGUI::~SectoresGUI()
{
    delete m_ui;
}

void SectoresGUI::changeEvent(QEvent *e)
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


void SectoresGUI::insertRow(){
    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(m_ui->tablaSectores->model());
     if (!model)
         return;
     QModelIndex insertIndex = m_ui->tablaSectores->currentIndex();
     int row = insertIndex.row() == -1 ? 0 : insertIndex.row();
     model->insertRow(row);
     insertIndex = model->index(row, 0);
     m_ui->tablaSectores->setCurrentIndex(insertIndex);
     m_ui->tablaSectores->edit(insertIndex);
}

void SectoresGUI::deleteRow(){
}

void SectoresGUI::modificarFila(){
}

void SectoresGUI::on_tablaSectores_activated(QModelIndex index)
{

}
