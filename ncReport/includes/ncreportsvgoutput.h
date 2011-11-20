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
#ifndef NCREPORTSVGOUTPUT_H
#define NCREPORTSVGOUTPUT_H

#include "ncreportoutput.h"
#include <QList>
#include <QByteArray>

class QSvgGenerator;
class QBuffer;

/*!
SVG Output class. Result pages are stored in separated .svg files
*/
class NCREPORT_LIB_API NCReportSvgOutput : public NCReportOutput
{
public:
	NCReportSvgOutput( QObject* parent=0 );
	~NCReportSvgOutput();

	const QByteArray& page( int ) const;
	const QList<QByteArray>& pages() const;

	bool setup();
	void cleanup();
	void begin();
	void end();
	void newPage();
private:
	QSvgGenerator* m_generator;
	QBuffer *m_buffer;
	QList<QByteArray> m_pages;

	void createPageGenerator();
	void deletePageGenerator();
};

#endif //NCREPORTSVGOUTPUT_H
