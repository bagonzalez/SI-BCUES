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
#ifndef NCREPORTPREVIEWOUTPUT_H
#define NCREPORTPREVIEWOUTPUT_H

#include "ncreportoutput.h"
#include <QList>

class QPicture;

/*!
Print Preview Output class. NCReportPreviewOutput is used by NCReportPreviewWindow. 
For previewing the contents of NCReportPreviewOutput, this object must be added to 
NCReportPreviewWindow by NCReportPreviewWindow::setOutput( NCReportPreviewOutput* ) function.
*/
class NCREPORT_LIB_API NCReportPreviewOutput : public NCReportOutput
{
public:
	NCReportPreviewOutput( QObject* parent=0 );
	~NCReportPreviewOutput();
	
	QPicture* page( int );
	const QList<QPicture*>& pages();
	
	bool setup();
	void cleanup();
	void begin();
	void end();
	void newPage();
	//QDomDocument xmlOutput() const;
private:
	QList<QPicture*> m_pages;
};

#endif
