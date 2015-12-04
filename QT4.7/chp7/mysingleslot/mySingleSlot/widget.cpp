#include "widget.h"
#include "ui_widget.h"
#include "mydialog.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<1;
    MyDialog *dlg = new MyDialog(this);
    qDebug()<<2;
    connect(dlg,SIGNAL(dlgReturn(int)),this,SLOT(showValue(int)));
    qDebug()<<3;
    dlg->show();
    qDebug()<<4;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::showValue(int value)
{

    qDebug()<<5;
    ui->label->setText(tr("value is:%1").arg(value));
}
