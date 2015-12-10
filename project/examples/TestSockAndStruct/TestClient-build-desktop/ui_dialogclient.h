/********************************************************************************
** Form generated from reading UI file 'dialogclient.ui'
**
** Created: Thu Dec 3 12:10:23 2015
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCLIENT_H
#define UI_DIALOGCLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogClient
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditIP;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QPushButton *pushButtonConnect;
    QLabel *label_3;
    QLabel *labelShow;

    void setupUi(QDialog *DialogClient)
    {
        if (DialogClient->objectName().isEmpty())
            DialogClient->setObjectName(QString::fromUtf8("DialogClient"));
        DialogClient->resize(694, 347);
        layoutWidget = new QWidget(DialogClient);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 613, 195));
        mainLayout = new QVBoxLayout(layoutWidget);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(6, 6, 6, 6);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditIP = new QLineEdit(layoutWidget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));

        horizontalLayout->addWidget(lineEditIP);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditPort = new QLineEdit(layoutWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        horizontalLayout->addWidget(lineEditPort);

        pushButtonConnect = new QPushButton(layoutWidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));

        horizontalLayout->addWidget(pushButtonConnect);


        mainLayout->addLayout(horizontalLayout);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 12));

        mainLayout->addWidget(label_3);

        labelShow = new QLabel(layoutWidget);
        labelShow->setObjectName(QString::fromUtf8("labelShow"));
        labelShow->setMinimumSize(QSize(0, 80));

        mainLayout->addWidget(labelShow);

        layoutWidget->raise();
        labelShow->raise();

        retranslateUi(DialogClient);

        QMetaObject::connectSlotsByName(DialogClient);
    } // setupUi

    void retranslateUi(QDialog *DialogClient)
    {
        DialogClient->setWindowTitle(QApplication::translate("DialogClient", "DialogClient", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogClient", "IP", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogClient", "Port", 0, QApplication::UnicodeUTF8));
        pushButtonConnect->setText(QApplication::translate("DialogClient", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogClient", "\346\230\276\347\244\272\346\216\245\346\224\266\347\232\204\347\273\223\346\236\204\344\275\223\357\274\232", 0, QApplication::UnicodeUTF8));
        labelShow->setText(QApplication::translate("DialogClient", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogClient: public Ui_DialogClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCLIENT_H
