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
#ifndef NCCOLORCOMBO_H
#define NCCOLORCOMBO_H

#include <QComboBox>
#include <QColor>

/*!
Combo box class for color selection
*/
class NCColorCombo : public QComboBox
{
    Q_OBJECT
public:
	NCColorCombo( QWidget *parent );
	~NCColorCombo();
	
	void setColor( const QColor &col );
	QColor color() const;
	void setColor( const QString & colorname );
	QString colorName() const;
	
	void showEmptyList();
signals:
	void activated( const QColor &col );
	void highlighted( const QColor &col );

protected:
    virtual void resizeEvent( QResizeEvent *re );

private slots:
    void slotActivated( int index );
    void slotHighlighted( int index );

private:
    void addColors();
	void populateList();
    QColor customColor;
    QColor internalcolor;

private:
	bool _showEmptyList;
};

#endif
