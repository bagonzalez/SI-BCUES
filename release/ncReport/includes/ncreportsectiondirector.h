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
#ifndef NCREPORTSECTIONDIRECTOR_H
#define NCREPORTSECTIONDIRECTOR_H

#include <QMap>
#include <QSet>
#include <QList>

class NCReportDirector;
class NCReportSection;
class NCReportItem;

class NCReportSectionDirector
{
public:
	NCReportSectionDirector( NCReportDirector *director, NCReportSection *section );
    ~NCReportSectionDirector();
	
	class NCReportZone 
	{
		public:
			NCReportZone() : id( -1 ), startY(0), endY(0), offsetY(0), visible(false) {}
					
			int id;
			qreal startY, endY, offsetY;
			bool visible;
			QList<NCReportItem*> items;
			
			qreal heightMM() const { return endY - startY; }
	};
	
	bool renderSection();
	bool simpleRenderSection();
	
private:
	NCReportDirector *rd;
	NCReportSection *mSection;
	QMap<int,NCReportZone> zones;
	QSet<NCReportItem*> hiddenItems;
	qreal mTotalZonesHeight;	// height of all zones
	
	bool loadZones();
	bool checkSpace( const qreal spaceMM );
	bool renderItems();
	bool renderZones();
	bool renderZoneItems( const NCReportZone& );
	bool printWhen( NCReportItem *item );
	
	void setItemHidden( NCReportItem *item );
	bool itemIsHidden( NCReportItem *item );
	
	/*! Updates the height of the actual section depending on dynamic settings. If the height is changed it is written to height parameter*/
	//void updateDynamicSectionHeight( NCReportSection*, NCReportItem*, qreal& height );
	void adjustSize( NCReportItem* );
	//void afterRenderItem( NCReportItem* );
	
};

#endif
