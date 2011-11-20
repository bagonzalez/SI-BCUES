/********************************************************************************
** Form generated from reading UI file 'sectoresgui.ui'
**
** Created: Mon 19. Jul 20:18:11 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECTORESGUI_H
#define UI_SECTORESGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SectoresGUI
{
public:
    QGridLayout *gridLayout;
    QTableView *tablaSectores;
    QVBoxLayout *verticalLayout;
    QToolButton *btmIngresar;
    QToolButton *btmEliminar;
    QToolButton *btmModificar;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btmSeleccionar;
    QPushButton *btmCancelar;

    void setupUi(QDialog *SectoresGUI)
    {
        if (SectoresGUI->objectName().isEmpty())
            SectoresGUI->setObjectName(QString::fromUtf8("SectoresGUI"));
        SectoresGUI->resize(396, 363);
        gridLayout = new QGridLayout(SectoresGUI);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tablaSectores = new QTableView(SectoresGUI);
        tablaSectores->setObjectName(QString::fromUtf8("tablaSectores"));

        gridLayout->addWidget(tablaSectores, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btmIngresar = new QToolButton(SectoresGUI);
        btmIngresar->setObjectName(QString::fromUtf8("btmIngresar"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        btmIngresar->setIcon(icon);

        verticalLayout->addWidget(btmIngresar);

        btmEliminar = new QToolButton(SectoresGUI);
        btmEliminar->setObjectName(QString::fromUtf8("btmEliminar"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        btmEliminar->setIcon(icon1);

        verticalLayout->addWidget(btmEliminar);

        btmModificar = new QToolButton(SectoresGUI);
        btmModificar->setObjectName(QString::fromUtf8("btmModificar"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/default-applications-capplet.png"), QSize(), QIcon::Normal, QIcon::Off);
        btmModificar->setIcon(icon2);

        verticalLayout->addWidget(btmModificar);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btmSeleccionar = new QPushButton(SectoresGUI);
        btmSeleccionar->setObjectName(QString::fromUtf8("btmSeleccionar"));

        horizontalLayout->addWidget(btmSeleccionar);

        btmCancelar = new QPushButton(SectoresGUI);
        btmCancelar->setObjectName(QString::fromUtf8("btmCancelar"));

        horizontalLayout->addWidget(btmCancelar);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(SectoresGUI);

        QMetaObject::connectSlotsByName(SectoresGUI);
    } // setupUi

    void retranslateUi(QDialog *SectoresGUI)
    {
        SectoresGUI->setWindowTitle(QApplication::translate("SectoresGUI", "Sectores o Dependencias", 0, QApplication::UnicodeUTF8));
        btmIngresar->setText(QApplication::translate("SectoresGUI", "...", 0, QApplication::UnicodeUTF8));
        btmEliminar->setText(QApplication::translate("SectoresGUI", "...", 0, QApplication::UnicodeUTF8));
        btmModificar->setText(QApplication::translate("SectoresGUI", "...", 0, QApplication::UnicodeUTF8));
        btmSeleccionar->setText(QApplication::translate("SectoresGUI", "Seleccionar", 0, QApplication::UnicodeUTF8));
        btmCancelar->setText(QApplication::translate("SectoresGUI", "Cancelar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SectoresGUI: public Ui_SectoresGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECTORESGUI_H
