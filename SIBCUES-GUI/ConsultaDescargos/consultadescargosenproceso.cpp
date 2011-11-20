#include "consultadescargosenproceso.h"
#include "ui_consultadescargosenproceso.h"

ConsultaDescargosenProceso::ConsultaDescargosenProceso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsultaDescargosenProceso)
{
    ui->setupUi(this);
}

ConsultaDescargosenProceso::~ConsultaDescargosenProceso()
{
    delete ui;
}

void ConsultaDescargosenProceso::changeEvent(QEvent *e)
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
