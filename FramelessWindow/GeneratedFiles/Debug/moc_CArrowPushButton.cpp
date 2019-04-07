/****************************************************************************
** Meta object code from reading C++ file 'CArrowPushButton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CArrowPushButton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CArrowPushButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CArrowPushButton_t {
    QByteArrayData data[5];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CArrowPushButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CArrowPushButton_t qt_meta_stringdata_CArrowPushButton = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CArrowPushButton"
QT_MOC_LITERAL(1, 17, 11), // "signal_pull"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "signal_push"
QT_MOC_LITERAL(4, 42, 12) // "slot_clicked"

    },
    "CArrowPushButton\0signal_pull\0\0signal_push\0"
    "slot_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CArrowPushButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CArrowPushButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CArrowPushButton *_t = static_cast<CArrowPushButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_pull(); break;
        case 1: _t->signal_push(); break;
        case 2: _t->slot_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CArrowPushButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CArrowPushButton::signal_pull)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CArrowPushButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CArrowPushButton::signal_push)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CArrowPushButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_CArrowPushButton.data,
      qt_meta_data_CArrowPushButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CArrowPushButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CArrowPushButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CArrowPushButton.stringdata0))
        return static_cast<void*>(const_cast< CArrowPushButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int CArrowPushButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CArrowPushButton::signal_pull()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CArrowPushButton::signal_push()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
