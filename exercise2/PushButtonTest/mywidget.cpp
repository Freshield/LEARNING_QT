#include "mywidget.h"
#include <qapplication.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qdatetime.h>
#include <qfont.h>
#include <qtimer.h>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(200,120);
    setMaximumSize(200,120);

    QPushButton *quit = new QPushButton("QUIT",this);
    quit->setGeometry(62,40,75,30);
    quit->setFont(QFont("Times",18,QFont::Bold));

    connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
    QLabel *datalabel = new QLabel();

    QDateTime *datatime = new QDateTime(QDateTime::currentDateTime());
    datalabel->setText(datatime->date().toString());
    datalabel->show();

    QTimer *time_clock = new QTimer(parent);
    connect(time_clock,SIGNAL(timeout()),this,SLOT(showFullScreen()));
    time_clock->start(2000);


}

MyWidget::~MyWidget()
{

}
