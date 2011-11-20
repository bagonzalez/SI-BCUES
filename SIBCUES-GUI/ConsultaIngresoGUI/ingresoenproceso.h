#ifndef INGRESOENPROCESO_H
#define INGRESOENPROCESO_H

#include <QDialog>

#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>
#include <QList>
#include <QTableWidgetItem>
#include <QSqlQuery>

namespace Ui {
    class IngresoenProceso;
}

class IngresoenProceso : public QDialog {
    Q_OBJECT
public:
    IngresoenProceso(int idUnidad, QWidget *parent = 0);
    ~IngresoenProceso();

    int getIdIngreso();
    QList<QTableWidgetItem *>  getListaItems();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::IngresoenProceso *ui;
    int idIngreso;
    QList<QTableWidgetItem *> listaItem;

private slots:    
    void on_btmSeleccionar_pressed();
};

#endif // INGRESOENPROCESO_H
