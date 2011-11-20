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
#ifndef NCRDTESTDATAREADER_H
#define NCRDTESTDATAREADER_H

#include <QXmlStreamReader>

#define TESTDATAMODEL_COL_ID		0
#define TESTDATAMODEL_COL_DSTYPE	1
#define TESTDATAMODEL_COL_ENABLED	2
#define TESTDATAMODEL_COL_TEXTDATA	3

#define TESTDATAMODEL_COLUMNCOUNT	4

class QStandardItemModel;
class QIODevice;

/*!
Test data structure
 */
struct NCRDTestData
{
	QString id;
	int type;
	bool enabled;
	QString data;
};


/*!
Reads (text format) test data from XML file to QStandardItemModel 
*/
class NCRDTestDataReader : public QXmlStreamReader
{
public:
	NCRDTestDataReader();
	~NCRDTestDataReader();
	bool read( const QString& filename );
	bool read(QIODevice *device );
	
	QStandardItemModel* model();
	void setModel( QStandardItemModel* );
	
	bool isAttrib( const QString& name );
	QStringRef attrib( const QString& name );
	static void appendModel( QStandardItemModel *m, const NCRDTestData& data );
	
private:
	QString basetag;
	QStandardItemModel *m_model;
	
	void readContents();
	void readOptions();
	void readData();
	void readUnknownElement();
};

#endif
