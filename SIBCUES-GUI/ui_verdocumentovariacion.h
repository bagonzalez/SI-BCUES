/********************************************************************************
** Form generated from reading UI file 'verdocumentovariacion.ui'
**
** Created: Mon 19. Jul 20:18:09 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERDOCUMENTOVARIACION_H
#define UI_VERDOCUMENTOVARIACION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerDocumentoVariacion
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QTableWidget *TablaListaVariaciones;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QPushButton *Seleccionar;
    QPushButton *Cancelar;

    void setupUi(QWidget *VerDocumentoVariacion)
    {
        if (VerDocumentoVariacion->objectName().isEmpty())
            VerDocumentoVariacion->setObjectName(QString::fromUtf8("VerDocumentoVariacion"));
        VerDocumentoVariacion->setWindowModality(Qt::ApplicationModal);
        VerDocumentoVariacion->resize(545, 347);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/iconos-feed-fasticon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        VerDocumentoVariacion->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(VerDocumentoVariacion);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(VerDocumentoVariacion);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 24, 477, 16));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        TablaListaVariaciones = new QTableWidget(groupBox);
        if (TablaListaVariaciones->columnCount() < 1)
            TablaListaVariaciones->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TablaListaVariaciones->setHorizontalHeaderItem(0, __qtablewidgetitem);
        TablaListaVariaciones->setObjectName(QString::fromUtf8("TablaListaVariaciones"));
        TablaListaVariaciones->setGeometry(QRect(80, 70, 101, 241));
        TablaListaVariaciones->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(310, 70, 131, 111));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Seleccionar = new QPushButton(groupBox_2);
        Seleccionar->setObjectName(QString::fromUtf8("Seleccionar"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/Oxygen_Refit_thumb[2].png"), QSize(), QIcon::Normal, QIcon::Off);
        Seleccionar->setIcon(icon1);

        verticalLayout->addWidget(Seleccionar);

        Cancelar = new QPushButton(groupBox_2);
        Cancelar->setObjectName(QString::fromUtf8("Cancelar"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/iconos.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Cancelar->setIcon(icon2);

        verticalLayout->addWidget(Cancelar);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(VerDocumentoVariacion);
        QObject::connect(Cancelar, SIGNAL(clicked()), VerDocumentoVariacion, SLOT(close()));

        QMetaObject::connectSlotsByName(VerDocumentoVariacion);
    } // setupUi

    void retranslateUi(QWidget *VerDocumentoVariacion)
    {
        VerDocumentoVariacion->setWindowTitle(QApplication::translate("VerDocumentoVariacion", "Visualizacion de Informe de variacion de gastos por unidad presupuestaria", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("VerDocumentoVariacion", "Seleccion de a\303\261o de Documento de variacion de Gastos por Unidad Presupuestaria", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("VerDocumentoVariacion", "Seleccione Documento Variaci\303\263n de Gastos por unidad Presupuestaria que desea Ver", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = TablaListaVariaciones->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("VerDocumentoVariacion", "A\303\261o", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("VerDocumentoVariacion", "Opciones", 0, QApplication::UnicodeUTF8));
        Seleccionar->setText(QApplication::translate("VerDocumentoVariacion", "Seleccionar", 0, QApplication::UnicodeUTF8));
        Cancelar->setText(QApplication::translate("VerDocumentoVariacion", "Cancelar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VerDocumentoVariacion: public Ui_VerDocumentoVariacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERDOCUMENTOVARIACION_H
