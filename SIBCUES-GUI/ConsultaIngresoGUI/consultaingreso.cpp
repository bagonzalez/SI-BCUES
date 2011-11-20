#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include "consultaingreso.h"
#include "ui_consultaingreso.h"
#include <iostream>

#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"

ConsultaIngreso::ConsultaIngreso(int idUnidad, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::ConsultaIngreso)
{
    m_ui->setupUi(this);

    Persistencia::Persistencia *servicioPersistencia=new Persistencia(idUnidad);
    servicioPersistencia->crearConexion();

     QSqlQueryModel *model = new QSqlQueryModel(m_ui->tablaIngresoAF);
     model->setQuery("SELECT idIngreso, codigoIngreso,fechaIngreso FROM ingresobienes "
                     " LEFT JOIN inventario ON ingresobienes.idInventario = inventario.idInventario LEFT JOIN unidad ON unidad.idUnidad = inventario.idUnidad "
                     " WHERE tipoBienIngresado='activofijo' AND estadoIngreso='finalizado' AND unidad.idUnidad="+QString::number(idUnidad)+"  "
                     " ORDER BY idIngreso", QSqlDatabase::database("sibcues"));

      if (model->lastError().isValid())
        qDebug() << model->lastError();

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Codigo Ingreso"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Fecha"));

     m_ui->tablaIngresoAF->setModel(model);     
     m_ui->tablaIngresoAF->setSelectionBehavior ( QAbstractItemView::SelectRows);
     m_ui->tablaIngresoBiblio->alternatingRowColors();

     QSqlQueryModel *model2 = new QSqlQueryModel;
     model2->setQuery("SELECT idIngreso, fechaIngreso, acuerdoCSU_NO FROM ingresobienes WHERE tipoBienIngresado='matbibliografico' ORDER BY idIngreso", QSqlDatabase::database("sibcues"));
     if (model2->lastError().isValid())
        qDebug() << model->lastError();

     model2->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model2->setHeaderData(1, Qt::Horizontal, QObject::tr("Fecha Ingreso"));
     model2->setHeaderData(2, Qt::Horizontal, QObject::tr("Acuerdo CSU"));

     m_ui->tablaIngresoBiblio->setModel(model2);
     m_ui->tablaIngresoBiblio->setSelectionBehavior ( QAbstractItemView::SelectRows);    
     m_ui->tablaIngresoBiblio->alternatingRowColors();


}

ConsultaIngreso::~ConsultaIngreso()
{
    delete m_ui;
}

void ConsultaIngreso::on_salir_pressed(){
    this->close();
}

void ConsultaIngreso::changeEvent(QEvent *e)
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

void ConsultaIngreso::on_generarReporte_pressed(){

    QAbstractItemModel  *model=m_ui->tablaIngresoAF->model();


    int fila=m_ui->tablaIngresoAF->currentIndex().row();


     NCReport *report = new NCReport();
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/ingresoBienesAF.xml");
     NCReportParameter *par = new NCReportParameter( "idIngreso", model->index(fila,0).data(0).toInt());
     report->addParameter( "idIngreso", model->index(fila,0).data(0).toInt());


     report->runReportToPreview();
     QString error=report->lastErrorMsg();
     std::cout<< error.toStdString();

     if ( !report->hasError() ) {
       NCReportPreviewWindow *pv = new NCReportPreviewWindow();
       pv->setOutput( (NCReportPreviewOutput*)report->output() );
       pv->setWindowModality( Qt::ApplicationModal );
       pv->show();
     }
}

void ConsultaIngreso::on_generarReporteBiblio_pressed(){

     QAbstractItemModel  *model=m_ui->tablaIngresoBiblio->model();

    int fila=m_ui->tablaIngresoBiblio->currentIndex().row();
     /*NCReport *report = new NCReport();
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/ingresoBienesBiblio.xml");
     NCReportParameter *par = new NCReportParameter( "idIngreso", model->index(fila,0).data(0).toInt());
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

