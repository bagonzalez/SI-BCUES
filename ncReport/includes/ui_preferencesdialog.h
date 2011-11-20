/********************************************************************************
** Form generated from reading ui file 'preferencesdialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PREFERENCESDIALOG_H
#define UI_PREFERENCESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NCRDPreferencesDialogUI
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox_3;
    QHBoxLayout *hboxLayout;
    QLabel *label_5;
    QLineEdit *pathReport;
    QToolButton *btnChooseDir;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QFontComboBox *comboFontFamily;
    QLabel *label_3;
    QComboBox *comboFontSize;
    QLineEdit *fontTest;
    QLabel *label_6;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QCheckBox *cbGridVisible;
    QLabel *label;
    QSpinBox *spGridX;
    QCheckBox *cbGridSnap;
    QLabel *label_2;
    QSpinBox *spGridY;
    QSpacerItem *spacerItem;
    QPushButton *btnGridReset;
    QSpacerItem *spacerItem1;
    QGroupBox *groupBox_4;
    QVBoxLayout *vboxLayout1;
    QCheckBox *cbShowMaximized;
    QDialogButtonBox *buttons;

    void setupUi(QDialog *NCRDPreferencesDialogUI)
    {
        if (NCRDPreferencesDialogUI->objectName().isEmpty())
            NCRDPreferencesDialogUI->setObjectName(QString::fromUtf8("NCRDPreferencesDialogUI"));
        NCRDPreferencesDialogUI->resize(475, 381);
        verticalLayout = new QVBoxLayout(NCRDPreferencesDialogUI);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox_3 = new QGroupBox(NCRDPreferencesDialogUI);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        hboxLayout = new QHBoxLayout(groupBox_3);
        hboxLayout->setSpacing(3);
        hboxLayout->setMargin(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        hboxLayout->addWidget(label_5);

        pathReport = new QLineEdit(groupBox_3);
        pathReport->setObjectName(QString::fromUtf8("pathReport"));

        hboxLayout->addWidget(pathReport);

        btnChooseDir = new QToolButton(groupBox_3);
        btnChooseDir->setObjectName(QString::fromUtf8("btnChooseDir"));
        btnChooseDir->setFocusPolicy(Qt::NoFocus);

        hboxLayout->addWidget(btnChooseDir);


        vboxLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(NCRDPreferencesDialogUI);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(3);
        gridLayout->setMargin(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        comboFontFamily = new QFontComboBox(groupBox_2);
        comboFontFamily->setObjectName(QString::fromUtf8("comboFontFamily"));

        gridLayout->addWidget(comboFontFamily, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        comboFontSize = new QComboBox(groupBox_2);
        comboFontSize->setObjectName(QString::fromUtf8("comboFontSize"));
        comboFontSize->setEditable(true);

        gridLayout->addWidget(comboFontSize, 1, 1, 1, 1);

        fontTest = new QLineEdit(groupBox_2);
        fontTest->setObjectName(QString::fromUtf8("fontTest"));

        gridLayout->addWidget(fontTest, 2, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);


        vboxLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(NCRDPreferencesDialogUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout1 = new QGridLayout(groupBox);
        gridLayout1->setSpacing(3);
        gridLayout1->setMargin(6);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        cbGridVisible = new QCheckBox(groupBox);
        cbGridVisible->setObjectName(QString::fromUtf8("cbGridVisible"));

        gridLayout1->addWidget(cbGridVisible, 0, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout1->addWidget(label, 0, 2, 1, 1);

        spGridX = new QSpinBox(groupBox);
        spGridX->setObjectName(QString::fromUtf8("spGridX"));

        gridLayout1->addWidget(spGridX, 0, 3, 1, 1);

        cbGridSnap = new QCheckBox(groupBox);
        cbGridSnap->setObjectName(QString::fromUtf8("cbGridSnap"));

        gridLayout1->addWidget(cbGridSnap, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout1->addWidget(label_2, 1, 2, 1, 1);

        spGridY = new QSpinBox(groupBox);
        spGridY->setObjectName(QString::fromUtf8("spGridY"));

        gridLayout1->addWidget(spGridY, 1, 3, 1, 1);

        spacerItem = new QSpacerItem(20, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem, 1, 1, 1, 1);

        btnGridReset = new QPushButton(groupBox);
        btnGridReset->setObjectName(QString::fromUtf8("btnGridReset"));

        gridLayout1->addWidget(btnGridReset, 1, 5, 1, 1);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem1, 1, 4, 1, 1);


        vboxLayout->addWidget(groupBox);

        groupBox_4 = new QGroupBox(NCRDPreferencesDialogUI);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        vboxLayout1 = new QVBoxLayout(groupBox_4);
        vboxLayout1->setSpacing(3);
        vboxLayout1->setMargin(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        cbShowMaximized = new QCheckBox(groupBox_4);
        cbShowMaximized->setObjectName(QString::fromUtf8("cbShowMaximized"));

        vboxLayout1->addWidget(cbShowMaximized);


        vboxLayout->addWidget(groupBox_4);


        verticalLayout->addLayout(vboxLayout);

        buttons = new QDialogButtonBox(NCRDPreferencesDialogUI);
        buttons->setObjectName(QString::fromUtf8("buttons"));
        buttons->setOrientation(Qt::Horizontal);
        buttons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttons);

        QWidget::setTabOrder(pathReport, comboFontFamily);
        QWidget::setTabOrder(comboFontFamily, comboFontSize);
        QWidget::setTabOrder(comboFontSize, fontTest);
        QWidget::setTabOrder(fontTest, cbGridVisible);
        QWidget::setTabOrder(cbGridVisible, cbGridSnap);
        QWidget::setTabOrder(cbGridSnap, spGridX);
        QWidget::setTabOrder(spGridX, spGridY);
        QWidget::setTabOrder(spGridY, cbShowMaximized);
        QWidget::setTabOrder(cbShowMaximized, btnChooseDir);
        QWidget::setTabOrder(btnChooseDir, buttons);

        retranslateUi(NCRDPreferencesDialogUI);
        QObject::connect(buttons, SIGNAL(accepted()), NCRDPreferencesDialogUI, SLOT(accept()));
        QObject::connect(buttons, SIGNAL(rejected()), NCRDPreferencesDialogUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(NCRDPreferencesDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDPreferencesDialogUI)
    {
        NCRDPreferencesDialogUI->setWindowTitle(QApplication::translate("NCRDPreferencesDialogUI", "Preferences", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("NCRDPreferencesDialogUI", "Default paths", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NCRDPreferencesDialogUI", "Report directory", 0, QApplication::UnicodeUTF8));
        btnChooseDir->setText(QApplication::translate("NCRDPreferencesDialogUI", "...", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("NCRDPreferencesDialogUI", "Default font", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NCRDPreferencesDialogUI", "Family", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NCRDPreferencesDialogUI", "Point size", 0, QApplication::UnicodeUTF8));
        fontTest->setText(QApplication::translate("NCRDPreferencesDialogUI", "AaBbZz", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NCRDPreferencesDialogUI", "Font sample", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NCRDPreferencesDialogUI", "Default grid", 0, QApplication::UnicodeUTF8));
        cbGridVisible->setText(QApplication::translate("NCRDPreferencesDialogUI", "Visible", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NCRDPreferencesDialogUI", "Grid X", 0, QApplication::UnicodeUTF8));
        cbGridSnap->setText(QApplication::translate("NCRDPreferencesDialogUI", "Snap to grid", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NCRDPreferencesDialogUI", "Grid Y", 0, QApplication::UnicodeUTF8));
        btnGridReset->setText(QApplication::translate("NCRDPreferencesDialogUI", "Reset grid", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("NCRDPreferencesDialogUI", "Misc settings", 0, QApplication::UnicodeUTF8));
        cbShowMaximized->setText(QApplication::translate("NCRDPreferencesDialogUI", "Open report windows maximized", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDPreferencesDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDPreferencesDialogUI: public Ui_NCRDPreferencesDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCESDIALOG_H
