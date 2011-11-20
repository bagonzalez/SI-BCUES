/****************************************************************************
** Meta object code from reading C++ file 'manttoinventario.h'
**
** Created: Thu Apr 21 08:50:11 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SIBCUES-GUI/InventarioBienesGUI/manttoinventario.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manttoinventario.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ManttoInventario[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      42,   17,   17,   17, 0x08,
      74,   68,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ManttoInventario[] = {
    "ManttoInventario\0\0on_botonMenos_clicked()\0"
    "on_botonAgregar_clicked()\0index\0"
    "on_modeloTabla_activated(QModelIndex)\0"
};

const QMetaObject ManttoInventario::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ManttoInventario,
      qt_meta_data_ManttoInventario, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ManttoInventario::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ManttoInventario::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ManttoInventario::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ManttoInventario))
        return static_cast<void*>(const_cast< ManttoInventario*>(this));
    return QDialog::qt_metacast(_clname);
}

int ManttoInventario::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_botonMenos_clicked(); break;
        case 1: on_botonAgregar_clicked(); break;
        case 2: on_modeloTabla_activated((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
