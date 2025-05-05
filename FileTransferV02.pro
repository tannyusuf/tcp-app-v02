QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connect.cpp \
    connectionhandleui.cpp \
    listener.cpp \
    main.cpp \
    mainwindow.cpp \
    scanner.cpp \
    scannermanager.cpp \
    socketworker.cpp


HEADERS += \
    GlobalConfig.h \
    connect.h \
    connectionhandleui.h \
    listener.h \
    mainwindow.h \
    scanner.h \
    scannermanager.h \
    socketworker.h


FORMS += \
    connect.ui \
    connectionhandleui.ui \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
