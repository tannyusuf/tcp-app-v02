/****************************************************************************
** Meta object code from reading C++ file 'connectionhandleui.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../connectionhandleui.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectionhandleui.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSconnectionHandleUiENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSconnectionHandleUiENDCLASS = QtMocHelpers::stringData(
    "connectionHandleUi",
    "disconnectBtnClicked",
    "",
    "sendFileRequested",
    "filePath",
    "cancelFileTransferRequested",
    "on_btnDisconnect_clicked",
    "on_btnSendFile_clicked",
    "on_btnSelectFile_clicked",
    "on_pushButton_clicked",
    "onFileTransferProgress",
    "bytesSent",
    "bytesTotal",
    "onFileReceiveProgress",
    "bytesReceived",
    "onFileReceived",
    "onFileSent",
    "onFileTransferError",
    "errorMessage",
    "on_btnCancel_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSconnectionHandleUiENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x06,    1 /* Public */,
       3,    1,   93,    2, 0x06,    2 /* Public */,
       5,    0,   96,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   97,    2, 0x08,    5 /* Private */,
       7,    0,   98,    2, 0x08,    6 /* Private */,
       8,    0,   99,    2, 0x08,    7 /* Private */,
       9,    0,  100,    2, 0x08,    8 /* Private */,
      10,    2,  101,    2, 0x0a,    9 /* Public */,
      13,    2,  106,    2, 0x0a,   12 /* Public */,
      15,    1,  111,    2, 0x0a,   15 /* Public */,
      16,    0,  114,    2, 0x0a,   17 /* Public */,
      17,    1,  115,    2, 0x0a,   18 /* Public */,
      19,    0,  118,    2, 0x0a,   20 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   11,   12,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   14,   12,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject connectionHandleUi::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSconnectionHandleUiENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSconnectionHandleUiENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSconnectionHandleUiENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<connectionHandleUi, std::true_type>,
        // method 'disconnectBtnClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendFileRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'cancelFileTransferRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnDisconnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSendFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSelectFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFileTransferProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'onFileReceiveProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'onFileReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onFileSent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFileTransferError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_btnCancel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void connectionHandleUi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<connectionHandleUi *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->disconnectBtnClicked(); break;
        case 1: _t->sendFileRequested((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->cancelFileTransferRequested(); break;
        case 3: _t->on_btnDisconnect_clicked(); break;
        case 4: _t->on_btnSendFile_clicked(); break;
        case 5: _t->on_btnSelectFile_clicked(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->onFileTransferProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 8: _t->onFileReceiveProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 9: _t->onFileReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->onFileSent(); break;
        case 11: _t->onFileTransferError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->on_btnCancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (connectionHandleUi::*)();
            if (_t _q_method = &connectionHandleUi::disconnectBtnClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (connectionHandleUi::*)(const QString & );
            if (_t _q_method = &connectionHandleUi::sendFileRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (connectionHandleUi::*)();
            if (_t _q_method = &connectionHandleUi::cancelFileTransferRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *connectionHandleUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *connectionHandleUi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSconnectionHandleUiENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int connectionHandleUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void connectionHandleUi::disconnectBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void connectionHandleUi::sendFileRequested(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void connectionHandleUi::cancelFileTransferRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
