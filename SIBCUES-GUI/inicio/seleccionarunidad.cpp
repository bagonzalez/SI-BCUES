#include "seleccionarunidad.h"
#include "ui_seleccionarunidad.h"
#include <QSqlQuery>

#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"


SeleccionarUnidad::SeleccionarUnidad(int IDUnidad, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::SeleccionarUnidad)
{
    m_ui->setupUi(this);
    this->IDUnidad=IDUnidad;

    Persistencia *servicioPer=new Persistencia(IDUnidad);

    std::map<int, string> listaUnidades=servicioPer->cargarNombreUnidades();

    for
    (
            map<int, string>::iterator it = listaUnidades.begin();
            it != listaUnidades.end();
                ++it
     ){
          m_ui->unidad->addItem(QString(it->second.c_str()), QVariant::QVariant(it->first));
    }
}

SeleccionarUnidad::~SeleccionarUnidad()
{
    delete m_ui;
}

void SeleccionarUnidad::changeEvent(QEvent *e)
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

void SeleccionarUnidad::on_buttonBox_accepted()
{
    QString unidadRecibe=m_ui->unidad->currentText();
    Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->IDUnidad);
    idUnidad=QString::number(servicioPersistencia->oidUnidad(unidadRecibe));
}

void SeleccionarUnidad::on_buttonBox_rejected()
{
    this->close();
}

QString SeleccionarUnidad::getIdUnidad(){
    return this->idUnidad;
}
