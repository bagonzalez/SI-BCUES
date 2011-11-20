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
#ifndef NCRDTESTDATAWINDOW_H
#define NCRDTESTDATAWINDOW_H

#include <QMainWindow>
#include <QItemDelegate>
#include "ui_testdatawindow.h"

class QStandardItemModel;
class QDataWidgetMapper;
class NCReport;

/*! Test data editor main window for NCReport Designer */
class NCRDTestDataWindow : public QMainWindow, private Ui::NCRDTestDataWindowUI
{
  Q_OBJECT

public:
	NCRDTestDataWindow(QWidget* parent = 0, Qt::WFlags fl = 0 );
	~NCRDTestDataWindow();
	/*$PUBLIC_FUNCTIONS$*/
  
	QComboBox *comboBoxType();
	static bool generateTestData( const QString& fname, NCReport* report );
	static const QString defaultTestDataFile();
	
public slots:
  /*$PUBLIC_SLOTS$*/
	void newData();
	void openData();
	void saveData();
	void saveAsData();
	
	void addData();
	void removeData();
	void addRow();
	void insertRow();
	void removeRow();
	void addCol();
	void insertCol();
	void removeCol();
	
	void columnChange( int columnno );
	void refreshWidgets();
	/*! Load table's content from a tab separated text file*/
	void loadTableFromTextFile();

private:
	QStandardItemModel* model;
	QDataWidgetMapper *mapper;
	QString currentFileName;
	bool m_changed;
	bool m_internalChange;
	
	bool load( const QString& filename );
	bool save( const QString& filename );
	void addRow( bool insert );
	void updateLabels();
	void loadData();
	/*! Load table's content from a tab separated QString*/
	void loadTable( const QString& );
	void addTableRow( const QString& line );
	QString tableDataToString() const;
	
	void updateEnable();
	void writeSettings();
	void readSettings();
	void updateWindowTitle();
	bool maybeSave();

protected slots:
  /*$PROTECTED_SLOTS$*/
	void slotItemChanged( const QModelIndex & current, const QModelIndex & previous );
	void slotDataChanged( bool =true );

protected:
	void closeEvent(QCloseEvent *);
};


class NCRDTestDataItemDelegate : public QItemDelegate
{
public:
	NCRDTestDataItemDelegate( NCRDTestDataWindow *parent );
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
private:
	NCRDTestDataWindow *window;
};


#endif

