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
#ifndef NCRDDATASOURCETYPEDIALOG_H
#define NCRDDATASOURCETYPEDIALOG_H

#include <QDialog>
#include "ui_dstypedialog.h"
#include "ncreportdatasource.h"

/*!
Datasource type selector dialog class
*/
class NCRDDataSourceTypeDialog : public QDialog, private Ui::NCRDDataSourceTypeDialogUI
{
  Q_OBJECT

public:
  NCRDDataSourceTypeDialog(QWidget* parent = 0, Qt::WFlags fl = 0 );
  ~NCRDDataSourceTypeDialog();
  /*$PUBLIC_FUNCTIONS$*/
  
	NCReportDataSource::DataSourceType selectedType() const;

public slots:
  /*$PUBLIC_SLOTS$*/

protected:
  /*$PROTECTED_FUNCTIONS$*/

protected slots:
  /*$PROTECTED_SLOTS$*/

};

#endif

