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
    ///
    /// // Dosya transferi bağlantıları
    connect(page, &connectionHandleUi::sendFileRequested,
            this, &SocketWorker::sendFile, Qt::QueuedConnection);
    connect(page, &connectionHandleUi::cancelFileTransferRequested,
            this, &SocketWorker::cancelFileTransfer, Qt::QueuedConnection);

    connect(this, &SocketWorker::fileTransferProgress,
            page, &connectionHandleUi::onFileTransferProgress, Qt::QueuedConnection);
    connect(this, &SocketWorker::fileReceiveProgress,
            page, &connectionHandleUi::onFileReceiveProgress, Qt::QueuedConnection);
    connect(this, &SocketWorker::fileReceived,
            page, &connectionHandleUi::onFileReceived, Qt::QueuedConnection);
    connect(this, &SocketWorker::fileSent,
            page, &connectionHandleUi::onFileSent, Qt::QueuedConnection);
    connect(this, &SocketWorker::fileTransferError,
            page, &connectionHandleUi::onFileTransferError, Qt::QueuedConnection);


}

void SocketWorker::disconnectRequestFromMain(QString ipPort)
{
    onDisconnected();
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

void SocketWorker::sendFile(const QString &filePath)
{
    // Bağlantı durumunu kontrol et
    if (!m_socket || m_socket->state() != QAbstractSocket::ConnectedState) {
        emit fileTransferError("Bağlantı yok");
        return;
    }

    // Handshake tamamlanmış mı kontrol et
    if (m_state != HandshakeState::onHost_completed &&
        m_state != HandshakeState::onClient_completed) {
        emit fileTransferError("Bağlantı henüz hazır değil");
        return;
    }

    // Dosya açma
    m_outgoingFile.setFileName(filePath);
    if (!m_outgoingFile.open(QIODevice::ReadOnly)) {
        emit fileTransferError("Dosya açılamadı: " + filePath);
        return;
    }

    m_fileSize = m_outgoingFile.size();
    m_sendingFile = true;

    // Dosya adını ve boyutunu gönder
    QFileInfo fileInfo(filePath);
    QString fileName = fileInfo.fileName();

    // FILE_BEGIN komutu, ardından dosya adı ve boyutu
    QString fileHeader = QString("FILE_BEGIN:%1:%2\n").arg(fileName).arg(m_fileSize);
    m_socket->write(fileHeader.toUtf8());
    m_socket->flush();

    // Dosya içeriğini okuma ve gönderme
    sendFileChunk();
}

void SocketWorker::cancelFileTransfer()
{
    if (m_sendingFile) {
        m_socket->write("FILE_CANCEL\n");
        m_socket->flush();
        m_outgoingFile.close();
        m_sendingFile = false;
    }

    if (m_receivingFile) {
        m_incomingFile.close();
        m_receivingFile = false;
        m_bytesReceived = 0;
    }
}

void SocketWorker::sendFileChunk()
{
    // Dosya gönderimi devam ediyor mu?
    if (!m_sendingFile || !m_socket) {
        return;
    }

    // Buffer boyutu
    const qint64 chunkSize = 4096; // 4KB chunk boyutu

    // Buffer'a dosyadan veri oku
    QByteArray buffer = m_outgoingFile.read(chunkSize);

    if (buffer.isEmpty()) {
        // Dosya sonuna ulaşıldı, transfer tamamlandı
        m_socket->write("FILE_END\n");
        m_socket->flush();
        m_outgoingFile.close();
        m_sendingFile = false;
        emit fileSent();
        return;
    }

    // FILE_DATA komutunu gönder, ardından buffer boyutu ve veri
    QByteArray header = QString("FILE_DATA:%1\n").arg(buffer.size()).toUtf8();
    m_socket->write(header);
    m_socket->write(buffer);
    m_socket->flush();

    // Dosya gönderim durumunu güncelle
    qint64 bytesSent = m_outgoingFile.pos();
    emit fileTransferProgress(bytesSent, m_fileSize);

    // Eğer hala gönderecek veri varsa, bir sonraki parçayı göndermek için
    // QTimer kullanarak kuyruk oluşturma
    QTimer::singleShot(0, this, &SocketWorker::sendFileChunk);
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
                emit connectionEstablishedFromConnect(m_clientName);
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
            // Dosya transferi komutları kontrolü
            if (line.startsWith("FILE_BEGIN:")) {
                // Yeni bir dosya transferi başlıyor
                QStringList parts = line.split(":");
                if (parts.size() >= 3) {
                    m_currentFileName = parts[1];
                    m_fileSize = parts[2].toLongLong();
                    m_bytesReceived = 0;
                    m_receivingFile = true;

                    // Dosya yolunu doğru şekilde oluştur
                    QString filePath = m_fileReceiveDir + "/" + m_currentFileName;
                    m_incomingFile.setFileName(filePath);

                    if (!m_incomingFile.open(QIODevice::WriteOnly)) {
                        m_socket->write("FILE_ERROR:Dosya oluşturulamadı\n");
                        m_socket->flush();
                        m_receivingFile = false;
                    }
                    else {
                        m_socket->write("FILE_READY\n");
                        m_socket->flush();
                    }
                }
            }
            else if (line.startsWith("FILE_DATA:")) {
                if (m_receivingFile) {
                    // Veri parçası geliyor
                    QStringList parts = line.split(":");
                    if (parts.size() >= 2) {
                        int dataSize = parts[1].toInt();

                        // Veriyi oku
                        QByteArray buffer = m_socket->read(dataSize);
                        while (buffer.size() < dataSize && m_socket->waitForReadyRead(1000)) {
                            buffer.append(m_socket->read(dataSize - buffer.size()));
                        }

                        // Dosyaya yaz
                        if (buffer.size() == dataSize) {
                            m_incomingFile.write(buffer);
                            m_bytesReceived += buffer.size();
                            emit fileReceiveProgress(m_bytesReceived, m_fileSize);
                        }
                        else {
                            // Veri eksik
                            m_socket->write("FILE_ERROR:Eksik veri\n");
                            m_socket->flush();
                            m_incomingFile.close();
                            m_receivingFile = false;
                        }
                    }
                }
            }
            else if (line == "FILE_END") {
                if (m_receivingFile) {
                    // Dosya transferi tamamlandı
                    m_incomingFile.close();
                    m_receivingFile = false;
                    emit fileReceived(m_incomingFile.fileName());
                    m_socket->write("FILE_COMPLETE\n");
                    m_socket->flush();
                }
            }
            else if (line.startsWith("FILE_ERROR:")) {
                // Karşı taraftan bir hata geldi
                QString errorMsg = line.mid(11);
                emit fileTransferError(errorMsg);
                if (m_sendingFile) {
                    m_outgoingFile.close();
                    m_sendingFile = false;
                }
            }
            else if (line == "FILE_CANCEL") {
                // Transfer iptal edildi
                if (m_receivingFile) {
                    m_incomingFile.close();
                    m_receivingFile = false;
                }
                if (m_sendingFile) {
                    m_outgoingFile.close();
                    m_sendingFile = false;
                }
            }
            else if (line == "FILE_READY") {
                // Karşı taraf dosya almaya hazır
                if (m_sendingFile) {
                    sendFileChunk();
                }
            }
            else if (line == "FILE_COMPLETE") {
                // Dosya başarıyla gönderildi
                if (m_sendingFile) {
                    m_outgoingFile.close();
                    m_sendingFile = false;
                    emit fileSent();
                }
            }
            else {
                // Normal metin mesajı
                emit messageReceived(m_clientName, line);
            }
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


