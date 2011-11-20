/********************************************************************************
** Form generated from reading UI file 'mantenimientotitulo.ui'
**
** Created: Mon 19. Jul 20:18:11 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANTENIMIENTOTITULO_H
#define UI_MANTENIMIENTOTITULO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mantenimientoTitulo
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLineEdit *busqueda;
    QRadioButton *btmTitulo;
    QRadioButton *btmAutor;
    QPushButton *btmBuscar;
    QLabel *labelTitulo;
    QTableView *titulos;
    QVBoxLayout *verticalLayout_3;
    QToolButton *toolButton_3;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QWidget *page_2;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label_3;
    QListView *listaAutores;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_6;
    QToolButton *toolButton_6;
    QToolButton *toolButton_5;
    QToolButton *toolButton_4;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *seleccionarTitulo;

    void setupUi(QDialog *mantenimientoTitulo)
    {
        if (mantenimientoTitulo->objectName().isEmpty())
            mantenimientoTitulo->setObjectName(QString::fromUtf8("mantenimientoTitulo"));
        mantenimientoTitulo->setWindowModality(Qt::ApplicationModal);
        mantenimientoTitulo->resize(848, 604);
        gridLayout = new QGridLayout(mantenimientoTitulo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(mantenimientoTitulo);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        busqueda = new QLineEdit(groupBox_3);
        busqueda->setObjectName(QString::fromUtf8("busqueda"));

        gridLayout_2->addWidget(busqueda, 0, 0, 1, 1);

        btmTitulo = new QRadioButton(groupBox_3);
        btmTitulo->setObjectName(QString::fromUtf8("btmTitulo"));

        gridLayout_2->addWidget(btmTitulo, 0, 1, 1, 1);

        btmAutor = new QRadioButton(groupBox_3);
        btmAutor->setObjectName(QString::fromUtf8("btmAutor"));

        gridLayout_2->addWidget(btmAutor, 0, 2, 1, 1);

        btmBuscar = new QPushButton(groupBox_3);
        btmBuscar->setObjectName(QString::fromUtf8("btmBuscar"));

        gridLayout_2->addWidget(btmBuscar, 0, 3, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 2);

        labelTitulo = new QLabel(mantenimientoTitulo);
        labelTitulo->setObjectName(QString::fromUtf8("labelTitulo"));

        gridLayout->addWidget(labelTitulo, 1, 0, 1, 1);

        titulos = new QTableView(mantenimientoTitulo);
        titulos->setObjectName(QString::fromUtf8("titulos"));
        titulos->setAutoScroll(true);
        titulos->setAlternatingRowColors(true);

        gridLayout->addWidget(titulos, 4, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, 0, -1);
        toolButton_3 = new QToolButton(mantenimientoTitulo);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon);

        verticalLayout_3->addWidget(toolButton_3);

        toolButton_2 = new QToolButton(mantenimientoTitulo);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);

        verticalLayout_3->addWidget(toolButton_2);

        toolButton = new QToolButton(mantenimientoTitulo);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/default-applications-capplet.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon2);

        verticalLayout_3->addWidget(toolButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_3, 4, 1, 1, 1);

        stackedWidget = new QStackedWidget(mantenimientoTitulo);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));

        verticalLayout_5->addWidget(groupBox);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_5 = new QGridLayout(page_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        listaAutores = new QListView(groupBox_2);
        listaAutores->setObjectName(QString::fromUtf8("listaAutores"));
        listaAutores->setMaximumSize(QSize(16777215, 16777214));
        listaAutores->setAlternatingRowColors(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, listaAutores);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_2);


        gridLayout_5->addWidget(groupBox_2, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 1, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 4, 2, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, -1, 0, -1);
        toolButton_6 = new QToolButton(mantenimientoTitulo);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setIcon(icon);

        verticalLayout_6->addWidget(toolButton_6);

        toolButton_5 = new QToolButton(mantenimientoTitulo);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setIcon(icon1);

        verticalLayout_6->addWidget(toolButton_5);

        toolButton_4 = new QToolButton(mantenimientoTitulo);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setIcon(icon2);

        verticalLayout_6->addWidget(toolButton_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_6, 4, 4, 1, 1);

        widget = new QWidget(mantenimientoTitulo);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        seleccionarTitulo = new QToolButton(widget);
        seleccionarTitulo->setObjectName(QString::fromUtf8("seleccionarTitulo"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/iconos/button_ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        seleccionarTitulo->setIcon(icon3);

        horizontalLayout->addWidget(seleccionarTitulo);


        gridLayout->addWidget(widget, 0, 2, 1, 1);


        retranslateUi(mantenimientoTitulo);
        QObject::connect(busqueda, SIGNAL(returnPressed()), btmBuscar, SLOT(click()));

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(mantenimientoTitulo);
    } // setupUi

    void retranslateUi(QDialog *mantenimientoTitulo)
    {
        mantenimientoTitulo->setWindowTitle(QApplication::translate("mantenimientoTitulo", "Material Bibliografico", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("mantenimientoTitulo", "Busqueda", 0, QApplication::UnicodeUTF8));
        btmTitulo->setText(QApplication::translate("mantenimientoTitulo", "Titulo", 0, QApplication::UnicodeUTF8));
        btmAutor->setText(QApplication::translate("mantenimientoTitulo", "Autor", 0, QApplication::UnicodeUTF8));
        btmBuscar->setText(QApplication::translate("mantenimientoTitulo", "Buscar", 0, QApplication::UnicodeUTF8));
        labelTitulo->setText(QApplication::translate("mantenimientoTitulo", "Titulos:", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("mantenimientoTitulo", "...", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("mantenimientoTitulo", "...", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("mantenimientoTitulo", "...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("mantenimientoTitulo", "Titulo Obra", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("mantenimientoTitulo", "Autores:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("mantenimientoTitulo", "Lista:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("mantenimientoTitulo", "Nombre:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("mantenimientoTitulo", "Apellido:", 0, QApplication::UnicodeUTF8));
        toolButton_6->setText(QApplication::translate("mantenimientoTitulo", "...", 0, QApplication::UnicodeUTF8));
        toolButton_5->setText(QApplication::translate("mantenimientoTitulo", "...", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("mantenimientoTitulo", "...", 0, QApplication::UnicodeUTF8));
        seleccionarTitulo->setText(QApplication::translate("mantenimientoTitulo", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mantenimientoTitulo: public Ui_mantenimientoTitulo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANTENIMIENTOTITULO_H
