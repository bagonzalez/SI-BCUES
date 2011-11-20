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
#ifndef NCRDRULER_H
#define NCRDRULER_H

#include <QWidget>

/*!
Ruler widget
*/
class NCRDRuler : public QWidget
{
	Q_OBJECT
public:
	NCRDRuler( Qt::Orientation ori, QWidget *parent = 0 );
	~NCRDRuler();
	//void setMeasurement( Measurement* msr ) { m = msr; }
	/*!Ruler margin at left/top before scaling starts*/
	void setRulerMargin( int margin );
	/*!Offset of the scaling in pixel*/
	void setScaleOffset( int point, bool doupdate=FALSE );
	void setZoomScale( qreal );
	
public slots:	
/*	void setZoomLevel( double );
	void changeZoomLevelBy( double );*/
	
protected:
	virtual void paintEvent( QPaintEvent* );		
private:
	int scStart;
	int offset;
	Qt::Orientation orient;
	qreal measureunit;
 	qreal zoomscale;
};

#endif
