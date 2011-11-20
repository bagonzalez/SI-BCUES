#include "agregarusuario.h"
#include "ui_agregarusuario.h"

agregarUsuario::agregarUsuario(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::agregarUsuario)
{
    m_ui->setupUi(this);
}

agregarUsuario::~agregarUsuario()
{
    delete m_ui;
}

void agregarUsuario::changeEvent(QEvent *e)
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
