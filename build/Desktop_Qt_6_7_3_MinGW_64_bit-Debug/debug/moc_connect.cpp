/****************************************************************************
** Meta object code from reading C++ file 'connect.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../connect.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSConnectENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSConnectENDCLASS = QtMocHelpers::stringData(
    "Connect",
    "connectionEstablished",
    "",
    "ipPort",
    "connectionEstablishedFromConnect",
    "disconnectRequestedFromMainSignal",
    "deleteTab",
    "btnDontListen_clicked",
    "btnListen_clicked",
    "tabCreatedSignal",
    "connectionHandleUi*",
    "page",
    "sendIpPortToWorker",
    "ip",
    "port",
    "showResults",
    "ips",
    "on_btnScan_clicked",
    "pinged",
    "on_btnDontListen_clicked",
    "on_btnConnect_clicked",
    "on_btnListen_clicked",
    "tabCreatedSlot",
    "disconnectRequestedFromMain"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSConnectENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  110,    2, 0x06,    1 /* Public */,
       4,    1,  113,    2, 0x06,    3 /* Public */,
       5,    1,  116,    2, 0x06,    5 /* Public */,
       6,    1,  119,    2, 0x06,    7 /* Public */,
       7,    0,  122,    2, 0x06,    9 /* Public */,
       8,    0,  123,    2, 0x06,   10 /* Public */,
       9,    1,  124,    2, 0x06,   11 /* Public */,
      12,    2,  127,    2, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    1,  132,    2, 0x08,   16 /* Private */,
      17,    0,  135,    2, 0x08,   18 /* Private */,
      18,    0,  136,    2, 0x08,   19 /* Private */,
      19,    0,  137,    2, 0x08,   20 /* Private */,
      20,    0,  138,    2, 0x08,   21 /* Private */,
      21,    0,  139,    2, 0x08,   22 /* Private */,
      22,    1,  140,    2, 0x0a,   23 /* Public */,
      23,    1,  143,    2, 0x0a,   25 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,   13,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

Q_CONSTINIT const QMetaObject Connect::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSConnectENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSConnectENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSConnectENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Connect, std::true_type>,
        // method 'connectionEstablished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'connectionEstablishedFromConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'disconnectRequestedFromMainSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'deleteTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'btnDontListen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'btnListen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tabCreatedSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<connectionHandleUi *, std::false_type>,
        // method 'sendIpPortToWorker'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        // method 'showResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QString> &, std::false_type>,
        // method 'on_btnScan_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pinged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnDontListen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnConnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnListen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tabCreatedSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<connectionHandleUi *, std::false_type>,
        // method 'disconnectRequestedFromMain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void Connect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Connect *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectionEstablished((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->connectionEstablishedFromConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->disconnectRequestedFromMainSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->deleteTab((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->btnDontListen_clicked(); break;
        case 5: _t->btnListen_clicked(); break;
        case 6: _t->tabCreatedSignal((*reinterpret_cast< std::add_pointer_t<connectionHandleUi*>>(_a[1]))); break;
        case 7: _t->sendIpPortToWorker((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2]))); break;
        case 8: _t->showResults((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 9: _t->on_btnScan_clicked(); break;
        case 10: _t->pinged(); break;
        case 11: _t->on_btnDontListen_clicked(); break;
        case 12: _t->on_btnConnect_clicked(); break;
        case 13: _t->on_btnListen_clicked(); break;
        case 14: _t->tabCreatedSlot((*reinterpret_cast< std::add_pointer_t<connectionHandleUi*>>(_a[1]))); break;
        case 15: _t->disconnectRequestedFromMain((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< connectionHandleUi* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< connectionHandleUi* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Connect::*)(QString );
            if (_t _q_method = &Connect::connectionEstablished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Connect::*)(QString );
            if (_t _q_method = &Connect::connectionEstablishedFromConnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Connect::*)(QString );
            if (_t _q_method = &Connect::disconnectRequestedFromMainSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Connect::*)(QString );
            if (_t _q_method = &Connect::deleteTab; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Connect::*)();
            if (_t _q_method = &Connect::btnDontListen_clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Connect::*)();
            if (_t _q_method = &Connect::btnListen_clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Connect::*)(connectionHandleUi * );
            if (_t _q_method = &Connect::tabCreatedSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Connect::*)(QString , quint16 );
            if (_t _q_method = &Connect::sendIpPortToWorker; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject *Connect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Connect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSConnectENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Connect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Connect::connectionEstablished(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Connect::connectionEstablishedFromConnect(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Connect::disconnectRequestedFromMainSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Connect::deleteTab(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Connect::btnDontListen_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Connect::btnListen_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Connect::tabCreatedSignal(connectionHandleUi * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Connect::sendIpPortToWorker(QString _t1, quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
