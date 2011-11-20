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
#ifndef NCREPORTXMLDEFWRITER_H
#define NCREPORTXMLDEFWRITER_H

#include "ncreportxmlwriter.h"

class NCReportSection;
class NCReportDef;
class NCReportDataSource;
class NCReportVariable;

class NCReportXMLDefWriter : public NCReportXMLWriter
{
public:
	NCReportXMLDefWriter();
	NCReportXMLDefWriter( QString * string );
	
	void setReportDef( NCReportDef * );
	QString reportName() const;
	QString reportType() const;
	
protected:
	void writeOptions();
	void writeDataSources();
	void writeDataSource( NCReportDataSource* );
	void writeVariables();
	void writeVariable( NCReportVariable* );
	void writePageHeader();
	void writePageFooter();
	void writeReportHeader();
	void writeReportFooter();
	void writeDetails();
	
private:
	NCReportDef *rdef;
};


#endif
