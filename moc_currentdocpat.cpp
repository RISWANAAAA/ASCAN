/****************************************************************************
** Meta object code from reading C++ file 'currentdocpat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "currentdocpat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'currentdocpat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_currentDocPat_t {
    QByteArrayData data[10];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_currentDocPat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_currentDocPat_t qt_meta_stringdata_currentDocPat = {
    {
QT_MOC_LITERAL(0, 0, 13), // "currentDocPat"
QT_MOC_LITERAL(1, 14, 18), // "loaddocsqldatabase"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 18), // "loadpatsqldatabase"
QT_MOC_LITERAL(4, 53, 7), // "tx_main"
QT_MOC_LITERAL(5, 61, 20), // "tx_patdocnameid_main"
QT_MOC_LITERAL(6, 82, 2), // "id"
QT_MOC_LITERAL(7, 85, 4), // "name"
QT_MOC_LITERAL(8, 90, 20), // "on_ButDocSql_clicked"
QT_MOC_LITERAL(9, 111, 20) // "on_ButPatSql_clicked"

    },
    "currentDocPat\0loaddocsqldatabase\0\0"
    "loadpatsqldatabase\0tx_main\0"
    "tx_patdocnameid_main\0id\0name\0"
    "on_ButDocSql_clicked\0on_ButPatSql_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_currentDocPat[] = {

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

void currentDocPat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<currentDocPat *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loaddocsqldatabase(); break;
        case 1: _t->loadpatsqldatabase(); break;
        case 2: _t->tx_main(); break;
        case 3: _t->tx_patdocnameid_main((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->on_ButDocSql_clicked(); break;
        case 5: _t->on_ButPatSql_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (currentDocPat::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&currentDocPat::loaddocsqldatabase)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (currentDocPat::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&currentDocPat::loadpatsqldatabase)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (currentDocPat::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&currentDocPat::tx_main)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (currentDocPat::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&currentDocPat::tx_patdocnameid_main)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject currentDocPat::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_currentDocPat.data,
    qt_meta_data_currentDocPat,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *currentDocPat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *currentDocPat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_currentDocPat.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int currentDocPat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void currentDocPat::loaddocsqldatabase()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void currentDocPat::loadpatsqldatabase()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void currentDocPat::tx_main()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void currentDocPat::tx_patdocnameid_main(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
