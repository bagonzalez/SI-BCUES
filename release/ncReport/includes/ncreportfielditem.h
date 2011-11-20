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
#ifndef NCREPORTFIELDITEM_H
#define NCREPORTFIELDITEM_H

#include "ncreportlabelitem.h"

/*!
Field item data class
*/
class NCReportFieldData : public NCReportLabelData
{
public:
	NCReportFieldData();

	enum FieldSourceType { DataSource=0, Parameter, Variable, SysVar, Expression, Template };

	FieldSourceType fieldsourcetype;
	int precision;
	int fieldwidth;
	char format;
	QChar fillchar;
	bool localized;
	bool numBlankIfZero;
	bool evalscript;
	bool formatnum;
	//bool numSeparation;
	//char numSeparator;
	//char numDigitPoint;
	QString dateFormat;
    QString callFunction;
    QString lookupClass;
	QString arg;	// use QString::arg(...) evaluation
	short numChars;
};

/*!
Field item class
 */
class NCReportFieldItem : public NCReportLabelItem
{
public:
	NCReportFieldItem( QGraphicsItem* parent =0 );
	~NCReportFieldItem();
	
	int type() const;
	bool read( NCReportXMLReader* );
	bool write( NCReportXMLWriter* );
	void setDefaultForEditor();
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void adjustSize();
	bool isEmpty();
	
	//void paint( NCReportOutput* );
protected:
	void readProps( NCReportXMLReader* );
	void writeProps( NCReportXMLWriter* );
};


#endif
