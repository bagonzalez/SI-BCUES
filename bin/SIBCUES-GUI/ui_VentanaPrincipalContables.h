/********************************************************************************
** Form generated from reading UI file 'VentanaPrincipalContables.ui'
**
** Created: Thu Apr 21 08:48:21 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAPRINCIPALCONTABLES_H
#define UI_VENTANAPRINCIPALCONTABLES_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QDockWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowSistemaInventario
{
public:
    QAction *actionContabilidad;
    QAction *actionSistema_de_Costeo;
    QAction *actionLogear;
    QAction *actionSalir;
    QAction *actionConsultaIngreso;
    QAction *actionManual_usuario;
    QAction *actionAcerca_de;
    QAction *actionEstado_de_Capital;
    QAction *actionEstado_de_Resultado;
    QAction *catalogoActivoFijo;
    QAction *catalogoCuenta;
    QAction *consolidadoAF;
    QAction *actionVentas;
    QAction *actionGestionUsuario;
    QAction *actionRespaldo_de_Datos;
    QAction *actionConfiguracion_Sistema;
    QAction *actionMostrar_Calendario;
    QAction *actionMaterialBilbliografico;
    QAction *actionIngresoActivoFijo;
    QAction *actionTrasladoActivoFijo;
    QAction *actionDescargo;
    QAction *actionIngresoBibliografico;
    QAction *actionTraslado;
    QAction *actionDescargo_2;
    QAction *actionConsulta_de_Descargos_de_Bienes;
    QAction *actionConsulta_Traslado_de_Bienes;
    QAction *actionConsolidade_de_Material_Bibliografico;
    QAction *actionUsuario;
    QAction *actionPresupuesto;
    QAction *actionTransacciones;
    QAction *actionUsuarios;
    QAction *actionMarcas;
    QAction *actionTitulos;
    QAction *actionSectores_o_dependencias;
    QAction *actionIngresos_en_procesos;
    QAction *actionConsulta_de_Bienes;
    QAction *actionDescargos_en_Proceso;
    QAction *actionInventarios;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_6;
    QMenuBar *menubar;
    QMenu *menuInventario;
    QMenu *menuActivo_Fijo;
    QMenu *menuMaterial_Bibliografico;
    QMenu *menu_Ventas;
    QMenu *menuEstados_Financieros;
    QMenu *menuEstados_Financieros_2;
    QMenu *menu_Mantenimiento_2;
    QMenu *menu_Mantenimiento;
    QMenu *menu_Ayuda;
    QToolBar *toolBar;
    QStatusBar *statusbar;
    QDockWidget *contenedorTransacciones;
    QWidget *dockWidgetContents_7;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *historialTransacciones;
    QDockWidget *contieneCalendario;
    QWidget *div2;
    QCalendarWidget *calendarWidget;
    QDockWidget *usuariosConectados;
    QWidget *dockWidgetContents_2;
    QTreeWidget *treeWidget;

    void setupUi(QMainWindow *MainWindowSistemaInventario)
    {
        if (MainWindowSistemaInventario->objectName().isEmpty())
            MainWindowSistemaInventario->setObjectName(QString::fromUtf8("MainWindowSistemaInventario"));
        MainWindowSistemaInventario->setWindowModality(Qt::NonModal);
        MainWindowSistemaInventario->setEnabled(true);
        MainWindowSistemaInventario->resize(978, 700);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindowSistemaInventario->sizePolicy().hasHeightForWidth());
        MainWindowSistemaInventario->setSizePolicy(sizePolicy);
        MainWindowSistemaInventario->setMinimumSize(QSize(978, 700));
        MainWindowSistemaInventario->setMaximumSize(QSize(6587412, 6859745));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/blockdevice.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowSistemaInventario->setWindowIcon(icon);
        MainWindowSistemaInventario->setLocale(QLocale(QLocale::Spanish, QLocale::ElSalvador));
        MainWindowSistemaInventario->setDocumentMode(false);
        MainWindowSistemaInventario->setDockNestingEnabled(true);
        MainWindowSistemaInventario->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks);
        actionContabilidad = new QAction(MainWindowSistemaInventario);
        actionContabilidad->setObjectName(QString::fromUtf8("actionContabilidad"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/calc.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionContabilidad->setIcon(icon1);
        actionSistema_de_Costeo = new QAction(MainWindowSistemaInventario);
        actionSistema_de_Costeo->setObjectName(QString::fromUtf8("actionSistema_de_Costeo"));
        actionSistema_de_Costeo->setIcon(icon);
        actionLogear = new QAction(MainWindowSistemaInventario);
        actionLogear->setObjectName(QString::fromUtf8("actionLogear"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/empleados.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLogear->setIcon(icon2);
        actionSalir = new QAction(MainWindowSistemaInventario);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/iconos/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSalir->setIcon(icon3);
        actionConsultaIngreso = new QAction(MainWindowSistemaInventario);
        actionConsultaIngreso->setObjectName(QString::fromUtf8("actionConsultaIngreso"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConsultaIngreso->setIcon(icon4);
        actionManual_usuario = new QAction(MainWindowSistemaInventario);
        actionManual_usuario->setObjectName(QString::fromUtf8("actionManual_usuario"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionManual_usuario->setIcon(icon5);
        actionAcerca_de = new QAction(MainWindowSistemaInventario);
        actionAcerca_de->setObjectName(QString::fromUtf8("actionAcerca_de"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/iconos/trabajador.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAcerca_de->setIcon(icon6);
        actionEstado_de_Capital = new QAction(MainWindowSistemaInventario);
        actionEstado_de_Capital->setObjectName(QString::fromUtf8("actionEstado_de_Capital"));
        actionEstado_de_Resultado = new QAction(MainWindowSistemaInventario);
        actionEstado_de_Resultado->setObjectName(QString::fromUtf8("actionEstado_de_Resultado"));
        catalogoActivoFijo = new QAction(MainWindowSistemaInventario);
        catalogoActivoFijo->setObjectName(QString::fromUtf8("catalogoActivoFijo"));
        catalogoCuenta = new QAction(MainWindowSistemaInventario);
        catalogoCuenta->setObjectName(QString::fromUtf8("catalogoCuenta"));
        consolidadoAF = new QAction(MainWindowSistemaInventario);
        consolidadoAF->setObjectName(QString::fromUtf8("consolidadoAF"));
        actionVentas = new QAction(MainWindowSistemaInventario);
        actionVentas->setObjectName(QString::fromUtf8("actionVentas"));
        actionGestionUsuario = new QAction(MainWindowSistemaInventario);
        actionGestionUsuario->setObjectName(QString::fromUtf8("actionGestionUsuario"));
        actionRespaldo_de_Datos = new QAction(MainWindowSistemaInventario);
        actionRespaldo_de_Datos->setObjectName(QString::fromUtf8("actionRespaldo_de_Datos"));
        actionConfiguracion_Sistema = new QAction(MainWindowSistemaInventario);
        actionConfiguracion_Sistema->setObjectName(QString::fromUtf8("actionConfiguracion_Sistema"));
        actionMostrar_Calendario = new QAction(MainWindowSistemaInventario);
        actionMostrar_Calendario->setObjectName(QString::fromUtf8("actionMostrar_Calendario"));
        actionMaterialBilbliografico = new QAction(MainWindowSistemaInventario);
        actionMaterialBilbliografico->setObjectName(QString::fromUtf8("actionMaterialBilbliografico"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/ico_alpha_5_32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMaterialBilbliografico->setIcon(icon7);
        actionIngresoActivoFijo = new QAction(MainWindowSistemaInventario);
        actionIngresoActivoFijo->setObjectName(QString::fromUtf8("actionIngresoActivoFijo"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/ico_alpha_RegistryDefrag_32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIngresoActivoFijo->setIcon(icon8);
        actionTrasladoActivoFijo = new QAction(MainWindowSistemaInventario);
        actionTrasladoActivoFijo->setObjectName(QString::fromUtf8("actionTrasladoActivoFijo"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Iconos/iconos/PNG/Caargo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTrasladoActivoFijo->setIcon(icon9);
        actionDescargo = new QAction(MainWindowSistemaInventario);
        actionDescargo->setObjectName(QString::fromUtf8("actionDescargo"));
        actionIngresoBibliografico = new QAction(MainWindowSistemaInventario);
        actionIngresoBibliografico->setObjectName(QString::fromUtf8("actionIngresoBibliografico"));
        actionTraslado = new QAction(MainWindowSistemaInventario);
        actionTraslado->setObjectName(QString::fromUtf8("actionTraslado"));
        actionDescargo_2 = new QAction(MainWindowSistemaInventario);
        actionDescargo_2->setObjectName(QString::fromUtf8("actionDescargo_2"));
        actionConsulta_de_Descargos_de_Bienes = new QAction(MainWindowSistemaInventario);
        actionConsulta_de_Descargos_de_Bienes->setObjectName(QString::fromUtf8("actionConsulta_de_Descargos_de_Bienes"));
        actionConsulta_Traslado_de_Bienes = new QAction(MainWindowSistemaInventario);
        actionConsulta_Traslado_de_Bienes->setObjectName(QString::fromUtf8("actionConsulta_Traslado_de_Bienes"));
        actionConsolidade_de_Material_Bibliografico = new QAction(MainWindowSistemaInventario);
        actionConsolidade_de_Material_Bibliografico->setObjectName(QString::fromUtf8("actionConsolidade_de_Material_Bibliografico"));
        actionUsuario = new QAction(MainWindowSistemaInventario);
        actionUsuario->setObjectName(QString::fromUtf8("actionUsuario"));
        actionPresupuesto = new QAction(MainWindowSistemaInventario);
        actionPresupuesto->setObjectName(QString::fromUtf8("actionPresupuesto"));
        actionTransacciones = new QAction(MainWindowSistemaInventario);
        actionTransacciones->setObjectName(QString::fromUtf8("actionTransacciones"));
        actionUsuarios = new QAction(MainWindowSistemaInventario);
        actionUsuarios->setObjectName(QString::fromUtf8("actionUsuarios"));
        actionMarcas = new QAction(MainWindowSistemaInventario);
        actionMarcas->setObjectName(QString::fromUtf8("actionMarcas"));
        actionTitulos = new QAction(MainWindowSistemaInventario);
        actionTitulos->setObjectName(QString::fromUtf8("actionTitulos"));
        actionSectores_o_dependencias = new QAction(MainWindowSistemaInventario);
        actionSectores_o_dependencias->setObjectName(QString::fromUtf8("actionSectores_o_dependencias"));
        actionIngresos_en_procesos = new QAction(MainWindowSistemaInventario);
        actionIngresos_en_procesos->setObjectName(QString::fromUtf8("actionIngresos_en_procesos"));
        actionConsulta_de_Bienes = new QAction(MainWindowSistemaInventario);
        actionConsulta_de_Bienes->setObjectName(QString::fromUtf8("actionConsulta_de_Bienes"));
        actionDescargos_en_Proceso = new QAction(MainWindowSistemaInventario);
        actionDescargos_en_Proceso->setObjectName(QString::fromUtf8("actionDescargos_en_Proceso"));
        actionInventarios = new QAction(MainWindowSistemaInventario);
        actionInventarios->setObjectName(QString::fromUtf8("actionInventarios"));
        centralwidget = new QWidget(MainWindowSistemaInventario);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(30);
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/Iconos/iconos/PNG/Caargo.png")));

        horizontalLayout->addWidget(label_6);

        MainWindowSistemaInventario->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowSistemaInventario);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 978, 21));
        menuInventario = new QMenu(menubar);
        menuInventario->setObjectName(QString::fromUtf8("menuInventario"));
        menuActivo_Fijo = new QMenu(menuInventario);
        menuActivo_Fijo->setObjectName(QString::fromUtf8("menuActivo_Fijo"));
        menuMaterial_Bibliografico = new QMenu(menuInventario);
        menuMaterial_Bibliografico->setObjectName(QString::fromUtf8("menuMaterial_Bibliografico"));
        menu_Ventas = new QMenu(menubar);
        menu_Ventas->setObjectName(QString::fromUtf8("menu_Ventas"));
        menuEstados_Financieros = new QMenu(menubar);
        menuEstados_Financieros->setObjectName(QString::fromUtf8("menuEstados_Financieros"));
        menuEstados_Financieros_2 = new QMenu(menuEstados_Financieros);
        menuEstados_Financieros_2->setObjectName(QString::fromUtf8("menuEstados_Financieros_2"));
        menu_Mantenimiento_2 = new QMenu(menubar);
        menu_Mantenimiento_2->setObjectName(QString::fromUtf8("menu_Mantenimiento_2"));
        menu_Mantenimiento = new QMenu(menubar);
        menu_Mantenimiento->setObjectName(QString::fromUtf8("menu_Mantenimiento"));
        menu_Ayuda = new QMenu(menubar);
        menu_Ayuda->setObjectName(QString::fromUtf8("menu_Ayuda"));
        MainWindowSistemaInventario->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindowSistemaInventario);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setOrientation(Qt::Horizontal);
        toolBar->setIconSize(QSize(32, 32));
        MainWindowSistemaInventario->addToolBar(Qt::TopToolBarArea, toolBar);
        statusbar = new QStatusBar(MainWindowSistemaInventario);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowSistemaInventario->setStatusBar(statusbar);
        contenedorTransacciones = new QDockWidget(MainWindowSistemaInventario);
        contenedorTransacciones->setObjectName(QString::fromUtf8("contenedorTransacciones"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(contenedorTransacciones->sizePolicy().hasHeightForWidth());
        contenedorTransacciones->setSizePolicy(sizePolicy1);
        contenedorTransacciones->setMinimumSize(QSize(300, 250));
        contenedorTransacciones->setMaximumSize(QSize(500, 250));
        contenedorTransacciones->setAutoFillBackground(true);
        contenedorTransacciones->setFloating(false);
        contenedorTransacciones->setFeatures(QDockWidget::AllDockWidgetFeatures);
        contenedorTransacciones->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QString::fromUtf8("dockWidgetContents_7"));
        verticalLayoutWidget = new QWidget(dockWidgetContents_7);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 471, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        historialTransacciones = new QTableWidget(verticalLayoutWidget);
        if (historialTransacciones->columnCount() < 1)
            historialTransacciones->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        historialTransacciones->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (historialTransacciones->rowCount() < 4)
            historialTransacciones->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        historialTransacciones->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        historialTransacciones->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        historialTransacciones->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        historialTransacciones->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        historialTransacciones->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        historialTransacciones->setItem(1, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        historialTransacciones->setItem(2, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        historialTransacciones->setItem(3, 0, __qtablewidgetitem8);
        historialTransacciones->setObjectName(QString::fromUtf8("historialTransacciones"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(historialTransacciones->sizePolicy().hasHeightForWidth());
        historialTransacciones->setSizePolicy(sizePolicy2);
        historialTransacciones->setAlternatingRowColors(true);

        verticalLayout->addWidget(historialTransacciones);

        contenedorTransacciones->setWidget(dockWidgetContents_7);
        MainWindowSistemaInventario->addDockWidget(static_cast<Qt::DockWidgetArea>(8), contenedorTransacciones);
        contieneCalendario = new QDockWidget(MainWindowSistemaInventario);
        contieneCalendario->setObjectName(QString::fromUtf8("contieneCalendario"));
        contieneCalendario->setEnabled(true);
        sizePolicy1.setHeightForWidth(contieneCalendario->sizePolicy().hasHeightForWidth());
        contieneCalendario->setSizePolicy(sizePolicy1);
        contieneCalendario->setMinimumSize(QSize(290, 195));
        contieneCalendario->setMaximumSize(QSize(290, 195));
        contieneCalendario->setLayoutDirection(Qt::LeftToRight);
        contieneCalendario->setAutoFillBackground(false);
        contieneCalendario->setFloating(false);
        contieneCalendario->setFeatures(QDockWidget::AllDockWidgetFeatures);
        contieneCalendario->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        div2 = new QWidget();
        div2->setObjectName(QString::fromUtf8("div2"));
        calendarWidget = new QCalendarWidget(div2);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(0, 0, 272, 166));
        contieneCalendario->setWidget(div2);
        MainWindowSistemaInventario->addDockWidget(static_cast<Qt::DockWidgetArea>(2), contieneCalendario);
        usuariosConectados = new QDockWidget(MainWindowSistemaInventario);
        usuariosConectados->setObjectName(QString::fromUtf8("usuariosConectados"));
        usuariosConectados->setMinimumSize(QSize(300, 250));
        usuariosConectados->setMaximumSize(QSize(300, 250));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        treeWidget = new QTreeWidget(dockWidgetContents_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(0, 0, 291, 221));
        usuariosConectados->setWidget(dockWidgetContents_2);
        MainWindowSistemaInventario->addDockWidget(static_cast<Qt::DockWidgetArea>(8), usuariosConectados);

        menubar->addAction(menu_Mantenimiento->menuAction());
        menubar->addAction(menuInventario->menuAction());
        menubar->addAction(menu_Ventas->menuAction());
        menubar->addAction(menuEstados_Financieros->menuAction());
        menubar->addAction(menu_Mantenimiento_2->menuAction());
        menubar->addAction(menu_Ayuda->menuAction());
        menuInventario->addAction(menuActivo_Fijo->menuAction());
        menuInventario->addAction(menuMaterial_Bibliografico->menuAction());
        menuActivo_Fijo->addAction(actionIngresoActivoFijo);
        menuActivo_Fijo->addAction(actionTrasladoActivoFijo);
        menuActivo_Fijo->addAction(actionDescargo);
        menuMaterial_Bibliografico->addAction(actionIngresoBibliografico);
        menuMaterial_Bibliografico->addAction(actionTraslado);
        menuMaterial_Bibliografico->addAction(actionDescargo_2);
        menu_Ventas->addAction(actionConsultaIngreso);
        menu_Ventas->addAction(actionConsulta_de_Descargos_de_Bienes);
        menu_Ventas->addAction(actionConsulta_Traslado_de_Bienes);
        menu_Ventas->addSeparator();
        menu_Ventas->addAction(actionIngresos_en_procesos);
        menu_Ventas->addAction(actionDescargos_en_Proceso);
        menu_Ventas->addSeparator();
        menu_Ventas->addAction(actionConsulta_de_Bienes);
        menuEstados_Financieros->addAction(menuEstados_Financieros_2->menuAction());
        menuEstados_Financieros->addAction(catalogoCuenta);
        menuEstados_Financieros->addAction(consolidadoAF);
        menuEstados_Financieros->addAction(actionConsolidade_de_Material_Bibliografico);
        menuEstados_Financieros->addAction(actionUsuario);
        menuEstados_Financieros_2->addAction(catalogoActivoFijo);
        menuEstados_Financieros_2->addSeparator();
        menuEstados_Financieros_2->addAction(actionMaterialBilbliografico);
        menu_Mantenimiento_2->addAction(actionGestionUsuario);
        menu_Mantenimiento_2->addSeparator();
        menu_Mantenimiento_2->addAction(actionMostrar_Calendario);
        menu_Mantenimiento_2->addAction(actionTransacciones);
        menu_Mantenimiento_2->addAction(actionUsuarios);
        menu_Mantenimiento_2->addSeparator();
        menu_Mantenimiento_2->addAction(actionMarcas);
        menu_Mantenimiento_2->addAction(actionTitulos);
        menu_Mantenimiento_2->addAction(actionSectores_o_dependencias);
        menu_Mantenimiento_2->addSeparator();
        menu_Mantenimiento_2->addAction(actionInventarios);
        menu_Mantenimiento->addAction(actionContabilidad);
        menu_Mantenimiento->addAction(actionSistema_de_Costeo);
        menu_Mantenimiento->addAction(actionLogear);
        menu_Mantenimiento->addAction(actionPresupuesto);
        menu_Mantenimiento->addSeparator();
        menu_Mantenimiento->addAction(actionSalir);
        menu_Ayuda->addAction(actionManual_usuario);
        toolBar->addAction(actionContabilidad);
        toolBar->addAction(actionSistema_de_Costeo);
        toolBar->addAction(actionLogear);
        toolBar->addSeparator();
        toolBar->addAction(actionTrasladoActivoFijo);

        retranslateUi(MainWindowSistemaInventario);
        QObject::connect(actionSalir, SIGNAL(activated()), MainWindowSistemaInventario, SLOT(close()));
        QObject::connect(actionMostrar_Calendario, SIGNAL(activated()), contieneCalendario, SLOT(show()));
        QObject::connect(actionTransacciones, SIGNAL(activated()), contenedorTransacciones, SLOT(show()));
        QObject::connect(actionUsuarios, SIGNAL(activated()), usuariosConectados, SLOT(show()));

        QMetaObject::connectSlotsByName(MainWindowSistemaInventario);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowSistemaInventario)
    {
        MainWindowSistemaInventario->setWindowTitle(QApplication::translate("MainWindowSistemaInventario", "Sistema de Inventario - Biblioteca Central", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        MainWindowSistemaInventario->setStatusTip(QApplication::translate("MainWindowSistemaInventario", "Iniciado ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionContabilidad->setText(QApplication::translate("MainWindowSistemaInventario", "&Contabilidad", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionContabilidad->setStatusTip(QApplication::translate("MainWindowSistemaInventario", "Sistemas para el manejo de la contabilidad general de la empresa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionSistema_de_Costeo->setText(QApplication::translate("MainWindowSistemaInventario", "Catalogo de Activos Fijos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionSistema_de_Costeo->setStatusTip(QApplication::translate("MainWindowSistemaInventario", "Catalogo con la defincion de clases, para la correcta clasificacion. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionLogear->setText(QApplication::translate("MainWindowSistemaInventario", "Usuarios", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionLogear->setStatusTip(QApplication::translate("MainWindowSistemaInventario", "Ingreso al sistema.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionSalir->setText(QApplication::translate("MainWindowSistemaInventario", "&Salir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionSalir->setStatusTip(QApplication::translate("MainWindowSistemaInventario", "Cerrar aplicacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionConsultaIngreso->setText(QApplication::translate("MainWindowSistemaInventario", " Ingreso Bienes", 0, QApplication::UnicodeUTF8));
        actionManual_usuario->setText(QApplication::translate("MainWindowSistemaInventario", "Manual SI-BCUES", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionManual_usuario->setToolTip(QApplication::translate("MainWindowSistemaInventario", "Manual SI-BCUES", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAcerca_de->setText(QApplication::translate("MainWindowSistemaInventario", "Acerca de..", 0, QApplication::UnicodeUTF8));
        actionEstado_de_Capital->setText(QApplication::translate("MainWindowSistemaInventario", "Estado de Capital", 0, QApplication::UnicodeUTF8));
        actionEstado_de_Resultado->setText(QApplication::translate("MainWindowSistemaInventario", "Estado de Resultado", 0, QApplication::UnicodeUTF8));
        catalogoActivoFijo->setText(QApplication::translate("MainWindowSistemaInventario", "Activo Fijo", 0, QApplication::UnicodeUTF8));
        catalogoCuenta->setText(QApplication::translate("MainWindowSistemaInventario", "Catalogo Cuentas", 0, QApplication::UnicodeUTF8));
        consolidadoAF->setText(QApplication::translate("MainWindowSistemaInventario", "Consolidado de Activo Fijo - M5", 0, QApplication::UnicodeUTF8));
        actionVentas->setText(QApplication::translate("MainWindowSistemaInventario", "Ventas", 0, QApplication::UnicodeUTF8));
        actionGestionUsuario->setText(QApplication::translate("MainWindowSistemaInventario", "Gestion de Usuarios", 0, QApplication::UnicodeUTF8));
        actionRespaldo_de_Datos->setText(QApplication::translate("MainWindowSistemaInventario", "Respaldo de Datos", 0, QApplication::UnicodeUTF8));
        actionConfiguracion_Sistema->setText(QApplication::translate("MainWindowSistemaInventario", "Configuracion del Sistema Contable", 0, QApplication::UnicodeUTF8));
        actionMostrar_Calendario->setText(QApplication::translate("MainWindowSistemaInventario", "Calendario...", 0, QApplication::UnicodeUTF8));
        actionMaterialBilbliografico->setText(QApplication::translate("MainWindowSistemaInventario", "Material Bilbiografico", 0, QApplication::UnicodeUTF8));
        actionIngresoActivoFijo->setText(QApplication::translate("MainWindowSistemaInventario", "Ingreso", 0, QApplication::UnicodeUTF8));
        actionTrasladoActivoFijo->setText(QApplication::translate("MainWindowSistemaInventario", "Traslado ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionTrasladoActivoFijo->setToolTip(QApplication::translate("MainWindowSistemaInventario", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Traslado Activo Fijo</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionDescargo->setText(QApplication::translate("MainWindowSistemaInventario", "Descargo", 0, QApplication::UnicodeUTF8));
        actionIngresoBibliografico->setText(QApplication::translate("MainWindowSistemaInventario", "Ingreso", 0, QApplication::UnicodeUTF8));
        actionTraslado->setText(QApplication::translate("MainWindowSistemaInventario", "Traslado", 0, QApplication::UnicodeUTF8));
        actionDescargo_2->setText(QApplication::translate("MainWindowSistemaInventario", "Descargo", 0, QApplication::UnicodeUTF8));
        actionConsulta_de_Descargos_de_Bienes->setText(QApplication::translate("MainWindowSistemaInventario", "Descargos de Bienes", 0, QApplication::UnicodeUTF8));
        actionConsulta_Traslado_de_Bienes->setText(QApplication::translate("MainWindowSistemaInventario", "Traslado de Bienes", 0, QApplication::UnicodeUTF8));
        actionConsolidade_de_Material_Bibliografico->setText(QApplication::translate("MainWindowSistemaInventario", "Consolidado de Material Bibliografico -M5", 0, QApplication::UnicodeUTF8));
        actionUsuario->setText(QApplication::translate("MainWindowSistemaInventario", "Usuarios", 0, QApplication::UnicodeUTF8));
        actionPresupuesto->setText(QApplication::translate("MainWindowSistemaInventario", "Presupuesto", 0, QApplication::UnicodeUTF8));
        actionTransacciones->setText(QApplication::translate("MainWindowSistemaInventario", "Transacciones...", 0, QApplication::UnicodeUTF8));
        actionUsuarios->setText(QApplication::translate("MainWindowSistemaInventario", "Usuarios...", 0, QApplication::UnicodeUTF8));
        actionMarcas->setText(QApplication::translate("MainWindowSistemaInventario", "Marcas y modelos", 0, QApplication::UnicodeUTF8));
        actionTitulos->setText(QApplication::translate("MainWindowSistemaInventario", "Titulos y autores", 0, QApplication::UnicodeUTF8));
        actionSectores_o_dependencias->setText(QApplication::translate("MainWindowSistemaInventario", "Sectores o dependencias", 0, QApplication::UnicodeUTF8));
        actionIngresos_en_procesos->setText(QApplication::translate("MainWindowSistemaInventario", "Ingresos en  proceso...", 0, QApplication::UnicodeUTF8));
        actionConsulta_de_Bienes->setText(QApplication::translate("MainWindowSistemaInventario", "Consulta de Bienes", 0, QApplication::UnicodeUTF8));
        actionDescargos_en_Proceso->setText(QApplication::translate("MainWindowSistemaInventario", "Descargos en Proceso...", 0, QApplication::UnicodeUTF8));
        actionInventarios->setText(QApplication::translate("MainWindowSistemaInventario", "Inventarios", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindowSistemaInventario", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:30pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/iconos/blockdevice.png\" /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-weight:600;\">SI-BC</span><span style=\" font-family:'MS Shell Dlg 2'; font-weight:600; color:#ff0000;\">UES</span></p>\n"
"<p align=\"center\" style"
                        "=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600;\">Universidad de El Salvador</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:14pt;\">BIBLIOTECA CENTRAL</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\"> Sistema Bibliotecario</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">(c) 2009</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        menuInventario->setTitle(QApplication::translate("MainWindowSistemaInventario", "Inventario", 0, QApplication::UnicodeUTF8));
        menuActivo_Fijo->setTitle(QApplication::translate("MainWindowSistemaInventario", "Activo Fijo", 0, QApplication::UnicodeUTF8));
        menuMaterial_Bibliografico->setTitle(QApplication::translate("MainWindowSistemaInventario", "Material Bibliografico", 0, QApplication::UnicodeUTF8));
        menu_Ventas->setTitle(QApplication::translate("MainWindowSistemaInventario", "&Bienes", 0, QApplication::UnicodeUTF8));
        menuEstados_Financieros->setTitle(QApplication::translate("MainWindowSistemaInventario", "&Reportes", 0, QApplication::UnicodeUTF8));
        menuEstados_Financieros_2->setTitle(QApplication::translate("MainWindowSistemaInventario", "Catalogo Bienes", 0, QApplication::UnicodeUTF8));
        menu_Mantenimiento_2->setTitle(QApplication::translate("MainWindowSistemaInventario", "&Mantenimiento", 0, QApplication::UnicodeUTF8));
        menu_Mantenimiento->setTitle(QApplication::translate("MainWindowSistemaInventario", "&Modulos", 0, QApplication::UnicodeUTF8));
        menu_Ayuda->setTitle(QApplication::translate("MainWindowSistemaInventario", "&Ayuda", 0, QApplication::UnicodeUTF8));
        contenedorTransacciones->setWindowTitle(QApplication::translate("MainWindowSistemaInventario", "Transacciones", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = historialTransacciones->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindowSistemaInventario", "Historial", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = historialTransacciones->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindowSistemaInventario", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = historialTransacciones->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindowSistemaInventario", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = historialTransacciones->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindowSistemaInventario", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = historialTransacciones->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindowSistemaInventario", "4", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = historialTransacciones->isSortingEnabled();
        historialTransacciones->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem5 = historialTransacciones->item(0, 0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindowSistemaInventario", "mely8 ingreso un nuevo M1 con numero 7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = historialTransacciones->item(1, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindowSistemaInventario", "El usuario bruno2d ingreso al sistema a las 12:50", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = historialTransacciones->item(2, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindowSistemaInventario", "Se inicio un nuevo registro de M3 con codigo M3001", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = historialTransacciones->item(3, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindowSistemaInventario", "Se creo el usuario bb2000", 0, QApplication::UnicodeUTF8));
        historialTransacciones->setSortingEnabled(__sortingEnabled);

        contieneCalendario->setWindowTitle(QApplication::translate("MainWindowSistemaInventario", "Periodo Contable", 0, QApplication::UnicodeUTF8));
        usuariosConectados->setWindowTitle(QApplication::translate("MainWindowSistemaInventario", "Usuarios", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindowSistemaInventario", "Nombre", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindowSistemaInventario", "Usuarios", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindowSistemaInventario", "Biblioteca Central", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(1, QApplication::translate("MainWindowSistemaInventario", "Bruno Gonzalez", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindowSistemaInventario", "bruno2d", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(1, QApplication::translate("MainWindowSistemaInventario", "Melissa Ester", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindowSistemaInventario", "mely", 0, QApplication::UnicodeUTF8));
        treeWidget->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class MainWindowSistemaInventario: public Ui_MainWindowSistemaInventario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPALCONTABLES_H
