/********************************************************************************
** Form generated from reading UI file 'catalogoactivofijogui.ui'
**
** Created: Thu Apr 21 08:48:21 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATALOGOACTIVOFIJOGUI_H
#define UI_CATALOGOACTIVOFIJOGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CatalogoActivoFijoGUI
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *nombreClase;
    QLineEdit *cuentaAsignada;
    QLineEdit *numeroCuenta;
    QLineEdit *descripcion;
    QFrame *line;
    QToolButton *botonEliminar;
    QToolButton *botonNuevo;
    QToolButton *botonModificar;
    QToolButton *botonGuardar;
    QToolButton *ayudaActivoFijo;
    QTreeWidget *catalogoInventario;
    QGroupBox *groupBox_7;
    QLineEdit *saldoDeudor;
    QGroupBox *groupBox_8;
    QLineEdit *debe;
    QGroupBox *groupBox_9;
    QLineEdit *haber;
    QGroupBox *groupBox_10;
    QLineEdit *saldoAcreedor;
    QGroupBox *groupBox_11;
    QTextEdit *textEdit;
    QGroupBox *groupBox;
    QLineEdit *codigoCuenta;
    QToolButton *btmBuscar;
    QPushButton *btmSeleccionar;
    QPushButton *pushButton;
    QWidget *tab_4;
    QFrame *line_2;
    QLabel *label_10;
    QGroupBox *groupBox_4;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *claseBiblio;
    QLineEdit *cuentaBiblio;
    QLineEdit *especificoBiblio;
    QGroupBox *groupBox_5;
    QGroupBox *groupBox_6;
    QToolButton *botonEliminarBiblio;
    QToolButton *botonNuevoBiblio;
    QToolButton *botonModificaBiblio;
    QToolButton *botonGuardarBiblio;
    QToolButton *toolButton;
    QGroupBox *groupBox_3;
    QLineEdit *descripcionBiblio;
    QLabel *label_6;
    QLabel *label_8;
    QLineEdit *nombreUnidad;
    QLineEdit *nombreDpto;
    QLabel *label_17;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *CatalogoActivoFijoGUI)
    {
        if (CatalogoActivoFijoGUI->objectName().isEmpty())
            CatalogoActivoFijoGUI->setObjectName(QString::fromUtf8("CatalogoActivoFijoGUI"));
        CatalogoActivoFijoGUI->setWindowModality(Qt::ApplicationModal);
        CatalogoActivoFijoGUI->resize(900, 550);
        CatalogoActivoFijoGUI->setMinimumSize(QSize(640, 500));
        CatalogoActivoFijoGUI->setMaximumSize(QSize(900, 550));
        tabWidget = new QTabWidget(CatalogoActivoFijoGUI);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 70, 871, 441));
        tabWidget->setAutoFillBackground(true);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 60, 281, 181));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 30, 46, 14));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 100, 46, 14));
        nombreClase = new QLineEdit(groupBox_2);
        nombreClase->setObjectName(QString::fromUtf8("nombreClase"));
        nombreClase->setGeometry(QRect(70, 95, 51, 21));
        nombreClase->setMaxLength(3);
        nombreClase->setReadOnly(true);
        cuentaAsignada = new QLineEdit(groupBox_2);
        cuentaAsignada->setObjectName(QString::fromUtf8("cuentaAsignada"));
        cuentaAsignada->setGeometry(QRect(70, 60, 191, 21));
        cuentaAsignada->setReadOnly(true);
        numeroCuenta = new QLineEdit(groupBox_2);
        numeroCuenta->setObjectName(QString::fromUtf8("numeroCuenta"));
        numeroCuenta->setGeometry(QRect(70, 30, 81, 20));
        numeroCuenta->setMaxLength(5);
        numeroCuenta->setReadOnly(true);
        descripcion = new QLineEdit(groupBox_2);
        descripcion->setObjectName(QString::fromUtf8("descripcion"));
        descripcion->setGeometry(QRect(20, 130, 241, 20));
        line = new QFrame(tab_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 40, 841, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        botonEliminar = new QToolButton(tab_3);
        botonEliminar->setObjectName(QString::fromUtf8("botonEliminar"));
        botonEliminar->setGeometry(QRect(770, 10, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonEliminar->setIcon(icon);
        botonEliminar->setIconSize(QSize(20, 20));
        botonNuevo = new QToolButton(tab_3);
        botonNuevo->setObjectName(QString::fromUtf8("botonNuevo"));
        botonNuevo->setGeometry(QRect(650, 10, 31, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonNuevo->setIcon(icon1);
        botonNuevo->setIconSize(QSize(20, 20));
        botonModificar = new QToolButton(tab_3);
        botonModificar->setObjectName(QString::fromUtf8("botonModificar"));
        botonModificar->setGeometry(QRect(730, 10, 31, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/trabajador.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonModificar->setIcon(icon2);
        botonModificar->setIconSize(QSize(20, 20));
        botonGuardar = new QToolButton(tab_3);
        botonGuardar->setObjectName(QString::fromUtf8("botonGuardar"));
        botonGuardar->setGeometry(QRect(690, 10, 31, 31));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonGuardar->setIcon(icon3);
        botonGuardar->setIconSize(QSize(20, 20));
        ayudaActivoFijo = new QToolButton(tab_3);
        ayudaActivoFijo->setObjectName(QString::fromUtf8("ayudaActivoFijo"));
        ayudaActivoFijo->setGeometry(QRect(810, 10, 31, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        ayudaActivoFijo->setIcon(icon4);
        ayudaActivoFijo->setIconSize(QSize(32, 32));
        catalogoInventario = new QTreeWidget(tab_3);
        catalogoInventario->setObjectName(QString::fromUtf8("catalogoInventario"));
        catalogoInventario->setGeometry(QRect(10, 60, 256, 341));
        catalogoInventario->setAlternatingRowColors(true);
        groupBox_7 = new QGroupBox(tab_3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(580, 200, 141, 71));
        saldoDeudor = new QLineEdit(groupBox_7);
        saldoDeudor->setObjectName(QString::fromUtf8("saldoDeudor"));
        saldoDeudor->setGeometry(QRect(10, 30, 111, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(9);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        saldoDeudor->setFont(font);
        saldoDeudor->setLayoutDirection(Qt::RightToLeft);
        saldoDeudor->setReadOnly(true);
        groupBox_8 = new QGroupBox(tab_3);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(580, 110, 139, 79));
        groupBox_8->setStyleSheet(QString::fromUtf8(""));
        debe = new QLineEdit(groupBox_8);
        debe->setObjectName(QString::fromUtf8("debe"));
        debe->setGeometry(QRect(10, 30, 113, 22));
        debe->setLayoutDirection(Qt::RightToLeft);
        debe->setReadOnly(true);
        groupBox_9 = new QGroupBox(tab_3);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(720, 110, 139, 79));
        haber = new QLineEdit(groupBox_9);
        haber->setObjectName(QString::fromUtf8("haber"));
        haber->setGeometry(QRect(10, 30, 121, 25));
        haber->setLayoutDirection(Qt::RightToLeft);
        haber->setReadOnly(true);
        groupBox_10 = new QGroupBox(tab_3);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(720, 200, 141, 71));
        saldoAcreedor = new QLineEdit(groupBox_10);
        saldoAcreedor->setObjectName(QString::fromUtf8("saldoAcreedor"));
        saldoAcreedor->setGeometry(QRect(10, 30, 121, 25));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        saldoAcreedor->setFont(font1);
        saldoAcreedor->setLayoutDirection(Qt::RightToLeft);
        saldoAcreedor->setReadOnly(true);
        groupBox_11 = new QGroupBox(tab_3);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(580, 270, 279, 141));
        textEdit = new QTextEdit(groupBox_11);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 20, 261, 101));
        textEdit->setReadOnly(true);
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(580, 60, 279, 49));
        codigoCuenta = new QLineEdit(groupBox);
        codigoCuenta->setObjectName(QString::fromUtf8("codigoCuenta"));
        codigoCuenta->setGeometry(QRect(10, 20, 261, 22));
        codigoCuenta->setReadOnly(true);
        btmBuscar = new QToolButton(tab_3);
        btmBuscar->setObjectName(QString::fromUtf8("btmBuscar"));
        btmBuscar->setGeometry(QRect(370, 350, 121, 41));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Iconos/iconos/buscar.png"), QSize(), QIcon::Normal, QIcon::Off);
        btmBuscar->setIcon(icon5);
        btmBuscar->setIconSize(QSize(32, 32));
        btmSeleccionar = new QPushButton(tab_3);
        btmSeleccionar->setObjectName(QString::fromUtf8("btmSeleccionar"));
        btmSeleccionar->setGeometry(QRect(370, 240, 121, 41));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/iconos/button_ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        btmSeleccionar->setIcon(icon6);
        btmSeleccionar->setIconSize(QSize(32, 32));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(370, 290, 121, 51));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/iconos/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon7);
        pushButton->setIconSize(QSize(32, 32));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        line_2 = new QFrame(tab_4);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 40, 561, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 20, 261, 16));
        groupBox_4 = new QGroupBox(tab_4);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 60, 551, 81));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 20, 46, 21));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(360, 20, 46, 14));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(30, 50, 61, 16));
        claseBiblio = new QLineEdit(groupBox_4);
        claseBiblio->setObjectName(QString::fromUtf8("claseBiblio"));
        claseBiblio->setGeometry(QRect(410, 20, 51, 20));
        claseBiblio->setMaxLength(3);
        cuentaBiblio = new QLineEdit(groupBox_4);
        cuentaBiblio->setObjectName(QString::fromUtf8("cuentaBiblio"));
        cuentaBiblio->setGeometry(QRect(100, 20, 231, 20));
        cuentaBiblio->setReadOnly(true);
        especificoBiblio = new QLineEdit(groupBox_4);
        especificoBiblio->setObjectName(QString::fromUtf8("especificoBiblio"));
        especificoBiblio->setGeometry(QRect(100, 50, 231, 20));
        especificoBiblio->setReadOnly(true);
        groupBox_5 = new QGroupBox(tab_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 220, 551, 81));
        groupBox_6 = new QGroupBox(tab_4);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 310, 551, 91));
        botonEliminarBiblio = new QToolButton(tab_4);
        botonEliminarBiblio->setObjectName(QString::fromUtf8("botonEliminarBiblio"));
        botonEliminarBiblio->setGeometry(QRect(500, 10, 31, 31));
        botonEliminarBiblio->setIcon(icon);
        botonEliminarBiblio->setIconSize(QSize(20, 20));
        botonNuevoBiblio = new QToolButton(tab_4);
        botonNuevoBiblio->setObjectName(QString::fromUtf8("botonNuevoBiblio"));
        botonNuevoBiblio->setGeometry(QRect(450, 10, 31, 31));
        botonNuevoBiblio->setIcon(icon1);
        botonNuevoBiblio->setIconSize(QSize(20, 20));
        botonModificaBiblio = new QToolButton(tab_4);
        botonModificaBiblio->setObjectName(QString::fromUtf8("botonModificaBiblio"));
        botonModificaBiblio->setGeometry(QRect(400, 10, 31, 31));
        botonModificaBiblio->setIcon(icon2);
        botonModificaBiblio->setIconSize(QSize(20, 20));
        botonGuardarBiblio = new QToolButton(tab_4);
        botonGuardarBiblio->setObjectName(QString::fromUtf8("botonGuardarBiblio"));
        botonGuardarBiblio->setGeometry(QRect(350, 10, 31, 31));
        botonGuardarBiblio->setIcon(icon3);
        botonGuardarBiblio->setIconSize(QSize(20, 20));
        toolButton = new QToolButton(tab_4);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(550, 10, 31, 31));
        toolButton->setIcon(icon4);
        toolButton->setIconSize(QSize(32, 32));
        groupBox_3 = new QGroupBox(tab_4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 150, 551, 61));
        descripcionBiblio = new QLineEdit(groupBox_3);
        descripcionBiblio->setObjectName(QString::fromUtf8("descripcionBiblio"));
        descripcionBiblio->setGeometry(QRect(20, 20, 511, 20));
        tabWidget->addTab(tab_4, QString());
        label_6 = new QLabel(CatalogoActivoFijoGUI);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 20, 51, 20));
        label_8 = new QLabel(CatalogoActivoFijoGUI);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 50, 81, 16));
        nombreUnidad = new QLineEdit(CatalogoActivoFijoGUI);
        nombreUnidad->setObjectName(QString::fromUtf8("nombreUnidad"));
        nombreUnidad->setGeometry(QRect(100, 20, 81, 20));
        nombreUnidad->setReadOnly(true);
        nombreDpto = new QLineEdit(CatalogoActivoFijoGUI);
        nombreDpto->setObjectName(QString::fromUtf8("nombreDpto"));
        nombreDpto->setGeometry(QRect(100, 50, 261, 20));
        nombreDpto->setReadOnly(true);
        label_17 = new QLabel(CatalogoActivoFijoGUI);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(580, 20, 51, 51));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/iconos/kedit.png")));
        plainTextEdit = new QPlainTextEdit(CatalogoActivoFijoGUI);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(650, 20, 221, 61));
        plainTextEdit->setFrameShape(QFrame::WinPanel);
        plainTextEdit->setFrameShadow(QFrame::Raised);
        plainTextEdit->setReadOnly(true);
        plainTextEdit->setBackgroundVisible(false);
        QWidget::setTabOrder(numeroCuenta, nombreClase);
        QWidget::setTabOrder(nombreClase, botonGuardar);
        QWidget::setTabOrder(botonGuardar, botonModificar);
        QWidget::setTabOrder(botonModificar, botonNuevo);
        QWidget::setTabOrder(botonNuevo, botonEliminar);
        QWidget::setTabOrder(botonEliminar, ayudaActivoFijo);
        QWidget::setTabOrder(ayudaActivoFijo, tabWidget);
        QWidget::setTabOrder(tabWidget, claseBiblio);
        QWidget::setTabOrder(claseBiblio, descripcionBiblio);
        QWidget::setTabOrder(descripcionBiblio, botonGuardarBiblio);
        QWidget::setTabOrder(botonGuardarBiblio, botonModificaBiblio);
        QWidget::setTabOrder(botonModificaBiblio, botonNuevoBiblio);
        QWidget::setTabOrder(botonNuevoBiblio, botonEliminarBiblio);
        QWidget::setTabOrder(botonEliminarBiblio, toolButton);
        QWidget::setTabOrder(toolButton, especificoBiblio);
        QWidget::setTabOrder(especificoBiblio, cuentaBiblio);
        QWidget::setTabOrder(cuentaBiblio, nombreUnidad);
        QWidget::setTabOrder(nombreUnidad, nombreDpto);
        QWidget::setTabOrder(nombreDpto, plainTextEdit);
        QWidget::setTabOrder(plainTextEdit, cuentaAsignada);

        retranslateUi(CatalogoActivoFijoGUI);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CatalogoActivoFijoGUI);
    } // setupUi

    void retranslateUi(QWidget *CatalogoActivoFijoGUI)
    {
        CatalogoActivoFijoGUI->setWindowTitle(QApplication::translate("CatalogoActivoFijoGUI", "Catalogo de activo fijo", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CatalogoActivoFijoGUI", "Cuenta de inventario y clase", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CatalogoActivoFijoGUI", "Cuenta:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CatalogoActivoFijoGUI", "Clase:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botonEliminar->setToolTip(QApplication::translate("CatalogoActivoFijoGUI", "Eliminar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonEliminar->setText(QApplication::translate("CatalogoActivoFijoGUI", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botonNuevo->setToolTip(QApplication::translate("CatalogoActivoFijoGUI", "Nuevo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonNuevo->setText(QApplication::translate("CatalogoActivoFijoGUI", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botonModificar->setToolTip(QApplication::translate("CatalogoActivoFijoGUI", "Modificar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        botonModificar->setText(QApplication::translate("CatalogoActivoFijoGUI", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        botonGuardar->setToolTip(QApplication::translate("CatalogoActivoFijoGUI", "Guardar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        botonGuardar->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        botonGuardar->setText(QApplication::translate("CatalogoActivoFijoGUI", "...", 0, QApplication::UnicodeUTF8));
        ayudaActivoFijo->setText(QApplication::translate("CatalogoActivoFijoGUI", "...", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = catalogoInventario->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("CatalogoActivoFijoGUI", "Codigo", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("CatalogoActivoFijoGUI", "Catalogo", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("CatalogoActivoFijoGUI", "Saldo Deudor", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("CatalogoActivoFijoGUI", "Debe", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("CatalogoActivoFijoGUI", "Haber", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("CatalogoActivoFijoGUI", "Saldo Acreedor", 0, QApplication::UnicodeUTF8));
        groupBox_11->setTitle(QApplication::translate("CatalogoActivoFijoGUI", "Descripci\303\263n", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CatalogoActivoFijoGUI", "Nombre de la Cuenta", 0, QApplication::UnicodeUTF8));
        btmBuscar->setText(QApplication::translate("CatalogoActivoFijoGUI", " Buscar", 0, QApplication::UnicodeUTF8));
        btmSeleccionar->setText(QApplication::translate("CatalogoActivoFijoGUI", "Selecc", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("CatalogoActivoFijoGUI", "Cancelar", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("CatalogoActivoFijoGUI", "Activo Fijo", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("CatalogoActivoFijoGUI", "Ingreso de especificaciones de Material Bibliografico", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("CatalogoActivoFijoGUI", "Ingrese la clase: ", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("CatalogoActivoFijoGUI", "Cuenta:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("CatalogoActivoFijoGUI", "Clase:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("CatalogoActivoFijoGUI", "Especifico:", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("CatalogoActivoFijoGUI", "Datos Generales autor:", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("CatalogoActivoFijoGUI", "Datos Generales", 0, QApplication::UnicodeUTF8));
        botonEliminarBiblio->setText(QApplication::translate("CatalogoActivoFijoGUI", "...", 0, QApplication::UnicodeUTF8));
        botonNuevoBiblio->setText(QApplication::translate("CatalogoActivoFijoGUI", "...", 0, QApplication::UnicodeUTF8));
        botonModificaBiblio->setText(QApplication::translate("CatalogoActivoFijoGUI", "...", 0, QApplication::UnicodeUTF8));
        botonGuardarBiblio->setText(QApplication::translate("CatalogoActivoFijoGUI", "...", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("CatalogoActivoFijoGUI", "...", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CatalogoActivoFijoGUI", "Descripcion de la Clase:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("CatalogoActivoFijoGUI", "Material Bibliografico", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CatalogoActivoFijoGUI", "Unidad:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("CatalogoActivoFijoGUI", "Departamento:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QString());
        plainTextEdit->setPlainText(QApplication::translate("CatalogoActivoFijoGUI", "Cree, modifique o elimine especificaciones de los bienes inventariables.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatalogoActivoFijoGUI: public Ui_CatalogoActivoFijoGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATALOGOACTIVOFIJOGUI_H
