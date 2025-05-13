// connectionhandleui.h
#ifndef CONNECTIONHANDLEUI_H
#define CONNECTIONHANDLEUI_H

#include <QWidget>
#include <QDateTime>
#include <QFileDialog>
#include <QMessageBox>


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



    void on_btnSelectFolder_clicked();

public slots:
    void onFileTransferProgress(qint64 bytesSent, qint64 bytesTotal, const QString &filePath);
    void onFileReceiveProgress(qint64 bytesReceived, qint64 bytesTotal, const QString &filePath);
    void onFileReceived(const QString &filePath);
    void onFileSent(const QString &filePath);
    void onFileTransferError(const QString &errorMessage);

    void on_btnCancel_clicked();

    void transferBeginInfo(const QString &fileName);


private:
    Ui::connectionHandleUi *ui;


    QString outputMessageParam = "";

    QDateTime now;
    QString timePrefix;

    void outputMessage(QString outputMessageParam);
    void setFileTransferButtonsVisibleForSending(qint64 bytesSent, qint64 bytesTotal);
    void setFileTransferButtonsVisibleForReceiving(qint64 bytesReceived, qint64 bytesTotal);

signals:
    void disconnectBtnClicked();

    void sendFileRequested(const QString &filePath);
    void cancelFileTransferRequested();


};

#endif // CONNECTIONHANDLEUI_H
