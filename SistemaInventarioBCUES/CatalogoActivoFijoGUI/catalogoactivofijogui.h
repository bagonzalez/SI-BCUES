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
#include "../ModuloContable/ModuloContable_global.h"
#include "../ModuloContable/modulocontable.h"
#include "../ModuloCatalogo/ModuloCatalogo_global.h"
#include "../ModuloCatalogo/modulocatalogo.h"


#include "ui_catalogoactivofijogui.h"

using namespace contabilidad;
using namespace moduloinventario;


class CatalogoActivoFijoGUI : public QWidget {
    Q_OBJECT
public:
    CatalogoActivoFijoGUI(moduloinventario::RegistroCatalogo *, contabilidad::RegistroSistemaContable *, QWidget *parent = 0);
    ~CatalogoActivoFijoGUI();
    void completer();

protected:
    void changeEvent(QEvent *e);

public slots:
    void on_descripcion_editingFinished();
    void on_marca_editingFinished();
    void on_botonGuardar_pressed();


private:
    Ui::CatalogoActivoFijoGUI *m_ui;    
    RegistroCatalogo *registroCatalogo;
    RegistroSistemaContable *registroContable;

};

#endif // CATALOGOACTIVOFIJOGUI_H
