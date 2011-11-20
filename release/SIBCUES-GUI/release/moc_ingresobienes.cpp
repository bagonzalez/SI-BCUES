/****************************************************************************
** Meta object code from reading C++ file 'ingresobienes.h'
**
** Created: Sun 3. Jul 09:45:35 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SIBCUES-GUI/InventarioBienesGUI/ingresobienes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ingresobienes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ingresoBienes[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      49,   14,   14,   14, 0x0a,
      82,   14,   14,   14, 0x0a,
     113,   14,   14,   14, 0x0a,
     143,   14,   14,   14, 0x0a,
     174,   14,   14,   14, 0x0a,
     197,   14,   14,   14, 0x0a,
     231,   14,   14,   14, 0x0a,
     253,   14,   14,   14, 0x0a,
     293,   14,   14,   14, 0x08,
     317,   14,   14,   14, 0x08,
     340,   14,   14,   14, 0x08,
     373,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ingresoBienes[] = {
    "ingresoBienes\0\0on_numeroCuenta_editingFinished()\0"
    "on_nombreClase_editingFinished()\0"
    "on_marca_currentIndexChanged()\0"
    "on_botonAgregarBien_pressed()\0"
    "on_botonEliminarBien_pressed()\0"
    "on_nuevoBien_pressed()\0"
    "on_finalizarTransaccion_pressed()\0"
    "on_cancelar_pressed()\0"
    "on_anioInventario_currentIndexChanged()\0"
    "on_btmGuardar_pressed()\0on_btmMarcas_clicked()\0"
    "on_btmBuscarEspecifico_clicked()\0"
    "on_btmBuscarClases_clicked()\0"
};

const QMetaObject ingresoBienes::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ingresoBienes,
      qt_meta_data_ingresoBienes, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ingresoBienes::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ingresoBienes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ingresoBienes::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ingresoBienes))
        return static_cast<void*>(const_cast< ingresoBienes*>(this));
    return QWidget::qt_metacast(_clname);
}

int ingresoBienes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_numeroCuenta_editingFinished(); break;
        case 1: on_nombreClase_editingFinished(); break;
        case 2: on_marca_currentIndexChanged(); break;
        case 3: on_botonAgregarBien_pressed(); break;
        case 4: on_botonEliminarBien_pressed(); break;
        case 5: on_nuevoBien_pressed(); break;
        case 6: on_finalizarTransaccion_pressed(); break;
        case 7: on_cancelar_pressed(); break;
        case 8: on_anioInventario_currentIndexChanged(); break;
        case 9: on_btmGuardar_pressed(); break;
        case 10: on_btmMarcas_clicked(); break;
        case 11: on_btmBuscarEspecifico_clicked(); break;
        case 12: on_btmBuscarClases_clicked(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
