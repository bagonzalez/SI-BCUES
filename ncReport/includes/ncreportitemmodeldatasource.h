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
#ifndef NCREPORTITEMMODELDATASOURCE_H
#define NCREPORTITEMMODELDATASOURCE_H

#include "ncreportdatasource.h"

class QAbstractItemModel;

/*!
Datasource class for QAbstractItemModel based data
 */
class NCReportItemModelDataSource : public NCReportDataSource
{
	Q_OBJECT
public:
	NCReportItemModelDataSource( QObject *parent=0 );
    ~NCReportItemModelDataSource();
	
	bool open();
	bool close();
	bool first();
	bool last();
	bool next();
	bool prevoius();
	int size() const;
	
	QVariant value( const QString&, int nQTDataRole = -1) const;
	QVariant value( int, int nQTDataRole = -1) const;
	
	bool read( NCReportXMLReader* );
	bool write( NCReportXMLWriter* );
	void evaluate( NCReportEvaluator* );

	void setItemModel( QAbstractItemModel* );
	QAbstractItemModel* itemModel() const;
	void setModelID( const QString& );
	QString modelID() const;
			
protected:
	virtual bool checkModel();
private:
	QAbstractItemModel *model;
	QString modelid;
};



#endif
