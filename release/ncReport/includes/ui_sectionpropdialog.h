/********************************************************************************
** Form generated from reading ui file 'sectionpropdialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SECTIONPROPDIALOG_H
#define UI_SECTIONPROPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
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
#include <QtGui/QVBoxLayout>
#include "ncrdprintwhenpanel.h"

QT_BEGIN_NAMESPACE

class Ui_NCRDSectionDialogUI
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *leID;
    QLabel *label_3;
    QDoubleSpinBox *spHeight;
    QLineEdit *leType;
    QLabel *label;
    QSpacerItem *hSpacer;
    QCheckBox *cbAutoHeight;
    QCheckBox *cbHideIfBlank;
    QCheckBox *cbBreakRole;
    NCRDPrintWhenPanel *printWhenPanel;
    QSpacerItem *spacerItem;
    QHBoxLayout *layBtn;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDSectionDialogUI)
    {
        if (NCRDSectionDialogUI->objectName().isEmpty())
            NCRDSectionDialogUI->setObjectName(QString::fromUtf8("NCRDSectionDialogUI"));
        NCRDSectionDialogUI->setWindowModality(Qt::ApplicationModal);
        NCRDSectionDialogUI->resize(495, 234);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Helvetica"));
        NCRDSectionDialogUI->setFont(font);
        vboxLayout = new QVBoxLayout(NCRDSectionDialogUI);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        groupBox = new QGroupBox(NCRDSectionDialogUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(3);
        gridLayout->setMargin(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leID = new QLineEdit(groupBox);
        leID->setObjectName(QString::fromUtf8("leID"));

        gridLayout->addWidget(leID, 1, 1, 1, 3);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        spHeight = new QDoubleSpinBox(groupBox);
        spHeight->setObjectName(QString::fromUtf8("spHeight"));
        spHeight->setMaximum(999.99);

        gridLayout->addWidget(spHeight, 2, 1, 1, 1);

        leType = new QLineEdit(groupBox);
        leType->setObjectName(QString::fromUtf8("leType"));
        leType->setEnabled(true);
        leType->setReadOnly(true);

        gridLayout->addWidget(leType, 0, 1, 1, 3);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(hSpacer, 2, 2, 1, 1);

        cbAutoHeight = new QCheckBox(groupBox);
        cbAutoHeight->setObjectName(QString::fromUtf8("cbAutoHeight"));

        gridLayout->addWidget(cbAutoHeight, 2, 3, 1, 1);

        cbHideIfBlank = new QCheckBox(groupBox);
        cbHideIfBlank->setObjectName(QString::fromUtf8("cbHideIfBlank"));

        gridLayout->addWidget(cbHideIfBlank, 3, 3, 1, 1);

        cbBreakRole = new QCheckBox(groupBox);
        cbBreakRole->setObjectName(QString::fromUtf8("cbBreakRole"));

        gridLayout->addWidget(cbBreakRole, 4, 3, 1, 1);


        vboxLayout1->addWidget(groupBox);

        printWhenPanel = new NCRDPrintWhenPanel(NCRDSectionDialogUI);
        printWhenPanel->setObjectName(QString::fromUtf8("printWhenPanel"));

        vboxLayout1->addWidget(printWhenPanel);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem);


        hboxLayout->addLayout(vboxLayout1);


        vboxLayout->addLayout(hboxLayout);

        layBtn = new QHBoxLayout();
        layBtn->setObjectName(QString::fromUtf8("layBtn"));
        buttonBox = new QDialogButtonBox(NCRDSectionDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        layBtn->addWidget(buttonBox);


        vboxLayout->addLayout(layBtn);

        QWidget::setTabOrder(leType, leID);
        QWidget::setTabOrder(leID, spHeight);
        QWidget::setTabOrder(spHeight, buttonBox);

        retranslateUi(NCRDSectionDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDSectionDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDSectionDialogUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(NCRDSectionDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDSectionDialogUI)
    {
        NCRDSectionDialogUI->setWindowTitle(QApplication::translate("NCRDSectionDialogUI", "Report section settings", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NCRDSectionDialogUI", "Section's properties", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NCRDSectionDialogUI", "Section ID:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NCRDSectionDialogUI", "Height", 0, QApplication::UnicodeUTF8));
        spHeight->setSuffix(QApplication::translate("NCRDSectionDialogUI", " mm", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NCRDSectionDialogUI", "Section type:", 0, QApplication::UnicodeUTF8));
        cbAutoHeight->setText(QApplication::translate("NCRDSectionDialogUI", "Automatic height", 0, QApplication::UnicodeUTF8));
        cbHideIfBlank->setText(QApplication::translate("NCRDSectionDialogUI", "Hide section if content is blank", 0, QApplication::UnicodeUTF8));
        cbBreakRole->setText(QApplication::translate("NCRDSectionDialogUI", "Break to next page if singular", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDSectionDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDSectionDialogUI: public Ui_NCRDSectionDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECTIONPROPDIALOG_H
