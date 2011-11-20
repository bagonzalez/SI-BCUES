/********************************************************************************
** Form generated from reading ui file 'imagepropdialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_IMAGEPROPDIALOG_H
#define UI_IMAGEPROPDIALOG_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include "ncrdprintwhenpanel.h"

QT_BEGIN_NAMESPACE

class Ui_NCRDImagePropDialogUI
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbImage;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboResource;
    QSpacerItem *spcr;
    QLabel *label_2;
    QLineEdit *fileName;
    QToolButton *btnChoose;
    QLabel *label_4;
    QLineEdit *sqlExpr;
    QComboBox *comboFormat;
    QLabel *label_3;
    QHBoxLayout *laySc;
    QGroupBox *gbScaling;
    QVBoxLayout *vboxLayout1;
    QCheckBox *cbScaling;
    QGroupBox *gbAspect;
    QVBoxLayout *vboxLayout2;
    QRadioButton *rbIgnoreAspect;
    QRadioButton *rbKeepAspect;
    QRadioButton *rbExpandAspect;
    QGroupBox *gbTrans;
    QVBoxLayout *vboxLayout3;
    QRadioButton *rbFastTran;
    QRadioButton *rbSmoothTran;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout4;
    QLabel *lblPreview;
    NCRDPrintWhenPanel *printWhenPanel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDImagePropDialogUI)
    {
        if (NCRDImagePropDialogUI->objectName().isEmpty())
            NCRDImagePropDialogUI->setObjectName(QString::fromUtf8("NCRDImagePropDialogUI"));
        NCRDImagePropDialogUI->resize(532, 452);
        vboxLayout = new QVBoxLayout(NCRDImagePropDialogUI);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        gbImage = new QGroupBox(NCRDImagePropDialogUI);
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

        gridLayout->addItem(spcr, 0, 2, 1, 2);

        label_2 = new QLabel(gbImage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        fileName = new QLineEdit(gbImage);
        fileName->setObjectName(QString::fromUtf8("fileName"));

        gridLayout->addWidget(fileName, 2, 1, 1, 2);

        btnChoose = new QToolButton(gbImage);
        btnChoose->setObjectName(QString::fromUtf8("btnChoose"));

        gridLayout->addWidget(btnChoose, 2, 3, 1, 1);

        label_4 = new QLabel(gbImage);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        sqlExpr = new QLineEdit(gbImage);
        sqlExpr->setObjectName(QString::fromUtf8("sqlExpr"));

        gridLayout->addWidget(sqlExpr, 1, 1, 1, 3);

        comboFormat = new QComboBox(gbImage);
        comboFormat->setObjectName(QString::fromUtf8("comboFormat"));

        gridLayout->addWidget(comboFormat, 3, 1, 1, 1);

        label_3 = new QLabel(gbImage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);


        vboxLayout->addWidget(gbImage);

        laySc = new QHBoxLayout();
        laySc->setObjectName(QString::fromUtf8("laySc"));
        gbScaling = new QGroupBox(NCRDImagePropDialogUI);
        gbScaling->setObjectName(QString::fromUtf8("gbScaling"));
        vboxLayout1 = new QVBoxLayout(gbScaling);
        vboxLayout1->setSpacing(3);
        vboxLayout1->setMargin(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        cbScaling = new QCheckBox(gbScaling);
        cbScaling->setObjectName(QString::fromUtf8("cbScaling"));

        vboxLayout1->addWidget(cbScaling);

        gbAspect = new QGroupBox(gbScaling);
        gbAspect->setObjectName(QString::fromUtf8("gbAspect"));
        gbAspect->setEnabled(false);
        vboxLayout2 = new QVBoxLayout(gbAspect);
        vboxLayout2->setSpacing(3);
        vboxLayout2->setMargin(6);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        rbIgnoreAspect = new QRadioButton(gbAspect);
        rbIgnoreAspect->setObjectName(QString::fromUtf8("rbIgnoreAspect"));

        vboxLayout2->addWidget(rbIgnoreAspect);

        rbKeepAspect = new QRadioButton(gbAspect);
        rbKeepAspect->setObjectName(QString::fromUtf8("rbKeepAspect"));

        vboxLayout2->addWidget(rbKeepAspect);

        rbExpandAspect = new QRadioButton(gbAspect);
        rbExpandAspect->setObjectName(QString::fromUtf8("rbExpandAspect"));

        vboxLayout2->addWidget(rbExpandAspect);


        vboxLayout1->addWidget(gbAspect);

        gbTrans = new QGroupBox(gbScaling);
        gbTrans->setObjectName(QString::fromUtf8("gbTrans"));
        gbTrans->setEnabled(false);
        vboxLayout3 = new QVBoxLayout(gbTrans);
        vboxLayout3->setSpacing(3);
        vboxLayout3->setMargin(6);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        rbFastTran = new QRadioButton(gbTrans);
        rbFastTran->setObjectName(QString::fromUtf8("rbFastTran"));

        vboxLayout3->addWidget(rbFastTran);

        rbSmoothTran = new QRadioButton(gbTrans);
        rbSmoothTran->setObjectName(QString::fromUtf8("rbSmoothTran"));

        vboxLayout3->addWidget(rbSmoothTran);


        vboxLayout1->addWidget(gbTrans);


        laySc->addWidget(gbScaling);

        groupBox = new QGroupBox(NCRDImagePropDialogUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        vboxLayout4 = new QVBoxLayout(groupBox);
        vboxLayout4->setSpacing(2);
        vboxLayout4->setMargin(2);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        lblPreview = new QLabel(groupBox);
        lblPreview->setObjectName(QString::fromUtf8("lblPreview"));
        lblPreview->setAlignment(Qt::AlignCenter);

        vboxLayout4->addWidget(lblPreview);


        laySc->addWidget(groupBox);


        vboxLayout->addLayout(laySc);

        printWhenPanel = new NCRDPrintWhenPanel(NCRDImagePropDialogUI);
        printWhenPanel->setObjectName(QString::fromUtf8("printWhenPanel"));

        vboxLayout->addWidget(printWhenPanel);

        buttonBox = new QDialogButtonBox(NCRDImagePropDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(comboResource, sqlExpr);
        QWidget::setTabOrder(sqlExpr, fileName);
        QWidget::setTabOrder(fileName, btnChoose);
        QWidget::setTabOrder(btnChoose, cbScaling);
        QWidget::setTabOrder(cbScaling, rbIgnoreAspect);
        QWidget::setTabOrder(rbIgnoreAspect, rbKeepAspect);
        QWidget::setTabOrder(rbKeepAspect, rbExpandAspect);
        QWidget::setTabOrder(rbExpandAspect, rbFastTran);
        QWidget::setTabOrder(rbFastTran, rbSmoothTran);
        QWidget::setTabOrder(rbSmoothTran, buttonBox);

        retranslateUi(NCRDImagePropDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDImagePropDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDImagePropDialogUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(NCRDImagePropDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDImagePropDialogUI)
    {
        NCRDImagePropDialogUI->setWindowTitle(QApplication::translate("NCRDImagePropDialogUI", "Image properties", 0, QApplication::UnicodeUTF8));
        gbImage->setTitle(QApplication::translate("NCRDImagePropDialogUI", "Image", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NCRDImagePropDialogUI", "Image resource:", 0, QApplication::UnicodeUTF8));
        comboResource->clear();
        comboResource->insertItems(0, QStringList()
         << QApplication::translate("NCRDImagePropDialogUI", "Static", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDImagePropDialogUI", "Datasource", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDImagePropDialogUI", "File", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDImagePropDialogUI", "Filename from Datasource", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("NCRDImagePropDialogUI", "Image file:", 0, QApplication::UnicodeUTF8));
        btnChoose->setText(QApplication::translate("NCRDImagePropDialogUI", "...", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NCRDImagePropDialogUI", "Datasource column:", 0, QApplication::UnicodeUTF8));
        comboFormat->clear();
        comboFormat->insertItems(0, QStringList()
         << QApplication::translate("NCRDImagePropDialogUI", "Native", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDImagePropDialogUI", "Base64 encoded", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDImagePropDialogUI", "SVG format", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("NCRDImagePropDialogUI", "Format:", 0, QApplication::UnicodeUTF8));
        gbScaling->setTitle(QApplication::translate("NCRDImagePropDialogUI", "Scaling options", 0, QApplication::UnicodeUTF8));
        cbScaling->setText(QApplication::translate("NCRDImagePropDialogUI", "Enable scaling image", 0, QApplication::UnicodeUTF8));
        gbAspect->setTitle(QApplication::translate("NCRDImagePropDialogUI", "Aspect ratio", 0, QApplication::UnicodeUTF8));
        rbIgnoreAspect->setText(QApplication::translate("NCRDImagePropDialogUI", "Ignore aspect ratio", 0, QApplication::UnicodeUTF8));
        rbKeepAspect->setText(QApplication::translate("NCRDImagePropDialogUI", "Keep aspect ratio", 0, QApplication::UnicodeUTF8));
        rbExpandAspect->setText(QApplication::translate("NCRDImagePropDialogUI", "Keep aspect ratio by expanding", 0, QApplication::UnicodeUTF8));
        gbTrans->setTitle(QApplication::translate("NCRDImagePropDialogUI", "Transformation", 0, QApplication::UnicodeUTF8));
        rbFastTran->setText(QApplication::translate("NCRDImagePropDialogUI", "Fast image transformation", 0, QApplication::UnicodeUTF8));
        rbSmoothTran->setText(QApplication::translate("NCRDImagePropDialogUI", "Smooth image transormation", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NCRDImagePropDialogUI", "Preview", 0, QApplication::UnicodeUTF8));
        lblPreview->setText(QApplication::translate("NCRDImagePropDialogUI", "IMAGE", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDImagePropDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDImagePropDialogUI: public Ui_NCRDImagePropDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPROPDIALOG_H
