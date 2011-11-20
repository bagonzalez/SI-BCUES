/****************************************************************************
** Meta object code from reading C++ file 'ingresobienesbiblio.h'
**
** Created: Thu Apr 21 08:49:55 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SIBCUES-GUI/InventarioBienesGUI/ingresobienesbiblio.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ingresobienesbiblio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IngresoBienesBiblio[] = {

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
      21,   20,   20,   20, 0x0a,
      54,   20,   20,   20, 0x0a,
      84,   20,   20,   20, 0x0a,
     115,   20,   20,   20, 0x0a,
     138,   20,   20,   20, 0x0a,
     172,   20,   20,   20, 0x0a,
     194,   20,   20,   20, 0x08,
     220,   20,   20,   20, 0x08,
     250,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_IngresoBienesBiblio[] = {
    "IngresoBienesBiblio\0\0"
    "on_nombreClase_editingFinished()\0"
    "on_botonAgregarBien_pressed()\0"
    "on_botonEliminarBien_pressed()\0"
    "on_nuevoBien_pressed()\0"
    "on_finalizarTransaccion_pressed()\0"
    "on_cancelar_pressed()\0on_buscarTitulo_clicked()\0"
    "on_buscarEspecifico_clicked()\0"
    "on_buscarCuentaInventario_clicked()\0"
};

const QMetaObject IngresoBienesBiblio::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IngresoBienesBiblio,
      qt_meta_data_IngresoBienesBiblio, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IngresoBienesBiblio::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IngresoBienesBiblio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IngresoBienesBiblio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IngresoBienesBiblio))
        return static_cast<void*>(const_cast< IngresoBienesBiblio*>(this));
    return QWidget::qt_metacast(_clname);
}

int IngresoBienesBiblio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_nombreClase_editingFinished(); break;
        case 1: on_botonAgregarBien_pressed(); break;
        case 2: on_botonEliminarBien_pressed(); break;
        case 3: on_nuevoBien_pressed(); break;
        case 4: on_finalizarTransaccion_pressed(); break;
        case 5: on_cancelar_pressed(); break;
        case 6: on_buscarTitulo_clicked(); break;
        case 7: on_buscarEspecifico_clicked(); break;
        case 8: on_buscarCuentaInventario_clicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
