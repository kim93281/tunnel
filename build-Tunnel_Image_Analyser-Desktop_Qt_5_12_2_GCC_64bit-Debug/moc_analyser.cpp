/****************************************************************************
** Meta object code from reading C++ file 'analyser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Tunnel_Image_Analyser/analyser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analyser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Analyser_t {
    QByteArrayData data[12];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Analyser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Analyser_t qt_meta_stringdata_Analyser = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Analyser"
QT_MOC_LITERAL(1, 9, 16), // "onDetectorStatus"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "status"
QT_MOC_LITERAL(4, 34, 15), // "QueueListUpdate"
QT_MOC_LITERAL(5, 50, 34), // "on_actionOpenImageFolder_trig..."
QT_MOC_LITERAL(6, 85, 38), // "on_actionOpenProcessedFolder_..."
QT_MOC_LITERAL(7, 124, 27), // "on_actionmodeToggle_toggled"
QT_MOC_LITERAL(8, 152, 4), // "arg1"
QT_MOC_LITERAL(9, 157, 13), // "UpdateLogList"
QT_MOC_LITERAL(10, 171, 5), // "event"
QT_MOC_LITERAL(11, 177, 10) // "time_stamp"

    },
    "Analyser\0onDetectorStatus\0\0status\0"
    "QueueListUpdate\0on_actionOpenImageFolder_triggered\0"
    "on_actionOpenProcessedFolder_triggered\0"
    "on_actionmodeToggle_toggled\0arg1\0"
    "UpdateLogList\0event\0time_stamp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Analyser[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
       9,    2,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QTime,   10,   11,

       0        // eod
};

void Analyser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Analyser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onDetectorStatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->QueueListUpdate(); break;
        case 2: _t->on_actionOpenImageFolder_triggered(); break;
        case 3: _t->on_actionOpenProcessedFolder_triggered(); break;
        case 4: _t->on_actionmodeToggle_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->UpdateLogList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Analyser::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Analyser.data,
    qt_meta_data_Analyser,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Analyser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Analyser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Analyser.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Analyser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
