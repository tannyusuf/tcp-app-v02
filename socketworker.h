#ifndef SOCKETWORKER_H
#define SOCKETWORKER_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include "connectionhandleui.h"
#include <QCoreApplication>

class SocketWorker : public QObject
{
    Q_OBJECT
public:
    explicit SocketWorker(QObject* parent = nullptr);
    ~SocketWorker();


    QTcpSocket *socket() const;
    void setSocket(QTcpSocket *newSocket);

private:
    QTcpSocket* m_socket;
    QString m_ip;
    quint16 m_port;

    bool m_hsk1Received;
    bool m_hsk2Received;



public slots:
    void startProcessing();
    void tabCreated(connectionHandleUi* page);

    void socketFromConnect();
    void receiveIpPort(QString ip, quint16 port);
private slots:
    void handleData();
    void handleDataClient();
    void onDisconnected();


signals:
    void finished();

    //add tab
    void connectionEstablished(QString ipPort);
    void connectionClosed(QString ipPort);
};

#endif // SOCKETWORKER_H
