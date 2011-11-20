/********************************************************************************
** Form generated from reading UI file 'manttoinventario.ui'
**
** Created: Thu 30. Jun 00:04:43 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANTTOINVENTARIO_H
#define UI_MANTTOINVENTARIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ManttoInventario
{
public:
    QAction *insertRowAction;
    QAction *deleteRowAction;
    QAction *modificarRowAction;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QDateEdit *anio;
    QToolButton *botonAgregar;
    QToolButton *botonMenos;
    QTableView *modeloTabla;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ManttoInventario)
    {
        if (ManttoInventario->objectName().isEmpty())
            ManttoInventario->setObjectName(QString::fromUtf8("ManttoInventario"));
        ManttoInventario->resize(252, 285);
        insertRowAction = new QAction(ManttoInventario);
        insertRowAction->setObjectName(QString::fromUtf8("insertRowAction"));
        deleteRowAction = new QAction(ManttoInventario);
        deleteRowAction->setObjectName(QString::fromUtf8("deleteRowAction"));
        modificarRowAction = new QAction(ManttoInventario);
        modificarRowAction->setObjectName(QString::fromUtf8("modificarRowAction"));
        verticalLayout_3 = new QVBoxLayout(ManttoInventario);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        groupBox = new QGroupBox(ManttoInventario);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        anio = new QDateEdit(groupBox);
        anio->setObjectName(QString::fromUtf8("anio"));
        anio->setCalendarPopup(false);

        gridLayout->addWidget(anio, 0, 1, 1, 1);

        botonAgregar = new QToolButton(groupBox);
        botonAgregar->setObjectName(QString::fromUtf8("botonAgregar"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonAgregar->setIcon(icon);
        botonAgregar->setIconSize(QSize(16, 16));

        gridLayout->addWidget(botonAgregar, 0, 2, 1, 1);

        botonMenos = new QToolButton(groupBox);
        botonMenos->setObjectName(QString::fromUtf8("botonMenos"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonMenos->setIcon(icon1);

        gridLayout->addWidget(botonMenos, 0, 3, 1, 1);


        horizontalLayout->addWidget(groupBox);


        verticalLayout_3->addLayout(horizontalLayout);

        modeloTabla = new QTableView(ManttoInventario);
        modeloTabla->setObjectName(QString::fromUtf8("modeloTabla"));

        verticalLayout_3->addWidget(modeloTabla);

        buttonBox = new QDialogButtonBox(ManttoInventario);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(ManttoInventario);
        QObject::connect(buttonBox, SIGNAL(accepted()), ManttoInventario, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ManttoInventario, SLOT(reject()));

        QMetaObject::connectSlotsByName(ManttoInventario);
    } // setupUi

    void retranslateUi(QDialog *ManttoInventario)
    {
        ManttoInventario->setWindowTitle(QApplication::translate("ManttoInventario", "Mantenimiento", 0, QApplication::UnicodeUTF8));
        insertRowAction->setText(QApplication::translate("ManttoInventario", "Insertar Fila", 0, QApplication::UnicodeUTF8));
        deleteRowAction->setText(QApplication::translate("ManttoInventario", "Borrar Fila", 0, QApplication::UnicodeUTF8));
        modificarRowAction->setText(QApplication::translate("ManttoInventario", "Modifica Fila", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ManttoInventario", "Ingreso Inventario:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ManttoInventario", "A\303\261o:", 0, QApplication::UnicodeUTF8));
        anio->setDisplayFormat(QApplication::translate("ManttoInventario", "yyyy", 0, QApplication::UnicodeUTF8));
        botonMenos->setText(QApplication::translate("ManttoInventario", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ManttoInventario: public Ui_ManttoInventario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANTTOINVENTARIO_H
