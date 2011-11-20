/********************************************************************************
** Form generated from reading ui file 'testdatawindow.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TESTDATAWINDOW_H
#define UI_TESTDATAWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NCRDTestDataWindowUI
{
public:
    QAction *actNew;
    QAction *actOpen;
    QAction *actSave;
    QAction *actSaveAs;
    QAction *actClose;
    QAction *actAddRow;
    QAction *actInsertRow;
    QAction *actRemoveRow;
    QAction *actAddColumn;
    QAction *actInsertColumn;
    QAction *actRemoveColumn;
    QAction *actLoadContent;
    QAction *actAddData;
    QAction *actRemoveData;
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *id;
    QLabel *label_2;
    QComboBox *comboType;
    QCheckBox *cbEnabled;
    QLabel *label_5;
    QComboBox *comboSeparator;
    QSpacerItem *spacerItem;
    QTableWidget *tableData;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuOperations;
    QStatusBar *statusbar;
    QToolBar *tbFile;
    QDockWidget *dwList;
    QWidget *dockWidgetContents;
    QVBoxLayout *vboxLayout1;
    QLabel *label_4;
    QListView *listID;
    QToolBar *tbOperation;

    void setupUi(QMainWindow *NCRDTestDataWindowUI)
    {
        if (NCRDTestDataWindowUI->objectName().isEmpty())
            NCRDTestDataWindowUI->setObjectName(QString::fromUtf8("NCRDTestDataWindowUI"));
        NCRDTestDataWindowUI->resize(719, 489);
        const QIcon icon = QIcon(QString::fromUtf8(":/images/testdata.png"));
        NCRDTestDataWindowUI->setWindowIcon(icon);
        actNew = new QAction(NCRDTestDataWindowUI);
        actNew->setObjectName(QString::fromUtf8("actNew"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/images/filenew.png"));
        actNew->setIcon(icon1);
        actOpen = new QAction(NCRDTestDataWindowUI);
        actOpen->setObjectName(QString::fromUtf8("actOpen"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/images/fileopen.png"));
        actOpen->setIcon(icon2);
        actSave = new QAction(NCRDTestDataWindowUI);
        actSave->setObjectName(QString::fromUtf8("actSave"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/images/disk.png"));
        actSave->setIcon(icon3);
        actSaveAs = new QAction(NCRDTestDataWindowUI);
        actSaveAs->setObjectName(QString::fromUtf8("actSaveAs"));
        actClose = new QAction(NCRDTestDataWindowUI);
        actClose->setObjectName(QString::fromUtf8("actClose"));
        actAddRow = new QAction(NCRDTestDataWindowUI);
        actAddRow->setObjectName(QString::fromUtf8("actAddRow"));
        const QIcon icon4 = QIcon(QString::fromUtf8(":/images/table_row_insert.png"));
        actAddRow->setIcon(icon4);
        actInsertRow = new QAction(NCRDTestDataWindowUI);
        actInsertRow->setObjectName(QString::fromUtf8("actInsertRow"));
        actRemoveRow = new QAction(NCRDTestDataWindowUI);
        actRemoveRow->setObjectName(QString::fromUtf8("actRemoveRow"));
        const QIcon icon5 = QIcon(QString::fromUtf8(":/images/table_row_delete.png"));
        actRemoveRow->setIcon(icon5);
        actAddColumn = new QAction(NCRDTestDataWindowUI);
        actAddColumn->setObjectName(QString::fromUtf8("actAddColumn"));
        const QIcon icon6 = QIcon(QString::fromUtf8(":/images/tab_add.png"));
        actAddColumn->setIcon(icon6);
        actInsertColumn = new QAction(NCRDTestDataWindowUI);
        actInsertColumn->setObjectName(QString::fromUtf8("actInsertColumn"));
        actRemoveColumn = new QAction(NCRDTestDataWindowUI);
        actRemoveColumn->setObjectName(QString::fromUtf8("actRemoveColumn"));
        const QIcon icon7 = QIcon(QString::fromUtf8(":/images/tab_delete.png"));
        actRemoveColumn->setIcon(icon7);
        actLoadContent = new QAction(NCRDTestDataWindowUI);
        actLoadContent->setObjectName(QString::fromUtf8("actLoadContent"));
        actAddData = new QAction(NCRDTestDataWindowUI);
        actAddData->setObjectName(QString::fromUtf8("actAddData"));
        const QIcon icon8 = QIcon(QString::fromUtf8(":/images/table_add.png"));
        actAddData->setIcon(icon8);
        actRemoveData = new QAction(NCRDTestDataWindowUI);
        actRemoveData->setObjectName(QString::fromUtf8("actRemoveData"));
        const QIcon icon9 = QIcon(QString::fromUtf8(":/images/table_delete.png"));
        actRemoveData->setIcon(icon9);
        centralwidget = new QWidget(NCRDTestDataWindowUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        vboxLayout = new QVBoxLayout(centralwidget);
        vboxLayout->setSpacing(3);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(6, 6, 6, 6);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(3);
        gridLayout->setVerticalSpacing(3);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        id = new QLineEdit(centralwidget);
        id->setObjectName(QString::fromUtf8("id"));

        gridLayout->addWidget(id, 0, 3, 1, 2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        comboType = new QComboBox(centralwidget);
        comboType->setObjectName(QString::fromUtf8("comboType"));

        gridLayout->addWidget(comboType, 1, 3, 1, 3);

        cbEnabled = new QCheckBox(centralwidget);
        cbEnabled->setObjectName(QString::fromUtf8("cbEnabled"));

        gridLayout->addWidget(cbEnabled, 2, 5, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 2, 1, 1);

        comboSeparator = new QComboBox(centralwidget);
        comboSeparator->setObjectName(QString::fromUtf8("comboSeparator"));
        comboSeparator->setEnabled(false);

        gridLayout->addWidget(comboSeparator, 2, 3, 1, 1);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 2, 4, 1, 1);


        vboxLayout->addLayout(gridLayout);

        tableData = new QTableWidget(centralwidget);
        tableData->setObjectName(QString::fromUtf8("tableData"));

        vboxLayout->addWidget(tableData);

        NCRDTestDataWindowUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NCRDTestDataWindowUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 719, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOperations = new QMenu(menubar);
        menuOperations->setObjectName(QString::fromUtf8("menuOperations"));
        NCRDTestDataWindowUI->setMenuBar(menubar);
        statusbar = new QStatusBar(NCRDTestDataWindowUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NCRDTestDataWindowUI->setStatusBar(statusbar);
        tbFile = new QToolBar(NCRDTestDataWindowUI);
        tbFile->setObjectName(QString::fromUtf8("tbFile"));
        tbFile->setIconSize(QSize(16, 16));
        NCRDTestDataWindowUI->addToolBar(Qt::TopToolBarArea, tbFile);
        dwList = new QDockWidget(NCRDTestDataWindowUI);
        dwList->setObjectName(QString::fromUtf8("dwList"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        vboxLayout1 = new QVBoxLayout(dockWidgetContents);
        vboxLayout1->setSpacing(3);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        vboxLayout1->setContentsMargins(6, 6, 6, 6);
        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        vboxLayout1->addWidget(label_4);

        listID = new QListView(dockWidgetContents);
        listID->setObjectName(QString::fromUtf8("listID"));

        vboxLayout1->addWidget(listID);

        dwList->setWidget(dockWidgetContents);
        NCRDTestDataWindowUI->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dwList);
        tbOperation = new QToolBar(NCRDTestDataWindowUI);
        tbOperation->setObjectName(QString::fromUtf8("tbOperation"));
        tbOperation->setIconSize(QSize(16, 16));
        NCRDTestDataWindowUI->addToolBar(Qt::TopToolBarArea, tbOperation);
        QWidget::setTabOrder(listID, id);
        QWidget::setTabOrder(id, comboType);
        QWidget::setTabOrder(comboType, comboSeparator);
        QWidget::setTabOrder(comboSeparator, cbEnabled);
        QWidget::setTabOrder(cbEnabled, tableData);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuOperations->menuAction());
        menuFile->addAction(actNew);
        menuFile->addAction(actOpen);
        menuFile->addAction(actSave);
        menuFile->addAction(actSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actClose);
        menuOperations->addAction(actAddData);
        menuOperations->addAction(actRemoveData);
        menuOperations->addSeparator();
        menuOperations->addAction(actAddRow);
        menuOperations->addAction(actInsertRow);
        menuOperations->addAction(actRemoveRow);
        menuOperations->addSeparator();
        menuOperations->addAction(actAddColumn);
        menuOperations->addAction(actInsertColumn);
        menuOperations->addAction(actRemoveColumn);
        menuOperations->addSeparator();
        menuOperations->addAction(actLoadContent);
        tbFile->addAction(actNew);
        tbFile->addAction(actOpen);
        tbFile->addAction(actSave);
        tbOperation->addAction(actAddData);
        tbOperation->addAction(actRemoveData);
        tbOperation->addSeparator();
        tbOperation->addAction(actAddRow);
        tbOperation->addAction(actRemoveRow);
        tbOperation->addAction(actAddColumn);
        tbOperation->addAction(actRemoveColumn);

        retranslateUi(NCRDTestDataWindowUI);

        QMetaObject::connectSlotsByName(NCRDTestDataWindowUI);
    } // setupUi

    void retranslateUi(QMainWindow *NCRDTestDataWindowUI)
    {
        NCRDTestDataWindowUI->setWindowTitle(QApplication::translate("NCRDTestDataWindowUI", "Test data editor", 0, QApplication::UnicodeUTF8));
        actNew->setText(QApplication::translate("NCRDTestDataWindowUI", "&New", 0, QApplication::UnicodeUTF8));
        actNew->setShortcut(QApplication::translate("NCRDTestDataWindowUI", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actOpen->setText(QApplication::translate("NCRDTestDataWindowUI", "&Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actOpen->setToolTip(QApplication::translate("NCRDTestDataWindowUI", "Open test data file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actOpen->setShortcut(QApplication::translate("NCRDTestDataWindowUI", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actSave->setText(QApplication::translate("NCRDTestDataWindowUI", "&Save", 0, QApplication::UnicodeUTF8));
        actSave->setShortcut(QApplication::translate("NCRDTestDataWindowUI", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actSaveAs->setText(QApplication::translate("NCRDTestDataWindowUI", "Save as...", 0, QApplication::UnicodeUTF8));
        actClose->setText(QApplication::translate("NCRDTestDataWindowUI", "Close", 0, QApplication::UnicodeUTF8));
        actAddRow->setText(QApplication::translate("NCRDTestDataWindowUI", "Add row", 0, QApplication::UnicodeUTF8));
        actAddRow->setShortcut(QApplication::translate("NCRDTestDataWindowUI", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        actInsertRow->setText(QApplication::translate("NCRDTestDataWindowUI", "Insert row", 0, QApplication::UnicodeUTF8));
        actInsertRow->setShortcut(QApplication::translate("NCRDTestDataWindowUI", "Ctrl+Shift+R", 0, QApplication::UnicodeUTF8));
        actRemoveRow->setText(QApplication::translate("NCRDTestDataWindowUI", "Remove row", 0, QApplication::UnicodeUTF8));
        actRemoveRow->setShortcut(QApplication::translate("NCRDTestDataWindowUI", "Ctrl+Del", 0, QApplication::UnicodeUTF8));
        actAddColumn->setText(QApplication::translate("NCRDTestDataWindowUI", "Add column", 0, QApplication::UnicodeUTF8));
        actAddColumn->setShortcut(QApplication::translate("NCRDTestDataWindowUI", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actInsertColumn->setText(QApplication::translate("NCRDTestDataWindowUI", "Insert column", 0, QApplication::UnicodeUTF8));
        actRemoveColumn->setText(QApplication::translate("NCRDTestDataWindowUI", "Remove column", 0, QApplication::UnicodeUTF8));
        actRemoveColumn->setShortcut(QApplication::translate("NCRDTestDataWindowUI", "Ctrl+Shift+Del", 0, QApplication::UnicodeUTF8));
        actLoadContent->setText(QApplication::translate("NCRDTestDataWindowUI", "Load content from file...", 0, QApplication::UnicodeUTF8));
        actAddData->setText(QApplication::translate("NCRDTestDataWindowUI", "Add new data table", 0, QApplication::UnicodeUTF8));
        actRemoveData->setText(QApplication::translate("NCRDTestDataWindowUI", "Remove data table", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NCRDTestDataWindowUI", "ID (name):", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NCRDTestDataWindowUI", "Datasource type:", 0, QApplication::UnicodeUTF8));
        comboType->clear();
        comboType->insertItems(0, QStringList()
         << QApplication::translate("NCRDTestDataWindowUI", "String list (QStringList)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDTestDataWindowUI", "Item model (QStandardItemModel)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDTestDataWindowUI", "String parameter (QString)", 0, QApplication::UnicodeUTF8)
        );
        cbEnabled->setText(QApplication::translate("NCRDTestDataWindowUI", "Enabled (add test data to report)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NCRDTestDataWindowUI", "Column separator:", 0, QApplication::UnicodeUTF8));
        comboSeparator->clear();
        comboSeparator->insertItems(0, QStringList()
         << QApplication::translate("NCRDTestDataWindowUI", "Tab", 0, QApplication::UnicodeUTF8)
        );
        menuFile->setTitle(QApplication::translate("NCRDTestDataWindowUI", "File", 0, QApplication::UnicodeUTF8));
        menuOperations->setTitle(QApplication::translate("NCRDTestDataWindowUI", "Operations", 0, QApplication::UnicodeUTF8));
        tbFile->setWindowTitle(QApplication::translate("NCRDTestDataWindowUI", "File toolbar", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NCRDTestDataWindowUI", "Test data list:", 0, QApplication::UnicodeUTF8));
        tbOperation->setWindowTitle(QApplication::translate("NCRDTestDataWindowUI", "Operations toolbar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NCRDTestDataWindowUI: public Ui_NCRDTestDataWindowUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDATAWINDOW_H
