#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GlobalConfig::username().setUsernameOnce(getUserInput(this));
    qDebug() << "Username is set: " << GlobalConfig::username().getUsername();
    connPage = new Connect();
    ui->tabWdg->addTab(connPage, "Connection");




    connect(connPage, &Connect::connectionEstablished, [this](QString clientName) {
        // Add new tab

        if(askUserToConfirmConnection(clientName)){
            connectionHandleUi* page = new connectionHandleUi();
            ui->tabWdg->addTab(page, clientName);  // Removed tabIndex variable since it's unused
            emit tabCreated(page);
        }

        else{
            emit disconnect(clientName);
            connect(this, &MainWindow::disconnect, connPage, &Connect::disconnectRequestedFromMain);
        }

    });

    connect(connPage, &Connect::connectionEstablishedFromConnect, [this](QString clientName) {
        // Add new tab

        connectionHandleUi* page = new connectionHandleUi();
        ui->tabWdg->addTab(page, clientName);  // Removed tabIndex variable since it's unused
        emit tabCreated(page);

    });




    connect(this, &MainWindow::tabCreated, connPage, &Connect::tabCreatedSlot);
    // Connect tab close signal
    connect(connPage, &Connect::deleteTab,
            this, [=](QString clientName){
        removeTabByName(ui->tabWdg, clientName);
            });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::removeTabByName(QTabWidget *tabWidget, const QString &tabName)
{
    // Tüm tab'ları dolaş
    for (int i = 0; i < tabWidget->count(); ++i) {
        // Tab'ın metnini kontrol et
        if (tabWidget->tabText(i) == tabName) {
            // Önce widget'ı al ve sonra sil
            QWidget* widget = tabWidget->widget(i);
            tabWidget->removeTab(i);
            delete widget; // Uncommented this line to prevent memory leak
            return; // Tab bulundu ve silindi, fonksiyondan çık
        }
    }
    // Tab bulunamadıysa uyarı verebilirsiniz
    qWarning() << "Tab with name" << tabName << "not found";
}

QString MainWindow::getUserInput(QWidget *parent)
{
    while (true) {
        bool ok;
        QString text = QInputDialog::getText(parent,
                                             "File Transfer",
                                             "Enter your username:",
                                             QLineEdit::Normal,
                                             "", &ok);
        if (!ok) {
            QTimer::singleShot(0, [](){
                qApp->quit();
            });
            return "";
        }

        if (!text.trimmed().isEmpty()) {
            return text.trimmed();  // Geçerli giriş
        }


        QMessageBox::warning(parent, "Uyarı", "Boş giriş yapılamaz. Lütfen bir değer girin.");
    }
    //QApplication::quit();

}

bool MainWindow::askUserToConfirmConnection(QString clientName, QWidget *parent)
{
    QMessageBox::StandardButton reply = QMessageBox::question(parent,
                                                              "Confirm Connection",
                                                              "New connection established with " +
                                                              clientName + "\nDo you confirm?",
                                                              QMessageBox::Yes | QMessageBox::No);

    return reply == QMessageBox::Yes;
}





