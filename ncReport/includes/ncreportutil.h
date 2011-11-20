/****************************************************************************
* 
*  Copyright (C) 2002-2007 Norbert Szabo /Helta Kft. All rights reserved.
*  nszabo@helta.hu
*  www.helta.hu/ncreport
* 
*  This file is part of the NCReport reporting software
* 
*  This file may be used under the terms of the GNU General Public
*  License version 2.0 as published by the Free Software Foundation
*  and appearing in the file LICENSE.GPL included in the packaging of
*  this file.  Please review the following information to ensure GNU
*  General Public Licensing requirements will be met:
*  http://www.opensource.org/licenses/gpl-license.php
* 
*  If you are unsure which license is appropriate for your use, please
*  review the following information:
*  http://www.helta.hu/ncreport/price.html or contact me at
*  nszabo@helta.hu
* 
*  This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
*  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
****************************************************************************/
#ifndef NCREPORTUTIL_H
#define NCREPORTUTIL_H

class QGraphicsItem;
class NCReportItem;

class NCReportUtil 
{
public:
	static NCReportItem *castToNCReportItem( QGraphicsItem* );

	
};

#endif
