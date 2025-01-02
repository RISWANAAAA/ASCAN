/****************************************************************************
** Meta object code from reading C++ file 'addpatient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "addpatient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addpatient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_addPatient_t {
    QByteArrayData data[10];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addPatient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addPatient_t qt_meta_stringdata_addPatient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "addPatient"
QT_MOC_LITERAL(1, 11, 12), // "updatepatsql"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "savepatsql"
QT_MOC_LITERAL(4, 36, 11), // "saveforload"
QT_MOC_LITERAL(5, 48, 14), // "savepatid_name"
QT_MOC_LITERAL(6, 63, 2), // "id"
QT_MOC_LITERAL(7, 66, 4), // "name"
QT_MOC_LITERAL(8, 71, 21), // "on_ButPatBack_clicked"
QT_MOC_LITERAL(9, 93, 21) // "on_ButPatSave_clicked"

    },
    "addPatient\0updatepatsql\0\0savepatsql\0"
    "saveforload\0savepatid_name\0id\0name\0"
    "on_ButPatBack_clicked\0on_ButPatSave_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addPatient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    2,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void addPatient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<addPatient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updatepatsql(); break;
        case 1: _t->savepatsql(); break;
        case 2: _t->saveforload(); break;
        case 3: _t->savepatid_name((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->on_ButPatBack_clicked(); break;
        case 5: _t->on_ButPatSave_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (addPatient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&addPatient::updatepatsql)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (addPatient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&addPatient::savepatsql)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (addPatient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&addPatient::saveforload)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (addPatient::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&addPatient::savepatid_name)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject addPatient::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_addPatient.data,
    qt_meta_data_addPatient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *addPatient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addPatient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_addPatient.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int addPatient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void addPatient::updatepatsql()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void addPatient::savepatsql()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void addPatient::saveforload()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void addPatient::savepatid_name(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
