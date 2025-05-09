#include "listener.h"

Listener::Listener(QObject *parent)
    : QObject(parent),
    m_server(nullptr)
{

}


Listener::~Listener()
{

    if(m_server) {
        m_server->close();
    }
}

void Listener::startListening()
{
    Q_ASSERT(QThread::currentThread() == this->thread());

    m_server = new QTcpServer(this);

    connect(m_server, &QTcpServer::newConnection,
            this, &Listener::onNewConnection);

    if(!m_server->listen(QHostAddress::Any, m_port)) {
        qCritical() << QThread::currentThread()
        << "Listen failed:" << m_server->errorString();
        //emit serverError(m_server->errorString());
        return;
    }

    qInfo() << "Listening on port" << m_port
            << "in thread" << QThread::currentThread();
}

void Listener::stopListening()
{
    if (m_server && m_server->isListening()) {
        m_server->close();
        qDebug() << "Server stopped listening";
    }
}

void Listener::tabCreatedSlot(connectionHandleUi *page)
{
    emit tabCreatedSignal(page);
}

void Listener::disconnectRequestedFromMain(QString clientName)
{
    emit disconnectRequestedFromMainSignal(clientName);
}


void Listener::onNewConnection()
{

    Q_ASSERT(QThread::currentThread() == this->thread());

    while(m_server->hasPendingConnections()) {
        QTcpSocket* socket = m_server->nextPendingConnection();
        socket->setParent(nullptr); // Remove server as parent

        qDebug() << QThread::currentThread() << "Socket thread(Listener)" << socket->thread();
        SocketWorker* worker = new SocketWorker();
        QThread* workerTh = new QThread();
        workerTh->setObjectName("Worker Thread");

        worker->moveToThread(workerTh);

        socket->moveToThread(workerTh);
        worker->setSocket(socket);



        connect(worker, &SocketWorker::finished,
                workerTh, &QThread::quit);
        connect(workerTh, &QThread::finished,
                workerTh, &QThread::deleteLater);
        connect(workerTh, &QThread::destroyed,
                worker, &QObject::deleteLater);
        connect(workerTh, &QThread::started,
                worker, &SocketWorker::startProcessing);

        connect(worker, &SocketWorker::connectionEstablished,
                        this, [=](QString clientName){
            emit connectionEstablished(clientName);
        });
        connect(this, &Listener::tabCreatedSignal,
                worker, &SocketWorker::tabCreated);


        connect(worker, &SocketWorker::connectionClosed,
                this, [=](QString clientName){
                    emit deleteTab(clientName);
                });

        connect(this, &Listener::disconnectRequestedFromMainSignal, worker, &SocketWorker::disconnectRequestFromMain);

        workerTh->start();

        qDebug() << QThread::currentThread() << socket->peerAddress().toString() << ":" << socket->peerPort();

    }
}

void Listener::onSocketError(QAbstractSocket::SocketError err)
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    qDebug() << "Socket error:" << err << "-" << socket->errorString();
    socket->deleteLater();
}

