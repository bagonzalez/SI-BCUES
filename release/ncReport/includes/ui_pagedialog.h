/********************************************************************************
** Form generated from reading ui file 'pagedialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PAGEDIALOG_H
#define UI_PAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ncrdcolorcombo.h"

QT_BEGIN_NAMESPACE

class Ui_NCRDPageDialogUI
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabGen;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *gbGeneral;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *reportName;
    QLabel *label_2;
    QComboBox *comboEncoding;
    QLabel *label_4;
    QFontComboBox *comboFont;
    QComboBox *comboFontSize;
    QLabel *label_9;
    NCRDColorCombo *comboColor;
    QComboBox *comboReportType;
    QLabel *label_10;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *cbDoublePass;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboPageSize;
    QGridLayout *gridLayout1;
    QLabel *label_12;
    QDoubleSpinBox *spWidth;
    QLabel *label_13;
    QDoubleSpinBox *spHeight;
    QGroupBox *gbOrient;
    QVBoxLayout *_5;
    QRadioButton *radioP;
    QRadioButton *radioL;
    QGroupBox *gbMargins;
    QGridLayout *_4;
    QLabel *label_7;
    QDoubleSpinBox *spTop;
    QLabel *label_5;
    QDoubleSpinBox *spLeft;
    QLabel *label_6;
    QDoubleSpinBox *spRight;
    QLabel *label_8;
    QDoubleSpinBox *spBottom;
    QSpacerItem *verticalSpacer_3;
    QWidget *tabSect;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *gbHF;
    QGridLayout *_2;
    QCheckBox *cbPageHeader;
    QDoubleSpinBox *sbPH;
    QCheckBox *cbReportHeader;
    QDoubleSpinBox *sbRH;
    QCheckBox *cbPageFooter;
    QDoubleSpinBox *sbPF;
    QCheckBox *cbReportFooter;
    QDoubleSpinBox *sbRF;
    QSpacerItem *spacerItem;
    QSpacerItem *spacerItem1;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QDoubleSpinBox *sbZoneSpacing;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDPageDialogUI)
    {
        if (NCRDPageDialogUI->objectName().isEmpty())
            NCRDPageDialogUI->setObjectName(QString::fromUtf8("NCRDPageDialogUI"));
        NCRDPageDialogUI->resize(491, 332);
        verticalLayout = new QVBoxLayout(NCRDPageDialogUI);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(NCRDPageDialogUI);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabGen = new QWidget();
        tabGen->setObjectName(QString::fromUtf8("tabGen"));
        verticalLayout_2 = new QVBoxLayout(tabGen);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setMargin(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gbGeneral = new QGroupBox(tabGen);
        gbGeneral->setObjectName(QString::fromUtf8("gbGeneral"));
        gridLayout = new QGridLayout(gbGeneral);
        gridLayout->setSpacing(3);
        gridLayout->setMargin(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(gbGeneral);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        reportName = new QLineEdit(gbGeneral);
        reportName->setObjectName(QString::fromUtf8("reportName"));

        gridLayout->addWidget(reportName, 0, 1, 1, 2);

        label_2 = new QLabel(gbGeneral);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        comboEncoding = new QComboBox(gbGeneral);
        comboEncoding->setObjectName(QString::fromUtf8("comboEncoding"));

        gridLayout->addWidget(comboEncoding, 2, 1, 1, 1);

        label_4 = new QLabel(gbGeneral);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        comboFont = new QFontComboBox(gbGeneral);
        comboFont->setObjectName(QString::fromUtf8("comboFont"));

        gridLayout->addWidget(comboFont, 3, 1, 1, 1);

        comboFontSize = new QComboBox(gbGeneral);
        comboFontSize->setObjectName(QString::fromUtf8("comboFontSize"));
        comboFontSize->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(comboFontSize, 3, 2, 1, 1);

        label_9 = new QLabel(gbGeneral);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setEnabled(false);

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        comboColor = new NCRDColorCombo(gbGeneral);
        comboColor->setObjectName(QString::fromUtf8("comboColor"));
        comboColor->setEnabled(false);

        gridLayout->addWidget(comboColor, 4, 1, 1, 1);

        comboReportType = new QComboBox(gbGeneral);
        comboReportType->setObjectName(QString::fromUtf8("comboReportType"));

        gridLayout->addWidget(comboReportType, 1, 1, 1, 1);

        label_10 = new QLabel(gbGeneral);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 1, 1, 1);

        cbDoublePass = new QCheckBox(gbGeneral);
        cbDoublePass->setObjectName(QString::fromUtf8("cbDoublePass"));

        gridLayout->addWidget(cbDoublePass, 5, 0, 1, 2);


        verticalLayout_2->addWidget(gbGeneral);

        tabWidget->addTab(tabGen, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboPageSize = new QComboBox(groupBox_2);
        comboPageSize->setObjectName(QString::fromUtf8("comboPageSize"));

        horizontalLayout_2->addWidget(comboPageSize);

        gridLayout1 = new QGridLayout();
        gridLayout1->setSpacing(3);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(label_12, 0, 0, 1, 1);

        spWidth = new QDoubleSpinBox(groupBox_2);
        spWidth->setObjectName(QString::fromUtf8("spWidth"));
        spWidth->setMinimum(10);
        spWidth->setMaximum(999.99);

        gridLayout1->addWidget(spWidth, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(label_13, 1, 0, 1, 1);

        spHeight = new QDoubleSpinBox(groupBox_2);
        spHeight->setObjectName(QString::fromUtf8("spHeight"));
        spHeight->setMinimum(10);
        spHeight->setMaximum(999.99);

        gridLayout1->addWidget(spHeight, 1, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout1);


        horizontalLayout_3->addWidget(groupBox_2);

        gbOrient = new QGroupBox(tab);
        gbOrient->setObjectName(QString::fromUtf8("gbOrient"));
        _5 = new QVBoxLayout(gbOrient);
        _5->setSpacing(3);
        _5->setMargin(6);
        _5->setObjectName(QString::fromUtf8("_5"));
        radioP = new QRadioButton(gbOrient);
        radioP->setObjectName(QString::fromUtf8("radioP"));
        radioP->setChecked(true);

        _5->addWidget(radioP);

        radioL = new QRadioButton(gbOrient);
        radioL->setObjectName(QString::fromUtf8("radioL"));

        _5->addWidget(radioL);


        horizontalLayout_3->addWidget(gbOrient);


        verticalLayout_4->addLayout(horizontalLayout_3);

        gbMargins = new QGroupBox(tab);
        gbMargins->setObjectName(QString::fromUtf8("gbMargins"));
        _4 = new QGridLayout(gbMargins);
        _4->setSpacing(3);
        _4->setMargin(6);
        _4->setObjectName(QString::fromUtf8("_4"));
        label_7 = new QLabel(gbMargins);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        _4->addWidget(label_7, 0, 2, 1, 1);

        spTop = new QDoubleSpinBox(gbMargins);
        spTop->setObjectName(QString::fromUtf8("spTop"));
        spTop->setMinimumSize(QSize(70, 0));
        spTop->setMaximum(999.99);

        _4->addWidget(spTop, 0, 3, 1, 1);

        label_5 = new QLabel(gbMargins);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        _4->addWidget(label_5, 1, 0, 1, 1);

        spLeft = new QDoubleSpinBox(gbMargins);
        spLeft->setObjectName(QString::fromUtf8("spLeft"));
        spLeft->setMinimumSize(QSize(70, 0));
        spLeft->setMaximum(999.99);

        _4->addWidget(spLeft, 1, 1, 1, 1);

        label_6 = new QLabel(gbMargins);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        _4->addWidget(label_6, 1, 4, 1, 1);

        spRight = new QDoubleSpinBox(gbMargins);
        spRight->setObjectName(QString::fromUtf8("spRight"));
        spRight->setMinimumSize(QSize(70, 0));
        spRight->setMaximum(999.99);

        _4->addWidget(spRight, 1, 5, 1, 1);

        label_8 = new QLabel(gbMargins);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        _4->addWidget(label_8, 2, 2, 1, 1);

        spBottom = new QDoubleSpinBox(gbMargins);
        spBottom->setObjectName(QString::fromUtf8("spBottom"));
        spBottom->setMinimumSize(QSize(70, 0));
        spBottom->setMaximum(999.99);

        _4->addWidget(spBottom, 2, 3, 1, 1);


        verticalLayout_4->addWidget(gbMargins);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        tabWidget->addTab(tab, QString());
        tabSect = new QWidget();
        tabSect->setObjectName(QString::fromUtf8("tabSect"));
        verticalLayout_3 = new QVBoxLayout(tabSect);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setMargin(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gbHF = new QGroupBox(tabSect);
        gbHF->setObjectName(QString::fromUtf8("gbHF"));
        _2 = new QGridLayout(gbHF);
        _2->setSpacing(3);
        _2->setMargin(6);
        _2->setObjectName(QString::fromUtf8("_2"));
        cbPageHeader = new QCheckBox(gbHF);
        cbPageHeader->setObjectName(QString::fromUtf8("cbPageHeader"));

        _2->addWidget(cbPageHeader, 0, 0, 1, 1);

        sbPH = new QDoubleSpinBox(gbHF);
        sbPH->setObjectName(QString::fromUtf8("sbPH"));
        sbPH->setMinimumSize(QSize(70, 0));
        sbPH->setMaximum(999.99);

        _2->addWidget(sbPH, 0, 1, 1, 1);

        cbReportHeader = new QCheckBox(gbHF);
        cbReportHeader->setObjectName(QString::fromUtf8("cbReportHeader"));

        _2->addWidget(cbReportHeader, 0, 3, 1, 1);

        sbRH = new QDoubleSpinBox(gbHF);
        sbRH->setObjectName(QString::fromUtf8("sbRH"));
        sbRH->setMinimumSize(QSize(70, 0));
        sbRH->setMaximum(999.99);

        _2->addWidget(sbRH, 0, 4, 1, 1);

        cbPageFooter = new QCheckBox(gbHF);
        cbPageFooter->setObjectName(QString::fromUtf8("cbPageFooter"));

        _2->addWidget(cbPageFooter, 1, 0, 1, 1);

        sbPF = new QDoubleSpinBox(gbHF);
        sbPF->setObjectName(QString::fromUtf8("sbPF"));
        sbPF->setMinimumSize(QSize(70, 0));
        sbPF->setMaximum(999.99);

        _2->addWidget(sbPF, 1, 1, 1, 1);

        cbReportFooter = new QCheckBox(gbHF);
        cbReportFooter->setObjectName(QString::fromUtf8("cbReportFooter"));

        _2->addWidget(cbReportFooter, 1, 3, 1, 1);

        sbRF = new QDoubleSpinBox(gbHF);
        sbRF->setObjectName(QString::fromUtf8("sbRF"));
        sbRF->setMinimumSize(QSize(70, 0));
        sbRF->setMaximum(999.99);

        _2->addWidget(sbRF, 1, 4, 1, 1);

        spacerItem = new QSpacerItem(30, 15, QSizePolicy::Fixed, QSizePolicy::Minimum);

        _2->addItem(spacerItem, 0, 2, 1, 1);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(spacerItem1, 0, 5, 1, 1);


        verticalLayout_3->addWidget(gbHF);

        groupBox = new QGroupBox(tabSect);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout->addWidget(label_11);

        sbZoneSpacing = new QDoubleSpinBox(groupBox);
        sbZoneSpacing->setObjectName(QString::fromUtf8("sbZoneSpacing"));
        sbZoneSpacing->setMinimumSize(QSize(70, 0));
        sbZoneSpacing->setMaximum(999.99);

        horizontalLayout->addWidget(sbZoneSpacing);

        horizontalSpacer = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 147, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        tabWidget->addTab(tabSect, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(NCRDPageDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(reportName, comboReportType);
        QWidget::setTabOrder(comboReportType, comboEncoding);
        QWidget::setTabOrder(comboEncoding, comboFont);
        QWidget::setTabOrder(comboFont, comboFontSize);
        QWidget::setTabOrder(comboFontSize, comboColor);
        QWidget::setTabOrder(comboColor, cbDoublePass);
        QWidget::setTabOrder(cbDoublePass, comboPageSize);
        QWidget::setTabOrder(comboPageSize, spWidth);
        QWidget::setTabOrder(spWidth, spHeight);
        QWidget::setTabOrder(spHeight, radioP);
        QWidget::setTabOrder(radioP, radioL);
        QWidget::setTabOrder(radioL, spTop);
        QWidget::setTabOrder(spTop, spLeft);
        QWidget::setTabOrder(spLeft, spRight);
        QWidget::setTabOrder(spRight, spBottom);
        QWidget::setTabOrder(spBottom, cbPageHeader);
        QWidget::setTabOrder(cbPageHeader, cbPageFooter);
        QWidget::setTabOrder(cbPageFooter, sbPH);
        QWidget::setTabOrder(sbPH, sbPF);
        QWidget::setTabOrder(sbPF, cbReportHeader);
        QWidget::setTabOrder(cbReportHeader, cbReportFooter);
        QWidget::setTabOrder(cbReportFooter, sbRH);
        QWidget::setTabOrder(sbRH, sbRF);
        QWidget::setTabOrder(sbRF, sbZoneSpacing);
        QWidget::setTabOrder(sbZoneSpacing, tabWidget);
        QWidget::setTabOrder(tabWidget, buttonBox);

        retranslateUi(NCRDPageDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDPageDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDPageDialogUI, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(NCRDPageDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDPageDialogUI)
    {
        NCRDPageDialogUI->setWindowTitle(QApplication::translate("NCRDPageDialogUI", "Report and page settings", 0, QApplication::UnicodeUTF8));
        gbGeneral->setTitle(QApplication::translate("NCRDPageDialogUI", "General options", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NCRDPageDialogUI", "Report name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NCRDPageDialogUI", "File encoding", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NCRDPageDialogUI", "Default font", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("NCRDPageDialogUI", "Background color", 0, QApplication::UnicodeUTF8));
        comboReportType->clear();
        comboReportType->insertItems(0, QStringList()
         << QApplication::translate("NCRDPageDialogUI", "Report", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDPageDialogUI", "Text document", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("NCRDPageDialogUI", "Report type", 0, QApplication::UnicodeUTF8));
        cbDoublePass->setText(QApplication::translate("NCRDPageDialogUI", "Double pass mode", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabGen), QApplication::translate("NCRDPageDialogUI", "General", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("NCRDPageDialogUI", "Page size", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("NCRDPageDialogUI", "Width", 0, QApplication::UnicodeUTF8));
        spWidth->setSuffix(QApplication::translate("NCRDPageDialogUI", " mm", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("NCRDPageDialogUI", "Height", 0, QApplication::UnicodeUTF8));
        spHeight->setSuffix(QApplication::translate("NCRDPageDialogUI", " mm", 0, QApplication::UnicodeUTF8));
        gbOrient->setTitle(QApplication::translate("NCRDPageDialogUI", "Orientation", 0, QApplication::UnicodeUTF8));
        radioP->setText(QApplication::translate("NCRDPageDialogUI", "Portrait", 0, QApplication::UnicodeUTF8));
        radioL->setText(QApplication::translate("NCRDPageDialogUI", "Landscape", 0, QApplication::UnicodeUTF8));
        gbMargins->setTitle(QApplication::translate("NCRDPageDialogUI", "Margins", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("NCRDPageDialogUI", "Top", 0, QApplication::UnicodeUTF8));
        spTop->setSuffix(QApplication::translate("NCRDPageDialogUI", " mm", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NCRDPageDialogUI", "Left", 0, QApplication::UnicodeUTF8));
        spLeft->setSuffix(QApplication::translate("NCRDPageDialogUI", " mm", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NCRDPageDialogUI", "Right", 0, QApplication::UnicodeUTF8));
        spRight->setSuffix(QApplication::translate("NCRDPageDialogUI", " mm", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("NCRDPageDialogUI", "Bottom", 0, QApplication::UnicodeUTF8));
        spBottom->setSuffix(QApplication::translate("NCRDPageDialogUI", " mm", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("NCRDPageDialogUI", "Page settings", 0, QApplication::UnicodeUTF8));
        gbHF->setTitle(QApplication::translate("NCRDPageDialogUI", "Headers and footers", 0, QApplication::UnicodeUTF8));
        cbPageHeader->setText(QApplication::translate("NCRDPageDialogUI", "Page header", 0, QApplication::UnicodeUTF8));
        sbPH->setSuffix(QApplication::translate("NCRDPageDialogUI", " mm", 0, QApplication::UnicodeUTF8));
        cbReportHeader->setText(QApplication::translate("NCRDPageDialogUI", "Report header", 0, QApplication::UnicodeUTF8));
        sbRH->setSuffix(QApplication::translate("NCRDPageDialogUI", " mm", 0, QApplication::UnicodeUTF8));
        cbPageFooter->setText(QApplication::translate("NCRDPageDialogUI", "Page footer", 0, QApplication::UnicodeUTF8));
        sbPF->setSuffix(QApplication::translate("NCRDPageDialogUI", " mm", 0, QApplication::UnicodeUTF8));
        cbReportFooter->setText(QApplication::translate("NCRDPageDialogUI", "Report footer", 0, QApplication::UnicodeUTF8));
        sbRF->setSuffix(QApplication::translate("NCRDPageDialogUI", " mm", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NCRDPageDialogUI", "Zone settings", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("NCRDPageDialogUI", "Zone spacing:", 0, QApplication::UnicodeUTF8));
        sbZoneSpacing->setSuffix(QApplication::translate("NCRDPageDialogUI", " mm", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabSect), QApplication::translate("NCRDPageDialogUI", "Section options", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDPageDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDPageDialogUI: public Ui_NCRDPageDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEDIALOG_H
