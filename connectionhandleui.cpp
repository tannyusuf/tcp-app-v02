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

