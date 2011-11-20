/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 4. Jul 22:48:01 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Nuevo;
    QAction *action_Eliminar;
    QAction *action_Salir;
    QAction *action_Consultar;
    QAction *action_Modificar;
    QAction *action_Gestion_de_Usuarios;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QSplitter *splitter_10;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QSplitter *splitter_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QSplitter *splitter;
    QLineEdit *loginLine;
    QLineEdit *passLine;
    QLineEdit *passCLine;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_3;
    QSplitter *splitter_6;
    QSplitter *splitter_4;
    QLabel *label;
    QLineEdit *nameLine;
    QSplitter *splitter_5;
    QLabel *label_2;
    QLineEdit *lasNLine;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_2;
    QSplitter *splitter_8;
    QLabel *label_5;
    QLabel *label_6;
    QSplitter *splitter_7;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *tab3;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QMenu *menu_Archivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(459, 301);
        action_Nuevo = new QAction(MainWindow);
        action_Nuevo->setObjectName(QString::fromUtf8("action_Nuevo"));
        action_Eliminar = new QAction(MainWindow);
        action_Eliminar->setObjectName(QString::fromUtf8("action_Eliminar"));
        action_Salir = new QAction(MainWindow);
        action_Salir->setObjectName(QString::fromUtf8("action_Salir"));
        action_Consultar = new QAction(MainWindow);
        action_Consultar->setObjectName(QString::fromUtf8("action_Consultar"));
        action_Modificar = new QAction(MainWindow);
        action_Modificar->setObjectName(QString::fromUtf8("action_Modificar"));
        action_Gestion_de_Usuarios = new QAction(MainWindow);
        action_Gestion_de_Usuarios->setObjectName(QString::fromUtf8("action_Gestion_de_Usuarios"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter_10 = new QSplitter(tab);
        splitter_10->setObjectName(QString::fromUtf8("splitter_10"));
        splitter_10->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter_10);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        splitter_2 = new QSplitter(groupBox);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        label_3 = new QLabel(splitter_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        splitter_2->addWidget(label_3);
        label_4 = new QLabel(splitter_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        splitter_2->addWidget(label_4);
        label_7 = new QLabel(splitter_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        splitter_2->addWidget(label_7);

        formLayout->setWidget(0, QFormLayout::LabelRole, splitter_2);

        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        loginLine = new QLineEdit(splitter);
        loginLine->setObjectName(QString::fromUtf8("loginLine"));
        loginLine->setMaxLength(15);
        splitter->addWidget(loginLine);
        passLine = new QLineEdit(splitter);
        passLine->setObjectName(QString::fromUtf8("passLine"));
        passLine->setMaxLength(60);
        passLine->setEchoMode(QLineEdit::Password);
        splitter->addWidget(passLine);
        passCLine = new QLineEdit(splitter);
        passCLine->setObjectName(QString::fromUtf8("passCLine"));
        passCLine->setMaxLength(60);
        passCLine->setEchoMode(QLineEdit::Password);
        splitter->addWidget(passCLine);

        formLayout->setWidget(0, QFormLayout::FieldRole, splitter);

        splitter_10->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter_10);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout_3 = new QFormLayout(groupBox_2);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        splitter_6 = new QSplitter(groupBox_2);
        splitter_6->setObjectName(QString::fromUtf8("splitter_6"));
        splitter_6->setOrientation(Qt::Vertical);
        splitter_4 = new QSplitter(splitter_6);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter_4);
        label->setObjectName(QString::fromUtf8("label"));
        splitter_4->addWidget(label);
        nameLine = new QLineEdit(splitter_4);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));
        nameLine->setMaxLength(30);
        splitter_4->addWidget(nameLine);
        splitter_6->addWidget(splitter_4);
        splitter_5 = new QSplitter(splitter_6);
        splitter_5->setObjectName(QString::fromUtf8("splitter_5"));
        splitter_5->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        splitter_5->addWidget(label_2);
        lasNLine = new QLineEdit(splitter_5);
        lasNLine->setObjectName(QString::fromUtf8("lasNLine"));
        lasNLine->setMaxLength(30);
        splitter_5->addWidget(lasNLine);
        splitter_6->addWidget(splitter_5);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, splitter_6);

        splitter_10->addWidget(groupBox_2);

        gridLayout->addWidget(splitter_10, 0, 0, 1, 2);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        formLayout_2 = new QFormLayout(groupBox_3);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        splitter_8 = new QSplitter(groupBox_3);
        splitter_8->setObjectName(QString::fromUtf8("splitter_8"));
        splitter_8->setOrientation(Qt::Vertical);
        label_5 = new QLabel(splitter_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        splitter_8->addWidget(label_5);
        label_6 = new QLabel(splitter_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        splitter_8->addWidget(label_6);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, splitter_8);

        splitter_7 = new QSplitter(groupBox_3);
        splitter_7->setObjectName(QString::fromUtf8("splitter_7"));
        splitter_7->setOrientation(Qt::Vertical);
        comboBox = new QComboBox(splitter_7);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        splitter_7->addWidget(comboBox);
        comboBox_2 = new QComboBox(splitter_7);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        splitter_7->addWidget(comboBox_2);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, splitter_7);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);


        gridLayout->addWidget(groupBox_4, 1, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        verticalLayout_2 = new QVBoxLayout(tab3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget_2 = new QTableWidget(tab3);
        if (tableWidget_2->columnCount() < 5)
            tableWidget_2->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));

        verticalLayout_2->addWidget(tableWidget_2);

        pushButton_3 = new QPushButton(tab3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(tab3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_2->addWidget(pushButton_4);

        tabWidget->addTab(tab3, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 459, 20));
        menu_Archivo = new QMenu(menuBar);
        menu_Archivo->setObjectName(QString::fromUtf8("menu_Archivo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label_3->setBuddy(loginLine);
        label_4->setBuddy(passLine);
        label->setBuddy(nameLine);
        label_2->setBuddy(lasNLine);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(loginLine, nameLine);
        QWidget::setTabOrder(nameLine, lasNLine);
        QWidget::setTabOrder(lasNLine, passLine);
        QWidget::setTabOrder(passLine, passCLine);
        QWidget::setTabOrder(passCLine, comboBox_2);
        QWidget::setTabOrder(comboBox_2, pushButton);
        QWidget::setTabOrder(pushButton, tabWidget);
        QWidget::setTabOrder(tabWidget, comboBox);
        QWidget::setTabOrder(comboBox, pushButton_2);

        menuBar->addAction(menu_Archivo->menuAction());
        menu_Archivo->addAction(action_Nuevo);
        menu_Archivo->addAction(action_Eliminar);
        menu_Archivo->addSeparator();
        menu_Archivo->addAction(action_Salir);

        retranslateUi(MainWindow);
        QObject::connect(action_Salir, SIGNAL(activated()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion de Usuarios", 0, QApplication::UnicodeUTF8));
        action_Nuevo->setText(QApplication::translate("MainWindow", "&Nuevo", 0, QApplication::UnicodeUTF8));
        action_Eliminar->setText(QApplication::translate("MainWindow", "&Eliminar", 0, QApplication::UnicodeUTF8));
        action_Salir->setText(QApplication::translate("MainWindow", "&Salir", 0, QApplication::UnicodeUTF8));
        action_Consultar->setText(QApplication::translate("MainWindow", "&Consultar", 0, QApplication::UnicodeUTF8));
        action_Modificar->setText(QApplication::translate("MainWindow", "&Modificar", 0, QApplication::UnicodeUTF8));
        action_Gestion_de_Usuarios->setText(QApplication::translate("MainWindow", "&Gestion de Usuarios", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Sesion", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Login:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Contrasena:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Confirmar:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Informacion Usuario", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Nombre:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Apellido:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Descripcion de Puesto", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Unidad:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Rol:", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Opciones a Realizar", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Aceptar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Cancelar", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Agregar", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "login", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Nombre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Apellidos", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Unidad", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Rol", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Consultar", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "Eliminar", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QApplication::translate("MainWindow", "Eliminar", 0, QApplication::UnicodeUTF8));
        menu_Archivo->setTitle(QApplication::translate("MainWindow", "&Usuarios", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
