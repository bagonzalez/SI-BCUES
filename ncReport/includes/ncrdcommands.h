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
#ifndef NCRDCOMMANDS_H
#define NCRDCOMMANDS_H

#include "ncreportitem.h"

#include <QUndoCommand>
#include <QPointF>
#include <QList>
#include <QHash>

class NCRDSectionScene;
class NCReportItem;

class NCRDCommand : public QUndoCommand
{
public:
    NCRDCommand( NCReportItem* item, NCRDSectionScene *scene, QUndoCommand * parent );
	
	NCRDSectionScene *scene();
	NCReportItem *item();
	
protected:
    NCRDSectionScene *m_scene;
	NCReportItem *m_item;
};


class NCRDInsertItemCommand : public NCRDCommand
{
public:
    NCRDInsertItemCommand( NCReportItem* item, NCRDSectionScene *scene, const NCReportItemData::ObjectType type, const QPointF& pos, QUndoCommand *parent = 0);
    void undo();
    void redo();
	void setLine( const QLineF& );
	void setRect( const QRectF& );
private:
	NCReportItemData::ObjectType m_type;
	QPointF m_pos;
	QLineF m_line;
	QRectF m_rect;
	
	void insertItem();
	
};

class NCRDRemoveItemCommand : public NCRDCommand
{
public:
    NCRDRemoveItemCommand( const QList<QGraphicsItem*>& items, NCRDSectionScene *scene, QUndoCommand *parent = 0);
    void undo();
    void redo();
private:
	QList<QGraphicsItem*> m_items;
};

class NCRDMoveItemCommand : public NCRDCommand
{
public:
    NCRDMoveItemCommand( const QList<QGraphicsItem*>& items, NCRDSectionScene *scene, QUndoCommand *parent = 0);
    void undo();
    void redo();
	bool isValid();
private:
	bool initial;
	QPointF m_offset;
	QList<QGraphicsItem*> m_items;
	
	void moveBy( const QPointF& by );
};

class NCRDAlignItemCommand : public NCRDCommand
{
public:
	NCRDAlignItemCommand( NCRDSectionScene *scene, QUndoCommand *parent = 0 );
	
	class AlignPos { 
		public:
			AlignPos( const QPointF& pOld,  const QPointF& pNew ) : oldPos(pOld), newPos(pNew)
			{}
			QPointF oldPos;
			QPointF newPos;
	};
	class AlignSize { 
		public:
			AlignSize( const QSizeF& oldsize,  const QSizeF& newsize ) : oldSize(oldsize), newSize(newsize)
			{}
			QSizeF oldSize;
			QSizeF newSize;
	};
	enum AlignMode { NewPos, OldPos, NewSize, OldSize };
	
	void undo();
	void redo();
	void addItem( NCReportItem*, const QPointF& currentPos, const QPointF& newPos );
	void addItem( NCReportItem*, const QSizeF& currentSize, const QSizeF& newSize );
private:
	QHash<NCReportItem*,AlignPos> itemPosHash;
	QHash<NCReportItem*,AlignSize> itemSizeHash;

	void align( const AlignMode );
};


class NCRDResizeItemCommand : public NCRDCommand
{
public:
    NCRDResizeItemCommand( NCReportItem* item, NCRDSectionScene *scene, QUndoCommand *parent = 0);
/*	class Resize { 
		public:
			Resize( const QSizeF& os,  const QSizeF& ns ) : oldSize(os), newSize(ns)
			{}
			QSizeF oldSize;
			QSizeF newSize;
	};*/
	
    void undo();
    void redo();
private:
	bool initial;
	QPointF m_offset;
	QSizeF m_sizeChange;
	
	void resizeBy(const QSizeF & bySize, const QPointF & byPos);
};


#endif
