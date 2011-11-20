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
#ifndef NCREPORTPAGEOPTION_H
#define NCREPORTPAGEOPTION_H

#include "ncreport.h"

#include <QPrinter>
#include <QFont>
#include <QColor>
#include <QVector>

class NCReportXMLReader;
class NCReportXMLWriter;

/*!
This class represents the page properties of report
*/
class NCReportPageOption
{
public:
	NCReportPageOption();
	
	class PageData
	{
		public:
		PageData() : name( QString() ), pageSize( QPrinter::A4 ), width( -1 ), height( -1 )
		{}
		PageData( const QString& nm, const QPrinter::PageSize ps, const qreal w, const qreal h )
			: name(nm), pageSize( ps ), width(w), height(h)
		{}
		QString name;
		QPrinter::PageSize pageSize;
		qreal width;
		qreal height;
	};
	void setPageSize( const QPrinter::PageSize );
	void setCustomPageSize( const QSizeF& );
	void setOrientation( const QPrinter::Orientation );
	static void pageSizeByName( const QString psname, const QPrinter::Orientation orient, QPrinter::PageSize& psid, double& w, double& h );
	static QString pageSizeToName( const QPrinter::PageSize );
	static void loadPageDataVector( QVector<NCReportPageOption::PageData>& );

	QString reportTypeName() const;
	void setReportType( const QString& name );
	
	void adjustPageSize();
	bool read( NCReportXMLReader* r );
	bool write( NCReportXMLWriter* r );
	
	QSizeF purePageSize() const;

	
	//-------------------------------------------
	QPrinter::PageSize pageSize;
	QPrinter::Orientation pageOrientation;
	NCReport::ReportType reportType;
	
	QString reportName;
	qreal pageWidth, pageHeight;
	qreal topMargin, bottomMargin, leftMargin, rightMargin;
	int columnCount;
	qreal columnWidth, columnSpacing;
	QFont defaultFont;
	QString encoding;
	QColor backcolor;
	qreal zoneSpacing;
	bool doublePassMode;
};

#endif
