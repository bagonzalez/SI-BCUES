/********************************************************************************
** Form generated from reading ui file 'dstypedialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DSTYPEDIALOG_H
#define UI_DSTYPEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NCRDDataSourceTypeDialogUI
{
public:
    QHBoxLayout *hboxLayout;
    QGroupBox *gbTypes;
    QVBoxLayout *vboxLayout;
    QRadioButton *rbSql;
    QRadioButton *rbText;
    QRadioButton *rbXml;
    QRadioButton *rbStringList;
    QRadioButton *rbItem;
    QRadioButton *rbCustom;
    QSpacerItem *spacerItem;
    QVBoxLayout *vboxLayout1;
    QPushButton *btnCreate;
    QPushButton *btnCancel;
    QSpacerItem *spacerItem1;

    void setupUi(QDialog *NCRDDataSourceTypeDialogUI)
    {
        if (NCRDDataSourceTypeDialogUI->objectName().isEmpty())
            NCRDDataSourceTypeDialogUI->setObjectName(QString::fromUtf8("NCRDDataSourceTypeDialogUI"));
        NCRDDataSourceTypeDialogUI->resize(213, 169);
        hboxLayout = new QHBoxLayout(NCRDDataSourceTypeDialogUI);
        hboxLayout->setSpacing(3);
        hboxLayout->setMargin(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        gbTypes = new QGroupBox(NCRDDataSourceTypeDialogUI);
        gbTypes->setObjectName(QString::fromUtf8("gbTypes"));
        vboxLayout = new QVBoxLayout(gbTypes);
        vboxLayout->setSpacing(3);
        vboxLayout->setMargin(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(6, 6, 6, 6);
        rbSql = new QRadioButton(gbTypes);
        rbSql->setObjectName(QString::fromUtf8("rbSql"));
        rbSql->setChecked(true);

        vboxLayout->addWidget(rbSql);

        rbText = new QRadioButton(gbTypes);
        rbText->setObjectName(QString::fromUtf8("rbText"));

        vboxLayout->addWidget(rbText);

        rbXml = new QRadioButton(gbTypes);
        rbXml->setObjectName(QString::fromUtf8("rbXml"));

        vboxLayout->addWidget(rbXml);

        rbStringList = new QRadioButton(gbTypes);
        rbStringList->setObjectName(QString::fromUtf8("rbStringList"));

        vboxLayout->addWidget(rbStringList);

        rbItem = new QRadioButton(gbTypes);
        rbItem->setObjectName(QString::fromUtf8("rbItem"));

        vboxLayout->addWidget(rbItem);

        rbCustom = new QRadioButton(gbTypes);
        rbCustom->setObjectName(QString::fromUtf8("rbCustom"));

        vboxLayout->addWidget(rbCustom);


        hboxLayout->addWidget(gbTypes);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(3);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        btnCreate = new QPushButton(NCRDDataSourceTypeDialogUI);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));

        vboxLayout1->addWidget(btnCreate);

        btnCancel = new QPushButton(NCRDDataSourceTypeDialogUI);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        vboxLayout1->addWidget(btnCancel);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem1);


        hboxLayout->addLayout(vboxLayout1);

        QWidget::setTabOrder(rbSql, rbText);
        QWidget::setTabOrder(rbText, rbXml);
        QWidget::setTabOrder(rbXml, rbStringList);
        QWidget::setTabOrder(rbStringList, rbItem);
        QWidget::setTabOrder(rbItem, rbCustom);
        QWidget::setTabOrder(rbCustom, btnCreate);
        QWidget::setTabOrder(btnCreate, btnCancel);

        retranslateUi(NCRDDataSourceTypeDialogUI);
        QObject::connect(btnCreate, SIGNAL(clicked()), NCRDDataSourceTypeDialogUI, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), NCRDDataSourceTypeDialogUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(NCRDDataSourceTypeDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDDataSourceTypeDialogUI)
    {
        NCRDDataSourceTypeDialogUI->setWindowTitle(QApplication::translate("NCRDDataSourceTypeDialogUI", "Datasource type", 0, QApplication::UnicodeUTF8));
        gbTypes->setTitle(QApplication::translate("NCRDDataSourceTypeDialogUI", "Datasource types", 0, QApplication::UnicodeUTF8));
        rbSql->setText(QApplication::translate("NCRDDataSourceTypeDialogUI", "SQL query", 0, QApplication::UnicodeUTF8));
        rbText->setText(QApplication::translate("NCRDDataSourceTypeDialogUI", "Text", 0, QApplication::UnicodeUTF8));
        rbXml->setText(QApplication::translate("NCRDDataSourceTypeDialogUI", "XML", 0, QApplication::UnicodeUTF8));
        rbStringList->setText(QApplication::translate("NCRDDataSourceTypeDialogUI", "String list", 0, QApplication::UnicodeUTF8));
        rbItem->setText(QApplication::translate("NCRDDataSourceTypeDialogUI", "Item model", 0, QApplication::UnicodeUTF8));
        rbCustom->setText(QApplication::translate("NCRDDataSourceTypeDialogUI", "Custom", 0, QApplication::UnicodeUTF8));
        btnCreate->setText(QApplication::translate("NCRDDataSourceTypeDialogUI", "Create", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("NCRDDataSourceTypeDialogUI", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDDataSourceTypeDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDDataSourceTypeDialogUI: public Ui_NCRDDataSourceTypeDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSTYPEDIALOG_H
