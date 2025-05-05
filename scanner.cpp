#include "scanner.h"
#include <QProcess>
#include <QDebug>

Scanner::Scanner(const QString &ip, QObject *parent)
    : QObject(parent), m_ip(ip)
{
}

void Scanner::doPing()
{
    QProcess process;
    QStringList arguments;

#ifdef Q_OS_WIN
    // Windows için: -n 1 -> 1 kez ping gönder
    arguments << "-n" << "1" << m_ip;
#else
    // Diğer sistemler için: -c 1 -> 1 kez ping gönder
    arguments << "-c" << "1" << m_ip;
#endif

    process.start("ping", arguments);


    if (!process.waitForFinished(5000)) {
        qDebug() << "Ping komutu tamamlanamadı:" << m_ip;
        qDebug() << "Hata:" << process.errorString() << "Ip:" << m_ip;
        emit pingResult(m_ip, false);
        emit finished();
        return;
    }


    QByteArray stdOutput = process.readAllStandardOutput();
    QByteArray stdError = process.readAllStandardError();


    QString output = QString::fromLocal8Bit(stdOutput) + QString::fromLocal8Bit(stdError);
    output = output.toLower();

    bool success = output.contains("ttl=");

    emit pingResult(m_ip, success);
    emit finished();
}
