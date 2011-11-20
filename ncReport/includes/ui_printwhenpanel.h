/********************************************************************************
** Form generated from reading ui file 'printwhenpanel.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PRINTWHENPANEL_H
#define UI_PRINTWHENPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NCRDPrintWhenPanelUI
{
public:
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *gbPrintWhen;
    QHBoxLayout *horizontalLayout;
    QLabel *lblExp;
    QLineEdit *printWhen;
    QLabel *lblZoneID;
    QSpinBox *zoneID;

    void setupUi(QWidget *NCRDPrintWhenPanelUI)
    {
        if (NCRDPrintWhenPanelUI->objectName().isEmpty())
            NCRDPrintWhenPanelUI->setObjectName(QString::fromUtf8("NCRDPrintWhenPanelUI"));
        NCRDPrintWhenPanelUI->resize(465, 54);
        horizontalLayout_3 = new QHBoxLayout(NCRDPrintWhenPanelUI);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setMargin(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gbPrintWhen = new QGroupBox(NCRDPrintWhenPanelUI);
        gbPrintWhen->setObjectName(QString::fromUtf8("gbPrintWhen"));
        horizontalLayout = new QHBoxLayout(gbPrintWhen);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setMargin(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblExp = new QLabel(gbPrintWhen);
        lblExp->setObjectName(QString::fromUtf8("lblExp"));

        horizontalLayout->addWidget(lblExp);

        printWhen = new QLineEdit(gbPrintWhen);
        printWhen->setObjectName(QString::fromUtf8("printWhen"));

        horizontalLayout->addWidget(printWhen);

        lblZoneID = new QLabel(gbPrintWhen);
        lblZoneID->setObjectName(QString::fromUtf8("lblZoneID"));

        horizontalLayout->addWidget(lblZoneID);

        zoneID = new QSpinBox(gbPrintWhen);
        zoneID->setObjectName(QString::fromUtf8("zoneID"));

        horizontalLayout->addWidget(zoneID);


        horizontalLayout_3->addWidget(gbPrintWhen);


        retranslateUi(NCRDPrintWhenPanelUI);

        QMetaObject::connectSlotsByName(NCRDPrintWhenPanelUI);
    } // setupUi

    void retranslateUi(QWidget *NCRDPrintWhenPanelUI)
    {
        NCRDPrintWhenPanelUI->setWindowTitle(QApplication::translate("NCRDPrintWhenPanelUI", "Form", 0, QApplication::UnicodeUTF8));
        gbPrintWhen->setTitle(QApplication::translate("NCRDPrintWhenPanelUI", "Print when conditions", 0, QApplication::UnicodeUTF8));
        lblExp->setText(QApplication::translate("NCRDPrintWhenPanelUI", "Logical expression:", 0, QApplication::UnicodeUTF8));
        lblZoneID->setText(QApplication::translate("NCRDPrintWhenPanelUI", "Zone ID:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDPrintWhenPanelUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDPrintWhenPanelUI: public Ui_NCRDPrintWhenPanelUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTWHENPANEL_H
