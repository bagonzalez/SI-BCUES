/********************************************************************************
** Form generated from reading ui file 'clasesdecvs.ui'
**
** Created: Wed 13. Jan 21:51:12 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CLASESDECVS_H
#define UI_CLASESDECVS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clasesdecvs
{
public:
    QWidget *centralWidget;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *clasesdecvs)
    {
        if (clasesdecvs->objectName().isEmpty())
            clasesdecvs->setObjectName(QString::fromUtf8("clasesdecvs"));
        clasesdecvs->resize(600, 400);
        centralWidget = new QWidget(clasesdecvs);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(70, 60, 211, 22));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 180, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 120, 291, 16));
        clasesdecvs->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(clasesdecvs);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        clasesdecvs->setMenuBar(menuBar);
        mainToolBar = new QToolBar(clasesdecvs);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        clasesdecvs->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(clasesdecvs);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        clasesdecvs->setStatusBar(statusBar);

        retranslateUi(clasesdecvs);

        QMetaObject::connectSlotsByName(clasesdecvs);
    } // setupUi

    void retranslateUi(QMainWindow *clasesdecvs)
    {
        clasesdecvs->setWindowTitle(QApplication::translate("clasesdecvs", "clasesdecvs", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("clasesdecvs", "PushButton", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("clasesdecvs", "TextLabel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(clasesdecvs);
    } // retranslateUi

};

namespace Ui {
    class clasesdecvs: public Ui_clasesdecvs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASESDECVS_H
