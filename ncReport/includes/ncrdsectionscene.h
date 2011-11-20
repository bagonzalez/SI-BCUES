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
#ifndef NCRDSECTIONSCENE_H
#define NCRDSECTIONSCENE_H

#include "ncreportsection.h"
#include <QLineF>
#include <QRectF>  

class NCReportItem;
class NCRDMainWindow;
class NCRDDocument;
class QGraphicsLineItem;
class QGraphicsRectItem;

/*!
This class represents the graphics scene of a report section for the designer.\n
*/
class NCRDSectionScene : public NCReportSection
{
	Q_OBJECT
public:
    NCRDSectionScene( NCRDMainWindow *mw, NCRDDocument * doc, QObject* parent );
    ~NCRDSectionScene();

	void setEditorMode();
	void emitContentChanged();
	void emitItemChanged( NCReportItem* );
	
	void insertItemCommand( const QPointF& pos);
	void removeItemCommand( NCReportItem*, bool removeSelected = true );
	void moveItemCommand( NCReportItem*, bool moveSelected = true );
	void resizeItemCommand( NCReportItem* );
	NCReportItem* firstSelectedItem();
	NCRDMainWindow *mainWindow();
	void keyboardAction( QKeyEvent* );
	void addItemZ( NCReportItem* );
	void addItemForEngine( NCReportItem* );
	
signals:
	void itemRightClicked( NCReportItem* );
	void firstItemSelected( NCReportItem* );			
	
public slots:
	void slotSelectionChanged();
	void actionManagerChanged();
	
protected:
	void contextMenuEvent(QGraphicsSceneContextMenuEvent*);
	void mousePressEvent( QGraphicsSceneMouseEvent* );
 	void mouseDoubleClickEvent( QGraphicsSceneMouseEvent * );
	void mouseReleaseEvent( QGraphicsSceneMouseEvent* );
	void mouseMoveEvent( QGraphicsSceneMouseEvent * );
	void keyPressEvent( QKeyEvent * keyEvent );
	void keyReleaseEvent( QKeyEvent * keyEvent );
	void wheelEvent( QGraphicsSceneWheelEvent* );
	//void focusInEvent( QFocusEvent * focusEvent );	
	
 	void drawBackground( QPainter * painter, const QRectF & rect );
	void paintGrid( QPainter* p );
	
private:
	NCRDMainWindow *m_mainwin;
	NCRDDocument *m_document;
	NCReportItem *m_lastInsertedItem;
	NCReportItem *m_firstSelectedItem;
	QGraphicsLineItem *insertingLineItem;
	QGraphicsRectItem *insertingRectItem;
	QLineF adjustLine( const QLineF& ) const;
};

#endif
