#include "trasladoactivofijo.h"
#include "ui_trasladoactivofijo.h"

TrasladoActivoFijo::TrasladoActivoFijo(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::TrasladoActivoFijo)
{
    m_ui->setupUi(this);
}

TrasladoActivoFijo::~TrasladoActivoFijo()
{
    delete m_ui;
}

void TrasladoActivoFijo::changeEvent(QEvent *e)
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
