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
#ifndef NCREPORTOUTPUT_H
#define NCREPORTOUTPUT_H

#include "ncreportscale.h"
#include "ncreportpageoption.h"

#include <QString>
#include <QObject>

class QPrinter;
class QPainter;
class QWidget;
class QPrintPreviewDialog;
class NCReport;
class NCReportItem;

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
Report output base class. This virtual class is used for defining output for NCReport.\n
To create your own report output class just implement an NCReportOutput subclass.\n
The standard subclasses are: NCReportPrinterOutput, NCReportPreviewOutput, NCReportPdfOutput.
 */
class NCREPORT_LIB_API NCReportOutput : public QObject
{
	Q_OBJECT
public:
	enum OutputType { Preview=0, QtPreview, Printer, Pdf, Svg, Image, Xml, Html, PlainText, Null, Custom };
	
	NCReportOutput( QObject* parent=0 );
	//NCReportOutput( OutputType );
	virtual ~NCReportOutput();
	
	void setPageOption( const NCReportPageOption& );
	NCReportPageOption& option();
	void setAutoDelete( bool );
	bool isAutoDelete() const;
	void setFileName( const QString& );
	QString fileName() const;
	OutputType output() const;
 	void setShowPrintDialog( bool );
	bool showPrintDialog();
 	void setCopies( int num );
	int copies() const;
	/*!The painter of the specified output. This is defined in begin() method.*/
	QPainter* painter();
	NCReportScale& scale();
	void setParentWidget( QWidget* );
	QWidget *parentWidget();
	void setPageFromTo( int from, int to );
	int fromPage() const;
	int toPage() const;

	/*!Setup method for prepating the output, for example run printer setup dialog.\n
	If returns false, the report rendering will be cancelled*/
	virtual bool setup() =0;
	virtual void cleanup() =0;
	virtual void begin() =0;
	virtual void end() =0;
	virtual void newPage() =0;
	//QDomDocument xmlOutput() const;
	/*! Virtual function for custom rendering methods if subclassing this class*/
	virtual void renderItem( NCReportItem* item, const QPointF& mPos );

protected:
	virtual void setOutput( OutputType );
	virtual void setPainter( QPainter* );
	virtual void deletePainter();
private:
	OutputType otype;
	QString fname;
	bool showprdia;
	bool autodel;
	int numcopies;
	QPainter *p;
	NCReportPageOption opt;
	NCReportScale sc;
	QWidget *m_parentWidget;
	int m_fromPage;
	int m_toPage;
};

/*!
Printer output class.
*/
class NCREPORT_LIB_API NCReportPrinterOutput : public NCReportOutput
{
public:
	NCReportPrinterOutput(QObject* parent=0);
	virtual ~NCReportPrinterOutput();
	
	//virtual bool printDialog( QPrinter *pr );
	
	virtual bool setup();
	virtual void cleanup();
	virtual void begin();
	virtual void end();
	virtual void newPage();
	//QDomDocument xmlOutput() const;
	QPrinter* printer();
	
protected:
	virtual	void initPrinter();
	/*!Virtual function for customized setting up of the printer*/
	virtual void customInitPrinter( QPrinter* );
	//virtual	void deletePrinter();
	QPrinter *pr;
	
};

/*!
PDF output class
*/
class NCREPORT_LIB_API NCReportPdfOutput : public NCReportPrinterOutput
{
public:
	NCReportPdfOutput(QObject* parent=0);
	virtual ~NCReportPdfOutput();
	//virtual bool printDialog( QPrinter *pr );
	virtual bool setup();
	
};

/*!
Null output class for double pass reports
*/
class NCReportNullOutput : public NCReportOutput
{
public:
	NCReportNullOutput(QObject* parent=0);
	virtual ~NCReportNullOutput();

	bool setup();
	void cleanup();
	void begin();
	void end();
	void newPage();
};
#endif
