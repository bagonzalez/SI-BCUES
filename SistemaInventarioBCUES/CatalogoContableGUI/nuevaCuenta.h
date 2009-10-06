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

#ifndef NUEVACUENTA_H
 #define NUEVACUENTA_H

#include "ui_nuevaCuenta.h"


class NuevaCuenta: public QDialog
 {
     Q_OBJECT
 private:
    QString nombreCuenta;
    QString descripcion;
    QString codigo;
    bool    manual;

 public:
     NuevaCuenta(QDialog *parent = 0);
     QString getNombreCuenta();
     QString getDescripcion();
     QString getCodigoManual();
     bool getManual();

 private slots:
     void on_buttonBox_accepted();
     void on_buttonBox_rejected();
     void on_codManual_clicked ();

 private:
	 Ui::DialogoNuevaCuenta ui;
 };

 #endif

