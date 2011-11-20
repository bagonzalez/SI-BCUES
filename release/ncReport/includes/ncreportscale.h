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
#ifndef NCREPORTSCALE_H
#define NCREPORTSCALE_H

#include <QtGlobal>
#include <QPointF>
#include <QSize>

/*!
This class is responsible for conversion from pixel into metric measurement and vice versa
 */
class NCReportScale
{
public:
    NCReportScale();
    NCReportScale( qreal dpi );
    ~NCReportScale();

	void setScreenResolution();
	void setPrinterResolution( int dpi=0 );
	
	void setDPI( qreal dpi );
	
	qreal pixelToMM( int pixel );
	qreal pixelToMM( qreal pixel );
	int mmToPixel( qreal mm );
	qreal mmToRealPixel( qreal mm ) const;
	QPointF pointToMM( const QPointF& point ) const;
	QPointF mmToPoint( const QPointF& pointMM ) const;
	QSizeF sizeToMM( const QSizeF& size ) const;
	QSizeF mmToSize( const QSizeF& sizeMM ) const;
private:
	qreal _dpi;
};

#endif
