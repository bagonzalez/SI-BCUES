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
#ifndef NCREPORTEVALUATOR_H
#define NCREPORTEVALUATOR_H

#include <QString>
#include <QVariant>
#include <QScriptEngine>

class NCReportDef;
class NCReportDataSource;
class NCReportFieldData;
class NCReportVariable;
class NCReportGroup;
class NCReportDirector;
class NCReportItemData;

/*!
This class is responsible for evaluating fields, variables, dynmic items and script expressions.\n
NCReportEvaluator also evaluates the specified logical grouping conditions.
Used by NCReportDirector.
*/
class NCReportEvaluator
{
public:
    NCReportEvaluator();
    NCReportEvaluator( NCReportDef* );
    ~NCReportEvaluator();
	
	enum ExpType { DataSource=0, Parameter, Variable };
	
	void setReportDef( NCReportDef* );
	void setDirector( NCReportDirector* );
	
	bool evaluate( QString& exp );
	bool evaluate( QString& exp, ExpType );
	bool evaluateScript( const QString & exp, QString& result );
	bool evaluateScript( const QString & exp, bool& result );
	bool evaluateScript( const QString & exp, double& result );
	bool evaluateScript( const QString & exp, QVariant& result );
	bool evaluateField( NCReportFieldData* field );
	bool evaluateVariable( NCReportVariable* var );
	bool evaluateGroup( NCReportGroup* g );
	bool evaluatePrintWhen( const QString& expr );
	bool evaluateDynamicItem( NCReportItemData* );
	static bool loadContentFromTextFile( const QString& fname, QString& content );
private:
	QScriptEngine engine;
	NCReportDef *rdef;
	NCReportDirector *director;
	bool eval( QString& expr, ExpType type, const QString& token );
	bool getDataSourceValue( const QString& name, QVariant& val);
	//HRaba
	int getItemRoleInfo(QString& name);

	bool getParameterValue( const QString& name, QVariant& val );
	bool getVariableValue( const QString& name, QVariant& val );
	bool getSysVarValue( const QString& name, QVariant& val );
	
	bool evaluateDynamicText( NCReportItemData* );
	bool evaluateDynamicImage( NCReportItemData* );
	bool evaluateDynamicGraph( NCReportItemData* );
	bool evaluateDynamicBarcode( NCReportItemData* );

};

#endif
