/********************************************************************************
** Form generated from reading ui file 'sqlconndialog.ui'
**
** Created: Sat Aug 29 18:01:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SQLCONNDIALOG_H
#define UI_SQLCONNDIALOG_H

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
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NCRDSqlConnectionDialogUI
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *layForm;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListView *listConns;
    QHBoxLayout *layBtn;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QGroupBox *gbConn;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QComboBox *comboDriver;
    QSpacerItem *sp2;
    QLabel *label_4;
    QLineEdit *host;
    QLabel *label_3;
    QLineEdit *dbname;
    QLabel *label_5;
    QLineEdit *username;
    QLabel *label_6;
    QLineEdit *password;
    QLabel *label_7;
    QLineEdit *port;
    QLabel *label_8;
    QLabel *lblStatus;
    QLabel *label_10;
    QLineEdit *name;
    QPushButton *btnConnect;
    QSpacerItem *sp1;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NCRDSqlConnectionDialogUI)
    {
        if (NCRDSqlConnectionDialogUI->objectName().isEmpty())
            NCRDSqlConnectionDialogUI->setObjectName(QString::fromUtf8("NCRDSqlConnectionDialogUI"));
        NCRDSqlConnectionDialogUI->setWindowModality(Qt::ApplicationModal);
        NCRDSqlConnectionDialogUI->resize(545, 358);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Helvetica"));
        NCRDSqlConnectionDialogUI->setFont(font);
        verticalLayout_2 = new QVBoxLayout(NCRDSqlConnectionDialogUI);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        layForm = new QHBoxLayout();
        layForm->setSpacing(3);
        layForm->setObjectName(QString::fromUtf8("layForm"));
        groupBox = new QGroupBox(NCRDSqlConnectionDialogUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listConns = new QListView(groupBox);
        listConns->setObjectName(QString::fromUtf8("listConns"));

        verticalLayout->addWidget(listConns);

        layBtn = new QHBoxLayout();
        layBtn->setSpacing(3);
        layBtn->setObjectName(QString::fromUtf8("layBtn"));
        btnAdd = new QPushButton(groupBox);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        layBtn->addWidget(btnAdd);

        btnRemove = new QPushButton(groupBox);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));

        layBtn->addWidget(btnRemove);


        verticalLayout->addLayout(layBtn);


        layForm->addWidget(groupBox);

        gbConn = new QGroupBox(NCRDSqlConnectionDialogUI);
        gbConn->setObjectName(QString::fromUtf8("gbConn"));
        gridLayout = new QGridLayout(gbConn);
        gridLayout->setSpacing(3);
        gridLayout->setMargin(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(gbConn);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        comboDriver = new QComboBox(gbConn);
        comboDriver->setObjectName(QString::fromUtf8("comboDriver"));

        gridLayout->addWidget(comboDriver, 0, 1, 1, 1);

        sp2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(sp2, 1, 0, 1, 1);

        label_4 = new QLabel(gbConn);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        host = new QLineEdit(gbConn);
        host->setObjectName(QString::fromUtf8("host"));

        gridLayout->addWidget(host, 3, 1, 1, 1);

        label_3 = new QLabel(gbConn);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        dbname = new QLineEdit(gbConn);
        dbname->setObjectName(QString::fromUtf8("dbname"));

        gridLayout->addWidget(dbname, 4, 1, 1, 1);

        label_5 = new QLabel(gbConn);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        username = new QLineEdit(gbConn);
        username->setObjectName(QString::fromUtf8("username"));

        gridLayout->addWidget(username, 5, 1, 1, 1);

        label_6 = new QLabel(gbConn);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        password = new QLineEdit(gbConn);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(password, 6, 1, 1, 1);

        label_7 = new QLabel(gbConn);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        port = new QLineEdit(gbConn);
        port->setObjectName(QString::fromUtf8("port"));
        port->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(port, 7, 1, 1, 1);

        label_8 = new QLabel(gbConn);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        lblStatus = new QLabel(gbConn);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));

        gridLayout->addWidget(lblStatus, 8, 1, 1, 1);

        label_10 = new QLabel(gbConn);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        name = new QLineEdit(gbConn);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 2, 1, 1, 1);

        btnConnect = new QPushButton(gbConn);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConnect->setIcon(icon);
        btnConnect->setCheckable(true);
        btnConnect->setAutoDefault(false);

        gridLayout->addWidget(btnConnect, 9, 1, 1, 1);

        sp1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(sp1, 10, 1, 1, 1);


        layForm->addWidget(gbConn);

        layForm->setStretch(0, 1);
        layForm->setStretch(1, 3);

        verticalLayout_2->addLayout(layForm);

        buttonBox = new QDialogButtonBox(NCRDSqlConnectionDialogUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

        QWidget::setTabOrder(listConns, comboDriver);
        QWidget::setTabOrder(comboDriver, name);
        QWidget::setTabOrder(name, host);
        QWidget::setTabOrder(host, dbname);
        QWidget::setTabOrder(dbname, username);
        QWidget::setTabOrder(username, password);
        QWidget::setTabOrder(password, port);

        retranslateUi(NCRDSqlConnectionDialogUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), NCRDSqlConnectionDialogUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NCRDSqlConnectionDialogUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(NCRDSqlConnectionDialogUI);
    } // setupUi

    void retranslateUi(QDialog *NCRDSqlConnectionDialogUI)
    {
        NCRDSqlConnectionDialogUI->setWindowTitle(QApplication::translate("NCRDSqlConnectionDialogUI", "Database connections", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NCRDSqlConnectionDialogUI", "Connections", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("NCRDSqlConnectionDialogUI", "Add", 0, QApplication::UnicodeUTF8));
        btnRemove->setText(QApplication::translate("NCRDSqlConnectionDialogUI", "Remove", 0, QApplication::UnicodeUTF8));
        gbConn->setTitle(QApplication::translate("NCRDSqlConnectionDialogUI", "Connection properties", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NCRDSqlConnectionDialogUI", "Database driver", 0, QApplication::UnicodeUTF8));
        comboDriver->clear();
        comboDriver->insertItems(0, QStringList()
         << QApplication::translate("NCRDSqlConnectionDialogUI", "QDB2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDSqlConnectionDialogUI", "QIBASE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDSqlConnectionDialogUI", "QMYSQL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDSqlConnectionDialogUI", "QOCI", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDSqlConnectionDialogUI", "QODBC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDSqlConnectionDialogUI", "QPSQL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDSqlConnectionDialogUI", "QSQLITE2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDSqlConnectionDialogUI", "QSQLITE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NCRDSqlConnectionDialogUI", "QTDS", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("NCRDSqlConnectionDialogUI", "Host name (IP address)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NCRDSqlConnectionDialogUI", "Database name", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NCRDSqlConnectionDialogUI", "Username", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NCRDSqlConnectionDialogUI", "Password", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("NCRDSqlConnectionDialogUI", "Port", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("NCRDSqlConnectionDialogUI", "Status", 0, QApplication::UnicodeUTF8));
        lblStatus->setText(QApplication::translate("NCRDSqlConnectionDialogUI", "Disconnected", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("NCRDSqlConnectionDialogUI", "Connection name", 0, QApplication::UnicodeUTF8));
        btnConnect->setText(QApplication::translate("NCRDSqlConnectionDialogUI", "Connect", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NCRDSqlConnectionDialogUI);
    } // retranslateUi

};

namespace Ui {
    class NCRDSqlConnectionDialogUI: public Ui_NCRDSqlConnectionDialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLCONNDIALOG_H
