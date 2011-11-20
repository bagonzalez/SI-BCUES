/****************************************************************************
** Meta object code from reading C++ file 'consultatraslados.h'
**
** Created: Sun 3. Jul 09:45:39 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SIBCUES-GUI/ConsultaTraslados/consultatraslados.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'consultatraslados.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_consultaTraslados[] = {

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
      19,   18,   18,   18, 0x0a,
      47,   18,   18,   18, 0x0a,
      77,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_consultaTraslados[] = {
    "consultaTraslados\0\0on_generarReporte_pressed()\0"
    "on_generarReporteMB_pressed()\0"
    "on_salir_pressed()\0"
};

const QMetaObject consultaTraslados::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_consultaTraslados,
      qt_meta_data_consultaTraslados, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &consultaTraslados::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *consultaTraslados::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *consultaTraslados::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_consultaTraslados))
        return static_cast<void*>(const_cast< consultaTraslados*>(this));
    return QWidget::qt_metacast(_clname);
}

int consultaTraslados::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_generarReporte_pressed(); break;
        case 1: on_generarReporteMB_pressed(); break;
        case 2: on_salir_pressed(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
