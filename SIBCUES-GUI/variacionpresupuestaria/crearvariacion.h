#ifndef CREARVARIACION_H
#define CREARVARIACION_H

#include <QtGui/QWidget>
#include <QSqlQuery>
#include <iostream>
#include <QMessageBox>

namespace Ui {
    class CrearVariacion;
}

class CrearVariacion : public QWidget {
    Q_OBJECT
private:

public:

    CrearVariacion(QWidget *parent = 0);
    virtual ~CrearVariacion();


public slots:
     void on_AgregarButton_clicked();
     void on_CancelarButton_clicked();
     void on_obtenerSolicitadoLinkButton_clicked();



protected:
    void changeEvent(QEvent *e);


private:
    Ui::CrearVariacion *m_ui;
    int row,columna;
    float MontoTotal;
    std::string FuenteFinanciamiento;
    float total;
    QSqlQuery consulta;
    QString consulta1, consulta2;
    QString QCodigo, QDescripcion, QIdCuenta,QEjercicioFiscal,QFfinanciamiento,QFuenteFinanciamiento,query,QMontoTotal;
    QStringList MontoPSolicitado;




};
#endif // CREARVARIACION_H
