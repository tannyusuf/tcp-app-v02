#ifndef SCANNERMANAGER_H
#define SCANNERMANAGER_H

#include <QObject>
#include "scanner.h"

class ScannerManager : public QObject
{
    Q_OBJECT
public:
    explicit ScannerManager(QObject *parent = nullptr);

public slots:
    void startScan();

signals:
    void scanFinished(const QList<QString>&ips);
    void pinged();

private:
    void handlePingResults(const QString &ip, bool ok);

    QList<QString> m_ips;
    int m_done = 0;
    int m_total = 256;

};

#endif // SCANNERMANAGER_H
