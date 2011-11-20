#ifndef CATALOGOCONTABLE_H
#define CATALOGOCONTABLE_H

#include <QtGui/QDialog>

#include "../ModuloContable/ModuloContable_global.h"
#include "../ModuloContable/modulocontable.h"
#include "cargaManual.h"
#include "nuevaCuenta.h"
#include "../CatalogoActivoFijoGUI/dialogobuscarcuenta.h"

namespace Ui {
    class CatalogoContable;
}

class CatalogoContable : public QDialog {
    Q_OBJECT
public:
    CatalogoContable(RegistroSistemaContable *reg, QWidget *parent = 0);
    ~CatalogoContable();

        void crearPalo();
        void crearPaloR(string nombreCuenta, QList<QTreeWidgetItem *> *lista , QTreeWidgetItem *);
        void CrearNuevaCuenta(string tipoCuenta);
        RegistroSistemaContable *registro;
        void closeEvent(QCloseEvent *event);

        QString getCodigoCuenta();
        QString getNombreCuenta();


public slots:
        void on_Catalogo_currentItemChanged();
        void on_transaccion_clicked();
        void on_pushButton_3_clicked();


private slots:
    void on_btmSeleccionar_clicked();
    void on_botonBuscar_clicked();
    void on_crearCuenta_clicked();
    void on_crearRubro_clicked();
    void on_crearEspecifico_clicked();

protected:
    void changeEvent(QEvent *e);


private:
    Ui::CatalogoContable *m_ui;
    QString codigo;
    QString nombreCuenta;
};

#endif // CATALOGOCONTABLE_H
