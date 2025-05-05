#ifndef CONNECT_H
#define CONNECT_H

#include <QWidget>
#include <QDateTime>
#include <QThread>
#include <QHash>
#include "connectionhandleui.h"
#include "scannermanager.h"
#include "connectionmanager.h"
#include "listener.h"

namespace Ui {
class Connect;
}

class Connect : public QWidget
{
    Q_OBJECT

public:
    explicit Connect(QWidget *parent = nullptr);
    ~Connect();

private:
    Ui::Connect *ui;

    /*
     * Scanner starts
     */
    quint16 port = 8000;
    ScannerManager scanner;
    int progress = 0;

    QString outputMessageParam = "";

    QDateTime now;
    QString timePrefix;


    void outputMessage(QString outputMessageParam);
    /*
     * Scanner ends
     */

    Listener* listener;
    QThread* listenerTh;





private slots:
    /*
     * Scanner starts
     */
    void showResults(const QList<QString>& ips);
    void on_btnScan_clicked();

    void pinged();
    /*
     * Scanner ends
     */

    //addTab




    void on_btnDontListen_clicked();

    void on_btnConnect_clicked();

    void on_btnListen_clicked();

public slots:

    void tabCreatedSlot(connectionHandleUi* page);

signals:

    void connectionEstablished(QString ipPort);
    void deleteTab(QString ipPort);
    void btnDontListen_clicked();
    void btnListen_clicked();
    void tabCreatedSignal(connectionHandleUi* page);
    void sendIpPortToWorker(QString ip, quint16 port);



};

#endif // CONNECT_H
