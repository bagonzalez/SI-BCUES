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
#ifndef NCREPORT_H
#define NCREPORT_H

#include "ncreportparameter.h"
#include "ncreportsource.h"

#include <QObject>
#include <QSqlDatabase>
#include <QPointer>

class NCReportDef;
class NCReportOutput;
class NCReportDirector;
class NCReportLookup;
class NCReportDataSource;
class NCReportAbstractItemRendering;
class QAbstractItemModel;
class QTextDocument;
class QWidget;

/*!
NCReport engine class. 
*/

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
NCReport report generator engine class. For running reports you should use this class
*/

class NCREPORT_LIB_API NCReport : public QObject
//class NCReport : public QObject
{
	Q_OBJECT
public:
	NCReport( QObject *parent=0 );
	~NCReport();
	
	enum ReportType { Report=0, TextDocumentPrint };
	
	/*! Returns the current program version*/
	QString version() const;
	/*! Return short program information */
	QString info() const;
	/*! Method for reseting the report object.\n
	Clears all objects from memory and makes the report object enable to run again a report */
	void reset( bool all=FALSE );
	/*! Specifies the report source property by type */
 	void setReportSource( NCReportSource::ReportSourceType );
	/*! Specifies the report source object */
	void setReportSource( NCReportSource* );
	/*! Specifies the report output */
	void setOutput( NCReportOutput*, bool deleteLast=true );
	/*! Specifies the file name of the report output object that uses files*/
	void setReportFile( const QString& );	
	/*! By this method you can add report definition XML string directly to report */
	void setReportDef( const QString& );	
 	void setForceCopies( int );
	/*! Enables os disables using wait cursor while running process */
	void setUseWaitCursor( bool );
	/*! Sets a custom, external text document for printing in NCReport::TextDocumentPrint mode */
	void setTextDocument( QTextDocument* );
	void setPageProgressText( const QString& );
	QString pageProgressText() const;
 	
 	//void setTrimmers( int tfont_print, int tfont_prevw, int tline_print, int tline_prevw );
	//void setDeleteReportAfterPreview( bool );
 	
	/*! Adds a NCReportParameter parameter to the report*/
 	void addParameter( NCReportParameter* );
	/*! Adds a parameter to the report by id and value*/
	void addParameter( const QString& id, const QVariant& value );
	void addLookupClass( NCReportLookup* );
	/*! Adds a custom datasource to the report*/
	void addCustomDataSource( NCReportDataSource* );
	/*! Adds a custom item rendering object to the report*/
	void addItemRenderingClass( NCReportAbstractItemRendering* );
	/*! Adds a QStringList as a datasource to the report. The <i>id</i> is used for identification purpuses.*/
	void addStringList( const QStringList&, const QString& id );
	/*! Adds a QAbstractItemModel to the report. The model class is used by item model datasource. 
	The <i>id</i> is used for identification purpuses.*/
	void addItemModel( QAbstractItemModel*, const QString& id );
	
	/*! Returns true if an error occured; otherwise false.*/
 	bool hasError();
	/*! Returns the last error message if error occured*/
	QString lastErrorMsg();
	/*! Returns the current output for the report*/
	NCReportOutput *output();
	/*! Returns the current NCReportSource for the report*/
	NCReportSource *reportSource();
	/*! Returns the current NCReportDataSource for the report*/
	NCReportDataSource *dataSource( const QString& );

	//HRaba
	/*! Returns the report's definition object*/
	NCReportDef *reportDef() {return rdef;}
	/*! Returns the type of the report*/
	ReportType reportType() const { return m_reportType; }
	/*! Returns the text document assigned to the report*/
	QTextDocument *document() { return m_document; }
	/*! Returns last elapsed report runtime */
	int runTimeElapsed() const;

signals:
	/*! This signal is emitted when the report start */
	void reportStarts();
	/*! This signal is emitted when the report ends */
	void reportEnds();
	/*! This signal is emitted when a datasource opens. This is when SQL query stars in SQL datasource. */
	void dataSourceOpen( const QString& dsID );
	/*! This signal is emitted after the datasource opened. totalRows is the number of rows in the datasource (if available). */
	void dataSourceOpened( const QString& dsID, int totalRows);
	/*! This signal is emitted when a datasource record / row is pending. */
	void dataRowProgress( const QString& dsID, int row );
	/*! This signal is emitted when the current datasource record / row is pending. */
	void dataRowProgress( int row );
	/*! This signal is emitted before the current datasource is progressed. */
	void dataRowCount( int numRows );
	/*! This signal is emitted before a report section is rendered */
	void sectionProgress( const QString& sectionID );
	/*! This signal is emitted when a (new) page started. */
	void pageProgress( int page );
	/*! This signal is emitted when a (new) page started. */
	void pageProgress( const QString& );
	/*! This signal is emitted before the QPrintPreview dialog appears when QtPreview mode. */
	void showQtPreviewDialog();

public slots:
	/*! This function runs the report and returns true if the report process succeeded, otherwise false.*/
 	bool runReport();
	void runReportToPrinter( int copies=1, bool showdialog=TRUE, QWidget* parent=0 );
 	void runReportToPreview();
	void runReportToQtPreview();
	void runReportToPDF( const QString& filename );
	void runReportToSVG( const QString& filename );
	void cancel();

private slots:
	void slotDataSourceOpen( const QString& dsID );
	void slotDataSourceOpened( const QString& dsID, int totalRows );
	void slotDataRowProgress( const QString& dsID, int row );
	void slotDataRowProgress( int row );
	void slotDataRowCount( int numRows );
	void slotSectionProgress( const QString& sectionID );
	void slotPageProgress( int page );

protected:
	virtual void customizeReportDef( NCReportDef* );

private:
	NCReportDef *rdef;
	NCReportSource *source;
	NCReportDirector *director;
	QPointer<NCReportOutput> out;
	int fcopy;
	bool usewaitcursor;
	ReportType m_reportType;
	QTextDocument *m_document;
	bool m_cancelled;
	int m_elapsed;
	QString m_pageProgressText;
	
	void loadConfig();
 	bool reportProcess();
};


#endif //NCREPORT_H

