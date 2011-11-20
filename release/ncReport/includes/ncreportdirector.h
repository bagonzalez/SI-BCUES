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
#ifndef NCREPORTDIRECTOR_H
#define NCREPORTDIRECTOR_H

#include <QObject>
#include <QStack>

#include "ncreport.h"
#include "ncreportdatasource.h"

//class NCReport;
class NCReportDef;
class NCReportSection;
class NCReportEvaluator;
//class NCReportDataSource;
class NCReportGroup;
class NCReportItem;

/*!
This class is the internal engine of NCReport. The NCReportDirector manages the whole report running process.\n
Responsible for running datasources and rendering report.
 */
class NCReportDirector : public QObject
{
	Q_OBJECT
public:
	friend class NCReportSectionDirector;
	enum ProcessState { Initial=0, Finished, PageBegin, PageOnProcess, PageEnd, GroupHeader, GroupFooter,
						PageHeader, PageFooter, ReportHeader, ReportFooter, Detail, Unknown };
	enum PageStatus { Printable=0, Hidden };
	enum PassState { Off=0, TestPass, RealPass };

    NCReportDirector( NCReport* parent );
    ~NCReportDirector();
	
	void setReportDef( NCReportDef* );
	void setForceCopies( int );
	void setCurrentForceCopy( int );	
	
	bool reportProcess();
	int pageNo() const;
	int pageCount() const;
	int numForceCopies() const;
	int currentForceCopy() const;
	int currentRow() const;
	int numRows() const;
	NCReportSection* currentDetail();
	NCReportDataSource *currentDataSource();
	PageStatus pageStatus( int page ) const;
	PageStatus currentPageStatus() const;

signals:
	void dataSourceOpen( const QString& dsID );
	void dataSourceOpened( const QString& dsID, int );
	void dataRowProgress( const QString& dsID, int );
	void dataRowProgress( int row );
	void dataRowCount( int numRows );
	void sectionProgress( const QString& sectionID );
	void pageProgress( int );
	
public slots:
	/*!Cancels report process*/
	void cancel();
	
private:
	NCReport *report;
	NCReportDef *rdef;
	NCReportEvaluator *evaluator;
	ProcessState state;
	PageStatus m_pageStatus, m_previousPageStatus;
	PassState m_passState;
	qreal mPaintPosX, mPaintPosY;		// painter positions in mm
	bool flagFinished;
	bool flagRHeader, flagRFooter;
	bool flagNoSpaceInPage;
	bool flagBeginReport;
	bool flagNoUpdate;	// flag for avoidance the unneccessary update of variables, fields...
	int pageno;
	int pagecount;
	int detailID; // current processing detail
	int forcecopies, currentforcecopy;
	int currentrow;
	QStack<NCReportGroup*> inside;
	QStack<NCReportGroup*> outside;
	NCReportSection* lastRenderedSection;	// save the last printed section
	enum FieldUpdateMode { All=0, DataSourcesOnly, ParametersOnly, VariablesOnly, SystemVariablesOnly, ExpressionsOnly,
		DataSourcesAndExpressionsOnly, ParametersAndExpressionsOnly, VariablesAndExpressionsOnly, SystemVariablesAndExpressionsOnly,
  		AllWithoutParameters
	};
	//QStack<NCReportItem*> opItems;
	
	
	//-----------------------------
	// PRIVATE METHODS
	//-----------------------------
	//bool openDataSources( NCReportDataSource::OpenRoles role, const QString& groupID = QString() );
	bool openDataSources( NCReportDataSource::OpenRoles role );
	bool openDataSource( NCReportDataSource* );
	bool closeDataSources( NCReportDataSource::OpenRoles role );
	
	void pageBegin();
	void pageEnd();
	void reportHeader();
	void reportFooter();
	bool detail();
	bool printOverPageSection();
	bool reprintSections();
	
	/*!Enters to the next group level and handles it*/
	bool groupIn();	
	/*!Leaves from the group level and handles it*/
	bool groupOut( bool final = FALSE );
	/*! Renders the content of a section*/
	bool renderSection( NCReportSection* );
	
	/*! Updates the fields */
	void updateFields( FieldUpdateMode m );
	void updateVariables();
	void updateDynamicItems();
	void updateGroups( NCReportSection *d );
	void resetGroup( NCReportGroup* );
	void initGroupStacks();
	/*! Reset all variables */
	void resetVariables();
	/*! Breaks the current page and begins a new one*/
	void pageBreak();
	
	/*! Returns available space to bottom in the current page in mm.*/
	qreal spaceToBottom() const;
	bool printTextDocument();

	/*! returns the width of the section */
	qreal sectionWidthMM( NCReportSection* ) const;
	/*! returns true if there are more detail(s) after current */
	bool isNextDetail() const;
	/*! Skip to next record in the datasource ds */
	bool nextDataRow(NCReportDataSource*) const;
	/*! Requeries (sql) datasource by ds */
	bool reQueryDataSource( NCReportDataSource* ) const;
	/*! Requeries (sql) datasource that is assigned to a group by group ID */
	bool reQueryDataSource( const QString& groupID ) const;

};

#endif
