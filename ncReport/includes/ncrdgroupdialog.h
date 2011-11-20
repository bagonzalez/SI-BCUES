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
#ifndef NCRDGROUPDIALOG_H
#define NCRDGROUPDIALOG_H

#include <QDialog>
#include "ui_groupdialog.h"

class QStandardItemModel;
class QDataWidgetMapper;
class NCReportSection;
class NCReportGroup;
class NCRDDocument;

/*!
Group/Band properties dialog class
*/
class NCRDGroupDialog : public QDialog, private Ui::NCRDGroupDialogUI
{
  Q_OBJECT

public:
  NCRDGroupDialog( NCRDDocument* doc, NCReportSection *detail, QWidget* parent = 0, Qt::WFlags fl = 0 );
  ~NCRDGroupDialog();
  /*$PUBLIC_FUNCTIONS$*/
	void applyChanges();
	void discardChanges();

public slots:
  /*$PUBLIC_SLOTS$*/

protected:
  /*$PROTECTED_FUNCTIONS$*/

protected slots:
  /*$PROTECTED_SLOTS$*/
	void add();
	void remove();
	void up();
	void down();
	void slotItemChanged( const QModelIndex & current, const QModelIndex & previous );
	void slotVarListChanged(QListWidgetItem*);

private:
	QStandardItemModel* model;
	//QStandardItemModel* modelVars;
	QDataWidgetMapper *mapper;
	QList<NCReportGroup*> removeGroups;
	NCRDDocument *document;
	NCReportSection *m_detail;
	bool internalChange;
	
	void setupModel();
	void setupListVars();
	void appendModel( NCReportGroup*, int row, bool =FALSE );
	void updateVarListFromModel();
	void updateModelFromVarList();
	void updateEnable();
		
};

#endif
