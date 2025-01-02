/****************************************************************************
** Meta object code from reading C++ file 'loaddoctor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "loaddoctor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loaddoctor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_loaddoctor_t {
    QByteArrayData data[13];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_loaddoctor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_loaddoctor_t qt_meta_stringdata_loaddoctor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "loaddoctor"
QT_MOC_LITERAL(1, 11, 14), // "sendpatcurrent"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "loadpatid"
QT_MOC_LITERAL(4, 37, 2), // "id"
QT_MOC_LITERAL(5, 40, 9), // "loaddocid"
QT_MOC_LITERAL(6, 50, 22), // "on_ButPatTouch_clicked"
QT_MOC_LITERAL(7, 73, 20), // "on_ButPatAdd_clicked"
QT_MOC_LITERAL(8, 94, 20), // "on_ButDocAdd_clicked"
QT_MOC_LITERAL(9, 115, 22), // "on_ButDocTouch_clicked"
QT_MOC_LITERAL(10, 138, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(11, 160, 21), // "on_ButDocLoad_clicked"
QT_MOC_LITERAL(12, 182, 21) // "on_ButPatLoad_clicked"

    },
    "loaddoctor\0sendpatcurrent\0\0loadpatid\0"
    "id\0loaddocid\0on_ButPatTouch_clicked\0"
    "on_ButPatAdd_clicked\0on_ButDocAdd_clicked\0"
    "on_ButDocTouch_clicked\0on_pushButton_clicked\0"
    "on_ButDocLoad_clicked\0on_ButPatLoad_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_loaddoctor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   71,    2, 0x08 /* Private */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void loaddoctor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<loaddoctor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendpatcurrent(); break;
        case 1: _t->loadpatid((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->loaddocid((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_ButPatTouch_clicked(); break;
        case 4: _t->on_ButPatAdd_clicked(); break;
        case 5: _t->on_ButDocAdd_clicked(); break;
        case 6: _t->on_ButDocTouch_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_ButDocLoad_clicked(); break;
        case 9: _t->on_ButPatLoad_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (loaddoctor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&loaddoctor::sendpatcurrent)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (loaddoctor::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&loaddoctor::loadpatid)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (loaddoctor::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&loaddoctor::loaddocid)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject loaddoctor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_loaddoctor.data,
    qt_meta_data_loaddoctor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *loaddoctor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *loaddoctor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_loaddoctor.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int loaddoctor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void loaddoctor::sendpatcurrent()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void loaddoctor::loadpatid(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void loaddoctor::loaddocid(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
