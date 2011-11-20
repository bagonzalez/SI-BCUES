/********************************************************************************
** Form generated from reading UI file 'seleccionarunidad.ui'
**
** Created: Thu Apr 21 08:48:21 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECCIONARUNIDAD_H
#define UI_SELECCIONARUNIDAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SeleccionarUnidad
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *unidad;
    QTextEdit *textEdit;

    void setupUi(QDialog *SeleccionarUnidad)
    {
        if (SeleccionarUnidad->objectName().isEmpty())
            SeleccionarUnidad->setObjectName(QString::fromUtf8("SeleccionarUnidad"));
        SeleccionarUnidad->setWindowModality(Qt::ApplicationModal);
        SeleccionarUnidad->resize(438, 225);
        SeleccionarUnidad->setMinimumSize(QSize(438, 225));
        SeleccionarUnidad->setMaximumSize(QSize(438, 225));
        buttonBox = new QDialogButtonBox(SeleccionarUnidad);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(280, 170, 141, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(SeleccionarUnidad);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 100, 201, 16));
        unidad = new QComboBox(SeleccionarUnidad);
        unidad->setObjectName(QString::fromUtf8("unidad"));
        unidad->setGeometry(QRect(30, 120, 281, 22));
        textEdit = new QTextEdit(SeleccionarUnidad);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 10, 401, 71));

        retranslateUi(SeleccionarUnidad);
        QObject::connect(buttonBox, SIGNAL(accepted()), SeleccionarUnidad, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SeleccionarUnidad, SLOT(reject()));

        QMetaObject::connectSlotsByName(SeleccionarUnidad);
    } // setupUi

    void retranslateUi(QDialog *SeleccionarUnidad)
    {
        SeleccionarUnidad->setWindowTitle(QApplication::translate("SeleccionarUnidad", "Seleccione la unidad", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SeleccionarUnidad", "Seleccione la unidad a  la que pertencera:", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("SeleccionarUnidad", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">A continuacion por favor seleccione la unidad a la que pertenecera, esta ya debe de haber sido creada previamente. Para poder acceder a las funciones del sistema debe poseer una cuenta, est\303\241 debera ser proporcionada por los administradores que actualmente estan registrados. </span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SeleccionarUnidad: public Ui_SeleccionarUnidad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECCIONARUNIDAD_H
