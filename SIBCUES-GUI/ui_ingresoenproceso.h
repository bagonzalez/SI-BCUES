/********************************************************************************
** Form generated from reading UI file 'ingresoenproceso.ui'
**
** Created: Mon 19. Jul 20:18:12 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INGRESOENPROCESO_H
#define UI_INGRESOENPROCESO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IngresoenProceso
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tablaIngresosAF;
    QPushButton *btmSeleccionar;
    QWidget *tab_2;
    QPushButton *btmSalir;

    void setupUi(QDialog *IngresoenProceso)
    {
        if (IngresoenProceso->objectName().isEmpty())
            IngresoenProceso->setObjectName(QString::fromUtf8("IngresoenProceso"));
        IngresoenProceso->resize(400, 425);
        verticalLayout_2 = new QVBoxLayout(IngresoenProceso);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(IngresoenProceso);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        tablaIngresosAF = new QTableView(tab);
        tablaIngresosAF->setObjectName(QString::fromUtf8("tablaIngresosAF"));

        verticalLayout->addWidget(tablaIngresosAF);

        btmSeleccionar = new QPushButton(tab);
        btmSeleccionar->setObjectName(QString::fromUtf8("btmSeleccionar"));

        verticalLayout->addWidget(btmSeleccionar);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        btmSalir = new QPushButton(IngresoenProceso);
        btmSalir->setObjectName(QString::fromUtf8("btmSalir"));

        verticalLayout_2->addWidget(btmSalir);


        retranslateUi(IngresoenProceso);
        QObject::connect(btmSalir, SIGNAL(pressed()), IngresoenProceso, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(IngresoenProceso);
    } // setupUi

    void retranslateUi(QDialog *IngresoenProceso)
    {
        IngresoenProceso->setWindowTitle(QApplication::translate("IngresoenProceso", "Consulta de Ingresos en proceso", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("IngresoenProceso", "Seleccione el ingreso a consultar.", 0, QApplication::UnicodeUTF8));
        btmSeleccionar->setText(QApplication::translate("IngresoenProceso", "Seleccionar", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("IngresoenProceso", "Activo Fijo", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("IngresoenProceso", "Material Bibliografico", 0, QApplication::UnicodeUTF8));
        btmSalir->setText(QApplication::translate("IngresoenProceso", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IngresoenProceso: public Ui_IngresoenProceso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INGRESOENPROCESO_H
