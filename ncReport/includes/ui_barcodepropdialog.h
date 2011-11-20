/********************************************************************************
** Form generated from reading ui file 'barcodepropdialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_BARCODEPROPDIALOG_H
#define UI_BARCODEPROPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ncrdprintwhenpanel.h"
#include "qtcolorcombobox.h"

QT_BEGIN_NAMESPACE

class Ui_NCRDBarcodePropDialogUI
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbImage;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboResource;
    QSpacerItem *spcr;
    QLabel *label_2;
    QLineEdit *staticCode;
    QComboBox *comboBarcodeType;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *dataColumn;
    QTabWidget *tab;
    QWidget *tabApp;
    QVBoxLayout *verticalLayout;
    QGridLayout *layAppearance;
    QLabel *label_6;
    QSpinBox *heightb;
    QLabel *lblScale;
    QDoubleSpinBox *spnScale;
    QLabel *label_9;
    QComboBox *btype;
    QLabel *label_8;
    QSpinBox *bwidth;
    QLabel *lblWhitespace;
    QSpinBox *spnWhitespace;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QLabel *label_7;
    QtColorComboBox *comboForeColor;
    QtColorComboBox *comboBackColor;
    QSpacerItem *verticalSpacer;
    QWidget *tabComposite;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chkComposite;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblCompType;
    QComboBox *cmbCompType;
    QLabel *lblComposite;
    QTextEdit *txtComposite;
    NCRDPrintWhenPanel *printWhenPanel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDBarcodePropDialogUI)
    {
        if (NCRDBarcodePropDialogUI->objectName().isEmpty())
            NCRDBarcodePropDialogUI->setObjectName(QString::fromUtf8("NCRDBarcodePropDialogUI"));
        NCRDBarcodePropDialogUI->resize(496, 394);
        vboxLayout = new QVBoxLayout(NCRDBarcodePropDialogUI);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        gbImage = new QGroupBox(NCRDBarcodePropDialogUI);
        gbImage->setObjectName(QString::fromUtf8("gbImage"));
        gridLayout = new QGridLayout(gbImage);
        gridLayout->setSpacing(3);
        gridLayout->setMargin(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(gbImage);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboResource = new QComboBox(gbImage);
        comboResource->setObjectName(QString::fromUtf8("comboResource"));

        gridLayout->addWidget(comboResource, 0, 1, 1, 1);

        spcr = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spcr, 0, 2, 1, 3);

        label_2 = new QLabel(gbImage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        staticCode = new QLineEdit(gbImage);
        staticCode->setObjectName(QString::fromUtf8("staticCode"));

        gridLayout->addWidget(staticCode, 3, 1, 1, 4);

        comboBarcodeType = new QComboBox(gbImage);
        comboBarcodeType->setObjectName(QString::fromUtf8("comboBarcodeType"));

        gridLayout->addWidget(comboBarcodeType, 1, 1, 1, 4);

        label_4 = new QLabel(gbImage);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(gbImage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        dataColumn = new QLineEdit(gbImage);
        dataColumn->setObjectName(QString::fromUtf8("dataColumn"));

        gridLayout->addWidget(dataColumn, 2, 1, 1, 4);


        vboxLayout->addWidget(gbImage);

        tab = new QTabWidget(NCRDBarcodePropDialogUI);
        tab->setObjectName(QString::fromUtf8("tab"));
        tabApp = new QWidget();
        tabApp->setObjectName(QString::fromUtf8("tabApp"));
        verticalLayout = new QVBoxLayout(tabApp);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        layAppearance = new QGridLayout();
        layAppearance->setSpacing(3);
        layAppearance->setObjectName(QString::fromUtf8("layAppearance"));
        label_6 = new QLabel(tabApp);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        layAppearance->addWidget(label_6, 0, 0, 1, 1);

        heightb = new QSpinBox(tabApp);
        heightb->setObjectName(QString::fromUtf8("heightb"));
        heightb->setMaximum(300);
        heightb->setValue(50);

        layAppearance->addWidget(heightb, 0, 1, 1, 1);

        lblScale = new QLabel(tabApp);
        lblScale->setObjectName(QString::fromUtf8("lblScale"));

        layAppearance->addWidget(lblScale, 3, 0, 1, 1);

        spnScale = new QDoubleSpinBox(tabApp);
        spnScale->setObjectName(QString::fromUtf8("spnScale"));
        spnScale->setDecimals(2);
        spnScale->setMinimum(0.5);
        spnScale->setMaximum(99.5);
        spnScale->setSingleStep(0.5);
        spnScale->setValue(1);

        layAppearance->addWidget(spnScale, 3, 1, 1, 1);

        label_9 = new QLabel(tabApp);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        layAppearance->addWidget(label_9, 0, 3, 1, 1);

        btype = new QComboBox(tabApp);
        btype->setObjectName(QString::fromUtf8("btype"));

        layAppearance->addWidget(btype, 0, 4, 1, 1);

        label_8 = new QLabel(tabApp);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        layAppearance->addWidget(label_8, 1, 3, 1, 1);

        bwidth = new QSpinBox(tabApp);
        bwidth->setObjectName(QString::fromUtf8("bwidth"));
        bwidth->setMinimum(0);
        bwidth->setMaximum(16);
        bwidth->setValue(0);

        layAppearance->addWidget(bwidth, 1, 4, 1, 1);

        lblWhitespace = new QLabel(tabApp);
        lblWhitespace->setObjectName(QString::fromUtf8("lblWhitespace"));

        layAppearance->addWidget(lblWhitespace, 1, 0, 1, 1);

        spnWhitespace = new QSpinBox(tabApp);
        spnWhitespace->setObjectName(QString::fromUtf8("spnWhitespace"));

        layAppearance->addWidget(spnWhitespace, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        layAppearance->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_5 = new QLabel(tabApp);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        layAppearance->addWidget(label_5, 3, 3, 1, 1);

        label_7 = new QLabel(tabApp);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        layAppearance->addWidget(label_7, 4, 3, 1, 1);

        comboForeColor = new QtColorComboBox(tabApp);
        comboForeColor->setObjectName(QString::fromUtf8("comboForeColor"));

        layAppearance->addWidget(comboForeColor, 3, 4, 1, 1);

        comboBackColor = new QtColorComboBox(tabApp);
        comboBackColor->setObjectName(QString::fromUtf8("comboBackColor"));

        layAppearance->addWidget(comboBackColor, 4, 4, 1, 1);


        verticalLayout->addLayout(layAppearance);

        verticalSpacer = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        tab->addTab(tabApp, QString());
        tabComposite = new QWidget();
        tabComposite->setObjectName(QString::fromUtf8("tabComposite"));
        verticalLayout_2 = new QVBoxLayout(tabComposite);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setMargin(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chkComposite = new QCheckBox(tabComposite);
        chkComposite->setObjectName(QString::fromUtf8("chkComposite"));

        horizontalLayout->addWidget(chkComposite);

        horizontalSpacer_2 = new QSpacerItem(68, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lblCompType = new QLabel(tabComposite);
        lblCompType->setObjectName(QString::fromUtf8("lblCompType"));

        horizontalLayout->addWidget(lblCompType);

        cmbCompType = new QComboBox(tabComposite);
        cmbCompType->setObjectName(QString::fromUtf8("cmbCompType"));

        horizontalLayout->addWidget(cmbCompType);


        verticalLayout_2->addLayout(horizontalLayout);

        lblComposite = new QLabel(tabComposite);
        lblComposite->setObjectName(QString::fromUtf8("lblComposite"));

        verticalLayout_2->addWidget(lblComposite);

        txtComposite = new QTextEdit(tabComposite);
        txtComposite->setObjectName(QString::fromUtf8("txtComposite"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txtComposite->sizePolicy().hasHeightForWidth());
        txtComposite->setSizePolicy(sizePolicy1);
        txtComposite->setAcceptRichText(false);

        verticalLayout_2->addWidget(txtComposite);

        tab->addTab(tabComposite, QString());

        vboxLayout->addWidget(tab);

        printWhenPanel = new NCRDPrintWhenPanel(NCRDBarcodePropDialogUI);
        printWhenPanel->setObjectName(QString::fromUtf8("printWhenPanel"));

        vboxLayout->addWidget(printWhenPanel);

        buttonBox = new QDialogButtonBox(NCRDBarcodePropDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        lblCompType->setBuddy(cmbCompType);
        lblComposite->setBuddy(txtComposite);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(comboResource, comboBarcodeType);
        QWidget::setTabOrder(comboBarcodeType, dataColumn);
        QWidget::setTabOrder(dataColumn, staticCode);
        QWidget::setTabOrder(staticCode, tab);
        QWidget::setTabOrder(tab, chkComposite);
        QWidget::setTabOrder(chkComposite, cmbCompType);
        QWidget::setTabOrder(cmbCompType, txtComposite);
        QWidget::setTabOrder(txtComposite, heightb);
        QWidget::setTabOrder(heightb, spnWhitespace);
        QWidget::setTabOrder(spnWhitespace, spnScale);
        QWidget::setTabOrder(spnScale, btype);
        QWidget::setTabOrder(btype, bwidth);
        QWidget::setTabOrder(bwidth, buttonBox);

        retranslateUi(NCRDBarcodePropDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDBarcodePropDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDBarcodePropDialogUI, SLOT(reject()));

        tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(NCRDBarcodePropDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDBarcodePropDialogUI)
    {
        NCRDBarcodePropDialogUI->setWindowTitle(QApplication::translate("NCRDBarcodePropDialogUI", "Barcode properties", 0, QApplication::UnicodeUTF8));
        gbImage->setTitle(QApplication::translate("NCRDBarcodePropDialogUI", "Barcode", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NCRDBarcodePropDialogUI", "Item resource:", 0, QApplication::UnicodeUTF8));
        comboResource->clear();
        comboResource->insertItems(0, QStringList()
         << QApplication::translate("NCRDBarcodePropDialogUI", "Static", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDBarcodePropDialogUI", "Datasource", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("NCRDBarcodePropDialogUI", "Static barcode data", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NCRDBarcodePropDialogUI", "Barcode type", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NCRDBarcodePropDialogUI", "Datasource column", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NCRDBarcodePropDialogUI", "Height:", 0, QApplication::UnicodeUTF8));
        heightb->setSuffix(QApplication::translate("NCRDBarcodePropDialogUI", " X", 0, QApplication::UnicodeUTF8));
        heightb->setPrefix(QString());
        lblScale->setText(QApplication::translate("NCRDBarcodePropDialogUI", "Printing Scale:", 0, QApplication::UnicodeUTF8));
        spnScale->setSuffix(QString());
        label_9->setText(QApplication::translate("NCRDBarcodePropDialogUI", "Border type:", 0, QApplication::UnicodeUTF8));
        btype->clear();
        btype->insertItems(0, QStringList()
         << QApplication::translate("NCRDBarcodePropDialogUI", "No border", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDBarcodePropDialogUI", "Bind", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDBarcodePropDialogUI", "Box", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("NCRDBarcodePropDialogUI", "Border width:", 0, QApplication::UnicodeUTF8));
        bwidth->setSuffix(QApplication::translate("NCRDBarcodePropDialogUI", " X", 0, QApplication::UnicodeUTF8));
        lblWhitespace->setText(QApplication::translate("NCRDBarcodePropDialogUI", "Whitespace:", 0, QApplication::UnicodeUTF8));
        spnWhitespace->setSuffix(QApplication::translate("NCRDBarcodePropDialogUI", " X", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NCRDBarcodePropDialogUI", "Foreground color:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("NCRDBarcodePropDialogUI", "Background color:", 0, QApplication::UnicodeUTF8));
        tab->setTabText(tab->indexOf(tabApp), QApplication::translate("NCRDBarcodePropDialogUI", "Appearance", 0, QApplication::UnicodeUTF8));
        chkComposite->setText(QApplication::translate("NCRDBarcodePropDialogUI", "&Add 2D Component", 0, QApplication::UnicodeUTF8));
        lblCompType->setText(QApplication::translate("NCRDBarcodePropDialogUI", "Component T&ype:", 0, QApplication::UnicodeUTF8));
        cmbCompType->clear();
        cmbCompType->insertItems(0, QStringList()
         << QApplication::translate("NCRDBarcodePropDialogUI", "Automatic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDBarcodePropDialogUI", "CC-A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDBarcodePropDialogUI", "CC-B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDBarcodePropDialogUI", "CC-C", 0, QApplication::UnicodeUTF8)
        );
        lblComposite->setText(QApplication::translate("NCRDBarcodePropDialogUI", "2D Component Data:", 0, QApplication::UnicodeUTF8));
        tab->setTabText(tab->indexOf(tabComposite), QApplication::translate("NCRDBarcodePropDialogUI", "Composit code", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDBarcodePropDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDBarcodePropDialogUI: public Ui_NCRDBarcodePropDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARCODEPROPDIALOG_H
