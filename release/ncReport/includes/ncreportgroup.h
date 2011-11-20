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
#ifndef NCREPORTGROUP_H
#define NCREPORTGROUP_H

#include <QString>

class NCReportSection;

/*!
This class represents the a group/band of report. Managed by NCReportDirector
 */
class NCReportGroup
{
	friend class NCReportXMLDefReader;
	friend class NCReportDef;
public:
	NCReportGroup();
	~NCReportGroup();

	enum GroupState { Closed=0, OnProcess };
	
	void setID( const QString& );
	void setValue( const QString& );
	void setGroupExp( const QString& );
	void setResetVars( const QString& );
	void setReprintHeaderOnNextPage( bool );
	void setStartsOnNextPage( bool );
	/*! Flag for saving first page/initial print */
	void setInitialPrintDone( bool );
	/*! Sets the group status */
	void setGroupChanged( bool );
	bool isGroupChanged();
	/*! flag is useful for avoid duplicated prints*/
	void setPrintLock(bool);
	bool printLock();
	void setSortOrder( short );
	short sortOrder() const;
	
	NCReportSection *header();
	NCReportSection *footer();
	NCReportSection *detail();
	const QString& resetVariables() const;
	const QString& expression() const;
	bool reprintHeaderOnNextPage();
	const QString& groupID() const;
	bool startsOnNewPage();
	bool initialPrintDone();
	const QString& value() const;
	void initReset();
	
private:
	GroupState state;
	
	NCReportSection *hdr;
	NCReportSection *ftr;
	NCReportSection *dtl;

	bool enabled;	// is grouping enabled:
	bool groupchanged;
	QString id;
	QString groupExp;	// data source column or expression
	QString currentValue; //, lastValue;
	QString resetvars;		//list of variables which have to be reset at the end of group. (delimited with "," comma)

	bool m_startsOnNewPage;
	//bool resetPageno;
	bool m_reprintHeader;
	bool m_initialPrintDone;
	bool m_printLock; // flag for avoid duplicated prints
	short m_order;	// order index
};

#endif
