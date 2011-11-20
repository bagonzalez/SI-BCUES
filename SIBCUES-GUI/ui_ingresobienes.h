/********************************************************************************
** Form generated from reading UI file 'ingresobienes.ui'
**
** Created: Mon 9. Aug 09:25:21 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INGRESOBIENES_H
#define UI_INGRESOBIENES_H

#include <QtCore/QDate>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDoubleSpinBox>
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
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ingresoBienes
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
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
    QFormLayout *formLayout;
    QLabel *label_6;
    QLineEdit *numeroAcuerdoCSU;
    QLabel *label_7;
    QDateEdit *fechaAcuerdo;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QLineEdit *numeroCuenta;
    QLabel *label_9;
    QLineEdit *nombreClase;
    QToolButton *btmBuscarClases;
    QLineEdit *cuentaAsignada;
    QLabel *label_19;
    QLineEdit *numEspecifico;
    QLineEdit *nombreEspecifico;
    QToolButton *btmBuscarEspecifico;
    QLabel *label_10;
    QComboBox *marca;
    QToolButton *btmMarcas;
    QLabel *label_14;
    QDateEdit *fechaAdquisicion;
    QLabel *label_11;
    QComboBox *modelo;
    QLabel *label_15;
    QDoubleSpinBox *valorBien;
    QLabel *label_13;
    QLineEdit *serie;
    QLabel *label_18;
    QComboBox *sectorDestino;
    QLabel *label_12;
    QLineEdit *descripcion;
    QTableWidget *tablaBienes;
    QToolButton *botonAgregarBien;
    QToolButton *botonEliminarBien;
    QToolButton *nuevoBien;
    QLabel *label_21;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btmGuardar;
    QPushButton *finalizarTransaccion;
    QPushButton *cancelar;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QComboBox *anioInventario;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_4;
    QLineEdit *numeroIngreso;
    QLabel *label_16;
    QLineEdit *totalIngreso;
    QLineEdit *observaciones;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ingresoBienes)
    {
        if (ingresoBienes->objectName().isEmpty())
            ingresoBienes->setObjectName(QString::fromUtf8("ingresoBienes"));
        ingresoBienes->setWindowModality(Qt::ApplicationModal);
        ingresoBienes->resize(975, 734);
        ingresoBienes->setMaximumSize(QSize(36584, 36524));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/ico_alpha_RegistryDefrag_32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        ingresoBienes->setWindowIcon(icon);
        gridLayout = new QGridLayout(ingresoBienes);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(ingresoBienes);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
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


        horizontalLayout->addWidget(groupBox);

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


        horizontalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        formLayout = new QFormLayout(groupBox_4);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        numeroAcuerdoCSU = new QLineEdit(groupBox_4);
        numeroAcuerdoCSU->setObjectName(QString::fromUtf8("numeroAcuerdoCSU"));
        numeroAcuerdoCSU->setMaxLength(15);

        formLayout->setWidget(0, QFormLayout::FieldRole, numeroAcuerdoCSU);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_7);

        fechaAcuerdo = new QDateEdit(groupBox_4);
        fechaAcuerdo->setObjectName(QString::fromUtf8("fechaAcuerdo"));
        fechaAcuerdo->setCalendarPopup(true);
        fechaAcuerdo->setDate(QDate(2010, 1, 1));

        formLayout->setWidget(1, QFormLayout::FieldRole, fechaAcuerdo);


        horizontalLayout->addWidget(groupBox_4);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 6);

        groupBox_5 = new QGroupBox(ingresoBienes);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_4 = new QGridLayout(groupBox_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_3 = new QGridLayout(groupBox_6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        numeroCuenta = new QLineEdit(groupBox_6);
        numeroCuenta->setObjectName(QString::fromUtf8("numeroCuenta"));

        gridLayout_3->addWidget(numeroCuenta, 0, 1, 1, 2);

        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 0, 3, 1, 1);

        nombreClase = new QLineEdit(groupBox_6);
        nombreClase->setObjectName(QString::fromUtf8("nombreClase"));
        nombreClase->setMaxLength(3);

        gridLayout_3->addWidget(nombreClase, 0, 4, 1, 1);

        btmBuscarClases = new QToolButton(groupBox_6);
        btmBuscarClases->setObjectName(QString::fromUtf8("btmBuscarClases"));

        gridLayout_3->addWidget(btmBuscarClases, 0, 5, 1, 1);

        cuentaAsignada = new QLineEdit(groupBox_6);
        cuentaAsignada->setObjectName(QString::fromUtf8("cuentaAsignada"));
        cuentaAsignada->setReadOnly(true);

        gridLayout_3->addWidget(cuentaAsignada, 1, 1, 1, 5);

        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_3->addWidget(label_19, 2, 0, 1, 1);

        numEspecifico = new QLineEdit(groupBox_6);
        numEspecifico->setObjectName(QString::fromUtf8("numEspecifico"));

        gridLayout_3->addWidget(numEspecifico, 2, 1, 1, 1);

        nombreEspecifico = new QLineEdit(groupBox_6);
        nombreEspecifico->setObjectName(QString::fromUtf8("nombreEspecifico"));
        nombreEspecifico->setReadOnly(true);

        gridLayout_3->addWidget(nombreEspecifico, 2, 2, 1, 3);

        btmBuscarEspecifico = new QToolButton(groupBox_6);
        btmBuscarEspecifico->setObjectName(QString::fromUtf8("btmBuscarEspecifico"));

        gridLayout_3->addWidget(btmBuscarEspecifico, 2, 5, 1, 1);


        gridLayout_4->addWidget(groupBox_6, 0, 0, 4, 1);

        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 0, 1, 1, 1);

        marca = new QComboBox(groupBox_5);
        marca->setObjectName(QString::fromUtf8("marca"));
        marca->setEditable(true);

        gridLayout_4->addWidget(marca, 0, 2, 1, 1);

        btmMarcas = new QToolButton(groupBox_5);
        btmMarcas->setObjectName(QString::fromUtf8("btmMarcas"));

        gridLayout_4->addWidget(btmMarcas, 0, 3, 1, 1);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 0, 4, 1, 1);

        fechaAdquisicion = new QDateEdit(groupBox_5);
        fechaAdquisicion->setObjectName(QString::fromUtf8("fechaAdquisicion"));
        fechaAdquisicion->setCalendarPopup(true);
        fechaAdquisicion->setDate(QDate(2010, 1, 1));

        gridLayout_4->addWidget(fechaAdquisicion, 0, 5, 1, 1);

        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 1, 1, 1, 1);

        modelo = new QComboBox(groupBox_5);
        modelo->setObjectName(QString::fromUtf8("modelo"));
        modelo->setEditable(true);

        gridLayout_4->addWidget(modelo, 1, 2, 1, 1);

        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_4->addWidget(label_15, 1, 4, 1, 1);

        valorBien = new QDoubleSpinBox(groupBox_5);
        valorBien->setObjectName(QString::fromUtf8("valorBien"));
        valorBien->setLocale(QLocale(QLocale::Spanish, QLocale::ElSalvador));
        valorBien->setWrapping(false);
        valorBien->setFrame(true);
        valorBien->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valorBien->setButtonSymbols(QAbstractSpinBox::NoButtons);
        valorBien->setKeyboardTracking(true);
        valorBien->setMaximum(1e+07);

        gridLayout_4->addWidget(valorBien, 1, 5, 1, 1);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 2, 1, 1, 1);

        serie = new QLineEdit(groupBox_5);
        serie->setObjectName(QString::fromUtf8("serie"));
        serie->setMaxLength(25);

        gridLayout_4->addWidget(serie, 2, 2, 1, 2);

        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_4->addWidget(label_18, 2, 4, 1, 1);

        sectorDestino = new QComboBox(groupBox_5);
        sectorDestino->setObjectName(QString::fromUtf8("sectorDestino"));

        gridLayout_4->addWidget(sectorDestino, 2, 5, 1, 1);

        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 3, 1, 1, 1);

        descripcion = new QLineEdit(groupBox_5);
        descripcion->setObjectName(QString::fromUtf8("descripcion"));
        descripcion->setReadOnly(true);

        gridLayout_4->addWidget(descripcion, 3, 2, 1, 4);


        gridLayout->addWidget(groupBox_5, 3, 0, 1, 6);

        tablaBienes = new QTableWidget(ingresoBienes);
        tablaBienes->setObjectName(QString::fromUtf8("tablaBienes"));
        tablaBienes->setAlternatingRowColors(true);

        gridLayout->addWidget(tablaBienes, 5, 0, 4, 5);

        botonAgregarBien = new QToolButton(ingresoBienes);
        botonAgregarBien->setObjectName(QString::fromUtf8("botonAgregarBien"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonAgregarBien->setIcon(icon1);

        gridLayout->addWidget(botonAgregarBien, 5, 5, 1, 1);

        botonEliminarBien = new QToolButton(ingresoBienes);
        botonEliminarBien->setObjectName(QString::fromUtf8("botonEliminarBien"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonEliminarBien->setIcon(icon2);

        gridLayout->addWidget(botonEliminarBien, 6, 5, 1, 1);

        nuevoBien = new QToolButton(ingresoBienes);
        nuevoBien->setObjectName(QString::fromUtf8("nuevoBien"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/iconos/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        nuevoBien->setIcon(icon3);

        gridLayout->addWidget(nuevoBien, 7, 5, 1, 1);

        label_21 = new QLabel(ingresoBienes);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        QFont font;
        font.setFamily(QString::fromUtf8("Impact"));
        font.setPointSize(20);
        label_21->setFont(font);

        gridLayout->addWidget(label_21, 13, 0, 1, 1);

        groupBox_7 = new QGroupBox(ingresoBienes);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_7);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btmGuardar = new QPushButton(groupBox_7);
        btmGuardar->setObjectName(QString::fromUtf8("btmGuardar"));

        horizontalLayout_2->addWidget(btmGuardar);

        finalizarTransaccion = new QPushButton(groupBox_7);
        finalizarTransaccion->setObjectName(QString::fromUtf8("finalizarTransaccion"));

        horizontalLayout_2->addWidget(finalizarTransaccion);

        cancelar = new QPushButton(groupBox_7);
        cancelar->setObjectName(QString::fromUtf8("cancelar"));

        horizontalLayout_2->addWidget(cancelar);


        gridLayout->addWidget(groupBox_7, 13, 4, 1, 1);

        widget = new QWidget(ingresoBienes);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        anioInventario = new QComboBox(widget);
        anioInventario->setObjectName(QString::fromUtf8("anioInventario"));

        horizontalLayout_3->addWidget(anioInventario);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        numeroIngreso = new QLineEdit(widget);
        numeroIngreso->setObjectName(QString::fromUtf8("numeroIngreso"));
        numeroIngreso->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(numeroIngreso);


        gridLayout->addWidget(widget, 0, 0, 1, 6);

        label_16 = new QLabel(ingresoBienes);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label_16, 9, 0, 1, 1);

        totalIngreso = new QLineEdit(ingresoBienes);
        totalIngreso->setObjectName(QString::fromUtf8("totalIngreso"));
        totalIngreso->setReadOnly(true);

        gridLayout->addWidget(totalIngreso, 9, 1, 1, 1);

        observaciones = new QLineEdit(ingresoBienes);
        observaciones->setObjectName(QString::fromUtf8("observaciones"));
        observaciones->setMaxLength(148);

        gridLayout->addWidget(observaciones, 12, 1, 1, 4);

        label_17 = new QLabel(ingresoBienes);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 12, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 9, 3, 1, 1);

        QWidget::setTabOrder(fondoGeneral, fondosPropios);
        QWidget::setTabOrder(fondosPropios, donado);
        QWidget::setTabOrder(donado, noFactura);
        QWidget::setTabOrder(noFactura, CEF);
        QWidget::setTabOrder(CEF, fechaFactura);
        QWidget::setTabOrder(fechaFactura, numeroAcuerdoCSU);
        QWidget::setTabOrder(numeroAcuerdoCSU, fechaAcuerdo);
        QWidget::setTabOrder(fechaAcuerdo, numeroCuenta);
        QWidget::setTabOrder(numeroCuenta, nombreClase);
        QWidget::setTabOrder(nombreClase, marca);
        QWidget::setTabOrder(marca, modelo);
        QWidget::setTabOrder(modelo, serie);
        QWidget::setTabOrder(serie, descripcion);
        QWidget::setTabOrder(descripcion, fechaAdquisicion);
        QWidget::setTabOrder(fechaAdquisicion, valorBien);
        QWidget::setTabOrder(valorBien, sectorDestino);
        QWidget::setTabOrder(sectorDestino, botonAgregarBien);
        QWidget::setTabOrder(botonAgregarBien, botonEliminarBien);
        QWidget::setTabOrder(botonEliminarBien, nuevoBien);
        QWidget::setTabOrder(nuevoBien, tablaBienes);
        QWidget::setTabOrder(tablaBienes, nombreEspecifico);
        QWidget::setTabOrder(nombreEspecifico, cuentaAsignada);

        retranslateUi(ingresoBienes);
        QObject::connect(cancelar, SIGNAL(clicked()), ingresoBienes, SLOT(deleteLater()));

        QMetaObject::connectSlotsByName(ingresoBienes);
    } // setupUi

    void retranslateUi(QWidget *ingresoBienes)
    {
        ingresoBienes->setWindowTitle(QApplication::translate("ingresoBienes", "Ingreso de Bienes al Inventario de Activo Fijo", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("ingresoBienes", "Datos Generales: ", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ingresoBienes", "Tipo de Adquisicion:", 0, QApplication::UnicodeUTF8));
        fondoGeneral->setText(QApplication::translate("ingresoBienes", "Fondo General", 0, QApplication::UnicodeUTF8));
        fondosPropios->setText(QApplication::translate("ingresoBienes", "Fondos Propios", 0, QApplication::UnicodeUTF8));
        donado->setText(QApplication::translate("ingresoBienes", "Donado", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ingresoBienes", "Proveedor: ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ingresoBienes", "Nombre:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("ingresoBienes", "CEF. No.:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ingresoBienes", "Factura: ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ingresoBienes", "Fecha Factura:", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("ingresoBienes", "Acuerdo C.S.U: ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ingresoBienes", "No.:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ingresoBienes", "Fecha:", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("ingresoBienes", "Bien:", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("ingresoBienes", "Especificacion Bien:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ingresoBienes", "Cuenta: ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ingresoBienes", "Clase:", 0, QApplication::UnicodeUTF8));
        btmBuscarClases->setText(QApplication::translate("ingresoBienes", "...", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("ingresoBienes", "Especifico: ", 0, QApplication::UnicodeUTF8));
        btmBuscarEspecifico->setText(QApplication::translate("ingresoBienes", "...", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ingresoBienes", "Marca:", 0, QApplication::UnicodeUTF8));
        btmMarcas->setText(QApplication::translate("ingresoBienes", "...", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("ingresoBienes", "Fecha Adquisicion:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ingresoBienes", "Modelo:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("ingresoBienes", "Valor:            ($)", 0, QApplication::UnicodeUTF8));
        valorBien->setSpecialValueText(QString());
        label_13->setText(QApplication::translate("ingresoBienes", "Serie:", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("ingresoBienes", "Sector Destino:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("ingresoBienes", "Descripcion:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botonAgregarBien->setToolTip(QApplication::translate("ingresoBienes", "Agregar Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonAgregarBien->setText(QString());
#ifndef QT_NO_TOOLTIP
        botonEliminarBien->setToolTip(QApplication::translate("ingresoBienes", "Eliminar Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonEliminarBien->setText(QApplication::translate("ingresoBienes", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        nuevoBien->setToolTip(QApplication::translate("ingresoBienes", "Nuevo Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nuevoBien->setText(QApplication::translate("ingresoBienes", "...", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("ingresoBienes", "AF-M1", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QString());
        btmGuardar->setText(QApplication::translate("ingresoBienes", "Guardar", 0, QApplication::UnicodeUTF8));
        finalizarTransaccion->setText(QApplication::translate("ingresoBienes", "Ingresar", 0, QApplication::UnicodeUTF8));
        cancelar->setText(QApplication::translate("ingresoBienes", "Cancelar", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ingresoBienes", "Inventario: ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ingresoBienes", "Numero Ingreso:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("ingresoBienes", "Total:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("ingresoBienes", "Observaciones:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ingresoBienes: public Ui_ingresoBienes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INGRESOBIENES_H
