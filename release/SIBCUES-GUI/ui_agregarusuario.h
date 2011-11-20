/********************************************************************************
** Form generated from reading UI file 'agregarusuario.ui'
**
** Created: Sat 14. May 00:05:01 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGREGARUSUARIO_H
#define UI_AGREGARUSUARIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_agregarUsuario
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QListWidget *listWidget;

    void setupUi(QWidget *agregarUsuario)
    {
        if (agregarUsuario->objectName().isEmpty())
            agregarUsuario->setObjectName(QString::fromUtf8("agregarUsuario"));
        agregarUsuario->resize(480, 640);
        gridLayout = new QGridLayout(agregarUsuario);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(agregarUsuario);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(agregarUsuario);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

        groupBox = new QGroupBox(agregarUsuario);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 30, 421, 337));

        gridLayout->addWidget(groupBox, 0, 0, 1, 2);


        retranslateUi(agregarUsuario);

        QMetaObject::connectSlotsByName(agregarUsuario);
    } // setupUi

    void retranslateUi(QWidget *agregarUsuario)
    {
        agregarUsuario->setWindowTitle(QApplication::translate("agregarUsuario", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("agregarUsuario", "Agregar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("agregarUsuario", "Eliminar", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("agregarUsuario", "Usuarios:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class agregarUsuario: public Ui_agregarUsuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGREGARUSUARIO_H
