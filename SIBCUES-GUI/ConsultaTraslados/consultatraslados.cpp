#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

#include "consultatraslados.h"
#include "ui_consultatraslados.h"


consultaTraslados::consultaTraslados(int idUnidad, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::consultaTraslados)
{
    m_ui->setupUi(this);


     servicioPersistencia=new Persistencia(idUnidad);
     servicioPersistencia->crearConexion();


     QSqlQueryModel *model = new QSqlQueryModel;
     model->setQuery("SELECT idTraslado, codTraslado, fechaTraslado FROM trasladobienes LEFT JOIN inventario ON "
                     " inventario.idInventario=trasladobienes.idInventario LEFT JOIN unidad ON unidad.idUnidad = inventario.idUnidad  "
                     " WHERE tipoBienTraslado='activofijo'  AND estadoTraslado='finalizado' AND unidad.idUnidad="+QString::number(idUnidad)+" "
                     " ORDER BY idTraslado", QSqlDatabase::database("sibcues"));
      if (model->lastError().isValid())
        qDebug() << model->lastError();

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Codigo Traslado"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Fecha"));

     m_ui->tablaTrasladoAF->setModel(model);
     m_ui->tablaTrasladoAF->setSelectionBehavior ( QAbstractItemView::SelectRows);
      m_ui->tablaTrasladoAF->alternatingRowColors();

     QSqlQueryModel *model2 = new QSqlQueryModel;
     model2->setQuery("SELECT idTraslado, fechaTraslado FROM trasladobienes WHERE tipoBienTraslado='matbibliografico' ORDER BY idTraslado");
     if (model2->lastError().isValid())
        qDebug() << model->lastError();

     model2->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model2->setHeaderData(1, Qt::Horizontal, QObject::tr("Fecha Traslado"));

     m_ui->tablaTrasladoBiblio->setModel(model2);
     m_ui->tablaTrasladoBiblio->setSelectionBehavior ( QAbstractItemView::SelectRows);
     m_ui->tablaTrasladoBiblio->alternatingRowColors();

}

consultaTraslados::~consultaTraslados()
{
    delete m_ui;
}

void consultaTraslados::changeEvent(QEvent *e)
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



void consultaTraslados::on_generarReporte_pressed(){



    QAbstractItemModel  *model=m_ui->tablaTrasladoAF->model();

    int fila=m_ui->tablaTrasladoAF->currentIndex().row();

     NCReport *report = new NCReport();
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/trasladoBienesAF.xml");
     report->addParameter( "idTraslado", model->index(fila,0).data(0).toInt());

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

void consultaTraslados::on_salir_pressed(){
    this->close();
}

void consultaTraslados::on_generarReporteMB_pressed(){

    QAbstractItemModel  *model=m_ui->tablaTrasladoBiblio->model();

    int fila=m_ui->tablaTrasladoBiblio->currentIndex().row();

     /*NCReport *report = new NCReport();
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/trasladoBienesBiblio.xml");
     NCReportParameter *par = new NCReportParameter( "idTraslado", model->index(fila,0).data(0).toInt());
     report->addParameter( par );

     report->runReportToPreview();
     QString error=report->lastErrorMsg();
     std::cout<< error.toStdString();

     NCReportPreviewWindow *pv = new NCReportPreviewWindow();
     pv->setReport( report );
     pv->setOutput( (NCReportPreviewOutput*) report->output() );
     pv->setWindowModality(Qt::ApplicationModal );
     pv->setAttribute( Qt::WA_DeleteOnClose );
     pv->show();*/

}

