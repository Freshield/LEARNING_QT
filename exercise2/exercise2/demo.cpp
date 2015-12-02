#include "demo.h"
#include "ui_demo.h"
#include <QDebug>

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

    str.insert(4,"23333");
    ui->label_6->setText(str);

    str = " WELCOME \t TO \n YOU! ";
    ui->label->setText(str);
    str = str.simplified();
    ui->label_2->setText(str);

    str.startsWith("WELCOME",Qt::CaseSensitive);
    str.startsWith("you",Qt::CaseSensitive);
    str.contains("WELCOME",Qt::CaseSensitive);
    str = "125";
    bool ok;
    int hex = str.toInt(&ok,16);
    QString temp = QString("%1").arg(hex);
    ui->label_3->setText(temp);
    int dec = str.toInt(&ok,10);
    temp = QString("%1").arg(dec);
    ui->label_4->setText(temp);

    str = "WELCOME TO YOUR";
    qDebug()<<str;
    QByteArray ba = str.toUtf8();
    qDebug()<<ba.data();
    ba.append("HELLO,WORLD");
    qDebug()<<ba.data();
    qDebug()<<QString().isNull();
    qDebug()<<QString().isEmpty();
    qDebug()<<QString("").isNull();
    qDebug()<<QString("").isEmpty();

    QList<QString>list;
    {
        QString strt("TEST");
        list<<strt;
    }
    qDebug()<<list[0]<<"how are you";

    QMap<QString,QString>map;
    {
        map.insert("beijing","111");
        map.insert("shanghai","021");
        map.insert("nanjing","025");
        QMapIterator<QString,QString>i(map);
        for(;i.hasNext();)
        {
            qDebug()<<""<<i.key()<<""<<i.next().value();

        }
        QMutableMapIterator<QString,QString>mi(map);
        if(mi.findNext("111"))
        {
            mi.setValue("010");
        }
        QMapIterator<QString,QString>modi(map);
        qDebug()<<"";
        for(;modi.hasNext();)
        {
            qDebug()<<""<<modi.key()<<""<<modi.next().value();
        }
    }







}

DEMO::~DEMO()
{
    delete ui;
}
