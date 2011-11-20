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
#include <QWebView>
#include <QSplashScreen>
#include <QDesktopWidget>
#include "ui_VentanaPrincipalContables.h"
#include "UsuariosGUI/accesousuario.h"
#include "CatalogoContableGUI/catalogocontable.h"
#include "CatalogoActivoFijoGUI/catalogoactivofijogui.h"
#include "CatalogoActivoFijoGUI/marcas.h"
#include "ConsultaIngresoGUI/consultaingreso.h"
#include "ConsultaIngresoGUI/ingresoenproceso.h"
#include "ConsultaDescargos/consultadescargos.h"
#include "ConsultaDescargos/descargosproceso.h"
#include "ConsultaTraslados/consultatraslados.h"
#include "InventarioBienesGUI/ingresobienes.h"
#include "InventarioBienesGUI/ingresobienesbiblio.h"
#include "InventarioBienesGUI/descargobienesmb.h"
#include "InventarioBienesGUI/descargobienes.h"
#include "InventarioBienesGUI/trasladoactivofijo.h"
#include "InventarioBienesGUI/trasladobienesbiblio.h"
#include "InventarioBienesGUI/sectoresgui.h"
#include "InventarioBienesGUI/mantenimientotitulo.h"
#include "InventarioBienesGUI/consultabienes.h"
#include "InventarioBienesGUI/manttoinventario.h"
#include "bienesporsector.h"
#include "manualusuario.h"
#include "gestionUsuarios/mainwindow.h"
#include "inicio/primerinicio.h"
#include "progresoreporte.h"


#include "variacionpresupuestaria/variacionpresupuestaria.h"
#include "variacionpresupuestaria/crearvariacion.h"
#include "variacionpresupuestaria/presupuestoaprobado.h"
#include "variacionpresupuestaria/verdocumentovariacion.h"
#include "variacionpresupuestaria/razonamiento.h"

#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"

class VentanaPrincipalContables: public QMainWindow
{
        Q_OBJECT
	private:
                CatalogoContable *catalogo;
                CatalogoActivoFijoGUI *catalogoAF;
                AccesoUsuario *accesoUsuario;
                ConsultaIngreso *consultaIngresoBien;
                ConsultaDescargos *consultaDescargo;
                consultaTraslados *consultaTraslado;
                PrimerInicio *primerInicio;                
                DescargoBienes *descargoBienesAF;
                 TrasladoActivoFijo *traslado;
                 TrasladoBienesBiblio *trasladoMB;
                 VariacionPresupuestaria *variacionPresupuestacia;

                 MainWindow *usuariosAdmin;

                 QDesktopWidget *desktop;

                 manualUsuario *manual;

                 IngresoBienesBiblio *ingresoBiblio;
                 DescargoBienesMB *decargoBienesMB;
                //AcercaDe *acercaDe;


	public:
         VentanaPrincipalContables( RegistroCatalogo *, basico::Registro  *registroBasico, moduloinventario::InventarioActivoFijo *inventario, QSplashScreen *splash, QDesktopWidget *desktop);
	 virtual ~VentanaPrincipalContables();
         //RegistroSistemaContable *registro;
         RegistroCatalogo *registroCatalogo;
         InventarioActivoFijo *inventario;        
         void iniciarConfiguracion();


	private slots:
		virtual void on_actionContabilidad_activated();
		virtual void on_actionSistema_de_Costeo_activated();
                virtual void on_actionLogear_activated();
                virtual void on_actionMaterialBilbliografico_activated();
                virtual void on_actionConsultaIngreso_activated();
                void on_actionConsulta_de_Descargos_de_Bienes_activated();
                void on_actionConsulta_Traslado_de_Bienes_activated();
                void on_actionTrasladoActivoFijo_activated();
                void on_actionIngresoActivoFijo_activated();
                void on_actionDescargo_activated();
                void on_actionIngresoBibliografico_activated();
                void on_actionDescargo_2_activated();
                void on_actionTraslado_activated();
                void on_catalogoActivoFijo_activated();
                void on_catalogoCuenta_activated();
                void on_consolidadoAF_activated();
                void on_actionConsolidade_de_Material_Bibliografico_activated();
                void on_actionUsuario_activated();
                void on_actionGestionUsuario_activated();
                void on_actionManual_usuario_activated();
                void on_actionPresupuesto_activated();
                void on_actionMarcas_activated();
                void on_actionSectores_o_dependencias_activated();
                void on_actionTitulos_activated();
                void on_actionIngresos_en_procesos_activated();
                void on_actionConsulta_de_Bienes_activated();
                void on_actionDescargos_en_Proceso_activated();
                void on_actionInventarios_activated();
                void on_actionReporte_por_sector_activated();




	private:
                Ui::MainWindowSistemaInventario ui;
                basico::Registro *regBasico;               
};

#endif



