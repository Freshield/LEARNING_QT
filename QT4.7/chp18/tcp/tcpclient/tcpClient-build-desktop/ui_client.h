/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created: Fri Dec 4 16:38:50 2015
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *messageLabel;
    QPushButton *connectButton;
    QLineEdit *hostLineEdit;
    QLineEdit *portLineEdit;
    QPushButton *pushButton;
    QLineEdit *sendLineEdit;
    QLabel *label_3;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(871, 614);
        label = new QLabel(Client);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 50, 116, 34));
        label_2 = new QLabel(Client);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 120, 116, 34));
        messageLabel = new QLabel(Client);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setGeometry(QRect(90, 430, 441, 61));
        connectButton = new QPushButton(Client);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(640, 200, 187, 57));
        hostLineEdit = new QLineEdit(Client);
        hostLineEdit->setObjectName(QString::fromUtf8("hostLineEdit"));
        hostLineEdit->setGeometry(QRect(220, 30, 491, 51));
        portLineEdit = new QLineEdit(Client);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        portLineEdit->setGeometry(QRect(220, 120, 491, 51));
        pushButton = new QPushButton(Client);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(650, 490, 187, 57));
        sendLineEdit = new QLineEdit(Client);
        sendLineEdit->setObjectName(QString::fromUtf8("sendLineEdit"));
        sendLineEdit->setGeometry(QRect(220, 320, 471, 51));
        label_3 = new QLabel(Client);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 330, 116, 34));

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Client", "host:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Client", "port:", 0, QApplication::UnicodeUTF8));
        messageLabel->setText(QApplication::translate("Client", "message is:", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("Client", "connect", 0, QApplication::UnicodeUTF8));
        hostLineEdit->setText(QApplication::translate("Client", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        portLineEdit->setText(QApplication::translate("Client", "2333", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Client", "send", 0, QApplication::UnicodeUTF8));
        sendLineEdit->setText(QApplication::translate("Client", "hi", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Client", "send:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
