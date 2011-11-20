/****************************************************************************
*
*  Copyright (C) 2002-2009 Helta Kft. / NociSoft Software Solutions
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
#ifndef _NCREPORTAPP_H
#define _NCREPORTAPP_H

#include "ncreport.h"
#include "ncreportparameter.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"

static const char* _usage = "Options:\n"
 "  -?, --help                       Display this help and exit\n"
 "  -v, --version                    NCReport version\n"
 "  -f, --report-file <filename>     Name of the report definition (xml) file.\n"
 "                                   If this is set, the report definition\n"
 "                                   will be parsed from this file instead of a database.\n"
 "  -q, --sql-driver <driver>        Qt sql driver name for database connection (Avaible drivers: QDB2,QIBASE,QMYSQL,QOCI,QODBC,QPSQL,QSQLITE,QTDS)\n"
 "  -h, --host <hostname>            Database host name or IP address (default is localhost)\n"
 "  -u, --user <username>            Database user login name\n"
 "  -p, --password <password>        Database user login password\n"
 "  -d, --database <dbname>          Database name to use\n"
 "  -c, --connection-id <id>         Sql connection name/id\n"
 "  -o, --output <print | preview | pdf>\n"
 "                                   Output type. Use \"print\" for send report to printer or \"preview\"\n"
 "                                   to show report in a preview window. The default output is \"preview\"\n"
 "  -of, --output-file <filename>    Number of copies in case output is printer\n"
 "  --copies <1..50>                 Number of copies in case output is printer\n"
 "  --force-copy                     Use forced copy printing method. This is useful for documents\n"
 "                                   in which have to know the number of current copy.\n"
 "  -dbid, --report-db-id <id>            ID number of the report definition (xml) text in a database record.\n"
 "                                   If this is set the report definition will be parsed from\n"
 "                                   database/table/record instead of a file.\n"
 "  -par, --add-parameter <parametername>,<value>\n"
 "                                   Adds a custom parameter to report. You must specify the value\n"
 "                                   and name of the parameter separated by comma.\n"
 "                                   The P{parametername} expression can be used in the report definition\n"
 "                                   (Example: firstname,\"Robert\")\n"
 "";

static const char* _usage_error_1 = "Invalid argument. Use --report-file <filename> OR --report-id <ID> . You may not use both these parameters.";

class NCReportApp
{
public:
	NCReportApp();
	~NCReportApp() {}

	//encpasulate into exec function;
	bool						init( int argc, char* argv[] );
	bool						exec( NCReport& ncreport, int argc, char* argv[] );
	bool						isPreview();

protected:
	bool						commandLineHandler( int argc, char* argv[] );
	bool						databaseConnection();
	bool						reportResourceSetting( NCReport& ncreport );
	bool						addParameters( NCReport& ncreport, int argc, char* argv[] );
	bool						outputInitialize( NCReport& ncreport );
	/*bool						runReportToPdf( NCReport& ncreport );*/
	bool						runReport( NCReport& ncreport );

	//bool		run
private:
	QString						m_driver;
	QString						m_host;
	QString						m_user;
	QString						m_password;
	QString						m_database;
	QString						m_outputFile;
	QString						m_repFile;
	QString						m_connID;
	int							m_copies;
	int							m_reportID;
	NCReportOutput::OutputType	m_outPut;
};

#endif
