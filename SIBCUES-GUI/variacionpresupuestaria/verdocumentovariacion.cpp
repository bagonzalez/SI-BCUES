#include "verdocumentovariacion.h"
#include "ui_verdocumentovariacion.h"
#include <QSqlQuery>



#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"

VerDocumentoVariacion::VerDocumentoVariacion(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::VerDocumentoVariacion)
{
    m_ui->setupUi(this);
    QString query,QEjercicioFiscal;
    int i=0;
    query="SELECT idEspecificacion FROM `variacionpresupuestaria`";
    consulta.exec(query);
    while (consulta.next()){
            m_ui->TablaListaVariaciones->insertRow(i);
            QEjercicioFiscal=consulta.value(0).toString();
            QTableWidgetItem *year=new QTableWidgetItem(QEjercicioFiscal);
            m_ui->TablaListaVariaciones->setItem(i,0,year);
            i++;
        }
  consulta.clear();
}


VerDocumentoVariacion::~VerDocumentoVariacion()
{
    delete m_ui;
}


void VerDocumentoVariacion::changeEvent(QEvent *e)
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

void VerDocumentoVariacion::on_Seleccionar_clicked()
{

  int year;
  m_ui->TablaListaVariaciones->selectColumn(0);
  year=m_ui->TablaListaVariaciones->currentItem()->data(0).toInt();

  /*Persistencia::Persistencia *servicioPersistencia=new Persistencia();
  servicioPersistencia->crearConexion();*/
  
  /* NCReport *report = new NCReport();
    report->reset(true);
    report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/VariacionPresupuestaria.xml");
      NCReportParameter *par = new NCReportParameter( "idEspecificacion", year);
     report->addParameter( par );
       report->runReportToPreview();
       QString error=report->lastErrorMsg();
        //std::cout<< error.toStdString();
               NCReportPreviewWindow *pv = new NCReportPreviewWindow();
                     pv->setReport( report );
                     pv->setOutput( (NCReportPreviewOutput*) report->output() );
                     pv->setWindowModality(Qt::ApplicationModal );
                     pv->setAttribute( Qt::WA_DeleteOnClose );
                     pv->show();*/

}
