#include "bienesporsector.h"
#include "ui_bienesporsector.h"

BienesporSector::BienesporSector(basico::Registro *registroBasico, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BienesporSector)
{
    ui->setupUi(this);

    this->registroBasico=registroBasico;

    servicioPersistencia=new Persistencia(registroBasico->getUnidad()->id);

    std::map<int, string> listaSectores=servicioPersistencia->cargarSectores();
    ui->descripSector->addItem("<< Todos >>", QVariant::QVariant(-1));

    for
    (
            map<int, string>::iterator it = listaSectores.begin();
            it != listaSectores.end();
                ++it
     ){
          ui->descripSector->addItem(QString(it->second.c_str()), QVariant::QVariant(it->first));
    }

    QMap<int, QString> listaAnioInventa=servicioPersistencia->getInventariosFijos();
    ui->anioSelecc->addItem("<< Todos >>", QVariant::QVariant(-1));

    for(QMap<int, QString>::iterator it = listaAnioInventa.begin();
        it != listaAnioInventa.end();
        ++it
    ){

            ui->anioSelecc->addItem(QString(it.value()), QVariant::QVariant(it.key()));
    }

}

BienesporSector::~BienesporSector()
{
    delete ui;
}

void BienesporSector::on_btnCancelar_clicked()
{
    this->close();
}

void BienesporSector::on_btnVerReporte_clicked()
{


     NCReport *report = new NCReport();
     report->reset(true);
     report->setReportSource( NCReportSource::File  );
     report->setReportFile("Reportes/listadoBienesAF.xml");
     report->addParameter( "idUnidad", QVariant(registroBasico->getUnidad()->id));

     if(ui->anioSelecc->currentText()==("<< Todos >>"))
         report->addParameter( "anioInventarioSelecc", QVariant("%"));
     else
         report->addParameter( "anioInventarioSelecc", QVariant(ui->anioSelecc->currentText()));

     if(ui->descripSector->currentText()==("<< Todos >>"))
         report->addParameter( "descripcionSectoSelecc",QVariant("%"));
     else
         report->addParameter( "descripcionSectoSelecc",QVariant(ui->descripSector->currentText()));


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
