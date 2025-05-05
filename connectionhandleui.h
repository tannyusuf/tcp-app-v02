// connectionhandleui.h
#ifndef CONNECTIONHANDLEUI_H
#define CONNECTIONHANDLEUI_H

#include <QWidget>
#include <QDateTime>


namespace Ui { class connectionHandleUi; }
class connectionHandleUi : public QWidget {
    Q_OBJECT
public:
    explicit connectionHandleUi(QWidget *parent = nullptr);
    ~connectionHandleUi();



private slots:
    void on_btnDisconnect_clicked();

private:
    Ui::connectionHandleUi *ui;


    QString outputMessageParam = "";

    QDateTime now;
    QString timePrefix;

    void outputMessage(QString outputMessageParam);

signals:
    void disconnectBtnClicked();

};

#endif // CONNECTIONHANDLEUI_H
