#ifndef CONSULTABIENES_H
#define CONSULTABIENES_H

#include <QDialog>
#include <CatalogoActivoFijoGUI/catalogoactivofijogui.h>


#include "../../ModuloContable/ModuloContable_global.h"
#include "../../ModuloContable/modulocontable.h"
#include "../../ModuloCatalogo/ModuloCatalogo_global.h"
#include "../../ModuloCatalogo/modulocatalogo.h"
#include "../../Basico/Basico_global.h"
#include "../../Basico/basico.h"
#include "../../ModuloInventario/ModuloInventario_global.h"
#include "../../ModuloInventario/moduloinventario.h"


namespace Ui {
    class ConsultaBienes;
}

class ConsultaBienes : public QDialog {
    Q_OBJECT
public:
    ConsultaBienes( moduloinventario::RegistroCatalogo *reg, contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, InventarioActivoFijo *_inventario, QWidget *parent = 0);
    ~ConsultaBienes();
    int getBienSeleccionado();
    void completer();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ConsultaBienes *ui;

    RegistroCatalogo *registroCatalogo;
    RegistroSistemaContable *registroContable;
    RegistroSistemaContable *regEspecificos;
    Registro  *regBasico;
    InventarioActivoFijo *inventario;
    int idInvAF;
    int idBienSeleccionado;

    std::map<string, string> listaCodigosCuentas;



private slots:
    void on_nombreClase_editingFinished();
    void on_numeroCuenta_editingFinished();
    void on_seleccionarBien_pressed();
    void on_buttonBox_accepted();
    void on_btmBuscarClases_pressed();
    void iniciarConsulta();

};

#endif // CONSULTABIENES_H
