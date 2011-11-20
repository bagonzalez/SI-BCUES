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
#ifndef NCRDDETAILDIALOG_H
#define NCRDDETAILDIALOG_H

#include <QDialog>
#include <QStandardItem>
#include <QList>
#include <QItemDelegate>

#include "ui_detaildialog.h"

class QStandardItemModel;
class QDataWidgetMapper;
class NCRDDocument;
class NCReportSection;
class NCReportGroup;

/*!
Report Detail properties dialog class
*/
class NCRDDetailDialog : public QDialog, private Ui::NCRDDetailDialogUI
{
  Q_OBJECT

public:
  NCRDDetailDialog( NCRDDocument *doc, QWidget* parent = 0, Qt::WFlags fl = 0 );
  ~NCRDDetailDialog();
  /*$PUBLIC_FUNCTIONS$*/
  
	void applyChanges();
	void discardChanges();
	
	QComboBox *comboDS();

public slots:
  /*$PUBLIC_SLOTS$*/

protected:
  /*$PROTECTED_FUNCTIONS$*/

protected slots:
  /*$PROTECTED_SLOTS$*/
	void doGrouping();
	void add();
	void remove();
	void up();
	void down();
	
	void slotItemChanged( const QModelIndex & current, const QModelIndex & previous );

private:
	QStandardItemModel* model;
	QDataWidgetMapper *mapper;
	NCRDDocument *document;
	QList<NCReportSection*> removeDetails;
	
	void setupModel();
	void appendModel( NCReportSection*, int row, bool inew );
};


/*!
Custom model item for storing NCReportSection object pointer
*/
class NCRDStandardPointerItem : public QStandardItem
{
public:
	NCRDStandardPointerItem( NCReportSection *se, bool ins )
		: sect(se), insertedasnew(ins)
	{
	}
	
	~NCRDStandardPointerItem()
	{
	}
	
	void setSection( NCReportSection* se )
	{
		sect = se;
	}
	
	void setGroup( NCReportGroup* gr )
	{
		grp = gr;
	}
	
	NCReportGroup *group()
	{
		return grp;
	}
	
	NCReportSection *section()
	{
		return sect;
	}
	
	bool insertedAsNew()
	{
		return insertedasnew;
	}

private:
	NCReportSection *sect;
	NCReportGroup *grp;
	bool insertedasnew;
};

/*!
Item delegate class for providing display and editing facilities for detail's data items from a model.
*/
class NCRDDetailItemDelegate : public QItemDelegate
{
public:
	NCRDDetailItemDelegate( NCRDDetailDialog *parent );
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
protected:
	//void drawDisplay( QPainter *painter, const QStyleOptionViewItem &option, const QRect & rect, const QString & text ) const;
private:
	NCRDDetailDialog *dialog;
};


#endif

