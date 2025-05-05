#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QHash>
#include <QInputDialog>
#include <QMessageBox>
#include <QApplication>
#include <QMessageBox>
#include "connect.h"
#include "connectionhandleui.h"
#include "GlobalConfig.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Connect* connPage;


    void removeTabByName(QTabWidget* tabWidget, const QString& tabName);
    QString getUserInput(QWidget* parent = nullptr);
    bool askUserToConfirmConnection(QString ipPort ,QWidget* parent = nullptr);


private:

public slots:


private slots:



signals:
    void tabCreated(connectionHandleUi* page);

};
#endif // MAINWINDOW_H
