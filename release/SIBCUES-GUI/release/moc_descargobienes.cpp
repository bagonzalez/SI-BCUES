/****************************************************************************
** Meta object code from reading C++ file 'descargobienes.h'
**
** Created: Sun 3. Jul 09:45:38 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SIBCUES-GUI/InventarioBienesGUI/descargobienes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'descargobienes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DescargoBienes[] = {

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
      16,   15,   15,   15, 0x0a,
      46,   15,   15,   15, 0x0a,
      75,   15,   15,   15, 0x0a,
     110,   15,   15,   15, 0x0a,
     140,   15,   15,   15, 0x0a,
     171,   15,   15,   15, 0x0a,
     205,   15,   15,   15, 0x0a,
     227,   15,   15,   15, 0x0a,
     267,   15,   15,   15, 0x08,
     296,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DescargoBienes[] = {
    "DescargoBienes\0\0on_cuentaNO_editingFinished()\0"
    "on_claseNO_editingFinished()\0"
    "on_correlativoNO_editingFinished()\0"
    "on_botonAgregarBien_pressed()\0"
    "on_botonEliminarBien_pressed()\0"
    "on_finalizarTransaccion_pressed()\0"
    "on_cancelar_pressed()\0"
    "on_anioInventario_currentIndexChanged()\0"
    "on_guardarTraslado_pressed()\0"
    "on_consultaBien_pressed()\0"
};

const QMetaObject DescargoBienes::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DescargoBienes,
      qt_meta_data_DescargoBienes, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DescargoBienes::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DescargoBienes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DescargoBienes::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DescargoBienes))
        return static_cast<void*>(const_cast< DescargoBienes*>(this));
    return QWidget::qt_metacast(_clname);
}

int DescargoBienes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_cuentaNO_editingFinished(); break;
        case 1: on_claseNO_editingFinished(); break;
        case 2: on_correlativoNO_editingFinished(); break;
        case 3: on_botonAgregarBien_pressed(); break;
        case 4: on_botonEliminarBien_pressed(); break;
        case 5: on_finalizarTransaccion_pressed(); break;
        case 6: on_cancelar_pressed(); break;
        case 7: on_anioInventario_currentIndexChanged(); break;
        case 8: on_guardarTraslado_pressed(); break;
        case 9: on_consultaBien_pressed(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
