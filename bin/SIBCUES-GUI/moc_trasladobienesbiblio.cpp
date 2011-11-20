/****************************************************************************
** Meta object code from reading C++ file 'trasladobienesbiblio.h'
**
** Created: Thu Apr 21 08:49:57 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SIBCUES-GUI/InventarioBienesGUI/trasladobienesbiblio.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trasladobienesbiblio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TrasladoBienesBiblio[] = {

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
      22,   21,   21,   21, 0x0a,
      51,   21,   21,   21, 0x0a,
      86,   21,   21,   21, 0x0a,
     116,   21,   21,   21, 0x0a,
     147,   21,   21,   21, 0x0a,
     181,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TrasladoBienesBiblio[] = {
    "TrasladoBienesBiblio\0\0"
    "on_claseNO_editingFinished()\0"
    "on_correlativoNO_editingFinished()\0"
    "on_botonAgregarBien_pressed()\0"
    "on_botonEliminarBien_pressed()\0"
    "on_finalizarTransaccion_pressed()\0"
    "on_cancelar_pressed()\0"
};

const QMetaObject TrasladoBienesBiblio::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TrasladoBienesBiblio,
      qt_meta_data_TrasladoBienesBiblio, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TrasladoBienesBiblio::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TrasladoBienesBiblio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TrasladoBienesBiblio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TrasladoBienesBiblio))
        return static_cast<void*>(const_cast< TrasladoBienesBiblio*>(this));
    return QWidget::qt_metacast(_clname);
}

int TrasladoBienesBiblio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
