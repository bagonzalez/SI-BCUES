/****************************************************************************
** Meta object code from reading C++ file 'primerinicio.h'
**
** Created: Thu Apr 21 08:49:46 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SIBCUES-GUI/inicio/primerinicio.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'primerinicio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PrimerInicio[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      40,   13,   13,   13, 0x08,
      67,   13,   13,   13, 0x08,
      93,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PrimerInicio[] = {
    "PrimerInicio\0\0on_botonAceptar_clicked()\0"
    "on_btnExisteConf_clicked()\0"
    "on_btnNuevaConf_clicked()\0"
    "on_botonCancelar_clicked()\0"
};

const QMetaObject PrimerInicio::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PrimerInicio,
      qt_meta_data_PrimerInicio, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PrimerInicio::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PrimerInicio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PrimerInicio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrimerInicio))
        return static_cast<void*>(const_cast< PrimerInicio*>(this));
    return QWidget::qt_metacast(_clname);
}

int PrimerInicio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_botonAceptar_clicked(); break;
        case 1: on_btnExisteConf_clicked(); break;
        case 2: on_btnNuevaConf_clicked(); break;
        case 3: on_botonCancelar_clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
