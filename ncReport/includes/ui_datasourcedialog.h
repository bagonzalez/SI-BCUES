/********************************************************************************
** Form generated from reading ui file 'datasourcedialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DATASOURCEDIALOG_H
#define UI_DATASOURCEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ncrdsqltextedit.h"

QT_BEGIN_NAMESPACE

class Ui_NCRDDataSourceDialogUI
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *layForm;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout1;
    QListView *listDS;
    QHBoxLayout *layAddButtons;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QVBoxLayout *layRight;
    QGroupBox *gbDS;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QComboBox *comboDsType;
    QLabel *lblFilename;
    QLineEdit *filenameurl;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *dsID;
    QLabel *label_9;
    QComboBox *comboLocation;
    QLabel *label_18;
    QComboBox *comboRole;
    QCheckBox *cbEmpty;
    QStackedWidget *stackW;
    QWidget *pageSQL;
    QVBoxLayout *vboxLayout2;
    QTabWidget *tabWidget;
    QWidget *tabConn;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *gbID;
    QGridLayout *gridLayout1;
    QLabel *label_17;
    QLineEdit *connID;
    QSpacerItem *horizontalSpacer;
    QLabel *lblParentID;
    QLineEdit *parentDsID;
    QCheckBox *cbExternal;
    QGroupBox *gbConnection;
    QGridLayout *gridLayout_2;
    QLabel *label_16;
    QComboBox *cDriver;
    QLabel *label_8;
    QLineEdit *cPort;
    QLabel *label_3;
    QLineEdit *cHost;
    QLabel *label_5;
    QLineEdit *cDatabase;
    QLabel *label_6;
    QLineEdit *cUsername;
    QLabel *label_7;
    QLineEdit *cPassword;
    QPushButton *btnTestConn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QWidget *tabQuery;
    QVBoxLayout *verticalLayout;
    NCRDSqlTextEdit *queryEditor;
    QWidget *pageText;
    QVBoxLayout *vboxLayout3;
    QGroupBox *gbText;
    QVBoxLayout *vboxLayout4;
    QHBoxLayout *layTextOpt;
    QLabel *label_15;
    QComboBox *comboTxtColumnSep;
    QLabel *label_19;
    QLineEdit *delimCharTxt;
    QSpacerItem *spacerTo;
    QLabel *label_12;
    NCRDSqlTextEdit *staticText;
    QWidget *pageXML;
    QVBoxLayout *vboxLayout5;
    QGroupBox *gbXML;
    QVBoxLayout *vboxLayout6;
    QLabel *label_10;
    NCRDSqlTextEdit *staticXML;
    QWidget *pageList;
    QVBoxLayout *vboxLayout7;
    QGroupBox *gbStringList;
    QVBoxLayout *vboxLayout8;
    QGridLayout *laySLOpt;
    QLabel *label_11;
    QLineEdit *stringListID;
    QLabel *label_20;
    QComboBox *comboSlColumnSep;
    QLabel *label_21;
    QLineEdit *delimCharSl;
    QSpacerItem *spacerSlOpt;
    QSpacerItem *sp2;
    QWidget *pageModel;
    QVBoxLayout *vboxLayout9;
    QGroupBox *gbModel;
    QVBoxLayout *vboxLayout10;
    QHBoxLayout *layIMDS;
    QLabel *label_13;
    QLineEdit *modelID;
    QSpacerItem *spIMDS;
    QSpacerItem *spIMDS_2;
    QWidget *pageCustom;
    QVBoxLayout *vboxLayout11;
    QGroupBox *gbCustom;
    QVBoxLayout *vboxLayout12;
    QHBoxLayout *layCustom;
    QLabel *label_14;
    QLineEdit *customID;
    QSpacerItem *spacerCustom;
    QSpacerItem *spacerCustom2;
    QHBoxLayout *layBtn;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDDataSourceDialogUI)
    {
        if (NCRDDataSourceDialogUI->objectName().isEmpty())
            NCRDDataSourceDialogUI->setObjectName(QString::fromUtf8("NCRDDataSourceDialogUI"));
        NCRDDataSourceDialogUI->setWindowModality(Qt::ApplicationModal);
        NCRDDataSourceDialogUI->resize(803, 570);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Helvetica"));
        NCRDDataSourceDialogUI->setFont(font);
        vboxLayout = new QVBoxLayout(NCRDDataSourceDialogUI);
        vboxLayout->setSpacing(3);
        vboxLayout->setMargin(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        layForm = new QHBoxLayout();
        layForm->setSpacing(3);
        layForm->setObjectName(QString::fromUtf8("layForm"));
        groupBox = new QGroupBox(NCRDDataSourceDialogUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(200, 16777215));
        vboxLayout1 = new QVBoxLayout(groupBox);
        vboxLayout1->setSpacing(3);
        vboxLayout1->setMargin(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        listDS = new QListView(groupBox);
        listDS->setObjectName(QString::fromUtf8("listDS"));

        vboxLayout1->addWidget(listDS);

        layAddButtons = new QHBoxLayout();
        layAddButtons->setSpacing(3);
        layAddButtons->setObjectName(QString::fromUtf8("layAddButtons"));
        btnAdd = new QPushButton(groupBox);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setAutoDefault(false);

        layAddButtons->addWidget(btnAdd);

        btnRemove = new QPushButton(groupBox);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));
        btnRemove->setAutoDefault(false);

        layAddButtons->addWidget(btnRemove);


        vboxLayout1->addLayout(layAddButtons);


        layForm->addWidget(groupBox);

        layRight = new QVBoxLayout();
        layRight->setSpacing(6);
        layRight->setObjectName(QString::fromUtf8("layRight"));
        gbDS = new QGroupBox(NCRDDataSourceDialogUI);
        gbDS->setObjectName(QString::fromUtf8("gbDS"));
        gridLayout = new QGridLayout(gbDS);
        gridLayout->setSpacing(3);
        gridLayout->setMargin(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(3);
        label_4 = new QLabel(gbDS);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        comboDsType = new QComboBox(gbDS);
        comboDsType->setObjectName(QString::fromUtf8("comboDsType"));

        gridLayout->addWidget(comboDsType, 1, 1, 1, 1);

        lblFilename = new QLabel(gbDS);
        lblFilename->setObjectName(QString::fromUtf8("lblFilename"));

        gridLayout->addWidget(lblFilename, 5, 0, 1, 1);

        filenameurl = new QLineEdit(gbDS);
        filenameurl->setObjectName(QString::fromUtf8("filenameurl"));

        gridLayout->addWidget(filenameurl, 5, 1, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 2);

        label_2 = new QLabel(gbDS);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        dsID = new QLineEdit(gbDS);
        dsID->setObjectName(QString::fromUtf8("dsID"));

        gridLayout->addWidget(dsID, 3, 1, 1, 1);

        label_9 = new QLabel(gbDS);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 3, 2, 1, 1);

        comboLocation = new QComboBox(gbDS);
        comboLocation->setObjectName(QString::fromUtf8("comboLocation"));

        gridLayout->addWidget(comboLocation, 3, 3, 1, 1);

        label_18 = new QLabel(gbDS);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 2, 0, 1, 1);

        comboRole = new QComboBox(gbDS);
        comboRole->setObjectName(QString::fromUtf8("comboRole"));

        gridLayout->addWidget(comboRole, 2, 1, 1, 1);

        cbEmpty = new QCheckBox(gbDS);
        cbEmpty->setObjectName(QString::fromUtf8("cbEmpty"));

        gridLayout->addWidget(cbEmpty, 2, 2, 1, 2);


        layRight->addWidget(gbDS);

        stackW = new QStackedWidget(NCRDDataSourceDialogUI);
        stackW->setObjectName(QString::fromUtf8("stackW"));
        pageSQL = new QWidget();
        pageSQL->setObjectName(QString::fromUtf8("pageSQL"));
        vboxLayout2 = new QVBoxLayout(pageSQL);
        vboxLayout2->setSpacing(3);
        vboxLayout2->setMargin(6);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        tabWidget = new QTabWidget(pageSQL);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMovable(true);
        tabConn = new QWidget();
        tabConn->setObjectName(QString::fromUtf8("tabConn"));
        verticalLayout_2 = new QVBoxLayout(tabConn);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setMargin(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gbID = new QGroupBox(tabConn);
        gbID->setObjectName(QString::fromUtf8("gbID"));
        gridLayout1 = new QGridLayout(gbID);
        gridLayout1->setSpacing(3);
        gridLayout1->setMargin(6);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        gridLayout1->setHorizontalSpacing(6);
        gridLayout1->setVerticalSpacing(3);
        label_17 = new QLabel(gbID);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout1->addWidget(label_17, 0, 0, 1, 1);

        connID = new QLineEdit(gbID);
        connID->setObjectName(QString::fromUtf8("connID"));

        gridLayout1->addWidget(connID, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(horizontalSpacer, 0, 2, 1, 1);

        lblParentID = new QLabel(gbID);
        lblParentID->setObjectName(QString::fromUtf8("lblParentID"));

        gridLayout1->addWidget(lblParentID, 1, 0, 1, 1);

        parentDsID = new QLineEdit(gbID);
        parentDsID->setObjectName(QString::fromUtf8("parentDsID"));

        gridLayout1->addWidget(parentDsID, 1, 1, 1, 1);


        verticalLayout_2->addWidget(gbID);

        cbExternal = new QCheckBox(tabConn);
        cbExternal->setObjectName(QString::fromUtf8("cbExternal"));

        verticalLayout_2->addWidget(cbExternal);

        gbConnection = new QGroupBox(tabConn);
        gbConnection->setObjectName(QString::fromUtf8("gbConnection"));
        gbConnection->setEnabled(false);
        gridLayout_2 = new QGridLayout(gbConnection);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setMargin(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(6);
        gridLayout_2->setVerticalSpacing(3);
        label_16 = new QLabel(gbConnection);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 0, 0, 1, 1);

        cDriver = new QComboBox(gbConnection);
        cDriver->setObjectName(QString::fromUtf8("cDriver"));

        gridLayout_2->addWidget(cDriver, 0, 1, 1, 1);

        label_8 = new QLabel(gbConnection);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 0, 3, 1, 1);

        cPort = new QLineEdit(gbConnection);
        cPort->setObjectName(QString::fromUtf8("cPort"));
        cPort->setMaximumSize(QSize(70, 16777215));

        gridLayout_2->addWidget(cPort, 0, 4, 1, 1);

        label_3 = new QLabel(gbConnection);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        cHost = new QLineEdit(gbConnection);
        cHost->setObjectName(QString::fromUtf8("cHost"));

        gridLayout_2->addWidget(cHost, 1, 1, 1, 1);

        label_5 = new QLabel(gbConnection);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        cDatabase = new QLineEdit(gbConnection);
        cDatabase->setObjectName(QString::fromUtf8("cDatabase"));

        gridLayout_2->addWidget(cDatabase, 2, 1, 1, 4);

        label_6 = new QLabel(gbConnection);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        cUsername = new QLineEdit(gbConnection);
        cUsername->setObjectName(QString::fromUtf8("cUsername"));

        gridLayout_2->addWidget(cUsername, 3, 1, 1, 1);

        label_7 = new QLabel(gbConnection);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 4, 0, 1, 1);

        cPassword = new QLineEdit(gbConnection);
        cPassword->setObjectName(QString::fromUtf8("cPassword"));
        cPassword->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(cPassword, 4, 1, 1, 1);

        btnTestConn = new QPushButton(gbConnection);
        btnTestConn->setObjectName(QString::fromUtf8("btnTestConn"));

        gridLayout_2->addWidget(btnTestConn, 4, 3, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 2, 1, 1);


        verticalLayout_2->addWidget(gbConnection);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(tabConn, QString());
        tabQuery = new QWidget();
        tabQuery->setObjectName(QString::fromUtf8("tabQuery"));
        verticalLayout = new QVBoxLayout(tabQuery);
        verticalLayout->setSpacing(3);
        verticalLayout->setMargin(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        queryEditor = new NCRDSqlTextEdit(tabQuery);
        queryEditor->setObjectName(QString::fromUtf8("queryEditor"));
        queryEditor->setAcceptRichText(false);

        verticalLayout->addWidget(queryEditor);

        tabWidget->addTab(tabQuery, QString());

        vboxLayout2->addWidget(tabWidget);

        stackW->addWidget(pageSQL);
        pageText = new QWidget();
        pageText->setObjectName(QString::fromUtf8("pageText"));
        vboxLayout3 = new QVBoxLayout(pageText);
        vboxLayout3->setSpacing(3);
        vboxLayout3->setMargin(0);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        gbText = new QGroupBox(pageText);
        gbText->setObjectName(QString::fromUtf8("gbText"));
        vboxLayout4 = new QVBoxLayout(gbText);
        vboxLayout4->setSpacing(3);
        vboxLayout4->setMargin(6);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        layTextOpt = new QHBoxLayout();
        layTextOpt->setSpacing(3);
        layTextOpt->setObjectName(QString::fromUtf8("layTextOpt"));
        label_15 = new QLabel(gbText);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        layTextOpt->addWidget(label_15);

        comboTxtColumnSep = new QComboBox(gbText);
        comboTxtColumnSep->setObjectName(QString::fromUtf8("comboTxtColumnSep"));

        layTextOpt->addWidget(comboTxtColumnSep);

        label_19 = new QLabel(gbText);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        layTextOpt->addWidget(label_19);

        delimCharTxt = new QLineEdit(gbText);
        delimCharTxt->setObjectName(QString::fromUtf8("delimCharTxt"));
        delimCharTxt->setMaximumSize(QSize(30, 16777215));

        layTextOpt->addWidget(delimCharTxt);

        spacerTo = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layTextOpt->addItem(spacerTo);


        vboxLayout4->addLayout(layTextOpt);

        label_12 = new QLabel(gbText);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        vboxLayout4->addWidget(label_12);

        staticText = new NCRDSqlTextEdit(gbText);
        staticText->setObjectName(QString::fromUtf8("staticText"));

        vboxLayout4->addWidget(staticText);


        vboxLayout3->addWidget(gbText);

        stackW->addWidget(pageText);
        pageXML = new QWidget();
        pageXML->setObjectName(QString::fromUtf8("pageXML"));
        vboxLayout5 = new QVBoxLayout(pageXML);
        vboxLayout5->setSpacing(3);
        vboxLayout5->setMargin(0);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        gbXML = new QGroupBox(pageXML);
        gbXML->setObjectName(QString::fromUtf8("gbXML"));
        vboxLayout6 = new QVBoxLayout(gbXML);
        vboxLayout6->setSpacing(3);
        vboxLayout6->setMargin(6);
        vboxLayout6->setObjectName(QString::fromUtf8("vboxLayout6"));
        label_10 = new QLabel(gbXML);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        vboxLayout6->addWidget(label_10);

        staticXML = new NCRDSqlTextEdit(gbXML);
        staticXML->setObjectName(QString::fromUtf8("staticXML"));

        vboxLayout6->addWidget(staticXML);


        vboxLayout5->addWidget(gbXML);

        stackW->addWidget(pageXML);
        pageList = new QWidget();
        pageList->setObjectName(QString::fromUtf8("pageList"));
        vboxLayout7 = new QVBoxLayout(pageList);
        vboxLayout7->setSpacing(3);
        vboxLayout7->setMargin(0);
        vboxLayout7->setObjectName(QString::fromUtf8("vboxLayout7"));
        gbStringList = new QGroupBox(pageList);
        gbStringList->setObjectName(QString::fromUtf8("gbStringList"));
        vboxLayout8 = new QVBoxLayout(gbStringList);
        vboxLayout8->setSpacing(3);
        vboxLayout8->setMargin(6);
        vboxLayout8->setObjectName(QString::fromUtf8("vboxLayout8"));
        laySLOpt = new QGridLayout();
        laySLOpt->setSpacing(3);
        laySLOpt->setObjectName(QString::fromUtf8("laySLOpt"));
        label_11 = new QLabel(gbStringList);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        laySLOpt->addWidget(label_11, 0, 0, 1, 1);

        stringListID = new QLineEdit(gbStringList);
        stringListID->setObjectName(QString::fromUtf8("stringListID"));

        laySLOpt->addWidget(stringListID, 0, 1, 1, 3);

        label_20 = new QLabel(gbStringList);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        laySLOpt->addWidget(label_20, 1, 0, 1, 1);

        comboSlColumnSep = new QComboBox(gbStringList);
        comboSlColumnSep->setObjectName(QString::fromUtf8("comboSlColumnSep"));

        laySLOpt->addWidget(comboSlColumnSep, 1, 1, 1, 1);

        label_21 = new QLabel(gbStringList);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        laySLOpt->addWidget(label_21, 1, 2, 1, 1);

        delimCharSl = new QLineEdit(gbStringList);
        delimCharSl->setObjectName(QString::fromUtf8("delimCharSl"));
        delimCharSl->setMaximumSize(QSize(30, 16777215));

        laySLOpt->addWidget(delimCharSl, 1, 3, 1, 1);

        spacerSlOpt = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        laySLOpt->addItem(spacerSlOpt, 1, 4, 1, 1);


        vboxLayout8->addLayout(laySLOpt);

        sp2 = new QSpacerItem(20, 101, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout8->addItem(sp2);


        vboxLayout7->addWidget(gbStringList);

        stackW->addWidget(pageList);
        pageModel = new QWidget();
        pageModel->setObjectName(QString::fromUtf8("pageModel"));
        vboxLayout9 = new QVBoxLayout(pageModel);
        vboxLayout9->setSpacing(3);
        vboxLayout9->setMargin(0);
        vboxLayout9->setObjectName(QString::fromUtf8("vboxLayout9"));
        gbModel = new QGroupBox(pageModel);
        gbModel->setObjectName(QString::fromUtf8("gbModel"));
        vboxLayout10 = new QVBoxLayout(gbModel);
        vboxLayout10->setSpacing(3);
        vboxLayout10->setMargin(6);
        vboxLayout10->setObjectName(QString::fromUtf8("vboxLayout10"));
        layIMDS = new QHBoxLayout();
        layIMDS->setSpacing(3);
        layIMDS->setObjectName(QString::fromUtf8("layIMDS"));
        label_13 = new QLabel(gbModel);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        layIMDS->addWidget(label_13);

        modelID = new QLineEdit(gbModel);
        modelID->setObjectName(QString::fromUtf8("modelID"));

        layIMDS->addWidget(modelID);

        spIMDS = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layIMDS->addItem(spIMDS);


        vboxLayout10->addLayout(layIMDS);

        spIMDS_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout10->addItem(spIMDS_2);


        vboxLayout9->addWidget(gbModel);

        stackW->addWidget(pageModel);
        pageCustom = new QWidget();
        pageCustom->setObjectName(QString::fromUtf8("pageCustom"));
        vboxLayout11 = new QVBoxLayout(pageCustom);
        vboxLayout11->setSpacing(3);
        vboxLayout11->setMargin(0);
        vboxLayout11->setObjectName(QString::fromUtf8("vboxLayout11"));
        gbCustom = new QGroupBox(pageCustom);
        gbCustom->setObjectName(QString::fromUtf8("gbCustom"));
        vboxLayout12 = new QVBoxLayout(gbCustom);
        vboxLayout12->setSpacing(3);
        vboxLayout12->setMargin(6);
        vboxLayout12->setObjectName(QString::fromUtf8("vboxLayout12"));
        layCustom = new QHBoxLayout();
        layCustom->setSpacing(3);
        layCustom->setObjectName(QString::fromUtf8("layCustom"));
        label_14 = new QLabel(gbCustom);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        layCustom->addWidget(label_14);

        customID = new QLineEdit(gbCustom);
        customID->setObjectName(QString::fromUtf8("customID"));

        layCustom->addWidget(customID);

        spacerCustom = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layCustom->addItem(spacerCustom);


        vboxLayout12->addLayout(layCustom);

        spacerCustom2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout12->addItem(spacerCustom2);


        vboxLayout11->addWidget(gbCustom);

        stackW->addWidget(pageCustom);

        layRight->addWidget(stackW);


        layForm->addLayout(layRight);


        vboxLayout->addLayout(layForm);

        layBtn = new QHBoxLayout();
        layBtn->setSpacing(3);
        layBtn->setObjectName(QString::fromUtf8("layBtn"));
        buttonBox = new QDialogButtonBox(NCRDDataSourceDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        layBtn->addWidget(buttonBox);


        vboxLayout->addLayout(layBtn);

        QWidget::setTabOrder(listDS, btnAdd);
        QWidget::setTabOrder(btnAdd, btnRemove);
        QWidget::setTabOrder(btnRemove, comboDsType);
        QWidget::setTabOrder(comboDsType, comboRole);
        QWidget::setTabOrder(comboRole, cbEmpty);
        QWidget::setTabOrder(cbEmpty, dsID);
        QWidget::setTabOrder(dsID, comboLocation);
        QWidget::setTabOrder(comboLocation, filenameurl);
        QWidget::setTabOrder(filenameurl, tabWidget);
        QWidget::setTabOrder(tabWidget, connID);
        QWidget::setTabOrder(connID, parentDsID);
        QWidget::setTabOrder(parentDsID, cbExternal);
        QWidget::setTabOrder(cbExternal, cDriver);
        QWidget::setTabOrder(cDriver, cPort);
        QWidget::setTabOrder(cPort, cHost);
        QWidget::setTabOrder(cHost, cDatabase);
        QWidget::setTabOrder(cDatabase, cUsername);
        QWidget::setTabOrder(cUsername, cPassword);
        QWidget::setTabOrder(cPassword, btnTestConn);
        QWidget::setTabOrder(btnTestConn, buttonBox);
        QWidget::setTabOrder(buttonBox, staticText);
        QWidget::setTabOrder(staticText, comboTxtColumnSep);
        QWidget::setTabOrder(comboTxtColumnSep, delimCharSl);
        QWidget::setTabOrder(delimCharSl, delimCharTxt);
        QWidget::setTabOrder(delimCharTxt, comboSlColumnSep);
        QWidget::setTabOrder(comboSlColumnSep, staticXML);
        QWidget::setTabOrder(staticXML, modelID);
        QWidget::setTabOrder(modelID, stringListID);
        QWidget::setTabOrder(stringListID, queryEditor);
        QWidget::setTabOrder(queryEditor, customID);

        retranslateUi(NCRDDataSourceDialogUI);
        QObject::connect(comboDsType, SIGNAL(activated(int)), stackW, SLOT(setCurrentIndex(int)));
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDDataSourceDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDDataSourceDialogUI, SLOT(reject()));

        stackW->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(NCRDDataSourceDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDDataSourceDialogUI)
    {
        NCRDDataSourceDialogUI->setWindowTitle(QApplication::translate("NCRDDataSourceDialogUI", "Datasources", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NCRDDataSourceDialogUI", "Datasources", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("NCRDDataSourceDialogUI", "Add", 0, QApplication::UnicodeUTF8));
        btnRemove->setText(QApplication::translate("NCRDDataSourceDialogUI", "Remove", 0, QApplication::UnicodeUTF8));
        gbDS->setTitle(QApplication::translate("NCRDDataSourceDialogUI", "Datasource properties", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NCRDDataSourceDialogUI", "Datasource type", 0, QApplication::UnicodeUTF8));
        comboDsType->clear();
        comboDsType->insertItems(0, QStringList()
         << QApplication::translate("NCRDDataSourceDialogUI", "SQL query", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Text", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "XML", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "String list", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Item model", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Custom", 0, QApplication::UnicodeUTF8)
        );
        lblFilename->setText(QApplication::translate("NCRDDataSourceDialogUI", "File name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NCRDDataSourceDialogUI", "Datasource ID", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("NCRDDataSourceDialogUI", "Location type", 0, QApplication::UnicodeUTF8));
        comboLocation->clear();
        comboLocation->insertItems(0, QStringList()
         << QApplication::translate("NCRDDataSourceDialogUI", "Static", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "File", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Http", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Ftp", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Parameter", 0, QApplication::UnicodeUTF8)
        );
        label_18->setText(QApplication::translate("NCRDDataSourceDialogUI", "Opening/running role", 0, QApplication::UnicodeUTF8));
        comboRole->clear();
        comboRole->insertItems(0, QStringList()
         << QApplication::translate("NCRDDataSourceDialogUI", "Begining of the report", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Child datasource (subquery)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "When group change", 0, QApplication::UnicodeUTF8)
        );
        cbEmpty->setText(QApplication::translate("NCRDDataSourceDialogUI", "Empty datasource warning", 0, QApplication::UnicodeUTF8));
        gbID->setTitle(QApplication::translate("NCRDDataSourceDialogUI", "Identification", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("NCRDDataSourceDialogUI", "Connection ID", 0, QApplication::UnicodeUTF8));
        lblParentID->setText(QApplication::translate("NCRDDataSourceDialogUI", "Parent datasource ID", 0, QApplication::UnicodeUTF8));
        cbExternal->setText(QApplication::translate("NCRDDataSourceDialogUI", "Use private (external) database connection", 0, QApplication::UnicodeUTF8));
        gbConnection->setTitle(QApplication::translate("NCRDDataSourceDialogUI", "Private connection parameters", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("NCRDDataSourceDialogUI", "Driver", 0, QApplication::UnicodeUTF8));
        cDriver->clear();
        cDriver->insertItems(0, QStringList()
         << QApplication::translate("NCRDDataSourceDialogUI", "QPSQL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "QMYSQL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "QOCI", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "QODBC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "QDB2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "QTDS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "QSQLITE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "QIBASE", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("NCRDDataSourceDialogUI", "Port", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NCRDDataSourceDialogUI", "Host", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NCRDDataSourceDialogUI", "Database", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NCRDDataSourceDialogUI", "Username", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("NCRDDataSourceDialogUI", "Password", 0, QApplication::UnicodeUTF8));
        btnTestConn->setText(QApplication::translate("NCRDDataSourceDialogUI", "Test", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabConn), QApplication::translate("NCRDDataSourceDialogUI", "SQL Connection", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabQuery), QApplication::translate("NCRDDataSourceDialogUI", "SQL Query", 0, QApplication::UnicodeUTF8));
        gbText->setTitle(QApplication::translate("NCRDDataSourceDialogUI", "Text datasource", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("NCRDDataSourceDialogUI", "Column delimiter:", 0, QApplication::UnicodeUTF8));
        comboTxtColumnSep->clear();
        comboTxtColumnSep->insertItems(0, QStringList()
         << QApplication::translate("NCRDDataSourceDialogUI", "Tab", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Comma", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Semicolon", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Space", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Vertical bar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Custom", 0, QApplication::UnicodeUTF8)
        );
        label_19->setText(QApplication::translate("NCRDDataSourceDialogUI", "Custom delimiter character:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("NCRDDataSourceDialogUI", "Static text:", 0, QApplication::UnicodeUTF8));
        gbXML->setTitle(QApplication::translate("NCRDDataSourceDialogUI", "XML datasource", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("NCRDDataSourceDialogUI", "Static XML string", 0, QApplication::UnicodeUTF8));
        gbStringList->setTitle(QApplication::translate("NCRDDataSourceDialogUI", "QStringList datasource", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("NCRDDataSourceDialogUI", "String list ID:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("NCRDDataSourceDialogUI", "Column delimiter:", 0, QApplication::UnicodeUTF8));
        comboSlColumnSep->clear();
        comboSlColumnSep->insertItems(0, QStringList()
         << QApplication::translate("NCRDDataSourceDialogUI", "Tab", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Comma", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Semicolon", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Space", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Vertical bar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDDataSourceDialogUI", "Custom", 0, QApplication::UnicodeUTF8)
        );
        label_21->setText(QApplication::translate("NCRDDataSourceDialogUI", "Custom delimiter character:", 0, QApplication::UnicodeUTF8));
        gbModel->setTitle(QApplication::translate("NCRDDataSourceDialogUI", "Item model datasource", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("NCRDDataSourceDialogUI", "Item model ID:", 0, QApplication::UnicodeUTF8));
        gbCustom->setTitle(QApplication::translate("NCRDDataSourceDialogUI", "Custom datasource", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("NCRDDataSourceDialogUI", "Custom datasource ID:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDDataSourceDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDDataSourceDialogUI: public Ui_NCRDDataSourceDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASOURCEDIALOG_H
