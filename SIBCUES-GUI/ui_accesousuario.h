/********************************************************************************
** Form generated from reading UI file 'accesousuario.ui'
**
** Created: Mon 19. Jul 20:18:06 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCESOUSUARIO_H
#define UI_ACCESOUSUARIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccesoUsuario
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *login;
    QLineEdit *password;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *boton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *AccesoUsuario)
    {
        if (AccesoUsuario->objectName().isEmpty())
            AccesoUsuario->setObjectName(QString::fromUtf8("AccesoUsuario"));
        AccesoUsuario->setWindowModality(Qt::ApplicationModal);
        AccesoUsuario->resize(315, 165);
        AccesoUsuario->setMaximumSize(QSize(347, 179));
        AccesoUsuario->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/empleados.png"), QSize(), QIcon::Normal, QIcon::Off);
        AccesoUsuario->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(AccesoUsuario);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(AccesoUsuario);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        login = new QLineEdit(groupBox);
        login->setObjectName(QString::fromUtf8("login"));

        gridLayout->addWidget(login, 0, 2, 1, 1);

        password = new QLineEdit(groupBox);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(password, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 1, 1, 1);

        boton = new QDialogButtonBox(AccesoUsuario);
        boton->setObjectName(QString::fromUtf8("boton"));
        boton->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(boton, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 2, 1, 1);


        retranslateUi(AccesoUsuario);

        QMetaObject::connectSlotsByName(AccesoUsuario);
    } // setupUi

    void retranslateUi(QWidget *AccesoUsuario)
    {
        AccesoUsuario->setWindowTitle(QApplication::translate("AccesoUsuario", "Ingreso al Sistema", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AccesoUsuario", "Ingrese los siguientes datos:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AccesoUsuario", "Contrase\303\261a", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AccesoUsuario", "Usuario:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AccesoUsuario: public Ui_AccesoUsuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCESOUSUARIO_H
