/********************************************************************************
** Form generated from reading UI file 'dialogsrv.ui'
**
** Created: Thu Dec 3 12:08:24 2015
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSRV_H
#define UI_DIALOGSRV_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSrv
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditPort;
    QPushButton *pushButtonListen;
    QPushButton *pushButtonStop;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QPushButton *pushButtonSend;
    QLabel *label_2;

    void setupUi(QDialog *DialogSrv)
    {
        if (DialogSrv->objectName().isEmpty())
            DialogSrv->setObjectName(QString::fromUtf8("DialogSrv"));
        DialogSrv->resize(739, 379);
        layoutWidget = new QWidget(DialogSrv);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 622, 294));
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

        lineEditPort = new QLineEdit(layoutWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        horizontalLayout->addWidget(lineEditPort);

        pushButtonListen = new QPushButton(layoutWidget);
        pushButtonListen->setObjectName(QString::fromUtf8("pushButtonListen"));

        horizontalLayout->addWidget(pushButtonListen);

        pushButtonStop = new QPushButton(layoutWidget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));

        horizontalLayout->addWidget(pushButtonStop);


        mainLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout_2->addWidget(listWidget);

        pushButtonSend = new QPushButton(layoutWidget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));

        horizontalLayout_2->addWidget(pushButtonSend);


        mainLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        mainLayout->addWidget(label_2);


        retranslateUi(DialogSrv);

        QMetaObject::connectSlotsByName(DialogSrv);
    } // setupUi

    void retranslateUi(QDialog *DialogSrv)
    {
        DialogSrv->setWindowTitle(QApplication::translate("DialogSrv", "DialogSrv", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogSrv", "\347\233\221\345\220\254\347\253\257\345\217\243", 0, QApplication::UnicodeUTF8));
        pushButtonListen->setText(QApplication::translate("DialogSrv", "\345\274\200\345\220\257\347\233\221\345\220\254", 0, QApplication::UnicodeUTF8));
        pushButtonStop->setText(QApplication::translate("DialogSrv", "\345\201\234\346\255\242\347\233\221\345\220\254", 0, QApplication::UnicodeUTF8));
        pushButtonSend->setText(QApplication::translate("DialogSrv", "\345\217\221\345\214\205\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogSrv", "\347\255\211\345\276\205\345\256\242\346\210\267\350\277\236\350\277\233\346\235\245\344\271\213\345\220\216\357\274\214\344\273\216\345\267\246\350\276\271\351\200\211\344\270\200\344\270\252\345\201\232\345\217\221\345\214\205\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogSrv: public Ui_DialogSrv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSRV_H
