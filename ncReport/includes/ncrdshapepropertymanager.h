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
#ifndef NCRDSHAPEPROPERTYMANAGER_H
#define NCRDSHAPEPROPERTYMANAGER_H

#include "ncrdpropertymanager.h"
#include <QPen>
#include <QBrush>
#include <QColor>

class QAction;
class QFontComboBox;
class QComboBox;
class QActionGroup;
class QDoubleSpinBox;

/*!
This is a manager class provides managing the connection between shape based report items and the specified toolbar.\n
 */
class NCRDShapePropertyManager : public NCRDPropertyManager
{
	Q_OBJECT
public:
    NCRDShapePropertyManager( NCRDMainWindow* parent );
    ~NCRDShapePropertyManager();
	
	void setEnabled( bool );
	void applyPropsToItem( NCReportItem* );
	void applyPropsToManager( NCReportItem* );
	void buildMenu(QMenu*);
	void buildToolBar(QToolBar*);
	void reset();
	QPen pen() const;
	QBrush brush() const;
	QColor currentLineColor() const;
	QColor currentFillColor() const;
			
public slots:
	void lineStyle( int idx );
	void lineWidth( double w );
	void lineColor();
	void fillPattern( int idx );
	void fillColor();
	
private:
    void penChanged(const QPen &p);
    void brushChanged(const QBrush &b);
    void lineColorChanged(const QColor &c);
    void lineWidthChanged(double w);
    void fillColorChanged(const QColor &c);
	
	QAction *actLineColor, *actFillColor;
	QComboBox *comboLineStyle, *comboBrush;
	QDoubleSpinBox *spinLineWidth;
	QPen m_pen;
	QBrush m_brush;
	QColor m_lineColor, m_fillColor;
};


#endif
