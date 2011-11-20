#ifndef SELECCIONARUNIDAD_H
#define SELECCIONARUNIDAD_H

#include <QtGui/QDialog>

namespace Ui {
    class SeleccionarUnidad;
}

class SeleccionarUnidad : public QDialog {
    Q_OBJECT
public:
    SeleccionarUnidad(int idUnidad, QWidget *parent = 0);
    ~SeleccionarUnidad();    
    QString getIdUnidad();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SeleccionarUnidad *m_ui;
    QString idUnidad;
    int IDUnidad;

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
};

#endif // SELECCIONARUNIDAD_H
