/********************************************************************************
** Form generated from reading UI file 'connect.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT_H
#define UI_CONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Connect
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *lblOutput;
    QListWidget *lstOutput;
    QGridLayout *gridLayout_2;
    QLabel *lblScan;
    QProgressBar *progressBar;
    QGridLayout *gridLayout;
    QComboBox *cmbIpAdd;
    QLabel *lblIpAdd;
    QPushButton *btnScan;
    QPushButton *btnConnect;
    QGridLayout *gridLayout_5;
    QPushButton *btnDontListen;
    QLabel *lblListening;
    QPushButton *btnListen;

    void setupUi(QWidget *Connect)
    {
        if (Connect->objectName().isEmpty())
            Connect->setObjectName("Connect");
        Connect->resize(800, 575);
        Connect->setMinimumSize(QSize(800, 575));
        Connect->setMaximumSize(QSize(800, 575));
        layoutWidget = new QWidget(Connect);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 30, 771, 521));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 10, 8);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(-1, -1, -1, 25);
        lblOutput = new QLabel(layoutWidget);
        lblOutput->setObjectName("lblOutput");

        gridLayout_3->addWidget(lblOutput, 4, 0, 1, 1);

        lstOutput = new QListWidget(layoutWidget);
        lstOutput->setObjectName("lstOutput");
        lstOutput->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);

        gridLayout_3->addWidget(lstOutput, 6, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 3, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        lblScan = new QLabel(layoutWidget);
        lblScan->setObjectName("lblScan");

        gridLayout_2->addWidget(lblScan, 0, 0, 1, 1);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(0);

        gridLayout_2->addWidget(progressBar, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        cmbIpAdd = new QComboBox(layoutWidget);
        cmbIpAdd->setObjectName("cmbIpAdd");

        gridLayout->addWidget(cmbIpAdd, 0, 1, 1, 2);

        lblIpAdd = new QLabel(layoutWidget);
        lblIpAdd->setObjectName("lblIpAdd");

        gridLayout->addWidget(lblIpAdd, 0, 0, 1, 1);

        btnScan = new QPushButton(layoutWidget);
        btnScan->setObjectName("btnScan");

        gridLayout->addWidget(btnScan, 1, 0, 1, 1);

        btnConnect = new QPushButton(layoutWidget);
        btnConnect->setObjectName("btnConnect");

        gridLayout->addWidget(btnConnect, 1, 1, 1, 2);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        btnDontListen = new QPushButton(layoutWidget);
        btnDontListen->setObjectName("btnDontListen");

        gridLayout_5->addWidget(btnDontListen, 0, 2, 1, 1);

        lblListening = new QLabel(layoutWidget);
        lblListening->setObjectName("lblListening");

        gridLayout_5->addWidget(lblListening, 0, 0, 1, 1);

        btnListen = new QPushButton(layoutWidget);
        btnListen->setObjectName("btnListen");

        gridLayout_5->addWidget(btnListen, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_5, 2, 0, 1, 1);


        retranslateUi(Connect);

        QMetaObject::connectSlotsByName(Connect);
    } // setupUi

    void retranslateUi(QWidget *Connect)
    {
        Connect->setWindowTitle(QCoreApplication::translate("Connect", "Form", nullptr));
        lblOutput->setText(QCoreApplication::translate("Connect", "Program Output", nullptr));
        lblScan->setText(QCoreApplication::translate("Connect", "Scanning ...", nullptr));
        lblIpAdd->setText(QCoreApplication::translate("Connect", "IP Addresses", nullptr));
        btnScan->setText(QCoreApplication::translate("Connect", "Scan", nullptr));
        btnConnect->setText(QCoreApplication::translate("Connect", "Connect", nullptr));
        btnDontListen->setText(QCoreApplication::translate("Connect", "Don't Listen", nullptr));
        lblListening->setText(QCoreApplication::translate("Connect", "Listening mode ON.", nullptr));
        btnListen->setText(QCoreApplication::translate("Connect", "Listen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Connect: public Ui_Connect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_H
