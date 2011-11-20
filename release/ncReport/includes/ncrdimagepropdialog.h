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
#ifndef NCRDIMAGEPROPDIALOG_H
#define NCRDIMAGEPROPDIALOG_H

#include <QDialog>
#include "ui_imagepropdialog.h"

#ifdef USE_QIMAGE_INSTEAD_OF_QPIXMAP
#include <QImage>
#else
#include <QPixmap>
#endif

class NCRDDocument;
class NCReportItem;

/*!
Image item properties dialog class
*/
class NCRDImagePropDialog : public QDialog, private Ui::NCRDImagePropDialogUI
{
  Q_OBJECT

public:
  NCRDImagePropDialog( NCReportItem *item, NCRDDocument* parent, Qt::WFlags fl = 0 );
  ~NCRDImagePropDialog();
  /*$PUBLIC_FUNCTIONS$*/
	void applyChanges();
	void discardChanges();

public slots:
  /*$PUBLIC_SLOTS$*/

protected:
  /*$PROTECTED_FUNCTIONS$*/

protected slots:
  /*$PROTECTED_SLOTS$*/
	void selectFile();
	void updateEnabled( bool );
	void updatePreview();
	void fileChanged();

private:
	NCReportItem *m_item;
	NCRDDocument *m_doc;
#ifdef USE_QIMAGE_INSTEAD_OF_QPIXMAP
	QImage m_image;
#else
	QPixmap m_image;
#endif
	QString svgXmlText;

};

#endif

