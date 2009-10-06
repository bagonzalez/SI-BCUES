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

#ifndef VENTANAPRINCIPALCONTABLES_H
#define VENTANAPRINCIPALCONTABLES_H

#include <QMainWindow>
#include "../ModuloContable/ModuloContable/headers/RegistroSistemaContable.h"

#include "ui_VentanaPrincipalContables.h"
#include "CatalogoContableGUI/contgeneral.h"
#include "CatalogoActivoFijoGUI/catalogoactivofijogui.h"



class VentanaPrincipalContables: public QMainWindow
{
        Q_OBJECT
	private:
                ContGeneral *catalogo;
                CatalogoActivoFijoGUI *catalogoAF;
                //AcercaDe *acercaDe;


	public:
         VentanaPrincipalContables(RegistroSistemaContable*, RegistroCatalogo * );
	 virtual ~VentanaPrincipalContables();
	 RegistroSistemaContable *registro;
         RegistroCatalogo *registroCatalogo;


	private slots:
		virtual void on_actionContabilidad_activated();
		virtual void on_actionSistema_de_Costeo_activated();
		virtual void on_actionAcerca_de_activated();


	private:
		Ui::MainWindowSistemaContable ui;
};

#endif



