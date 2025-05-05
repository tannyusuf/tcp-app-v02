#ifndef SOCKETWORKER_H
#define SOCKETWORKER_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include "connectionhandleui.h"
#include <QCoreApplication>
#include "GlobalConfig.h"

enum class HandshakeState {
    onHost_receivingHSK1,
    onHost_sendingHSK2,
    onClient_receivingHSK2,
    onClient_sendingName,
    onHost_receivingName,
    onHost_sendingName,
    onClient_receivingName,
    onClient_sendingOK,
    onHost_receivingOK, // emit connestab
    onHost_sendingOK,
    onClient_receivingOK, // emit connest
    onHost_completed,
    onClient_completed
    };

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
    QString m_name = GlobalConfig::username().getUsername();
    QString m_clientName;
    bool m_connectionReported = false;

    HandshakeState m_state;





public slots:
    void startProcessing();
    void tabCreated(connectionHandleUi* page);

    void socketFromConnect();
    void receiveIpPort(QString ip, quint16 port);
private slots:
    void handleData();

    void onDisconnected();


signals:
    void finished();

    //add tab
    void connectionEstablished(QString ipPort);
    void connectionClosed(QString ipPort);
};

#endif // SOCKETWORKER_H
