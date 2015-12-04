#include "server.h"
#include "ui_server.h"
#include <QtNetwork>

Server::Server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    if(!tcpServer->listen(QHostAddress::LocalHost,2333))
    {
        qDebug()<<tcpServer->errorString();
        close();
    }
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));
}

Server::~Server()
{
    delete ui;
}

void Server::sendMessage()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out<<(quint16)0;
    out<<tr("hello TCP!!!");
    out.device()->seek(0);
    out<<(quint16)(block.size() - sizeof(quint16));

    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection,SIGNAL(disconnected()),clientConnection,SLOT(deleteLater()));
    clientConnection->write(block);
    clientConnection->disconnectFromHost();

    ui->label->setText("send message successful!!!");








}
