#ifndef SOCKETWORKER_H
#define SOCKETWORKER_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <QFile>
#include <QTimer>
#include <QDir>
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

    // Dosya transferi için gerekli değişkenler
    QFile m_incomingFile;
    QFile m_outgoingFile;
    qint64 m_fileSize;
    qint64 m_bytesReceived;
    QString m_currentFileName;
    bool m_receivingFile = false;
    bool m_sendingFile = false;
    QByteArray m_fileBuffer;

    QString m_fileReceiveDir = QDir::homePath() + "/Downloads";





public slots:
    void startProcessing();
    void tabCreated(connectionHandleUi* page);
    void disconnectRequestFromMain(QString clientName);


    void socketFromConnect();
    void receiveIpPort(QString ip, quint16 port);

    // Dosya transferi için yeni slotlar
    void sendFile(const QString &filePath);
    void cancelFileTransfer();
    void sendFileChunk();
private slots:
    void handleData();
    void onDisconnected();






signals:
    void finished();

    //add tab
    void connectionEstablished(QString clientName);
    void connectionEstablishedFromConnect(QString clientName);

    void transferCancelledFromClient();



    void connectionClosed(QString clientName);

    void messageReceived(const QString &sender, const QString &message);
    // Dosya transferi için yeni sinyaller
    void fileTransferProgress(qint64 bytesSent, qint64 bytesTotal);
    void fileReceiveProgress(qint64 bytesReceived, qint64 bytesTotal);
    void fileReceived(const QString &filePath);
    void fileSent();
    void fileTransferError(const QString &errorMessage);
};

#endif // SOCKETWORKER_H
