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
#ifndef NCRDRUNNERDIALOG_H
#define NCRDRUNNERDIALOG_H

#include <QDialog>
#include "ui_starterdialog.h"

class NCRDMainWindow;
class NCRDDocument;

/*!
Dialog class for running reports from inside of designer
*/
class NCRDRunnerDialog : public QDialog, private Ui::NCRDRunnerDialogUI
{
  Q_OBJECT

public:
	NCRDRunnerDialog( NCRDMainWindow *mw, NCRDDocument *doc, QWidget* parent = 0, Qt::WFlags fl = 0 );
	~NCRDRunnerDialog();
  
  enum Output { Preview=0, Printer, Pdf };
  
  /*$PUBLIC_FUNCTIONS$*/
	void runReport();
	void saveParams();
	void loadParams();

public slots:
  /*$PUBLIC_SLOTS$*/

protected:
  /*$PROTECTED_FUNCTIONS$*/

protected slots:
  /*$PROTECTED_SLOTS$*/
	void addParam();
	void removeParam();
private:
	NCRDMainWindow *mainwindow;
	NCRDDocument *document;
	
	void addParam(const QString& name, const QString& value);
	
};

#endif

