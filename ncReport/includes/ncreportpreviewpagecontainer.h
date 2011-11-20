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
#ifndef NCREPORTPREVIEWPAGECONTAINER_H
#define NCREPORTPREVIEWPAGECONTAINER_H

#include <QWidget>
#include <QPoint>

#define MAX_PAGES	4

class NCReportPreviewPage;

/*!
Container widget class for storing the current report preview page(s) in a QScrollWidget
*/
class NCReportPreviewPageContainer : public QWidget
{
public:
    NCReportPreviewPageContainer( QWidget * parent );
	~NCReportPreviewPageContainer();
	
	enum ShowType { Single=0, Double, Quatro };
	
	void setShowType( const ShowType );
	void setMargins( int left, int right, int top, int bottom );
    void setPageSize( const QSizeF& mmsize );
	void loadPage( const QList<QPicture*>&, int pageno );
	void scale(qreal factor);
	qreal currentScaleFactor() const;

protected:
    //void paintEvent( QPaintEvent* );
	void updateSizeAndPos();

private:
	int m_leftMargin, m_rightMargin, m_topMargin, m_bottomMargin;
	ShowType m_showType;
	int numpagesviewable;
	qreal currentscalefactor;
	NCReportPreviewPage* pages[MAX_PAGES];
	QPoint topLefts[MAX_PAGES];
};

#endif
