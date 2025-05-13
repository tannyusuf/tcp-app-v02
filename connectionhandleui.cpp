// connectionhandleui.cpp
#include "connectionhandleui.h"
#include "ui_connectionhandleui.h"



connectionHandleUi::connectionHandleUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::connectionHandleUi)

{
    ui->setupUi(this);
    ui->lblSending->setVisible(false);
    ui->lblSendingBar->setVisible(false);
    ui->btnCancel->setVisible(false);

}

connectionHandleUi::~connectionHandleUi()
{
    delete ui;
}

void connectionHandleUi::outputMessage(QString outputMessageParam)
{

    now = QDateTime::currentDateTime();
    timePrefix = "[" + now.toString("yyyy-MM-dd hh:mm:ss") + "] ";

    ui->lstOutput->addItem(timePrefix + outputMessageParam);
    ui->lstOutput->scrollToBottom();

}

void connectionHandleUi::setFileTransferButtonsVisibleForSending(qint64 bytesSent, qint64 bytesTotal)
{
    ui->lblSending->setVisible(true);
    ui->lblSendingBar->setVisible(true);
    ui->btnCancel->setVisible(true);
    ui->lblSending->setText("Sending File");

    ui->lblSendingBar->setRange(0, bytesTotal);
    ui->lblSendingBar->setValue(bytesSent);
}

void connectionHandleUi::setFileTransferButtonsVisibleForReceiving(qint64 bytesReceived, qint64 bytesTotal)
{
    ui->lblSending->setVisible(true);
    ui->lblSendingBar->setVisible(true);
    ui->btnCancel->setVisible(true);
    ui->lblSending->setText("Receiving File");

    ui->lblSendingBar->setRange(0, bytesTotal);
    ui->lblSendingBar->setValue(bytesReceived);

}

void connectionHandleUi::on_btnDisconnect_clicked()
{
    emit disconnectBtnClicked();
}


void connectionHandleUi::on_btnSendFile_clicked()
{
    QString path = ui->lineEditPath->text();
    emit sendFileRequested(path);


}


void connectionHandleUi::on_btnSelectFile_clicked()
{
    QFileDialog dialog(this);
    dialog.setWindowTitle(tr("Select File"));
    dialog.setDirectory(QDir::currentPath());
    dialog.setNameFilter(tr("Resim Dosyaları (*.png *.jpg);;Tüm Dosyalar (*.*)"));
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setViewMode(QFileDialog::Detail);

    if (dialog.exec() == QDialog::Accepted) {
        QString selected = dialog.selectedFiles().first();
        ui->lineEditPath->setText(selected);
        ui->btnSendFile->setEnabled(true);

        outputMessageParam = QString("File Selected: %1")
                                 .arg(selected);
        outputMessage(outputMessageParam);
    }
}


void connectionHandleUi::on_pushButton_clicked()
{
    emit cancelFileTransferRequested();

    outputMessageParam = QString("File Transfer Cancelled!");
    outputMessage(outputMessageParam);
}

void connectionHandleUi::onFileTransferProgress(qint64 bytesSent, qint64 bytesTotal, const QString &filePath)
{
    setFileTransferButtonsVisibleForSending(bytesSent, bytesTotal);
    ui->btnSelectFile->setEnabled(false);
    ui->btnCancel->setEnabled(true);
    ui->btnSendFile->setEnabled(false);

}

void connectionHandleUi::onFileReceiveProgress(qint64 bytesReceived, qint64 bytesTotal, const QString &filePath)
{
    setFileTransferButtonsVisibleForReceiving(bytesReceived, bytesTotal);
    ui->btnSelectFile->setEnabled(false);
    ui->btnCancel->setEnabled(true);
    ui->btnSendFile->setEnabled(false);

}

void connectionHandleUi::onFileReceived(const QString &filePath)
{
    ui->lblSending->setText("File Received!");
    ui->btnCancel->setEnabled(false);
    ui->btnSelectFile->setEnabled(true);
    ui->btnSendFile->setEnabled(true);
    outputMessageParam = QString("File [%1] is received!").arg(filePath);
    outputMessage(outputMessageParam);
}

void connectionHandleUi::onFileSent(const QString &filePath)
{
    ui->lblSending->setText("File Sent!");
    ui->btnCancel->setEnabled(false);
    ui->btnSelectFile->setEnabled(true);
    ui->btnSendFile->setEnabled(true);
    outputMessageParam = QString("File [%1] is sent!").arg(filePath);
    outputMessage(outputMessageParam);
}

void connectionHandleUi::onFileTransferError(const QString &errorMessage)
{
    ui->lblSending->setText("ERROR!");
    ui->btnCancel->setEnabled(false);
    ui->btnSelectFile->setEnabled(true);
    ui->btnSendFile->setEnabled(true);
    outputMessageParam = QString("[ERROR]").arg(errorMessage);
    outputMessage(outputMessageParam);
}


void connectionHandleUi::on_btnCancel_clicked()
{

    ui->lblSending->setText("File Transfer Cancelled!");
    ui->btnCancel->setEnabled(false);
    ui->btnSelectFile->setEnabled(true);
    ui->btnSendFile->setEnabled(true);
    ui->lblSendingBar->setValue(0);
    emit cancelFileTransferRequested();
}

void connectionHandleUi::transferBeginInfo(const QString &fileName)
{
    outputMessageParam = QString("File [%1] transmission is started").arg(fileName);
    outputMessage(outputMessageParam);
}




void connectionHandleUi::on_btnSelectFolder_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    tr("Select Folder"),
                                                    QDir::currentPath(),
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!dir.isEmpty()) {
        ui->lineEditPath->setText(dir);
        ui->btnSendFile->setEnabled(true);

        outputMessageParam = QString("Folder Selected: %1").arg(dir);
        outputMessage(outputMessageParam);
    }
}

