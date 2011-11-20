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
#ifndef NCRDSECTIONDIALOG_H
#define NCRDSECTIONDIALOG_H

#include <QDialog>
#include "ui_sectionpropdialog.h"

class NCRDDesignSection;
class NCRDDocument;

class NCRDSectionDialog : public QDialog, private Ui::NCRDSectionDialogUI
{
  Q_OBJECT

public:
	NCRDSectionDialog( NCRDDocument *, NCRDDesignSection*, QWidget* parent = 0, Qt::WFlags fl = 0 );
	~NCRDSectionDialog();
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
	NCRDDocument *m_document;
	NCRDDesignSection *m_dsect;
	double mPrevHeight;

};

#endif

