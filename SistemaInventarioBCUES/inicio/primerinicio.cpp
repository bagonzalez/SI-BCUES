#include <QFile>
#include <QVariant>
#include <QTextStream>

#include "primerinicio.h"
#include "ui_primerinicio.h"

PrimerInicio::PrimerInicio(basico::Registro  *_registroBasico, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::PrimerInicio)
{
    m_ui->setupUi(this);
    this->registroBasico=_registroBasico;
}

PrimerInicio::~PrimerInicio()
{
    delete m_ui;
}

void PrimerInicio::changeEvent(QEvent *e)
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


void PrimerInicio::on_botonAceptar_clicked(){
   string nombreUnidad=this->m_ui->nombreUnidad->text().toStdString();
   string codigoP1=this->m_ui->codigoUnidad->text().toStdString();
   string codigoP2=this->m_ui->lineaUnidad->text().toStdString();

   string nombreUsuario=this->m_ui->nombreUsuario->text().toStdString();
   string apellidoUsuario=this->m_ui->apelldosUsuario->text().toStdString();
   string cuenta=this->m_ui->cuenta->text().toStdString();
   string password=this->m_ui->password->text().toStdString();

   int idUnidad=this->registroBasico->crearUnidad(codigoP1, codigoP2, nombreUnidad);
   this->registroBasico->crearUsuario(nombreUsuario, apellidoUsuario, cuenta, password, basico::administrador);

   QString idUni=QVariant::QVariant(idUnidad).toString();

   QFile file("configuacion.conf");

    if (!file.open(QFile::WriteOnly | QFile::Text)) {

    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << idUni;
    QApplication::restoreOverrideCursor();
    file.close();
    this->close();
}
