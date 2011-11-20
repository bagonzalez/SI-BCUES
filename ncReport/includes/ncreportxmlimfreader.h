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
#ifndef NCREPORTXMLIMFREADER_H
#define NCREPORTXMLIMFREADER_H

#include "ncreportxmlreader.h"

class QStringList;
class QTextStream;

/*!
IT WAS JUST A TEST AND NOT USED!\n
Intermediate XML format reader. Hungarian comment: Beolvassa az egesz report tartalmat, az oldalankenti\n
informaciokat nem dolgozza fol, hanem egy listaba teszi.
*/

class NCReportXMLImfReader : public NCReportXMLReader
{
public:
	NCReportXMLImfReader();
	virtual ~NCReportXMLImfReader();
	virtual bool read(QIODevice *device, const QString& def);
	
	void setPageXMLList( QStringList* list );
protected:
	QStringList *pageList;
	
	virtual void init();
    virtual void readReport();
	virtual void readHtmlText();
	virtual void readPage();
	virtual void readItems( NCReportSection* );	
	virtual void writeItem(QTextStream& ts);	
};


#endif
