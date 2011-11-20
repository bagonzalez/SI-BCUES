/********************************************************************************
** Form generated from reading UI file 'primerinicio.ui'
**
** Created: Thu Apr 21 08:48:21 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMERINICIO_H
#define UI_PRIMERINICIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrimerInicio
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *codigoUnidad;
    QLabel *label_3;
    QLineEdit *lineaUnidad;
    QLabel *label;
    QLineEdit *nombreUnidad;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QLineEdit *nombreBase;
    QLabel *label_10;
    QLineEdit *usuarioBase;
    QLabel *label_8;
    QLineEdit *contraseniaBase;
    QLabel *label_11;
    QLineEdit *servidor;
    QLabel *label_12;
    QLineEdit *numeroPuerto;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLineEdit *cuenta;
    QLabel *label_13;
    QLabel *label_5;
    QLineEdit *password;
    QLineEdit *repassword;
    QLabel *label_6;
    QLineEdit *nombreUsuario;
    QLabel *label_7;
    QLineEdit *apelldosUsuario;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *textBrowser;
    QLabel *label_14;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_15;
    QRadioButton *btnNuevaConf;
    QRadioButton *btnExisteConf;
    QSpacerItem *horizontalSpacer;
    QPushButton *botonCancelar;
    QPushButton *botonAceptar;
    QGroupBox *boxotrasConfig;
    QFormLayout *formLayout;
    QLabel *label_16;
    QLineEdit *director;
    QLabel *label_17;
    QLineEdit *jefeActivo;

    void setupUi(QWidget *PrimerInicio)
    {
        if (PrimerInicio->objectName().isEmpty())
            PrimerInicio->setObjectName(QString::fromUtf8("PrimerInicio"));
        PrimerInicio->setWindowModality(Qt::ApplicationModal);
        PrimerInicio->resize(632, 617);
        gridLayout = new QGridLayout(PrimerInicio);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(PrimerInicio);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        codigoUnidad = new QLineEdit(groupBox);
        codigoUnidad->setObjectName(QString::fromUtf8("codigoUnidad"));
        codigoUnidad->setMaxLength(3);

        gridLayout_2->addWidget(codigoUnidad, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        lineaUnidad = new QLineEdit(groupBox);
        lineaUnidad->setObjectName(QString::fromUtf8("lineaUnidad"));
        lineaUnidad->setMaxLength(3);

        gridLayout_2->addWidget(lineaUnidad, 0, 3, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        nombreUnidad = new QLineEdit(groupBox);
        nombreUnidad->setObjectName(QString::fromUtf8("nombreUnidad"));
        nombreUnidad->setMaxLength(35);

        gridLayout_2->addWidget(nombreUnidad, 1, 1, 1, 3);


        gridLayout->addWidget(groupBox, 3, 0, 1, 2);

        groupBox_3 = new QGroupBox(PrimerInicio);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        nombreBase = new QLineEdit(groupBox_3);
        nombreBase->setObjectName(QString::fromUtf8("nombreBase"));

        verticalLayout->addWidget(nombreBase);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        usuarioBase = new QLineEdit(groupBox_3);
        usuarioBase->setObjectName(QString::fromUtf8("usuarioBase"));

        verticalLayout->addWidget(usuarioBase);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        contraseniaBase = new QLineEdit(groupBox_3);
        contraseniaBase->setObjectName(QString::fromUtf8("contraseniaBase"));
        contraseniaBase->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(contraseniaBase);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        servidor = new QLineEdit(groupBox_3);
        servidor->setObjectName(QString::fromUtf8("servidor"));

        verticalLayout->addWidget(servidor);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);

        numeroPuerto = new QLineEdit(groupBox_3);
        numeroPuerto->setObjectName(QString::fromUtf8("numeroPuerto"));

        verticalLayout->addWidget(numeroPuerto);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox_3, 3, 2, 3, 2);

        groupBox_2 = new QGroupBox(PrimerInicio);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        cuenta = new QLineEdit(groupBox_2);
        cuenta->setObjectName(QString::fromUtf8("cuenta"));
        cuenta->setMaxLength(15);

        gridLayout_3->addWidget(cuenta, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        password = new QLineEdit(groupBox_2);
        password->setObjectName(QString::fromUtf8("password"));
        password->setMaxLength(10);
        password->setEchoMode(QLineEdit::Password);

        gridLayout_3->addWidget(password, 1, 1, 1, 1);

        repassword = new QLineEdit(groupBox_2);
        repassword->setObjectName(QString::fromUtf8("repassword"));
        repassword->setEchoMode(QLineEdit::Password);

        gridLayout_3->addWidget(repassword, 1, 2, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        nombreUsuario = new QLineEdit(groupBox_2);
        nombreUsuario->setObjectName(QString::fromUtf8("nombreUsuario"));
        nombreUsuario->setMaxLength(30);

        gridLayout_3->addWidget(nombreUsuario, 2, 1, 1, 2);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 3, 0, 1, 1);

        apelldosUsuario = new QLineEdit(groupBox_2);
        apelldosUsuario->setObjectName(QString::fromUtf8("apelldosUsuario"));
        apelldosUsuario->setMaxLength(30);

        gridLayout_3->addWidget(apelldosUsuario, 3, 1, 1, 2);


        gridLayout->addWidget(groupBox_2, 5, 0, 1, 2);

        widget_2 = new QWidget(PrimerInicio);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        textBrowser = new QTextBrowser(widget_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setAcceptDrops(false);
        textBrowser->setAutoFillBackground(false);
        textBrowser->setAcceptRichText(false);

        horizontalLayout_2->addWidget(textBrowser);

        label_14 = new QLabel(widget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/iconos/kedit.png")));

        horizontalLayout_2->addWidget(label_14);


        gridLayout->addWidget(widget_2, 0, 0, 1, 4);

        widget = new QWidget(PrimerInicio);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_15 = new QLabel(widget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout->addWidget(label_15);

        btnNuevaConf = new QRadioButton(widget);
        btnNuevaConf->setObjectName(QString::fromUtf8("btnNuevaConf"));

        horizontalLayout->addWidget(btnNuevaConf);

        btnExisteConf = new QRadioButton(widget);
        btnExisteConf->setObjectName(QString::fromUtf8("btnExisteConf"));

        horizontalLayout->addWidget(btnExisteConf);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(widget, 1, 0, 1, 2);

        botonCancelar = new QPushButton(PrimerInicio);
        botonCancelar->setObjectName(QString::fromUtf8("botonCancelar"));

        gridLayout->addWidget(botonCancelar, 8, 3, 1, 1);

        botonAceptar = new QPushButton(PrimerInicio);
        botonAceptar->setObjectName(QString::fromUtf8("botonAceptar"));

        gridLayout->addWidget(botonAceptar, 8, 2, 1, 1);

        boxotrasConfig = new QGroupBox(PrimerInicio);
        boxotrasConfig->setObjectName(QString::fromUtf8("boxotrasConfig"));
        formLayout = new QFormLayout(boxotrasConfig);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_16 = new QLabel(boxotrasConfig);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_16);

        director = new QLineEdit(boxotrasConfig);
        director->setObjectName(QString::fromUtf8("director"));

        formLayout->setWidget(0, QFormLayout::FieldRole, director);

        label_17 = new QLabel(boxotrasConfig);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_17);

        jefeActivo = new QLineEdit(boxotrasConfig);
        jefeActivo->setObjectName(QString::fromUtf8("jefeActivo"));

        formLayout->setWidget(1, QFormLayout::FieldRole, jefeActivo);


        gridLayout->addWidget(boxotrasConfig, 4, 0, 1, 1);

        QWidget::setTabOrder(codigoUnidad, lineaUnidad);
        QWidget::setTabOrder(lineaUnidad, nombreUnidad);
        QWidget::setTabOrder(nombreUnidad, cuenta);
        QWidget::setTabOrder(cuenta, password);
        QWidget::setTabOrder(password, repassword);
        QWidget::setTabOrder(repassword, nombreUsuario);
        QWidget::setTabOrder(nombreUsuario, apelldosUsuario);
        QWidget::setTabOrder(apelldosUsuario, nombreBase);
        QWidget::setTabOrder(nombreBase, usuarioBase);
        QWidget::setTabOrder(usuarioBase, contraseniaBase);
        QWidget::setTabOrder(contraseniaBase, servidor);
        QWidget::setTabOrder(servidor, numeroPuerto);

        retranslateUi(PrimerInicio);

        QMetaObject::connectSlotsByName(PrimerInicio);
    } // setupUi

    void retranslateUi(QWidget *PrimerInicio)
    {
        PrimerInicio->setWindowTitle(QApplication::translate("PrimerInicio", "Configuraciones Iniciales", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PrimerInicio", "Datos Generales", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PrimerInicio", "Codigo Unidad:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PrimerInicio", "Linea de Trabajo:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PrimerInicio", "Nombre Unidad:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("PrimerInicio", "Conexion a la base de datos:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("PrimerInicio", "Nombre de la base:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("PrimerInicio", "Usuario:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("PrimerInicio", "Contrase\303\261a de conexion:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("PrimerInicio", "Servidor:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("PrimerInicio", "Puerto:", 0, QApplication::UnicodeUTF8));
        numeroPuerto->setText(QApplication::translate("PrimerInicio", "3306", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("PrimerInicio", "Cuenta de Administrador:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PrimerInicio", "Cuenta:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("PrimerInicio", "Re-Contrase\303\261a:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PrimerInicio", "Contrase\303\261a:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PrimerInicio", "Nombre:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PrimerInicio", "Apellidos:", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("PrimerInicio", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">Bienvenido, antes de iniciar por primera vez el sistema, es necesario que especifique, los datos generales de la Unidad, estos seran utilizado de forma predeterminada cada vez que inicie el sistema. Si lo que desea es instalar un cliente mas para una unidad ya existente puede, seleccionar  en tipo de configuracion 'ya existente'. Ademas de"
                        "bera proporcionar las opciones de conexion, esto lo puede consultar con el encargado del departamento de sistemas de su unidad.</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        label_14->setText(QString());
        label_15->setText(QApplication::translate("PrimerInicio", "Tipo configuracion:", 0, QApplication::UnicodeUTF8));
        btnNuevaConf->setText(QApplication::translate("PrimerInicio", "Nueva", 0, QApplication::UnicodeUTF8));
        btnExisteConf->setText(QApplication::translate("PrimerInicio", "Existente", 0, QApplication::UnicodeUTF8));
        botonCancelar->setText(QApplication::translate("PrimerInicio", "Cancelar", 0, QApplication::UnicodeUTF8));
        botonAceptar->setText(QApplication::translate("PrimerInicio", "Aceptar", 0, QApplication::UnicodeUTF8));
        boxotrasConfig->setTitle(QApplication::translate("PrimerInicio", "Otras configuraciones:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("PrimerInicio", "Director (a) Unidad:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("PrimerInicio", "Jefe activo fijo:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PrimerInicio: public Ui_PrimerInicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMERINICIO_H
