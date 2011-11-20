/********************************************************************************
** Form generated from reading UI file 'marcas.ui'
**
** Created: Thu Apr 21 08:48:21 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARCAS_H
#define UI_MARCAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_marcas
{
public:
    QAction *insertRowAction;
    QAction *deleteRowAction;
    QAction *modificarRowAction;
    QGridLayout *gridLayout;
    QTableView *tablaMarcas;
    QVBoxLayout *verticalLayout;
    QToolButton *btmAgregarMarca;
    QToolButton *btmEliminarMarca;
    QToolButton *btmModificarMarca;
    QSpacerItem *verticalSpacer;
    QLabel *labelMarcas;
    QTableView *tablaModelo;
    QLabel *labelModelos;
    QVBoxLayout *verticalLayout_2;
    QToolButton *btmAgregarModelo;
    QToolButton *btmEliminarModelo;
    QToolButton *btmModificarModelo;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btmSeleccionar;
    QPushButton *btmCancelar;

    void setupUi(QDialog *marcas)
    {
        if (marcas->objectName().isEmpty())
            marcas->setObjectName(QString::fromUtf8("marcas"));
        marcas->setWindowModality(Qt::ApplicationModal);
        marcas->resize(435, 430);
        insertRowAction = new QAction(marcas);
        insertRowAction->setObjectName(QString::fromUtf8("insertRowAction"));
        deleteRowAction = new QAction(marcas);
        deleteRowAction->setObjectName(QString::fromUtf8("deleteRowAction"));
        modificarRowAction = new QAction(marcas);
        modificarRowAction->setObjectName(QString::fromUtf8("modificarRowAction"));
        gridLayout = new QGridLayout(marcas);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tablaMarcas = new QTableView(marcas);
        tablaMarcas->setObjectName(QString::fromUtf8("tablaMarcas"));
        tablaMarcas->setAlternatingRowColors(true);

        gridLayout->addWidget(tablaMarcas, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        btmAgregarMarca = new QToolButton(marcas);
        btmAgregarMarca->setObjectName(QString::fromUtf8("btmAgregarMarca"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        btmAgregarMarca->setIcon(icon);
        btmAgregarMarca->setIconSize(QSize(26, 26));

        verticalLayout->addWidget(btmAgregarMarca);

        btmEliminarMarca = new QToolButton(marcas);
        btmEliminarMarca->setObjectName(QString::fromUtf8("btmEliminarMarca"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        btmEliminarMarca->setIcon(icon1);
        btmEliminarMarca->setIconSize(QSize(26, 26));

        verticalLayout->addWidget(btmEliminarMarca);

        btmModificarMarca = new QToolButton(marcas);
        btmModificarMarca->setObjectName(QString::fromUtf8("btmModificarMarca"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/default-applications-capplet.png"), QSize(), QIcon::Normal, QIcon::Off);
        btmModificarMarca->setIcon(icon2);
        btmModificarMarca->setIconSize(QSize(26, 26));

        verticalLayout->addWidget(btmModificarMarca);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        labelMarcas = new QLabel(marcas);
        labelMarcas->setObjectName(QString::fromUtf8("labelMarcas"));

        gridLayout->addWidget(labelMarcas, 0, 0, 1, 1);

        tablaModelo = new QTableView(marcas);
        tablaModelo->setObjectName(QString::fromUtf8("tablaModelo"));
        tablaModelo->setAlternatingRowColors(true);

        gridLayout->addWidget(tablaModelo, 3, 0, 1, 1);

        labelModelos = new QLabel(marcas);
        labelModelos->setObjectName(QString::fromUtf8("labelModelos"));

        gridLayout->addWidget(labelModelos, 2, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btmAgregarModelo = new QToolButton(marcas);
        btmAgregarModelo->setObjectName(QString::fromUtf8("btmAgregarModelo"));
        btmAgregarModelo->setIcon(icon);
        btmAgregarModelo->setIconSize(QSize(26, 26));

        verticalLayout_2->addWidget(btmAgregarModelo);

        btmEliminarModelo = new QToolButton(marcas);
        btmEliminarModelo->setObjectName(QString::fromUtf8("btmEliminarModelo"));
        btmEliminarModelo->setIcon(icon1);
        btmEliminarModelo->setIconSize(QSize(26, 26));

        verticalLayout_2->addWidget(btmEliminarModelo);

        btmModificarModelo = new QToolButton(marcas);
        btmModificarModelo->setObjectName(QString::fromUtf8("btmModificarModelo"));
        btmModificarModelo->setIcon(icon2);
        btmModificarModelo->setIconSize(QSize(26, 26));

        verticalLayout_2->addWidget(btmModificarModelo);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_2, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btmSeleccionar = new QPushButton(marcas);
        btmSeleccionar->setObjectName(QString::fromUtf8("btmSeleccionar"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/iconos/button_ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        btmSeleccionar->setIcon(icon3);

        horizontalLayout->addWidget(btmSeleccionar);

        btmCancelar = new QPushButton(marcas);
        btmCancelar->setObjectName(QString::fromUtf8("btmCancelar"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/iconos/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btmCancelar->setIcon(icon4);

        horizontalLayout->addWidget(btmCancelar);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);


        retranslateUi(marcas);

        QMetaObject::connectSlotsByName(marcas);
    } // setupUi

    void retranslateUi(QDialog *marcas)
    {
        marcas->setWindowTitle(QApplication::translate("marcas", "Seleccion de marcas", 0, QApplication::UnicodeUTF8));
        insertRowAction->setText(QApplication::translate("marcas", "Insertar Fila", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        insertRowAction->setToolTip(QApplication::translate("marcas", "Insertar Fila", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deleteRowAction->setText(QApplication::translate("marcas", "Delete Row", 0, QApplication::UnicodeUTF8));
        modificarRowAction->setText(QApplication::translate("marcas", "modficiar row", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btmAgregarMarca->setToolTip(QApplication::translate("marcas", "Agregar Marca", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        btmAgregarMarca->setWhatsThis(QApplication::translate("marcas", "Puede agregar nuevas marcas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        btmAgregarMarca->setText(QApplication::translate("marcas", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btmEliminarMarca->setToolTip(QApplication::translate("marcas", "Eliminar Marca", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        btmEliminarMarca->setWhatsThis(QApplication::translate("marcas", "Elimine las marcas ya no utilizadas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        btmEliminarMarca->setText(QApplication::translate("marcas", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btmModificarMarca->setToolTip(QApplication::translate("marcas", "Modificar marca", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        btmModificarMarca->setWhatsThis(QApplication::translate("marcas", "Cambie el nombre de la marca", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        btmModificarMarca->setText(QApplication::translate("marcas", "...", 0, QApplication::UnicodeUTF8));
        labelMarcas->setText(QApplication::translate("marcas", "Marcas:", 0, QApplication::UnicodeUTF8));
        labelModelos->setText(QApplication::translate("marcas", "Modelos:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btmAgregarModelo->setToolTip(QApplication::translate("marcas", "Agregar modelos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btmAgregarModelo->setText(QApplication::translate("marcas", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btmEliminarModelo->setToolTip(QApplication::translate("marcas", "Eliminar modelos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btmEliminarModelo->setText(QApplication::translate("marcas", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btmModificarModelo->setToolTip(QApplication::translate("marcas", "Modificar modelos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btmModificarModelo->setText(QApplication::translate("marcas", "...", 0, QApplication::UnicodeUTF8));
        btmSeleccionar->setText(QApplication::translate("marcas", "Seleccionar", 0, QApplication::UnicodeUTF8));
        btmCancelar->setText(QApplication::translate("marcas", "Cancelar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class marcas: public Ui_marcas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARCAS_H
