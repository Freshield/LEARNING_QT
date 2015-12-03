/********************************************************************************
** Form generated from reading UI file 'hellodialog.ui'
**
** Created: Wed Dec 2 17:48:54 2015
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLODIALOG_H
#define UI_HELLODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_HelloDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *HelloDialog)
    {
        if (HelloDialog->objectName().isEmpty())
            HelloDialog->setObjectName(QString::fromUtf8("HelloDialog"));
        HelloDialog->resize(1107, 756);
        label = new QLabel(HelloDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 210, 541, 241));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Sunken);
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(HelloDialog);

        QMetaObject::connectSlotsByName(HelloDialog);
    } // setupUi

    void retranslateUi(QDialog *HelloDialog)
    {
        HelloDialog->setWindowTitle(QApplication::translate("HelloDialog", "HelloDialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HelloDialog", "HELLO WORLD!!!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HelloDialog: public Ui_HelloDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLODIALOG_H
