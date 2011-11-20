/********************************************************************************
** Form generated from reading UI file 'manualusuario.ui'
**
** Created: Thu Apr 21 08:48:21 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUALUSUARIO_H
#define UI_MANUALUSUARIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_manualUsuario
{
public:
    QGroupBox *groupBox;
    QWebView *webView;

    void setupUi(QWidget *manualUsuario)
    {
        if (manualUsuario->objectName().isEmpty())
            manualUsuario->setObjectName(QString::fromUtf8("manualUsuario"));
        manualUsuario->setWindowModality(Qt::ApplicationModal);
        manualUsuario->resize(882, 680);
        groupBox = new QGroupBox(manualUsuario);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 831, 621));
        webView = new QWebView(groupBox);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setGeometry(QRect(30, 30, 781, 571));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy);
        webView->setUrl(QUrl("file:///C:/SI-BCUES/ManualUsuario/MANUALDEUSUARIOSIBCUES.html"));

        retranslateUi(manualUsuario);

        QMetaObject::connectSlotsByName(manualUsuario);
    } // setupUi

    void retranslateUi(QWidget *manualUsuario)
    {
        manualUsuario->setWindowTitle(QApplication::translate("manualUsuario", "Manual de Usuario", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("manualUsuario", "Manual de Usuario", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class manualUsuario: public Ui_manualUsuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUALUSUARIO_H
