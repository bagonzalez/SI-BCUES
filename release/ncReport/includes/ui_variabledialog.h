/********************************************************************************
** Form generated from reading ui file 'variabledialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VARIABLEDIALOG_H
#define UI_VARIABLEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NCRDVariableDialogUI
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QTableView *tableView;
    QVBoxLayout *vboxLayout1;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QSpacerItem *spacerItem;
    QGroupBox *gbProp;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *variableID;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboScope;
    QLabel *label_5;
    QLineEdit *initValue;
    QComboBox *comboFunc;
    QLabel *label_6;
    QLineEdit *expression;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem1;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDVariableDialogUI)
    {
        if (NCRDVariableDialogUI->objectName().isEmpty())
            NCRDVariableDialogUI->setObjectName(QString::fromUtf8("NCRDVariableDialogUI"));
        NCRDVariableDialogUI->setWindowModality(Qt::ApplicationModal);
        NCRDVariableDialogUI->resize(561, 432);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Helvetica"));
        NCRDVariableDialogUI->setFont(font);
        vboxLayout = new QVBoxLayout(NCRDVariableDialogUI);
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        tableView = new QTableView(NCRDVariableDialogUI);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        hboxLayout->addWidget(tableView);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        btnAdd = new QPushButton(NCRDVariableDialogUI);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        vboxLayout1->addWidget(btnAdd);

        btnRemove = new QPushButton(NCRDVariableDialogUI);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));

        vboxLayout1->addWidget(btnRemove);

        spacerItem = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem);


        hboxLayout->addLayout(vboxLayout1);


        vboxLayout->addLayout(hboxLayout);

        gbProp = new QGroupBox(NCRDVariableDialogUI);
        gbProp->setObjectName(QString::fromUtf8("gbProp"));
        gridLayout = new QGridLayout(gbProp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(3);
        gridLayout->setContentsMargins(6, 6, 6, 6);
        label_2 = new QLabel(gbProp);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        variableID = new QLineEdit(gbProp);
        variableID->setObjectName(QString::fromUtf8("variableID"));
        variableID->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(variableID, 0, 1, 1, 1);

        label_3 = new QLabel(gbProp);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(gbProp);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        comboScope = new QComboBox(gbProp);
        comboScope->setObjectName(QString::fromUtf8("comboScope"));
        comboScope->setMaximumSize(QSize(140, 16777215));

        gridLayout->addWidget(comboScope, 3, 1, 1, 1);

        label_5 = new QLabel(gbProp);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        initValue = new QLineEdit(gbProp);
        initValue->setObjectName(QString::fromUtf8("initValue"));
        initValue->setMaximumSize(QSize(120, 16777215));
        initValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(initValue, 4, 1, 1, 1);

        comboFunc = new QComboBox(gbProp);
        comboFunc->setObjectName(QString::fromUtf8("comboFunc"));
        comboFunc->setMaximumSize(QSize(140, 16777215));

        gridLayout->addWidget(comboFunc, 2, 1, 1, 1);

        label_6 = new QLabel(gbProp);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        expression = new QLineEdit(gbProp);
        expression->setObjectName(QString::fromUtf8("expression"));

        gridLayout->addWidget(expression, 1, 1, 1, 1);


        vboxLayout->addWidget(gbProp);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);

        buttonBox = new QDialogButtonBox(NCRDVariableDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        hboxLayout1->addWidget(buttonBox);


        vboxLayout->addLayout(hboxLayout1);

        QWidget::setTabOrder(tableView, variableID);
        QWidget::setTabOrder(variableID, expression);
        QWidget::setTabOrder(expression, comboFunc);
        QWidget::setTabOrder(comboFunc, comboScope);
        QWidget::setTabOrder(comboScope, initValue);
        QWidget::setTabOrder(initValue, btnAdd);
        QWidget::setTabOrder(btnAdd, btnRemove);
        QWidget::setTabOrder(btnRemove, buttonBox);

        retranslateUi(NCRDVariableDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDVariableDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDVariableDialogUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(NCRDVariableDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDVariableDialogUI)
    {
        NCRDVariableDialogUI->setWindowTitle(QApplication::translate("NCRDVariableDialogUI", "Variable settings", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("NCRDVariableDialogUI", "Add", 0, QApplication::UnicodeUTF8));
        btnRemove->setText(QApplication::translate("NCRDVariableDialogUI", "Remove", 0, QApplication::UnicodeUTF8));
        gbProp->setTitle(QApplication::translate("NCRDVariableDialogUI", "Variable properties", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NCRDVariableDialogUI", "Variable ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NCRDVariableDialogUI", "Function type", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NCRDVariableDialogUI", "Reset scope", 0, QApplication::UnicodeUTF8));
        comboScope->clear();
        comboScope->insertItems(0, QStringList()
         << QApplication::translate("NCRDVariableDialogUI", "Report", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDVariableDialogUI", "Page", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDVariableDialogUI", "Group", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("NCRDVariableDialogUI", "Initial value", 0, QApplication::UnicodeUTF8));
        initValue->setText(QApplication::translate("NCRDVariableDialogUI", "0", 0, QApplication::UnicodeUTF8));
        comboFunc->clear();
        comboFunc->insertItems(0, QStringList()
         << QApplication::translate("NCRDVariableDialogUI", "COUNT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDVariableDialogUI", "SUM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDVariableDialogUI", "STD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDVariableDialogUI", "AVERAGE", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("NCRDVariableDialogUI", "Variable expression", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDVariableDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDVariableDialogUI: public Ui_NCRDVariableDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIABLEDIALOG_H
