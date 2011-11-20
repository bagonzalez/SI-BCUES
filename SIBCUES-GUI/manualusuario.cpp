#include "manualusuario.h"
#include "ui_manualusuario.h"

manualUsuario::manualUsuario(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::manualUsuario)
{
    m_ui->setupUi(this);

}

manualUsuario::~manualUsuario()
{
    delete m_ui;
}

void manualUsuario::changeEvent(QEvent *e)
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
