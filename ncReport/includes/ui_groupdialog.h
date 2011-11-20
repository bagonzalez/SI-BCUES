/********************************************************************************
** Form generated from reading ui file 'groupdialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GROUPDIALOG_H
#define UI_GROUPDIALOG_H

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
#include <QtGui/QListView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NCRDGroupDialogUI
{
public:
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QHBoxLayout *hboxLayout1;
    QListView *listGroups;
    QVBoxLayout *vboxLayout1;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QSpacerItem *spacerItem;
    QPushButton *btnUp;
    QPushButton *btnDown;
    QSpacerItem *spacerItem1;
    QVBoxLayout *vboxLayout2;
    QGroupBox *gbGroup;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *groupID;
    QLabel *label_4;
    QLineEdit *groupExp;
    QGroupBox *gbHF;
    QGridLayout *gridLayout1;
    QCheckBox *cbHeader;
    QDoubleSpinBox *spHeader;
    QLabel *label_5;
    QCheckBox *cbFooter;
    QDoubleSpinBox *spFooter;
    QLabel *label_6;
    QCheckBox *cbReprint;
    QCheckBox *cbPrintOnNewPage;
    QLabel *label_3;
    QListWidget *listVars;
    QVBoxLayout *vboxLayout3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDGroupDialogUI)
    {
        if (NCRDGroupDialogUI->objectName().isEmpty())
            NCRDGroupDialogUI->setObjectName(QString::fromUtf8("NCRDGroupDialogUI"));
        NCRDGroupDialogUI->setWindowModality(Qt::ApplicationModal);
        NCRDGroupDialogUI->resize(610, 384);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Helvetica"));
        NCRDGroupDialogUI->setFont(font);
        hboxLayout = new QHBoxLayout(NCRDGroupDialogUI);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        label = new QLabel(NCRDGroupDialogUI);
        label->setObjectName(QString::fromUtf8("label"));

        vboxLayout->addWidget(label);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        listGroups = new QListView(NCRDGroupDialogUI);
        listGroups->setObjectName(QString::fromUtf8("listGroups"));

        hboxLayout1->addWidget(listGroups);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        btnAdd = new QPushButton(NCRDGroupDialogUI);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setAutoDefault(false);

        vboxLayout1->addWidget(btnAdd);

        btnRemove = new QPushButton(NCRDGroupDialogUI);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));

        vboxLayout1->addWidget(btnRemove);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout1->addItem(spacerItem);

        btnUp = new QPushButton(NCRDGroupDialogUI);
        btnUp->setObjectName(QString::fromUtf8("btnUp"));

        vboxLayout1->addWidget(btnUp);

        btnDown = new QPushButton(NCRDGroupDialogUI);
        btnDown->setObjectName(QString::fromUtf8("btnDown"));

        vboxLayout1->addWidget(btnDown);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem1);


        hboxLayout1->addLayout(vboxLayout1);


        vboxLayout->addLayout(hboxLayout1);


        hboxLayout->addLayout(vboxLayout);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        gbGroup = new QGroupBox(NCRDGroupDialogUI);
        gbGroup->setObjectName(QString::fromUtf8("gbGroup"));
        gridLayout = new QGridLayout(gbGroup);
        gridLayout->setSpacing(3);
        gridLayout->setMargin(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(gbGroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        groupID = new QLineEdit(gbGroup);
        groupID->setObjectName(QString::fromUtf8("groupID"));
        groupID->setMaximumSize(QSize(90, 16777215));

        gridLayout->addWidget(groupID, 0, 1, 1, 1);

        label_4 = new QLabel(gbGroup);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        groupExp = new QLineEdit(gbGroup);
        groupExp->setObjectName(QString::fromUtf8("groupExp"));
        groupExp->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(groupExp, 1, 1, 1, 1);


        vboxLayout2->addWidget(gbGroup);

        gbHF = new QGroupBox(NCRDGroupDialogUI);
        gbHF->setObjectName(QString::fromUtf8("gbHF"));
        gridLayout1 = new QGridLayout(gbHF);
        gridLayout1->setSpacing(3);
        gridLayout1->setMargin(6);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        cbHeader = new QCheckBox(gbHF);
        cbHeader->setObjectName(QString::fromUtf8("cbHeader"));

        gridLayout1->addWidget(cbHeader, 0, 0, 1, 1);

        spHeader = new QDoubleSpinBox(gbHF);
        spHeader->setObjectName(QString::fromUtf8("spHeader"));
        spHeader->setMaximum(999.99);

        gridLayout1->addWidget(spHeader, 0, 1, 1, 1);

        label_5 = new QLabel(gbHF);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout1->addWidget(label_5, 0, 2, 1, 1);

        cbFooter = new QCheckBox(gbHF);
        cbFooter->setObjectName(QString::fromUtf8("cbFooter"));

        gridLayout1->addWidget(cbFooter, 1, 0, 1, 1);

        spFooter = new QDoubleSpinBox(gbHF);
        spFooter->setObjectName(QString::fromUtf8("spFooter"));
        spFooter->setMaximum(999.99);

        gridLayout1->addWidget(spFooter, 1, 1, 1, 1);

        label_6 = new QLabel(gbHF);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout1->addWidget(label_6, 1, 2, 1, 1);

        cbReprint = new QCheckBox(gbHF);
        cbReprint->setObjectName(QString::fromUtf8("cbReprint"));

        gridLayout1->addWidget(cbReprint, 2, 0, 1, 3);

        cbPrintOnNewPage = new QCheckBox(gbHF);
        cbPrintOnNewPage->setObjectName(QString::fromUtf8("cbPrintOnNewPage"));

        gridLayout1->addWidget(cbPrintOnNewPage, 3, 0, 1, 3);


        vboxLayout2->addWidget(gbHF);

        label_3 = new QLabel(NCRDGroupDialogUI);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        vboxLayout2->addWidget(label_3);

        listVars = new QListWidget(NCRDGroupDialogUI);
        listVars->setObjectName(QString::fromUtf8("listVars"));

        vboxLayout2->addWidget(listVars);


        hboxLayout->addLayout(vboxLayout2);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(6);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        buttonBox = new QDialogButtonBox(NCRDGroupDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout3->addWidget(buttonBox);


        hboxLayout->addLayout(vboxLayout3);

        QWidget::setTabOrder(listGroups, btnAdd);
        QWidget::setTabOrder(btnAdd, btnRemove);
        QWidget::setTabOrder(btnRemove, btnUp);
        QWidget::setTabOrder(btnUp, btnDown);
        QWidget::setTabOrder(btnDown, groupID);
        QWidget::setTabOrder(groupID, groupExp);
        QWidget::setTabOrder(groupExp, cbHeader);
        QWidget::setTabOrder(cbHeader, spHeader);
        QWidget::setTabOrder(spHeader, cbFooter);
        QWidget::setTabOrder(cbFooter, spFooter);
        QWidget::setTabOrder(spFooter, cbReprint);
        QWidget::setTabOrder(cbReprint, cbPrintOnNewPage);
        QWidget::setTabOrder(cbPrintOnNewPage, listVars);

        retranslateUi(NCRDGroupDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDGroupDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDGroupDialogUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(NCRDGroupDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDGroupDialogUI)
    {
        NCRDGroupDialogUI->setWindowTitle(QApplication::translate("NCRDGroupDialogUI", "Data grouping", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NCRDGroupDialogUI", "Groups", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("NCRDGroupDialogUI", "Add", 0, QApplication::UnicodeUTF8));
        btnRemove->setText(QApplication::translate("NCRDGroupDialogUI", "Remove", 0, QApplication::UnicodeUTF8));
        btnUp->setText(QApplication::translate("NCRDGroupDialogUI", "Up", 0, QApplication::UnicodeUTF8));
        btnDown->setText(QApplication::translate("NCRDGroupDialogUI", "Down", 0, QApplication::UnicodeUTF8));
        gbGroup->setTitle(QApplication::translate("NCRDGroupDialogUI", "Group properties", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NCRDGroupDialogUI", "Group ID", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NCRDGroupDialogUI", "Group expression", 0, QApplication::UnicodeUTF8));
        gbHF->setTitle(QApplication::translate("NCRDGroupDialogUI", "Header and Footer", 0, QApplication::UnicodeUTF8));
        cbHeader->setText(QApplication::translate("NCRDGroupDialogUI", "Group header", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NCRDGroupDialogUI", "mm", 0, QApplication::UnicodeUTF8));
        cbFooter->setText(QApplication::translate("NCRDGroupDialogUI", "Group footer", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NCRDGroupDialogUI", "mm", 0, QApplication::UnicodeUTF8));
        cbReprint->setText(QApplication::translate("NCRDGroupDialogUI", "Reprint header on new page", 0, QApplication::UnicodeUTF8));
        cbPrintOnNewPage->setText(QApplication::translate("NCRDGroupDialogUI", "Starts on new page", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NCRDGroupDialogUI", "Reset variables", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDGroupDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDGroupDialogUI: public Ui_NCRDGroupDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPDIALOG_H
