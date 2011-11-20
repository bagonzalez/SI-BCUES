/********************************************************************************
** Form generated from reading UI file 'dialogobuscarcuenta.ui'
**
** Created: Sat 14. May 00:05:02 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOBUSCARCUENTA_H
#define UI_DIALOGOBUSCARCUENTA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialogoBuscarCuenta
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *textoABuscar;
    QPushButton *btmBuscar;
    QPushButton *btmCancelar;
    QLabel *labelResultados;
    QTableWidget *tablaResultado;
    QTextBrowser *textoMarcado;
    QPushButton *btmSeleccionar;
    QLabel *label_2;

    void setupUi(QDialog *dialogoBuscarCuenta)
    {
        if (dialogoBuscarCuenta->objectName().isEmpty())
            dialogoBuscarCuenta->setObjectName(QString::fromUtf8("dialogoBuscarCuenta"));
        dialogoBuscarCuenta->setWindowModality(Qt::ApplicationModal);
        dialogoBuscarCuenta->resize(755, 433);
        gridLayout = new QGridLayout(dialogoBuscarCuenta);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(dialogoBuscarCuenta);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        textoABuscar = new QLineEdit(groupBox);
        textoABuscar->setObjectName(QString::fromUtf8("textoABuscar"));

        verticalLayout->addWidget(textoABuscar);


        gridLayout->addWidget(groupBox, 0, 0, 2, 2);

        btmBuscar = new QPushButton(dialogoBuscarCuenta);
        btmBuscar->setObjectName(QString::fromUtf8("btmBuscar"));

        gridLayout->addWidget(btmBuscar, 0, 2, 1, 1);

        btmCancelar = new QPushButton(dialogoBuscarCuenta);
        btmCancelar->setObjectName(QString::fromUtf8("btmCancelar"));

        gridLayout->addWidget(btmCancelar, 1, 2, 1, 1);

        labelResultados = new QLabel(dialogoBuscarCuenta);
        labelResultados->setObjectName(QString::fromUtf8("labelResultados"));

        gridLayout->addWidget(labelResultados, 2, 0, 1, 1);

        tablaResultado = new QTableWidget(dialogoBuscarCuenta);
        tablaResultado->setObjectName(QString::fromUtf8("tablaResultado"));
        tablaResultado->setAlternatingRowColors(true);

        gridLayout->addWidget(tablaResultado, 3, 0, 1, 1);

        textoMarcado = new QTextBrowser(dialogoBuscarCuenta);
        textoMarcado->setObjectName(QString::fromUtf8("textoMarcado"));

        gridLayout->addWidget(textoMarcado, 3, 1, 1, 2);

        btmSeleccionar = new QPushButton(dialogoBuscarCuenta);
        btmSeleccionar->setObjectName(QString::fromUtf8("btmSeleccionar"));

        gridLayout->addWidget(btmSeleccionar, 4, 0, 1, 1);

        label_2 = new QLabel(dialogoBuscarCuenta);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);


        retranslateUi(dialogoBuscarCuenta);
        QObject::connect(btmCancelar, SIGNAL(clicked()), dialogoBuscarCuenta, SLOT(close()));
        QObject::connect(tablaResultado, SIGNAL(doubleClicked(QModelIndex)), btmSeleccionar, SLOT(click()));

        QMetaObject::connectSlotsByName(dialogoBuscarCuenta);
    } // setupUi

    void retranslateUi(QDialog *dialogoBuscarCuenta)
    {
        dialogoBuscarCuenta->setWindowTitle(QApplication::translate("dialogoBuscarCuenta", "Buscar cuentas", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("dialogoBuscarCuenta", "Busqueda", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dialogoBuscarCuenta", "Ingrese la frase o palabra a buscar:", 0, QApplication::UnicodeUTF8));
        btmBuscar->setText(QApplication::translate("dialogoBuscarCuenta", "Buscar", 0, QApplication::UnicodeUTF8));
        btmCancelar->setText(QApplication::translate("dialogoBuscarCuenta", "Cancelar", 0, QApplication::UnicodeUTF8));
        labelResultados->setText(QApplication::translate("dialogoBuscarCuenta", "Resultados:", 0, QApplication::UnicodeUTF8));
        btmSeleccionar->setText(QApplication::translate("dialogoBuscarCuenta", "Seleccionar", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dialogoBuscarCuenta", "Descricpci\303\263n:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialogoBuscarCuenta: public Ui_dialogoBuscarCuenta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOBUSCARCUENTA_H
