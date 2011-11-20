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
#ifndef NCREPORTSOURCE_H
#define NCREPORTSOURCE_H

#include <QString>
#include <QPrinter>

class QIODevice;
class NCReportDef;
class NCReportXMLDefReader;
class NCReportXMLDefWriter;

#ifdef Q_WS_WIN
#	if defined(NCREPORT_EXPORT)
#		define NCREPORT_LIB_API __declspec(dllexport)
#	elif defined(NCREPORT_IMPORT) 
#		define NCREPORT_LIB_API __declspec(dllimport)
#	else
#		define NCREPORT_LIB_API
#	endif
#else
#	define NCREPORT_LIB_API
#endif

/*!
Report XML definition resource handler. Manages the definition source from the different locations or storage units.\n
Report definitions are ready to fetch from database, file or via internet (http/ftp)
 */
class NCREPORT_LIB_API NCReportSource
{
public:
	NCReportSource();
	virtual ~NCReportSource();
	
	enum ReportSourceType { File=0, Database, Http, Ftp, Custom, Parameter };	// report definition source
	
	void setReportDef( NCReportDef* );
	void setReportDef( const QString& );
	void setSourceType( NCReportSource::ReportSourceType );
	ReportSourceType sourceType() const;
	void setLoadQuery( const QString& );
	void setSaveQuery( const QString& );
	void setConnectionID( const QString& );
	void setFileName( const QString& );
 	void setReportID( int );	// set pk value in report table -if we use report def. file from Database
 	void setReportID( const QString& );	// set string id value in report table -if we use report def. file from Database
	QString definition() const;
	NCReportDef *reportDef();			
	bool load( NCReportXMLDefReader& );
	bool save( NCReportXMLDefWriter& );
	
protected:
	virtual bool loadFromFile( NCReportXMLDefReader& );
	virtual bool loadFromDatabase( NCReportXMLDefReader&);
	virtual bool loadFromHttp( NCReportXMLDefReader& );
	virtual bool loadFromFtp( NCReportXMLDefReader& );
	virtual bool loadFromCustomSource( NCReportXMLDefReader& );
	virtual bool loadFromString( NCReportXMLDefReader& );
	
	virtual bool saveToFile( NCReportXMLDefWriter& );
	virtual bool saveToDatabase( NCReportXMLDefWriter&);
	virtual bool saveToHttp( NCReportXMLDefWriter& );
	virtual bool saveToFtp( NCReportXMLDefWriter& );
	virtual bool saveToCustomSource( NCReportXMLDefWriter& );
	
	void setParseError( NCReportXMLDefReader& );
	
private:
	NCReportDef *rdef;
	QString reportLoadQuery, reportSaveQuery;
	QString fileName;
	ReportSourceType type;
	QString _definition;	// the xml definition file;
	QString idS;
	int id;
	QString connectionID;

	//bool loadResource( QIODevice *file=0 );

};


#endif
