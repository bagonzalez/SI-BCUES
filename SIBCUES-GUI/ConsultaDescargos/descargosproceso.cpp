#include "descargosproceso.h"
#include "ui_descargosproceso.h"

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"


DescargosProceso::DescargosProceso(int idUnidad, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DescargosProceso)
{
    ui->setupUi(this);

    Persistencia::Persistencia *servicioPersistencia=new Persistencia(idUnidad);    

     QSqlQueryModel *model = new QSqlQueryModel(ui->tablaDescargoAF);
     model->setQuery("SELECT descargobienes.idDescargo, descargobienes.codigoDescargo, fechaDescargo FROM descargobienes "
                     " LEFT JOIN inventario ON inventario.idInventario=descargobienes.idInventario LEFT JOIN unidad ON unidad.idUnidad = inventario.idUnidad  "
                     "WHERE tipoBienDescargo='activofijo' AND estadoDescargo='enproceso' AND unidad.idUnidad="+QString::number(idUnidad)+" "
                     " ORDER BY idDescargo", QSqlDatabase::database("sibcues"));
     if (model->lastError().isValid())
        qDebug() << model->lastError();

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Codigo Descargo"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Fecha"));


     ui->tablaDescargoAF->setModel(model);
     ui->tablaDescargoAF->setSelectionBehavior ( QAbstractItemView::SelectRows);
     ui->tablaDescargoAF->alternatingRowColors();
     this->idDescargo=0;
}

DescargosProceso::~DescargosProceso()
{
    delete ui;
}

void DescargosProceso::changeEvent(QEvent *e)
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

void DescargosProceso::on_btmSeleccionar_pressed()
{
     QAbstractItemModel  *model=ui->tablaDescargoAF->model();
     int fila=ui->tablaDescargoAF->currentIndex().row();
     this->idDescargo=model->index(fila,0).data(0).toInt();



     QString SQL="SELECT especcuenta.codigoCuenta as nombreCuenta, ";
             SQL+="especbien.nombreClase as clase, ";
             SQL+="especbien.descripcionClase as descripcion, ";
             SQL+="modelo.modelo as modelo, ";
             SQL+="marca.nombreMarca as marca, ";
             SQL+="bienactivofijo.fechaAdquisicion as fecha, ";
             SQL+="bienactivofijo.valor as Valor, ";
             SQL+="bienactivofijo.correlativo as correlativo, ";
             SQL+="bienactivofijo.serie as serie, ";
             SQL+="bienactivofijo.idBien as idBien, ";
             SQL+="sectores.descripcionSector as sector ";
             SQL+="FROM lineaDescargoAF  LEFT JOIN descargobienes ON lineaDescargoAF.idDescargo=descargobienes.idDescargo ";
             SQL+="LEFT JOIN bienactivofijo ON lineaDescargoAF.idBien=bienactivofijo.idBien ";
             SQL+="LEFT JOIN sectores ON bienactivofijo.idSector=sectores.idSector ";
             SQL+="LEFT JOIN modelo ON bienactivofijo.idModelo=modelo.idModelo ";
             SQL+="LEFT JOIN marca ON bienactivofijo.idMarca=marca.idMarca ";
             SQL+="LEFT JOIN especbien ON especbien.idEspec=bienactivofijo.idEspec ";
             SQL+="LEFT JOIN especcuenta ON especcuenta.idEspecCuenta=especbien.idEspecCuenta ";
             SQL+="WHERE descargobienes.idDescargo = "+ QString::number(idDescargo);

     QSqlQuery query(QSqlDatabase::database("sibcues"));
     QSqlQuery query2(QSqlDatabase::database("sibcues"));
     query.exec(SQL);

     while(query.next()){
         listaItem.push_back(new QTableWidgetItem(query.value(0).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(1).toString()));

         SQL="SELECT  especcuenta.codigoCuenta as especifico  FROM lineaDescargoAF  ";
         SQL+="LEFT JOIN descargobienes ON lineaDescargoAF.idDescargo=descargobienes.idDescargo ";
         SQL+="LEFT JOIN especcuenta ON especcuenta.idEspecCuenta=lineaDescargoAF.idEspecifico ";
         SQL+="WHERE descargobienes.idDescargo = "+QString::number(idDescargo)+" AND lineaDescargoAF.idBien= "+query.value(9).toString();

         query2.exec(SQL);
         while(query2.next()){
             listaItem.push_back(new QTableWidgetItem(query2.value(0).toString()));
         }
         listaItem.push_back(new QTableWidgetItem(query.value(7).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(2).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(4).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(3).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(8).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(5).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(6).toString()));
         //listaItem.push_back(new QTableWidgetItem(query.value(10).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(9).toString()));
     }
     this->close();
}

QList<QTableWidgetItem *>  DescargosProceso::getListaItems(){
    return this->listaItem;
}

int DescargosProceso::getIdDescargo(){
    return this->idDescargo;
}
