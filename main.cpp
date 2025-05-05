#include "mainwindow.h"

#include <QApplication>
#include <QNetworkProxyFactory>
#include <QLoggingCategory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    QNetworkProxyFactory::setUseSystemConfiguration(false);

    QLoggingCategory::setFilterRules("qt.network.ssl.warning=true\n"
                                     "qt.network.ssl.fatal=true\n"
                                     "qt.network.auth.*=true\n"
                                     "qt.network.tcp.*=true\n"
                                     "qt.network.*=true");
}
