#include "mantenimientotitulo.h"
#include "ui_mantenimientotitulo.h"
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QAbstractItemModel>


#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"


mantenimientoTitulo::mantenimientoTitulo(int idUnidad, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::mantenimientoTitulo)
{
    m_ui->setupUi(this);

    m_ui->btmTitulo->setChecked(true);


    Persistencia::Persistencia *servicioPersistencia=new Persistencia(idUnidad);

     QSqlQueryModel *model = new QSqlQueryModel(m_ui->titulos);
     model->setQuery("SELECT tituloObra, isbn FROM titulo;", QSqlDatabase::database("sibcues"));
     if (model->lastError().isValid())
        qDebug() << model->lastError();

     //model->setTable("titulo");
     //model->select();

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Titulo Material Bibliografico"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("ISBN"));
     m_ui->titulos->setModel(model);
     m_ui->titulos->alternatingRowColors();
     //m_ui->titulos->hideColumn(0);
     m_ui->titulos->horizontalHeader()->resizeSection(0, 350);
     m_ui->titulos->setSelectionMode(QAbstractItemView::SingleSelection);
     connect(m_ui->titulos->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(on_titulos_activated(QModelIndex)));
     m_ui->labelTitulo->setText("Titulos: "+QString::number(model->rowCount())+" resultados.");


}

mantenimientoTitulo::~mantenimientoTitulo()
{
    delete m_ui;
}

void mantenimientoTitulo::changeEvent(QEvent *e)
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

void mantenimientoTitulo::on_titulos_activated(QModelIndex index)
{
     QString tituloSelecc=index.data(0).toString();
     QSqlQueryModel *model = new QSqlQueryModel(m_ui->listaAutores);
     model->setQuery("SELECT autor.nombreAutor FROM obrade left join titulo on titulo.idTitulo=obrade.idTitulo left join autor on obrade.idAutor=autor.idAutor WHERE titulo.tituloObra=\""+tituloSelecc+"\";", QSqlDatabase::database("sibcues"));
     if (model->lastError().isValid())
        qDebug() << model->lastError();

     //model->setTable("titulo");
     //model->select();
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Titulo Material Bibliografico"));
     //model->setEditStrategy(QSqlTableModel::OnRowChange);
     //m_ui->titulos->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
     m_ui->listaAutores->setModel(model);
     m_ui->titulos->alternatingRowColors();

}

void mantenimientoTitulo::on_btmBuscar_clicked()
{
    if(m_ui->btmTitulo->isChecked()){

        QSqlQueryModel *model = new QSqlQueryModel(m_ui->titulos);
        model->setQuery("SELECT tituloObra, isbn FROM titulo WHERE tituloObra LIKE '%"+m_ui->busqueda->text()+"%';", QSqlDatabase::database("sibcues"));
         if (model->lastError().isValid())
            qDebug() << model->lastError();

         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Titulo Material Bibliografico"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("ISBN"));
         m_ui->titulos->setModel(model);
         connect(m_ui->titulos->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(on_titulos_activated(QModelIndex)));
         m_ui->labelTitulo->setText("Titulos: "+QString::number(model->rowCount())+" resultados.");
    }
    else{

        QSqlQueryModel *model = new QSqlQueryModel(m_ui->titulos);
        model->setQuery("SELECT titulo.tituloObra, titulo.isbn FROM obrade left join titulo on titulo.idTitulo=obrade.idTitulo left join autor on obrade.idAutor=autor.idAutor WHERE autor.nombreAutor LIKE '%"+m_ui->busqueda->text()+"%';", QSqlDatabase::database("sibcues"));

        if (model->lastError().isValid())
            qDebug() << model->lastError();

         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Titulo Material Bibliografico"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("ISBN"));
         m_ui->titulos->setModel(model);
         connect(m_ui->titulos->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(on_titulos_activated(QModelIndex)));
         m_ui->labelTitulo->setText("Titulos: "+QString::number(model->rowCount())+" resultados.");
    }
}

void mantenimientoTitulo::on_seleccionarTitulo_clicked()
{
    QAbstractItemModel  *model=m_ui->titulos->model();
    int fila=m_ui->titulos->currentIndex().row();
    this->titulo=model->index(fila,0).data(0).toString();
    this->isbn=model->index(fila, 1).data(0).toString();
    this->close();
}


QString mantenimientoTitulo::getTitulo(){
    return this->titulo;
}

QString mantenimientoTitulo::getISBN(){
    return this->isbn;

}
