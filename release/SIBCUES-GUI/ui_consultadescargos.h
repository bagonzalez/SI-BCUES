/********************************************************************************
** Form generated from reading UI file 'consultadescargos.ui'
**
** Created: Sat 14. May 00:05:01 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSULTADESCARGOS_H
#define UI_CONSULTADESCARGOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConsultaDescargos
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QTableView *tablaDescargoAF;
    QPushButton *generarReporte;
    QWidget *tab_2;
    QTableView *tablaDescargoBiblio;
    QPushButton *generarReporteMB;
    QPushButton *salir;

    void setupUi(QWidget *ConsultaDescargos)
    {
        if (ConsultaDescargos->objectName().isEmpty())
            ConsultaDescargos->setObjectName(QString::fromUtf8("ConsultaDescargos"));
        ConsultaDescargos->setWindowModality(Qt::ApplicationModal);
        ConsultaDescargos->resize(415, 419);
        verticalLayout_2 = new QVBoxLayout(ConsultaDescargos);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(ConsultaDescargos);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        tabWidget = new QTabWidget(ConsultaDescargos);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tablaDescargoAF = new QTableView(tab);
        tablaDescargoAF->setObjectName(QString::fromUtf8("tablaDescargoAF"));

        verticalLayout->addWidget(tablaDescargoAF);

        generarReporte = new QPushButton(tab);
        generarReporte->setObjectName(QString::fromUtf8("generarReporte"));

        verticalLayout->addWidget(generarReporte);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tablaDescargoBiblio = new QTableView(tab_2);
        tablaDescargoBiblio->setObjectName(QString::fromUtf8("tablaDescargoBiblio"));
        tablaDescargoBiblio->setGeometry(QRect(10, 10, 351, 211));
        generarReporteMB = new QPushButton(tab_2);
        generarReporteMB->setObjectName(QString::fromUtf8("generarReporteMB"));
        generarReporteMB->setGeometry(QRect(130, 230, 101, 23));
        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        salir = new QPushButton(ConsultaDescargos);
        salir->setObjectName(QString::fromUtf8("salir"));

        verticalLayout_2->addWidget(salir);


        retranslateUi(ConsultaDescargos);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConsultaDescargos);
    } // setupUi

    void retranslateUi(QWidget *ConsultaDescargos)
    {
        ConsultaDescargos->setWindowTitle(QApplication::translate("ConsultaDescargos", "Consulta de Descargo de Bienes", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConsultaDescargos", "Seleccione el descargo a consultar (M3)", 0, QApplication::UnicodeUTF8));
        generarReporte->setText(QApplication::translate("ConsultaDescargos", "Generar Reporte", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ConsultaDescargos", "Activo Fijo", 0, QApplication::UnicodeUTF8));
        generarReporteMB->setText(QApplication::translate("ConsultaDescargos", "Generar Reporte", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ConsultaDescargos", "Material Bibliografico", 0, QApplication::UnicodeUTF8));
        salir->setText(QApplication::translate("ConsultaDescargos", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConsultaDescargos: public Ui_ConsultaDescargos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSULTADESCARGOS_H
