/********************************************************************************
** Form generated from reading UI file 'catalogocontable.ui'
**
** Created: Sat 14. May 00:05:02 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATALOGOCONTABLE_H
#define UI_CATALOGOCONTABLE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatalogoContable
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *Catalogo;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *codigoCuenta;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *debe;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *haber;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *saldoDeudor;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *saldoAcreedor;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QTextEdit *textEdit;
    QPushButton *crearRubro;
    QPushButton *crearCuenta;
    QPushButton *crearEspecifico;
    QPushButton *transaccion;
    QToolButton *pushButton_3;
    QToolButton *btmSeleccionar;
    QToolButton *botonBuscar;

    void setupUi(QDialog *CatalogoContable)
    {
        if (CatalogoContable->objectName().isEmpty())
            CatalogoContable->setObjectName(QString::fromUtf8("CatalogoContable"));
        CatalogoContable->resize(900, 590);
        gridLayout = new QGridLayout(CatalogoContable);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Catalogo = new QTreeWidget(CatalogoContable);
        Catalogo->setObjectName(QString::fromUtf8("Catalogo"));
        Catalogo->setMaximumSize(QSize(580, 680));
        Catalogo->setLocale(QLocale(QLocale::Spanish, QLocale::ElSalvador));
        Catalogo->setAlternatingRowColors(true);

        gridLayout->addWidget(Catalogo, 1, 0, 5, 4);

        groupBox = new QGroupBox(CatalogoContable);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        codigoCuenta = new QLineEdit(groupBox);
        codigoCuenta->setObjectName(QString::fromUtf8("codigoCuenta"));
        codigoCuenta->setReadOnly(true);

        verticalLayout->addWidget(codigoCuenta);


        gridLayout->addWidget(groupBox, 1, 4, 1, 5);

        groupBox_2 = new QGroupBox(CatalogoContable);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        debe = new QLineEdit(groupBox_2);
        debe->setObjectName(QString::fromUtf8("debe"));
        debe->setLayoutDirection(Qt::RightToLeft);
        debe->setReadOnly(true);

        verticalLayout_2->addWidget(debe);


        gridLayout->addWidget(groupBox_2, 2, 4, 1, 2);

        groupBox_3 = new QGroupBox(CatalogoContable);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        haber = new QLineEdit(groupBox_3);
        haber->setObjectName(QString::fromUtf8("haber"));
        haber->setLayoutDirection(Qt::RightToLeft);
        haber->setReadOnly(true);

        verticalLayout_3->addWidget(haber);


        gridLayout->addWidget(groupBox_3, 2, 6, 1, 3);

        groupBox_5 = new QGroupBox(CatalogoContable);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        saldoDeudor = new QLineEdit(groupBox_5);
        saldoDeudor->setObjectName(QString::fromUtf8("saldoDeudor"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(9);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        saldoDeudor->setFont(font);
        saldoDeudor->setLayoutDirection(Qt::RightToLeft);
        saldoDeudor->setReadOnly(true);

        verticalLayout_4->addWidget(saldoDeudor);


        gridLayout->addWidget(groupBox_5, 3, 4, 1, 2);

        groupBox_6 = new QGroupBox(CatalogoContable);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_5 = new QVBoxLayout(groupBox_6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        saldoAcreedor = new QLineEdit(groupBox_6);
        saldoAcreedor->setObjectName(QString::fromUtf8("saldoAcreedor"));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        saldoAcreedor->setFont(font1);
        saldoAcreedor->setLayoutDirection(Qt::RightToLeft);
        saldoAcreedor->setReadOnly(true);

        verticalLayout_5->addWidget(saldoAcreedor);


        gridLayout->addWidget(groupBox_6, 3, 6, 1, 3);

        groupBox_4 = new QGroupBox(CatalogoContable);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        textEdit = new QTextEdit(groupBox_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout_6->addWidget(textEdit);


        gridLayout->addWidget(groupBox_4, 4, 4, 1, 5);

        crearRubro = new QPushButton(CatalogoContable);
        crearRubro->setObjectName(QString::fromUtf8("crearRubro"));

        gridLayout->addWidget(crearRubro, 6, 0, 1, 1);

        crearCuenta = new QPushButton(CatalogoContable);
        crearCuenta->setObjectName(QString::fromUtf8("crearCuenta"));

        gridLayout->addWidget(crearCuenta, 6, 1, 1, 1);

        crearEspecifico = new QPushButton(CatalogoContable);
        crearEspecifico->setObjectName(QString::fromUtf8("crearEspecifico"));

        gridLayout->addWidget(crearEspecifico, 6, 2, 1, 1);

        transaccion = new QPushButton(CatalogoContable);
        transaccion->setObjectName(QString::fromUtf8("transaccion"));

        gridLayout->addWidget(transaccion, 6, 3, 1, 1);

        pushButton_3 = new QToolButton(CatalogoContable);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(34, 34));

        gridLayout->addWidget(pushButton_3, 0, 8, 1, 1);

        btmSeleccionar = new QToolButton(CatalogoContable);
        btmSeleccionar->setObjectName(QString::fromUtf8("btmSeleccionar"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/button_ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        btmSeleccionar->setIcon(icon1);
        btmSeleccionar->setIconSize(QSize(34, 34));

        gridLayout->addWidget(btmSeleccionar, 0, 7, 1, 1);

        botonBuscar = new QToolButton(CatalogoContable);
        botonBuscar->setObjectName(QString::fromUtf8("botonBuscar"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Iconos/iconos/buscar.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonBuscar->setIcon(icon2);
        botonBuscar->setIconSize(QSize(34, 34));

        gridLayout->addWidget(botonBuscar, 0, 6, 1, 1);


        retranslateUi(CatalogoContable);

        QMetaObject::connectSlotsByName(CatalogoContable);
    } // setupUi

    void retranslateUi(QDialog *CatalogoContable)
    {
        CatalogoContable->setWindowTitle(QApplication::translate("CatalogoContable", "Catalogo Contable", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = Catalogo->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("CatalogoContable", "Catalogo de Cuentas", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("CatalogoContable", "Codigo", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CatalogoContable", "Nombre de la Cuenta", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CatalogoContable", "Debe", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CatalogoContable", "Haber", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("CatalogoContable", "Saldo Deudor", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("CatalogoContable", "Saldo Acreedor", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("CatalogoContable", "Descripci\303\263n", 0, QApplication::UnicodeUTF8));
        crearRubro->setText(QApplication::translate("CatalogoContable", "Crear Rubro", 0, QApplication::UnicodeUTF8));
        crearCuenta->setText(QApplication::translate("CatalogoContable", "Crear Cuenta", 0, QApplication::UnicodeUTF8));
        crearEspecifico->setText(QApplication::translate("CatalogoContable", "Crear Especifico", 0, QApplication::UnicodeUTF8));
        transaccion->setText(QApplication::translate("CatalogoContable", "Crear Transaccion", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("CatalogoContable", "...", 0, QApplication::UnicodeUTF8));
        btmSeleccionar->setText(QString());
        botonBuscar->setText(QApplication::translate("CatalogoContable", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatalogoContable: public Ui_CatalogoContable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATALOGOCONTABLE_H
