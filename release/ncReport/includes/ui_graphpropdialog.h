/********************************************************************************
** Form generated from reading ui file 'graphpropdialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GRAPHPROPDIALOG_H
#define UI_GRAPHPROPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include "ncrdprintwhenpanel.h"

QT_BEGIN_NAMESPACE

class Ui_NCRDGraphPropDialogUI
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbImage;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboResource;
    QSpacerItem *spacerItem;
    QLabel *label_2;
    QLineEdit *text;
    QLabel *label_4;
    QTextEdit *graphDef;
    QLabel *label_5;
    QLineEdit *classID;
    NCRDPrintWhenPanel *printWhenPanel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDGraphPropDialogUI)
    {
        if (NCRDGraphPropDialogUI->objectName().isEmpty())
            NCRDGraphPropDialogUI->setObjectName(QString::fromUtf8("NCRDGraphPropDialogUI"));
        NCRDGraphPropDialogUI->resize(488, 275);
        vboxLayout = new QVBoxLayout(NCRDGraphPropDialogUI);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        gbImage = new QGroupBox(NCRDGraphPropDialogUI);
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

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 0, 2, 1, 3);

        label_2 = new QLabel(gbImage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        text = new QLineEdit(gbImage);
        text->setObjectName(QString::fromUtf8("text"));

        gridLayout->addWidget(text, 2, 1, 1, 4);

        label_4 = new QLabel(gbImage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_4->setWordWrap(true);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        graphDef = new QTextEdit(gbImage);
        graphDef->setObjectName(QString::fromUtf8("graphDef"));

        gridLayout->addWidget(graphDef, 3, 1, 1, 4);

        label_5 = new QLabel(gbImage);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        classID = new QLineEdit(gbImage);
        classID->setObjectName(QString::fromUtf8("classID"));

        gridLayout->addWidget(classID, 1, 1, 1, 1);


        vboxLayout->addWidget(gbImage);

        printWhenPanel = new NCRDPrintWhenPanel(NCRDGraphPropDialogUI);
        printWhenPanel->setObjectName(QString::fromUtf8("printWhenPanel"));

        vboxLayout->addWidget(printWhenPanel);

        buttonBox = new QDialogButtonBox(NCRDGraphPropDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(comboResource, classID);
        QWidget::setTabOrder(classID, text);
        QWidget::setTabOrder(text, graphDef);
        QWidget::setTabOrder(graphDef, buttonBox);

        retranslateUi(NCRDGraphPropDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDGraphPropDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDGraphPropDialogUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(NCRDGraphPropDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDGraphPropDialogUI)
    {
        NCRDGraphPropDialogUI->setWindowTitle(QApplication::translate("NCRDGraphPropDialogUI", "Graph/Custom item properties", 0, QApplication::UnicodeUTF8));
        gbImage->setTitle(QApplication::translate("NCRDGraphPropDialogUI", "Graph/Custom item", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NCRDGraphPropDialogUI", "Item resource:", 0, QApplication::UnicodeUTF8));
        comboResource->clear();
        comboResource->insertItems(0, QStringList()
         << QApplication::translate("NCRDGraphPropDialogUI", "Static", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDGraphPropDialogUI", "Datasource", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("NCRDGraphPropDialogUI", "Datasource column:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NCRDGraphPropDialogUI", "Graph/Item static definition:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NCRDGraphPropDialogUI", "Class ID:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDGraphPropDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDGraphPropDialogUI: public Ui_NCRDGraphPropDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHPROPDIALOG_H
