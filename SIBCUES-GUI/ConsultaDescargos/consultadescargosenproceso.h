#ifndef CONSULTADESCARGOSENPROCESO_H
#define CONSULTADESCARGOSENPROCESO_H

#include <QDialog>

namespace Ui {
    class ConsultaDescargosenProceso;
}

class ConsultaDescargosenProceso : public QDialog {
    Q_OBJECT
public:
    ConsultaDescargosenProceso(QWidget *parent = 0);
    ~ConsultaDescargosenProceso();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ConsultaDescargosenProceso *ui;
};

#endif // CONSULTADESCARGOSENPROCESO_H
