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

/*********************************************************************
*
* Este es el fichero de cabezera que servira para la cont. General
*
*********************************************************************/

#ifndef CONTGENERAL_H
#define CONTGENERAL_H
#include <QSqlQuery>
#include "ui_contgeneral.h"

#include "../ModuloContable/ModuloContable_global.h"
#include "../ModuloContable/modulocontable.h"
#include "cargaManual.h"

using namespace contabilidad;

class ContGeneral : public QMainWindow
{
	Q_OBJECT

public:
	ContGeneral(RegistroSistemaContable *);
	void crearPalo();
        void crearPaloR(string nombreCuenta, QList<QTreeWidgetItem *> *lista , QTreeWidgetItem *);
	void CrearNuevaCuenta(bool cat);
        RegistroSistemaContable *registro;
	

public slots: 
	void on_Catalogo_currentItemChanged();
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_transaccion_clicked();
        void on_pushButton_3_clicked();
	
private:
 Ui::ContGeneral ui;
};

#endif
