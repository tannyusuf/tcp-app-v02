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

    m_state = HandshakeState::onHost_receivingHSK1;
    connect(m_socket, &QTcpSocket::disconnected, this, &SocketWorker::onDisconnected, Qt::DirectConnection);


    connect(m_socket, &QTcpSocket::readyRead,
            this, &SocketWorker::handleData,
            Qt::DirectConnection);

    qDebug() << "Socket thread:(worker thread)" << m_socket->thread();
    qDebug() << "(Worker) socket connected to:" << m_socket->peerAddress().toString() << m_socket->peerPort();



    m_ip = m_socket->peerAddress().toString();
    m_port = m_socket->peerPort();


    QString ipPort = QString("%1:%2").arg(m_ip).arg(m_port);

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
            this, &SocketWorker::handleData,
            Qt::DirectConnection);
    connect(m_socket, &QTcpSocket::connected, this, [this]() {

        QString ipPort = QString("%1:%2").arg(m_ip).arg(m_port);

        qDebug() << "socket connected to(WorkerThread):" << ipPort;


        m_state = HandshakeState::onClient_receivingHSK2;
        m_socket->write("HSK1\n");
        m_socket->flush();

    });
    connect(m_socket, &QTcpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError socketError) {
        qDebug() << "Connection error:" << m_socket->errorString();
        //errorhand
    });


    m_socket->connectToHost(m_ip, m_port);

}

void SocketWorker::receiveIpPort(QString ip, quint16 port)
{
    m_ip = ip;
    m_port = port;
}



void SocketWorker::handleData()
{

    //handshake
    while (m_socket->canReadLine()) {
        QString line = QString::fromUtf8(m_socket->readLine()).trimmed();
        qDebug() << "Received:" << line;

        switch (m_state) {
        case HandshakeState::onHost_receivingHSK1:
            if (line == "HSK1") {

                m_state = HandshakeState::onHost_sendingHSK2;
                qDebug() << "Server: Received HSK1";


                m_socket->write("HSK2\n");
                m_socket->flush();
                m_state = HandshakeState::onHost_receivingName;
                qDebug() << "Server: Sent HSK2";
            }
            else {
                m_socket->write("ERR\n");
                m_socket->flush();
                m_socket->disconnectFromHost();
                qDebug() << "Unexpected message in WaitingForHSK1:" << line;
            }
            break;



        case HandshakeState::onClient_receivingHSK2:
            if (line == "HSK2") {

                m_state = HandshakeState::onClient_sendingName;
                qDebug() << "Client: Received HSK2";


                m_socket->write((m_name + "\n").toUtf8());
                m_socket->flush();
                m_state = HandshakeState::onClient_receivingName;
                qDebug() << "Client: Sent name";
            }
            else {
                m_socket->write("ERR\n");
                m_socket->flush();
                m_socket->disconnectFromHost();
                qDebug() << "Unexpected message in WaitingForHSK2:" << line;
            }
            break;



        case HandshakeState::onHost_receivingName:
            m_clientName = line;
            m_state = HandshakeState::onHost_sendingName;
            qDebug() << "Server: Received name";

            // İsmi hemen gönder
            m_socket->write((m_name + "\n").toUtf8());
            m_socket->flush();
            m_state = HandshakeState::onHost_receivingOK;
            qDebug() << "Server: Sent name";
            break;



        case HandshakeState::onClient_receivingName:
            m_clientName = line;
            m_state = HandshakeState::onClient_sendingOK;
            qDebug() << "Client: Received name";

            // OK'yi hemen gönder
            m_socket->write("OK\n");
            m_socket->flush();
            m_state = HandshakeState::onClient_receivingOK;
            qDebug() << "Client: Sent OK";
            break;



        case HandshakeState::onHost_receivingOK:
            if (line == "OK") {

                m_state = HandshakeState::onHost_sendingOK;
                qDebug() << "Server: Received OK";


                m_socket->write("OK\n");
                m_socket->flush();
                m_state = HandshakeState::onHost_completed;
                qDebug() << "Server: Sent OK";

                emit connectionEstablished(m_clientName);
            }
            else {
                m_socket->write("ERR\n");
                m_socket->flush();
                m_socket->disconnectFromHost();
                qDebug() << "Unexpected message in WaitingForOK:" << line;
            }
            break;



        case HandshakeState::onClient_receivingOK:
            if (line == "OK") {
                // Client davranışı
                m_state = HandshakeState::onClient_completed;
                qDebug() << "Client: Received OK";
                emit connectionEstablished(m_clientName);
            }
            else {
                m_socket->write("ERR\n");
                m_socket->flush();
                m_socket->disconnectFromHost();
                qDebug() << "Unexpected message in WaitingForOK:" << line;
            }
            break;

        case HandshakeState::onHost_completed:
        case HandshakeState::onClient_completed:

            //emit messageReceived(m_clientName, line);
            break;

        default:
            qDebug() << "Unknown state: " << static_cast<int>(m_state);
            break;
        }
    }
}


void SocketWorker::onDisconnected()
{
    if (!m_socket) {
        qDebug() << QThread::currentThread() << "onDisconnected called with null socket";
        return;
    }


    QString ip = m_socket->peerAddress().toString();
    QString ipPort = QString("%1:%2").arg(ip).arg(m_socket->peerPort());


    disconnect(m_socket, nullptr, this, nullptr);

    if (m_socket->state() != QAbstractSocket::UnconnectedState) {
        m_socket->disconnectFromHost();
        if (m_socket->state() != QAbstractSocket::UnconnectedState) {
            m_socket->waitForDisconnected(1000);
        }
    }


    m_socket->deleteLater();
    m_socket = nullptr;

    emit connectionClosed(m_clientName);

    qDebug() << QThread::currentThread() << "The client Disconnected ipport:" << ipPort;
}


