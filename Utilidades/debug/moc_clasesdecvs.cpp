/****************************************************************************
** Meta object code from reading C++ file 'clasesdecvs.h'
**
** Created: Mon 4. Jan 22:33:11 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../clasesdecvs.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clasesdecvs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_clasesdecvs[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_clasesdecvs[] = {
    "clasesdecvs\0\0on_pushButton_clicked()\0"
};

const QMetaObject clasesdecvs::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_clasesdecvs,
      qt_meta_data_clasesdecvs, 0 }
};

const QMetaObject *clasesdecvs::metaObject() const
{
    return &staticMetaObject;
}

void *clasesdecvs::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_clasesdecvs))
        return static_cast<void*>(const_cast< clasesdecvs*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int clasesdecvs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_clicked(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
