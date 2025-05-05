#include <QCoreApplication>
#include <QThread>
#include <QProcess>
#include <QDebug>
#include <QObject>

class Scanner : public QObject {
    Q_OBJECT
public:
    explicit Scanner(const QString &ip, QObject *parent = nullptr);

public slots:
    void doPing();

signals:
    void pingResult(const QString &ip, bool success);
    void finished();

private:
    QString m_ip;
};
