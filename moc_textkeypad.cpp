/****************************************************************************
** Meta object code from reading C++ file 'textkeypad.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "textkeypad.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textkeypad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_textkeypad_t {
    QByteArrayData data[12];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_textkeypad_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_textkeypad_t qt_meta_stringdata_textkeypad = {
    {
QT_MOC_LITERAL(0, 0, 10), // "textkeypad"
QT_MOC_LITERAL(1, 11, 10), // "textsignal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "digit"
QT_MOC_LITERAL(4, 29, 10), // "backsignal"
QT_MOC_LITERAL(5, 40, 11), // "spacesignal"
QT_MOC_LITERAL(6, 52, 11), // "entersignal"
QT_MOC_LITERAL(7, 64, 9), // "entertext"
QT_MOC_LITERAL(8, 74, 9), // "enterback"
QT_MOC_LITERAL(9, 84, 10), // "spaceenter"
QT_MOC_LITERAL(10, 95, 10), // "enterenter"
QT_MOC_LITERAL(11, 106, 25) // "on_ButUpper_Lower_clicked"

    },
    "textkeypad\0textsignal\0\0digit\0backsignal\0"
    "spacesignal\0entersignal\0entertext\0"
    "enterback\0spaceenter\0enterenter\0"
    "on_ButUpper_Lower_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_textkeypad[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    0,   62,    2, 0x06 /* Public */,
       5,    0,   63,    2, 0x06 /* Public */,
       6,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void textkeypad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<textkeypad *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->textsignal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->backsignal(); break;
        case 2: _t->spacesignal(); break;
        case 3: _t->entersignal(); break;
        case 4: _t->entertext(); break;
        case 5: _t->enterback(); break;
        case 6: _t->spaceenter(); break;
        case 7: _t->enterenter(); break;
        case 8: _t->on_ButUpper_Lower_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (textkeypad::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&textkeypad::textsignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (textkeypad::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&textkeypad::backsignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (textkeypad::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&textkeypad::spacesignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (textkeypad::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&textkeypad::entersignal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject textkeypad::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_textkeypad.data,
    qt_meta_data_textkeypad,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *textkeypad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *textkeypad::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_textkeypad.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int textkeypad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void textkeypad::textsignal(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void textkeypad::backsignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void textkeypad::spacesignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void textkeypad::entersignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
