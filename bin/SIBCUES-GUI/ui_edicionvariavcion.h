/********************************************************************************
** Form generated from reading UI file 'edicionvariavcion.ui'
**
** Created: Thu Apr 21 08:48:21 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDICIONVARIAVCION_H
#define UI_EDICIONVARIAVCION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edicionvariavcion
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *Institucion;
    QHBoxLayout *horizontalLayout_6;
    QLabel *EjercicioFiscal;
    QLineEdit *EjercicioFiscal2;
    QHBoxLayout *horizontalLayout_8;
    QSplitter *splitter_3;
    QLabel *EjercicioFiscal_4;
    QLineEdit *FuenteFinanciamiento;
    QHBoxLayout *horizontalLayout_9;
    QSplitter *splitter;
    QLabel *FechaElaboracion;
    QLineEdit *Fecha;
    QLineEdit *Institucion2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QTableWidget *tablaVariacion;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *AgregarButton;
    QPushButton *cancelarButton;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *salirButton;

    void setupUi(QWidget *edicionvariavcion)
    {
        if (edicionvariavcion->objectName().isEmpty())
            edicionvariavcion->setObjectName(QString::fromUtf8("edicionvariavcion"));
        edicionvariavcion->setWindowModality(Qt::ApplicationModal);
        edicionvariavcion->resize(942, 512);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/Oxygen_Refit_thumb[2].png"), QSize(), QIcon::Normal, QIcon::Off);
        edicionvariavcion->setWindowIcon(icon);
        gridLayout_4 = new QGridLayout(edicionvariavcion);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_2 = new QGroupBox(edicionvariavcion);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Institucion = new QLabel(groupBox);
        Institucion->setObjectName(QString::fromUtf8("Institucion"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        Institucion->setFont(font);

        gridLayout->addWidget(Institucion, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        EjercicioFiscal = new QLabel(groupBox);
        EjercicioFiscal->setObjectName(QString::fromUtf8("EjercicioFiscal"));
        EjercicioFiscal->setFont(font);

        horizontalLayout_6->addWidget(EjercicioFiscal);

        EjercicioFiscal2 = new QLineEdit(groupBox);
        EjercicioFiscal2->setObjectName(QString::fromUtf8("EjercicioFiscal2"));
        EjercicioFiscal2->setReadOnly(true);

        horizontalLayout_6->addWidget(EjercicioFiscal2);


        gridLayout->addLayout(horizontalLayout_6, 0, 2, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        splitter_3 = new QSplitter(groupBox);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        EjercicioFiscal_4 = new QLabel(splitter_3);
        EjercicioFiscal_4->setObjectName(QString::fromUtf8("EjercicioFiscal_4"));
        EjercicioFiscal_4->setFont(font);
        splitter_3->addWidget(EjercicioFiscal_4);
        FuenteFinanciamiento = new QLineEdit(splitter_3);
        FuenteFinanciamiento->setObjectName(QString::fromUtf8("FuenteFinanciamiento"));
        FuenteFinanciamiento->setReadOnly(true);
        splitter_3->addWidget(FuenteFinanciamiento);

        horizontalLayout_8->addWidget(splitter_3);


        gridLayout->addLayout(horizontalLayout_8, 0, 3, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        FechaElaboracion = new QLabel(splitter);
        FechaElaboracion->setObjectName(QString::fromUtf8("FechaElaboracion"));
        FechaElaboracion->setFont(font);
        splitter->addWidget(FechaElaboracion);
        Fecha = new QLineEdit(splitter);
        Fecha->setObjectName(QString::fromUtf8("Fecha"));
        Fecha->setReadOnly(true);
        splitter->addWidget(Fecha);

        horizontalLayout_9->addWidget(splitter);


        gridLayout->addLayout(horizontalLayout_9, 0, 4, 1, 1);

        Institucion2 = new QLineEdit(groupBox);
        Institucion2->setObjectName(QString::fromUtf8("Institucion2"));
        Institucion2->setReadOnly(true);

        gridLayout->addWidget(Institucion2, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tablaVariacion = new QTableWidget(groupBox_3);
        if (tablaVariacion->columnCount() < 5)
            tablaVariacion->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tablaVariacion->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setText(QString::fromUtf8("Nombre de Cuenta"));
        __qtablewidgetitem1->setFont(font);
        tablaVariacion->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tablaVariacion->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tablaVariacion->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tablaVariacion->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tablaVariacion->setObjectName(QString::fromUtf8("tablaVariacion"));
        tablaVariacion->setMinimumSize(QSize(660, 300));
        tablaVariacion->setMaximumSize(QSize(800, 600));
        tablaVariacion->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tablaVariacion->setMouseTracking(true);
        tablaVariacion->setAutoFillBackground(true);
        tablaVariacion->setLineWidth(3);
        tablaVariacion->setEditTriggers(QAbstractItemView::AllEditTriggers);
        tablaVariacion->setDragEnabled(false);
        tablaVariacion->setDragDropOverwriteMode(true);
        tablaVariacion->setAlternatingRowColors(true);
        tablaVariacion->setTextElideMode(Qt::ElideNone);
        tablaVariacion->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        tablaVariacion->setWordWrap(false);
        tablaVariacion->setRowCount(0);
        tablaVariacion->setColumnCount(5);

        gridLayout_2->addWidget(tablaVariacion, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        layoutWidget_2 = new QWidget(groupBox_4);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 90, 111, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        AgregarButton = new QPushButton(layoutWidget_2);
        AgregarButton->setObjectName(QString::fromUtf8("AgregarButton"));

        verticalLayout_2->addWidget(AgregarButton);

        cancelarButton = new QPushButton(layoutWidget_2);
        cancelarButton->setObjectName(QString::fromUtf8("cancelarButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/pre2-iconos.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelarButton->setIcon(icon1);

        verticalLayout_2->addWidget(cancelarButton);


        gridLayout_2->addWidget(groupBox_4, 0, 3, 1, 1);

        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_5 = new QVBoxLayout(groupBox_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        salirButton = new QPushButton(groupBox_5);
        salirButton->setObjectName(QString::fromUtf8("salirButton"));

        verticalLayout_5->addWidget(salirButton);


        gridLayout_2->addWidget(groupBox_5, 1, 3, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);


        retranslateUi(edicionvariavcion);
        QObject::connect(salirButton, SIGNAL(clicked()), edicionvariavcion, SLOT(close()));

        QMetaObject::connectSlotsByName(edicionvariavcion);
    } // setupUi

    void retranslateUi(QWidget *edicionvariavcion)
    {
        edicionvariavcion->setWindowTitle(QApplication::translate("edicionvariavcion", "Edicion Variacion de Gastos Presupuestaria", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("edicionvariavcion", "Variaci\303\263n de Gastos por Unidad Presupuestaria Linea de Trabajo,Rubro, Cuenta y Especifico", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("edicionvariavcion", "Datos Generales de Variaci\303\263n de Gastos por Unidad  Presupuestaria", 0, QApplication::UnicodeUTF8));
        Institucion->setText(QApplication::translate("edicionvariavcion", "Institucion", 0, QApplication::UnicodeUTF8));
        EjercicioFiscal->setText(QApplication::translate("edicionvariavcion", "Ejercicio Fiscal:", 0, QApplication::UnicodeUTF8));
        EjercicioFiscal_4->setText(QApplication::translate("edicionvariavcion", "Fuente Financiamiento:", 0, QApplication::UnicodeUTF8));
        FechaElaboracion->setText(QApplication::translate("edicionvariavcion", "Fecha Elaboracion", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("edicionvariavcion", "Especificacion Presupuesto Solicitado", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tablaVariacion->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("edicionvariavcion", "   Codigo Cuenta", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tablaVariacion->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("edicionvariavcion", "Presupuesto Aprobado (a)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tablaVariacion->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("edicionvariavcion", "Presupuesto Solicitado (b)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tablaVariacion->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QApplication::translate("edicionvariavcion", "Razonamiento", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("edicionvariavcion", "Registro: Presupuesto Solicitado", 0, QApplication::UnicodeUTF8));
        AgregarButton->setText(QApplication::translate("edicionvariavcion", "Modificar", 0, QApplication::UnicodeUTF8));
        cancelarButton->setText(QApplication::translate("edicionvariavcion", "Cancelar", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("edicionvariavcion", "Opciones", 0, QApplication::UnicodeUTF8));
        salirButton->setText(QApplication::translate("edicionvariavcion", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class edicionvariavcion: public Ui_edicionvariavcion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDICIONVARIAVCION_H
