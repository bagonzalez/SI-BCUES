/********************************************************************************
** Form generated from reading ui file 'detaildialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DETAILDIALOG_H
#define UI_DETAILDIALOG_H

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
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NCRDDetailDialogUI
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox_3;
    QHBoxLayout *hboxLayout1;
    QListView *listView;
    QVBoxLayout *vboxLayout1;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QSpacerItem *spacerItem;
    QPushButton *btnUp;
    QPushButton *btnDown;
    QVBoxLayout *vboxLayout2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *leDetailID;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QComboBox *comboDataSource;
    QDoubleSpinBox *spHeight;
    QGroupBox *groupBox_2;
    QVBoxLayout *vboxLayout3;
    QLabel *label;
    QLineEdit *pageBreakCond;
    QCheckBox *cbNewPage;
    QSpacerItem *spacerItem1;
    QHBoxLayout *hboxLayout2;
    QPushButton *btnGrouping;
    QSpacerItem *spacerItem2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDDetailDialogUI)
    {
        if (NCRDDetailDialogUI->objectName().isEmpty())
            NCRDDetailDialogUI->setObjectName(QString::fromUtf8("NCRDDetailDialogUI"));
        NCRDDetailDialogUI->setWindowModality(Qt::ApplicationModal);
        NCRDDetailDialogUI->resize(574, 285);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Helvetica"));
        NCRDDetailDialogUI->setFont(font);
        vboxLayout = new QVBoxLayout(NCRDDetailDialogUI);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        groupBox_3 = new QGroupBox(NCRDDetailDialogUI);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(250, 16777215));
        hboxLayout1 = new QHBoxLayout(groupBox_3);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        listView = new QListView(groupBox_3);
        listView->setObjectName(QString::fromUtf8("listView"));

        hboxLayout1->addWidget(listView);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(3);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        btnAdd = new QPushButton(groupBox_3);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        vboxLayout1->addWidget(btnAdd);

        btnRemove = new QPushButton(groupBox_3);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));

        vboxLayout1->addWidget(btnRemove);

        spacerItem = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem);

        btnUp = new QPushButton(groupBox_3);
        btnUp->setObjectName(QString::fromUtf8("btnUp"));
        btnUp->setEnabled(false);

        vboxLayout1->addWidget(btnUp);

        btnDown = new QPushButton(groupBox_3);
        btnDown->setObjectName(QString::fromUtf8("btnDown"));
        btnDown->setEnabled(false);

        vboxLayout1->addWidget(btnDown);


        hboxLayout1->addLayout(vboxLayout1);


        hboxLayout->addWidget(groupBox_3);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        groupBox = new QGroupBox(NCRDDetailDialogUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(3);
        gridLayout->setMargin(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        leDetailID = new QLineEdit(groupBox);
        leDetailID->setObjectName(QString::fromUtf8("leDetailID"));

        gridLayout->addWidget(leDetailID, 0, 1, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        comboDataSource = new QComboBox(groupBox);
        comboDataSource->setObjectName(QString::fromUtf8("comboDataSource"));

        gridLayout->addWidget(comboDataSource, 2, 1, 1, 2);

        spHeight = new QDoubleSpinBox(groupBox);
        spHeight->setObjectName(QString::fromUtf8("spHeight"));
        spHeight->setMaximum(999.99);

        gridLayout->addWidget(spHeight, 1, 1, 1, 1);


        vboxLayout2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(NCRDDetailDialogUI);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        vboxLayout3 = new QVBoxLayout(groupBox_2);
        vboxLayout3->setSpacing(3);
        vboxLayout3->setMargin(6);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        vboxLayout3->addWidget(label);

        pageBreakCond = new QLineEdit(groupBox_2);
        pageBreakCond->setObjectName(QString::fromUtf8("pageBreakCond"));

        vboxLayout3->addWidget(pageBreakCond);

        cbNewPage = new QCheckBox(groupBox_2);
        cbNewPage->setObjectName(QString::fromUtf8("cbNewPage"));

        vboxLayout3->addWidget(cbNewPage);


        vboxLayout2->addWidget(groupBox_2);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout2->addItem(spacerItem1);


        hboxLayout->addLayout(vboxLayout2);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        btnGrouping = new QPushButton(NCRDDetailDialogUI);
        btnGrouping->setObjectName(QString::fromUtf8("btnGrouping"));

        hboxLayout2->addWidget(btnGrouping);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem2);

        buttonBox = new QDialogButtonBox(NCRDDetailDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        hboxLayout2->addWidget(buttonBox);


        vboxLayout->addLayout(hboxLayout2);

        QWidget::setTabOrder(listView, btnAdd);
        QWidget::setTabOrder(btnAdd, btnRemove);
        QWidget::setTabOrder(btnRemove, btnUp);
        QWidget::setTabOrder(btnUp, btnDown);
        QWidget::setTabOrder(btnDown, leDetailID);
        QWidget::setTabOrder(leDetailID, spHeight);
        QWidget::setTabOrder(spHeight, comboDataSource);
        QWidget::setTabOrder(comboDataSource, pageBreakCond);
        QWidget::setTabOrder(pageBreakCond, btnGrouping);
        QWidget::setTabOrder(btnGrouping, buttonBox);

        retranslateUi(NCRDDetailDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDDetailDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDDetailDialogUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(NCRDDetailDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDDetailDialogUI)
    {
        NCRDDetailDialogUI->setWindowTitle(QApplication::translate("NCRDDetailDialogUI", "Report detail settings", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("NCRDDetailDialogUI", "Details", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("NCRDDetailDialogUI", "Add", 0, QApplication::UnicodeUTF8));
        btnRemove->setText(QApplication::translate("NCRDDetailDialogUI", "Remove", 0, QApplication::UnicodeUTF8));
        btnUp->setText(QApplication::translate("NCRDDetailDialogUI", "Up", 0, QApplication::UnicodeUTF8));
        btnDown->setText(QApplication::translate("NCRDDetailDialogUI", "Down", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NCRDDetailDialogUI", "Detail properties", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NCRDDetailDialogUI", "Detail ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NCRDDetailDialogUI", "Height", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NCRDDetailDialogUI", "mm", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NCRDDetailDialogUI", "Datasource", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("NCRDDetailDialogUI", "Page break", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NCRDDetailDialogUI", "Break condition (logical expression)", 0, QApplication::UnicodeUTF8));
        cbNewPage->setText(QApplication::translate("NCRDDetailDialogUI", "Starts on new page", 0, QApplication::UnicodeUTF8));
        btnGrouping->setText(QApplication::translate("NCRDDetailDialogUI", "Data grouping...", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDDetailDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDDetailDialogUI: public Ui_NCRDDetailDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILDIALOG_H
