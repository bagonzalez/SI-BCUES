/********************************************************************************
** Form generated from reading UI file 'presupuestoaprobado.ui'
**
** Created: Thu Apr 21 08:48:21 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESUPUESTOAPROBADO_H
#define UI_PRESUPUESTOAPROBADO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
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

class Ui_PresupuestoAprobado
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
    QTableWidget *tablaPresupuestoAprobado;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *AgregarButton;
    QPushButton *cancelarButton;
    QGroupBox *groupBox_6;
    QSplitter *splitter_2;
    QLineEdit *montoTotallLine;
    QCommandLinkButton *TotalAprobadoLinkButton;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *salirButton;

    void setupUi(QWidget *PresupuestoAprobado)
    {
        if (PresupuestoAprobado->objectName().isEmpty())
            PresupuestoAprobado->setObjectName(QString::fromUtf8("PresupuestoAprobado"));
        PresupuestoAprobado->setWindowModality(Qt::ApplicationModal);
        PresupuestoAprobado->resize(899, 480);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/cosas.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        PresupuestoAprobado->setWindowIcon(icon);
        gridLayout_4 = new QGridLayout(PresupuestoAprobado);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_2 = new QGroupBox(PresupuestoAprobado);
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

        gridLayout->addWidget(Institucion2, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tablaPresupuestoAprobado = new QTableWidget(groupBox_3);
        if (tablaPresupuestoAprobado->columnCount() < 3)
            tablaPresupuestoAprobado->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tablaPresupuestoAprobado->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setText(QString::fromUtf8("Nombre de Cuenta"));
        __qtablewidgetitem1->setFont(font);
        tablaPresupuestoAprobado->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tablaPresupuestoAprobado->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tablaPresupuestoAprobado->setObjectName(QString::fromUtf8("tablaPresupuestoAprobado"));
        tablaPresupuestoAprobado->setMinimumSize(QSize(261, 211));
        tablaPresupuestoAprobado->setMaximumSize(QSize(600, 500));
        tablaPresupuestoAprobado->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        tablaPresupuestoAprobado->setMouseTracking(true);
        tablaPresupuestoAprobado->setAutoFillBackground(true);
        tablaPresupuestoAprobado->setLineWidth(3);
        tablaPresupuestoAprobado->setEditTriggers(QAbstractItemView::AllEditTriggers);
        tablaPresupuestoAprobado->setDragEnabled(false);
        tablaPresupuestoAprobado->setDragDropOverwriteMode(true);
        tablaPresupuestoAprobado->setAlternatingRowColors(true);
        tablaPresupuestoAprobado->setTextElideMode(Qt::ElideNone);
        tablaPresupuestoAprobado->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        tablaPresupuestoAprobado->setWordWrap(false);
        tablaPresupuestoAprobado->setRowCount(0);
        tablaPresupuestoAprobado->setColumnCount(3);

        gridLayout_2->addWidget(tablaPresupuestoAprobado, 0, 0, 1, 1);

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

        groupBox_6 = new QGroupBox(groupBox_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        splitter_2 = new QSplitter(groupBox_6);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(430, 30, 139, 20));
        splitter_2->setOrientation(Qt::Horizontal);
        montoTotallLine = new QLineEdit(splitter_2);
        montoTotallLine->setObjectName(QString::fromUtf8("montoTotallLine"));
        montoTotallLine->setReadOnly(true);
        splitter_2->addWidget(montoTotallLine);
        TotalAprobadoLinkButton = new QCommandLinkButton(groupBox_6);
        TotalAprobadoLinkButton->setObjectName(QString::fromUtf8("TotalAprobadoLinkButton"));
        TotalAprobadoLinkButton->setGeometry(QRect(170, 20, 221, 41));

        gridLayout_2->addWidget(groupBox_6, 1, 0, 2, 1);

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


        retranslateUi(PresupuestoAprobado);
        QObject::connect(salirButton, SIGNAL(clicked()), PresupuestoAprobado, SLOT(close()));

        QMetaObject::connectSlotsByName(PresupuestoAprobado);
    } // setupUi

    void retranslateUi(QWidget *PresupuestoAprobado)
    {
        PresupuestoAprobado->setWindowTitle(QApplication::translate("PresupuestoAprobado", "Registro Presupuesto Aprobado", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("PresupuestoAprobado", "Variaci\303\263n de Gastos por Unidad Presupuestaria Linea de Trabajo,Rubro, Cuenta y Especifico", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PresupuestoAprobado", "Datos Generales de Variaci\303\263n de Gastos por Unidad  Presupuestaria", 0, QApplication::UnicodeUTF8));
        Institucion->setText(QApplication::translate("PresupuestoAprobado", "Institucion", 0, QApplication::UnicodeUTF8));
        EjercicioFiscal->setText(QApplication::translate("PresupuestoAprobado", "Ejercicio Fiscal:", 0, QApplication::UnicodeUTF8));
        EjercicioFiscal_4->setText(QApplication::translate("PresupuestoAprobado", "Fuente Financiamiento:", 0, QApplication::UnicodeUTF8));
        FechaElaboracion->setText(QApplication::translate("PresupuestoAprobado", "Fecha Elaboracion", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("PresupuestoAprobado", "Especificacion Presupuesto Solicitado", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tablaPresupuestoAprobado->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PresupuestoAprobado", "   Codigo Cuenta", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tablaPresupuestoAprobado->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("PresupuestoAprobado", "Presupuesto Aprobado", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("PresupuestoAprobado", "Registro: Presupuesto Solicitado", 0, QApplication::UnicodeUTF8));
        AgregarButton->setText(QApplication::translate("PresupuestoAprobado", "Agregar", 0, QApplication::UnicodeUTF8));
        cancelarButton->setText(QApplication::translate("PresupuestoAprobado", "Cancelar", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("PresupuestoAprobado", "Total Supuesto Aprobado", 0, QApplication::UnicodeUTF8));
        montoTotallLine->setText(QString());
        TotalAprobadoLinkButton->setText(QApplication::translate("PresupuestoAprobado", "Obtener Total Aprobado", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("PresupuestoAprobado", "Opciones", 0, QApplication::UnicodeUTF8));
        salirButton->setText(QApplication::translate("PresupuestoAprobado", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PresupuestoAprobado: public Ui_PresupuestoAprobado {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESUPUESTOAPROBADO_H
