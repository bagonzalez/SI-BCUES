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
#ifndef NCRDDATASOURCEDIALOG_H
#define NCRDDATASOURCEDIALOG_H

#include <QDialog>
#include "ui_datasourcedialog.h"

#include <QList>
#include <QStandardItem>
#include <QItemDelegate>
#include "ui_variabledialog.h"

class QStandardItemModel;
class QDataWidgetMapper;
class NCRDDocument;
class NCReportDataSource;
class QComboBox;

/*!
Datasource properties dialog class
*/
class NCRDDataSourceDialog : public QDialog, private Ui::NCRDDataSourceDialogUI
{
  Q_OBJECT
public:
  NCRDDataSourceDialog(NCRDDocument *doc, QWidget* parent = 0, Qt::WFlags fl = 0 );
  ~NCRDDataSourceDialog();
  /*$PUBLIC_FUNCTIONS$*/
	void applyChanges();
	void discardChanges();

	QComboBox *comboBoxDSType();
	QComboBox *comboBoxLocType();
	QComboBox *comboTxtColumnDelimiter();
	QComboBox *comboSlColumnDelimiter();
	QComboBox *comboOpenRole();
	public slots:
  /*$PUBLIC_SLOTS$*/

protected:
  /*$PROTECTED_FUNCTIONS$*/

protected slots:
  /*$PROTECTED_SLOTS$*/
	void add();
	void remove();
	void slotItemChanged( const QModelIndex & current, const QModelIndex & previous );
	void updateEnable();
	void textEditorContentChanged();
	void testExternalConnection();
private:
	QStandardItemModel* model;
	QDataWidgetMapper *mapper;
	NCRDDocument *document;
	QList<NCReportDataSource*> removeDatasources;
	
	void setupModel();
	void appendModel( NCReportDataSource*, int row, bool flagNew );
	
};

/*!
QStandardItem class for storing datasources 
*/
class NCRDDataSourceItem : public QStandardItem
{
public:
	NCRDDataSourceItem( NCReportDataSource *ds, bool flag )
		: datasource(ds), flagnew( flag )
	{
	}
	
	~NCRDDataSourceItem()
	{
	}
	
	bool flagNew()
	{
		return flagnew;
	}
	NCReportDataSource* dataSource()
	{
		return datasource;
	}
private:
	NCReportDataSource *datasource;
	bool flagnew;
};

/*!
Item delegate class for handling data widget delegation in Datasource dialog
*/
class NCRDDataSourceItemDelegate : public QItemDelegate
{
public:
	NCRDDataSourceItemDelegate( NCRDDataSourceDialog *parent );
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
	void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
protected:
	//void drawDisplay( QPainter *painter, const QStyleOptionViewItem &option, const QRect & rect, const QString & text ) const;
private:
	NCRDDataSourceDialog *dialog;
	
	bool isComboBox( const QModelIndex & index );
};


#endif

