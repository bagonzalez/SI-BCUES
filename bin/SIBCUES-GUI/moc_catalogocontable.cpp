/****************************************************************************
** Meta object code from reading C++ file 'catalogocontable.h'
**
** Created: Thu Apr 21 08:50:05 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SIBCUES-GUI/CatalogoContableGUI/catalogocontable.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'catalogocontable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CatalogoContable[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      51,   17,   17,   17, 0x0a,
      76,   17,   17,   17, 0x0a,
     102,   17,   17,   17, 0x08,
     130,   17,   17,   17, 0x08,
     155,   17,   17,   17, 0x08,
     180,   17,   17,   17, 0x08,
     204,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CatalogoContable[] = {
    "CatalogoContable\0\0on_Catalogo_currentItemChanged()\0"
    "on_transaccion_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_btmSeleccionar_clicked()\0"
    "on_botonBuscar_clicked()\0"
    "on_crearCuenta_clicked()\0"
    "on_crearRubro_clicked()\0"
    "on_crearEspecifico_clicked()\0"
};

const QMetaObject CatalogoContable::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CatalogoContable,
      qt_meta_data_CatalogoContable, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CatalogoContable::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CatalogoContable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CatalogoContable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CatalogoContable))
        return static_cast<void*>(const_cast< CatalogoContable*>(this));
    return QDialog::qt_metacast(_clname);
}

int CatalogoContable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_Catalogo_currentItemChanged(); break;
        case 1: on_transaccion_clicked(); break;
        case 2: on_pushButton_3_clicked(); break;
        case 3: on_btmSeleccionar_clicked(); break;
        case 4: on_botonBuscar_clicked(); break;
        case 5: on_crearCuenta_clicked(); break;
        case 6: on_crearRubro_clicked(); break;
        case 7: on_crearEspecifico_clicked(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
