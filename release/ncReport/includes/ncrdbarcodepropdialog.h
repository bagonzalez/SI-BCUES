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
#ifndef NCRDBARCODEPROPDIALOG_H
#define NCRDBARCODEPROPDIALOG_H

#include <QDialog>
#include "ui_barcodepropdialog.h"
#include "ncreportbarcodeitem.h"

class NCRDDocument;
class NCReportItem;

/*!
Barcode's properties dialog class
*/
class NCRDBarcodePropDialog : public QDialog, private Ui::NCRDBarcodePropDialogUI
{
	Q_OBJECT
public:
  NCRDBarcodePropDialog( NCReportItem *item, NCRDDocument* parent, Qt::WFlags fl = 0 );
  ~NCRDBarcodePropDialog();

  enum OptionWidgetTypes { CheckBox=0, RadioButton };

  /*$PUBLIC_FUNCTIONS$*/
	void applyChanges();
	void applyOptions();
	void discardChanges();

public slots:
  /*$PUBLIC_SLOTS$*/

protected:
  /*$PROTECTED_FUNCTIONS$*/

protected slots:
  /*$PROTECTED_SLOTS$*/
	void changeOptions();
	void compositeEnable();
	void compositeEANCheck();
	void datamatrixOptions();
	void maxiPrimary();
	void apply( QAbstractButton* );

private:
	NCReportItem *m_item;
	NCRDDocument *m_doc;
	QWidget *m_optionWidget;
	int m_barcodeType;

	void loadTab( const QString& uifile, const QString& caption );
	void loadOptions();
	void loadOption( const QString& id );
	void setOption( const QString& id );
};

#endif

