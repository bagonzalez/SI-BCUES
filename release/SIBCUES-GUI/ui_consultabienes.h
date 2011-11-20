/********************************************************************************
** Form generated from reading UI file 'consultabienes.ui'
**
** Created: Sat 14. May 00:05:02 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSULTABIENES_H
#define UI_CONSULTABIENES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConsultaBienes
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QCheckBox *checkSector;
    QCheckBox *checkClase;
    QLabel *label;
    QComboBox *sectores;
    QGroupBox *grupoEspecificacion;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QLineEdit *numeroCuenta;
    QLabel *label_9;
    QLineEdit *nombreClase;
    QToolButton *btmBuscarClases;
    QLineEdit *descripcion;
    QDialogButtonBox *buttonBox;
    QLabel *labelResultados;
    QTableView *tablaBienes;
    QLabel *valorListado;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *seleccionarBien;

    void setupUi(QDialog *ConsultaBienes)
    {
        if (ConsultaBienes->objectName().isEmpty())
            ConsultaBienes->setObjectName(QString::fromUtf8("ConsultaBienes"));
        ConsultaBienes->resize(800, 600);
        ConsultaBienes->setMinimumSize(QSize(800, 600));
        verticalLayout = new QVBoxLayout(ConsultaBienes);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(ConsultaBienes);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        checkSector = new QCheckBox(groupBox);
        checkSector->setObjectName(QString::fromUtf8("checkSector"));

        formLayout->setWidget(0, QFormLayout::LabelRole, checkSector);

        checkClase = new QCheckBox(groupBox);
        checkClase->setObjectName(QString::fromUtf8("checkClase"));

        formLayout->setWidget(0, QFormLayout::FieldRole, checkClase);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        sectores = new QComboBox(groupBox);
        sectores->setObjectName(QString::fromUtf8("sectores"));
        sectores->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, sectores);


        verticalLayout->addWidget(groupBox);

        grupoEspecificacion = new QGroupBox(ConsultaBienes);
        grupoEspecificacion->setObjectName(QString::fromUtf8("grupoEspecificacion"));
        grupoEspecificacion->setEnabled(false);
        gridLayout_3 = new QGridLayout(grupoEspecificacion);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_8 = new QLabel(grupoEspecificacion);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        numeroCuenta = new QLineEdit(grupoEspecificacion);
        numeroCuenta->setObjectName(QString::fromUtf8("numeroCuenta"));

        gridLayout_3->addWidget(numeroCuenta, 0, 1, 1, 2);

        label_9 = new QLabel(grupoEspecificacion);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 0, 3, 1, 1);

        nombreClase = new QLineEdit(grupoEspecificacion);
        nombreClase->setObjectName(QString::fromUtf8("nombreClase"));
        nombreClase->setMaxLength(3);

        gridLayout_3->addWidget(nombreClase, 0, 4, 1, 1);

        btmBuscarClases = new QToolButton(grupoEspecificacion);
        btmBuscarClases->setObjectName(QString::fromUtf8("btmBuscarClases"));

        gridLayout_3->addWidget(btmBuscarClases, 0, 5, 1, 1);

        descripcion = new QLineEdit(grupoEspecificacion);
        descripcion->setObjectName(QString::fromUtf8("descripcion"));
        descripcion->setReadOnly(true);

        gridLayout_3->addWidget(descripcion, 1, 1, 1, 5);


        verticalLayout->addWidget(grupoEspecificacion);

        buttonBox = new QDialogButtonBox(ConsultaBienes);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        labelResultados = new QLabel(ConsultaBienes);
        labelResultados->setObjectName(QString::fromUtf8("labelResultados"));

        verticalLayout->addWidget(labelResultados);

        tablaBienes = new QTableView(ConsultaBienes);
        tablaBienes->setObjectName(QString::fromUtf8("tablaBienes"));

        verticalLayout->addWidget(tablaBienes);

        valorListado = new QLabel(ConsultaBienes);
        valorListado->setObjectName(QString::fromUtf8("valorListado"));

        verticalLayout->addWidget(valorListado);

        widget = new QWidget(ConsultaBienes);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        seleccionarBien = new QPushButton(widget);
        seleccionarBien->setObjectName(QString::fromUtf8("seleccionarBien"));

        horizontalLayout->addWidget(seleccionarBien);


        verticalLayout->addWidget(widget);


        retranslateUi(ConsultaBienes);
        QObject::connect(checkClase, SIGNAL(clicked(bool)), grupoEspecificacion, SLOT(setEnabled(bool)));
        QObject::connect(checkSector, SIGNAL(clicked(bool)), sectores, SLOT(setEnabled(bool)));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConsultaBienes, SLOT(close()));

        QMetaObject::connectSlotsByName(ConsultaBienes);
    } // setupUi

    void retranslateUi(QDialog *ConsultaBienes)
    {
        ConsultaBienes->setWindowTitle(QApplication::translate("ConsultaBienes", "Consulta de Bienes", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ConsultaBienes", "Filtro:", 0, QApplication::UnicodeUTF8));
        checkSector->setText(QApplication::translate("ConsultaBienes", "Sectores", 0, QApplication::UnicodeUTF8));
        checkClase->setText(QApplication::translate("ConsultaBienes", "Clase", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConsultaBienes", "Sector:", 0, QApplication::UnicodeUTF8));
        grupoEspecificacion->setTitle(QApplication::translate("ConsultaBienes", "Especificacion Bien:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ConsultaBienes", "Cuenta: ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ConsultaBienes", "Clase:", 0, QApplication::UnicodeUTF8));
        btmBuscarClases->setText(QApplication::translate("ConsultaBienes", "...", 0, QApplication::UnicodeUTF8));
        labelResultados->setText(QApplication::translate("ConsultaBienes", "Resultados: ", 0, QApplication::UnicodeUTF8));
        valorListado->setText(QApplication::translate("ConsultaBienes", "Valor del Listado: ", 0, QApplication::UnicodeUTF8));
        seleccionarBien->setText(QApplication::translate("ConsultaBienes", "Seleccionar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConsultaBienes: public Ui_ConsultaBienes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSULTABIENES_H
