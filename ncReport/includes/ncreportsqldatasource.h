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
#ifndef NCREPORTSQLDATASOURCE_H
#define NCREPORTSQLDATASOURCE_H

#include "ncreportdatasource.h"
#include <QSqlDatabase>

class QSqlQuery;

/*!
Datasource for SQL queries. Uses Qt's SQL module.\n
Inherits: NCReportDataSource
*/
class NCReportSQLDataSource : public NCReportDataSource
{
	Q_OBJECT
	
	friend class NCReportXMLDefReader;
public:
	NCReportSQLDataSource( QObject *parent=0 );
	~NCReportSQLDataSource();

	bool open();
	bool close();
	bool first();
	bool last();
	bool next();
	bool prevoius();
	bool seek( int index );
	int size() const;
	bool reQuery();

	QVariant value( const QString&, int nQTDataRole = -1) const;
	QVariant value( int, int nQTDataRole = -1) const;
	
	bool read( NCReportXMLReader* );
	bool write( NCReportXMLWriter* );
	void evaluate( NCReportEvaluator* );

	void setSqlQuery( const QString& );
	//void setDatabase( const QSqlDatabase & );
	QString sqlQuery() const;
	
	void setHost( const QString& );
	void setDB( const QString& );
	void setUser( const QString& );
	void setPassword( const QString& );
	void setPort( const QString& );
	void setDriver( const QString& );
	void setConnectionID( const QString& );
	QString connectionID() const;
	
	QString dbHost() const;
	QString dbDatabase() const;
	QString dbUser() const;
	QString dbPassword() const;
	QString dbPort() const;
	QString dbDriver() const;
	bool connectDatabase();
	bool disconnectDatabase();
	
	int rowCount() const;
	int columnCount() const;
	bool queryIsValid( const QString& );
	
private:
	QSqlQuery *sql;
	//QSqlDatabase database;
	QString driver;
	QString host, dbname, user, password, port;
	QString connID;
	QString query;
};


#endif
