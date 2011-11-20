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
#ifndef NCREPORTLABELITEM_H
#define NCREPORTLABELITEM_H

#include "ncreportitem.h"

#include <QString>
#include <QColor>
#include <QFont>

/*!
Simple text label item's data class
 */
class NCReportLabelData : public NCReportItemData
{
public:
	NCReportLabelData();
	enum BGMode { Transparent=0, FilledBackground };

	Qt::Alignment alignmentH;
	Qt::Alignment alignmentV;
	bool wordbreak; //, singleline, expandtabs;
	QColor forecolor;
	QColor backcolor;
	QFont font;
	QString displayValue;
	QString lastValue;
	int rotation;
	BGMode bgMode;
	bool hideRepeated;
};

/*!
Simple text label item class
 */
class NCReportLabelItem : public NCReportItem
{
public:
 	NCReportLabelItem( int type, QGraphicsItem* parent =0);
 	virtual ~NCReportLabelItem();
	//virtual QRectF boundingRect() const;
	virtual int type() const;
	
	virtual bool read( NCReportXMLReader* );
	virtual bool write( NCReportXMLWriter* );
	virtual void setDefaultForEditor();
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	virtual void paint( NCReportOutput*, const QPointF& );
	virtual void adjustSize();
	virtual void adjustSize(NCReportOutput*);
	virtual bool isEmpty();
	
protected:
	virtual void readProps( NCReportXMLReader* );
	virtual void writeProps( NCReportXMLWriter* );
	virtual void adjustFont( QFont & font, NCReportOutput* =0 );

};

#endif
