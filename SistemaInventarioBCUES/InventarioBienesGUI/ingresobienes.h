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

#ifndef INGRESOBIENES_H
#define INGRESOBIENES_H


#include "../../ModuloContable/ModuloContable_global.h"
#include "../../ModuloContable/modulocontable.h"
#include "../../ModuloCatalogo/ModuloCatalogo_global.h"
#include "../../ModuloCatalogo/modulocatalogo.h"
#include "../../Basico/Basico_global.h"
#include "../../Basico/basico.h"
#include "../../ModuloInventario/ModuloInventario_global.h"
#include "../../ModuloInventario/moduloinventario.h"

#include <QtGui/QWidget>

using namespace moduloinventario;
using namespace contabilidad;
using namespace basico;
namespace Ui {
    class ingresoBienes;
}

class ingresoBienes : public QWidget {
    Q_OBJECT
public:
    ingresoBienes( RegistroCatalogo *regCatalogo, contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, InventarioActivoFijo *_inventario, QWidget *parent = 0);
    ~ingresoBienes();

protected:
    void changeEvent(QEvent *e);

    void completer();    
    void limpiar();

public slots:
    void on_numeroCuenta_editingFinished ();
    void on_nombreClase_editingFinished ();
    void on_marca_currentIndexChanged ( );
    void on_botonAgregarBien_pressed();
    void on_botonEliminarBien_pressed();
    void on_nuevoBien_pressed();
    void on_finalizarTransaccion_pressed();


private:
    Ui::ingresoBienes *m_ui;
    RegistroCatalogo *registroCatalogo;
    RegistroSistemaContable *registroContable;
    Registro  *regBasico;
    InventarioActivoFijo *inventario;

    int numeroTran, fila, columna;
    float valorTotal;

    std::map<int, string> listaCodigosCuentas;
    std::map<int, string> listaCodigosEspecificos;
    std::map<string, string> listaTitulos;
    std::map<int, string> otrosTitulos;
};

#endif // INGRESOBIENES_H
