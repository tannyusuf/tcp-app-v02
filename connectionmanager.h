#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QObject>
#include "listener.h"
#include "connectionhandleui.h"
#include "socketworker.h"
#include <QTcpSocket>

class ConnectionManager : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionManager(QObject *parent = nullptr);
    ~ConnectionManager();

private:
    Listener* listener;
    QThread* listenerTh;
    QList<QThread*> activeWorkerThreads;

private slots:
    void handleNewSocketFromListener(QTcpSocket* socket);



signals:
    void addNewTab(connectionHandleUi* page,
                   QString ip_port);

    void deleteTab(QString ipPort);


};

#endif // CONNECTIONMANAGER_H
