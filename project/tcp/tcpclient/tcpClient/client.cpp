#include "client.h"
#include "ui_client.h"

#include <QtNetwork>
#include <QMessageBox>
#include "submitdialog.h"
#include "seeallbiddialog.h"
#include "biditemdialog.h"

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    uidnum = "NULL";
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));

    connect(tcpSocket,SIGNAL(connected()),this,SLOT(ifconnected()));
}

Client::~Client()
{
    delete ui;
}

void Client::newConnect()
{
    blockSize = 0;

    tcpSocket->abort();
    tcpSocket->connectToHost(ui->hostLineEdit->text(),ui->portLineEdit->text().toInt());

}

void Client::readMessage()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    if(blockSize == 0)
    {
        if(tcpSocket->bytesAvailable() < (int)sizeof(quint16))
        {
            return;
        }
        in >> blockSize;
    }

    if(tcpSocket->bytesAvailable() < blockSize)
    {
        return;
    }

    in >> message;

    //--------------------------------------------------------------//
    //----------------FIGURE OUT THE MESSAGE------------------------//
    //--------------------------------------------------------------//
    //first connect
    if(message[0] == '0' && message[1] == '-')
    {
        int place = message.indexOf("<uidnum>");
        QString getter = message.mid(place+8,message.size()-place-8);
        uidnum = getter;
        ui->uidnum_label->setText(getter);
    }
    else if(message == tr("SERVER SEND:YOUR REGISTED SUCCESS"))
    {
        name = ui->sendLineEdit->text();
        ui->sendLineEdit->setText("");
        ui->sendLineEdit->setEnabled(false);
        ui->regist_pushButton->setEnabled(false);
        ui->bid_pushButton->setEnabled(true);
        ui->see_all_bid_pushButton->setEnabled(true);
        ui->see_all_your_bid_pushButton->setEnabled(true);
        ui->submit_pushButton->setEnabled(true);
        ui->deregist_pushButton->setEnabled(true);
        ui->withdraw_pushButton->setEnabled(true);
        ui->see_all_your_item_pushButton->setEnabled(true);
        ui->namelabel->setText(name);

        ui->messageLabel->setText(message+tr("\n")+tr("Now you can try to play the game"));

    }
    //see all bid
    else if(message.contains("SERVER SEND:ALL BID IS BELOW\n"))
    {
        SeeAllBidDialog *newseeallbid = new SeeAllBidDialog(this,message);
        newseeallbid->show();
        ui->messageLabel->setText("SERVER SEND:ALL BID IS BELOW");

    }
    //want a bid
    else if(message.contains("SERVER SEND:ALL ITEM YOU CAN BID IS BELOW\n"))
    {
        BidItemDialog *newbiditem = new BidItemDialog(this,message,uidnum);
        connect(newbiditem,SIGNAL(biditemsinfo(QString,QString)),this,SLOT(getbiditem(QString,QString)),Qt::QueuedConnection);
        newbiditem->show();
        ui->messageLabel->setText("SERVER SEND:GET BID ITEM");
    }
    //see client's bid
    else if(message.contains("SERVER SEND:ALL ITEM YOUR BID IS BELOW\n"))
    {
        SeeAllBidDialog *newseeallbid = new SeeAllBidDialog(this,message);
        newseeallbid->show();
        ui->messageLabel->setText("SERVER SEND:ALL BID IS BELOW");

    }
    //see client's item
    else if(message.contains("SERVER SEND:ALL ITEM BELONG TO YOU IS BELOW\n"))
    {
        SeeAllBidDialog *newseeallbid = new SeeAllBidDialog(this,message);
        newseeallbid->show();
        ui->messageLabel->setText("SERVER SEND:ALL ITEM IS BELOW");

    }
    else
    {
        ui->messageLabel->setText(message);
    }

    blockSize = 0;


}

void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString();
}









void Client::on_connectButton_clicked()
{
    newConnect();
}

void Client::on_pushButton_clicked()
{

    QByteArray block = pickup_data(ui->sendLineEdit->text());
    tcpSocket->write(block);
}

void Client::ifconnected()
{
    QMessageBox::information(this,tr("Connected"),tr("Connected successed"));
    ui->connectButton->setEnabled(false);
    ui->hostLineEdit->setEnabled(false);
    ui->portLineEdit->setEnabled(false);
    ui->regist_pushButton->setEnabled(true);
    ui->sendLineEdit->setEnabled(true);
    ui->messageLabel->setText(tr("Connect success,\nthen entre your name \nand press regist to regist first"));
    return;
}

QString Client::format_message(QString header, QString data)
{

    QString message ="CLIENT UID "+uidnum+" send: "+"<uidnum>"+uidnum+"</uidnu>"+"<header>"+header+"</heade>"+"<messag>"+data+"</messa>";
    return message;
}

void Client::on_regist_pushButton_clicked()
{
    if(ui->sendLineEdit->text() == tr(""))
    {
        QMessageBox::warning(this,tr("Regist"),tr("Name can not be empty"));
        return;
    }
    else
    {
        QString message = format_message("0",ui->sendLineEdit->text());
        QByteArray block = pickup_data(message);
        tcpSocket->write(block);
    }


}


QByteArray Client::pickup_data(QString data)
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out<<(quint16)0;
    out<<data;//here is the true string data
    out.device()->seek(0);
    out<<(quint16)(block.size() - sizeof(quint16));

    return block;
}


void Client::on_see_all_bid_pushButton_clicked()
{
    QString message = format_message("1",tr("I WANT TO SEE ALL BID"));
    QByteArray block = pickup_data(message);
    tcpSocket->write(block);
}

void Client::on_submit_pushButton_clicked()
{
    SubmitDialog *newsubmit = new SubmitDialog(this);
    connect(newsubmit,SIGNAL(CallMainWindowItemName(QString)),this,SLOT(submititems(QString)));
    newsubmit->show();
}

void Client::submititems(QString itemname)
{
    QString message = format_message("2",itemname);
    QByteArray block = pickup_data(message);
    tcpSocket->write(block);
    ui->messageLabel->setText(tr("SUBMIT AN ITEM\nNAME IS")+itemname);
}

void Client::on_bid_pushButton_clicked()
{
    QString message = format_message("3",tr("I WANT TO BID AN ITEM"));
    QByteArray block = pickup_data(message);
    tcpSocket->write(block);
}


void Client::getbiditem(QString itemscode, QString itemprice)
{
    //ui->messageLabel->setText(itemscode+itemprice);

    QString messagetemp = tr("<itecod>")+itemscode+tr("</iteco>")+tr("<itepri>")+itemprice+tr("</itepr>");
    QString message = format_message("31",messagetemp);
    QByteArray block = pickup_data(message);
    tcpSocket->write(block);

}

void Client::on_see_all_your_bid_pushButton_clicked()
{
    QString message = format_message("4",tr("I WANT TO SEE ALL MY BID"));
    QByteArray block = pickup_data(message);
    tcpSocket->write(block);
}

void Client::on_withdraw_pushButton_clicked()
{

}

void Client::on_see_all_your_item_pushButton_clicked()
{
    QString message = format_message("5",tr("I WANT TO SEE ALL MY SALE"));
    QByteArray block = pickup_data(message);
    tcpSocket->write(block);
}
