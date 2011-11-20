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

#ifndef CONSULTADESCARGOS_H
#define CONSULTADESCARGOS_H

#include <QtGui/QWidget>

#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"

namespace Ui {
    class ConsultaDescargos;
}

class ConsultaDescargos : public QWidget {
    Q_OBJECT
public:
    ConsultaDescargos(int idUnidad, QWidget *parent = 0);
    ~ConsultaDescargos();

public slots:
    virtual void on_generarReporte_pressed();
    void on_generarReporteMB_pressed();
    void on_salir_pressed();

protected:
    void changeEvent(QEvent *e);


private:
    Ui::ConsultaDescargos *m_ui;
};

#endif // CONSULTADESCARGOS_H