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
#ifndef NCREPORTABSTRACTITEMRENDERING_H
#define NCREPORTABSTRACTITEMRENDERING_H

#include <QRectF>
#include <QString>

class QPainter;
class NCReportOutput;

#ifdef Q_WS_WIN
#	if defined(NCREPORT_EXPORT)
#		define NCREPORT_LIB_API __declspec(dllexport)
#	elif defined(NCREPORT_IMPORT) 
#		define NCREPORT_LIB_API __declspec(dllimport)
#	else
#		define NCREPORT_LIB_API
#	endif
#else
#	define NCREPORT_LIB_API
#endif

/*!
Abstract class for custom contents in NCReport. Ideal for creating graphs, drawings or such contents.\n
*/

class NCREPORT_LIB_API NCReportAbstractItemRendering
{
public:
    NCReportAbstractItemRendering();
    virtual ~NCReportAbstractItemRendering();
	
	void setID( const QString& );
	const QString& id() const;
	/*!
	 * Abstract method for painting custom item content into the specified report output
	 * @param painter active QPainter object
	 * @param output current NCReportOutput 
	 * @param rect Rectangle of the item. Positions and size come from report definition
	 * @param itemdata Specification string, come from report definition
	 */
	virtual void paintItem( QPainter* painter, NCReportOutput* output, const QRectF& rect, const QString& itemdata ) =0;
private:
	QString classid;
};

#endif
