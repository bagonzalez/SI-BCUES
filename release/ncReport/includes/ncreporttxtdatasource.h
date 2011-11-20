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
#ifndef NCREPORTTXTDATASOURCE_H
#define NCREPORTTXTDATASOURCE_H

#include "ncreportdatasource.h"

class QFile;
class QTextStream;

/*!
Datasource for QString based texts. Each rows represent a record and the data columns are separated by
a delimiter character.
Inherits: NCReportDataSource
 */
class NCReportTXTDataSource : public NCReportDataSource
{
	Q_OBJECT
public:
	NCReportTXTDataSource( QObject *parent=0 );
	~NCReportTXTDataSource();
	
	enum Delimiter { Tab=0, Comma, SemiColon, Space, VBar, Custom };
	
	bool open();
	bool close();
	bool first();
	bool last();
	bool next();
	bool prevoius();
	int size() const;
	QVariant value( const QString&, int nQTDataRole = -1 ) const;
	QVariant value( int, int nQTDataRole = -1 ) const;
	bool read( NCReportXMLReader* );
	bool write( NCReportXMLWriter* );
	void evaluate( NCReportEvaluator* );
	void setColumnDelimiter( const Delimiter );
	Delimiter columnDelimiter() const;
	void setCustomDelimiterCharacter( const char );
	char delimiterCharacter() const;
	bool seek( int index );

	int rowCount() const;
	int columnCount() const;
	
private:
	char delimiter;
	Delimiter cDelim;
	QFile *dataFile;
	QTextStream *ts;
	QString currentRow;
	QString lastRow;
	QString nextRow;
};


#endif
