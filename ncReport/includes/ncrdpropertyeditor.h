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
#ifndef NCRDPROPERTYEDITOR_H
#define NCRDPROPERTYEDITOR_H

#include <QDockWidget>
#include <QPointer>
#include <QItemDelegate>
#include <QSizeF>
#include <QPointF>
#include <QModelIndex>

#include "ncrdsectionscene.h"
#include "ncrddocument.h"

class QVBoxLayout;
class QLabel;
class QTableView;
class QStandardItemModel;
class QStandardItem;
class NCRDMainWindow;

/*!
This class provides for editing and representing the base properties of a report item or a report section.\n
It enables to show/edit the position and size of the objects mentioned above.
*/
class NCRDPropertyEditor : public QDockWidget
{
	Q_OBJECT
public:
    NCRDPropertyEditor( NCRDMainWindow * parent = 0, Qt::WindowFlags flags = 0 );
    ~NCRDPropertyEditor();
	
	void setDocument( NCRDDocument* );
	//void setScene( NCRDSectionScene* );
	void setSection( NCRDDesignSection* );
	void setItem( NCReportItem* );
	
	void setItemPropsEnabled( bool );
	void setSectionPropsEnabled( bool );
	bool isNumericRow( int ) const;
	
	NCRDDocument* document();

protected slots:
	void itemChanged( QStandardItem * item );
protected:	
	QWidget *dockWidgetContents;
	QVBoxLayout *vboxLayout;
	QLabel *label;
	QTableView *tableView;
	QStandardItemModel* model;
	
	NCRDMainWindow *m_mainwin;
	//QPointer<NCRDSectionScene> m_scene;
	QPointer<NCRDDesignSection> m_section;
	QPointer<NCRDDocument> m_doc;
	NCReportItem *m_item;
	bool m_InternalChange;
	
	void setupModel();
	void setSectionType( const QString& );
	void setSectionHeight( qreal h );
	void setItemName( const QString& );
	void setItemPosition( const QPointF& );
	void setItemSize( const QSizeF& );
};

/*!
Provides display and editing facilities for data items from a model within property editor
*/
class NCRDPropertyEditorItemDelegate : public QItemDelegate
{
public:
	NCRDPropertyEditorItemDelegate( NCRDPropertyEditor *parent );
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
	void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void paint( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
protected:
	void drawDisplay( QPainter *painter, const QStyleOptionViewItem &option, const QRect & rect, const QString & text ) const;
private:
	NCRDPropertyEditor *pEditor;
	int m_row, m_col;
};


#endif
