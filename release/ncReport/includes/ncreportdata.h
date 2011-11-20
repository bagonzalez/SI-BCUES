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
#ifndef NCREPORTDATA_H
#define NCREPORTDATA_H

#include <QVariant>
#include <QString>

#ifdef Q_WS_WIN
#	if defined(NCREPORT_EXPORT)
#		define NCREPORT_LIB_API __declspec(dllexport)
#	elif defined(NCREPORT_IMPORT) 
#		define NCREPORT_LIB_API __declspec(dllimport)
#	else
#		define NCREPORT_LIB_API
#	endif
#else
#	define NCREPORT_LIB_API
#endif

/*!
NCReport base data class
*/

class NCREPORT_LIB_API NCReportData
{
public:
	enum DataType { Text=0, Numeric, Date, DateTime, Boolean, Image, Custom };

	NCReportData();
	NCReportData( DataType );
	~NCReportData();

	void setDataType( DataType );
	void setDataType( const QString& tname );
	void setID( const QString& );
	QString id() const;

	void setValue( const QVariant&, DataType );
	void setValue( const QVariant& );
	QVariant value() const;
	DataType type() const;
	QString typeName() const;
	QVariant& valueRef();
	
private:
	QVariant val;
	DataType dType;
	QString dID;
};

#endif
