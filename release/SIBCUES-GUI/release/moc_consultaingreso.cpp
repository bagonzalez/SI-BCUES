/****************************************************************************
** Meta object code from reading C++ file 'consultaingreso.h'
**
** Created: Sat 14. May 00:22:49 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SIBCUES-GUI/ConsultaIngresoGUI/consultaingreso.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'consultaingreso.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConsultaIngreso[] = {

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
      17,   16,   16,   16, 0x0a,
      45,   16,   16,   16, 0x0a,
      79,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ConsultaIngreso[] = {
    "ConsultaIngreso\0\0on_generarReporte_pressed()\0"
    "on_generarReporteBiblio_pressed()\0"
    "on_salir_pressed()\0"
};

const QMetaObject ConsultaIngreso::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ConsultaIngreso,
      qt_meta_data_ConsultaIngreso, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConsultaIngreso::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConsultaIngreso::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConsultaIngreso::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConsultaIngreso))
        return static_cast<void*>(const_cast< ConsultaIngreso*>(this));
    return QWidget::qt_metacast(_clname);
}

int ConsultaIngreso::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_generarReporte_pressed(); break;
        case 1: on_generarReporteBiblio_pressed(); break;
        case 2: on_salir_pressed(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE