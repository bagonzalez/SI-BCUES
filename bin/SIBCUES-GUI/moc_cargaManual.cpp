/****************************************************************************
** Meta object code from reading C++ file 'cargaManual.h'
**
** Created: Thu Apr 21 08:49:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SIBCUES-GUI/CatalogoContableGUI/cargaManual.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cargaManual.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CargaManual[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      46,   12,   12,   12, 0x0a,
      72,   12,   12,   12, 0x0a,
      96,   12,   12,   12, 0x0a,
     122,   12,   12,   12, 0x0a,
     143,   12,   12,   12, 0x0a,
     166,   12,   12,   12, 0x0a,
     188,   12,   12,   12, 0x0a,
     218,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CargaManual[] = {
    "CargaManual\0\0on_catalogo_currentItemChanged()\0"
    "on_importe_valueChanged()\0"
    "on_buttonBox_rejected()\0"
    "on_partidaDoble_pressed()\0"
    "on_aplicar_pressed()\0on_finalizar_pressed()\0"
    "on_eliminar_pressed()\0"
    "on_nuevaTransaccion_pressed()\0"
    "on_cancelarTran_pressed()\0"
};

const QMetaObject CargaManual::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CargaManual,
      qt_meta_data_CargaManual, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CargaManual::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CargaManual::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CargaManual::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CargaManual))
        return static_cast<void*>(const_cast< CargaManual*>(this));
    return QDialog::qt_metacast(_clname);
}

int CargaManual::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_catalogo_currentItemChanged(); break;
        case 1: on_importe_valueChanged(); break;
        case 2: on_buttonBox_rejected(); break;
        case 3: on_partidaDoble_pressed(); break;
        case 4: on_aplicar_pressed(); break;
        case 5: on_finalizar_pressed(); break;
        case 6: on_eliminar_pressed(); break;
        case 7: on_nuevaTransaccion_pressed(); break;
        case 8: on_cancelarTran_pressed(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
