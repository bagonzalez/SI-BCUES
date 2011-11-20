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

#ifndef PRIMERINICIO_H
#define PRIMERINICIO_H

#include <QtGui/QWidget>
#include "../../ModuloContable/ModuloContable_global.h"
#include "../../ModuloContable/modulocontable.h"
#include "../../ModuloCatalogo/ModuloCatalogo_global.h"
#include "../../ModuloCatalogo/modulocatalogo.h"
#include "../../Basico/Basico_global.h"
#include "../../Basico/basico.h"
#include "../../ModuloInventario/ModuloInventario_global.h"
#include "../../ModuloInventario/moduloinventario.h"

#include "seleccionarunidad.h"

namespace Ui {
    class PrimerInicio;
}

class PrimerInicio : public QWidget {
    Q_OBJECT
public:
    PrimerInicio(RegistroCatalogo *_regCatalogo, contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, InventarioActivoFijo *_inventario, QWidget *parent = 0);
    ~PrimerInicio();   

public slots:
    void on_botonAceptar_clicked();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::PrimerInicio *m_ui;
    basico::Registro  *registroBasico;

    RegistroCatalogo *registroCatalogo;
    RegistroSistemaContable *registroContable;
    InventarioActivoFijo *inventario;

    bool configuracionNueva;

private slots:
    void on_btnExisteConf_clicked();
    void on_btnNuevaConf_clicked();    
    void on_botonCancelar_clicked();
};

#endif // PRIMERINICIO_H
