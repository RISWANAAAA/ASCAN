/****************************************************************************
** Meta object code from reading C++ file 'addlens.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "addlens.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addlens.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddLens_t {
    QByteArrayData data[8];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddLens_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddLens_t qt_meta_stringdata_AddLens = {
    {
QT_MOC_LITERAL(0, 0, 7), // "AddLens"
QT_MOC_LITERAL(1, 8, 13), // "updatelenssql"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "savelenssql"
QT_MOC_LITERAL(4, 35, 12), // "tx_insertiol"
QT_MOC_LITERAL(5, 48, 3), // "iol"
QT_MOC_LITERAL(6, 52, 22), // "on_ButLensBack_clicked"
QT_MOC_LITERAL(7, 75, 22) // "on_ButLensSave_clicked"

    },
    "AddLens\0updatelenssql\0\0savelenssql\0"
    "tx_insertiol\0iol\0on_ButLensBack_clicked\0"
    "on_ButLensSave_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddLens[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddLens::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddLens *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updatelenssql(); break;
        case 1: _t->savelenssql(); break;
        case 2: _t->tx_insertiol((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_ButLensBack_clicked(); break;
        case 4: _t->on_ButLensSave_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddLens::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddLens::updatelenssql)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AddLens::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddLens::savelenssql)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AddLens::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddLens::tx_insertiol)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AddLens::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_AddLens.data,
    qt_meta_data_AddLens,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AddLens::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddLens::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddLens.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AddLens::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void AddLens::updatelenssql()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AddLens::savelenssql()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AddLens::tx_insertiol(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
