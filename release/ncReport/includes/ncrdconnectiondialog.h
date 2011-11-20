/****************************************************************************
* 
*  Copyright (C) 2002-2008 Helta Kft. / NociSoft Software Solutions
*  All rights reserved.
*  Author: Norbert Szabo
*  E-mail: nszabo@helta.hu, info@nocisoft.com
*  Web: www.nocisoft.com
* 
*  This file is part of the NCReport reporting software
* 
*  Licensees holding a valid NCReport License Agreement may use this
*  file in accordance with the rights, responsibilities, and obligations
*  contained therein. Please consult your licensing agreement or contact
*  nszabo@helta.hu if any conditions of this licensing are not clear
*  to you.
* 
*  This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
*  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
****************************************************************************/
#ifndef NCRDCONNECTIONDIALOG_H
#define NCRDCONNECTIONDIALOG_H

#include "ui_sqlconndialog.h"

#include <QDialog>
#include <QItemDelegate>

class QStandardItemModel;
class QDataWidgetMapper;
class NCRDMainWindow;
class QComboBox;

static const char* const _drivers[] = 
{ "QDB2","QIBASE","QMYSQL","QOCI","QODBC","QPSQL","QSQLITE2","QSQLITE","QTDS" }; 

/*!
SQL connection structure
*/
struct NCRDConnection 
{
	QString name;
	int driver;
	QString host;
	QString database;
	QString user;
	QString password;
	QString port;
	bool connected;
};

/*!
SQL Connection properties dialog class
*/
class NCRDConnectionDialog : public QDialog, private Ui::NCRDSqlConnectionDialogUI
{
  Q_OBJECT

public:
  NCRDConnectionDialog( NCRDMainWindow *mw = 0, QWidget* parent = 0, Qt::WFlags fl = 0 );
  ~NCRDConnectionDialog();
  /*$PUBLIC_FUNCTIONS$*/
	void applyChanges();
	void discardChanges();
	
	QComboBox* comboBoxDriver();
	static bool connectDatabase( const NCRDConnection& con, QString& msg );
	static bool disconnectDatabase( const QString& cname );

public slots:
  /*$PUBLIC_SLOTS$*/

protected:
  /*$PROTECTED_FUNCTIONS$*/

protected slots:
  /*$PROTECTED_SLOTS$*/
	void add();
	void remove();
	void slotItemChanged( const QModelIndex & current, const QModelIndex & previous );
	bool connectDB( bool );

private:
	QStandardItemModel* model;
	QDataWidgetMapper *mapper;
	NCRDMainWindow *mainwindow;
	QStringList removeConns;
	
	void setupModel();
	void appendModel( const NCRDConnection&, int row, bool flagNew );
	void updateEnable();
	void updateConnectText();

};

class NCRDConnectionItemDelegate : public QItemDelegate
{
public:
	NCRDConnectionItemDelegate( NCRDConnectionDialog *parent );
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
private:
	NCRDConnectionDialog *dialog;
};


#endif

