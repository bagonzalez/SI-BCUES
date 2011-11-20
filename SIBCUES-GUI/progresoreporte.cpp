#include "progresoreporte.h"
#include "ui_progresoreporte.h"

progresoReporte::progresoReporte(NCReport *report, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::progresoReporte)
{
    m_ui->setupUi(this);
    m_ui->progressBar->setValue(0);
    m_ui->progressBar->setMaximum(1000);
    m_ui->progresoText->setText("Cargando datos...");
    connect(report, SIGNAL(pageProgress(int)), this, SLOT(cambiarProgreso(int)));
    connect(report, SIGNAL(pageProgress(int)), m_ui->progressBar, SLOT(setValue(int)));
    connect(report, SIGNAL(dataRowCount(int)), m_ui->progressBar, SLOT(setValue(int)));
    connect(report, SIGNAL(reportEnds()), this, SLOT(close()));
    this->report=report;
}

progresoReporte::~progresoReporte()
{
    delete m_ui;
}

void progresoReporte::changeEvent(QEvent *e)
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

void progresoReporte::cambiarProgreso(int pagina){
    m_ui->progresoText->setText("Cargando reporte, pagina...: "+QString::number(pagina));
}


void progresoReporte::execReport(){    
   report->runReportToPreview();
}
