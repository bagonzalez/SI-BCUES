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

#ifndef ACCESOUSUARIO_H
#define ACCESOUSUARIO_H

#include <QtGui/QWidget>
#include <QMainWindow>
#include "../Basico/Basico_global.h"
#include "../Basico/basico.h"


using namespace basico;
namespace Ui {
    class AccesoUsuario;
}

class AccesoUsuario : public QWidget {
    Q_OBJECT
public:
    AccesoUsuario(basico::Registro *registroBasico, QMainWindow *, QWidget *parent = 0);
    ~AccesoUsuario();

    bool getAceptado();

public slots:
    void on_boton_accepted();
    void on_boton_rejected();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AccesoUsuario *m_ui;
    string login;
    string password;
    bool aceptado;
    basico::Registro *registroBasico;
    QMainWindow *ventana;



};

#endif // ACCESOUSUARIO_H
