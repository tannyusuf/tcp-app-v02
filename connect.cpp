#include "connect.h"
#include "ui_connect.h"


Connect::Connect(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Connect)
{
    ui->setupUi(this);

    //setMovable(true);


    /*
     * Scanner starts
     */
    ui->progressBar->setRange(0, 255);
    ui->progressBar->setValue(0);
    ui->progressBar->setVisible(false);
    ui->lblScan->setVisible(false);
    ui->btnConnect->setEnabled(false);
    ui->btnListen->setEnabled(false);



    progress = ui->progressBar->value();
    connect(&scanner, &ScannerManager::scanFinished, this, &Connect::showResults);
    connect(&scanner, &ScannerManager::pinged, this, &Connect::pinged);


    /*
     * Scanner ends
     */

    /*
     * Connection handle starts
     */


        /*
        * Create and start Listener object and thread
        */



    listener = new Listener();
    listenerTh = new QThread();
    listenerTh->setObjectName("Listener Thread");
    listener->moveToThread(listenerTh);

    // Connect signals AFTER moving to thread
    connect(listenerTh, &QThread::started,
            listener, &Listener::startListening);


    connect(this, &Connect::btnDontListen_clicked, listener, &Listener::stopListening);
    connect(this, &Connect::btnListen_clicked, listener, &Listener::startListening);

    // Cleanup connections
    connect(listenerTh, &QThread::finished,
            listener, &QObject::deleteLater);
    connect(listenerTh, &QThread::finished,
            listenerTh, &QThread::deleteLater);

    connect(listener, &Listener::connectionEstablished,
            this, [=](QString clientName){
                emit connectionEstablished(clientName);
                outputMessageParam = QString("New Connection with %1").arg(clientName);
                outputMessage(outputMessageParam);

            });

    connect(this, &Connect::tabCreatedSignal,
            listener, &Listener::tabCreatedSlot);

    connect(listener, &Listener::deleteTab,
            this, [=](QString clientName){
                emit deleteTab(clientName);
            });

    connect(this, &Connect::disconnectRequestedFromMainSignal, listener, &Listener::disconnectRequestedFromMain);

    listenerTh->start();
    qDebug() << QThread::currentThread() << ": Listener Started";
}

Connect::~Connect()
{
    /* Cleaning */

    listenerTh->quit();

    if (listenerTh && listenerTh->isRunning()) {
        qDebug() << "Stopping ConnectionManager thread";
        listenerTh->quit();
        if (!listenerTh->wait(1000)) {
            qWarning() << "Forcing thread termination";
            listenerTh->terminate();
        }
    }



    delete ui;
}

void Connect::outputMessage(QString outputMessageParam)
{

    now = QDateTime::currentDateTime();
    timePrefix = "[" + now.toString("yyyy-MM-dd hh:mm:ss") + "] ";

    ui->lstOutput->addItem(timePrefix + outputMessageParam);
    ui->lstOutput->scrollToBottom();

}


    /*
     * Scanner starts
     */

void Connect::showResults(const QList<QString> &ips)
{

    ui->cmbIpAdd->clear();
    for(int i = 0; i < ips.count(); i++){

        ui->cmbIpAdd->addItem(ips.at(i));
        outputMessageParam = "Reachable ip: " + ips.at(i);
        outputMessage(outputMessageParam);

    }

    ui->lblScan->setText("Done !");
    ui->btnConnect->setEnabled(true);
}


void Connect::on_btnScan_clicked()
{

    ui->lblScan->setText("Scanning ...");
    outputMessageParam = "IPs are scanning...";
    outputMessage(outputMessageParam);

    ui->progressBar->setVisible(true);
    ui->lblScan->setVisible(true);
    ui->btnConnect->setEnabled(false);

    progress = 0;
    ui->progressBar->setValue(progress);

    scanner.startScan();
}

void Connect::pinged()
{
    ui->progressBar->setValue(progress++);
}

    /*
     * Scanner ends
     */








void Connect::tabCreatedSlot(connectionHandleUi *page)
{
    emit tabCreatedSignal(page);
}

void Connect::disconnectRequestedFromMain(QString clientName)
{
    emit disconnectRequestedFromMainSignal(clientName);
}


void Connect::on_btnConnect_clicked()
{
    QString ip = ui->cmbIpAdd->currentText();
    QTcpSocket* socket = new QTcpSocket();


    //QString ipPort = QString("%1:%2").arg(socket->peerAddress().toString())
    //                     .arg(socket->peerPort());


    socket->setParent(nullptr);
    //qDebug() << QThread::currentThread() << "Socket thread(Main)" << socket->thread();
    SocketWorker* worker = new SocketWorker();
    connect(this, &Connect::sendIpPortToWorker, worker, &SocketWorker::receiveIpPort);
    emit sendIpPortToWorker(ip, port);
    QThread* workerTh = new QThread();
    workerTh->setObjectName("Worker Thread from Connect");



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
            worker, &SocketWorker::socketFromConnect);


    connect(worker, &SocketWorker::connectionEstablishedFromConnect,
            this, [=](QString clientName){
                emit connectionEstablishedFromConnect(clientName);
                outputMessageParam = QString("New Connection with %1").arg(clientName);
                outputMessage(outputMessageParam);
                //qDebug() << "connected:" << ipPort;
            });

    connect(this, &Connect::tabCreatedSignal,
            worker, &SocketWorker::tabCreated);

    connect(worker, &SocketWorker::connectionClosed,
            this, [=](QString clientName){
                emit deleteTab(clientName);
            outputMessageParam = QString("Connection closed with %1").arg(clientName);
            outputMessage(outputMessageParam);
            });

    workerTh->start();

}


void Connect::on_btnListen_clicked()
{
    emit btnListen_clicked();
    ui->btnDontListen->setEnabled(true);
    ui->btnListen->setEnabled(false);

    outputMessageParam = "Listening for new connections.";
    outputMessage(outputMessageParam);
}



void Connect::on_btnDontListen_clicked()
{
    emit btnDontListen_clicked();
    ui->btnListen->setEnabled(true);
    ui->btnDontListen->setEnabled(false);

    outputMessageParam = "Not listening for new connections.";
    outputMessage(outputMessageParam);
}

