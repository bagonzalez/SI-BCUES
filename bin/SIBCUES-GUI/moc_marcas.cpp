/****************************************************************************
** Meta object code from reading C++ file 'marcas.h'
**
** Created: Thu Apr 21 08:50:06 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SIBCUES-GUI/CatalogoActivoFijoGUI/marcas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'marcas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_marcas[] = {

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
       8,    7,    7,    7, 0x08,
      38,    7,    7,    7, 0x08,
      73,   67,    7,    7, 0x08,
     111,   67,    7,    7, 0x08,
     149,    7,    7,    7, 0x08,
     174,    7,    7,    7, 0x08,
     202,    7,    7,    7, 0x08,
     233,    7,    7,    7, 0x08,
     264,    7,    7,    7, 0x08,
     298,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_marcas[] = {
    "marcas\0\0on_btmAgregarModelo_clicked()\0"
    "on_btmAgregarMarca_clicked()\0index\0"
    "on_tablaModelo_activated(QModelIndex)\0"
    "on_tablaMarcas_activated(QModelIndex)\0"
    "on_btmCancelar_clicked()\0"
    "on_btmSeleccionar_clicked()\0"
    "on_insertRowAction_triggered()\0"
    "on_deleteRowAction_triggered()\0"
    "on_modificarRowAction_triggered()\0"
    "currentChanged()\0"
};

const QMetaObject marcas::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_marcas,
      qt_meta_data_marcas, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &marcas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *marcas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *marcas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_marcas))
        return static_cast<void*>(const_cast< marcas*>(this));
    return QDialog::qt_metacast(_clname);
}

int marcas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btmAgregarModelo_clicked(); break;
        case 1: on_btmAgregarMarca_clicked(); break;
        case 2: on_tablaModelo_activated((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 3: on_tablaMarcas_activated((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 4: on_btmCancelar_clicked(); break;
        case 5: on_btmSeleccionar_clicked(); break;
        case 6: on_insertRowAction_triggered(); break;
        case 7: on_deleteRowAction_triggered(); break;
        case 8: on_modificarRowAction_triggered(); break;
        case 9: currentChanged(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
