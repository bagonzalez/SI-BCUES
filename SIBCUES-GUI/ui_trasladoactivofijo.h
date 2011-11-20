/********************************************************************************
** Form generated from reading UI file 'trasladoactivofijo.ui'
**
** Created: Mon 19. Jul 20:18:07 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRASLADOACTIVOFIJO_H
#define UI_TRASLADOACTIVOFIJO_H

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

class Ui_TrasladoActivoFijo
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *temporal;
    QRadioButton *definitivo;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_6;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *cuentaNO;
    QLineEdit *claseNO;
    QLineEdit *correlativoNO;
    QLineEdit *especificoNO;
    QToolButton *consultaBien;
    QLabel *label_4;
    QLineEdit *observaciones;
    QLabel *label_18;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *guardarTraslado;
    QPushButton *finalizarTransaccion;
    QPushButton *cancelar;
    QLabel *label_17;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_3;
    QWidget *widget_8;
    QGridLayout *gridLayout_4;
    QWidget *widget_4;
    QFormLayout *formLayout_2;
    QLabel *label_11;
    QLabel *label_10;
    QLineEdit *marca;
    QLineEdit *modelo;
    QWidget *widget_5;
    QFormLayout *formLayout_3;
    QLabel *label_15;
    QLabel *label_13;
    QDoubleSpinBox *valorBien;
    QLineEdit *serie;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_14;
    QDateEdit *fechaAquisicion;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_12;
    QLineEdit *descripcion;
    QWidget *widget_61;
    QFormLayout *formLayout;
    QLabel *label_8;
    QLineEdit *cuentaAsignada;
    QLabel *label_19;
    QLineEdit *nombreEspecifico;
    QTableWidget *tablaBienes;
    QToolButton *botonAgregarBien;
    QToolButton *botonEliminarBien;
    QToolButton *nuevoBien;
    QLineEdit *totalIngreso;
    QLabel *label_16;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLineEdit *codigoTraslado;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QComboBox *unidadRecibe;

    void setupUi(QWidget *TrasladoActivoFijo)
    {
        if (TrasladoActivoFijo->objectName().isEmpty())
            TrasladoActivoFijo->setObjectName(QString::fromUtf8("TrasladoActivoFijo"));
        TrasladoActivoFijo->setWindowModality(Qt::ApplicationModal);
        TrasladoActivoFijo->resize(975, 640);
        TrasladoActivoFijo->setMinimumSize(QSize(975, 625));
        gridLayout = new QGridLayout(TrasladoActivoFijo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(TrasladoActivoFijo);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        temporal = new QRadioButton(groupBox_2);
        temporal->setObjectName(QString::fromUtf8("temporal"));

        verticalLayout->addWidget(temporal);

        definitivo = new QRadioButton(groupBox_2);
        definitivo->setObjectName(QString::fromUtf8("definitivo"));

        verticalLayout->addWidget(definitivo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox_2, 0, 1, 2, 1);

        groupBox = new QGroupBox(TrasladoActivoFijo);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);


        verticalLayout_2->addWidget(widget_2);

        widget_10 = new QWidget(groupBox);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_5 = new QHBoxLayout(widget_10);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        cuentaNO = new QLineEdit(widget_10);
        cuentaNO->setObjectName(QString::fromUtf8("cuentaNO"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        cuentaNO->setFont(font);
        cuentaNO->setMaxLength(5);

        horizontalLayout_5->addWidget(cuentaNO);

        claseNO = new QLineEdit(widget_10);
        claseNO->setObjectName(QString::fromUtf8("claseNO"));
        claseNO->setFont(font);
        claseNO->setMaxLength(3);

        horizontalLayout_5->addWidget(claseNO);

        correlativoNO = new QLineEdit(widget_10);
        correlativoNO->setObjectName(QString::fromUtf8("correlativoNO"));
        correlativoNO->setFont(font);
        correlativoNO->setMaxLength(4);

        horizontalLayout_5->addWidget(correlativoNO);

        especificoNO = new QLineEdit(widget_10);
        especificoNO->setObjectName(QString::fromUtf8("especificoNO"));
        especificoNO->setFont(font);
        especificoNO->setMaxLength(5);

        horizontalLayout_5->addWidget(especificoNO);

        consultaBien = new QToolButton(widget_10);
        consultaBien->setObjectName(QString::fromUtf8("consultaBien"));

        horizontalLayout_5->addWidget(consultaBien);


        verticalLayout_2->addWidget(widget_10);


        gridLayout->addWidget(groupBox, 0, 2, 2, 3);

        label_4 = new QLabel(TrasladoActivoFijo);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 8, 0, 1, 1);

        observaciones = new QLineEdit(TrasladoActivoFijo);
        observaciones->setObjectName(QString::fromUtf8("observaciones"));
        observaciones->setMaxLength(148);

        gridLayout->addWidget(observaciones, 12, 1, 1, 3);

        label_18 = new QLabel(TrasladoActivoFijo);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Impact"));
        font1.setPointSize(20);
        label_18->setFont(font1);

        gridLayout->addWidget(label_18, 13, 0, 1, 1);

        widget = new QWidget(TrasladoActivoFijo);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        guardarTraslado = new QPushButton(widget);
        guardarTraslado->setObjectName(QString::fromUtf8("guardarTraslado"));

        horizontalLayout->addWidget(guardarTraslado);

        finalizarTransaccion = new QPushButton(widget);
        finalizarTransaccion->setObjectName(QString::fromUtf8("finalizarTransaccion"));

        horizontalLayout->addWidget(finalizarTransaccion);

        cancelar = new QPushButton(widget);
        cancelar->setObjectName(QString::fromUtf8("cancelar"));

        horizontalLayout->addWidget(cancelar);


        gridLayout->addWidget(widget, 13, 3, 1, 1);

        label_17 = new QLabel(TrasladoActivoFijo);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 12, 0, 1, 1);

        groupBox_5 = new QGroupBox(TrasladoActivoFijo);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_3 = new QGridLayout(groupBox_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget_8 = new QWidget(groupBox_5);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        gridLayout_4 = new QGridLayout(widget_8);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget_4 = new QWidget(widget_8);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        formLayout_2 = new QFormLayout(widget_4);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_11 = new QLabel(widget_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_11);

        label_10 = new QLabel(widget_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_10);

        marca = new QLineEdit(widget_4);
        marca->setObjectName(QString::fromUtf8("marca"));
        marca->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, marca);

        modelo = new QLineEdit(widget_4);
        modelo->setObjectName(QString::fromUtf8("modelo"));
        modelo->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, modelo);


        gridLayout_4->addWidget(widget_4, 0, 1, 1, 1);

        widget_5 = new QWidget(widget_8);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        formLayout_3 = new QFormLayout(widget_5);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_15 = new QLabel(widget_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_15);

        label_13 = new QLabel(widget_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_13);

        valorBien = new QDoubleSpinBox(widget_5);
        valorBien->setObjectName(QString::fromUtf8("valorBien"));
        valorBien->setFont(font);
        valorBien->setLocale(QLocale(QLocale::Spanish, QLocale::ElSalvador));
        valorBien->setWrapping(false);
        valorBien->setFrame(true);
        valorBien->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valorBien->setReadOnly(true);
        valorBien->setButtonSymbols(QAbstractSpinBox::NoButtons);
        valorBien->setKeyboardTracking(true);
        valorBien->setMaximum(1e+07);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, valorBien);

        serie = new QLineEdit(widget_5);
        serie->setObjectName(QString::fromUtf8("serie"));
        serie->setMaxLength(25);
        serie->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        serie->setReadOnly(true);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, serie);


        gridLayout_4->addWidget(widget_5, 0, 2, 1, 1);

        widget_6 = new QWidget(widget_8);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_14 = new QLabel(widget_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_4->addWidget(label_14);

        fechaAquisicion = new QDateEdit(widget_6);
        fechaAquisicion->setObjectName(QString::fromUtf8("fechaAquisicion"));
        fechaAquisicion->setReadOnly(true);

        verticalLayout_4->addWidget(fechaAquisicion);


        gridLayout_4->addWidget(widget_6, 0, 3, 1, 1);

        widget_7 = new QWidget(widget_8);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_3 = new QHBoxLayout(widget_7);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_12 = new QLabel(widget_7);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_3->addWidget(label_12);

        descripcion = new QLineEdit(widget_7);
        descripcion->setObjectName(QString::fromUtf8("descripcion"));
        descripcion->setReadOnly(true);

        horizontalLayout_3->addWidget(descripcion);


        gridLayout_4->addWidget(widget_7, 1, 1, 1, 3);

        widget_61 = new QWidget(widget_8);
        widget_61->setObjectName(QString::fromUtf8("widget_61"));
        formLayout = new QFormLayout(widget_61);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_8 = new QLabel(widget_61);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_8);

        cuentaAsignada = new QLineEdit(widget_61);
        cuentaAsignada->setObjectName(QString::fromUtf8("cuentaAsignada"));
        cuentaAsignada->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, cuentaAsignada);

        label_19 = new QLabel(widget_61);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_19);

        nombreEspecifico = new QLineEdit(widget_61);
        nombreEspecifico->setObjectName(QString::fromUtf8("nombreEspecifico"));
        nombreEspecifico->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, nombreEspecifico);


        gridLayout_4->addWidget(widget_61, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_8, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox_5, 3, 0, 1, 5);

        tablaBienes = new QTableWidget(TrasladoActivoFijo);
        tablaBienes->setObjectName(QString::fromUtf8("tablaBienes"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tablaBienes->sizePolicy().hasHeightForWidth());
        tablaBienes->setSizePolicy(sizePolicy);

        gridLayout->addWidget(tablaBienes, 4, 0, 4, 4);

        botonAgregarBien = new QToolButton(TrasladoActivoFijo);
        botonAgregarBien->setObjectName(QString::fromUtf8("botonAgregarBien"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonAgregarBien->setIcon(icon);

        gridLayout->addWidget(botonAgregarBien, 4, 4, 1, 1);

        botonEliminarBien = new QToolButton(TrasladoActivoFijo);
        botonEliminarBien->setObjectName(QString::fromUtf8("botonEliminarBien"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonEliminarBien->setIcon(icon1);

        gridLayout->addWidget(botonEliminarBien, 5, 4, 1, 1);

        nuevoBien = new QToolButton(TrasladoActivoFijo);
        nuevoBien->setObjectName(QString::fromUtf8("nuevoBien"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        nuevoBien->setIcon(icon2);

        gridLayout->addWidget(nuevoBien, 6, 4, 1, 1);

        totalIngreso = new QLineEdit(TrasladoActivoFijo);
        totalIngreso->setObjectName(QString::fromUtf8("totalIngreso"));
        totalIngreso->setReadOnly(true);

        gridLayout->addWidget(totalIngreso, 11, 1, 1, 1);

        label_16 = new QLabel(TrasladoActivoFijo);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 11, 0, 1, 1);

        widget_3 = new QWidget(TrasladoActivoFijo);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        codigoTraslado = new QLineEdit(widget_3);
        codigoTraslado->setObjectName(QString::fromUtf8("codigoTraslado"));

        verticalLayout_3->addWidget(codigoTraslado);


        gridLayout->addWidget(widget_3, 0, 0, 1, 1);

        widget_9 = new QWidget(TrasladoActivoFijo);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        verticalLayout_5 = new QVBoxLayout(widget_9);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_9 = new QLabel(widget_9);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_5->addWidget(label_9);

        unidadRecibe = new QComboBox(widget_9);
        unidadRecibe->setObjectName(QString::fromUtf8("unidadRecibe"));

        verticalLayout_5->addWidget(unidadRecibe);


        gridLayout->addWidget(widget_9, 1, 0, 1, 1);


        retranslateUi(TrasladoActivoFijo);
        QObject::connect(cuentaNO, SIGNAL(textChanged(QString)), claseNO, SLOT(clear()));
        QObject::connect(claseNO, SIGNAL(textChanged(QString)), correlativoNO, SLOT(clear()));
        QObject::connect(claseNO, SIGNAL(textChanged(QString)), especificoNO, SLOT(clear()));
        QObject::connect(correlativoNO, SIGNAL(textChanged(QString)), marca, SLOT(clear()));
        QObject::connect(correlativoNO, SIGNAL(textChanged(QString)), valorBien, SLOT(clear()));
        QObject::connect(correlativoNO, SIGNAL(textChanged(QString)), modelo, SLOT(clear()));
        QObject::connect(correlativoNO, SIGNAL(textChanged(QString)), serie, SLOT(clear()));
        QObject::connect(correlativoNO, SIGNAL(textChanged(QString)), fechaAquisicion, SLOT(clear()));
        QObject::connect(correlativoNO, SIGNAL(textChanged(QString)), descripcion, SLOT(clear()));

        QMetaObject::connectSlotsByName(TrasladoActivoFijo);
    } // setupUi

    void retranslateUi(QWidget *TrasladoActivoFijo)
    {
        TrasladoActivoFijo->setWindowTitle(QApplication::translate("TrasladoActivoFijo", "Tralado de Bienes al Inventario de Activo Fijo", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("TrasladoActivoFijo", "Tipo Traslado:", 0, QApplication::UnicodeUTF8));
        temporal->setText(QApplication::translate("TrasladoActivoFijo", "Temporal", 0, QApplication::UnicodeUTF8));
        definitivo->setText(QApplication::translate("TrasladoActivoFijo", "Definitivo", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("TrasladoActivoFijo", "Codigo Bien:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TrasladoActivoFijo", "Clase:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TrasladoActivoFijo", "Cuenta:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TrasladoActivoFijo", "Correlativo:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TrasladoActivoFijo", "Especifico:", 0, QApplication::UnicodeUTF8));
        consultaBien->setText(QApplication::translate("TrasladoActivoFijo", "...", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_18->setText(QApplication::translate("TrasladoActivoFijo", "AF-M2", 0, QApplication::UnicodeUTF8));
        guardarTraslado->setText(QApplication::translate("TrasladoActivoFijo", "Guardar", 0, QApplication::UnicodeUTF8));
        finalizarTransaccion->setText(QApplication::translate("TrasladoActivoFijo", "Trasladar", 0, QApplication::UnicodeUTF8));
        cancelar->setText(QApplication::translate("TrasladoActivoFijo", "Cancelar", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("TrasladoActivoFijo", "Observaciones:", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("TrasladoActivoFijo", "Bien:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("TrasladoActivoFijo", "Modelo:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("TrasladoActivoFijo", "Marca:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("TrasladoActivoFijo", "Valor:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("TrasladoActivoFijo", "Serie:", 0, QApplication::UnicodeUTF8));
        valorBien->setSpecialValueText(QString());
        label_14->setText(QApplication::translate("TrasladoActivoFijo", "Adquirido:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("TrasladoActivoFijo", "Descripcion:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("TrasladoActivoFijo", "Cuenta: ", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("TrasladoActivoFijo", "Especifico: ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botonAgregarBien->setToolTip(QApplication::translate("TrasladoActivoFijo", "Agregar Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonAgregarBien->setText(QString());
#ifndef QT_NO_TOOLTIP
        botonEliminarBien->setToolTip(QApplication::translate("TrasladoActivoFijo", "Eliminar Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonEliminarBien->setText(QApplication::translate("TrasladoActivoFijo", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        nuevoBien->setToolTip(QApplication::translate("TrasladoActivoFijo", "Nuevo Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nuevoBien->setText(QApplication::translate("TrasladoActivoFijo", "...", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("TrasladoActivoFijo", "Total:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TrasladoActivoFijo", "Codigo Traslado:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("TrasladoActivoFijo", "Unidad que Recibe:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TrasladoActivoFijo: public Ui_TrasladoActivoFijo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRASLADOACTIVOFIJO_H
