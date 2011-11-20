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
#ifndef NCREPORTSECTION_H
#define NCREPORTSECTION_H


#include <QGraphicsScene>

class NCReportGroup;
class QGraphicsSceneContextMenuEvent;
class NCReportItem;

/*!
Report section scene's data class. The class stores the section's properties
 */
class NCReportSectionData
{
public:
	NCReportSectionData();
	~NCReportSectionData();
	
	enum SectionType { PageHeader=0, PageFooter, GroupHeader, GroupFooter, Detail,
		ReportHeader, ReportFooter, Custom };
	enum SpaceCheckRole { SectionOnly=0, SectionPlusDetail };

	bool finished();
	void setFinished( bool );
		
	SectionType type;
	SpaceCheckRole checkRole;
	qreal mHeight;
	bool show;
	bool finish;
	bool autoHeight;
	bool hideIfBlank;
	QString id;
	QString caption;
	
	//detail properties
	QString tagname;
	QString datasource;
	QList<NCReportGroup*> groups;
	int layoutIndex;	// index for internal purpuses in designer
	QString pageBreakExp;
	bool startsOnNewPage; // if multiple details >1
	QString printWhenExp;
};

//------------- SECTION -------------------------------------

/*!
Report section scene. This is the basic section scene in which the report sections based on.
*/
class NCReportSection : public QGraphicsScene
{
	Q_OBJECT
public:
	NCReportSection( QObject* parent );
	virtual ~NCReportSection();
	
	NCReportSectionData* data();
	
	inline bool gridVisible() const   { return m_gridVisible; }
	void setGridVisible(bool visible) { m_gridVisible = visible; }
	
	inline bool snapX() const     { return m_snapX; }
	void setSnapX(bool snap)      { m_snapX = snap; }
	
	inline bool snapY() const     { return m_snapY; }
	void setSnapY(bool snap)      { m_snapY = snap; }
	
	inline int deltaX() const     { return m_deltaX; }
	void setDeltaX(int dx)        { m_deltaX = dx; }
	
	inline int deltaY() const     { return m_deltaY; }
	void setDeltaY(int dy)        { m_deltaY = dy; }
	
    QPointF snapToPoint(const QPointF &p) const;
    qreal snapToX(const qreal) const;
    qreal snapToY(const qreal) const;
	int nextZValue();
	void resetZValue();
	/*! Adds report item to scene and sets the specified Z-order. Virtual function for differeces between engine and designer */
	virtual void addItemZ( NCReportItem* );
	/*! Adds report item to scene for report engine only.*/
	virtual void addItemForEngine( NCReportItem* );

	/*! Virtual function for emiting changes when used in editor*/
	virtual void emitContentChanged();
	virtual void emitItemChanged( NCReportItem* );
	//void setVirtualMargin( qreal left, qreal right, qreal top, qreal bottom );
	//QPointF mapToMargin( const QPointF & point ) const;
	QList<NCReportItem*>& reportItems() { return m_itemList; }

protected:
	NCReportSectionData *d;
private:
	//qreal leftMargin, rightMargin, topMargin, bottomMargin;
    bool m_gridVisible;
    bool m_snapX;
    bool m_snapY;
    int m_deltaX;
    int m_deltaY;
	int zvalue;
	QList<NCReportItem*> m_itemList;

private:
	int snapValue(int value, int grid) const;
};

#endif
