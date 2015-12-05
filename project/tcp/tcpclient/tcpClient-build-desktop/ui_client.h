/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created: Sat Dec 5 16:55:08 2015
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
    QPushButton *regist_pushButton;
    QPushButton *see_all_bid_pushButton;
    QPushButton *submit_pushButton;
    QPushButton *bid_pushButton;
    QPushButton *see_all_your_bid_pushButton;
    QPushButton *deregist_pushButton;
    QPushButton *withdraw_pushButton;
    QLabel *label_5;
    QLabel *namelabel;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(1027, 818);
        label = new QLabel(Client);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 90, 116, 34));
        label_2 = new QLabel(Client);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 160, 116, 34));
        messageLabel = new QLabel(Client);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setGeometry(QRect(20, 240, 751, 441));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        messageLabel->setFont(font);
        messageLabel->setFrameShape(QFrame::Panel);
        messageLabel->setFrameShadow(QFrame::Sunken);
        messageLabel->setWordWrap(true);
        connectButton = new QPushButton(Client);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(800, 60, 191, 61));
        hostLineEdit = new QLineEdit(Client);
        hostLineEdit->setObjectName(QString::fromUtf8("hostLineEdit"));
        hostLineEdit->setGeometry(QRect(240, 70, 491, 51));
        portLineEdit = new QLineEdit(Client);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        portLineEdit->setGeometry(QRect(240, 160, 491, 51));
        pushButton = new QPushButton(Client);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(800, 720, 201, 61));
        sendLineEdit = new QLineEdit(Client);
        sendLineEdit->setObjectName(QString::fromUtf8("sendLineEdit"));
        sendLineEdit->setEnabled(false);
        sendLineEdit->setGeometry(QRect(240, 710, 471, 51));
        label_3 = new QLabel(Client);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 720, 116, 34));
        label_4 = new QLabel(Client);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 10, 61, 31));
        uidnum_label = new QLabel(Client);
        uidnum_label->setObjectName(QString::fromUtf8("uidnum_label"));
        uidnum_label->setGeometry(QRect(90, 10, 116, 34));
        regist_pushButton = new QPushButton(Client);
        regist_pushButton->setObjectName(QString::fromUtf8("regist_pushButton"));
        regist_pushButton->setEnabled(false);
        regist_pushButton->setGeometry(QRect(796, 240, 201, 61));
        see_all_bid_pushButton = new QPushButton(Client);
        see_all_bid_pushButton->setObjectName(QString::fromUtf8("see_all_bid_pushButton"));
        see_all_bid_pushButton->setEnabled(false);
        see_all_bid_pushButton->setGeometry(QRect(796, 310, 201, 61));
        submit_pushButton = new QPushButton(Client);
        submit_pushButton->setObjectName(QString::fromUtf8("submit_pushButton"));
        submit_pushButton->setEnabled(false);
        submit_pushButton->setGeometry(QRect(796, 380, 201, 61));
        bid_pushButton = new QPushButton(Client);
        bid_pushButton->setObjectName(QString::fromUtf8("bid_pushButton"));
        bid_pushButton->setEnabled(false);
        bid_pushButton->setGeometry(QRect(800, 450, 201, 61));
        see_all_your_bid_pushButton = new QPushButton(Client);
        see_all_your_bid_pushButton->setObjectName(QString::fromUtf8("see_all_your_bid_pushButton"));
        see_all_your_bid_pushButton->setEnabled(false);
        see_all_your_bid_pushButton->setGeometry(QRect(800, 520, 201, 61));
        deregist_pushButton = new QPushButton(Client);
        deregist_pushButton->setObjectName(QString::fromUtf8("deregist_pushButton"));
        deregist_pushButton->setEnabled(false);
        deregist_pushButton->setGeometry(QRect(800, 590, 201, 61));
        withdraw_pushButton = new QPushButton(Client);
        withdraw_pushButton->setObjectName(QString::fromUtf8("withdraw_pushButton"));
        withdraw_pushButton->setEnabled(false);
        withdraw_pushButton->setGeometry(QRect(800, 650, 201, 61));
        label_5 = new QLabel(Client);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 50, 116, 34));
        namelabel = new QLabel(Client);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(100, 50, 116, 34));

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Client", "host:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Client", "port:", 0, QApplication::UnicodeUTF8));
        messageLabel->setText(QApplication::translate("Client", "Welcome to the bid system\n"
"\n"
"write host address\n"
"and the port number\n"
"then press connect button\n"
"to connect to the server", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("Client", "connect", 0, QApplication::UnicodeUTF8));
        hostLineEdit->setText(QApplication::translate("Client", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        portLineEdit->setText(QApplication::translate("Client", "2333", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Client", "send", 0, QApplication::UnicodeUTF8));
        sendLineEdit->setText(QString());
        label_3->setText(QApplication::translate("Client", "send:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Client", "uid:", 0, QApplication::UnicodeUTF8));
        uidnum_label->setText(QString());
        regist_pushButton->setText(QApplication::translate("Client", "regist", 0, QApplication::UnicodeUTF8));
        see_all_bid_pushButton->setText(QApplication::translate("Client", "see all bid", 0, QApplication::UnicodeUTF8));
        submit_pushButton->setText(QApplication::translate("Client", "submit an item", 0, QApplication::UnicodeUTF8));
        bid_pushButton->setText(QApplication::translate("Client", "bid an item", 0, QApplication::UnicodeUTF8));
        see_all_your_bid_pushButton->setText(QApplication::translate("Client", "see all your bid", 0, QApplication::UnicodeUTF8));
        deregist_pushButton->setText(QApplication::translate("Client", "deregist", 0, QApplication::UnicodeUTF8));
        withdraw_pushButton->setText(QApplication::translate("Client", "withdraw item", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Client", "name:", 0, QApplication::UnicodeUTF8));
        namelabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
