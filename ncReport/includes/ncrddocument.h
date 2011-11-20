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
#ifndef NCRDDOCUMENT_H
#define NCRDDOCUMENT_H

#include "ncreportsection.h"
#include "ncreportsource.h"
#include <QScrollArea>
#include <QList>
//#include <QHash>

class QVBoxLayout;
class QSplitter;
class NCRDMainWindow;
class NCRDRuler;
class NCRDDesignSection;
class NCRDSectionScene;
class NCRDDef;
class QUndoStack;
class QMdiSubWindow;
class NCReportDataSource;

/*!
Internal Document source class for storing informations the different load/save ways of a report document
*/
class NCRDDocumentSourceInfo
{
public:
	NCRDDocumentSourceInfo() 
	{
		rsType = NCReportSource::File;
	}
	
	NCReportSource::ReportSourceType rsType;
	QString fileName;
	QString connectionID;
	QString description;
	QString reportColumn;
	QString tableName;
	QString keyColumn;
	QString keyValue;
	
	QString loadQuery() const;
	QString saveQuery() const;
};

/*!
Represents a report document in designer
*/
class NCRDDocument : public QScrollArea
{
    Q_OBJECT

/*	friend class NCRDDetailDialog;
	friend class NCRDGroupDialog;*/
public:
    NCRDDocument( NCRDMainWindow *parent );
	~NCRDDocument();
	
	enum ZoomMode { ZoomIn, ZoomOut, ZoomOne, ZoomFull, ZoomFit };

	void setReportSourceType( NCReportSource::ReportSourceType );
	void newFile(const QString& filename);
	bool load(const NCRDDocumentSourceInfo & si );
    bool save();
	bool saveAs( const QString& fname );
	bool save(const NCRDDocumentSourceInfo & si );
    QString userFriendlyCurrentFile();
	NCRDDocumentSourceInfo currentSourceInfo() { return curSourceInfo; }
	bool isModified();
	void testFunction();
	QUndoStack *undoStack() const;
	void setToolMode();
	void setCurrentDesignSection( NCRDDesignSection* );
	NCRDDesignSection* currentDesignSection();
	void setCurrentScene( NCRDSectionScene* );
	NCRDSectionScene* currentScene();
	
	void setSubWindow( QMdiSubWindow* );
	
	void updateGrid();
	/*! Gets the layout index for the specified section*/
	int sectionIndex( NCReportSection* );
	/*! Updates the entire document by the content of NCReportDef */
	void updateSectionsByReportDef();
	/*! Updates the group sections by the content of NCReportDef */
	void updateGroupSections( NCReportSection *detail );
	void updateSectionOrder();
	/*! Updates the page settings */
	void updatePageSettings();
	NCRDDef* reportDef();
	void removeSection( NCReportSection* );
	void removeGroupSections( NCReportSection* );
	void updateSection( NCReportSection* );
	/*!Find designer section by NCReportSection* (scene) Returns the list id of the designer section if exists, 
	-1 if does not.*/
	int sectionExists( NCReportSection* );
	void sectionPropDialog( NCReportSection* =0 );
	
	qreal purePageWidth() const;
	void adjustContent();
	void initPropertyEditor();
	void setLoadQuery( const QString& );
	void setSaveQuery( const QString& );
	NCReportItem* firstSelectedItem();
	void setDefaultFont( const QFont& );
	void updateManagers();
	
	void bringToFront();
	void moveToBack();
	void alignLeft();
	void alignRight();
	void alignHCenter();
	void alignVCenter();
	void alignTop();
	void alignBottom();
	void alignSameWidth();
	void alignSameHeight();
	void copy();
	void cut();
	void paste();
	
	void keyboardAction( QKeyEvent* );
	void zoom( ZoomMode );
	qreal zoomScale() const;

	void dataSourceColumnNames( QStringList& keywords, NCReportDataSource* =0 ) const;

public slots:
    void documentWasModified();
    void sceneContentModified(const QList<QRectF>& );
	void setModified(bool);
	void slotSectionResized( const QSize & );
	void itemEdit( NCReportItem* );
	void actionManagerChanged();

protected slots:
	void slotSectionClickFocus();	
	void slotSectionFirstItemSelected(NCReportItem*);
	void slotHorizontalScroll(int);
	
protected:
    void closeEvent(QCloseEvent *);
	void scrollContentsBy( int dx, int dy );
private:
    //QString curFile;
	NCRDDocumentSourceInfo curSourceInfo;
    bool isUntitled;
	bool modified;
	enum ItemOperation { BringFront, MoveBack, AlignLeft, AlignRight, 
		AlignHCenter, AlignVCenter, AlignTop, AlignBottom, AlignSameWidth, AlignSameHeight };
	
	QSplitter *split;
	//QHash<QString,NCRDDesignSection*> sections;
	QList<NCRDDesignSection*> sections;
	NCRDDesignSection *m_currentDesignSection;
	QList<int> sectionIndexes;
	NCRDRuler *rulertop;
	QWidget *sectioncontainer;
	QVBoxLayout *laySC;
	NCRDMainWindow *mainwindow;
	NCRDDef* rdef;
	NCRDSectionScene *m_currentScene;
	QUndoStack *m_undostack;
	int m_counter_details;
	NCReportSource::ReportSourceType rstype;
	//HRaba
	NCReportSource m_source;
	QString loadQuery, saveQuery;
	NCReportItem *m_firstSelectedItem;
	QMdiSubWindow *m_subWindow;
	qreal m_zoomScale;

	bool maybeSave();
	void setCurrentSourceInfo(const NCRDDocumentSourceInfo &si );
	QString strippedName(const QString &fullFileName);
	bool loadReportDef();
	void addSection( NCReportSectionData::SectionType );
	/*!Adds a new section to the document by NCReportSection parameter*/
	void addSection( NCReportSection *sect );

	void itemAlignmentOperation( const ItemOperation );	
};

#endif
