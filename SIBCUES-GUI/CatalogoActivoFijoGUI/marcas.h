#ifndef MARCAS_H
#define MARCAS_H

#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>
#include <QModelIndex>
#include <QtGui/QDialog>

namespace Ui {
    class marcas;
}

class marcas : public QDialog {
    Q_OBJECT
public:
    marcas(int idUnidad, QWidget *parent = 0);
    ~marcas();
    int getIDMarca();
    int getIDModelo();    
    QString getMarca();
    QString getModelo();

    void insertRow();
    void deleteRow();
    void modificarFila();
    void updateActions();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::marcas *m_ui;
    int idMarca, idModelo;
    QString marca, modelo;

private slots:    

    void on_btmAgregarModelo_clicked();
    void on_btmAgregarMarca_clicked();
    void on_tablaModelo_activated(QModelIndex index);
    void on_tablaMarcas_activated(QModelIndex index);
    void on_btmCancelar_clicked();
    void on_btmSeleccionar_clicked();

    void on_insertRowAction_triggered()
     { insertRow(); }
    void on_deleteRowAction_triggered()
     { deleteRow(); }

    void on_modificarRowAction_triggered()
     { modificarFila(); }


    void currentChanged() { updateActions(); }


};

#endif // MARCAS_H
