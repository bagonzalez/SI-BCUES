/********************************************************************************
** Form generated from reading ui file 'labelpropdialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LABELPROPDIALOG_H
#define UI_LABELPROPDIALOG_H

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
#include <QtGui/QPlainTextEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "ncrdprintwhenpanel.h"
#include "qtcolorcombobox.h"

QT_BEGIN_NAMESPACE

class Ui_NCRDLabelPropDialogUI
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbBase;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *text;
    QGroupBox *gbSet;
    QGridLayout *gridLayout;
    QCheckBox *cbWordWrap;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QComboBox *comboBGMode;
    QCheckBox *cbAutoHeight;
    QLabel *label_3;
    QtColorComboBox *comboBackColor;
    NCRDPrintWhenPanel *printWhenPanel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDLabelPropDialogUI)
    {
        if (NCRDLabelPropDialogUI->objectName().isEmpty())
            NCRDLabelPropDialogUI->setObjectName(QString::fromUtf8("NCRDLabelPropDialogUI"));
        NCRDLabelPropDialogUI->resize(455, 297);
        vboxLayout = new QVBoxLayout(NCRDLabelPropDialogUI);
        vboxLayout->setMargin(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        gbBase = new QGroupBox(NCRDLabelPropDialogUI);
        gbBase->setObjectName(QString::fromUtf8("gbBase"));
        horizontalLayout = new QHBoxLayout(gbBase);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        text = new QPlainTextEdit(gbBase);
        text->setObjectName(QString::fromUtf8("text"));
        text->setTabChangesFocus(true);

        horizontalLayout->addWidget(text);


        vboxLayout->addWidget(gbBase);

        gbSet = new QGroupBox(NCRDLabelPropDialogUI);
        gbSet->setObjectName(QString::fromUtf8("gbSet"));
        gridLayout = new QGridLayout(gbSet);
        gridLayout->setSpacing(3);
        gridLayout->setMargin(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cbWordWrap = new QCheckBox(gbSet);
        cbWordWrap->setObjectName(QString::fromUtf8("cbWordWrap"));

        gridLayout->addWidget(cbWordWrap, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(37, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        label_5 = new QLabel(gbSet);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        comboBGMode = new QComboBox(gbSet);
        comboBGMode->setObjectName(QString::fromUtf8("comboBGMode"));

        gridLayout->addWidget(comboBGMode, 0, 3, 1, 1);

        cbAutoHeight = new QCheckBox(gbSet);
        cbAutoHeight->setObjectName(QString::fromUtf8("cbAutoHeight"));

        gridLayout->addWidget(cbAutoHeight, 1, 0, 1, 2);

        label_3 = new QLabel(gbSet);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        comboBackColor = new QtColorComboBox(gbSet);
        comboBackColor->setObjectName(QString::fromUtf8("comboBackColor"));

        gridLayout->addWidget(comboBackColor, 1, 3, 1, 1);


        vboxLayout->addWidget(gbSet);

        printWhenPanel = new NCRDPrintWhenPanel(NCRDLabelPropDialogUI);
        printWhenPanel->setObjectName(QString::fromUtf8("printWhenPanel"));

        vboxLayout->addWidget(printWhenPanel);

        buttonBox = new QDialogButtonBox(NCRDLabelPropDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(text, cbWordWrap);
        QWidget::setTabOrder(cbWordWrap, cbAutoHeight);
        QWidget::setTabOrder(cbAutoHeight, comboBGMode);
        QWidget::setTabOrder(comboBGMode, comboBackColor);
        QWidget::setTabOrder(comboBackColor, buttonBox);

        retranslateUi(NCRDLabelPropDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDLabelPropDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDLabelPropDialogUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(NCRDLabelPropDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDLabelPropDialogUI)
    {
        NCRDLabelPropDialogUI->setWindowTitle(QApplication::translate("NCRDLabelPropDialogUI", "Label properties", 0, QApplication::UnicodeUTF8));
        gbBase->setTitle(QApplication::translate("NCRDLabelPropDialogUI", "Label text", 0, QApplication::UnicodeUTF8));
        gbSet->setTitle(QApplication::translate("NCRDLabelPropDialogUI", "Settings", 0, QApplication::UnicodeUTF8));
        cbWordWrap->setText(QApplication::translate("NCRDLabelPropDialogUI", "Word wrapping", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NCRDLabelPropDialogUI", "Background mode:", 0, QApplication::UnicodeUTF8));
        comboBGMode->clear();
        comboBGMode->insertItems(0, QStringList()
         << QApplication::translate("NCRDLabelPropDialogUI", "Transparent", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDLabelPropDialogUI", "Filled background", 0, QApplication::UnicodeUTF8)
        );
        cbAutoHeight->setText(QApplication::translate("NCRDLabelPropDialogUI", "Automatic height", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NCRDLabelPropDialogUI", "Background color:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDLabelPropDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDLabelPropDialogUI: public Ui_NCRDLabelPropDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELPROPDIALOG_H
