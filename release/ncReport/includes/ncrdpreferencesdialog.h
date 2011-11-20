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
#ifndef NCRDPREFERENCESDIALOG_H
#define NCRDPREFERENCESDIALOG_H

#include <QDialog>
#include "ui_preferencesdialog.h"
#include "ncrdpreferences.h"

class NCRDPreferencesDialog : public QDialog, private Ui::NCRDPreferencesDialogUI
{
  Q_OBJECT

public:
  NCRDPreferencesDialog(QWidget* parent = 0, Qt::WFlags fl = 0 );
  ~NCRDPreferencesDialog();
  /*$PUBLIC_FUNCTIONS$*/
  void load( NCRDPreferences& );
  void save( NCRDPreferences& );
  
public slots:
  /*$PUBLIC_SLOTS$*/
	void resetGrid();
	void openDir();
	void showFontSample();

protected:
  /*$PROTECTED_FUNCTIONS$*/

protected slots:
  /*$PROTECTED_SLOTS$*/

};

#endif

