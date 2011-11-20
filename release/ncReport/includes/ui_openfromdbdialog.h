/********************************************************************************
** Form generated from reading ui file 'openfromdbdialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OPENFROMDBDIALOG_H
#define UI_OPENFROMDBDIALOG_H

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
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NCRDOpenFromDBDialogUI
{
public:
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout1;
    QLabel *label;
    QComboBox *comboConn;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *tableName;
    QLabel *label_3;
    QLineEdit *reportColumn;
    QLabel *label_4;
    QLineEdit *keyValue;
    QLineEdit *keyColumn;
    QLabel *label_5;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDOpenFromDBDialogUI)
    {
        if (NCRDOpenFromDBDialogUI->objectName().isEmpty())
            NCRDOpenFromDBDialogUI->setObjectName(QString::fromUtf8("NCRDOpenFromDBDialogUI"));
        NCRDOpenFromDBDialogUI->resize(429, 195);
        hboxLayout = new QHBoxLayout(NCRDOpenFromDBDialogUI);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        label = new QLabel(NCRDOpenFromDBDialogUI);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        hboxLayout1->addWidget(label);

        comboConn = new QComboBox(NCRDOpenFromDBDialogUI);
        comboConn->setObjectName(QString::fromUtf8("comboConn"));

        hboxLayout1->addWidget(comboConn);


        vboxLayout->addLayout(hboxLayout1);

        groupBox = new QGroupBox(NCRDOpenFromDBDialogUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        tableName = new QLineEdit(groupBox);
        tableName->setObjectName(QString::fromUtf8("tableName"));

        gridLayout->addWidget(tableName, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        reportColumn = new QLineEdit(groupBox);
        reportColumn->setObjectName(QString::fromUtf8("reportColumn"));

        gridLayout->addWidget(reportColumn, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        keyValue = new QLineEdit(groupBox);
        keyValue->setObjectName(QString::fromUtf8("keyValue"));

        gridLayout->addWidget(keyValue, 3, 1, 1, 1);

        keyColumn = new QLineEdit(groupBox);
        keyColumn->setObjectName(QString::fromUtf8("keyColumn"));

        gridLayout->addWidget(keyColumn, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);


        vboxLayout->addWidget(groupBox);


        hboxLayout->addLayout(vboxLayout);

        buttonBox = new QDialogButtonBox(NCRDOpenFromDBDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        hboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(comboConn, tableName);
        QWidget::setTabOrder(tableName, reportColumn);
        QWidget::setTabOrder(reportColumn, keyColumn);
        QWidget::setTabOrder(keyColumn, keyValue);
        QWidget::setTabOrder(keyValue, buttonBox);

        retranslateUi(NCRDOpenFromDBDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDOpenFromDBDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDOpenFromDBDialogUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(NCRDOpenFromDBDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDOpenFromDBDialogUI)
    {
        NCRDOpenFromDBDialogUI->setWindowTitle(QApplication::translate("NCRDOpenFromDBDialogUI", "Open report from database", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NCRDOpenFromDBDialogUI", "Used connection:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NCRDOpenFromDBDialogUI", "Report location", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NCRDOpenFromDBDialogUI", "Table name:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NCRDOpenFromDBDialogUI", "Report column name:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NCRDOpenFromDBDialogUI", "Key value / ID:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NCRDOpenFromDBDialogUI", "Key column name:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDOpenFromDBDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDOpenFromDBDialogUI: public Ui_NCRDOpenFromDBDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENFROMDBDIALOG_H
