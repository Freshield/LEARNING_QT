/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created: Sat Dec 5 14:45:07 2015
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
    QLabel *label_4;
    QLabel *uidnum_label;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(1017, 811);
        label = new QLabel(Client);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 130, 116, 34));
        label_2 = new QLabel(Client);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 200, 116, 34));
        messageLabel = new QLabel(Client);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setGeometry(QRect(50, 480, 621, 151));
        connectButton = new QPushButton(Client);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(660, 280, 187, 57));
        hostLineEdit = new QLineEdit(Client);
        hostLineEdit->setObjectName(QString::fromUtf8("hostLineEdit"));
        hostLineEdit->setGeometry(QRect(240, 110, 491, 51));
        portLineEdit = new QLineEdit(Client);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        portLineEdit->setGeometry(QRect(240, 200, 491, 51));
        pushButton = new QPushButton(Client);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(670, 570, 187, 57));
        sendLineEdit = new QLineEdit(Client);
        sendLineEdit->setObjectName(QString::fromUtf8("sendLineEdit"));
        sendLineEdit->setGeometry(QRect(240, 400, 471, 51));
        label_3 = new QLabel(Client);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 410, 116, 34));
        label_4 = new QLabel(Client);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 10, 61, 31));
        uidnum_label = new QLabel(Client);
        uidnum_label->setObjectName(QString::fromUtf8("uidnum_label"));
        uidnum_label->setGeometry(QRect(90, 10, 116, 34));

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
        label_4->setText(QApplication::translate("Client", "uid:", 0, QApplication::UnicodeUTF8));
        uidnum_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
