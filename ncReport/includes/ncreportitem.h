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
#ifndef NCREPORTITEM_H
#define NCREPORTITEM_H

#include "ncreportdata.h"
#include <QGraphicsItem>

class NCReportXMLReader;
class NCReportXMLWriter;
class NCReportOutput;
class QGraphicsSceneMouseEvent;
class NCReportSection;
class QPaintDevice;

#define SELECTION_BOXSIZE		5.0


/*!
This class represents the base (abstract) report item's data class
 */
class NCReportItemData : public NCReportData
{
public:
	NCReportItemData();
	virtual ~NCReportItemData(); 
	//QString etype;
	enum ObjectType { Label, Field, Text, Line, Rectangle, Ellipse, Image, Barcode, Graph, Custom, Invalid };
	enum ItemSourceType { Static=0, DataSource, File, FileNameFromDataSource, CustomAdded }; 
	//enum ItemSourceType { Static=0, DataSource, File, FileNameFromDataSource, 
	//		Template, TemplateDataSource, TemplateFile, TemplateFileNameFromDataSource }; 

	enum FitRole { NoFit=0, FitHeightToSection, FitHeightToZone };

	ObjectType objectType;
	ItemSourceType ist;
	QString tagname;
	QString id;
	QString text;
	QString printWhen;
	QString description;
	bool printDone;
	bool autoHeight;
	FitRole fitRole;
	
	// metric position/size in mm
	QPointF mPos;
	//QPointF mPosBak;		// position for backup
	QPointF mOffset;		// offset pos for Zone handling
	QSizeF mSize;			// fixed size in mm
	QSizeF mRealSize;		// real or required size in mm (for Label, Text)
	QSizeF mSectionSize;	// size of the current section
	QSizeF mZoneSize;		// size of the current zone (inside the section)

	QSizeF currentSize, lastSize;	// size in scene
	QPointF currentScenePos, lastScenePos;
	bool unfinished;
	bool templateMode;
	int zoneID;
	bool adjusted;
	bool printWhenResult;	// for internal usage
};

/*!
This class represents the base (abstract) report item class
 */
class NCReportItem : public QGraphicsItem
{
public:
 	NCReportItem( QGraphicsItem* parent =0 );
 	virtual ~NCReportItem();
	
	enum SelectionDirection { LeftTop=0, Top, RightTop, Right, RightBottom, Bottom, LeftBottom, Left, None };
	
	NCReportItemData* data();
	NCReportSection *sectionScene();
	virtual QRectF boundingRect() const;
	virtual int type() const =0;
	virtual void setSnapPos( const QPointF& );
	virtual void resize( const QSizeF& );
	virtual void resizeInMM( const QSizeF& );
	virtual const QSizeF currentSize() const;
	virtual const QSizeF lastSize() const;
	virtual const QPointF lastPos() const;
	SelectionDirection selectionHoverState() const;
	/*!Size hint for designer*/
	virtual QSizeF sizeHint() const;
	/*! adjust size for designer */
	virtual void adjustSize();
	/*! adjust size for report rendering */
	virtual void adjustSize( NCReportOutput* );
	virtual QSizeF sizeMM() const;
	/*! Returns the real/required size in mm for item. Use adjustSize() before. */
	virtual QSizeF realSizeMM() const;
	virtual void offsetPastePos();
	
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) =0;
	virtual bool read( NCReportXMLReader* );
	virtual bool write( NCReportXMLWriter* );
	/*!Set default settings for editor when add as new item*/
	virtual void setDefaultForEditor()=0;
	/*!Updates its settings for editor after load*/
	virtual void updateForEditor();
	/*!Updates the metric settings before editor saves it's data*/
	virtual void updateForSave();
	/*!Refreshes the size in the scene by metric size*/
	virtual void updateSize();
	/*!Refreshes the position in the scene by metric position*/
	virtual void updatePosition();
	/*! 
	Print/paint method for rendering item in high resolution device such as QPrinter
	*/
	virtual void paint( NCReportOutput*, const QPointF& )=0;
	/*! Returns position in item was selected */
	QPointF selectPos() const;
	void saveSelectPos();
	QSizeF selectSize() const;
	void saveSelectSize();
	/*! Returns if item is dynamic or not. */
	bool isDynamic();
	/*! Returns if item is empty or not. Virtual. */
	virtual bool isEmpty();
	/*! Zone position offset */
	virtual void setOffset( const QPointF offset );
	virtual void enableOffsetPosition();
	virtual void disableOffsetPosition();
			
	void setSectionSize( const QSizeF& );
	void setZoneSize( const QSizeF& );
protected:
	NCReportItemData *d;
	SelectionDirection m_selectionHoverState;
	QSizeF m_newSize;
	QPointF m_selectPos;
	QSizeF m_selectSize;
	//bool m_isMoving;
	
	virtual void readBaseProperties( NCReportXMLReader* );
	virtual void paintSelection(QPainter *painter);
	virtual QRectF selectionRect( const SelectionDirection, const QSizeF& itemsize ) const;
	virtual void updateCursor(const SelectionDirection dir);
	
	virtual QVariant itemChange( GraphicsItemChange change, const QVariant & value );
	virtual void itemPositionChange( const QPointF& );
	virtual void hoverMoveEvent( QGraphicsSceneHoverEvent * event );
	virtual void mouseMoveEvent( QGraphicsSceneMouseEvent * event );
	virtual void mouseDoubleClickEvent( QGraphicsSceneMouseEvent * event );
	virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent * event );
};


#endif
