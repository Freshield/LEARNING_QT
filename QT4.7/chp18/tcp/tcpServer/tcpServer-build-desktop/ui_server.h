/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created: Fri Dec 4 21:18:17 2015
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_3;
    QLineEdit *PortLineEdit;
    QPushButton *setButton;
    QListWidget *listWidget;

    void setupUi(QDialog *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QString::fromUtf8("Server"));
        Server->resize(857, 685);
        label = new QLabel(Server);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 440, 341, 191));
        lineEdit = new QLineEdit(Server);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(400, 440, 421, 71));
        pushButton = new QPushButton(Server);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(610, 570, 187, 57));
        label_3 = new QLabel(Server);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 60, 116, 34));
        PortLineEdit = new QLineEdit(Server);
        PortLineEdit->setObjectName(QString::fromUtf8("PortLineEdit"));
        PortLineEdit->setGeometry(QRect(170, 50, 431, 51));
        setButton = new QPushButton(Server);
        setButton->setObjectName(QString::fromUtf8("setButton"));
        setButton->setGeometry(QRect(640, 50, 187, 57));
        listWidget = new QListWidget(Server);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(90, 150, 671, 251));

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QDialog *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Server", "WAITING!!!", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("Server", "hello", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Server", "send", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Server", "port:", 0, QApplication::UnicodeUTF8));
        PortLineEdit->setText(QApplication::translate("Server", "2333", 0, QApplication::UnicodeUTF8));
        setButton->setText(QApplication::translate("Server", "set", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
