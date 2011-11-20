/********************************************************************************
** Form generated from reading ui file 'fieldpropdialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FIELDPROPDIALOG_H
#define UI_FIELDPROPDIALOG_H

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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ncrdprintwhenpanel.h"
#include "qtcolorcombobox.h"

QT_BEGIN_NAMESPACE

class Ui_NCRDFieldPropDialogUI
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbBase;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboFST;
    QComboBox *comboDataType;
    QLabel *label_4;
    QLabel *label_13;
    QLineEdit *leDescription;
    QLineEdit *fieldExpr;
    QTabWidget *tabWidget;
    QWidget *tabGeneral;
    QVBoxLayout *vboxLayout1;
    QGridLayout *lGrid;
    QSpinBox *spinChars;
    QLabel *label_11;
    QLineEdit *argText;
    QSpacerItem *spcr;
    QCheckBox *cbWordWrap;
    QLabel *label_14;
    QCheckBox *cbAutoHeight;
    QLabel *label_3;
    QtColorComboBox *comboBackColor;
    QLabel *label_5;
    QComboBox *comboBGMode;
    QCheckBox *cbHideRepeated;
    QSpacerItem *spGeneral;
    QWidget *tabNum;
    QVBoxLayout *vboxLayout2;
    QGridLayout *gridNum;
    QCheckBox *cbFormating;
    QLabel *label_7;
    QSpinBox *spinDecimals;
    QCheckBox *cbLocalize;
    QLabel *label_8;
    QSpinBox *spinFWidth;
    QCheckBox *cbBlankIfZero;
    QLabel *label_9;
    QLineEdit *formatChar;
    QLabel *label_10;
    QLineEdit *fillChar;
    QSpacerItem *spNu;
    QSpacerItem *spNu2;
    QWidget *tabDate;
    QVBoxLayout *vboxLayout3;
    QGridLayout *gridDT;
    QLabel *label_12;
    QLineEdit *dateFormat;
    QSpacerItem *spDT;
    QWidget *tabOther;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayoutOther;
    QLabel *label_15;
    QLineEdit *callFunction;
    QLabel *label_16;
    QLineEdit *lookupClass;
    QSpacerItem *verticalSpacer;
    NCRDPrintWhenPanel *printWhenPanel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDFieldPropDialogUI)
    {
        if (NCRDFieldPropDialogUI->objectName().isEmpty())
            NCRDFieldPropDialogUI->setObjectName(QString::fromUtf8("NCRDFieldPropDialogUI"));
        NCRDFieldPropDialogUI->resize(496, 404);
        vboxLayout = new QVBoxLayout(NCRDFieldPropDialogUI);
        vboxLayout->setMargin(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        gbBase = new QGroupBox(NCRDFieldPropDialogUI);
        gbBase->setObjectName(QString::fromUtf8("gbBase"));
        gridLayout = new QGridLayout(gbBase);
        gridLayout->setSpacing(3);
        gridLayout->setMargin(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(gbBase);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gbBase);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboFST = new QComboBox(gbBase);
        comboFST->setObjectName(QString::fromUtf8("comboFST"));

        gridLayout->addWidget(comboFST, 0, 1, 1, 1);

        comboDataType = new QComboBox(gbBase);
        comboDataType->setObjectName(QString::fromUtf8("comboDataType"));

        gridLayout->addWidget(comboDataType, 2, 1, 1, 1);

        label_4 = new QLabel(gbBase);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_13 = new QLabel(gbBase);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 3, 0, 1, 1);

        leDescription = new QLineEdit(gbBase);
        leDescription->setObjectName(QString::fromUtf8("leDescription"));

        gridLayout->addWidget(leDescription, 3, 1, 1, 1);

        fieldExpr = new QLineEdit(gbBase);
        fieldExpr->setObjectName(QString::fromUtf8("fieldExpr"));

        gridLayout->addWidget(fieldExpr, 1, 1, 1, 1);


        vboxLayout->addWidget(gbBase);

        tabWidget = new QTabWidget(NCRDFieldPropDialogUI);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabGeneral = new QWidget();
        tabGeneral->setObjectName(QString::fromUtf8("tabGeneral"));
        vboxLayout1 = new QVBoxLayout(tabGeneral);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        lGrid = new QGridLayout();
        lGrid->setSpacing(3);
        lGrid->setObjectName(QString::fromUtf8("lGrid"));
        spinChars = new QSpinBox(tabGeneral);
        spinChars->setObjectName(QString::fromUtf8("spinChars"));
        spinChars->setMaximum(1999);

        lGrid->addWidget(spinChars, 0, 1, 1, 2);

        label_11 = new QLabel(tabGeneral);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        lGrid->addWidget(label_11, 1, 0, 1, 1);

        argText = new QLineEdit(tabGeneral);
        argText->setObjectName(QString::fromUtf8("argText"));

        lGrid->addWidget(argText, 1, 1, 1, 4);

        spcr = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lGrid->addItem(spcr, 0, 3, 1, 1);

        cbWordWrap = new QCheckBox(tabGeneral);
        cbWordWrap->setObjectName(QString::fromUtf8("cbWordWrap"));

        lGrid->addWidget(cbWordWrap, 2, 0, 1, 2);

        label_14 = new QLabel(tabGeneral);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        lGrid->addWidget(label_14, 0, 0, 1, 1);

        cbAutoHeight = new QCheckBox(tabGeneral);
        cbAutoHeight->setObjectName(QString::fromUtf8("cbAutoHeight"));

        lGrid->addWidget(cbAutoHeight, 3, 0, 1, 2);

        label_3 = new QLabel(tabGeneral);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        lGrid->addWidget(label_3, 3, 3, 1, 1);

        comboBackColor = new QtColorComboBox(tabGeneral);
        comboBackColor->setObjectName(QString::fromUtf8("comboBackColor"));

        lGrid->addWidget(comboBackColor, 3, 4, 1, 1);

        label_5 = new QLabel(tabGeneral);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        lGrid->addWidget(label_5, 2, 3, 1, 1);

        comboBGMode = new QComboBox(tabGeneral);
        comboBGMode->setObjectName(QString::fromUtf8("comboBGMode"));

        lGrid->addWidget(comboBGMode, 2, 4, 1, 1);

        cbHideRepeated = new QCheckBox(tabGeneral);
        cbHideRepeated->setObjectName(QString::fromUtf8("cbHideRepeated"));

        lGrid->addWidget(cbHideRepeated, 4, 0, 1, 2);


        vboxLayout1->addLayout(lGrid);

        spGeneral = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spGeneral);

        tabWidget->addTab(tabGeneral, QString());
        tabNum = new QWidget();
        tabNum->setObjectName(QString::fromUtf8("tabNum"));
        vboxLayout2 = new QVBoxLayout(tabNum);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        gridNum = new QGridLayout();
        gridNum->setSpacing(3);
        gridNum->setObjectName(QString::fromUtf8("gridNum"));
        cbFormating = new QCheckBox(tabNum);
        cbFormating->setObjectName(QString::fromUtf8("cbFormating"));

        gridNum->addWidget(cbFormating, 0, 0, 1, 1);

        label_7 = new QLabel(tabNum);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridNum->addWidget(label_7, 0, 2, 1, 1);

        spinDecimals = new QSpinBox(tabNum);
        spinDecimals->setObjectName(QString::fromUtf8("spinDecimals"));
        spinDecimals->setMaximumSize(QSize(70, 16777215));
        spinDecimals->setMaximum(12);

        gridNum->addWidget(spinDecimals, 0, 3, 1, 1);

        cbLocalize = new QCheckBox(tabNum);
        cbLocalize->setObjectName(QString::fromUtf8("cbLocalize"));

        gridNum->addWidget(cbLocalize, 1, 0, 1, 1);

        label_8 = new QLabel(tabNum);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridNum->addWidget(label_8, 1, 2, 1, 1);

        spinFWidth = new QSpinBox(tabNum);
        spinFWidth->setObjectName(QString::fromUtf8("spinFWidth"));
        spinFWidth->setMaximumSize(QSize(70, 16777215));

        gridNum->addWidget(spinFWidth, 1, 3, 1, 1);

        cbBlankIfZero = new QCheckBox(tabNum);
        cbBlankIfZero->setObjectName(QString::fromUtf8("cbBlankIfZero"));

        gridNum->addWidget(cbBlankIfZero, 2, 0, 1, 1);

        label_9 = new QLabel(tabNum);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridNum->addWidget(label_9, 2, 2, 1, 1);

        formatChar = new QLineEdit(tabNum);
        formatChar->setObjectName(QString::fromUtf8("formatChar"));
        formatChar->setMaximumSize(QSize(50, 16777215));
        formatChar->setMaxLength(1);

        gridNum->addWidget(formatChar, 2, 3, 1, 1);

        label_10 = new QLabel(tabNum);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridNum->addWidget(label_10, 3, 2, 1, 1);

        fillChar = new QLineEdit(tabNum);
        fillChar->setObjectName(QString::fromUtf8("fillChar"));
        fillChar->setMaximumSize(QSize(50, 16777215));
        fillChar->setMaxLength(1);

        gridNum->addWidget(fillChar, 3, 3, 1, 1);

        spNu = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridNum->addItem(spNu, 2, 1, 1, 1);


        vboxLayout2->addLayout(gridNum);

        spNu2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout2->addItem(spNu2);

        tabWidget->addTab(tabNum, QString());
        tabDate = new QWidget();
        tabDate->setObjectName(QString::fromUtf8("tabDate"));
        vboxLayout3 = new QVBoxLayout(tabDate);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        gridDT = new QGridLayout();
        gridDT->setObjectName(QString::fromUtf8("gridDT"));
        label_12 = new QLabel(tabDate);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridDT->addWidget(label_12, 0, 0, 1, 1);

        dateFormat = new QLineEdit(tabDate);
        dateFormat->setObjectName(QString::fromUtf8("dateFormat"));

        gridDT->addWidget(dateFormat, 0, 1, 1, 1);


        vboxLayout3->addLayout(gridDT);

        spDT = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout3->addItem(spDT);

        tabWidget->addTab(tabDate, QString());
        tabOther = new QWidget();
        tabOther->setObjectName(QString::fromUtf8("tabOther"));
        verticalLayout = new QVBoxLayout(tabOther);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayoutOther = new QGridLayout();
        gridLayoutOther->setSpacing(3);
        gridLayoutOther->setObjectName(QString::fromUtf8("gridLayoutOther"));
        label_15 = new QLabel(tabOther);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setEnabled(false);

        gridLayoutOther->addWidget(label_15, 0, 0, 1, 1);

        callFunction = new QLineEdit(tabOther);
        callFunction->setObjectName(QString::fromUtf8("callFunction"));
        callFunction->setEnabled(false);

        gridLayoutOther->addWidget(callFunction, 0, 1, 1, 1);

        label_16 = new QLabel(tabOther);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setEnabled(false);

        gridLayoutOther->addWidget(label_16, 1, 0, 1, 1);

        lookupClass = new QLineEdit(tabOther);
        lookupClass->setObjectName(QString::fromUtf8("lookupClass"));
        lookupClass->setEnabled(false);

        gridLayoutOther->addWidget(lookupClass, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayoutOther);

        verticalSpacer = new QSpacerItem(20, 95, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        tabWidget->addTab(tabOther, QString());

        vboxLayout->addWidget(tabWidget);

        printWhenPanel = new NCRDPrintWhenPanel(NCRDFieldPropDialogUI);
        printWhenPanel->setObjectName(QString::fromUtf8("printWhenPanel"));

        vboxLayout->addWidget(printWhenPanel);

        buttonBox = new QDialogButtonBox(NCRDFieldPropDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(comboFST, fieldExpr);
        QWidget::setTabOrder(fieldExpr, comboDataType);
        QWidget::setTabOrder(comboDataType, leDescription);
        QWidget::setTabOrder(leDescription, tabWidget);
        QWidget::setTabOrder(tabWidget, spinChars);
        QWidget::setTabOrder(spinChars, argText);
        QWidget::setTabOrder(argText, cbWordWrap);
        QWidget::setTabOrder(cbWordWrap, cbAutoHeight);
        QWidget::setTabOrder(cbAutoHeight, cbHideRepeated);
        QWidget::setTabOrder(cbHideRepeated, comboBGMode);
        QWidget::setTabOrder(comboBGMode, comboBackColor);
        QWidget::setTabOrder(comboBackColor, cbFormating);
        QWidget::setTabOrder(cbFormating, cbLocalize);
        QWidget::setTabOrder(cbLocalize, cbBlankIfZero);
        QWidget::setTabOrder(cbBlankIfZero, spinDecimals);
        QWidget::setTabOrder(spinDecimals, spinFWidth);
        QWidget::setTabOrder(spinFWidth, formatChar);
        QWidget::setTabOrder(formatChar, fillChar);
        QWidget::setTabOrder(fillChar, dateFormat);
        QWidget::setTabOrder(dateFormat, callFunction);
        QWidget::setTabOrder(callFunction, lookupClass);
        QWidget::setTabOrder(lookupClass, buttonBox);

        retranslateUi(NCRDFieldPropDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDFieldPropDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDFieldPropDialogUI, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(NCRDFieldPropDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDFieldPropDialogUI)
    {
        NCRDFieldPropDialogUI->setWindowTitle(QApplication::translate("NCRDFieldPropDialogUI", "Field properties", 0, QApplication::UnicodeUTF8));
        gbBase->setTitle(QApplication::translate("NCRDFieldPropDialogUI", "Field", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NCRDFieldPropDialogUI", "Field source type:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NCRDFieldPropDialogUI", "Field column expression:", 0, QApplication::UnicodeUTF8));
        comboFST->clear();
        comboFST->insertItems(0, QStringList()
         << QApplication::translate("NCRDFieldPropDialogUI", "Datasource", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDFieldPropDialogUI", "Parameter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDFieldPropDialogUI", "Variable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDFieldPropDialogUI", "System variable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDFieldPropDialogUI", "Expression", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDFieldPropDialogUI", "Template", 0, QApplication::UnicodeUTF8)
        );
        comboDataType->clear();
        comboDataType->insertItems(0, QStringList()
         << QApplication::translate("NCRDFieldPropDialogUI", "Text", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDFieldPropDialogUI", "Numeric", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDFieldPropDialogUI", "Date", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDFieldPropDialogUI", "DateTime", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDFieldPropDialogUI", "Boolean", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("NCRDFieldPropDialogUI", "Data type:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("NCRDFieldPropDialogUI", "Description / title", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("NCRDFieldPropDialogUI", "QString arg(%1) string:", 0, QApplication::UnicodeUTF8));
        cbWordWrap->setText(QApplication::translate("NCRDFieldPropDialogUI", "Word wrapping", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("NCRDFieldPropDialogUI", "Character length:", 0, QApplication::UnicodeUTF8));
        cbAutoHeight->setText(QApplication::translate("NCRDFieldPropDialogUI", "Automatic height", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NCRDFieldPropDialogUI", "Background color:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NCRDFieldPropDialogUI", "Background mode:", 0, QApplication::UnicodeUTF8));
        comboBGMode->clear();
        comboBGMode->insertItems(0, QStringList()
         << QApplication::translate("NCRDFieldPropDialogUI", "Transparent", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDFieldPropDialogUI", "Filled background", 0, QApplication::UnicodeUTF8)
        );
        cbHideRepeated->setText(QApplication::translate("NCRDFieldPropDialogUI", "Hide repeated values", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabGeneral), QApplication::translate("NCRDFieldPropDialogUI", "General", 0, QApplication::UnicodeUTF8));
        cbFormating->setText(QApplication::translate("NCRDFieldPropDialogUI", "Number formating", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("NCRDFieldPropDialogUI", "Decimal precision:", 0, QApplication::UnicodeUTF8));
        cbLocalize->setText(QApplication::translate("NCRDFieldPropDialogUI", "Use localized settings", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("NCRDFieldPropDialogUI", "Field width:", 0, QApplication::UnicodeUTF8));
        cbBlankIfZero->setText(QApplication::translate("NCRDFieldPropDialogUI", "Blank if value equals zero", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("NCRDFieldPropDialogUI", "Format character:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("NCRDFieldPropDialogUI", "Fill character:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabNum), QApplication::translate("NCRDFieldPropDialogUI", "Numeric", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("NCRDFieldPropDialogUI", "Date / DateTime format:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabDate), QApplication::translate("NCRDFieldPropDialogUI", "Date/Time", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("NCRDFieldPropDialogUI", "Call function:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("NCRDFieldPropDialogUI", "Lookup class name:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabOther), QApplication::translate("NCRDFieldPropDialogUI", "Other", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDFieldPropDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDFieldPropDialogUI: public Ui_NCRDFieldPropDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIELDPROPDIALOG_H
