/********************************************************************************
** Form generated from reading UI file 'variacionpresupuestaria.ui'
**
** Created: Mon 19. Jul 20:18:09 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VARIACIONPRESUPUESTARIA_H
#define UI_VARIACIONPRESUPUESTARIA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VariacionPresupuestaria
{
public:
    QAction *actionSalir;
    QAction *actionRegistro_de_Presupuesto_Solicitado;
    QAction *actionRegistro_de_Presupuesto_Aprobado;
    QAction *actionVariacion_Presupuestaria;
    QAction *actionDocumento_de_Variacion_Presupuestaria;
    QAction *actionRegistro_de_Razonamiento_Variacion_Presupuestaria;
    QWidget *centralWidget;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuNuevo;
    QMenu *menu_Nueva_Variacion_de_Gastos_por_Unidad_Presupuestaria;
    QMenu *menuEdicion;
    QMenu *menuVer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VariacionPresupuestaria)
    {
        if (VariacionPresupuestaria->objectName().isEmpty())
            VariacionPresupuestaria->setObjectName(QString::fromUtf8("VariacionPresupuestaria"));
        VariacionPresupuestaria->setWindowModality(Qt::ApplicationModal);
        VariacionPresupuestaria->resize(240, 157);
        VariacionPresupuestaria->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/hh.png"), QSize(), QIcon::Normal, QIcon::Off);
        VariacionPresupuestaria->setWindowIcon(icon);
        VariacionPresupuestaria->setIconSize(QSize(35, 35));
        actionSalir = new QAction(VariacionPresupuestaria);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        actionRegistro_de_Presupuesto_Solicitado = new QAction(VariacionPresupuestaria);
        actionRegistro_de_Presupuesto_Solicitado->setObjectName(QString::fromUtf8("actionRegistro_de_Presupuesto_Solicitado"));
        actionRegistro_de_Presupuesto_Aprobado = new QAction(VariacionPresupuestaria);
        actionRegistro_de_Presupuesto_Aprobado->setObjectName(QString::fromUtf8("actionRegistro_de_Presupuesto_Aprobado"));
        actionVariacion_Presupuestaria = new QAction(VariacionPresupuestaria);
        actionVariacion_Presupuestaria->setObjectName(QString::fromUtf8("actionVariacion_Presupuestaria"));
        actionDocumento_de_Variacion_Presupuestaria = new QAction(VariacionPresupuestaria);
        actionDocumento_de_Variacion_Presupuestaria->setObjectName(QString::fromUtf8("actionDocumento_de_Variacion_Presupuestaria"));
        actionRegistro_de_Razonamiento_Variacion_Presupuestaria = new QAction(VariacionPresupuestaria);
        actionRegistro_de_Razonamiento_Variacion_Presupuestaria->setObjectName(QString::fromUtf8("actionRegistro_de_Razonamiento_Variacion_Presupuestaria"));
        centralWidget = new QWidget(VariacionPresupuestaria);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 161, 41));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        VariacionPresupuestaria->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VariacionPresupuestaria);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 240, 21));
        menuNuevo = new QMenu(menuBar);
        menuNuevo->setObjectName(QString::fromUtf8("menuNuevo"));
        menu_Nueva_Variacion_de_Gastos_por_Unidad_Presupuestaria = new QMenu(menuNuevo);
        menu_Nueva_Variacion_de_Gastos_por_Unidad_Presupuestaria->setObjectName(QString::fromUtf8("menu_Nueva_Variacion_de_Gastos_por_Unidad_Presupuestaria"));
        menuEdicion = new QMenu(menuBar);
        menuEdicion->setObjectName(QString::fromUtf8("menuEdicion"));
        menuVer = new QMenu(menuBar);
        menuVer->setObjectName(QString::fromUtf8("menuVer"));
        VariacionPresupuestaria->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VariacionPresupuestaria);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        VariacionPresupuestaria->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VariacionPresupuestaria);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VariacionPresupuestaria->setStatusBar(statusBar);

        menuBar->addAction(menuNuevo->menuAction());
        menuBar->addAction(menuEdicion->menuAction());
        menuBar->addAction(menuVer->menuAction());
        menuNuevo->addAction(menu_Nueva_Variacion_de_Gastos_por_Unidad_Presupuestaria->menuAction());
        menuNuevo->addAction(actionSalir);
        menu_Nueva_Variacion_de_Gastos_por_Unidad_Presupuestaria->addAction(actionRegistro_de_Presupuesto_Solicitado);
        menu_Nueva_Variacion_de_Gastos_por_Unidad_Presupuestaria->addAction(actionRegistro_de_Presupuesto_Aprobado);
        menu_Nueva_Variacion_de_Gastos_por_Unidad_Presupuestaria->addSeparator();
        menu_Nueva_Variacion_de_Gastos_por_Unidad_Presupuestaria->addAction(actionRegistro_de_Razonamiento_Variacion_Presupuestaria);
        menuEdicion->addAction(actionVariacion_Presupuestaria);
        menuVer->addAction(actionDocumento_de_Variacion_Presupuestaria);

        retranslateUi(VariacionPresupuestaria);
        QObject::connect(actionSalir, SIGNAL(activated()), VariacionPresupuestaria, SLOT(close()));

        QMetaObject::connectSlotsByName(VariacionPresupuestaria);
    } // setupUi

    void retranslateUi(QMainWindow *VariacionPresupuestaria)
    {
        VariacionPresupuestaria->setWindowTitle(QApplication::translate("VariacionPresupuestaria", "VariacionPresupuestaria", 0, QApplication::UnicodeUTF8));
        actionSalir->setText(QApplication::translate("VariacionPresupuestaria", "Salir", 0, QApplication::UnicodeUTF8));
        actionRegistro_de_Presupuesto_Solicitado->setText(QApplication::translate("VariacionPresupuestaria", "Registro de Presupuesto Solicitado", 0, QApplication::UnicodeUTF8));
        actionRegistro_de_Presupuesto_Aprobado->setText(QApplication::translate("VariacionPresupuestaria", "Registro de Presupuesto Aprobado", 0, QApplication::UnicodeUTF8));
        actionVariacion_Presupuestaria->setText(QApplication::translate("VariacionPresupuestaria", "Variacion Presupuestaria", 0, QApplication::UnicodeUTF8));
        actionDocumento_de_Variacion_Presupuestaria->setText(QApplication::translate("VariacionPresupuestaria", "Documento de Variacion Presupuestaria", 0, QApplication::UnicodeUTF8));
        actionRegistro_de_Razonamiento_Variacion_Presupuestaria->setText(QApplication::translate("VariacionPresupuestaria", "Registro de Razonamiento Variacion Presupuestaria", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("VariacionPresupuestaria", "Presupuesto", 0, QApplication::UnicodeUTF8));
        menuNuevo->setTitle(QApplication::translate("VariacionPresupuestaria", "&Nuevo", 0, QApplication::UnicodeUTF8));
        menu_Nueva_Variacion_de_Gastos_por_Unidad_Presupuestaria->setTitle(QApplication::translate("VariacionPresupuestaria", "&Nueva ", 0, QApplication::UnicodeUTF8));
        menuEdicion->setTitle(QApplication::translate("VariacionPresupuestaria", "Edicion", 0, QApplication::UnicodeUTF8));
        menuVer->setTitle(QApplication::translate("VariacionPresupuestaria", "Ver", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VariacionPresupuestaria: public Ui_VariacionPresupuestaria {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIACIONPRESUPUESTARIA_H
