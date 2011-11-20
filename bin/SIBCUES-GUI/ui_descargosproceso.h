/********************************************************************************
** Form generated from reading UI file 'descargosproceso.ui'
**
** Created: Thu Apr 21 08:48:21 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESCARGOSPROCESO_H
#define UI_DESCARGOSPROCESO_H

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

class Ui_DescargosProceso
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tablaDescargoAF;
    QPushButton *btmSeleccionar;
    QWidget *tab_2;
    QPushButton *btmSalir;

    void setupUi(QDialog *DescargosProceso)
    {
        if (DescargosProceso->objectName().isEmpty())
            DescargosProceso->setObjectName(QString::fromUtf8("DescargosProceso"));
        DescargosProceso->resize(400, 437);
        verticalLayout_2 = new QVBoxLayout(DescargosProceso);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(DescargosProceso);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        tablaDescargoAF = new QTableView(tab);
        tablaDescargoAF->setObjectName(QString::fromUtf8("tablaDescargoAF"));

        verticalLayout->addWidget(tablaDescargoAF);

        btmSeleccionar = new QPushButton(tab);
        btmSeleccionar->setObjectName(QString::fromUtf8("btmSeleccionar"));

        verticalLayout->addWidget(btmSeleccionar);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        btmSalir = new QPushButton(DescargosProceso);
        btmSalir->setObjectName(QString::fromUtf8("btmSalir"));

        verticalLayout_2->addWidget(btmSalir);


        retranslateUi(DescargosProceso);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DescargosProceso);
    } // setupUi

    void retranslateUi(QDialog *DescargosProceso)
    {
        DescargosProceso->setWindowTitle(QApplication::translate("DescargosProceso", "Consulta Descargo de BIenes en porceso", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DescargosProceso", "Seleccione el descargo a consultar.", 0, QApplication::UnicodeUTF8));
        btmSeleccionar->setText(QApplication::translate("DescargosProceso", "Seleccionar", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DescargosProceso", "Activo Fijo", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DescargosProceso", "Material Bibliografico", 0, QApplication::UnicodeUTF8));
        btmSalir->setText(QApplication::translate("DescargosProceso", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DescargosProceso: public Ui_DescargosProceso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESCARGOSPROCESO_H
