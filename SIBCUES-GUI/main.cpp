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

#include <QtGui/QApplication>
#include <QSqlDatabase>
#include <QSplashScreen>
 #include <QDesktopWidget>
#include "../ModuloContable/ModuloContable_global.h"
#include "../ModuloContable/modulocontable.h"
#include "../ModuloCatalogo/ModuloCatalogo_global.h"
#include "../ModuloCatalogo/modulocatalogo.h"
#include "../Basico/Basico_global.h"
#include "../Basico/basico.h"
#include "../ModuloInventario/ModuloInventario_global.h"
#include "../ModuloInventario/moduloinventario.h"
#include "../Persistencia/Persistencia_global.h"
#include "../Persistencia/persistencia.h"


using namespace contabilidad;
using namespace moduloinventario;
using namespace basico;


#include "VentanaPrincipalContables.h"

int main(int argc, char *argv[])
{
     QApplication app(argc, argv);

     Q_INIT_RESOURCE(ContablesPrincipal);
     Q_INIT_RESOURCE(recursosIconos);

     QPixmap pixmap(":/Iconos/images/SIBCUES.png");

      QSplashScreen *splash=new  QSplashScreen::QSplashScreen(pixmap);

      splash->show();

      splash->setWindowModality(Qt::ApplicationModal);
      splash->showMessage("Cargando Modulos", Qt::AlignLeft, Qt::white);

      basico::Registro *registroBasico=new Registro();
      RegistroCatalogo::RegistroCatalogo *regCatalogo;//=new RegistroCatalogo(usuario);
      moduloinventario::InventarioActivoFijo *inventario=new InventarioActivoFijo();
/*
    //Creamos una especificacion de Activo Fijo
    contabilidad::Subcuenta *cuenta=reg->crearSubCuenta("Mobiliario y equipo de Oficina", "080", "Hola");

    int codIng=regCatalogo->crearIngreso(fech, tiempo);
    regCatalogo->crearEspecActivoF(cuenta, codIng, "080");
    regCatalogo->introducirInformacion(codIng, "CPU/MOUSE/TECLADO", "HP", "HP1");

    //Podemos hacer una transaccion contable con esa clase
    int cod=reg->crearTransaccion(fech);
    reg->introducirInformacionTransaccion(200, true, "080",cod);
    reg->introducirInformacionTransaccion(200, false, "Equipos Informticos",cod);    
*/
    splash->showMessage("Creando la ventana principal", Qt::AlignLeft, Qt::white);
    QDesktopWidget *desktop = app.desktop() ;

    VentanaPrincipalContables mainWin(regCatalogo, registroBasico, inventario, splash, desktop);


    mainWin.setGeometry(        QStyle::alignedRect( Qt::LeftToRight,
                                Qt::AlignCenter,
                                mainWin.size(),
                                desktop->availableGeometry()
                        ));

    splash->finish(&mainWin);        
    return app.exec();
}
