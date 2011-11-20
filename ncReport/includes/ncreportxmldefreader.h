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
#ifndef NCREPORTXMLDEFREADER_H
#define NCREPORTXMLDEFREADER_H

#include "ncreportxmlreader.h"

class NCReportDef;
class NCReportSection;
class NCReportGroup;
class QTreeWidgetItem;
class NCReportDataSource;

/*!
This class represents the report XML definition stream reader.\n
Responsible for parsing XML definition into NCReportDef class
*/
class NCReportXMLDefReader : public NCReportXMLReader
{
public:
	NCReportXMLDefReader( NCReportDef *r );
	virtual ~NCReportXMLDefReader();
	
protected:

	virtual void init();
	virtual void readDataSources();
	virtual void readDataSource();
	virtual void readVariables();
	virtual void readVariable();
	virtual void readPageHeader();
	virtual void readPageFooter();
	virtual void readReportHeader();
	virtual void readReportFooter();
	virtual void readDetails();
	virtual void readDetail();
	virtual void readGroups( NCReportSection* );
	virtual void readGroup( NCReportSection* );
	virtual void readGroupHeader( NCReportGroup* );
	virtual void readGroupFooter( NCReportGroup* );
	virtual void readField( NCReportFieldItem* );
	
	virtual void afterReadItem( NCReportItem* );
	virtual void setDefaultFont(QFont &);
	
	virtual NCReportDataSource* createCustomDataSource(const QString& dsID);

private:
	void organizeDataSources();
};

#endif
