/****************************************************************************
*
*  Copyright (C) 2002-2009 Helta Kft. / NociSoft Software Solutions
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
#ifndef NCREPORTQTPREVIEWOUTPUT_H
#define NCREPORTQTPREVIEWOUTPUT_H

#include "ncreportoutput.h"

class QPrintPreviewDialog;

/*!
Qt Print preview output class
*/
class NCREPORT_LIB_API NCReportQtPreviewOutput : public NCReportPrinterOutput
{
	Q_OBJECT
public:
	NCReportQtPreviewOutput(QObject* parent=0);
	virtual ~NCReportQtPreviewOutput();
	//virtual bool printDialog( QPrinter *pr );
	virtual bool setup();
	QPrintPreviewDialog *dialog();
	void setReport( NCReport* );
	void begin();
	void end();

private slots:
	void printPreview(QPrinter *);
private:
	QPrintPreviewDialog *m_preview;
	NCReport *m_report;
};

#endif // NCREPORTQTPREVIEWOUTPUT_H
