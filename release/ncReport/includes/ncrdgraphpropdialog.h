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
#ifndef NCRDGRAPHPROPDIALOG_H
#define NCRDGRAPHPROPDIALOG_H

#include <QDialog>
#include "ui_graphpropdialog.h"

class NCRDDocument;
class NCReportItem;

/*!
Graph/custom report item properties dialog class
*/
class NCRDGraphPropDialog : public QDialog, private Ui::NCRDGraphPropDialogUI
{
  Q_OBJECT
public:
  NCRDGraphPropDialog( NCReportItem *item, NCRDDocument* parent, Qt::WFlags fl = 0 );
  ~NCRDGraphPropDialog();
  /*$PUBLIC_FUNCTIONS$*/
	void applyChanges();
	void discardChanges();

public slots:
  /*$PUBLIC_SLOTS$*/

protected:
  /*$PROTECTED_FUNCTIONS$*/

protected slots:
  /*$PROTECTED_SLOTS$*/
private:
	NCReportItem *m_item;
	NCRDDocument *m_doc;

};

#endif

