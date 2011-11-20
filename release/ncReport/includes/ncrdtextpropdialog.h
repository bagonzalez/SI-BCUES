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
#ifndef NCRDTEXTPROPDIALOG_H
#define NCRDTEXTPROPDIALOG_H

#include <QDialog>
#include "ui_textpropdialog.h"

class NCRDDocument;
class NCReportItem;

class NCRDTextPropDialog : public QDialog, private Ui::NCRDTextPropDialogUI
{
  Q_OBJECT

public:
	NCRDTextPropDialog(NCReportItem *item, NCRDDocument* parent = 0, Qt::WFlags fl = 0 );
	~NCRDTextPropDialog();
	
  /*$PUBLIC_FUNCTIONS$*/
	void setDefaultFont( const QFont& );
	
	void applyChanges();
	void discardChanges();
  
public slots:
  /*$PUBLIC_SLOTS$*/

protected:
  /*$PROTECTED_FUNCTIONS$*/

protected slots:
  /*$PROTECTED_SLOTS$*/
	void textBold();
	void textUnderline();
	void textItalic();
	void textFamily(const QString &f);
	void textSize(const QString &p);
	void textStyle(int styleIndex);
	void textColor();
	void textAlign();
	
	void currentCharFormatChanged(const QTextCharFormat &format);
	void cursorPositionChanged();
	void htmlEditChanged();
	void textEditChanged();
	
	void comboSourceTypeChanged(int = -1);
	void selectFile();
	void checkBoxChanged(int);
	void tabChanged(int);
private:
	void mergeFormatOnWordOrSelection(const QTextCharFormat &);
	void fontChanged(const QFont &f);
	void colorChanged(const QColor &c);
	void alignmentChanged(Qt::Alignment a);
		
private:
	NCReportItem *m_item;
	NCRDDocument *m_doc;
	bool m_htmlChanged, m_textChanged;
};

#endif

