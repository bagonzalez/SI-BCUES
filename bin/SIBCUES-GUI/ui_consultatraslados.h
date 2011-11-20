/********************************************************************************
** Form generated from reading UI file 'consultatraslados.ui'
**
** Created: Thu Apr 21 08:48:21 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSULTATRASLADOS_H
#define UI_CONSULTATRASLADOS_H

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

class Ui_consultaTraslados
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTableView *tablaTrasladoAF;
    QPushButton *generarReporte;
    QWidget *tab_2;
    QTableView *tablaTrasladoBiblio;
    QPushButton *generarReporteMB;
    QPushButton *salir;

    void setupUi(QWidget *consultaTraslados)
    {
        if (consultaTraslados->objectName().isEmpty())
            consultaTraslados->setObjectName(QString::fromUtf8("consultaTraslados"));
        consultaTraslados->setWindowModality(Qt::ApplicationModal);
        consultaTraslados->resize(419, 418);
        verticalLayout = new QVBoxLayout(consultaTraslados);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(consultaTraslados);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        tabWidget = new QTabWidget(consultaTraslados);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tablaTrasladoAF = new QTableView(tab);
        tablaTrasladoAF->setObjectName(QString::fromUtf8("tablaTrasladoAF"));

        verticalLayout_2->addWidget(tablaTrasladoAF);

        generarReporte = new QPushButton(tab);
        generarReporte->setObjectName(QString::fromUtf8("generarReporte"));

        verticalLayout_2->addWidget(generarReporte);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tablaTrasladoBiblio = new QTableView(tab_2);
        tablaTrasladoBiblio->setObjectName(QString::fromUtf8("tablaTrasladoBiblio"));
        tablaTrasladoBiblio->setGeometry(QRect(10, 10, 351, 211));
        generarReporteMB = new QPushButton(tab_2);
        generarReporteMB->setObjectName(QString::fromUtf8("generarReporteMB"));
        generarReporteMB->setGeometry(QRect(130, 240, 111, 23));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        salir = new QPushButton(consultaTraslados);
        salir->setObjectName(QString::fromUtf8("salir"));

        verticalLayout->addWidget(salir);


        retranslateUi(consultaTraslados);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(consultaTraslados);
    } // setupUi

    void retranslateUi(QWidget *consultaTraslados)
    {
        consultaTraslados->setWindowTitle(QApplication::translate("consultaTraslados", "Consulta de Traslados realizados", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("consultaTraslados", "Seleccione el traslado a consultar (M2)", 0, QApplication::UnicodeUTF8));
        generarReporte->setText(QApplication::translate("consultaTraslados", "Generar Reporte", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("consultaTraslados", "Activo Fijo", 0, QApplication::UnicodeUTF8));
        generarReporteMB->setText(QApplication::translate("consultaTraslados", "Generar Reporte", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("consultaTraslados", "Material Bibliografico", 0, QApplication::UnicodeUTF8));
        salir->setText(QApplication::translate("consultaTraslados", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class consultaTraslados: public Ui_consultaTraslados {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSULTATRASLADOS_H
