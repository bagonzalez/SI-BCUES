/********************************************************************************
** Form generated from reading UI file 'consultaingreso.ui'
**
** Created: Thu Apr 21 08:48:21 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSULTAINGRESO_H
#define UI_CONSULTAINGRESO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConsultaIngreso
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QTableView *tablaIngresoAF;
    QPushButton *generarReporte;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QTableView *tablaIngresoBiblio;
    QPushButton *generarReporteBiblio;
    QPushButton *salir;

    void setupUi(QWidget *ConsultaIngreso)
    {
        if (ConsultaIngreso->objectName().isEmpty())
            ConsultaIngreso->setObjectName(QString::fromUtf8("ConsultaIngreso"));
        ConsultaIngreso->setWindowModality(Qt::ApplicationModal);
        ConsultaIngreso->resize(410, 382);
        gridLayout = new QGridLayout(ConsultaIngreso);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ConsultaIngreso);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tabWidget = new QTabWidget(ConsultaIngreso);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tablaIngresoAF = new QTableView(tab);
        tablaIngresoAF->setObjectName(QString::fromUtf8("tablaIngresoAF"));

        verticalLayout->addWidget(tablaIngresoAF);

        generarReporte = new QPushButton(tab);
        generarReporte->setObjectName(QString::fromUtf8("generarReporte"));

        verticalLayout->addWidget(generarReporte);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tablaIngresoBiblio = new QTableView(tab_2);
        tablaIngresoBiblio->setObjectName(QString::fromUtf8("tablaIngresoBiblio"));

        verticalLayout_2->addWidget(tablaIngresoBiblio);

        generarReporteBiblio = new QPushButton(tab_2);
        generarReporteBiblio->setObjectName(QString::fromUtf8("generarReporteBiblio"));

        verticalLayout_2->addWidget(generarReporteBiblio);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        salir = new QPushButton(ConsultaIngreso);
        salir->setObjectName(QString::fromUtf8("salir"));

        gridLayout->addWidget(salir, 2, 0, 1, 1);


        retranslateUi(ConsultaIngreso);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ConsultaIngreso);
    } // setupUi

    void retranslateUi(QWidget *ConsultaIngreso)
    {
        ConsultaIngreso->setWindowTitle(QApplication::translate("ConsultaIngreso", "Consulta de Ingresos de Bienes", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConsultaIngreso", "Seleccione el ingreso a consultar (M1)", 0, QApplication::UnicodeUTF8));
        generarReporte->setText(QApplication::translate("ConsultaIngreso", "Generar Reporte", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ConsultaIngreso", "Activo Fijo", 0, QApplication::UnicodeUTF8));
        generarReporteBiblio->setText(QApplication::translate("ConsultaIngreso", "Generar Reporte", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ConsultaIngreso", "Material Bibliografico", 0, QApplication::UnicodeUTF8));
        salir->setText(QApplication::translate("ConsultaIngreso", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConsultaIngreso: public Ui_ConsultaIngreso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSULTAINGRESO_H
