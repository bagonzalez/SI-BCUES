#ifndef MANTTOINVENTARIO_H
#define MANTTOINVENTARIO_H


#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>
#include <QModelIndex>
#include <QDialog>

namespace Ui {
    class ManttoInventario;
}

class Persistencia;

class ManttoInventario : public QDialog
{
    Q_OBJECT

public:
    explicit ManttoInventario(int idUnidad, QWidget *parent = 0);
    ~ManttoInventario();
    void crearTabla();

private slots:
    void on_botonMenos_clicked();
    void on_botonAgregar_clicked();
    void on_modeloTabla_activated(QModelIndex index);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ManttoInventario *ui;
    Persistencia *servicioPersistencia;
    int idUnidad;
};

#endif // MANTTOINVENTARIO_H
