/********************************************************************************
** Form generated from reading UI file 'connectionhandleui.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONHANDLEUI_H
#define UI_CONNECTIONHANDLEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_connectionHandleUi
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QWidget *fileSelectWdg;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnSelectFile;
    QLineEdit *lineEditPath;
    QPushButton *btnSendFile;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnDisconnect;
    QGridLayout *gridLayout_3;
    QProgressBar *lblSendingBar;
    QLabel *lblSending;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblOutput;
    QListWidget *lstOutput;

    void setupUi(QWidget *connectionHandleUi)
    {
        if (connectionHandleUi->objectName().isEmpty())
            connectionHandleUi->setObjectName("connectionHandleUi");
        connectionHandleUi->resize(800, 575);
        connectionHandleUi->setMinimumSize(QSize(800, 575));
        connectionHandleUi->setMaximumSize(QSize(800, 575));
        layoutWidget = new QWidget(connectionHandleUi);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 20, 781, 541));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(-1, -1, 10, -1);
        fileSelectWdg = new QWidget(layoutWidget);
        fileSelectWdg->setObjectName("fileSelectWdg");
        horizontalLayout_2 = new QHBoxLayout(fileSelectWdg);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, -1, -1, -1);
        btnSelectFile = new QPushButton(fileSelectWdg);
        btnSelectFile->setObjectName("btnSelectFile");

        horizontalLayout_2->addWidget(btnSelectFile);

        lineEditPath = new QLineEdit(fileSelectWdg);
        lineEditPath->setObjectName("lineEditPath");

        horizontalLayout_2->addWidget(lineEditPath);

        btnSendFile = new QPushButton(fileSelectWdg);
        btnSendFile->setObjectName("btnSendFile");

        horizontalLayout_2->addWidget(btnSendFile);


        gridLayout->addWidget(fileSelectWdg, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(-1, -1, 19, -1);
        btnDisconnect = new QPushButton(layoutWidget);
        btnDisconnect->setObjectName("btnDisconnect");

        verticalLayout_4->addWidget(btnDisconnect);


        verticalLayout_2->addLayout(verticalLayout_4);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(-1, -1, 19, -1);
        lblSendingBar = new QProgressBar(layoutWidget);
        lblSendingBar->setObjectName("lblSendingBar");
        lblSendingBar->setValue(0);

        gridLayout_3->addWidget(lblSendingBar, 0, 1, 1, 1);

        lblSending = new QLabel(layoutWidget);
        lblSending->setObjectName("lblSending");

        gridLayout_3->addWidget(lblSending, 0, 0, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        gridLayout_3->addWidget(pushButton, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, -1, 10, 8);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, -1, -1, 25);
        lblOutput = new QLabel(layoutWidget);
        lblOutput->setObjectName("lblOutput");

        verticalLayout_3->addWidget(lblOutput);

        lstOutput = new QListWidget(layoutWidget);
        lstOutput->setObjectName("lstOutput");
        lstOutput->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);

        verticalLayout_3->addWidget(lstOutput);


        verticalLayout->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(connectionHandleUi);

        QMetaObject::connectSlotsByName(connectionHandleUi);
    } // setupUi

    void retranslateUi(QWidget *connectionHandleUi)
    {
        connectionHandleUi->setWindowTitle(QCoreApplication::translate("connectionHandleUi", "Form", nullptr));
        btnSelectFile->setText(QCoreApplication::translate("connectionHandleUi", "Select File", nullptr));
        btnSendFile->setText(QCoreApplication::translate("connectionHandleUi", "Send", nullptr));
        btnDisconnect->setText(QCoreApplication::translate("connectionHandleUi", "Disconnect", nullptr));
        lblSending->setText(QCoreApplication::translate("connectionHandleUi", "Sending File ...", nullptr));
        pushButton->setText(QCoreApplication::translate("connectionHandleUi", "Cancel", nullptr));
        lblOutput->setText(QCoreApplication::translate("connectionHandleUi", "Connection Output", nullptr));
    } // retranslateUi

};

namespace Ui {
    class connectionHandleUi: public Ui_connectionHandleUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONHANDLEUI_H
