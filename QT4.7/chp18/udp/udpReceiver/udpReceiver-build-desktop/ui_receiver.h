/********************************************************************************
** Form generated from reading UI file 'receiver.ui'
**
** Created: Thu Dec 3 21:16:25 2015
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVER_H
#define UI_RECEIVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Receiver
{
public:
    QLabel *label;

    void setupUi(QDialog *Receiver)
    {
        if (Receiver->objectName().isEmpty())
            Receiver->setObjectName(QString::fromUtf8("Receiver"));
        Receiver->resize(827, 580);
        label = new QLabel(Receiver);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 50, 401, 171));

        retranslateUi(Receiver);

        QMetaObject::connectSlotsByName(Receiver);
    } // setupUi

    void retranslateUi(QDialog *Receiver)
    {
        Receiver->setWindowTitle(QApplication::translate("Receiver", "Receiver", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Receiver", "WAITTING!!!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Receiver: public Ui_Receiver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVER_H
