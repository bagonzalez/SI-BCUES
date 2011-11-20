/****************************************************************************
** Meta object code from reading C++ file 'descargobienesmb.h'
**
** Created: Thu Apr 21 08:49:56 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SIBCUES-GUI/InventarioBienesGUI/descargobienesmb.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'descargobienesmb.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DescargoBienesMB[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      47,   17,   17,   17, 0x0a,
      82,   17,   17,   17, 0x0a,
     112,   17,   17,   17, 0x0a,
     143,   17,   17,   17, 0x0a,
     177,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DescargoBienesMB[] = {
    "DescargoBienesMB\0\0on_claseNO_editingFinished()\0"
    "on_correlativoNO_editingFinished()\0"
    "on_botonAgregarBien_pressed()\0"
    "on_botonEliminarBien_pressed()\0"
    "on_finalizarTransaccion_pressed()\0"
    "on_cancelar_pressed()\0"
};

const QMetaObject DescargoBienesMB::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DescargoBienesMB,
      qt_meta_data_DescargoBienesMB, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DescargoBienesMB::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DescargoBienesMB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DescargoBienesMB::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DescargoBienesMB))
        return static_cast<void*>(const_cast< DescargoBienesMB*>(this));
    return QWidget::qt_metacast(_clname);
}

int DescargoBienesMB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_claseNO_editingFinished(); break;
        case 1: on_correlativoNO_editingFinished(); break;
        case 2: on_botonAgregarBien_pressed(); break;
        case 3: on_botonEliminarBien_pressed(); break;
        case 4: on_finalizarTransaccion_pressed(); break;
        case 5: on_cancelar_pressed(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
