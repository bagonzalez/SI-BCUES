/********************************************************************************
** Form generated from reading ui file 'textpropdialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TEXTPROPDIALOG_H
#define UI_TEXTPROPDIALOG_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ncrdprintwhenpanel.h"

QT_BEGIN_NAMESPACE

class Ui_NCRDTextPropDialogUI
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbImage;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboResource;
    QLabel *lblFile;
    QLineEdit *fileName;
    QToolButton *btnFile;
    QLabel *lblDSColumn;
    QLineEdit *dsColumn;
    QCheckBox *cbFix;
    QCheckBox *cbDefault;
    QCheckBox *cbAutoHeight;
    QCheckBox *cbDefaultFont;
    QCheckBox *cbTemplate;
    QTabWidget *tab;
    QWidget *tabDocument;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *_2;
    QFontComboBox *comboFont;
    QComboBox *comboSize;
    QToolButton *tbBold;
    QToolButton *tbItalic;
    QToolButton *tbUnderline;
    QToolButton *tbLeft;
    QToolButton *tbCenter;
    QToolButton *tbRight;
    QToolButton *tbColor;
    QSpacerItem *spacerItem;
    QTextEdit *textEdit;
    QCheckBox *cbAdjust;
    QWidget *tabHtml;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *htmlEdit;
    NCRDPrintWhenPanel *printWhenPanel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDTextPropDialogUI)
    {
        if (NCRDTextPropDialogUI->objectName().isEmpty())
            NCRDTextPropDialogUI->setObjectName(QString::fromUtf8("NCRDTextPropDialogUI"));
        NCRDTextPropDialogUI->resize(670, 607);
        vboxLayout = new QVBoxLayout(NCRDTextPropDialogUI);
        vboxLayout->setSpacing(3);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        gbImage = new QGroupBox(NCRDTextPropDialogUI);
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
        comboResource->setMaximumSize(QSize(250, 16777215));

        gridLayout->addWidget(comboResource, 0, 1, 1, 2);

        lblFile = new QLabel(gbImage);
        lblFile->setObjectName(QString::fromUtf8("lblFile"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblFile->sizePolicy().hasHeightForWidth());
        lblFile->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lblFile, 2, 0, 1, 1);

        fileName = new QLineEdit(gbImage);
        fileName->setObjectName(QString::fromUtf8("fileName"));

        gridLayout->addWidget(fileName, 2, 1, 1, 2);

        btnFile = new QToolButton(gbImage);
        btnFile->setObjectName(QString::fromUtf8("btnFile"));
        btnFile->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnFile, 2, 3, 1, 1);

        lblDSColumn = new QLabel(gbImage);
        lblDSColumn->setObjectName(QString::fromUtf8("lblDSColumn"));

        gridLayout->addWidget(lblDSColumn, 1, 0, 1, 1);

        dsColumn = new QLineEdit(gbImage);
        dsColumn->setObjectName(QString::fromUtf8("dsColumn"));

        gridLayout->addWidget(dsColumn, 1, 1, 1, 3);

        cbFix = new QCheckBox(gbImage);
        cbFix->setObjectName(QString::fromUtf8("cbFix"));

        gridLayout->addWidget(cbFix, 4, 0, 1, 2);

        cbDefault = new QCheckBox(gbImage);
        cbDefault->setObjectName(QString::fromUtf8("cbDefault"));

        gridLayout->addWidget(cbDefault, 5, 0, 1, 1);

        cbAutoHeight = new QCheckBox(gbImage);
        cbAutoHeight->setObjectName(QString::fromUtf8("cbAutoHeight"));

        gridLayout->addWidget(cbAutoHeight, 3, 0, 1, 2);

        cbDefaultFont = new QCheckBox(gbImage);
        cbDefaultFont->setObjectName(QString::fromUtf8("cbDefaultFont"));

        gridLayout->addWidget(cbDefaultFont, 3, 2, 1, 1);

        cbTemplate = new QCheckBox(gbImage);
        cbTemplate->setObjectName(QString::fromUtf8("cbTemplate"));

        gridLayout->addWidget(cbTemplate, 4, 2, 1, 1);


        vboxLayout->addWidget(gbImage);

        tab = new QTabWidget(NCRDTextPropDialogUI);
        tab->setObjectName(QString::fromUtf8("tab"));
        tabDocument = new QWidget();
        tabDocument->setObjectName(QString::fromUtf8("tabDocument"));
        verticalLayout = new QVBoxLayout(tabDocument);
        verticalLayout->setSpacing(3);
        verticalLayout->setMargin(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        _2 = new QHBoxLayout();
        _2->setSpacing(2);
        _2->setObjectName(QString::fromUtf8("_2"));
        comboFont = new QFontComboBox(tabDocument);
        comboFont->setObjectName(QString::fromUtf8("comboFont"));
        comboFont->setFocusPolicy(Qt::NoFocus);

        _2->addWidget(comboFont);

        comboSize = new QComboBox(tabDocument);
        comboSize->setObjectName(QString::fromUtf8("comboSize"));
        comboSize->setFocusPolicy(Qt::NoFocus);
        comboSize->setEditable(true);

        _2->addWidget(comboSize);

        tbBold = new QToolButton(tabDocument);
        tbBold->setObjectName(QString::fromUtf8("tbBold"));
        tbBold->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/text_bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbBold->setIcon(icon);
        tbBold->setCheckable(true);

        _2->addWidget(tbBold);

        tbItalic = new QToolButton(tabDocument);
        tbItalic->setObjectName(QString::fromUtf8("tbItalic"));
        tbItalic->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/text_italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbItalic->setIcon(icon1);
        tbItalic->setCheckable(true);

        _2->addWidget(tbItalic);

        tbUnderline = new QToolButton(tabDocument);
        tbUnderline->setObjectName(QString::fromUtf8("tbUnderline"));
        tbUnderline->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/text_underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbUnderline->setIcon(icon2);
        tbUnderline->setCheckable(true);

        _2->addWidget(tbUnderline);

        tbLeft = new QToolButton(tabDocument);
        tbLeft->setObjectName(QString::fromUtf8("tbLeft"));
        tbLeft->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/text_align_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbLeft->setIcon(icon3);
        tbLeft->setCheckable(true);

        _2->addWidget(tbLeft);

        tbCenter = new QToolButton(tabDocument);
        tbCenter->setObjectName(QString::fromUtf8("tbCenter"));
        tbCenter->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/text_align_center.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbCenter->setIcon(icon4);
        tbCenter->setCheckable(true);

        _2->addWidget(tbCenter);

        tbRight = new QToolButton(tabDocument);
        tbRight->setObjectName(QString::fromUtf8("tbRight"));
        tbRight->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/text_align_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbRight->setIcon(icon5);
        tbRight->setCheckable(true);

        _2->addWidget(tbRight);

        tbColor = new QToolButton(tabDocument);
        tbColor->setObjectName(QString::fromUtf8("tbColor"));
        tbColor->setFocusPolicy(Qt::NoFocus);

        _2->addWidget(tbColor);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(spacerItem);


        verticalLayout->addLayout(_2);

        textEdit = new QTextEdit(tabDocument);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        cbAdjust = new QCheckBox(tabDocument);
        cbAdjust->setObjectName(QString::fromUtf8("cbAdjust"));

        verticalLayout->addWidget(cbAdjust);

        tab->addTab(tabDocument, QString());
        tabHtml = new QWidget();
        tabHtml->setObjectName(QString::fromUtf8("tabHtml"));
        verticalLayout_2 = new QVBoxLayout(tabHtml);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setMargin(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        htmlEdit = new QTextEdit(tabHtml);
        htmlEdit->setObjectName(QString::fromUtf8("htmlEdit"));
        htmlEdit->setLineWrapMode(QTextEdit::NoWrap);
        htmlEdit->setAcceptRichText(false);

        verticalLayout_2->addWidget(htmlEdit);

        tab->addTab(tabHtml, QString());

        vboxLayout->addWidget(tab);

        printWhenPanel = new NCRDPrintWhenPanel(NCRDTextPropDialogUI);
        printWhenPanel->setObjectName(QString::fromUtf8("printWhenPanel"));

        vboxLayout->addWidget(printWhenPanel);

        buttonBox = new QDialogButtonBox(NCRDTextPropDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(comboResource, dsColumn);
        QWidget::setTabOrder(dsColumn, fileName);
        QWidget::setTabOrder(fileName, cbAutoHeight);
        QWidget::setTabOrder(cbAutoHeight, cbFix);
        QWidget::setTabOrder(cbFix, cbDefault);
        QWidget::setTabOrder(cbDefault, cbDefaultFont);
        QWidget::setTabOrder(cbDefaultFont, cbTemplate);
        QWidget::setTabOrder(cbTemplate, tab);
        QWidget::setTabOrder(tab, textEdit);
        QWidget::setTabOrder(textEdit, cbAdjust);
        QWidget::setTabOrder(cbAdjust, buttonBox);
        QWidget::setTabOrder(buttonBox, htmlEdit);

        retranslateUi(NCRDTextPropDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDTextPropDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDTextPropDialogUI, SLOT(reject()));

        tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(NCRDTextPropDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDTextPropDialogUI)
    {
        NCRDTextPropDialogUI->setWindowTitle(QApplication::translate("NCRDTextPropDialogUI", "Text properties", 0, QApplication::UnicodeUTF8));
        gbImage->setTitle(QApplication::translate("NCRDTextPropDialogUI", "Text options", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NCRDTextPropDialogUI", "Text source type:", 0, QApplication::UnicodeUTF8));
        comboResource->clear();
        comboResource->insertItems(0, QStringList()
         << QApplication::translate("NCRDTextPropDialogUI", "Static", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDTextPropDialogUI", "Datasource", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDTextPropDialogUI", "File", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDTextPropDialogUI", "File name from datasource", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDTextPropDialogUI", "Custom added", 0, QApplication::UnicodeUTF8)
        );
        lblFile->setText(QApplication::translate("NCRDTextPropDialogUI", "Text file:", 0, QApplication::UnicodeUTF8));
        btnFile->setText(QApplication::translate("NCRDTextPropDialogUI", "...", 0, QApplication::UnicodeUTF8));
        lblDSColumn->setText(QApplication::translate("NCRDTextPropDialogUI", "Text column expression:", 0, QApplication::UnicodeUTF8));
        cbFix->setText(QApplication::translate("NCRDTextPropDialogUI", "Size correction (Fixing height)", 0, QApplication::UnicodeUTF8));
        cbDefault->setText(QApplication::translate("NCRDTextPropDialogUI", "Default size and margins", 0, QApplication::UnicodeUTF8));
        cbAutoHeight->setText(QApplication::translate("NCRDTextPropDialogUI", "Automatic height", 0, QApplication::UnicodeUTF8));
        cbDefaultFont->setText(QApplication::translate("NCRDTextPropDialogUI", "Use system font settings", 0, QApplication::UnicodeUTF8));
        cbTemplate->setText(QApplication::translate("NCRDTextPropDialogUI", "Template mode", 0, QApplication::UnicodeUTF8));
        cbAdjust->setText(QApplication::translate("NCRDTextPropDialogUI", "Adjust item's size in designer", 0, QApplication::UnicodeUTF8));
        tab->setTabText(tab->indexOf(tabDocument), QApplication::translate("NCRDTextPropDialogUI", "Text", 0, QApplication::UnicodeUTF8));
        tab->setTabText(tab->indexOf(tabHtml), QApplication::translate("NCRDTextPropDialogUI", "HTML code", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDTextPropDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDTextPropDialogUI: public Ui_NCRDTextPropDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTPROPDIALOG_H
