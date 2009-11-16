#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include "consultaingreso.h"
#include "ui_consultaingreso.h"
#include <iostream>

ConsultaIngreso::ConsultaIngreso(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::ConsultaIngreso)
{
    m_ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "sibcues");
    if ( !db.isValid() ) {
        QMessageBox::warning( 0, "Error de Base de Datos", QObject::tr("No se pudo cargar el driver.") );
    }
     db.setHostName("127.0.0.1");
     db.setPort(3306);
     db.setDatabaseName("sibcues");
     db.setUserName("root");
     db.setPassword("root");
     if ( !db.open() ) {
        QMessageBox::warning( 0, "Error en Aplicacion", QObject::tr("No se puede conectar a la base: ")+db.lastError().databaseText() );
    }


     QSqlQueryModel *model = new QSqlQueryModel;
     model->setQuery("SELECT idIngreso, fechaIngreso, acuerdoCSU_NO FROM ingresobienes WHERE tipoBienIngreso='activofijo'");
      if (model->lastError().isValid())
        qDebug() << model->lastError();

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Fecha Ingreso"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Acuerdo CSU"));

     m_ui->tablaIngresoAF->setModel(model);     
     m_ui->tablaIngresoAF->setSelectionBehavior ( QAbstractItemView::SelectRows);
      m_ui->tablaIngresoBiblio->alternatingRowColors();

     QSqlQueryModel *model2 = new QSqlQueryModel;
     model2->setQuery("SELECT idIngreso, fechaIngreso, acuerdoCSU_NO FROM ingresobienes WHERE tipoBienIngreso='matbibliografico'");
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



     NCReport *report = new NCReport();
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/ingresoBienesAF.xml");
     NCReportParameter *par = new NCReportParameter( "idIngreso", 13 );
     report->addParameter( par );

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
