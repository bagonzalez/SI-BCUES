#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

#include "consultadescargos.h"
#include "ui_consultadescargos.h"


#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"


ConsultaDescargos::ConsultaDescargos(int idUnidad, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::ConsultaDescargos)
{
    m_ui->setupUi(this);

     Persistencia::Persistencia *servicioPersistencia=new Persistencia(idUnidad);
     servicioPersistencia->crearConexion();

     QSqlQueryModel *model = new QSqlQueryModel;
     model->setQuery("SELECT idDescargo, codigoDescargo, fechaDescargo FROM descargobienes  "
                     " LEFT JOIN inventario ON inventario.idInventario=descargobienes.idInventario LEFT JOIN unidad ON unidad.idUnidad = inventario.idUnidad  "
                     " WHERE tipoBienDescargo='activofijo' AND estadoDescargo='finalizado' AND unidad.idUnidad="+QString::number(idUnidad)+" ORDER BY idDescargo", QSqlDatabase::database("sibcues"));
      if (model->lastError().isValid())
        qDebug() << model->lastError();

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Codigo Descargo"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Fecha Descargo"));

     m_ui->tablaDescargoAF->setModel(model);
     m_ui->tablaDescargoAF->setSelectionBehavior ( QAbstractItemView::SelectRows);
     m_ui->tablaDescargoAF->alternatingRowColors();

     QSqlQueryModel *model2 = new QSqlQueryModel;
     model2->setQuery("SELECT idDescargo, fechaDescargo FROM descargobienes WHERE tipoBienDescargo='matbibliografico' ORDER BY idDescargo");
     if (model2->lastError().isValid())
        qDebug() << model->lastError();

     model2->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model2->setHeaderData(1, Qt::Horizontal, QObject::tr("Fecha Descargo"));

     m_ui->tablaDescargoBiblio->setModel(model2);
     m_ui->tablaDescargoBiblio->setSelectionBehavior ( QAbstractItemView::SelectRows);
     m_ui->tablaDescargoBiblio->alternatingRowColors();
}

ConsultaDescargos::~ConsultaDescargos()
{
    delete m_ui;
}

void ConsultaDescargos::changeEvent(QEvent *e)
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

void ConsultaDescargos::on_generarReporte_pressed(){

    QAbstractItemModel  *model=m_ui->tablaDescargoAF->model();

    int fila=m_ui->tablaDescargoAF->currentIndex().row();


     NCReport *report = new NCReport();
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/descargoBienesAF.xml");
     //NCReportParameter *par = new NCReportParameter( "idDescargo", model->index(fila,0).data(0).toInt());
     //report->addParameter( par );
     report->addParameter( "idDescargo", QVariant( model->index(fila,0).data(0).toInt()) );

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

void ConsultaDescargos::on_salir_pressed(){
    this->close();
}

void ConsultaDescargos::on_generarReporteMB_pressed(){

    QAbstractItemModel  *model=m_ui->tablaDescargoBiblio->model();
    int fila=m_ui->tablaDescargoBiblio->currentIndex().row();

    /*NCReport *report = new NCReport();
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/descargoBienesBiblio.xml");
     NCReportParameter *par = new NCReportParameter( "idDescargo", model->index(fila,0).data(0).toInt());
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
