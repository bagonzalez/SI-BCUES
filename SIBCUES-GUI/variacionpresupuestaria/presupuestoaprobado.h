#ifndef PRESUPUESTOAPROBADO_H
#define PRESUPUESTOAPROBADO_H

#include <QtGui/QWidget>
#include <QSqlQuery>
#include <iostream>
#include <QMessageBox>

namespace Ui {
    class PresupuestoAprobado;
}

class PresupuestoAprobado : public QWidget {
    Q_OBJECT
public:
    PresupuestoAprobado(QWidget *parent = 0);
    ~PresupuestoAprobado();

protected:
    void changeEvent(QEvent *e);

public slots:
     void on_AgregarButton_clicked();
     void on_cancelarButton_clicked();
     void on_TotalAprobadoLinkButton_clicked();


private:
    Ui::PresupuestoAprobado *m_ui;
    int row,columna;
    float MontoTotal;
    std::string FuenteFinanciamiento;
    float total;
    QSqlQuery consulta;
    QString QCodigo, QDescripcion, QIdCuenta,QEjercicioFiscal,QFfinanciamiento,QIdEspecificacion,QMontoTotal,query;
};

#endif // PRESUPUESTOAPROBADO_H
