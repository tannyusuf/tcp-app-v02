/****************************************************************************
** Meta object code from reading C++ file 'socketworker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../socketworker.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socketworker.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSocketWorkerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSocketWorkerENDCLASS = QtMocHelpers::stringData(
    "SocketWorker",
    "finished",
    "",
    "connectionEstablished",
    "clientName",
    "connectionEstablishedFromConnect",
    "transferCancelledFromClient",
    "connectionClosed",
    "messageReceived",
    "sender",
    "message",
    "fileTransferProgress",
    "bytesSent",
    "bytesTotal",
    "fileReceiveProgress",
    "bytesReceived",
    "fileReceived",
    "filePath",
    "fileSent",
    "fileTransferError",
    "errorMessage",
    "startProcessing",
    "tabCreated",
    "connectionHandleUi*",
    "page",
    "disconnectRequestFromMain",
    "socketFromConnect",
    "receiveIpPort",
    "ip",
    "port",
    "sendFile",
    "cancelFileTransfer",
    "sendFileChunk",
    "handleData",
    "onDisconnected"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSocketWorkerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  140,    2, 0x06,    1 /* Public */,
       3,    1,  141,    2, 0x06,    2 /* Public */,
       5,    1,  144,    2, 0x06,    4 /* Public */,
       6,    0,  147,    2, 0x06,    6 /* Public */,
       7,    1,  148,    2, 0x06,    7 /* Public */,
       8,    2,  151,    2, 0x06,    9 /* Public */,
      11,    2,  156,    2, 0x06,   12 /* Public */,
      14,    2,  161,    2, 0x06,   15 /* Public */,
      16,    1,  166,    2, 0x06,   18 /* Public */,
      18,    0,  169,    2, 0x06,   20 /* Public */,
      19,    1,  170,    2, 0x06,   21 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      21,    0,  173,    2, 0x0a,   23 /* Public */,
      22,    1,  174,    2, 0x0a,   24 /* Public */,
      25,    1,  177,    2, 0x0a,   26 /* Public */,
      26,    0,  180,    2, 0x0a,   28 /* Public */,
      27,    2,  181,    2, 0x0a,   29 /* Public */,
      30,    1,  186,    2, 0x0a,   32 /* Public */,
      31,    0,  189,    2, 0x0a,   34 /* Public */,
      32,    0,  190,    2, 0x0a,   35 /* Public */,
      33,    0,  191,    2, 0x08,   36 /* Private */,
      34,    0,  192,    2, 0x08,   37 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   12,   13,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   15,   13,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,   28,   29,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SocketWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSocketWorkerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSocketWorkerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSocketWorkerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SocketWorker, std::true_type>,
        // method 'finished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectionEstablished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'connectionEstablishedFromConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'transferCancelledFromClient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectionClosed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'messageReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'fileTransferProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'fileReceiveProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'fileReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'fileSent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fileTransferError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'startProcessing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tabCreated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<connectionHandleUi *, std::false_type>,
        // method 'disconnectRequestFromMain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'socketFromConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'receiveIpPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        // method 'sendFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'cancelFileTransfer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendFileChunk'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SocketWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SocketWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->connectionEstablished((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->connectionEstablishedFromConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->transferCancelledFromClient(); break;
        case 4: _t->connectionClosed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->messageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 6: _t->fileTransferProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 7: _t->fileReceiveProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 8: _t->fileReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->fileSent(); break;
        case 10: _t->fileTransferError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->startProcessing(); break;
        case 12: _t->tabCreated((*reinterpret_cast< std::add_pointer_t<connectionHandleUi*>>(_a[1]))); break;
        case 13: _t->disconnectRequestFromMain((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->socketFromConnect(); break;
        case 15: _t->receiveIpPort((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2]))); break;
        case 16: _t->sendFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->cancelFileTransfer(); break;
        case 18: _t->sendFileChunk(); break;
        case 19: _t->handleData(); break;
        case 20: _t->onDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 12:
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
            using _t = void (SocketWorker::*)();
            if (_t _q_method = &SocketWorker::finished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SocketWorker::*)(QString );
            if (_t _q_method = &SocketWorker::connectionEstablished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SocketWorker::*)(QString );
            if (_t _q_method = &SocketWorker::connectionEstablishedFromConnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SocketWorker::*)();
            if (_t _q_method = &SocketWorker::transferCancelledFromClient; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SocketWorker::*)(QString );
            if (_t _q_method = &SocketWorker::connectionClosed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SocketWorker::*)(const QString & , const QString & );
            if (_t _q_method = &SocketWorker::messageReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SocketWorker::*)(qint64 , qint64 );
            if (_t _q_method = &SocketWorker::fileTransferProgress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SocketWorker::*)(qint64 , qint64 );
            if (_t _q_method = &SocketWorker::fileReceiveProgress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (SocketWorker::*)(const QString & );
            if (_t _q_method = &SocketWorker::fileReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (SocketWorker::*)();
            if (_t _q_method = &SocketWorker::fileSent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (SocketWorker::*)(const QString & );
            if (_t _q_method = &SocketWorker::fileTransferError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject *SocketWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSocketWorkerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SocketWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void SocketWorker::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SocketWorker::connectionEstablished(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SocketWorker::connectionEstablishedFromConnect(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SocketWorker::transferCancelledFromClient()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SocketWorker::connectionClosed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SocketWorker::messageReceived(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SocketWorker::fileTransferProgress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SocketWorker::fileReceiveProgress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SocketWorker::fileReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SocketWorker::fileSent()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void SocketWorker::fileTransferError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
