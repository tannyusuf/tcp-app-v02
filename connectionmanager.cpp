#include "connectionmanager.h"

ConnectionManager::ConnectionManager(QObject *parent)
    : QObject{parent}
{
    listener = new Listener();
    listenerTh = new QThread();
    listenerTh->setObjectName("Listener Thread");
    listener->moveToThread(listenerTh);

    // Connect signals AFTER moving to thread
    connect(listenerTh, &QThread::started,
            listener, &Listener::startListening);
    connect(listener, &Listener::newSocketAvailable,
            this, &ConnectionManager::handleNewSocketFromListener,
            Qt::QueuedConnection); // Crucial for thread safety

    // Cleanup connections
    connect(listenerTh, &QThread::finished,
            listener, &QObject::deleteLater);
    connect(listenerTh, &QThread::finished,
            listenerTh, &QThread::deleteLater);

    listenerTh->start();
    qDebug() << QThread::currentThread() << ": Listener Started";


}


/*
 *Burası hakkında düşünelim
 */
ConnectionManager::~ConnectionManager()
{
    qDebug() << QThread::currentThread() << ": Shutting down all threads...";

    // 1. Stop all worker threads
    for (QThread* thread : activeWorkerThreads) {
        thread->quit();
        if(thread->isRunning()){
            thread->terminate();
        }
    }

    // 2. Stop listener thread
    if (listenerTh && listenerTh->isRunning()) {
        listenerTh->quit();
        if (!listenerTh->wait(2000)) {
            listenerTh->terminate();
            listenerTh->wait();
        }
    }

    qDebug() << QThread::currentThread() << ": All threads stopped";
}

void ConnectionManager::handleNewSocketFromListener(QTcpSocket *socket)
{
    qDebug() << QThread::currentThread() << socket->peerAddress().toString() << ":" << socket->peerPort();
    //qDebug() << QThread::currentThread() << socket.;
    // Verify we're in manager thread
    Q_ASSERT(QThread::currentThread() == this->thread());

    // Create worker and dedicated thread
    QThread* workerThread = new QThread;
    connectionHandleUi* page = new connectionHandleUi();
    SocketWorker* worker = new SocketWorker(socket, page);
    workerThread->setObjectName("Worker Thread");

    connect(worker, &SocketWorker::finished,
            workerThread, &QThread::quit);
    connect(workerThread, &QThread::finished,
            workerThread, &QThread::deleteLater);
    connect(workerThread, &QThread::destroyed,
            worker, &QObject::deleteLater);

    //connect(worker, &SocketWorker::connectionEstablished,
    //        this, &ConnectionManager::connectionEstablished);

    connect(worker, &SocketWorker::connectionEstablished, [this](connectionHandleUi* page, QString ipPort) {
        emit addNewTab(page, ipPort);
    });

    connect(worker, &SocketWorker::connectionClosed, [this, workerThread](QString ipPort){
        //qDebug() << QThread::currentThread() << "The client Disconnected";
        emit deleteTab(ipPort);
        activeWorkerThreads.removeOne(workerThread);
        qDebug() << QThread::currentThread() << "Active Threads: (connect)";
        for (QThread *thread : activeWorkerThreads){

            qDebug() << thread->objectName();
        }
    });

    socket->moveToThread(workerThread);

    // Move both to worker thread
    worker->moveToThread(workerThread);
    // Socket is moved automatically via parent-child

    // Start processing
    connect(workerThread, &QThread::started,
            worker, &SocketWorker::startProcessing);

    /*QString socketAddress = QString("%1:%2")
                                .arg(socket->peerAddress().toString())
                                .arg(socket->peerPort());
    emit addNewTab(page, socketAddress);*/

    workerThread->start();


    qDebug() << "Worker thread started:" << workerThread->isRunning();

    activeWorkerThreads.append(workerThread);
    connect(workerThread, &QThread::finished, this, [this, workerThread](){
        activeWorkerThreads.removeAll(workerThread);
    });

    qDebug() << QThread::currentThread() << "Active Threads: (connect)";
    for (QThread *thread : activeWorkerThreads){

        qDebug() << thread->objectName();
    }


}

/*void ConnectionManager::connectionEstablished()
{
    emit addTab();
}*/
