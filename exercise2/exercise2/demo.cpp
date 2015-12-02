#include "demo.h"
#include "ui_demo.h"

DEMO::DEMO(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DEMO)
{
    ui->setupUi(this);
    QString str1 = "WELCOME";
    ui->label->setText(str1);
    str1 = str1+" TO YOU!";
    ui->label_2->setText(str1);
    QString str2 = "HELLO";
    ui->label_3->setText(str2);
    str2 += " WORLD!";
    ui->label_4->setText(str2);
    str2.append("23333");
    ui->label_5->setText(str2);

    QString str;
    str = QString("%1 was born in %2").arg("JOHN").arg(1982);
    ui->label_6->setText(str);




}

DEMO::~DEMO()
{
    delete ui;
}
