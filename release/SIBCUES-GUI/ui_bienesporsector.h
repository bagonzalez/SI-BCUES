/********************************************************************************
** Form generated from reading UI file 'bienesporsector.ui'
**
** Created: Sun 3. Jul 09:58:25 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIENESPORSECTOR_H
#define UI_BIENESPORSECTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BienesporSector
{
public:
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *descripSector;
    QLabel *label_2;
    QComboBox *anioSelecc;
    QPushButton *btnCancelar;
    QPushButton *btnVerReporte;

    void setupUi(QDialog *BienesporSector)
    {
        if (BienesporSector->objectName().isEmpty())
            BienesporSector->setObjectName(QString::fromUtf8("BienesporSector"));
        BienesporSector->resize(388, 179);
        groupBox = new QGroupBox(BienesporSector);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 331, 101));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        descripSector = new QComboBox(groupBox);
        descripSector->setObjectName(QString::fromUtf8("descripSector"));

        formLayout->setWidget(0, QFormLayout::FieldRole, descripSector);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        anioSelecc = new QComboBox(groupBox);
        anioSelecc->setObjectName(QString::fromUtf8("anioSelecc"));

        formLayout->setWidget(1, QFormLayout::FieldRole, anioSelecc);

        btnCancelar = new QPushButton(BienesporSector);
        btnCancelar->setObjectName(QString::fromUtf8("btnCancelar"));
        btnCancelar->setGeometry(QRect(280, 140, 75, 23));
        btnVerReporte = new QPushButton(BienesporSector);
        btnVerReporte->setObjectName(QString::fromUtf8("btnVerReporte"));
        btnVerReporte->setGeometry(QRect(190, 140, 75, 23));

        retranslateUi(BienesporSector);

        QMetaObject::connectSlotsByName(BienesporSector);
    } // setupUi

    void retranslateUi(QDialog *BienesporSector)
    {
        BienesporSector->setWindowTitle(QApplication::translate("BienesporSector", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BienesporSector", "Reporte de bienes de activo fijo por sectores", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BienesporSector", "Sector:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BienesporSector", "A\303\261o Inventario:", 0, QApplication::UnicodeUTF8));
        btnCancelar->setText(QApplication::translate("BienesporSector", "Cancelar", 0, QApplication::UnicodeUTF8));
        btnVerReporte->setText(QApplication::translate("BienesporSector", "Ver Reporte", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BienesporSector: public Ui_BienesporSector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIENESPORSECTOR_H
