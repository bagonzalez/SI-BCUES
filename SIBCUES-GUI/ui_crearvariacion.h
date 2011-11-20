/********************************************************************************
** Form generated from reading UI file 'crearvariacion.ui'
**
** Created: Mon 19. Jul 20:18:10 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREARVARIACION_H
#define UI_CREARVARIACION_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CrearVariacion
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
    QSpinBox *EjercicioFiscal2;
    QHBoxLayout *horizontalLayout_8;
    QSplitter *splitter_3;
    QLabel *EjercicioFiscal_4;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_9;
    QSplitter *splitter;
    QLabel *FechaElaboracion;
    QDateEdit *dateElaboracion;
    QLineEdit *Institucion2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QTableWidget *tablaPresupuestoSolicitado;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *AgregarButton;
    QPushButton *CancelarButton;
    QGroupBox *groupBox_6;
    QCommandLinkButton *obtenerSolicitadoLinkButton;
    QSplitter *splitter_2;
    QLineEdit *montoTotallLine;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *salirButton;

    void setupUi(QWidget *CrearVariacion)
    {
        if (CrearVariacion->objectName().isEmpty())
            CrearVariacion->setObjectName(QString::fromUtf8("CrearVariacion"));
        CrearVariacion->setWindowModality(Qt::ApplicationModal);
        CrearVariacion->resize(1062, 459);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CrearVariacion->sizePolicy().hasHeightForWidth());
        CrearVariacion->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/cosas.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        CrearVariacion->setWindowIcon(icon);
        gridLayout_4 = new QGridLayout(CrearVariacion);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_2 = new QGroupBox(CrearVariacion);
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

        EjercicioFiscal2 = new QSpinBox(groupBox);
        EjercicioFiscal2->setObjectName(QString::fromUtf8("EjercicioFiscal2"));
        EjercicioFiscal2->setMinimum(2010);
        EjercicioFiscal2->setMaximum(2999);

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
        comboBox = new QComboBox(splitter_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEditable(false);
        comboBox->setDuplicatesEnabled(false);
        splitter_3->addWidget(comboBox);

        horizontalLayout_8->addWidget(splitter_3);


        gridLayout->addLayout(horizontalLayout_8, 0, 4, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        FechaElaboracion = new QLabel(splitter);
        FechaElaboracion->setObjectName(QString::fromUtf8("FechaElaboracion"));
        FechaElaboracion->setFont(font);
        splitter->addWidget(FechaElaboracion);
        dateElaboracion = new QDateEdit(splitter);
        dateElaboracion->setObjectName(QString::fromUtf8("dateElaboracion"));
        dateElaboracion->setDateTime(QDateTime(QDate(2009, 11, 8), QTime(0, 0, 0)));
        dateElaboracion->setMinimumDateTime(QDateTime(QDate(2009, 11, 8), QTime(0, 0, 0)));
        dateElaboracion->setMinimumDate(QDate(2009, 11, 8));
        dateElaboracion->setCalendarPopup(true);
        dateElaboracion->setDate(QDate(2009, 11, 8));
        splitter->addWidget(dateElaboracion);

        horizontalLayout_9->addWidget(splitter);


        gridLayout->addLayout(horizontalLayout_9, 0, 5, 1, 1);

        Institucion2 = new QLineEdit(groupBox);
        Institucion2->setObjectName(QString::fromUtf8("Institucion2"));
        Institucion2->setReadOnly(true);

        gridLayout->addWidget(Institucion2, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tablaPresupuestoSolicitado = new QTableWidget(groupBox_3);
        if (tablaPresupuestoSolicitado->columnCount() < 3)
            tablaPresupuestoSolicitado->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tablaPresupuestoSolicitado->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setText(QString::fromUtf8("Nombre de Cuenta"));
        __qtablewidgetitem1->setFont(font);
        tablaPresupuestoSolicitado->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tablaPresupuestoSolicitado->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tablaPresupuestoSolicitado->setObjectName(QString::fromUtf8("tablaPresupuestoSolicitado"));
        tablaPresupuestoSolicitado->setMinimumSize(QSize(261, 211));
        tablaPresupuestoSolicitado->setMaximumSize(QSize(600, 500));
        tablaPresupuestoSolicitado->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tablaPresupuestoSolicitado->setMouseTracking(true);
        tablaPresupuestoSolicitado->setAutoFillBackground(true);
        tablaPresupuestoSolicitado->setLineWidth(2);
        tablaPresupuestoSolicitado->setEditTriggers(QAbstractItemView::CurrentChanged|QAbstractItemView::DoubleClicked);
        tablaPresupuestoSolicitado->setDragEnabled(false);
        tablaPresupuestoSolicitado->setDragDropOverwriteMode(false);
        tablaPresupuestoSolicitado->setAlternatingRowColors(true);
        tablaPresupuestoSolicitado->setSelectionBehavior(QAbstractItemView::SelectItems);
        tablaPresupuestoSolicitado->setTextElideMode(Qt::ElideNone);
        tablaPresupuestoSolicitado->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        tablaPresupuestoSolicitado->setWordWrap(false);
        tablaPresupuestoSolicitado->setRowCount(0);
        tablaPresupuestoSolicitado->setColumnCount(3);
        tablaPresupuestoSolicitado->horizontalHeader()->setMinimumSectionSize(30);
        tablaPresupuestoSolicitado->verticalHeader()->setDefaultSectionSize(20);
        tablaPresupuestoSolicitado->verticalHeader()->setMinimumSectionSize(30);

        gridLayout_2->addWidget(tablaPresupuestoSolicitado, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        layoutWidget_2 = new QWidget(groupBox_4);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 80, 111, 91));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        AgregarButton = new QPushButton(layoutWidget_2);
        AgregarButton->setObjectName(QString::fromUtf8("AgregarButton"));
        AgregarButton->setIconSize(QSize(20, 20));

        verticalLayout_2->addWidget(AgregarButton);

        CancelarButton = new QPushButton(layoutWidget_2);
        CancelarButton->setObjectName(QString::fromUtf8("CancelarButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/pre2-iconos.png"), QSize(), QIcon::Normal, QIcon::Off);
        CancelarButton->setIcon(icon1);
        CancelarButton->setIconSize(QSize(20, 20));

        verticalLayout_2->addWidget(CancelarButton);


        gridLayout_2->addWidget(groupBox_4, 0, 3, 1, 1);

        groupBox_6 = new QGroupBox(groupBox_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        obtenerSolicitadoLinkButton = new QCommandLinkButton(groupBox_6);
        obtenerSolicitadoLinkButton->setObjectName(QString::fromUtf8("obtenerSolicitadoLinkButton"));
        obtenerSolicitadoLinkButton->setGeometry(QRect(140, 20, 221, 31));
        splitter_2 = new QSplitter(groupBox_6);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(410, 30, 139, 20));
        splitter_2->setOrientation(Qt::Horizontal);
        montoTotallLine = new QLineEdit(splitter_2);
        montoTotallLine->setObjectName(QString::fromUtf8("montoTotallLine"));
        montoTotallLine->setReadOnly(true);
        splitter_2->addWidget(montoTotallLine);

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


        retranslateUi(CrearVariacion);
        QObject::connect(salirButton, SIGNAL(clicked()), CrearVariacion, SLOT(close()));

        QMetaObject::connectSlotsByName(CrearVariacion);
    } // setupUi

    void retranslateUi(QWidget *CrearVariacion)
    {
        CrearVariacion->setWindowTitle(QApplication::translate("CrearVariacion", "Registro Presupuesto solocitado", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CrearVariacion", "Variaci\303\263n de Gastos por Unidad Presupuestaria Linea de Trabajo,Rubro, Cuenta y Especifico", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CrearVariacion", "Datos Generales de Variaci\303\263n de Gastos por Unidad  Presupuestaria", 0, QApplication::UnicodeUTF8));
        Institucion->setText(QApplication::translate("CrearVariacion", "Institucion:", 0, QApplication::UnicodeUTF8));
        EjercicioFiscal->setText(QApplication::translate("CrearVariacion", "Ejercicio Fiscal:", 0, QApplication::UnicodeUTF8));
        EjercicioFiscal_4->setText(QApplication::translate("CrearVariacion", "Fuente Financiamiento:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("CrearVariacion", "0201 Fondo General", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CrearVariacion", "0101 Fondos Propios", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CrearVariacion", "0203 Donado", 0, QApplication::UnicodeUTF8)
        );
        FechaElaboracion->setText(QApplication::translate("CrearVariacion", "Fecha Elaboracion", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CrearVariacion", "Especificacion Presupuesto Solicitado", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tablaPresupuestoSolicitado->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CrearVariacion", "   Codigo Cuenta", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tablaPresupuestoSolicitado->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("CrearVariacion", "Presupuesto Solicitado", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("CrearVariacion", "Registro: Presupuesto Solicitado", 0, QApplication::UnicodeUTF8));
        AgregarButton->setText(QApplication::translate("CrearVariacion", "Agregar", 0, QApplication::UnicodeUTF8));
        CancelarButton->setText(QApplication::translate("CrearVariacion", "Cancelar", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("CrearVariacion", "Total Supuesto Solicitado", 0, QApplication::UnicodeUTF8));
        obtenerSolicitadoLinkButton->setText(QApplication::translate("CrearVariacion", "Obtener Total Solicitado", 0, QApplication::UnicodeUTF8));
        montoTotallLine->setText(QString());
        groupBox_5->setTitle(QApplication::translate("CrearVariacion", "Opciones", 0, QApplication::UnicodeUTF8));
        salirButton->setText(QApplication::translate("CrearVariacion", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CrearVariacion: public Ui_CrearVariacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREARVARIACION_H
