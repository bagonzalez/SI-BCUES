/********************************************************************************
** Form generated from reading UI file 'manttoinventario.ui'
**
** Created: Thu Apr 21 08:48:21 2011
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
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
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
    QLabel *label_2;
    QDateEdit *anio;
    QLineEdit *descripcion;
    QVBoxLayout *verticalLayout;
    QToolButton *botonAgregar;
    QToolButton *botonMenos;
    QSpacerItem *verticalSpacer;
    QTableView *modeloTabla;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ManttoInventario)
    {
        if (ManttoInventario->objectName().isEmpty())
            ManttoInventario->setObjectName(QString::fromUtf8("ManttoInventario"));
        ManttoInventario->resize(400, 300);
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

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        anio = new QDateEdit(groupBox);
        anio->setObjectName(QString::fromUtf8("anio"));
        anio->setCalendarPopup(false);

        gridLayout->addWidget(anio, 0, 1, 1, 1);

        descripcion = new QLineEdit(groupBox);
        descripcion->setObjectName(QString::fromUtf8("descripcion"));

        gridLayout->addWidget(descripcion, 2, 1, 1, 1);


        horizontalLayout->addWidget(groupBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 0, -1);
        botonAgregar = new QToolButton(ManttoInventario);
        botonAgregar->setObjectName(QString::fromUtf8("botonAgregar"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonAgregar->setIcon(icon);
        botonAgregar->setIconSize(QSize(16, 16));

        verticalLayout->addWidget(botonAgregar);

        botonMenos = new QToolButton(ManttoInventario);
        botonMenos->setObjectName(QString::fromUtf8("botonMenos"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonMenos->setIcon(icon1);

        verticalLayout->addWidget(botonMenos);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


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
        groupBox->setTitle(QApplication::translate("ManttoInventario", "Ingreso:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ManttoInventario", "A\303\261o:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ManttoInventario", "Descripcion:", 0, QApplication::UnicodeUTF8));
        anio->setDisplayFormat(QApplication::translate("ManttoInventario", "yyyy", 0, QApplication::UnicodeUTF8));
        botonMenos->setText(QApplication::translate("ManttoInventario", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ManttoInventario: public Ui_ManttoInventario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANTTOINVENTARIO_H
