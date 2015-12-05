#include "client.h"
#include "ui_client.h"

#include <QtNetwork>
#include <QMessageBox>

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
        ui->uidnum_label->setText(getter);
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
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out<<(quint16)0;
    out<<ui->sendLineEdit->text();
    out.device()->seek(0);
    out<<(quint16)(block.size() - sizeof(quint16));

    tcpSocket->write(block);
}

void Client::ifconnected()
{
    QMessageBox::information(this,tr("Connected"),tr("Connected successed"));
    ui->connectButton->setEnabled(false);
    return;
}
