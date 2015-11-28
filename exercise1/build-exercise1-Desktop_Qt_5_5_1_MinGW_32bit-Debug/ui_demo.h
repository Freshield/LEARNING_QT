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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DEMO
{
public:
    QWidget *centralWidget;
    QLabel *areaLabel_1;
    QLabel *areaLabel_2;
    QLabel *radiusLabel;
    QLineEdit *radiusLineEdit;
    QPushButton *countBtm;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DEMO)
    {
        if (DEMO->objectName().isEmpty())
            DEMO->setObjectName(QStringLiteral("DEMO"));
        DEMO->resize(670, 289);
        centralWidget = new QWidget(DEMO);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        areaLabel_1 = new QLabel(centralWidget);
        areaLabel_1->setObjectName(QStringLiteral("areaLabel_1"));
        areaLabel_1->setGeometry(QRect(40, 60, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\273\277\345\256\213"));
        font.setPointSize(16);
        areaLabel_1->setFont(font);
        areaLabel_2 = new QLabel(centralWidget);
        areaLabel_2->setObjectName(QStringLiteral("areaLabel_2"));
        areaLabel_2->setGeometry(QRect(360, 60, 91, 31));
        areaLabel_2->setFont(font);
        radiusLabel = new QLabel(centralWidget);
        radiusLabel->setObjectName(QStringLiteral("radiusLabel"));
        radiusLabel->setGeometry(QRect(460, 60, 151, 41));
        QFont font1;
        font1.setPointSize(16);
        radiusLabel->setFont(font1);
        radiusLabel->setFrameShape(QFrame::Panel);
        radiusLabel->setFrameShadow(QFrame::Sunken);
        radiusLineEdit = new QLineEdit(centralWidget);
        radiusLineEdit->setObjectName(QStringLiteral("radiusLineEdit"));
        radiusLineEdit->setGeometry(QRect(160, 60, 141, 41));
        radiusLineEdit->setFont(font1);
        countBtm = new QPushButton(centralWidget);
        countBtm->setObjectName(QStringLiteral("countBtm"));
        countBtm->setGeometry(QRect(460, 150, 141, 51));
        countBtm->setFont(font);
        countBtm->setAutoDefault(false);
        countBtm->setFlat(false);
        DEMO->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DEMO);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 670, 30));
        DEMO->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DEMO);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DEMO->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DEMO);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DEMO->setStatusBar(statusBar);

        retranslateUi(DEMO);

        countBtm->setDefault(false);


        QMetaObject::connectSlotsByName(DEMO);
    } // setupUi

    void retranslateUi(QMainWindow *DEMO)
    {
        DEMO->setWindowTitle(QApplication::translate("DEMO", "DEMO", 0));
        areaLabel_1->setText(QApplication::translate("DEMO", "\345\215\212\345\276\204\357\274\232", 0));
        areaLabel_2->setText(QApplication::translate("DEMO", "\351\235\242\347\247\257\357\274\232", 0));
        radiusLabel->setText(QString());
        countBtm->setText(QApplication::translate("DEMO", "\350\256\241\347\256\227", 0));
    } // retranslateUi

};

namespace Ui {
    class DEMO: public Ui_DEMO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMO_H
