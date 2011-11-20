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
#ifndef NCREPORTLINEITEM_H
#define NCREPORTLINEITEM_H

#include "ncreportshapeitem.h"
#include <QLineF>

/*!
Line item's data class
 */
class NCReportLineData : public NCReportShapeData
{
public:
	NCReportLineData();

	QPointF mPos2;
	QLineF line;
};

/*!
Line item class
 */
class NCReportLineItem : public NCReportShapeItem
{
public:
 	NCReportLineItem( QGraphicsItem* parent =0);
 	~NCReportLineItem();
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	int type() const;
	
	bool read( NCReportXMLReader* );
	bool write( NCReportXMLWriter* );
	void setDefaultForEditor();
	void paint( NCReportOutput*, const QPointF& );
	
	QRectF boundingRect() const;
    QPainterPath shape() const;
	QLineF line() const;
    void setLine(const QLineF &line );
	void setPen( const QPen & pen );
	void setBrush( const QBrush & brush );
    void updateForEditor();
    void updateForSave();
	void updateSize();
	void updatePosition();
	
	void enableOffsetPosition();
	void disableOffsetPosition();

	
	inline void setLine(qreal x1, qreal y1, qreal x2, qreal y2) { 
		setLine(QLineF(x1, y1, x2, y2)); 
	}	
protected:
	void paintSelection(QPainter *painter);
	QRectF selectionRect( const SelectionDirection, const QSizeF& itemsize ) const;
	void updateCursor(const SelectionDirection dir);
	void itemPositionChange( const QPointF& );
	
private:
	QPointF movePoint;
};

#endif
