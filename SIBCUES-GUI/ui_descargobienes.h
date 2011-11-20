/********************************************************************************
** Form generated from reading UI file 'descargobienes.ui'
**
** Created: Sun 22. May 09:50:32 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef H_DESCARGOBIENES_H
#define H_DESCARGOBIENES_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DescargoBienes
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout;
    QWidget *widget_8;
    QGridLayout *gridLayout_5;
    QWidget *widget_10;
    QFormLayout *formLayout_4;
    QLabel *label_11;
    QLabel *label_10;
    QLineEdit *marca;
    QLineEdit *modelo;
    QWidget *widget_11;
    QFormLayout *formLayout_5;
    QLabel *label_15;
    QLabel *label_13;
    QDoubleSpinBox *valorBien;
    QLineEdit *serie;
    QWidget *widget_12;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_19;
    QDateEdit *fechaAquisicion;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_12;
    QLineEdit *descripcion;
    QWidget *widget_14;
    QFormLayout *formLayout_6;
    QLabel *label_8;
    QLineEdit *cuentaAsignada;
    QLabel *label_27;
    QLineEdit *nombreEspecifico;
    QWidget *widget_15;
    QGridLayout *gridLayout_3;
    QTableWidget *tablaBienes;
    QWidget *widget_16;
    QVBoxLayout *verticalLayout_3;
    QToolButton *botonAgregarBien;
    QToolButton *botonEliminarBien;
    QToolButton *nuevoBien;
    QSpacerItem *verticalSpacer;
    QWidget *widget_18;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_16;
    QLineEdit *totalIngreso;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_3;
    QFormLayout *formLayout_7;
    QLabel *label_4;
    QLineEdit *motivo;
    QLabel *label_17;
    QLineEdit *observaciones;
    QWidget *widget_17;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_14;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *guardarTraslado;
    QPushButton *finalizarTransaccion;
    QPushButton *cancelar;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;
    QLineEdit *cuentaNO;
    QLineEdit *claseNO;
    QLineEdit *correlativoNO;
    QLineEdit *especificoNO;
    QToolButton *consultaBien;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLineEdit *codigoDescargo;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QComboBox *anioInventario;

    void setupUi(QWidget *DescargoBienes)
    {
        if (DescargoBienes->objectName().isEmpty())
            DescargoBienes->setObjectName(QString::fromUtf8("DescargoBienes"));
        DescargoBienes->setWindowModality(Qt::ApplicationModal);
        DescargoBienes->resize(975, 699);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DescargoBienes->sizePolicy().hasHeightForWidth());
        DescargoBienes->setSizePolicy(sizePolicy);
        DescargoBienes->setMinimumSize(QSize(960, 625));
        DescargoBienes->setMaximumSize(QSize(897974, 989797));
        gridLayout = new QGridLayout(DescargoBienes);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_5 = new QGroupBox(DescargoBienes);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout = new QVBoxLayout(groupBox_5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_8 = new QWidget(groupBox_5);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        gridLayout_5 = new QGridLayout(widget_8);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        widget_10 = new QWidget(widget_8);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        formLayout_4 = new QFormLayout(widget_10);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_11 = new QLabel(widget_10);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_11);

        label_10 = new QLabel(widget_10);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_10);

        marca = new QLineEdit(widget_10);
        marca->setObjectName(QString::fromUtf8("marca"));
        marca->setReadOnly(true);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, marca);

        modelo = new QLineEdit(widget_10);
        modelo->setObjectName(QString::fromUtf8("modelo"));
        modelo->setReadOnly(true);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, modelo);


        gridLayout_5->addWidget(widget_10, 0, 1, 1, 1);

        widget_11 = new QWidget(widget_8);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        formLayout_5 = new QFormLayout(widget_11);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_15 = new QLabel(widget_11);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_15);

        label_13 = new QLabel(widget_11);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_13);

        valorBien = new QDoubleSpinBox(widget_11);
        valorBien->setObjectName(QString::fromUtf8("valorBien"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        valorBien->setFont(font);
        valorBien->setLocale(QLocale(QLocale::Spanish, QLocale::ElSalvador));
        valorBien->setWrapping(false);
        valorBien->setFrame(true);
        valorBien->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        valorBien->setReadOnly(true);
        valorBien->setButtonSymbols(QAbstractSpinBox::NoButtons);
        valorBien->setKeyboardTracking(true);
        valorBien->setMaximum(1e+07);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, valorBien);

        serie = new QLineEdit(widget_11);
        serie->setObjectName(QString::fromUtf8("serie"));
        serie->setMaxLength(25);
        serie->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        serie->setReadOnly(true);

        formLayout_5->setWidget(2, QFormLayout::FieldRole, serie);


        gridLayout_5->addWidget(widget_11, 0, 2, 1, 1);

        widget_12 = new QWidget(widget_8);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        verticalLayout_2 = new QVBoxLayout(widget_12);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_19 = new QLabel(widget_12);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_2->addWidget(label_19);

        fechaAquisicion = new QDateEdit(widget_12);
        fechaAquisicion->setObjectName(QString::fromUtf8("fechaAquisicion"));
        fechaAquisicion->setReadOnly(true);

        verticalLayout_2->addWidget(fechaAquisicion);


        gridLayout_5->addWidget(widget_12, 0, 3, 1, 1);

        widget_13 = new QWidget(widget_8);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        horizontalLayout_4 = new QHBoxLayout(widget_13);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_12 = new QLabel(widget_13);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_4->addWidget(label_12);

        descripcion = new QLineEdit(widget_13);
        descripcion->setObjectName(QString::fromUtf8("descripcion"));
        descripcion->setReadOnly(true);

        horizontalLayout_4->addWidget(descripcion);


        gridLayout_5->addWidget(widget_13, 1, 1, 1, 3);

        widget_14 = new QWidget(widget_8);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        formLayout_6 = new QFormLayout(widget_14);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        label_8 = new QLabel(widget_14);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_8);

        cuentaAsignada = new QLineEdit(widget_14);
        cuentaAsignada->setObjectName(QString::fromUtf8("cuentaAsignada"));
        cuentaAsignada->setReadOnly(true);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, cuentaAsignada);

        label_27 = new QLabel(widget_14);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label_27);

        nombreEspecifico = new QLineEdit(widget_14);
        nombreEspecifico->setObjectName(QString::fromUtf8("nombreEspecifico"));
        nombreEspecifico->setReadOnly(true);

        formLayout_6->setWidget(1, QFormLayout::FieldRole, nombreEspecifico);


        gridLayout_5->addWidget(widget_14, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_8);


        gridLayout->addWidget(groupBox_5, 1, 0, 1, 1);

        widget_15 = new QWidget(DescargoBienes);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        gridLayout_3 = new QGridLayout(widget_15);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tablaBienes = new QTableWidget(widget_15);
        tablaBienes->setObjectName(QString::fromUtf8("tablaBienes"));

        gridLayout_3->addWidget(tablaBienes, 1, 0, 1, 1);

        widget_16 = new QWidget(widget_15);
        widget_16->setObjectName(QString::fromUtf8("widget_16"));
        verticalLayout_3 = new QVBoxLayout(widget_16);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        botonAgregarBien = new QToolButton(widget_16);
        botonAgregarBien->setObjectName(QString::fromUtf8("botonAgregarBien"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonAgregarBien->setIcon(icon);

        verticalLayout_3->addWidget(botonAgregarBien);

        botonEliminarBien = new QToolButton(widget_16);
        botonEliminarBien->setObjectName(QString::fromUtf8("botonEliminarBien"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonEliminarBien->setIcon(icon1);

        verticalLayout_3->addWidget(botonEliminarBien);

        nuevoBien = new QToolButton(widget_16);
        nuevoBien->setObjectName(QString::fromUtf8("nuevoBien"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        nuevoBien->setIcon(icon2);

        verticalLayout_3->addWidget(nuevoBien);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        gridLayout_3->addWidget(widget_16, 1, 1, 1, 1);


        gridLayout->addWidget(widget_15, 2, 0, 1, 1);

        widget_18 = new QWidget(DescargoBienes);
        widget_18->setObjectName(QString::fromUtf8("widget_18"));
        horizontalLayout_6 = new QHBoxLayout(widget_18);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_16 = new QLabel(widget_18);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_6->addWidget(label_16);

        totalIngreso = new QLineEdit(widget_18);
        totalIngreso->setObjectName(QString::fromUtf8("totalIngreso"));
        totalIngreso->setReadOnly(true);

        horizontalLayout_6->addWidget(totalIngreso);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        gridLayout->addWidget(widget_18, 3, 0, 1, 1);

        widget_3 = new QWidget(DescargoBienes);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        formLayout_7 = new QFormLayout(widget_3);
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        formLayout_7->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_7->setWidget(3, QFormLayout::LabelRole, label_4);

        motivo = new QLineEdit(widget_3);
        motivo->setObjectName(QString::fromUtf8("motivo"));

        formLayout_7->setWidget(3, QFormLayout::FieldRole, motivo);

        label_17 = new QLabel(widget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_7->setWidget(4, QFormLayout::LabelRole, label_17);

        observaciones = new QLineEdit(widget_3);
        observaciones->setObjectName(QString::fromUtf8("observaciones"));
        observaciones->setMaxLength(148);

        formLayout_7->setWidget(4, QFormLayout::FieldRole, observaciones);


        gridLayout->addWidget(widget_3, 4, 0, 1, 1);

        widget_17 = new QWidget(DescargoBienes);
        widget_17->setObjectName(QString::fromUtf8("widget_17"));
        horizontalLayout_5 = new QHBoxLayout(widget_17);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_14 = new QLabel(widget_17);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Impact"));
        font1.setPointSize(20);
        label_14->setFont(font1);

        horizontalLayout_5->addWidget(label_14);

        widget_4 = new QWidget(widget_17);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        guardarTraslado = new QPushButton(widget_4);
        guardarTraslado->setObjectName(QString::fromUtf8("guardarTraslado"));

        horizontalLayout->addWidget(guardarTraslado);

        finalizarTransaccion = new QPushButton(widget_4);
        finalizarTransaccion->setObjectName(QString::fromUtf8("finalizarTransaccion"));

        horizontalLayout->addWidget(finalizarTransaccion);

        cancelar = new QPushButton(widget_4);
        cancelar->setObjectName(QString::fromUtf8("cancelar"));

        horizontalLayout->addWidget(cancelar);


        horizontalLayout_5->addWidget(widget_4);


        gridLayout->addWidget(widget_17, 5, 0, 1, 1);

        groupBox = new QGroupBox(DescargoBienes);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 0, 3, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 0, 4, 1, 1);

        cuentaNO = new QLineEdit(widget);
        cuentaNO->setObjectName(QString::fromUtf8("cuentaNO"));
        cuentaNO->setFont(font);
        cuentaNO->setMaxLength(5);

        gridLayout_4->addWidget(cuentaNO, 1, 1, 1, 1);

        claseNO = new QLineEdit(widget);
        claseNO->setObjectName(QString::fromUtf8("claseNO"));
        claseNO->setFont(font);
        claseNO->setMaxLength(3);

        gridLayout_4->addWidget(claseNO, 1, 2, 1, 1);

        correlativoNO = new QLineEdit(widget);
        correlativoNO->setObjectName(QString::fromUtf8("correlativoNO"));
        correlativoNO->setFont(font);
        correlativoNO->setMaxLength(4);

        gridLayout_4->addWidget(correlativoNO, 1, 3, 1, 1);

        especificoNO = new QLineEdit(widget);
        especificoNO->setObjectName(QString::fromUtf8("especificoNO"));
        especificoNO->setFont(font);
        especificoNO->setMaxLength(5);
        especificoNO->setReadOnly(true);

        gridLayout_4->addWidget(especificoNO, 1, 4, 1, 1);

        consultaBien = new QToolButton(widget);
        consultaBien->setObjectName(QString::fromUtf8("consultaBien"));

        gridLayout_4->addWidget(consultaBien, 1, 5, 1, 1);


        gridLayout_2->addWidget(widget, 1, 2, 1, 1);

        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        codigoDescargo = new QLineEdit(widget_2);
        codigoDescargo->setObjectName(QString::fromUtf8("codigoDescargo"));

        verticalLayout_4->addWidget(codigoDescargo);


        gridLayout_2->addWidget(widget_2, 1, 0, 1, 1);

        widget_5 = new QWidget(groupBox);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_5 = new QVBoxLayout(widget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_7 = new QLabel(widget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_5->addWidget(label_7);

        anioInventario = new QComboBox(widget_5);
        anioInventario->setObjectName(QString::fromUtf8("anioInventario"));

        verticalLayout_5->addWidget(anioInventario);


        gridLayout_2->addWidget(widget_5, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(DescargoBienes);
        QObject::connect(cuentaNO, SIGNAL(textChanged(QString)), claseNO, SLOT(clear()));
        QObject::connect(claseNO, SIGNAL(textChanged(QString)), correlativoNO, SLOT(clear()));
        QObject::connect(correlativoNO, SIGNAL(textChanged(QString)), especificoNO, SLOT(clear()));

        QMetaObject::connectSlotsByName(DescargoBienes);
    } // setupUi

    void retranslateUi(QWidget *DescargoBienes)
    {
        DescargoBienes->setWindowTitle(QApplication::translate("DescargoBienes", "Descargo de Bienes del Inventario de Activo Fijo", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("DescargoBienes", "Bien:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("DescargoBienes", "Modelo:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("DescargoBienes", "Marca:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("DescargoBienes", "Valor: ($)", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("DescargoBienes", "Serie:", 0, QApplication::UnicodeUTF8));
        valorBien->setSpecialValueText(QString());
        label_19->setText(QApplication::translate("DescargoBienes", "Adquirido:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("DescargoBienes", "Descripcion:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DescargoBienes", "Cuenta: ", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("DescargoBienes", "Especifico: ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botonAgregarBien->setToolTip(QApplication::translate("DescargoBienes", "Agregar Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonAgregarBien->setText(QString());
#ifndef QT_NO_TOOLTIP
        botonEliminarBien->setToolTip(QApplication::translate("DescargoBienes", "Eliminar Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonEliminarBien->setText(QApplication::translate("DescargoBienes", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        nuevoBien->setToolTip(QApplication::translate("DescargoBienes", "Nuevo Bien", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nuevoBien->setText(QApplication::translate("DescargoBienes", "...", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("DescargoBienes", "Total:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DescargoBienes", "Motivo del descargo:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("DescargoBienes", "Observaciones:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("DescargoBienes", "AF-M3", 0, QApplication::UnicodeUTF8));
        guardarTraslado->setText(QApplication::translate("DescargoBienes", "Guardar", 0, QApplication::UnicodeUTF8));
        finalizarTransaccion->setText(QApplication::translate("DescargoBienes", "Descargar", 0, QApplication::UnicodeUTF8));
        cancelar->setText(QApplication::translate("DescargoBienes", "Cancelar", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DescargoBienes", "Codigo del descargo y bien:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DescargoBienes", "Cuenta:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DescargoBienes", "Clase:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DescargoBienes", "Correlativo:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DescargoBienes", "Especifico:", 0, QApplication::UnicodeUTF8));
        consultaBien->setText(QApplication::translate("DescargoBienes", "...", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DescargoBienes", "Codigo Descargo:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DescargoBienes", "Inventario:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DescargoBienes: public Ui_DescargoBienes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // H_DESCARGOBIENES_H
