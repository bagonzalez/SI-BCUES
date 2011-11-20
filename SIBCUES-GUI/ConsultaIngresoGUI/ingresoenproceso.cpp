#include "ingresoenproceso.h"
#include "ui_ingresoenproceso.h"

#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"

IngresoenProceso::IngresoenProceso(int idUnidad, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IngresoenProceso)
{
    ui->setupUi(this);

    Persistencia::Persistencia *servicioPersistencia=new Persistencia(idUnidad);
    servicioPersistencia->crearConexion();

     QSqlQueryModel *model = new QSqlQueryModel(ui->tablaIngresosAF);
     model->setQuery("SELECT idIngreso, codigoIngreso, fechaIngreso FROM ingresobienes LEFT JOIN inventario ON "
                     " inventario.idInventario=ingresobienes.idInventario LEFT JOIN unidad ON unidad.idUnidad = inventario.idUnidad  "
                     " WHERE tipoBienIngresado='activofijo' AND estadoIngreso='enproceso' AND unidad.idUnidad="+QString::number(idUnidad)+" "
                     " ORDER BY idIngreso", QSqlDatabase::database("sibcues"));
     if (model->lastError().isValid())
        qDebug() << model->lastError();

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Codigo Ingreso"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Fecha Ingreso"));


     ui->tablaIngresosAF->setModel(model);
     ui->tablaIngresosAF->setSelectionBehavior ( QAbstractItemView::SelectRows);
     ui->tablaIngresosAF->alternatingRowColors();
     this->idIngreso=0;
}

IngresoenProceso::~IngresoenProceso()
{
    delete ui;
}

void IngresoenProceso::changeEvent(QEvent *e)
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

void IngresoenProceso::on_btmSeleccionar_pressed()
{
     QAbstractItemModel  *model=ui->tablaIngresosAF->model();
     int fila=ui->tablaIngresosAF->currentIndex().row();
     this->idIngreso=model->index(fila,0).data(0).toInt();



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
             SQL+="FROM lineaIngresoAF  LEFT JOIN ingresobienes ON lineaIngresoAF.idIngreso=ingresobienes.idIngreso ";
             SQL+="LEFT JOIN bienactivofijo ON lineaIngresoAF.idBien=bienactivofijo.idBien ";
             SQL+="LEFT JOIN sectores ON bienactivofijo.idSector=sectores.idSector ";
             SQL+="LEFT JOIN modelo ON bienactivofijo.idModelo=modelo.idModelo ";
             SQL+="LEFT JOIN marca ON bienactivofijo.idMarca=marca.idMarca ";
             SQL+="LEFT JOIN especbien ON especbien.idEspec=bienactivofijo.idEspec ";
             SQL+="LEFT JOIN especcuenta ON especcuenta.idEspecCuenta=especbien.idEspecCuenta ";
             SQL+="WHERE ingresobienes.idIngreso = "+ QString::number(idIngreso);

     QSqlQuery query(QSqlDatabase::database("sibcues"));
     QSqlQuery query2(QSqlDatabase::database("sibcues"));
     query.exec(SQL);

     while(query.next()){
         listaItem.push_back(new QTableWidgetItem(query.value(0).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(1).toString()));

         SQL="SELECT  especcuenta.codigoCuenta as especifico  FROM lineaIngresoAF  ";
         SQL+="LEFT JOIN ingresobienes ON lineaIngresoAF.idIngreso=ingresobienes.idIngreso ";
         SQL+="LEFT JOIN especcuenta ON especcuenta.idEspecCuenta=lineaIngresoAF.idEspecifico ";
         SQL+="WHERE ingresobienes.idIngreso = "+QString::number(idIngreso)+" AND lineaIngresoAF.idBien= "+query.value(9).toString();

         query2.exec(SQL);
         while(query2.next()){
             listaItem.push_back(new QTableWidgetItem(query2.value(0).toString()));
         }
         listaItem.push_back(new QTableWidgetItem(query.value(2).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(4).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(3).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(8).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(5).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(6).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(10).toString()));
         listaItem.push_back(new QTableWidgetItem(query.value(9).toString()));
     }
     this->close();
}

QList<QTableWidgetItem *>  IngresoenProceso::getListaItems(){
    return this->listaItem;
}

int IngresoenProceso::getIdIngreso(){
    return this->idIngreso;
}


