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
#ifndef NCREPORTPREVIEWPAGE_H
#define NCREPORTPREVIEWPAGE_H

#include <QWidget>

class QPicture;
class NCReportScale;

/*!
Report preview page class. Represents one preview page.
 */
class NCReportPreviewPage : public QWidget
{
    Q_OBJECT
public:
    NCReportPreviewPage( QWidget * parent = 0 );
	~NCReportPreviewPage();
	
	void setPicture( QPicture* );
	/*! size in mm */
    void setPageSize( const QSizeF& mmsize );	
    void scale(qreal factor);
	void print( QPainter*, NCReportScale& );
	void clear();
	qreal currentScaleFactor() const;
	
protected:
    void paintEvent( QPaintEvent* );
    void keyPressEvent(QKeyEvent *event);
    //void timerEvent(QTimerEvent *event);
    //void wheelEvent(QWheelEvent *event);
    void drawBackground(QPainter *painter, const QRect & rect );
private:
	//NCReportSection *sc;
	QPicture *picture;
	qreal m_scale;
	QSizeF mSize;	// size in mm

};


#endif
