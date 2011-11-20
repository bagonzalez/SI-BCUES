/***************************************************************************
 *   Copyright (C) 2009 by Bruno Gonzalez                                  *
 *   El Salvador                                                           *
 *   bruno2d@linux.ues.edu.sv                                              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifndef CATALOGOACTIVOFIJOGUI_H
#define CATALOGOACTIVOFIJOGUI_H

#include <QtGui/QWidget>
#include <QTreeWidgetItem>
#include "../ModuloContable/ModuloContable_global.h"
#include "../ModuloContable/modulocontable.h"
#include "../ModuloCatalogo/ModuloCatalogo_global.h"
#include "../ModuloCatalogo/modulocatalogo.h"
#include "../Basico/Basico_global.h"
#include "../Basico/basico.h"
#include "dialogobuscarcuenta.h"

#include "ui_catalogoactivofijogui.h"


#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"


using namespace contabilidad;
using namespace moduloinventario;
using namespace basico;

class CatalogoActivoFijoGUI : public QDialog {
    Q_OBJECT
public:
    CatalogoActivoFijoGUI(moduloinventario::RegistroCatalogo *, contabilidad::RegistroSistemaContable *, basico::Registro  *registroBasico, QWidget *parent = 0);
    ~CatalogoActivoFijoGUI();
    void completer();

    QString getMadre();
    QString getClase();

protected:
    void changeEvent(QEvent *e);
    void desactivar(bool activar);
    void limpiar();
    void crearPalo();
    void crearPaloR(string nombreCuenta, QList<QTreeWidgetItem *> *lista , QTreeWidgetItem *);


public slots:

    void on_botonGuardar_pressed();
    void on_botonNuevo_pressed();
    void on_botonGuardarBiblio_pressed();
    void on_numeroCuenta_editingFinished ();    
    void on_nombreClase_editingFinished ();
    void on_claseBiblio_editingFinished ();
    void on_anioInventario_currentIndexChanged ( );


private:
    Ui::CatalogoActivoFijoGUI *m_ui;    
    RegistroCatalogo *registroCatalogo;
    RegistroSistemaContable *registroContable;
    basico::Registro *regBasico;
    std::map<string, string> listaCodigosCuentas;
    std::map<string, string> listaCodigosEspecificos;
    std::map<string, string> listaTitulos;
    std::map<int, string> otrosTitulos;
    Persistencia *servicioPersistencia;

    QString madre;
    QString clase;


private slots:
    void on_pushButton_clicked();
    void on_btmSeleccionar_clicked();
    void on_btmBuscar_clicked();
    void on_catalogoInventario_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);
};

#endif // CATALOGOACTIVOFIJOGUI_H
