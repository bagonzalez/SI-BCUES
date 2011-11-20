/********************************************************************************
** Form generated from reading UI file 'trasladobienesbiblio.ui'
**
** Created: Tue 28. Jun 22:54:49 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRASLADOBIENESBIBLIO_H
#define UI_TRASLADOBIENESBIBLIO_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrasladoBienesBiblio
{
public:
    QTableWidget *tablaBienes;
    QToolButton *botonAgregarBien;
    QToolButton *nuevoBien;
    QGroupBox *groupBox;
    QLineEdit *cuentaNO;
    QLineEdit *claseNO;
    QLineEdit *correlativoNO;
    QLineEdit *especificoNO;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_21;
    QComboBox *anioInventario;
    QLabel *label_4;
    QLineEdit *totalIngreso;
    QLabel *label_16;
    QPushButton *cancelar;
    QToolButton *botonEliminarBien;
    QLabel *label_17;
    QLineEdit *observaciones;
    QPushButton *finalizarTransaccion;
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
    QLabel *label_11;
    QLineEdit *isbn;
    QLabel *label_18;
    QLabel *label_10;
    QLineEdit *titulo;
    QLineEdit *motivo;
    QLabel *label_14;
    QLineEdit *nombreUnidad;
    QGroupBox *groupBox_2;
    QRadioButton *temporal;
    QRadioButton *definitivo;
    QLineEdit *nombreDpto;
    QLabel *label_20;
    QLabel *label_7;
    QComboBox *unidadRecibe;
    QLineEdit *codigoTraslado;
    QLabel *label_13;

    void setupUi(QWidget *TrasladoBienesBiblio)
    {
        if (TrasladoBienesBiblio->objectName().isEmpty())
            TrasladoBienesBiblio->setObjectName(QString::fromUtf8("TrasladoBienesBiblio"));
        TrasladoBienesBiblio->setWindowModality(Qt::ApplicationModal);
        TrasladoBienesBiblio->resize(960, 625);
        TrasladoBienesBiblio->setMinimumSize(QSize(960, 625));
        TrasladoBienesBiblio->setMaximumSize(QSize(960, 625));
        tablaBienes = new QTableWidget(TrasladoBienesBiblio);
        tablaBienes->setObjectName(QString::fromUtf8("tablaBienes"));
        tablaBienes->setGeometry(QRect(10, 280, 901, 201));
        botonAgregarBien = new QToolButton(TrasladoBienesBiblio);
        botonAgregarBien->setObjectName(QString::fromUtf8("botonAgregarBien"));
        botonAgregarBien->setGeometry(QRect(920, 300, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonAgregarBien->setIcon(icon);
        nuevoBien = new QToolButton(TrasladoBienesBiblio);
        nuevoBien->setObjectName(QString::fromUtf8("nuevoBien"));
        nuevoBien->setGeometry(QRect(920, 380, 31, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        nuevoBien->setIcon(icon1);
        groupBox = new QGroupBox(TrasladoBienesBiblio);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(480, 10, 461, 81));
        cuentaNO = new QLineEdit(groupBox);
        cuentaNO->setObjectName(QString::fromUtf8("cuentaNO"));
        cuentaNO->setGeometry(QRect(150, 40, 61, 21));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        cuentaNO->setFont(font);
        cuentaNO->setMaxLength(5);
        cuentaNO->setReadOnly(true);
        claseNO = new QLineEdit(groupBox);
        claseNO->setObjectName(QString::fromUtf8("claseNO"));
        claseNO->setGeometry(QRect(230, 40, 61, 21));
        claseNO->setFont(font);
        claseNO->setMaxLength(3);
        correlativoNO = new QLineEdit(groupBox);
        correlativoNO->setObjectName(QString::fromUtf8("correlativoNO"));
        correlativoNO->setGeometry(QRect(310, 40, 61, 20));
        correlativoNO->setFont(font);
        correlativoNO->setMaxLength(7);
        especificoNO = new QLineEdit(groupBox);
        especificoNO->setObjectName(QString::fromUtf8("especificoNO"));
        especificoNO->setGeometry(QRect(390, 40, 61, 21));
        especificoNO->setFont(font);
        especificoNO->setMaxLength(5);
        especificoNO->setReadOnly(true);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 20, 61, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 20, 46, 14));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 20, 71, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(390, 20, 61, 16));
        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(20, 20, 61, 16));
        anioInventario = new QComboBox(groupBox);
        anioInventario->setObjectName(QString::fromUtf8("anioInventario"));
        anioInventario->setGeometry(QRect(20, 40, 111, 22));
        label_4 = new QLabel(TrasladoBienesBiblio);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 490, 111, 16));
        totalIngreso = new QLineEdit(TrasladoBienesBiblio);
        totalIngreso->setObjectName(QString::fromUtf8("totalIngreso"));
        totalIngreso->setGeometry(QRect(792, 510, 121, 20));
        totalIngreso->setReadOnly(true);
        label_16 = new QLabel(TrasladoBienesBiblio);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(740, 510, 46, 14));
        cancelar = new QPushButton(TrasladoBienesBiblio);
        cancelar->setObjectName(QString::fromUtf8("cancelar"));
        cancelar->setGeometry(QRect(850, 590, 75, 23));
        botonEliminarBien = new QToolButton(TrasladoBienesBiblio);
        botonEliminarBien->setObjectName(QString::fromUtf8("botonEliminarBien"));
        botonEliminarBien->setGeometry(QRect(920, 340, 31, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonEliminarBien->setIcon(icon2);
        label_17 = new QLabel(TrasladoBienesBiblio);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 540, 81, 16));
        observaciones = new QLineEdit(TrasladoBienesBiblio);
        observaciones->setObjectName(QString::fromUtf8("observaciones"));
        observaciones->setGeometry(QRect(10, 560, 901, 20));
        observaciones->setMaxLength(148);
        finalizarTransaccion = new QPushButton(TrasladoBienesBiblio);
        finalizarTransaccion->setObjectName(QString::fromUtf8("finalizarTransaccion"));
        finalizarTransaccion->setGeometry(QRect(760, 590, 75, 23));
        groupBox_5 = new QGroupBox(TrasladoBienesBiblio);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 100, 931, 171));
        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 30, 411, 121));
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
        valorBien->setFont(font);
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
        nombreAutor->setGeometry(QRect(20, 40, 261, 31));
        nombreAutor->setMaxLength(50);
        nombreAutor->setReadOnly(true);
        label_11 = new QLabel(groupBox_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 20, 51, 16));
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
        motivo = new QLineEdit(TrasladoBienesBiblio);
        motivo->setObjectName(QString::fromUtf8("motivo"));
        motivo->setGeometry(QRect(10, 510, 711, 20));
        label_14 = new QLabel(TrasladoBienesBiblio);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 584, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Impact"));
        font1.setPointSize(20);
        label_14->setFont(font1);
        nombreUnidad = new QLineEdit(TrasladoBienesBiblio);
        nombreUnidad->setObjectName(QString::fromUtf8("nombreUnidad"));
        nombreUnidad->setGeometry(QRect(10, 30, 81, 20));
        nombreUnidad->setReadOnly(true);
        groupBox_2 = new QGroupBox(TrasladoBienesBiblio);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(360, 10, 101, 81));
        temporal = new QRadioButton(groupBox_2);
        temporal->setObjectName(QString::fromUtf8("temporal"));
        temporal->setGeometry(QRect(20, 20, 84, 18));
        definitivo = new QRadioButton(groupBox_2);
        definitivo->setObjectName(QString::fromUtf8("definitivo"));
        definitivo->setGeometry(QRect(20, 50, 84, 18));
        nombreDpto = new QLineEdit(TrasladoBienesBiblio);
        nombreDpto->setObjectName(QString::fromUtf8("nombreDpto"));
        nombreDpto->setGeometry(QRect(100, 30, 101, 20));
        nombreDpto->setMaxLength(100);
        nombreDpto->setReadOnly(true);
        label_20 = new QLabel(TrasladoBienesBiblio);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 70, 101, 16));
        label_7 = new QLabel(TrasladoBienesBiblio);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 10, 111, 21));
        unidadRecibe = new QComboBox(TrasladoBienesBiblio);
        unidadRecibe->setObjectName(QString::fromUtf8("unidadRecibe"));
        unidadRecibe->setGeometry(QRect(130, 70, 221, 22));
        codigoTraslado = new QLineEdit(TrasladoBienesBiblio);
        codigoTraslado->setObjectName(QString::fromUtf8("codigoTraslado"));
        codigoTraslado->setGeometry(QRect(220, 30, 126, 22));
        label_13 = new QLabel(TrasladoBienesBiblio);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(220, 10, 126, 13));

        retranslateUi(TrasladoBienesBiblio);

        QMetaObject::connectSlotsByName(TrasladoBienesBiblio);
    } // setupUi

    void retranslateUi(QWidget *TrasladoBienesBiblio)
    {
        TrasladoBienesBiblio->setWindowTitle(QApplication::translate("TrasladoBienesBiblio", "Traslado de Bienes - Material Bibliografico", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botonAgregarBien->setToolTip(QApplication::translate("TrasladoBienesBiblio", "Agregar Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonAgregarBien->setText(QString());
#ifndef QT_NO_TOOLTIP
        nuevoBien->setToolTip(QApplication::translate("TrasladoBienesBiblio", "Nuevo Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nuevoBien->setText(QApplication::translate("TrasladoBienesBiblio", "...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("TrasladoBienesBiblio", "Codigo Bien:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TrasladoBienesBiblio", "Cuenta:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TrasladoBienesBiblio", "Clase:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TrasladoBienesBiblio", "Correlativo:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TrasladoBienesBiblio", "Especifico:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("TrasladoBienesBiblio", "Inventario:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TrasladoBienesBiblio", "Motivo del descargo:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("TrasladoBienesBiblio", "Total:", 0, QApplication::UnicodeUTF8));
        cancelar->setText(QApplication::translate("TrasladoBienesBiblio", "Cancelar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botonEliminarBien->setToolTip(QApplication::translate("TrasladoBienesBiblio", "Eliminar Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonEliminarBien->setText(QApplication::translate("TrasladoBienesBiblio", "...", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("TrasladoBienesBiblio", "Observaciones:", 0, QApplication::UnicodeUTF8));
        finalizarTransaccion->setText(QApplication::translate("TrasladoBienesBiblio", "Finalizar", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("TrasladoBienesBiblio", "Bien:", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("TrasladoBienesBiblio", "Identificacion del Bien", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("TrasladoBienesBiblio", "Cuenta: ", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("TrasladoBienesBiblio", "Especifico: ", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("TrasladoBienesBiblio", "Valor:", 0, QApplication::UnicodeUTF8));
        valorBien->setSpecialValueText(QString());
        label_12->setText(QApplication::translate("TrasladoBienesBiblio", "Descripcion:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("TrasladoBienesBiblio", "Adquirido:", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("TrasladoBienesBiblio", "Autor(es): ", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("TrasladoBienesBiblio", "Nombre(s):", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("TrasladoBienesBiblio", "ISBN:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("TrasladoBienesBiblio", "Titulo:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("TrasladoBienesBiblio", "MB-M2", 0, QApplication::UnicodeUTF8));
        nombreUnidad->setText(QApplication::translate("TrasladoBienesBiblio", "200 01", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("TrasladoBienesBiblio", "Tipo Traslado:", 0, QApplication::UnicodeUTF8));
        temporal->setText(QApplication::translate("TrasladoBienesBiblio", "Temporal", 0, QApplication::UnicodeUTF8));
        definitivo->setText(QApplication::translate("TrasladoBienesBiblio", "Definitivo", 0, QApplication::UnicodeUTF8));
        nombreDpto->setText(QApplication::translate("TrasladoBienesBiblio", "Biblioteca Central", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("TrasladoBienesBiblio", "Unidad que Recibe:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("TrasladoBienesBiblio", "Unidad que Entrega:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("TrasladoBienesBiblio", "Codigo Traslado:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TrasladoBienesBiblio: public Ui_TrasladoBienesBiblio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRASLADOBIENESBIBLIO_H
