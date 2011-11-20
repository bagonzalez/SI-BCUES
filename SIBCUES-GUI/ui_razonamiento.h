/********************************************************************************
** Form generated from reading UI file 'razonamiento.ui'
**
** Created: Mon 19. Jul 20:18:09 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAZONAMIENTO_H
#define UI_RAZONAMIENTO_H

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

class Ui_Razonamiento
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
    QTableWidget *tablaRazonamiento;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *AgregarButton;
    QPushButton *cancelarButton;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *salirButton;

    void setupUi(QWidget *Razonamiento)
    {
        if (Razonamiento->objectName().isEmpty())
            Razonamiento->setObjectName(QString::fromUtf8("Razonamiento"));
        Razonamiento->setWindowModality(Qt::ApplicationModal);
        Razonamiento->resize(938, 511);
        Razonamiento->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/cosas.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Razonamiento->setWindowIcon(icon);
        gridLayout_4 = new QGridLayout(Razonamiento);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_2 = new QGroupBox(Razonamiento);
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
        tablaRazonamiento = new QTableWidget(groupBox_3);
        if (tablaRazonamiento->columnCount() < 6)
            tablaRazonamiento->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tablaRazonamiento->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setText(QString::fromUtf8("Nombre de Cuenta"));
        __qtablewidgetitem1->setFont(font);
        tablaRazonamiento->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tablaRazonamiento->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tablaRazonamiento->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tablaRazonamiento->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tablaRazonamiento->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tablaRazonamiento->setObjectName(QString::fromUtf8("tablaRazonamiento"));
        tablaRazonamiento->setMinimumSize(QSize(660, 300));
        tablaRazonamiento->setMaximumSize(QSize(800, 600));
        tablaRazonamiento->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tablaRazonamiento->setMouseTracking(true);
        tablaRazonamiento->setAutoFillBackground(true);
        tablaRazonamiento->setLineWidth(3);
        tablaRazonamiento->setEditTriggers(QAbstractItemView::AllEditTriggers);
        tablaRazonamiento->setDragEnabled(false);
        tablaRazonamiento->setDragDropOverwriteMode(true);
        tablaRazonamiento->setAlternatingRowColors(true);
        tablaRazonamiento->setTextElideMode(Qt::ElideNone);
        tablaRazonamiento->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        tablaRazonamiento->setWordWrap(false);
        tablaRazonamiento->setRowCount(0);
        tablaRazonamiento->setColumnCount(6);

        gridLayout_2->addWidget(tablaRazonamiento, 0, 0, 1, 1);

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


        retranslateUi(Razonamiento);
        QObject::connect(salirButton, SIGNAL(clicked()), Razonamiento, SLOT(close()));

        QMetaObject::connectSlotsByName(Razonamiento);
    } // setupUi

    void retranslateUi(QWidget *Razonamiento)
    {
        Razonamiento->setWindowTitle(QApplication::translate("Razonamiento", "Registro de Razonamiento", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Razonamiento", "Variaci\303\263n de Gastos por Unidad Presupuestaria Linea de Trabajo,Rubro, Cuenta y Especifico", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Razonamiento", "Datos Generales de Variaci\303\263n de Gastos por Unidad  Presupuestaria", 0, QApplication::UnicodeUTF8));
        Institucion->setText(QApplication::translate("Razonamiento", "Institucion", 0, QApplication::UnicodeUTF8));
        EjercicioFiscal->setText(QApplication::translate("Razonamiento", "Ejercicio Fiscal:", 0, QApplication::UnicodeUTF8));
        EjercicioFiscal_4->setText(QApplication::translate("Razonamiento", "Fuente Financiamiento:", 0, QApplication::UnicodeUTF8));
        FechaElaboracion->setText(QApplication::translate("Razonamiento", "Fecha Elaboracion", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Razonamiento", "Especificacion Presupuesto Solicitado", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tablaRazonamiento->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Razonamiento", "   Codigo Cuenta", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tablaRazonamiento->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("Razonamiento", "Presupuesto Aprobado (a)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tablaRazonamiento->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("Razonamiento", "Presupuesto Solicitado (b)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tablaRazonamiento->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QApplication::translate("Razonamiento", "Variacion (b-a)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tablaRazonamiento->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QApplication::translate("Razonamiento", "Razonamiento", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Razonamiento", "Registro: Presupuesto Solicitado", 0, QApplication::UnicodeUTF8));
        AgregarButton->setText(QApplication::translate("Razonamiento", "Agregar", 0, QApplication::UnicodeUTF8));
        cancelarButton->setText(QApplication::translate("Razonamiento", "Cancelar", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("Razonamiento", "Opciones", 0, QApplication::UnicodeUTF8));
        salirButton->setText(QApplication::translate("Razonamiento", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Razonamiento: public Ui_Razonamiento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAZONAMIENTO_H
