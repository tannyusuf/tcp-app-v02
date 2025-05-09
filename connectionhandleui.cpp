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
}

void connectionHandleUi::onFileTransferProgress(qint64 bytesSent, qint64 bytesTotal)
{

}

void connectionHandleUi::onFileReceiveProgress(qint64 bytesReceived, qint64 bytesTotal)
{

}

void connectionHandleUi::onFileReceived(const QString &filePath)
{

}

void connectionHandleUi::onFileSent()
{

}

void connectionHandleUi::onFileTransferError(const QString &errorMessage)
{

}

