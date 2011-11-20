/********************************************************************************
** Form generated from reading UI file 'descargobienesmb.ui'
**
** Created: Thu Apr 21 08:48:21 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESCARGOBIENESMB_H
#define UI_DESCARGOBIENESMB_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DescargoBienesMB
{
public:
    QLineEdit *motivo;
    QLineEdit *observaciones;
    QLabel *label_16;
    QPushButton *cancelar;
    QLineEdit *nombreUnidad;
    QPushButton *finalizarTransaccion;
    QLineEdit *nombreDpto;
    QLineEdit *totalIngreso;
    QLabel *label_14;
    QToolButton *nuevoBien;
    QLabel *label_7;
    QTableWidget *tablaBienes;
    QGroupBox *groupBox_5;
    QGroupBox *groupBox_6;
    QLabel *label_8;
    QLineEdit *cuentaAsignada;
    QLabel *label_19;
    QLineEdit *nombreEspecifico;
    QLabel *label_15;
    QDoubleSpinBox *valorBien;
    QLineEdit *descripcion;
    QLabel *label_12;
    QDateEdit *fechaAquisicion;
    QLabel *label_9;
    QGroupBox *groupBox_7;
    QLineEdit *nombreAutor;
    QLineEdit *apellidoAutor;
    QLabel *label_11;
    QLabel *label_13;
    QLineEdit *isbn;
    QLabel *label_18;
    QLabel *label_10;
    QLineEdit *titulo;
    QGroupBox *groupBox;
    QLineEdit *cuentaNO;
    QLineEdit *claseNO;
    QLineEdit *correlativoNO;
    QLineEdit *especificoNO;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_17;
    QLabel *label_5;
    QLabel *label_4;
    QToolButton *botonAgregarBien;
    QToolButton *botonEliminarBien;

    void setupUi(QWidget *DescargoBienesMB)
    {
        if (DescargoBienesMB->objectName().isEmpty())
            DescargoBienesMB->setObjectName(QString::fromUtf8("DescargoBienesMB"));
        DescargoBienesMB->setWindowModality(Qt::ApplicationModal);
        DescargoBienesMB->resize(960, 625);
        DescargoBienesMB->setMinimumSize(QSize(960, 625));
        DescargoBienesMB->setMaximumSize(QSize(960, 625));
        motivo = new QLineEdit(DescargoBienesMB);
        motivo->setObjectName(QString::fromUtf8("motivo"));
        motivo->setGeometry(QRect(10, 510, 711, 20));
        observaciones = new QLineEdit(DescargoBienesMB);
        observaciones->setObjectName(QString::fromUtf8("observaciones"));
        observaciones->setGeometry(QRect(10, 560, 901, 20));
        observaciones->setMaxLength(148);
        label_16 = new QLabel(DescargoBienesMB);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(740, 510, 46, 14));
        cancelar = new QPushButton(DescargoBienesMB);
        cancelar->setObjectName(QString::fromUtf8("cancelar"));
        cancelar->setGeometry(QRect(850, 590, 75, 23));
        nombreUnidad = new QLineEdit(DescargoBienesMB);
        nombreUnidad->setObjectName(QString::fromUtf8("nombreUnidad"));
        nombreUnidad->setGeometry(QRect(10, 50, 131, 20));
        nombreUnidad->setReadOnly(true);
        finalizarTransaccion = new QPushButton(DescargoBienesMB);
        finalizarTransaccion->setObjectName(QString::fromUtf8("finalizarTransaccion"));
        finalizarTransaccion->setGeometry(QRect(760, 590, 75, 23));
        nombreDpto = new QLineEdit(DescargoBienesMB);
        nombreDpto->setObjectName(QString::fromUtf8("nombreDpto"));
        nombreDpto->setGeometry(QRect(180, 50, 161, 20));
        nombreDpto->setMaxLength(100);
        nombreDpto->setReadOnly(true);
        totalIngreso = new QLineEdit(DescargoBienesMB);
        totalIngreso->setObjectName(QString::fromUtf8("totalIngreso"));
        totalIngreso->setGeometry(QRect(792, 510, 121, 20));
        totalIngreso->setReadOnly(true);
        label_14 = new QLabel(DescargoBienesMB);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 584, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Impact"));
        font.setPointSize(20);
        label_14->setFont(font);
        nuevoBien = new QToolButton(DescargoBienesMB);
        nuevoBien->setObjectName(QString::fromUtf8("nuevoBien"));
        nuevoBien->setGeometry(QRect(920, 380, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        nuevoBien->setIcon(icon);
        label_7 = new QLabel(DescargoBienesMB);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 30, 111, 21));
        tablaBienes = new QTableWidget(DescargoBienesMB);
        tablaBienes->setObjectName(QString::fromUtf8("tablaBienes"));
        tablaBienes->setGeometry(QRect(10, 280, 901, 201));
        groupBox_5 = new QGroupBox(DescargoBienesMB);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 100, 931, 171));
        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 20, 411, 121));
        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 30, 46, 14));
        cuentaAsignada = new QLineEdit(groupBox_6);
        cuentaAsignada->setObjectName(QString::fromUtf8("cuentaAsignada"));
        cuentaAsignada->setGeometry(QRect(80, 30, 311, 20));
        cuentaAsignada->setReadOnly(true);
        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(20, 70, 61, 16));
        nombreEspecifico = new QLineEdit(groupBox_6);
        nombreEspecifico->setObjectName(QString::fromUtf8("nombreEspecifico"));
        nombreEspecifico->setGeometry(QRect(80, 70, 311, 20));
        nombreEspecifico->setReadOnly(true);
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(740, 50, 41, 20));
        valorBien = new QDoubleSpinBox(groupBox_5);
        valorBien->setObjectName(QString::fromUtf8("valorBien"));
        valorBien->setGeometry(QRect(810, 50, 101, 22));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        valorBien->setFont(font1);
        valorBien->setLocale(QLocale(QLocale::Spanish, QLocale::ElSalvador));
        valorBien->setWrapping(false);
        valorBien->setFrame(true);
        valorBien->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valorBien->setReadOnly(true);
        valorBien->setButtonSymbols(QAbstractSpinBox::NoButtons);
        valorBien->setKeyboardTracking(true);
        valorBien->setMaximum(1e+07);
        descripcion = new QLineEdit(groupBox_5);
        descripcion->setObjectName(QString::fromUtf8("descripcion"));
        descripcion->setGeometry(QRect(810, 20, 101, 20));
        descripcion->setReadOnly(true);
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(740, 20, 61, 16));
        fechaAquisicion = new QDateEdit(groupBox_5);
        fechaAquisicion->setObjectName(QString::fromUtf8("fechaAquisicion"));
        fechaAquisicion->setGeometry(QRect(810, 110, 101, 22));
        fechaAquisicion->setReadOnly(true);
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(740, 110, 71, 16));
        groupBox_7 = new QGroupBox(groupBox_5);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(430, 20, 291, 80));
        nombreAutor = new QLineEdit(groupBox_7);
        nombreAutor->setObjectName(QString::fromUtf8("nombreAutor"));
        nombreAutor->setGeometry(QRect(80, 20, 201, 20));
        nombreAutor->setMaxLength(50);
        nombreAutor->setReadOnly(true);
        apellidoAutor = new QLineEdit(groupBox_7);
        apellidoAutor->setObjectName(QString::fromUtf8("apellidoAutor"));
        apellidoAutor->setGeometry(QRect(80, 50, 201, 20));
        apellidoAutor->setMaxLength(35);
        apellidoAutor->setReadOnly(true);
        label_11 = new QLabel(groupBox_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 20, 51, 16));
        label_13 = new QLabel(groupBox_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 50, 51, 16));
        isbn = new QLineEdit(groupBox_5);
        isbn->setObjectName(QString::fromUtf8("isbn"));
        isbn->setGeometry(QRect(480, 110, 151, 20));
        isbn->setReadOnly(true);
        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(440, 110, 46, 14));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(440, 130, 51, 20));
        titulo = new QLineEdit(groupBox_5);
        titulo->setObjectName(QString::fromUtf8("titulo"));
        titulo->setGeometry(QRect(480, 140, 281, 21));
        titulo->setMaxLength(85);
        titulo->setReadOnly(true);
        groupBox = new QGroupBox(DescargoBienesMB);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(370, 10, 341, 81));
        cuentaNO = new QLineEdit(groupBox);
        cuentaNO->setObjectName(QString::fromUtf8("cuentaNO"));
        cuentaNO->setGeometry(QRect(22, 40, 61, 21));
        cuentaNO->setFont(font1);
        cuentaNO->setMaxLength(5);
        cuentaNO->setReadOnly(true);
        claseNO = new QLineEdit(groupBox);
        claseNO->setObjectName(QString::fromUtf8("claseNO"));
        claseNO->setGeometry(QRect(100, 40, 61, 21));
        claseNO->setFont(font1);
        claseNO->setMaxLength(3);
        correlativoNO = new QLineEdit(groupBox);
        correlativoNO->setObjectName(QString::fromUtf8("correlativoNO"));
        correlativoNO->setGeometry(QRect(180, 41, 61, 20));
        correlativoNO->setFont(font1);
        correlativoNO->setMaxLength(6);
        especificoNO = new QLineEdit(groupBox);
        especificoNO->setObjectName(QString::fromUtf8("especificoNO"));
        especificoNO->setGeometry(QRect(260, 40, 61, 21));
        especificoNO->setFont(font1);
        especificoNO->setMaxLength(5);
        especificoNO->setReadOnly(true);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(25, 20, 61, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 20, 46, 14));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 20, 71, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(260, 20, 61, 16));
        label_17 = new QLabel(DescargoBienesMB);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 540, 81, 16));
        label_5 = new QLabel(DescargoBienesMB);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 30, 91, 16));
        label_4 = new QLabel(DescargoBienesMB);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 490, 111, 16));
        botonAgregarBien = new QToolButton(DescargoBienesMB);
        botonAgregarBien->setObjectName(QString::fromUtf8("botonAgregarBien"));
        botonAgregarBien->setGeometry(QRect(920, 300, 31, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonAgregarBien->setIcon(icon1);
        botonEliminarBien = new QToolButton(DescargoBienesMB);
        botonEliminarBien->setObjectName(QString::fromUtf8("botonEliminarBien"));
        botonEliminarBien->setGeometry(QRect(920, 340, 31, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonEliminarBien->setIcon(icon2);

        retranslateUi(DescargoBienesMB);

        QMetaObject::connectSlotsByName(DescargoBienesMB);
    } // setupUi

    void retranslateUi(QWidget *DescargoBienesMB)
    {
        DescargoBienesMB->setWindowTitle(QApplication::translate("DescargoBienesMB", "Descargo de Bienes - Material Bibliografico", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("DescargoBienesMB", "Total:", 0, QApplication::UnicodeUTF8));
        cancelar->setText(QApplication::translate("DescargoBienesMB", "Cancelar", 0, QApplication::UnicodeUTF8));
        finalizarTransaccion->setText(QApplication::translate("DescargoBienesMB", "Finalizar", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("DescargoBienesMB", "MB-M3", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        nuevoBien->setToolTip(QApplication::translate("DescargoBienesMB", "Nuevo Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nuevoBien->setText(QApplication::translate("DescargoBienesMB", "...", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DescargoBienesMB", "Unidad Solicitante:", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("DescargoBienesMB", "Bien:", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("DescargoBienesMB", "Identificacion del Bien", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DescargoBienesMB", "Cuenta: ", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("DescargoBienesMB", "Especifico: ", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("DescargoBienesMB", "Valor:", 0, QApplication::UnicodeUTF8));
        valorBien->setSpecialValueText(QString());
        label_12->setText(QApplication::translate("DescargoBienesMB", "Descripcion:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("DescargoBienesMB", "Adquirido:", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("DescargoBienesMB", "Autor: ", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("DescargoBienesMB", "Nombre:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("DescargoBienesMB", "Apellido:", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("DescargoBienesMB", "ISBN:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("DescargoBienesMB", "Titulo:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DescargoBienesMB", "Codigo Bien:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DescargoBienesMB", "Cuenta:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DescargoBienesMB", "Clase:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DescargoBienesMB", "Correlativo:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DescargoBienesMB", "Especifico:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("DescargoBienesMB", "Observaciones:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DescargoBienesMB", "Departamento:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DescargoBienesMB", "Motivo del descargo:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botonAgregarBien->setToolTip(QApplication::translate("DescargoBienesMB", "Agregar Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonAgregarBien->setText(QString());
#ifndef QT_NO_TOOLTIP
        botonEliminarBien->setToolTip(QApplication::translate("DescargoBienesMB", "Eliminar Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonEliminarBien->setText(QApplication::translate("DescargoBienesMB", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DescargoBienesMB: public Ui_DescargoBienesMB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESCARGOBIENESMB_H
