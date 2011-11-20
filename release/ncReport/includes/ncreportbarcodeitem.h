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
#ifndef NCREPORTBARCODEITEM_H
#define NCREPORTBARCODEITEM_H

#include <QHash>
#include "ncreportitem.h"
#include "qzint.h"
//#include "ncreportbarcodetype.h"

/*!
Barcode item data class
*/
class NCReportBarcodeData : public NCReportItemData
{
public:
	NCReportBarcodeData();

	class BarcodeType
	{
	public:
		BarcodeType(): typeCode(0), typeName( QString() ) {}
		BarcodeType( int code, const QString& name = QString() ): typeCode(code), typeName( name ) {}
		int typeCode;
		QString typeName;
	};

	BarcodeType barcodeType;
	bool showCode;
	//int sizeFactor;
	int fontSize;
	// ----- ZINT BARCODE SYSTEM ----------
	Zint::QZint barcode;
	Zint::QZint::AspectRatioMode ar;
	bool composite;
	//QString barcodeData;
	QString compositeText;
	QHash<QString,QVariant> options;
	int securityLevel;
	int borderType;
	int borderWidth;
	int whiteSpace;
	qreal printingScale;
	int heightFactor;
	QColor foreColor, backColor;

	static void typesToVector( QVector<NCReportBarcodeData::BarcodeType>& );
	NCReportBarcodeData::BarcodeType typeByCode( int ) const;
	void update_barcode();
};

/*!
Barcode item class
 */
class NCReportBarcodeItem : public NCReportItem
{
public:
 	NCReportBarcodeItem( QGraphicsItem* parent =0);
 	~NCReportBarcodeItem();
	//QRectF boundingRect() const;
	int type() const;
	
	bool read( NCReportXMLReader* );
	bool readOptions( NCReportXMLReader* );
	bool write( NCReportXMLWriter* );
	bool writeOptions( NCReportXMLWriter* );
	void setDefaultForEditor();
	void paint( NCReportOutput*, const QPointF& );
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif
