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
#ifndef NCREPORTDEF_H
#define NCREPORTDEF_H

#include "ncreportparameter.h"
#include "ncreportvariable.h"
#include "ncreportpageoption.h"
#include "ncreportsection.h"
#include "ncreportfielditem.h"

#include <QObject>
#include <QHash>
#include <QList>

//HRaba
#define def_strMarkEditRole ":e"
#define def_strMarkUserRole ":u"
#define def_strMarkHeaderRole ":h"
#define def_nMarkHeaderRole -2
#define def_strMarkHeaderDecorationRole ":hc"
#define def_nMarkHeaderDecorationRole -3
#define def_strMarkHeaderUserRole ":hu"
#define def_nMarkHeaderUserRole -4
#define def_strMarkDecorationRole ":c"
#define def_strMarkDisplayRole ":d"

class NCReportDataSource;
class NCReportLookup;
class NCReportAbstractItemRendering;
class QAbstractItemModel;

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
Class for generating NCReport errors.
 */
class NCREPORT_LIB_API NCReportError
{
public:
	NCReportError();
	
	void setError( const QString& msg, int errcode=-1 );
	QString errorMsg() const;
	bool error();
	bool isOK();
	
private:
	bool _error;
	int errorcode;
	QString errormsg;
};

/*!
NCReport definition class. The class holds the whole information for report director for
rendering the report. 
*/
class NCReportDef : public QObject
{
	Q_OBJECT
public:
	NCReportDef( QObject * parent = 0 );
	virtual ~NCReportDef();
	
	void reset( bool all );
	NCReportSection* addPageHeader();
	void removePageHeader();
	NCReportSection* addPageFooter();
	void removePageFooter();
	NCReportSection* addReportHeader();
	void removeReportHeader();
	NCReportSection* addReportFooter();
	void removeReportFooter();
	
	NCReportGroup* addGroup( NCReportSection* );
	void removeGroup( NCReportSection*, NCReportGroup* );
	void removeAllGroups( NCReportSection* );
	NCReportSection* addGroupHeader( NCReportGroup* );
	void removeGroupHeader( NCReportGroup* );
	NCReportSection* addGroupFooter( NCReportGroup* );
	void removeGroupFooter( NCReportGroup* );
	
	NCReportSection* addDetail();
	void removeDetail( NCReportSection* );

	void addParameter( NCReportParameter* );
	void addVariable( NCReportVariable* );
	void removeVariable( NCReportVariable* );
	void addDataSource( NCReportDataSource* );
	void removeDataSource( NCReportDataSource* );
	NCReportError* error();
	
	QHash<QString,NCReportDataSource*>& dataSources();
	QHash<QString,NCReportVariable*>& variables();
	QHash<QString,NCReportParameter*>& parameters();
	QHash<QString,NCReportLookup*>& lookupClasses();
	QHash<QString,NCReportAbstractItemRendering*>& itemRenderingClasses();
	QHash<QString,QStringList>& stringLists();
	QHash<QString,QAbstractItemModel*>& itemModels();
	QList<NCReportSection*>& details();
	QList<NCReportSection*>& groupSections();
	QList<NCReportFieldData*>& fields();
	QList<NCReportItemData*>& dynamicItems();
	NCReportPageOption & option();
	
	NCReportSection *pageHeader();
	NCReportSection *pageFooter();
	NCReportSection *reportHeader();
	NCReportSection *reportFooter();
	
	void setDefaultDSName(const QString& );
	QString defaultDSName() const;
	void removeSection( NCReportSection*& );
	/*!Generate or re-generate layout index for all of details and groups */
	void reindexDetails();
	/*!Sorts or Re-orders groups of the specified detail by group order index. */
	void sortGroups( NCReportSection *detail );
	
protected:
	/*! Virtual method for creating report section scene. The function supports using derived section class*/
	virtual NCReportSection* createReportSection();
	
	NCReportSection* addSection( NCReportSection* );
	NCReportSection* addSection();
	int groupHeaderIndex( NCReportGroup *, int gidx ) const;
	int groupFooterIndex( NCReportGroup *, int gidx ) const;
	
private:
	NCReportPageOption opt;
	NCReportError err;
	//NCReport *ncreport;
	
	QHash<QString,NCReportDataSource*> dsources;
	QHash<QString,NCReportVariable*> vars;
	QHash<QString,NCReportParameter*> params;
	QHash<QString,NCReportLookup*> lookups;
	QHash<QString,NCReportAbstractItemRendering*> itemrenderings;
	QHash<QString,QStringList> stringlists;
	QHash<QString,QAbstractItemModel*> itemmodels;
	QList<NCReportSection*> dtls;
	QList<NCReportSection*> groupsections;
	QList<NCReportFieldData*> flds;
	QList<NCReportItemData*> dynitems;
	
	bool showPrintDialog;
	QString reportFileName;
	QString reportID;
	QString defDSName;
	int reportStringID;
	bool reportFileParsed;
	/*!layout index for designer*/
	int detailIndex;	 
	
	int numcopies;

	NCReportSection *pageheader;
	NCReportSection *pagefooter;
	NCReportSection *reportheader;
	NCReportSection *reportfooter;
};


#endif
