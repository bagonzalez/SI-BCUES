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
#ifndef NCREPORTTEXTITEM_H
#define NCREPORTTEXTITEM_H

#include "ncreportitem.h"

#include <QString>
#include <QColor>
#include <QFont>

#define NCRD_DEFAULT_TEXT 	"Html text"

class QTextDocument;

/*!
Html/Rich text item's data class
 */
class NCReportTextData : public NCReportItemData
{
public:
	NCReportTextData();
	void setHtml( const QString& );

	bool sizeFix;	// fix the document's height
	bool useFont;
	bool defaultPosAndSize;	// default pos and size for if text document print mode
	QString filename;
	QTextDocument *document;
	QString documentTemplate;	// document template for "mixed" source
	qreal requiredHeightMM;		// required printable height in MM
	//qreal printedHeightMM;		// height in MM that has been printed already
	QColor forecolor;
	QFont font;
};

/*!
Html/Rich text item class
 */
class NCReportTextItem : public NCReportItem
{
public:
	NCReportTextItem( QGraphicsItem * parent=0 );
	~NCReportTextItem();
	
	int type() const;
	bool read( NCReportXMLReader* );
	bool write( NCReportXMLWriter* );
	void setDefaultForEditor();
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void paint( NCReportOutput*, const QPointF& );
	void adjustSize();
	void adjustSize(NCReportOutput* =0);
	void resize( const QSizeF& );
	bool isEmpty();
	
	//void adjustDocument( NCReportOutput* );

protected:
	void readProps( NCReportXMLReader* );
	void writeProps( NCReportXMLWriter* );
	/*! Font adjustment for MAC users */
	virtual void adjustFont( NCReportOutput* =0 );
	
private:
};

#endif
