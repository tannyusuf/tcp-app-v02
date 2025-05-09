// connectionhandleui.h
#ifndef CONNECTIONHANDLEUI_H
#define CONNECTIONHANDLEUI_H

#include <QWidget>
#include <QDateTime>
#include <QFileDialog>


namespace Ui { class connectionHandleUi; }
class connectionHandleUi : public QWidget {
    Q_OBJECT
public:
    explicit connectionHandleUi(QWidget *parent = nullptr);
    ~connectionHandleUi();



private slots:
    void on_btnDisconnect_clicked();

    void on_btnSendFile_clicked();

    void on_btnSelectFile_clicked();

    void on_pushButton_clicked();

public slots:
    void onFileTransferProgress(qint64 bytesSent, qint64 bytesTotal);
    void onFileReceiveProgress(qint64 bytesReceived, qint64 bytesTotal);
    void onFileReceived(const QString &filePath);
    void onFileSent();
    void onFileTransferError(const QString &errorMessage);

private:
    Ui::connectionHandleUi *ui;


    QString outputMessageParam = "";

    QDateTime now;
    QString timePrefix;

    void outputMessage(QString outputMessageParam);

signals:
    void disconnectBtnClicked();

    void sendFileRequested(const QString &filePath);
    void cancelFileTransferRequested();

};

#endif // CONNECTIONHANDLEUI_H
