/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created: Fri Dec 4 16:37:28 2015
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
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QString::fromUtf8("Server"));
        Server->resize(701, 553);
        label = new QLabel(Server);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 150, 341, 191));
        lineEdit = new QLineEdit(Server);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 100, 421, 71));
        pushButton = new QPushButton(Server);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(450, 380, 187, 57));

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QDialog *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Server", "WAITING!!!", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("Server", "hello", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Server", "send", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
