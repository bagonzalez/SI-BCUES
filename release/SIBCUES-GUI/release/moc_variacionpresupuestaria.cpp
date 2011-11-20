/****************************************************************************
** Meta object code from reading C++ file 'variacionpresupuestaria.h'
**
** Created: Sat 14. May 00:23:07 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SIBCUES-GUI/variacionpresupuestaria/variacionpresupuestaria.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'variacionpresupuestaria.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VariacionPresupuestaria[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x08,
      81,   24,   24,   24, 0x08,
     135,   24,   24,   24, 0x08,
     194,   24,   24,   24, 0x08,
     265,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VariacionPresupuestaria[] = {
    "VariacionPresupuestaria\0\0"
    "on_actionRegistro_de_Presupuesto_Solicitado_activated()\0"
    "on_actionRegistro_de_Presupuesto_Aprobado_activated()\0"
    "on_actionDocumento_de_Variacion_Presupuestaria_activated()\0"
    "on_actionRegistro_de_Razonamiento_Variacion_Presupuestaria_activated()\0"
    "on_actionVariacion_Presupuestaria_activated()\0"
};

const QMetaObject VariacionPresupuestaria::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VariacionPresupuestaria,
      qt_meta_data_VariacionPresupuestaria, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VariacionPresupuestaria::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VariacionPresupuestaria::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VariacionPresupuestaria::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VariacionPresupuestaria))
        return static_cast<void*>(const_cast< VariacionPresupuestaria*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VariacionPresupuestaria::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionRegistro_de_Presupuesto_Solicitado_activated(); break;
        case 1: on_actionRegistro_de_Presupuesto_Aprobado_activated(); break;
        case 2: on_actionDocumento_de_Variacion_Presupuestaria_activated(); break;
        case 3: on_actionRegistro_de_Razonamiento_Variacion_Presupuestaria_activated(); break;
        case 4: on_actionVariacion_Presupuestaria_activated(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
