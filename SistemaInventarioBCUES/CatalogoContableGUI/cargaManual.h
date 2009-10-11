
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

#ifndef CARGAMANUAL_H
#define CARGAMANUALL_H
#include "ui_cargaManual.h"

#include "../ModuloContable/ModuloContable_global.h"
#include "../ModuloContable/modulocontable.h"
#include "../ModuloCatalogo/ModuloCatalogo_global.h"
#include "../ModuloCatalogo/modulocatalogo.h"


using namespace contabilidad;


class CargaManual: public QDialog
{
	Q_OBJECT

public:
	CargaManual(RegistroSistemaContable *, int );
	void crearPalo();
	QString getNombreCuenta();
	float getImporte();
	bool getCargo();
        void crearPaloR(string nombreCuenta, QList<QTreeWidgetItem *> *lista, QTreeWidgetItem *padre );

	RegistroSistemaContable *registro;
	int numeroTran, fila, columna, partidaDoble;
	float importe;
        string cuenta;
	bool cancelada;




public slots:
	void on_catalogo_currentItemChanged ();
	void on_importe_valueChanged();
	void on_buttonBox_rejected();
	void on_partidaDoble_pressed();
	void on_aplicar_pressed();
	void on_finalizar_pressed();
	void on_eliminar_pressed();

public:
	Ui::cargaManual ui;
};

#endif
