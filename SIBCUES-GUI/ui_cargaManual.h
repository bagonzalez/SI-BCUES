/********************************************************************************
** Form generated from reading UI file 'cargaManual.ui'
**
** Created: Mon 19. Jul 20:18:05 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARGAMANUAL_H
#define UI_CARGAMANUAL_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cargaManual
{
public:
    QWidget *verticalLayout;
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox_10;
    QLabel *label;
    QLabel *numeroTrans;
    QLabel *label_3;
    QDateEdit *fecha;
    QToolButton *nuevaTransaccion;
    QToolButton *cancelarTran;
    QGroupBox *groupBox_5;
    QTableWidget *asientosContables;
    QGroupBox *groupBox;
    QTreeWidget *catalogo;
    QGroupBox *groupBox_6;
    QPushButton *eliminar;
    QPushButton *finalizar;
    QPushButton *partidaDoble;
    QGroupBox *groupBox_7;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QGroupBox *groupBox_8;
    QLineEdit *debe;
    QGroupBox *groupBox_9;
    QLineEdit *haber;
    QLabel *label_2;
    QLineEdit *cuenta;
    QTextBrowser *descripcion;
    QGroupBox *groupBox_3;
    QDoubleSpinBox *importe;
    QGroupBox *groupBox_4;
    QRadioButton *cargo;
    QRadioButton *abono;
    QPushButton *aplicar;

    void setupUi(QDialog *cargaManual)
    {
        if (cargaManual->objectName().isEmpty())
            cargaManual->setObjectName(QString::fromUtf8("cargaManual"));
        cargaManual->setWindowModality(Qt::ApplicationModal);
        cargaManual->resize(962, 638);
        cargaManual->setMinimumSize(QSize(962, 638));
        cargaManual->setMaximumSize(QSize(962, 638));
        verticalLayout = new QWidget(cargaManual);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setGeometry(QRect(10, 10, 941, 51));
        vboxLayout = new QVBoxLayout(verticalLayout);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_10 = new QGroupBox(verticalLayout);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        label = new QLabel(groupBox_10);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 131, 16));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        numeroTrans = new QLabel(groupBox_10);
        numeroTrans->setObjectName(QString::fromUtf8("numeroTrans"));
        numeroTrans->setGeometry(QRect(170, 20, 54, 16));
        numeroTrans->setFont(font);
        label_3 = new QLabel(groupBox_10);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 20, 42, 17));
        fecha = new QDateEdit(groupBox_10);
        fecha->setObjectName(QString::fromUtf8("fecha"));
        fecha->setGeometry(QRect(410, 20, 110, 25));
        fecha->setReadOnly(true);
        nuevaTransaccion = new QToolButton(groupBox_10);
        nuevaTransaccion->setObjectName(QString::fromUtf8("nuevaTransaccion"));
        nuevaTransaccion->setGeometry(QRect(830, 10, 41, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        nuevaTransaccion->setIcon(icon);
        nuevaTransaccion->setIconSize(QSize(24, 24));
        cancelarTran = new QToolButton(groupBox_10);
        cancelarTran->setObjectName(QString::fromUtf8("cancelarTran"));
        cancelarTran->setGeometry(QRect(880, 10, 41, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelarTran->setIcon(icon1);
        cancelarTran->setIconSize(QSize(24, 24));

        vboxLayout->addWidget(groupBox_10);

        groupBox_5 = new QGroupBox(cargaManual);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(340, 70, 611, 231));
        asientosContables = new QTableWidget(groupBox_5);
        asientosContables->setObjectName(QString::fromUtf8("asientosContables"));
        asientosContables->setGeometry(QRect(10, 23, 581, 201));
        asientosContables->setColumnCount(0);
        groupBox = new QGroupBox(cargaManual);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 311, 551));
        catalogo = new QTreeWidget(groupBox);
        catalogo->setObjectName(QString::fromUtf8("catalogo"));
        catalogo->setGeometry(QRect(10, 20, 291, 521));
        groupBox_6 = new QGroupBox(cargaManual);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(340, 310, 611, 71));
        eliminar = new QPushButton(groupBox_6);
        eliminar->setObjectName(QString::fromUtf8("eliminar"));
        eliminar->setGeometry(QRect(220, 30, 171, 27));
        eliminar->setIcon(icon1);
        finalizar = new QPushButton(groupBox_6);
        finalizar->setObjectName(QString::fromUtf8("finalizar"));
        finalizar->setGeometry(QRect(420, 30, 161, 27));
        partidaDoble = new QPushButton(groupBox_6);
        partidaDoble->setObjectName(QString::fromUtf8("partidaDoble"));
        partidaDoble->setGeometry(QRect(20, 30, 161, 27));
        partidaDoble->setDefault(true);
        groupBox_7 = new QGroupBox(cargaManual);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(340, 390, 611, 231));
        groupBox_2 = new QGroupBox(groupBox_7);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 20, 571, 141));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(350, 20, 81, 17));
        groupBox_8 = new QGroupBox(groupBox_2);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(20, 70, 151, 61));
        debe = new QLineEdit(groupBox_8);
        debe->setObjectName(QString::fromUtf8("debe"));
        debe->setGeometry(QRect(10, 20, 131, 25));
        debe->setReadOnly(true);
        groupBox_9 = new QGroupBox(groupBox_2);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(180, 70, 151, 61));
        haber = new QLineEdit(groupBox_9);
        haber->setObjectName(QString::fromUtf8("haber"));
        haber->setGeometry(QRect(10, 20, 131, 25));
        haber->setReadOnly(true);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 58, 17));
        cuenta = new QLineEdit(groupBox_2);
        cuenta->setObjectName(QString::fromUtf8("cuenta"));
        cuenta->setGeometry(QRect(20, 40, 311, 25));
        cuenta->setReadOnly(true);
        descripcion = new QTextBrowser(groupBox_2);
        descripcion->setObjectName(QString::fromUtf8("descripcion"));
        descripcion->setGeometry(QRect(350, 40, 211, 94));
        groupBox_3 = new QGroupBox(groupBox_7);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(270, 170, 201, 51));
        importe = new QDoubleSpinBox(groupBox_3);
        importe->setObjectName(QString::fromUtf8("importe"));
        importe->setGeometry(QRect(20, 20, 171, 25));
        importe->setLayoutDirection(Qt::RightToLeft);
        importe->setLocale(QLocale(QLocale::Spanish, QLocale::ElSalvador));
        importe->setWrapping(false);
        importe->setFrame(true);
        importe->setButtonSymbols(QAbstractSpinBox::NoButtons);
        importe->setKeyboardTracking(true);
        importe->setDecimals(2);
        importe->setMaximum(1e+07);
        groupBox_4 = new QGroupBox(groupBox_7);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 170, 241, 51));
        cargo = new QRadioButton(groupBox_4);
        cargo->setObjectName(QString::fromUtf8("cargo"));
        cargo->setGeometry(QRect(30, 20, 91, 22));
        abono = new QRadioButton(groupBox_4);
        abono->setObjectName(QString::fromUtf8("abono"));
        abono->setGeometry(QRect(130, 20, 91, 22));
        aplicar = new QPushButton(groupBox_7);
        aplicar->setObjectName(QString::fromUtf8("aplicar"));
        aplicar->setGeometry(QRect(500, 180, 71, 41));
        aplicar->setLayoutDirection(Qt::LeftToRight);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/button_ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        aplicar->setIcon(icon2);
        QWidget::setTabOrder(partidaDoble, cargo);
        QWidget::setTabOrder(cargo, abono);
        QWidget::setTabOrder(abono, importe);
        QWidget::setTabOrder(importe, abono);
        QWidget::setTabOrder(abono, cargo);
        QWidget::setTabOrder(cargo, catalogo);
        QWidget::setTabOrder(catalogo, asientosContables);
        QWidget::setTabOrder(asientosContables, importe);
        QWidget::setTabOrder(importe, fecha);
        QWidget::setTabOrder(fecha, finalizar);
        QWidget::setTabOrder(finalizar, asientosContables);
        QWidget::setTabOrder(asientosContables, eliminar);

        retranslateUi(cargaManual);

        QMetaObject::connectSlotsByName(cargaManual);
    } // setupUi

    void retranslateUi(QDialog *cargaManual)
    {
        cargaManual->setWindowTitle(QApplication::translate("cargaManual", "Transaccion Manual", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("cargaManual", "Informacion:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("cargaManual", "Transaccion:  #", 0, QApplication::UnicodeUTF8));
        numeroTrans->setText(QApplication::translate("cargaManual", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("cargaManual", "Fecha:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        nuevaTransaccion->setToolTip(QApplication::translate("cargaManual", "Nueva Transaccion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nuevaTransaccion->setText(QApplication::translate("cargaManual", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cancelarTran->setToolTip(QApplication::translate("cargaManual", "Cancelar la transaccion actual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cancelarTran->setText(QApplication::translate("cargaManual", "...", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("cargaManual", "Asientos Contables", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("cargaManual", "Catalogo de Cuentas", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = catalogo->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("cargaManual", "Catalogo de Cuentas", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("cargaManual", "Opciones", 0, QApplication::UnicodeUTF8));
        eliminar->setText(QApplication::translate("cargaManual", "Eliminar Partida Doble", 0, QApplication::UnicodeUTF8));
        finalizar->setText(QApplication::translate("cargaManual", "Finalizar", 0, QApplication::UnicodeUTF8));
        partidaDoble->setText(QApplication::translate("cargaManual", "Partida Doble", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("cargaManual", "Informacion de la linea de Asientos Contables", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("cargaManual", "Cuenta:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("cargaManual", "Descripcion:", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("cargaManual", "Debe", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("cargaManual", "Haber", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("cargaManual", "Nombre:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("cargaManual", "Importe a efectuar", 0, QApplication::UnicodeUTF8));
        importe->setPrefix(QString());
        groupBox_4->setTitle(QApplication::translate("cargaManual", "Tipo asiento:", 0, QApplication::UnicodeUTF8));
        cargo->setText(QApplication::translate("cargaManual", "Cargo", 0, QApplication::UnicodeUTF8));
        abono->setText(QApplication::translate("cargaManual", "Abono", 0, QApplication::UnicodeUTF8));
        aplicar->setText(QApplication::translate("cargaManual", "Aplicar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class cargaManual: public Ui_cargaManual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARGAMANUAL_H
