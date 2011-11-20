/********************************************************************************
** Form generated from reading UI file 'progresoreporte.ui'
**
** Created: Mon 19. Jul 20:18:11 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESOREPORTE_H
#define UI_PROGRESOREPORTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_progresoReporte
{
public:
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    QLabel *progresoText;

    void setupUi(QDialog *progresoReporte)
    {
        if (progresoReporte->objectName().isEmpty())
            progresoReporte->setObjectName(QString::fromUtf8("progresoReporte"));
        progresoReporte->resize(478, 85);
        verticalLayout = new QVBoxLayout(progresoReporte);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        progressBar = new QProgressBar(progresoReporte);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        progresoText = new QLabel(progresoReporte);
        progresoText->setObjectName(QString::fromUtf8("progresoText"));
        progresoText->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(progresoText);


        retranslateUi(progresoReporte);

        QMetaObject::connectSlotsByName(progresoReporte);
    } // setupUi

    void retranslateUi(QDialog *progresoReporte)
    {
        progresoReporte->setWindowTitle(QApplication::translate("progresoReporte", "Generando Reporte...", 0, QApplication::UnicodeUTF8));
        progresoText->setText(QApplication::translate("progresoReporte", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class progresoReporte: public Ui_progresoReporte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESOREPORTE_H
