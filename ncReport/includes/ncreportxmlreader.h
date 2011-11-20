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
#ifndef NCREPORTXMLREADER_H
#define NCREPORTXMLREADER_H

#include <QXmlStreamReader>
#include <QPointF>
#include <QFont>
#include <QPen>
#include <QBrush>
#include <QSize>

class NCReportDef;
class NCReportSection;
class QTreeWidgetItem;
class NCReportPageOption;
class NCReportFieldItem;
class NCReportItem;

/*!
This abstract class represents the base report XML definition stream reader.\n
Contains methods for reading elementary item's properties.
*/
class NCReportXMLReader : public QXmlStreamReader
{
public:
	NCReportXMLReader();
	virtual ~NCReportXMLReader();
	void setPageOption( NCReportPageOption* );
	virtual bool read(QIODevice *device, const QString& def);
	void readUnknownElement();
	
	NCReportDef *reportDef() const;
	void setReportDef( NCReportDef* );
	
	bool isAttrib( const QString& name );
	QStringRef attrib( const QString& name );
	QString attribToString( const QString& name );
	int attribToInt( const QString& name );
	qreal attribToReal( const QString& name );
	bool attribToBool( const QString& name );
	
	void readFont( QFont& );
	void readPen( QPen& );
	void readBrush( QBrush& );
	QPointF readPos() const;
	QPointF readPosFrom() const;
	QPointF readPosTo() const;
	QSizeF readSize() const;
	Qt::Alignment readAlignmentH();
	Qt::Alignment readAlignmentV();
	qreal readLineWidth();
	
protected:
	QString basetag;
	NCReportPageOption *pageoption;
	NCReportDef *rdef;
	
	virtual void init()=0;
    virtual void readReport();
	
	virtual void readOptions();
	virtual void readHtmlText();
	virtual void readPage();
	virtual void readItems( NCReportSection* );
	virtual void readSection( NCReportSection* );
	
	virtual void readDataSources();
	virtual void readDataSource();
	virtual void readVariables();
	virtual void readVariable();
	virtual void readPageHeader();
	virtual void readPageFooter();
	virtual void readReportHeader();
	virtual void readReportFooter();
	virtual void readDetails();
	virtual void readField( NCReportFieldItem* );
	virtual void afterReadItem( NCReportItem* );
	virtual void afterAddItem( NCReportItem* );
	
	virtual void setDefaultFont( QFont& );
	virtual void setDefaultPen( QPen& );
	virtual void setDefaultBrush( QBrush& );
	
};

#endif
