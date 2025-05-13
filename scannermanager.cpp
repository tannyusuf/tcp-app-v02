#include "scannermanager.h"
#include <QThread>



ScannerManager::ScannerManager(QObject *parent)
    : QObject{parent}
{}

void ScannerManager::startScan()
{
    m_ips.clear();
    m_done = 0;

    const QString base = "10.10.238.";

    for(int i = 0; i < m_total; i++){

        QThread *thread = new QThread();
        Scanner *task = new Scanner(base + QString::number(i));
        task->moveToThread(thread);

        connect(thread, &QThread::started, task, &Scanner::doPing);
        connect(task, &Scanner::pingResult, this, &ScannerManager::handlePingResults, Qt::QueuedConnection);

        connect(task, &Scanner::finished, thread, &QThread::quit);
        connect(task, &Scanner::finished, task, &Scanner::deleteLater);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        thread->start();

    }
}

void ScannerManager::handlePingResults(const QString &ip, bool ok)
{
    emit pinged();
    if(ok){

        m_ips.append(ip);

    }

    if(++m_done == m_total)
        emit scanFinished(m_ips);

}


