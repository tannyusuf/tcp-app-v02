#include "socketworker.h"

SocketWorker::SocketWorker(QObject *parent)
    : QObject{parent}
{}

SocketWorker::~SocketWorker()
{
    if (m_socket) {
        if (m_socket->state() == QAbstractSocket::ConnectedState) {
            m_socket->disconnectFromHost();
            if (m_socket->state() != QAbstractSocket::UnconnectedState) {
                m_socket->waitForDisconnected(1000);
            }
        }
        m_socket->deleteLater();
        //?m_socket = nullptr;
    }
}

QTcpSocket *SocketWorker::socket() const
{
    return m_socket;
}

void SocketWorker::setSocket(QTcpSocket *newSocket)
{
    m_socket = newSocket;
}

void SocketWorker::startProcessing()
{
    connect(m_socket, &QTcpSocket::disconnected, this, &SocketWorker::onDisconnected, Qt::DirectConnection);

    m_hsk1Received = false;
    connect(m_socket, &QTcpSocket::readyRead,
            this, &SocketWorker::handleData,
            Qt::DirectConnection);

    qDebug() << "Socket thread:(worker thread)" << m_socket->thread();
    qDebug() << "(Worker) socket connected to:" << m_socket->peerAddress().toString() << m_socket->peerPort();


    m_ip = m_socket->peerAddress().toString();
    m_port = m_socket->peerPort();
    //handleData();
    QString ipPort = QString("%1:%2").arg(m_ip).arg(m_port);
    emit connectionEstablished(ipPort);
}

void SocketWorker::tabCreated(connectionHandleUi *page)
{

    //loglar
    connect(page, &connectionHandleUi::disconnectBtnClicked,
            this, &SocketWorker::onDisconnected, Qt::QueuedConnection);

    //////file-transfer eklenecek.


}

void SocketWorker::socketFromConnect()
{

    connect(m_socket, &QTcpSocket::disconnected, this, &SocketWorker::onDisconnected, Qt::DirectConnection);

    connect(m_socket, &QTcpSocket::readyRead,
            this, &SocketWorker::handleDataClient,
            Qt::DirectConnection);
    connect(m_socket, &QTcpSocket::connected, this, [this]() {
        // Bağlantı kurulduktan sonra ipPort değerini al
        QString ipPort = QString("%1:%2").arg(m_ip).arg(m_port);

        qDebug() << "socket connected to(WorkerThread):" << ipPort;

        emit connectionEstablished(ipPort);

        /*qDebug() << "Connected to server, sending HSK1";
        m_socket->write("HSK1");
        m_hsk2Received = false;*/
    });
    connect(m_socket, &QTcpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError socketError) {
        qDebug() << "Connection error:" << m_socket->errorString();
        // Buraya hata durumunda yapılması gereken işlemleri ekleyebilirsiniz
    });

    // Bağlantı isteği gönder
    m_socket->connectToHost(m_ip, m_port);
    //handleDataClient();
}

void SocketWorker::receiveIpPort(QString ip, quint16 port)
{
    m_ip = ip;
    m_port = port;
}



void SocketWorker::handleData()
{
    /*QByteArray data = m_socket->readAll();
    qDebug() << "Received:" << data;
    QString ipPort = (QString("%1:%2").arg(m_ip)
                          .arg(m_port));

    if (!m_hsk1Received) {
        if (data == "HSK1") {
            m_socket->write("HSK2");
            m_hsk1Received = true;
            qDebug() << "Sent HSK2";
        } else {
            m_socket->disconnectFromHost();
            qDebug() << "Invalid handshake, disconnecting";
        }
    } else {
        if (data == "OK") {
            qDebug() << "Handshake completed successfully";
            emit connectionEstablished(ipPort);
            // Artık normal iletişime başlayabilirsiniz
        } else {
            m_socket->disconnectFromHost();
            qDebug() << "Invalid final handshake, disconnecting";
        }
    }*/
}

void SocketWorker::handleDataClient()
{
    /*QByteArray data = m_socket->readAll();
    qDebug() << "Received:" << data;

    if (!m_hsk2Received) {
        if (data == "HSK2") {
            qDebug() << "Sending OK";
            m_socket->write("OK");
            m_hsk2Received = true;
            qDebug() << "Handshake completed successfully";
            QString ipPort = QString("%1:%2").arg(m_ip).arg(m_port);
            emit connectionEstablished(ipPort);
            // Artık normal iletişime başlayabilirsiniz
        } else {
            m_socket->disconnectFromHost();
            qDebug() << "Invalid handshake response, disconnecting";
        }
    } else {
        // Normal mesajları işle
    }*/
}

void SocketWorker::onDisconnected()
{
    if (!m_socket) {
        qDebug() << QThread::currentThread() << "onDisconnected called with null socket";
        return;
    }

    // Capture information before any operations that might affect the socket
    QString ip = m_socket->peerAddress().toString();
    QString ipPort = QString("%1:%2").arg(ip).arg(m_socket->peerPort());

    // Disconnect all signals from the socket
    disconnect(m_socket, nullptr, this, nullptr);

    if (m_socket->state() != QAbstractSocket::UnconnectedState) {
        m_socket->disconnectFromHost();
        if (m_socket->state() != QAbstractSocket::UnconnectedState) {
            m_socket->waitForDisconnected(1000);
        }
    }

    // Schedule deletion
    m_socket->deleteLater();
    m_socket = nullptr;

    emit connectionClosed(ipPort);

    qDebug() << QThread::currentThread() << "The client Disconnected ipport:" << ipPort;
}


