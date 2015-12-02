/********************************************************************************
** Form generated from reading UI file 'demo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMO_H
#define UI_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DEMO
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DEMO)
    {
        if (DEMO->objectName().isEmpty())
            DEMO->setObjectName(QStringLiteral("DEMO"));
        DEMO->resize(819, 614);
        centralWidget = new QWidget(DEMO);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 30, 621, 51));
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 100, 621, 51));
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 170, 621, 51));
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 240, 621, 51));
        label_4->setFrameShape(QFrame::Panel);
        label_4->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 310, 621, 51));
        label_5->setFrameShape(QFrame::Panel);
        label_5->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(80, 380, 621, 51));
        label_6->setFrameShape(QFrame::Panel);
        label_6->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 450, 291, 71));
        DEMO->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DEMO);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 819, 30));
        DEMO->setMenuBar(menuBar);
        statusBar = new QStatusBar(DEMO);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DEMO->setStatusBar(statusBar);

        retranslateUi(DEMO);

        QMetaObject::connectSlotsByName(DEMO);
    } // setupUi

    void retranslateUi(QMainWindow *DEMO)
    {
        DEMO->setWindowTitle(QApplication::translate("DEMO", "DEMO", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        pushButton->setText(QApplication::translate("DEMO", "QUIT", 0));
    } // retranslateUi

};

namespace Ui {
    class DEMO: public Ui_DEMO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMO_H
