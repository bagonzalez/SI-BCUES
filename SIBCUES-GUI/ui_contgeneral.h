/********************************************************************************
** Form generated from reading ui file 'contgeneral.ui'
**
** Created: Sat 2. Jan 16:28:27 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONTGENERAL_H
#define UI_CONTGENERAL_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContGeneral
{
public:
    QAction *salirMain;
    QAction *action_Ayuda_Rapida;
    QAction *action_Acerca_de_Sic2008;
    QAction *action_Eliminar;
    QAction *actionCargar;
    QAction *actionAbonar;
    QAction *action_Activo;
    QAction *action_Pasivo;
    QAction *action_Capital;
    QWidget *centralwidget;
    QGroupBox *groupBox_5;
    QLineEdit *saldoDeudor;
    QPushButton *pushButton_3;
    QPushButton *crearRubro;
    QPushButton *crearCuenta;
    QGroupBox *groupBox_6;
    QLineEdit *saldoAcreedor;
    QPushButton *transaccion;
    QTreeWidget *Catalogo;
    QLabel *label;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox;
    QLineEdit *codigoCuenta;
    QGroupBox *groupBox_2;
    QLineEdit *debe;
    QGroupBox *groupBox_3;
    QLineEdit *haber;
    QGroupBox *groupBox_4;
    QTextEdit *textEdit;
    QPushButton *crearEspecifico;
    QToolButton *botonBuscar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ContGeneral)
    {
        if (ContGeneral->objectName().isEmpty())
            ContGeneral->setObjectName(QString::fromUtf8("ContGeneral"));
        ContGeneral->setWindowModality(Qt::ApplicationModal);
        ContGeneral->resize(900, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ContGeneral->sizePolicy().hasHeightForWidth());
        ContGeneral->setSizePolicy(sizePolicy);
        ContGeneral->setMinimumSize(QSize(900, 600));
        ContGeneral->setMaximumSize(QSize(900, 600));
        QFont font;
        ContGeneral->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/addressbook.png"), QSize(), QIcon::Normal, QIcon::Off);
        ContGeneral->setWindowIcon(icon);
        ContGeneral->setStyleSheet(QString::fromUtf8(""));
        ContGeneral->setLocale(QLocale(QLocale::Spanish, QLocale::ElSalvador));
        salirMain = new QAction(ContGeneral);
        salirMain->setObjectName(QString::fromUtf8("salirMain"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("iconos/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        salirMain->setIcon(icon1);
        action_Ayuda_Rapida = new QAction(ContGeneral);
        action_Ayuda_Rapida->setObjectName(QString::fromUtf8("action_Ayuda_Rapida"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("iconos/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Ayuda_Rapida->setIcon(icon2);
        action_Acerca_de_Sic2008 = new QAction(ContGeneral);
        action_Acerca_de_Sic2008->setObjectName(QString::fromUtf8("action_Acerca_de_Sic2008"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("iconos/about_kde.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Acerca_de_Sic2008->setIcon(icon3);
        action_Eliminar = new QAction(ContGeneral);
        action_Eliminar->setObjectName(QString::fromUtf8("action_Eliminar"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("iconos/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Eliminar->setIcon(icon4);
        actionCargar = new QAction(ContGeneral);
        actionCargar->setObjectName(QString::fromUtf8("actionCargar"));
        actionAbonar = new QAction(ContGeneral);
        actionAbonar->setObjectName(QString::fromUtf8("actionAbonar"));
        action_Activo = new QAction(ContGeneral);
        action_Activo->setObjectName(QString::fromUtf8("action_Activo"));
        action_Pasivo = new QAction(ContGeneral);
        action_Pasivo->setObjectName(QString::fromUtf8("action_Pasivo"));
        action_Capital = new QAction(ContGeneral);
        action_Capital->setObjectName(QString::fromUtf8("action_Capital"));
        centralwidget = new QWidget(ContGeneral);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(610, 150, 141, 71));
        saldoDeudor = new QLineEdit(groupBox_5);
        saldoDeudor->setObjectName(QString::fromUtf8("saldoDeudor"));
        saldoDeudor->setGeometry(QRect(10, 30, 111, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        saldoDeudor->setFont(font1);
        saldoDeudor->setLayoutDirection(Qt::RightToLeft);
        saldoDeudor->setReadOnly(true);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(770, 540, 121, 31));
        crearRubro = new QPushButton(centralwidget);
        crearRubro->setObjectName(QString::fromUtf8("crearRubro"));
        crearRubro->setGeometry(QRect(20, 540, 121, 31));
        crearCuenta = new QPushButton(centralwidget);
        crearCuenta->setObjectName(QString::fromUtf8("crearCuenta"));
        crearCuenta->setGeometry(QRect(150, 540, 121, 31));
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(750, 150, 141, 71));
        saldoAcreedor = new QLineEdit(groupBox_6);
        saldoAcreedor->setObjectName(QString::fromUtf8("saldoAcreedor"));
        saldoAcreedor->setGeometry(QRect(10, 30, 121, 25));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        saldoAcreedor->setFont(font2);
        saldoAcreedor->setLayoutDirection(Qt::RightToLeft);
        saldoAcreedor->setReadOnly(true);
        transaccion = new QPushButton(centralwidget);
        transaccion->setObjectName(QString::fromUtf8("transaccion"));
        transaccion->setGeometry(QRect(430, 540, 121, 31));
        Catalogo = new QTreeWidget(centralwidget);
        Catalogo->setObjectName(QString::fromUtf8("Catalogo"));
        Catalogo->setGeometry(QRect(10, 20, 580, 501));
        Catalogo->setMaximumSize(QSize(580, 680));
        Catalogo->setLocale(QLocale(QLocale::Spanish, QLocale::ElSalvador));
        Catalogo->setAlternatingRowColors(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(610, 420, 46, 71));
        label->setPixmap(QPixmap(QString::fromUtf8(":/iconos/kedit.png")));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(670, 420, 221, 101));
        textBrowser->setFrameShape(QFrame::WinPanel);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(610, 10, 279, 49));
        codigoCuenta = new QLineEdit(groupBox);
        codigoCuenta->setObjectName(QString::fromUtf8("codigoCuenta"));
        codigoCuenta->setGeometry(QRect(10, 20, 261, 22));
        codigoCuenta->setReadOnly(true);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(610, 60, 139, 79));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        debe = new QLineEdit(groupBox_2);
        debe->setObjectName(QString::fromUtf8("debe"));
        debe->setGeometry(QRect(10, 30, 113, 22));
        debe->setLayoutDirection(Qt::RightToLeft);
        debe->setReadOnly(true);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(750, 60, 139, 79));
        haber = new QLineEdit(groupBox_3);
        haber->setObjectName(QString::fromUtf8("haber"));
        haber->setGeometry(QRect(10, 30, 121, 25));
        haber->setLayoutDirection(Qt::RightToLeft);
        haber->setReadOnly(true);
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(610, 230, 279, 179));
        textEdit = new QTextEdit(groupBox_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 20, 261, 151));
        textEdit->setReadOnly(true);
        crearEspecifico = new QPushButton(centralwidget);
        crearEspecifico->setObjectName(QString::fromUtf8("crearEspecifico"));
        crearEspecifico->setGeometry(QRect(280, 540, 111, 31));
        botonBuscar = new QToolButton(centralwidget);
        botonBuscar->setObjectName(QString::fromUtf8("botonBuscar"));
        botonBuscar->setGeometry(QRect(570, 540, 41, 31));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/iconos/default-applications-capplet.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonBuscar->setIcon(icon5);
        botonBuscar->setIconSize(QSize(34, 34));
        ContGeneral->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ContGeneral);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ContGeneral->setStatusBar(statusbar);

        retranslateUi(ContGeneral);
        QObject::connect(salirMain, SIGNAL(activated()), ContGeneral, SLOT(close()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), ContGeneral, SLOT(close()));

        QMetaObject::connectSlotsByName(ContGeneral);
    } // setupUi

    void retranslateUi(QMainWindow *ContGeneral)
    {
        ContGeneral->setWindowTitle(QApplication::translate("ContGeneral", "Catalogo Contable", 0, QApplication::UnicodeUTF8));
        salirMain->setText(QApplication::translate("ContGeneral", "&Salir", 0, QApplication::UnicodeUTF8));
        action_Ayuda_Rapida->setText(QApplication::translate("ContGeneral", "&Ayuda Rapida", 0, QApplication::UnicodeUTF8));
        action_Acerca_de_Sic2008->setText(QApplication::translate("ContGeneral", "&Acerca de Sic2008", 0, QApplication::UnicodeUTF8));
        action_Eliminar->setText(QApplication::translate("ContGeneral", "&Eliminar", 0, QApplication::UnicodeUTF8));
        actionCargar->setText(QApplication::translate("ContGeneral", "Cargar", 0, QApplication::UnicodeUTF8));
        actionAbonar->setText(QApplication::translate("ContGeneral", "Abonar", 0, QApplication::UnicodeUTF8));
        action_Activo->setText(QApplication::translate("ContGeneral", "&Activo", 0, QApplication::UnicodeUTF8));
        action_Pasivo->setText(QApplication::translate("ContGeneral", "&Pasivo", 0, QApplication::UnicodeUTF8));
        action_Capital->setText(QApplication::translate("ContGeneral", "&Capital", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("ContGeneral", "Saldo Deudor", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("ContGeneral", "Salir", 0, QApplication::UnicodeUTF8));
        crearRubro->setText(QApplication::translate("ContGeneral", "Crear Rubro", 0, QApplication::UnicodeUTF8));
        crearCuenta->setText(QApplication::translate("ContGeneral", "Crear Cuenta", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("ContGeneral", "Saldo Acreedor", 0, QApplication::UnicodeUTF8));
        transaccion->setText(QApplication::translate("ContGeneral", "Crear Transaccion", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = Catalogo->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("ContGeneral", "Catalogo de Cuentas", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("ContGeneral", "Codigo", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        textBrowser->setHtml(QApplication::translate("ContGeneral", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">El catalogo de cuentas le permite observar los diferentes saldos en las cuentas, ademas puede hacer asientos contables en </span><span style=\" font-size:8pt; font-weight:600;\">Crear Transaccion. </span><span style=\" font-size:8pt;\">Ademas puede crear cuentas y categorias, para conglomerar subcuentas.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ContGeneral", "Nombre de la Cuenta", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ContGeneral", "Debe", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("ContGeneral", "Haber", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("ContGeneral", "Descripci\303\263n", 0, QApplication::UnicodeUTF8));
        crearEspecifico->setText(QApplication::translate("ContGeneral", "Crear Especifico", 0, QApplication::UnicodeUTF8));
        botonBuscar->setText(QApplication::translate("ContGeneral", "...", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ContGeneral);
    } // retranslateUi

};

namespace Ui {
    class ContGeneral: public Ui_ContGeneral {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTGENERAL_H
