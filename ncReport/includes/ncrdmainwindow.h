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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFont>
#include <QHash>
#include <QMap>

#include "ncrdconnectiondialog.h"
#include "ncrddocument.h"
#include "ncrdpreferences.h"

#include "ncreportitem.h"
#include "ncreportoutput.h"
#include "ncreportsource.h"

class NCRDDocument;
class NCRDPropertyManager;
class NCRDTextPropertyManager;
class NCRDShapePropertyManager;
class NCRDPropertyEditor;
class NCRDPreference;
class NCReport;

class QProgressDialog;
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QSignalMapper;
class QUndoGroup;
class QSignalMapper;

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
NCReport Designer main window class
*/
class NCREPORT_LIB_API NCRDMainWindow : public QMainWindow
{
    Q_OBJECT
public:
	NCRDMainWindow( QWidget * parent = 0, Qt::WindowFlags flags = 0 );

	enum ToolState { Arrow=0, Tool };
	ToolState currentState() const;
	NCReportItemData::ObjectType currentTool() const;
	
	//void setGrid( const QPoint &p );
	QPoint grid() const;
	bool isShowGrid() const;
	bool isSnapGrid() const;
	bool isPropEditor() const;
	QUndoGroup* undoGroup() const;
	NCRDPropertyManager* propertyManager( const QString& name );
	NCRDPropertyEditor* propertyEditor( );
	void setManagersEnabled( bool );
	void resetManagers( NCRDDocument* );
	QHash<QString,NCRDConnection>& sqlConnections();
	QMap<QString,QVariant>& reportParameters();
	void updateConnectionMenu();
	void setDefaultReportSourceType( NCReportSource::ReportSourceType );
	
	void setReport( NCReport* );
	virtual void runReport( const NCRDDocumentSourceInfo & si, const NCReportOutput::OutputType, const QMap<QString,QVariant>& params );
	/*! Sets the defauld load query for DB sourced reports */
	//void setLoadQuery( const QString& );
	/*! Sets the defauld save query for DB sourced reports */
	//void setSaveQuery( const QString& );
	/*! Sets the default database connection ID for DB sourced reports */
	void setDefaultConnectionID( const QString& );
	QString defaultConnectionID() const;
	
	/*! Sets the default SQL table name for DB sourced reports */
	void setDefaultDBTable( const QString& );
	QString defaultDBTable() const;
	/*! Sets the default SQL column name for DB sourced reports */
	void setDefaultDBColumn( const QString& );
	QString defaultDBColumn() const;
	/*! Sets the default SQL key column name for DB sourced reports */
	void setDefaultDBKeyColumn( const QString& );
	QString defaultDBKeyColumn() const;
	/*! Sets the default SQL key value for DB sourced reports */
	void setDefaultDBKeyValue( const QString& );
	QString defaultDBKeyValue() const;
	
	QHash<QString,NCRDConnection>& dbConnections();

	bool connectDatabase( const QString&, bool );
	/*! Updates the toolbar/menu states by document. Often called by an active document */
	void updateMenus( NCRDDocument* doc );
	QFont defaultFont() const;
	void setCopyXML( const QString& );
	QString copyXML() const;
	QMenu* menuTools();

protected:
    virtual void closeEvent(QCloseEvent *event);
	virtual void createReportObject();
	virtual void destroyReportObject();

signals:
	void currentToolChanged();
	void connectClicked(const QString &);

public slots:
	void activate_Arrow();
	void activate_Label();
	void activate_Text();
	void activate_Field();
	void activate_Line();
	void activate_Rect();
	void activate_Ellipse();
	void activate_Img();
	void activate_Barcode();
	void activate_Graph();
	
protected slots:
    void newFile();
    void open();
	void openDB();
	void save();
    void saveAs();
    void cut();
    void copy();
    void paste();
    void about();
	
	void details();
	void pageSettings();
	void variables();
	void dataSources();
	void sqlEditor();
	void options();
	void editItem();
	void editSection();
	
	void undo();
	void redo();
	void deleteObject();
	void zoomIn();
	void zoomOut();
	void zoomOne();
	
    void updateMenus();
    void updateWindowMenu();
	NCRDDocument *createDocument();
	void deleteDocument( NCRDDocument*);	
    void switchLayoutDirection();
    void setActiveSubWindow(QWidget *window);

	void alignFront();
	void alignBack();
	void alignForward();
	void alignBackward();
	void alignLeft();
	void alignRight();
	void alignHCenter();
	void alignTop();
	void alignBottom();
	void alignVCenter();
	void alignSameWidth();
	void alignSameHeight();
	
	void showGrid();
	void snapToGrid();
	void testFunction();
	void showPropEdit();
	void showDataSourceTree();
	void dockWindowVisible(bool);
	void connectDB();
	void disconnectDB();
	void runReport();
	void runReportPreview();
	void testDataEditor();
	//void connectDatabase(const QString &);
	void connectDatabase(bool);
	void openRecentFile();

	void showReportProgressDialog();
	void hideReportProgressDialog();

protected:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
	void createEditors();
    void readSettings();
    void writeSettings();
	
	void refreshActiveDocument();
	void refreshTools();
	void applyGridSettings();
	void disableUnfinishedFunctions();
	void setCurrentFile(const QString &fileName);
	void updateRecentFileActions();
	QString strippedName(const QString &fullFileName);
	void load(const NCRDDocumentSourceInfo & si );
	void afterCreateDocument( NCRDDocument*);
	void applyPreferences( const NCRDPreferences & );
	
    NCRDDocument *activeDocument();
	QMdiSubWindow *findDocument( const NCRDDocumentSourceInfo & );

    QMdiArea *mdiArea;
    QSignalMapper *windowMapper;
	QUndoGroup *m_undoGroup;
	NCReportItemData::ObjectType t_tool_current, t_tool_last;
	ToolState t_state_current, t_state_last;
	//QPoint grd;
	//bool sGrid, snGrid;
	QHash<QString,NCRDPropertyManager*> pManagers;
	QHash<QString,NCRDConnection> connections;
	QMap<QString,QVariant> parameters;
	NCRDPropertyEditor *propEdit;
	NCReport *report;
	NCReportSource::ReportSourceType rstype;
	QString m_defaultConnectionID;
	//QString loadQuery, saveQuery;
	QString mDBTable, mDBColumn, mDBKeyColumn, mDBKeyValue;
	//QSignalMapper *sMapper;
	//NCRDTextPropertyManager *pmText;
	//NCRDShapePropertyManager *pmShape;
	//QString m_defaultReportDir;
	//QFont m_defaultFont;
	NCRDPreferences preferences;
	QString m_copyXML;
	QProgressDialog *progress;
	
	QMenu* mnFile;
	QMenu* mnReport;
	QMenu* mnEdit;
	QMenu* mnView;
	QMenu* mnTools;
	QMenu* mnFormat;
	QMenu* mnAlign;
	QMenu* mnHelp;
	QMenu* mnWindow;
	QMenu* mnConn;
	QMenu* mnRecent;
	
	QToolBar *tbFile;
	QToolBar *tbReport;
	QToolBar *tbConnection;
	QToolBar *tbEdit;
	QToolBar *tbTools;
	QToolBar *tbAlign;
	QToolBar *tbTextProps;
	QToolBar *tbShapeProps;
	QToolBar *tbDimProps;
	
	QAction *act_file_new;
	QAction *act_file_open;
	QAction *act_file_opendb;
	QAction *act_file_save;
	QAction *act_file_saveas;
	QAction *act_file_options;
	QAction *act_file_exit;
	
	QAction *act_report_details;
	QAction *act_report_pagesettings;
	QAction *act_report_variables;
	QAction *act_report_datasources;
	QAction *act_report_sqleditor;
	QAction *act_report_connectdb;
	QAction *act_report_disconnectdb;
	QAction *act_report_runreport;
	QAction *act_report_runreportpreview;
	QAction *act_report_testdata;
	QAction *act_report_edititem;
	QAction *act_report_editsection;
	
	QAction *act_view_showgrid;
	QAction *act_view_snapgrid;
	QAction *act_view_zoomin;
	QAction *act_view_zoomout;
	QAction *act_view_zoom1;
	QAction *act_view_showpropedit;
	QAction *act_view_showdstree;
	
	QAction *act_edit_copy;
	QAction *act_edit_paste;
	QAction *act_edit_cut;
	QAction *act_edit_delete;
	QAction *act_edit_undo;
	QAction *act_edit_redo;
	
	QAction *act_win_close;
	QAction *act_win_closeall;
	QAction *act_win_tile;
	QAction *act_win_cascade;
	QAction *act_win_next;
	QAction *act_win_previous;
	
	QAction *act_help_about;
	QAction *act_help_aboutqt;
	
	QAction *act_tool_arrow;
	QAction *act_tool_label;
	QAction *act_tool_text;
	QAction *act_tool_field;
	QAction *act_tool_rect;
	QAction *act_tool_line;
	QAction *act_tool_ellipse;
	QAction *act_tool_img;
	QAction *act_tool_barcode;
	QAction *act_tool_graph;
	
	QAction *act_align_front;
	QAction *act_align_back;
	QAction *act_align_forward;
	QAction *act_align_backward;
	QAction *act_align_left;
	QAction *act_align_right;
	QAction *act_align_hcenter;
	QAction *act_align_vcenter;
	QAction *act_align_top;
	QAction *act_align_bottom;
	QAction *act_align_sameheight;
	QAction *act_align_samewidth;

	QAction *act_separator;
	QAction *act_test;
	
	QAction *separatorAct;
	enum { MaxRecentFiles = 5 };
	QAction *recentFileActs[MaxRecentFiles];	
private:
	QString lastDir;
};

#endif
