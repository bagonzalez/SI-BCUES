/********************************************************************************
** Form generated from reading ui file 'starterdialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STARTERDIALOG_H
#define UI_STARTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NCRDRunnerDialogUI
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *gbOutput;
    QVBoxLayout *vboxLayout;
    QRadioButton *rbPreview;
    QRadioButton *rbQtPreview;
    QRadioButton *rbPrinter;
    QRadioButton *rbPdf;
    QRadioButton *rbSvg;
    QDialogButtonBox *buttonBox;
    QGroupBox *gbParams;
    QHBoxLayout *hboxLayout;
    QTableWidget *tableParams;
    QVBoxLayout *vboxLayout1;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QSpacerItem *spacerItem;

    void setupUi(QDialog *NCRDRunnerDialogUI)
    {
        if (NCRDRunnerDialogUI->objectName().isEmpty())
            NCRDRunnerDialogUI->setObjectName(QString::fromUtf8("NCRDRunnerDialogUI"));
        NCRDRunnerDialogUI->resize(529, 385);
        verticalLayout = new QVBoxLayout(NCRDRunnerDialogUI);
        verticalLayout->setMargin(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gbOutput = new QGroupBox(NCRDRunnerDialogUI);
        gbOutput->setObjectName(QString::fromUtf8("gbOutput"));
        vboxLayout = new QVBoxLayout(gbOutput);
        vboxLayout->setSpacing(3);
        vboxLayout->setMargin(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        rbPreview = new QRadioButton(gbOutput);
        rbPreview->setObjectName(QString::fromUtf8("rbPreview"));

        vboxLayout->addWidget(rbPreview);

        rbQtPreview = new QRadioButton(gbOutput);
        rbQtPreview->setObjectName(QString::fromUtf8("rbQtPreview"));

        vboxLayout->addWidget(rbQtPreview);

        rbPrinter = new QRadioButton(gbOutput);
        rbPrinter->setObjectName(QString::fromUtf8("rbPrinter"));

        vboxLayout->addWidget(rbPrinter);

        rbPdf = new QRadioButton(gbOutput);
        rbPdf->setObjectName(QString::fromUtf8("rbPdf"));

        vboxLayout->addWidget(rbPdf);

        rbSvg = new QRadioButton(gbOutput);
        rbSvg->setObjectName(QString::fromUtf8("rbSvg"));

        vboxLayout->addWidget(rbSvg);


        horizontalLayout->addWidget(gbOutput);

        buttonBox = new QDialogButtonBox(NCRDRunnerDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);

        gbParams = new QGroupBox(NCRDRunnerDialogUI);
        gbParams->setObjectName(QString::fromUtf8("gbParams"));
        hboxLayout = new QHBoxLayout(gbParams);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        tableParams = new QTableWidget(gbParams);
        if (tableParams->columnCount() < 2)
            tableParams->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableParams->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableParams->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableParams->setObjectName(QString::fromUtf8("tableParams"));
        tableParams->horizontalHeader()->setDefaultSectionSize(200);

        hboxLayout->addWidget(tableParams);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        btnAdd = new QPushButton(gbParams);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        vboxLayout1->addWidget(btnAdd);

        btnRemove = new QPushButton(gbParams);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));

        vboxLayout1->addWidget(btnRemove);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem);


        hboxLayout->addLayout(vboxLayout1);


        verticalLayout->addWidget(gbParams);

        QWidget::setTabOrder(rbPreview, rbQtPreview);
        QWidget::setTabOrder(rbQtPreview, rbPrinter);
        QWidget::setTabOrder(rbPrinter, rbPdf);
        QWidget::setTabOrder(rbPdf, rbSvg);
        QWidget::setTabOrder(rbSvg, buttonBox);
        QWidget::setTabOrder(buttonBox, tableParams);
        QWidget::setTabOrder(tableParams, btnAdd);
        QWidget::setTabOrder(btnAdd, btnRemove);

        retranslateUi(NCRDRunnerDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDRunnerDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDRunnerDialogUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(NCRDRunnerDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDRunnerDialogUI)
    {
        NCRDRunnerDialogUI->setWindowTitle(QApplication::translate("NCRDRunnerDialogUI", "Run report", 0, QApplication::UnicodeUTF8));
        gbOutput->setTitle(QApplication::translate("NCRDRunnerDialogUI", "Output to", 0, QApplication::UnicodeUTF8));
        rbPreview->setText(QApplication::translate("NCRDRunnerDialogUI", "NCReport Preview", 0, QApplication::UnicodeUTF8));
        rbQtPreview->setText(QApplication::translate("NCRDRunnerDialogUI", "Qt preview", 0, QApplication::UnicodeUTF8));
        rbPrinter->setText(QApplication::translate("NCRDRunnerDialogUI", "Printer", 0, QApplication::UnicodeUTF8));
        rbPdf->setText(QApplication::translate("NCRDRunnerDialogUI", "PDF file", 0, QApplication::UnicodeUTF8));
        rbSvg->setText(QApplication::translate("NCRDRunnerDialogUI", "SVG file(s)", 0, QApplication::UnicodeUTF8));
        gbParams->setTitle(QApplication::translate("NCRDRunnerDialogUI", "Report parameters", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableParams->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("NCRDRunnerDialogUI", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableParams->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("NCRDRunnerDialogUI", "Value", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("NCRDRunnerDialogUI", "Add", 0, QApplication::UnicodeUTF8));
        btnRemove->setText(QApplication::translate("NCRDRunnerDialogUI", "Remove", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDRunnerDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDRunnerDialogUI: public Ui_NCRDRunnerDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTERDIALOG_H
