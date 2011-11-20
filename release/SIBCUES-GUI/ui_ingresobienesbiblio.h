/********************************************************************************
** Form generated from reading UI file 'ingresobienesbiblio.ui'
**
** Created: Sat 14. May 00:05:02 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INGRESOBIENESBIBLIO_H
#define UI_INGRESOBIENESBIBLIO_H

#include <QtCore/QDate>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IngresoBienesBiblio
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *fondoGeneral;
    QRadioButton *fondosPropios;
    QRadioButton *donado;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QComboBox *nombreProveedor;
    QLabel *label_20;
    QLineEdit *CEF;
    QLabel *label_2;
    QLineEdit *noFactura;
    QLabel *label_3;
    QDateEdit *fechaFactura;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_7;
    QLabel *label_6;
    QLineEdit *numeroAcuerdoCSU;
    QLabel *label_7;
    QDateEdit *fechaAcuerdo;
    QSpacerItem *horizontalSpacer_6;
    QTableWidget *tablaBienes;
    QToolButton *botonAgregarBien;
    QToolButton *botonEliminarBien;
    QToolButton *nuevoBien;
    QLabel *label_21;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *finalizarTransaccion;
    QPushButton *cancelar;
    QLabel *label_17;
    QLabel *label_16;
    QLineEdit *totalIngreso;
    QLineEdit *observaciones;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_4;
    QWidget *widget_2;
    QGridLayout *gridLayout_5;
    QLabel *label_10;
    QLabel *label_18;
    QLineEdit *isbn;
    QLabel *label_15;
    QLabel *label_14;
    QLabel *label_12;
    QLineEdit *descripcion;
    QDoubleSpinBox *valorBien;
    QSpacerItem *horizontalSpacer;
    QLineEdit *titulo;
    QDateEdit *fechaAdquisicion;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *buscarTitulo;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QLineEdit *numeroCuenta;
    QLabel *label_9;
    QLineEdit *nombreClase;
    QLineEdit *cuentaAsignada;
    QLabel *label_19;
    QLineEdit *nombreEspecifico;
    QToolButton *buscarCuentaInventario;
    QToolButton *buscarEspecifico;
    QLineEdit *numEspecifico;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *numeroIngreso;
    QLabel *label_5;
    QComboBox *anioInventario;

    void setupUi(QWidget *IngresoBienesBiblio)
    {
        if (IngresoBienesBiblio->objectName().isEmpty())
            IngresoBienesBiblio->setObjectName(QString::fromUtf8("IngresoBienesBiblio"));
        IngresoBienesBiblio->setWindowModality(Qt::ApplicationModal);
        IngresoBienesBiblio->resize(975, 625);
        IngresoBienesBiblio->setMinimumSize(QSize(975, 625));
        IngresoBienesBiblio->setMaximumSize(QSize(88888, 88888));
        gridLayout = new QGridLayout(IngresoBienesBiblio);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(IngresoBienesBiblio);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        fondoGeneral = new QRadioButton(groupBox);
        fondoGeneral->setObjectName(QString::fromUtf8("fondoGeneral"));

        verticalLayout->addWidget(fondoGeneral);

        fondosPropios = new QRadioButton(groupBox);
        fondosPropios->setObjectName(QString::fromUtf8("fondosPropios"));

        verticalLayout->addWidget(fondosPropios);

        donado = new QRadioButton(groupBox);
        donado->setObjectName(QString::fromUtf8("donado"));

        verticalLayout->addWidget(donado);


        gridLayout_6->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        nombreProveedor = new QComboBox(groupBox_2);
        nombreProveedor->setObjectName(QString::fromUtf8("nombreProveedor"));
        nombreProveedor->setEditable(true);

        gridLayout_2->addWidget(nombreProveedor, 0, 1, 1, 2);

        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_2->addWidget(label_20, 0, 3, 1, 1);

        CEF = new QLineEdit(groupBox_2);
        CEF->setObjectName(QString::fromUtf8("CEF"));
        CEF->setMaxLength(8);

        gridLayout_2->addWidget(CEF, 0, 4, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        noFactura = new QLineEdit(groupBox_2);
        noFactura->setObjectName(QString::fromUtf8("noFactura"));
        noFactura->setMaxLength(20);

        gridLayout_2->addWidget(noFactura, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 2, 1, 2);

        fechaFactura = new QDateEdit(groupBox_2);
        fechaFactura->setObjectName(QString::fromUtf8("fechaFactura"));
        fechaFactura->setCalendarPopup(true);
        fechaFactura->setDate(QDate(2009, 1, 1));

        gridLayout_2->addWidget(fechaFactura, 1, 4, 1, 1);


        gridLayout_6->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_7 = new QGridLayout(groupBox_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_7->addWidget(label_6, 0, 0, 1, 1);

        numeroAcuerdoCSU = new QLineEdit(groupBox_4);
        numeroAcuerdoCSU->setObjectName(QString::fromUtf8("numeroAcuerdoCSU"));
        numeroAcuerdoCSU->setMaxLength(15);

        gridLayout_7->addWidget(numeroAcuerdoCSU, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_7->addWidget(label_7, 1, 0, 1, 1);

        fechaAcuerdo = new QDateEdit(groupBox_4);
        fechaAcuerdo->setObjectName(QString::fromUtf8("fechaAcuerdo"));
        fechaAcuerdo->setCalendarPopup(true);
        fechaAcuerdo->setDate(QDate(2010, 1, 1));

        gridLayout_7->addWidget(fechaAcuerdo, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_6, 0, 2, 1, 1);


        gridLayout_6->addWidget(groupBox_4, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 8);

        tablaBienes = new QTableWidget(IngresoBienesBiblio);
        tablaBienes->setObjectName(QString::fromUtf8("tablaBienes"));

        gridLayout->addWidget(tablaBienes, 3, 0, 4, 7);

        botonAgregarBien = new QToolButton(IngresoBienesBiblio);
        botonAgregarBien->setObjectName(QString::fromUtf8("botonAgregarBien"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonAgregarBien->setIcon(icon);

        gridLayout->addWidget(botonAgregarBien, 3, 7, 1, 1);

        botonEliminarBien = new QToolButton(IngresoBienesBiblio);
        botonEliminarBien->setObjectName(QString::fromUtf8("botonEliminarBien"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonEliminarBien->setIcon(icon1);

        gridLayout->addWidget(botonEliminarBien, 4, 7, 1, 1);

        nuevoBien = new QToolButton(IngresoBienesBiblio);
        nuevoBien->setObjectName(QString::fromUtf8("nuevoBien"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        nuevoBien->setIcon(icon2);

        gridLayout->addWidget(nuevoBien, 5, 7, 1, 1);

        label_21 = new QLabel(IngresoBienesBiblio);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        QFont font;
        font.setFamily(QString::fromUtf8("Impact"));
        font.setPointSize(20);
        label_21->setFont(font);

        gridLayout->addWidget(label_21, 10, 0, 1, 1);

        widget_3 = new QWidget(IngresoBienesBiblio);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        finalizarTransaccion = new QPushButton(widget_3);
        finalizarTransaccion->setObjectName(QString::fromUtf8("finalizarTransaccion"));

        horizontalLayout_2->addWidget(finalizarTransaccion);

        cancelar = new QPushButton(widget_3);
        cancelar->setObjectName(QString::fromUtf8("cancelar"));

        horizontalLayout_2->addWidget(cancelar);


        gridLayout->addWidget(widget_3, 10, 6, 1, 1);

        label_17 = new QLabel(IngresoBienesBiblio);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 9, 0, 1, 1);

        label_16 = new QLabel(IngresoBienesBiblio);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 7, 0, 1, 1);

        totalIngreso = new QLineEdit(IngresoBienesBiblio);
        totalIngreso->setObjectName(QString::fromUtf8("totalIngreso"));
        totalIngreso->setReadOnly(true);

        gridLayout->addWidget(totalIngreso, 7, 1, 1, 1);

        observaciones = new QLineEdit(IngresoBienesBiblio);
        observaciones->setObjectName(QString::fromUtf8("observaciones"));
        observaciones->setMaxLength(148);

        gridLayout->addWidget(observaciones, 9, 1, 1, 6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 7, 6, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 7, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 7, 2, 1, 1);

        groupBox_5 = new QGroupBox(IngresoBienesBiblio);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_4 = new QGridLayout(groupBox_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget_2 = new QWidget(groupBox_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_5 = new QGridLayout(widget_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_5->addWidget(label_10, 0, 0, 1, 1);

        label_18 = new QLabel(widget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_5->addWidget(label_18, 1, 0, 1, 1);

        isbn = new QLineEdit(widget_2);
        isbn->setObjectName(QString::fromUtf8("isbn"));
        isbn->setReadOnly(true);

        gridLayout_5->addWidget(isbn, 1, 1, 1, 2);

        label_15 = new QLabel(widget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_5->addWidget(label_15, 2, 0, 1, 1);

        label_14 = new QLabel(widget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_5->addWidget(label_14, 3, 0, 1, 1);

        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_5->addWidget(label_12, 4, 0, 1, 1);

        descripcion = new QLineEdit(widget_2);
        descripcion->setObjectName(QString::fromUtf8("descripcion"));
        descripcion->setReadOnly(true);

        gridLayout_5->addWidget(descripcion, 4, 1, 1, 2);

        valorBien = new QDoubleSpinBox(widget_2);
        valorBien->setObjectName(QString::fromUtf8("valorBien"));
        valorBien->setLocale(QLocale(QLocale::Spanish, QLocale::ElSalvador));
        valorBien->setWrapping(false);
        valorBien->setFrame(true);
        valorBien->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valorBien->setButtonSymbols(QAbstractSpinBox::NoButtons);
        valorBien->setKeyboardTracking(true);
        valorBien->setMaximum(1e+07);

        gridLayout_5->addWidget(valorBien, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 2, 2, 1, 1);

        titulo = new QLineEdit(widget_2);
        titulo->setObjectName(QString::fromUtf8("titulo"));

        gridLayout_5->addWidget(titulo, 0, 1, 1, 2);

        fechaAdquisicion = new QDateEdit(widget_2);
        fechaAdquisicion->setObjectName(QString::fromUtf8("fechaAdquisicion"));
        fechaAdquisicion->setCalendarPopup(true);
        fechaAdquisicion->setDate(QDate(2010, 1, 1));

        gridLayout_5->addWidget(fechaAdquisicion, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        buscarTitulo = new QToolButton(widget_2);
        buscarTitulo->setObjectName(QString::fromUtf8("buscarTitulo"));

        gridLayout_5->addWidget(buscarTitulo, 0, 3, 1, 1);


        gridLayout_4->addWidget(widget_2, 0, 1, 1, 1);

        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_3 = new QGridLayout(groupBox_6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        numeroCuenta = new QLineEdit(groupBox_6);
        numeroCuenta->setObjectName(QString::fromUtf8("numeroCuenta"));
        numeroCuenta->setReadOnly(true);

        gridLayout_3->addWidget(numeroCuenta, 0, 1, 1, 2);

        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 0, 3, 1, 1);

        nombreClase = new QLineEdit(groupBox_6);
        nombreClase->setObjectName(QString::fromUtf8("nombreClase"));
        nombreClase->setMaxLength(3);

        gridLayout_3->addWidget(nombreClase, 0, 4, 1, 1);

        cuentaAsignada = new QLineEdit(groupBox_6);
        cuentaAsignada->setObjectName(QString::fromUtf8("cuentaAsignada"));
        cuentaAsignada->setReadOnly(true);

        gridLayout_3->addWidget(cuentaAsignada, 1, 1, 1, 4);

        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_3->addWidget(label_19, 2, 0, 1, 1);

        nombreEspecifico = new QLineEdit(groupBox_6);
        nombreEspecifico->setObjectName(QString::fromUtf8("nombreEspecifico"));
        nombreEspecifico->setReadOnly(true);

        gridLayout_3->addWidget(nombreEspecifico, 2, 2, 1, 3);

        buscarCuentaInventario = new QToolButton(groupBox_6);
        buscarCuentaInventario->setObjectName(QString::fromUtf8("buscarCuentaInventario"));

        gridLayout_3->addWidget(buscarCuentaInventario, 0, 5, 1, 1);

        buscarEspecifico = new QToolButton(groupBox_6);
        buscarEspecifico->setObjectName(QString::fromUtf8("buscarEspecifico"));

        gridLayout_3->addWidget(buscarEspecifico, 2, 5, 1, 1);

        numEspecifico = new QLineEdit(groupBox_6);
        numEspecifico->setObjectName(QString::fromUtf8("numEspecifico"));

        gridLayout_3->addWidget(numEspecifico, 2, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_6, 0, 0, 3, 1);


        gridLayout->addWidget(groupBox_5, 2, 0, 1, 8);

        widget = new QWidget(IngresoBienesBiblio);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        numeroIngreso = new QLineEdit(widget);
        numeroIngreso->setObjectName(QString::fromUtf8("numeroIngreso"));

        horizontalLayout->addWidget(numeroIngreso);


        gridLayout->addWidget(widget, 0, 6, 1, 1);

        label_5 = new QLabel(IngresoBienesBiblio);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        anioInventario = new QComboBox(IngresoBienesBiblio);
        anioInventario->setObjectName(QString::fromUtf8("anioInventario"));

        gridLayout->addWidget(anioInventario, 0, 1, 1, 1);


        retranslateUi(IngresoBienesBiblio);

        QMetaObject::connectSlotsByName(IngresoBienesBiblio);
    } // setupUi

    void retranslateUi(QWidget *IngresoBienesBiblio)
    {
        IngresoBienesBiblio->setWindowTitle(QApplication::translate("IngresoBienesBiblio", "Ingreso de Bienes - Materiales Bibliografico", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("IngresoBienesBiblio", "Datos Generales: ", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("IngresoBienesBiblio", "Tipo de Adquisicion:", 0, QApplication::UnicodeUTF8));
        fondoGeneral->setText(QApplication::translate("IngresoBienesBiblio", "Fondo General", 0, QApplication::UnicodeUTF8));
        fondosPropios->setText(QApplication::translate("IngresoBienesBiblio", "Fondos Propios", 0, QApplication::UnicodeUTF8));
        donado->setText(QApplication::translate("IngresoBienesBiblio", "Donado", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("IngresoBienesBiblio", "Proveedor: ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("IngresoBienesBiblio", "Nombre:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("IngresoBienesBiblio", "CEF. No.:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("IngresoBienesBiblio", "Factura: ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("IngresoBienesBiblio", "Fecha Factura:", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("IngresoBienesBiblio", "Acuerdo C.S.U: ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("IngresoBienesBiblio", "No.:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("IngresoBienesBiblio", "Fecha:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botonAgregarBien->setToolTip(QApplication::translate("IngresoBienesBiblio", "Agregar Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonAgregarBien->setText(QString());
#ifndef QT_NO_TOOLTIP
        botonEliminarBien->setToolTip(QApplication::translate("IngresoBienesBiblio", "Eliminar Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonEliminarBien->setText(QApplication::translate("IngresoBienesBiblio", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        nuevoBien->setToolTip(QApplication::translate("IngresoBienesBiblio", "Nuevo Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nuevoBien->setText(QApplication::translate("IngresoBienesBiblio", "...", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("IngresoBienesBiblio", "MB-M1", 0, QApplication::UnicodeUTF8));
        finalizarTransaccion->setText(QApplication::translate("IngresoBienesBiblio", "Finalizar", 0, QApplication::UnicodeUTF8));
        cancelar->setText(QApplication::translate("IngresoBienesBiblio", "Cancelar", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("IngresoBienesBiblio", "Observaciones:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("IngresoBienesBiblio", "Total:", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("IngresoBienesBiblio", "Bien:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("IngresoBienesBiblio", "Titulo:", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("IngresoBienesBiblio", "ISBN:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("IngresoBienesBiblio", "Valor:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("IngresoBienesBiblio", "Fecha Adquisicion:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("IngresoBienesBiblio", "Descripcion:", 0, QApplication::UnicodeUTF8));
        valorBien->setSpecialValueText(QString());
        buscarTitulo->setText(QApplication::translate("IngresoBienesBiblio", "...", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("IngresoBienesBiblio", "Especificacion Bien:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("IngresoBienesBiblio", "Cuenta: ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("IngresoBienesBiblio", "Clase:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("IngresoBienesBiblio", "Especifico: ", 0, QApplication::UnicodeUTF8));
        buscarCuentaInventario->setText(QApplication::translate("IngresoBienesBiblio", "...", 0, QApplication::UnicodeUTF8));
        buscarEspecifico->setText(QApplication::translate("IngresoBienesBiblio", "...", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("IngresoBienesBiblio", "Numero de Ingreso:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("IngresoBienesBiblio", "A\303\261o Inventario:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IngresoBienesBiblio: public Ui_IngresoBienesBiblio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INGRESOBIENESBIBLIO_H
