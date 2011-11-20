/****************************************************************************
** Meta object code from reading C++ file 'catalogoactivofijogui.h'
**
** Created: Thu Apr 21 08:49:43 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SIBCUES-GUI/CatalogoActivoFijoGUI/catalogoactivofijogui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'catalogoactivofijogui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CatalogoActivoFijoGUI[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x0a,
      49,   22,   22,   22, 0x0a,
      73,   22,   22,   22, 0x0a,
     105,   22,   22,   22, 0x0a,
     139,   22,   22,   22, 0x0a,
     172,   22,   22,   22, 0x0a,
     205,   22,   22,   22, 0x08,
     229,   22,   22,   22, 0x08,
     257,   22,   22,   22, 0x08,
     297,  280,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CatalogoActivoFijoGUI[] = {
    "CatalogoActivoFijoGUI\0\0on_botonGuardar_pressed()\0"
    "on_botonNuevo_pressed()\0"
    "on_botonGuardarBiblio_pressed()\0"
    "on_numeroCuenta_editingFinished()\0"
    "on_nombreClase_editingFinished()\0"
    "on_claseBiblio_editingFinished()\0"
    "on_pushButton_clicked()\0"
    "on_btmSeleccionar_clicked()\0"
    "on_btmBuscar_clicked()\0current,previous\0"
    "on_catalogoInventario_currentItemChanged(QTreeWidgetItem*,QTreeWidgetI"
    "tem*)\0"
};

const QMetaObject CatalogoActivoFijoGUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CatalogoActivoFijoGUI,
      qt_meta_data_CatalogoActivoFijoGUI, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CatalogoActivoFijoGUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CatalogoActivoFijoGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CatalogoActivoFijoGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CatalogoActivoFijoGUI))
        return static_cast<void*>(const_cast< CatalogoActivoFijoGUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int CatalogoActivoFijoGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_botonGuardar_pressed(); break;
        case 1: on_botonNuevo_pressed(); break;
        case 2: on_botonGuardarBiblio_pressed(); break;
        case 3: on_numeroCuenta_editingFinished(); break;
        case 4: on_nombreClase_editingFinished(); break;
        case 5: on_claseBiblio_editingFinished(); break;
        case 6: on_pushButton_clicked(); break;
        case 7: on_btmSeleccionar_clicked(); break;
        case 8: on_btmBuscar_clicked(); break;
        case 9: on_catalogoInventario_currentItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
