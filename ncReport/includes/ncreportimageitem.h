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
#ifndef NCREPORTIMAGEITEM_H
#define NCREPORTIMAGEITEM_H

#include "ncreportitem.h"

/*!
Image item's data class
 */
class NCReportImageData : public NCReportItemData
{
public:
	NCReportImageData();

	enum ImageFormat { Binary=0, Base64Encoded, Svg };
#ifdef USE_QIMAGE_INSTEAD_OF_QPIXMAP
	QImage image;
#else
	QPixmap image;
#endif
	Qt::AspectRatioMode aspRatMode;
	Qt::TransformationMode transformMode;
	QString filename;
	bool scaling;
	ImageFormat format;
	QByteArray svgXml;

	bool load();
	bool loadFromTextFile( const QString& fname, QString& target );
};

/*!
Image item class
 */
class NCReportImageItem : public NCReportItem
{
public:
 	NCReportImageItem( QGraphicsItem* parent =0);
 	~NCReportImageItem();
	//QRectF boundingRect() const;
	int type() const;
	void adjustSize();
	
	bool read( NCReportXMLReader* );
	bool write( NCReportXMLWriter* );
	void setDefaultForEditor();
	void paint( NCReportOutput*, const QPointF& );
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif
