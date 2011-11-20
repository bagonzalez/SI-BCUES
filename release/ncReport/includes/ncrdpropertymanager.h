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
#ifndef NCRDPROPERTYMANAGER_H
#define NCRDPROPERTYMANAGER_H

#include <QObject>
#include <QPointer>

#include "ncrdsectionscene.h"
#include "ncrddocument.h"

class NCRDMainWindow;
class QToolBar;
class QMenu;

class NCReportItem;
class NCRDSectionScene;

/*!
This is an abstract manager class provides managing the connection between report items and the specified toolbars.\n
*/
class NCRDPropertyManager : public QObject
{
	Q_OBJECT
public:
    NCRDPropertyManager( NCRDMainWindow* parent );
    ~NCRDPropertyManager();
	
	void setDocument( NCRDDocument* );
	void setScene( NCRDSectionScene* );
	QToolBar* toolbar();
	QMenu* menu();
	
	virtual void setEnabled( bool );
	virtual void buildMenu(QMenu*);
	virtual void buildToolBar(QToolBar*);
	virtual void applyPropsToItem( NCReportItem* ) =0;
	virtual void applyPropsToManager( NCReportItem* ) =0;
	virtual void reset();
	virtual void applyChanges();
	
protected:
	QToolBar* m_toolbar;
	QMenu* m_menu;
	NCRDMainWindow *m_mainwin;
	QPointer<NCRDSectionScene> m_scene;
	QPointer<NCRDDocument> m_doc;
};

#endif
