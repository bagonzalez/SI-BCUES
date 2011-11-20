/********************************************************************************
** Form generated from reading UI file 'nuevaCuenta.ui'
**
** Created: Sat 14. May 00:05:01 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUEVACUENTA_H
#define UI_NUEVACUENTA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogoNuevaCuenta
{
public:
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox_3;
    QLineEdit *codigoManual;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QDialog *DialogoNuevaCuenta)
    {
        if (DialogoNuevaCuenta->objectName().isEmpty())
            DialogoNuevaCuenta->setObjectName(QString::fromUtf8("DialogoNuevaCuenta"));
        DialogoNuevaCuenta->setWindowModality(Qt::ApplicationModal);
        DialogoNuevaCuenta->resize(400, 350);
        DialogoNuevaCuenta->setMinimumSize(QSize(400, 350));
        DialogoNuevaCuenta->setMaximumSize(QSize(400, 350));
        groupBox = new QGroupBox(DialogoNuevaCuenta);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 80, 361, 71));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 331, 25));
        groupBox_2 = new QGroupBox(DialogoNuevaCuenta);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 160, 361, 131));
        groupBox_2->setMinimumSize(QSize(0, 0));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 20, 331, 94));
        buttonBox = new QDialogButtonBox(DialogoNuevaCuenta);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 300, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox_3 = new QGroupBox(DialogoNuevaCuenta);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 10, 361, 61));
        codigoManual = new QLineEdit(groupBox_3);
        codigoManual->setObjectName(QString::fromUtf8("codigoManual"));
        codigoManual->setEnabled(true);
        codigoManual->setGeometry(QRect(10, 20, 101, 20));
        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(140, 10, 84, 18));
        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(140, 30, 84, 18));
        QWidget::setTabOrder(lineEdit, textEdit);
        QWidget::setTabOrder(textEdit, buttonBox);
        QWidget::setTabOrder(buttonBox, codigoManual);

        retranslateUi(DialogoNuevaCuenta);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoNuevaCuenta, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoNuevaCuenta, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoNuevaCuenta);
    } // setupUi

    void retranslateUi(QDialog *DialogoNuevaCuenta)
    {
        DialogoNuevaCuenta->setWindowTitle(QApplication::translate("DialogoNuevaCuenta", "Crear Nueva Cuenta", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DialogoNuevaCuenta", "Nombre de la Cuenta", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DialogoNuevaCuenta", "Descripci\303\263n", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("DialogoNuevaCuenta", "Codigo:", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("DialogoNuevaCuenta", "Ingreso", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("DialogoNuevaCuenta", "Gasto", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogoNuevaCuenta: public Ui_DialogoNuevaCuenta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUEVACUENTA_H
