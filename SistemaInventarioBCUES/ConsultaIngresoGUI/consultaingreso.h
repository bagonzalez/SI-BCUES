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

#ifndef CONSULTAINGRESO_H
#define CONSULTAINGRESO_H

#include <QtGui/QWidget>



#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"


namespace Ui {
    class ConsultaIngreso;
}

class ConsultaIngreso : public QWidget {
    Q_OBJECT
public:
    ConsultaIngreso(QWidget *parent = 0);
    ~ConsultaIngreso();

public slots:
    virtual void on_generarReporte_pressed();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ConsultaIngreso *m_ui;
};

#endif // CONSULTAINGRESO_H
