#ifndef DIALOGOBUSCARCUENTA_H
#define DIALOGOBUSCARCUENTA_H

#include <QtGui/QDialog>
#include <QTableWidgetItem>

#include "../ModuloContable/ModuloContable_global.h"
#include "../ModuloContable/modulocontable.h"

namespace Ui {
    class dialogoBuscarCuenta;
}
using namespace contabilidad;

class dialogoBuscarCuenta : public QDialog {
    Q_OBJECT
public:
    dialogoBuscarCuenta( RegistroSistemaContable *regC, bool codigo, QWidget *parent = 0);
    ~dialogoBuscarCuenta();
    void crearTablaR(string nombreCuenta, int fila, QString nombreMadre);
    string getNombreCuenta();
    string getMadre();


protected:
    void changeEvent(QEvent *e);

private:
    Ui::dialogoBuscarCuenta *m_ui;
    contabilidad::RegistroSistemaContable *regContable;    
    string nombreCuenta;
    string nombreMadre;
    bool codigo;

private slots:
    void on_tablaResultado_itemSelectionChanged();
    void on_btmSeleccionar_clicked();
    void on_btmBuscar_clicked();
};

#endif // DIALOGOBUSCARCUENTA_H
