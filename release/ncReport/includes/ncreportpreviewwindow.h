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
#ifndef NCREPORTPREVIEWWINDOW_H
#define NCREPORTPREVIEWWINDOW_H

#include "ncreportpageoption.h"

#include <QMainWindow>
#include <QCloseEvent>
#include <QScrollArea>

class NCReportPreviewPageContainer;
class NCReportPreviewOutput;
class NCReportPreviewScrollArea;

class QWidget;
class QAction;
class QComboBox;
class QMenu;
class QTextEdit;
class QSpinBox;
class QProgressDialog;

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
Main window class for Print preview. Represents the contents of an NCReportPreviewOutput object
 */
class NCREPORT_LIB_API NCReportPreviewWindow : public QMainWindow
{
      Q_OBJECT
public:
	NCReportPreviewWindow();
	~NCReportPreviewWindow();

	enum PagePosition { Top, Bottom, Off };
	
	void setOutput( NCReportPreviewOutput* );
	void setReport( NCReport* );
	//bool setPageIMFData(QIODevice *device, const QString& imfdata);
	int pageCount();
	
public slots:
	void newFile();
	void open();
	bool save();
	bool saveAs();
	void about();
	void documentWasModified();
	void print();
	void printPDF();
	void printSVG();

	void zoom( const QString & s);
	void zoomPlus();
	void zoomMinus();
	void zoom1();
	
	void nextPage( const PagePosition = Top );
	void prevPage( const PagePosition = Top );
	void firstPage( const PagePosition = Top );
	void lastPage( const PagePosition = Top );
	void gotoPage();
	
	void loadPage( int pageno );
	void loadPage( int pageno, const PagePosition );
	
	//TESTS
	void testPrint1();
	void testPrint2();
	void addTestItems();
	void clearPage();

protected:
	void closeEvent(QCloseEvent *event);

private:
	//QWidget *pageContainer;
	QString m_winTitle;
	NCReportPreviewScrollArea *scrollArea;
	NCReportPreviewPageContainer *m_pageContainer;
	QString curFile;
	QStringList pagesData;
	int currentPage;
	NCReportPreviewOutput *output;
	NCReport *report;
	
	QMenu *mnFile;
	QMenu *mnView;
	QMenu *mnNav;
	QMenu *mnAbout;
	
	QToolBar *tbFile;
	QToolBar *tbView;
	QToolBar *tbNav;
	
	//QAction *actionTest1, *actionTest2;
	QAction *actionOpen;
	QAction *actionPrint, *actionPDF, *actionSVG, *actionFrst, *actionNext, *actionPrev, *actionLast;
	QAction *actionGo, *actionExit, *actionZP, *actionZM, *actionZ1;
	
	QAction *aboutAct;
	QAction *aboutQtAct;
	QComboBox *cbZoom;
	QSpinBox *spPage;
	
	void createActions();
	void createMenus();
	void createToolBars();
	void createStatusBar();
	
	void readSettings();
	void writeSettings();
	bool maybeSave();
	void loadFile(const QString &fileName);
	bool saveFile(const QString &fileName);
	void setCurrentFile(const QString &fileName);
	QString strippedName(const QString &fullFileName);
	void refreshActions();
	void updateZoomInfo();
	void showEvent(QShowEvent *event);
	void initPrinter( QPrinter* );
	void initProgress( QProgressDialog* );
	void printPicturePages( QPrinter* );
};


class NCReportPreviewScrollArea : public QScrollArea
{
	Q_OBJECT
public:
	NCReportPreviewScrollArea( NCReportPreviewWindow * parent = 0 );
	~NCReportPreviewScrollArea();

protected:
	void keyPressEvent( QKeyEvent* );
	
private:
	NCReportPreviewWindow* pWindow;
};


#endif
