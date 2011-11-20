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

#ifndef TRASLADOBIENESBIBLIO_H
#define TRASLADOBIENESBIBLIO_H

#include <QtGui/QWidget>


#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"

#include "../../ModuloContable/ModuloContable_global.h"
#include "../../ModuloContable/modulocontable.h"
#include "../../ModuloCatalogo/ModuloCatalogo_global.h"
#include "../../ModuloCatalogo/modulocatalogo.h"
#include "../../Basico/Basico_global.h"
#include "../../Basico/basico.h"
#include "../../ModuloInventario/ModuloInventario_global.h"
#include "../../ModuloInventario/moduloinventario.h"

#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"

namespace Ui {
    class TrasladoBienesBiblio;
}

class TrasladoBienesBiblio : public QWidget {
    Q_OBJECT
public:
    TrasladoBienesBiblio(RegistroCatalogo *_regCatalogo, contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, InventarioActivoFijo *_inventario, QWidget *parent = 0);
    ~TrasladoBienesBiblio();

protected:
    void changeEvent(QEvent *e);    
    void completer();
    void limpiar();

public slots:

    void on_claseNO_editingFinished ();
    void on_correlativoNO_editingFinished ();
    void on_botonAgregarBien_pressed();
    void on_botonEliminarBien_pressed();
    void on_finalizarTransaccion_pressed();
    void on_cancelar_pressed();
    void on_anioInventario_currentIndexChanged(QString anio );

private:
    Ui::TrasladoBienesBiblio *m_ui;

    Persistencia  *servicioPersistencia;


     RegistroCatalogo *registroCatalogo;
    RegistroSistemaContable *registroContable;
    Registro  *regBasico;
    InventarioActivoFijo *inventario;

    int numeroTran, fila, columna;
    float valorTotal;

    QString anioInvSelecc;
    QString estadoTraslado;

    std::map<string, string> listaCodigosCuentas;
    std::map<string, string> listaCodigosEspecificos;
    std::map<string, string> listaTitulos;
    std::map<int, string> otrosTitulos;
    std::map<int, Bien*> listaBienes;
};

#endif // TRASLADOBIENESBIBLIO_H
