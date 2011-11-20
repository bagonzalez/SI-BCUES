/********************************************************************************
** Form generated from reading ui file 'shapepropdialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SHAPEPROPDIALOG_H
#define UI_SHAPEPROPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include "ncrdprintwhenpanel.h"

QT_BEGIN_NAMESPACE

class Ui_NCRDShapePropDialogUI
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbRect;
    QGridLayout *gridLayout_2;
    QCheckBox *cbAutoHeight;
    QGroupBox *gbRound;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spRoundX;
    QLabel *label_2;
    QSpinBox *spRoundY;
    QGroupBox *gbFit;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *optExpandToSection;
    QRadioButton *optExpandToZone;
    QSpacerItem *horizontalSpacer;
    NCRDPrintWhenPanel *printWhenPanel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDShapePropDialogUI)
    {
        if (NCRDShapePropDialogUI->objectName().isEmpty())
            NCRDShapePropDialogUI->setObjectName(QString::fromUtf8("NCRDShapePropDialogUI"));
        NCRDShapePropDialogUI->resize(469, 206);
        vboxLayout = new QVBoxLayout(NCRDShapePropDialogUI);
        vboxLayout->setMargin(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        gbRect = new QGroupBox(NCRDShapePropDialogUI);
        gbRect->setObjectName(QString::fromUtf8("gbRect"));
        gridLayout_2 = new QGridLayout(gbRect);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        cbAutoHeight = new QCheckBox(gbRect);
        cbAutoHeight->setObjectName(QString::fromUtf8("cbAutoHeight"));

        gridLayout_2->addWidget(cbAutoHeight, 0, 0, 1, 1);

        gbRound = new QGroupBox(gbRect);
        gbRound->setObjectName(QString::fromUtf8("gbRound"));
        gridLayout = new QGridLayout(gbRound);
        gridLayout->setSpacing(3);
        gridLayout->setMargin(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(gbRound);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spRoundX = new QSpinBox(gbRound);
        spRoundX->setObjectName(QString::fromUtf8("spRoundX"));

        gridLayout->addWidget(spRoundX, 0, 1, 1, 1);

        label_2 = new QLabel(gbRound);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spRoundY = new QSpinBox(gbRound);
        spRoundY->setObjectName(QString::fromUtf8("spRoundY"));

        gridLayout->addWidget(spRoundY, 1, 1, 1, 1);


        gridLayout_2->addWidget(gbRound, 0, 1, 2, 1);

        gbFit = new QGroupBox(gbRect);
        gbFit->setObjectName(QString::fromUtf8("gbFit"));
        verticalLayout_2 = new QVBoxLayout(gbFit);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setMargin(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        optExpandToSection = new QRadioButton(gbFit);
        optExpandToSection->setObjectName(QString::fromUtf8("optExpandToSection"));

        verticalLayout_2->addWidget(optExpandToSection);

        optExpandToZone = new QRadioButton(gbFit);
        optExpandToZone->setObjectName(QString::fromUtf8("optExpandToZone"));

        verticalLayout_2->addWidget(optExpandToZone);


        gridLayout_2->addWidget(gbFit, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);


        vboxLayout->addWidget(gbRect);

        printWhenPanel = new NCRDPrintWhenPanel(NCRDShapePropDialogUI);
        printWhenPanel->setObjectName(QString::fromUtf8("printWhenPanel"));

        vboxLayout->addWidget(printWhenPanel);

        buttonBox = new QDialogButtonBox(NCRDShapePropDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(NCRDShapePropDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDShapePropDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDShapePropDialogUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(NCRDShapePropDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDShapePropDialogUI)
    {
        NCRDShapePropDialogUI->setWindowTitle(QApplication::translate("NCRDShapePropDialogUI", "Shape properties", 0, QApplication::UnicodeUTF8));
        gbRect->setTitle(QApplication::translate("NCRDShapePropDialogUI", "Rectangle settings", 0, QApplication::UnicodeUTF8));
        cbAutoHeight->setText(QApplication::translate("NCRDShapePropDialogUI", "Automatic height", 0, QApplication::UnicodeUTF8));
        gbRound->setTitle(QApplication::translate("NCRDShapePropDialogUI", "Rounded corners", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NCRDShapePropDialogUI", "X Round value", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NCRDShapePropDialogUI", "Y Round value", 0, QApplication::UnicodeUTF8));
        gbFit->setTitle(QString());
        optExpandToSection->setText(QApplication::translate("NCRDShapePropDialogUI", "Fit height to section", 0, QApplication::UnicodeUTF8));
        optExpandToZone->setText(QApplication::translate("NCRDShapePropDialogUI", "Fit height to zone", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDShapePropDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDShapePropDialogUI: public Ui_NCRDShapePropDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAPEPROPDIALOG_H
