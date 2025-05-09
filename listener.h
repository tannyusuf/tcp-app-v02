#ifndef LISTENER_H
#define LISTENER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include <QTimer>
#include "socketworker.h"
#include "connectionhandleui.h"

class Listener : public QObject
{
    Q_OBJECT
public:
    explicit Listener(QObject *parent = nullptr);
    ~Listener();

private:
    QTcpServer* m_server;
    quint16 m_port = 8000;
    QList<QThread*> activeWorkerThreads;

signals:
    void connectionEstablished(QString clientName);
    void disconnectRequestedFromMainSignal(QString clientName);

    void tabCreatedSignal(connectionHandleUi* page);
    void deleteTab(QString clientName);


public slots:
    void startListening();
    void stopListening();

    void tabCreatedSlot(connectionHandleUi* page);
    void disconnectRequestedFromMain(QString clientName);

private slots:
    void onNewConnection();
    void onSocketError(QAbstractSocket::SocketError err);
};

#endif // LISTENER_H
