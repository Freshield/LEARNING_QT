#include "server.h"
#include "ui_server.h"
#include <QtNetwork>

Server::Server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);


    if(! tcpServer.listen(QHostAddress::LocalHost,2333))
    {
        qDebug() << "1";
        qDebug()<<tcpServer.errorString();
        close();
    }
    connect(&tcpServer,SIGNAL(newConnection()),this,SLOT(acceptedConnection()));
}

Server::~Server()
{
    delete ui;
}

void Server::acceptedConnection()
{
    /*
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out<<(quint16)0;
    out<<tr("hello TCP!!!");
    out.device()->seek(0);
    out<<(quint16)(block.size() - sizeof(quint16));
*/
    blockSize = 0;

    test = tcpServer.nextPendingConnection();
    connect(test,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(test,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));



    //connect(clientConnection,SIGNAL(disconnected()),clientConnection,SLOT(deleteLater()));
   // clientConnection->write(block);
    //clientConnection->disconnectFromHost();

    ui->label->setText("connected");

}

void Server::on_pushButton_clicked()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out<<(quint16)0;
    out<<ui->lineEdit->text();
    out.device()->seek(0);
    out<<(quint16)(block.size() - sizeof(quint16));

    test->write(block);
}


void Server::displayError(QAbstractSocket::SocketError)
{
    qDebug() << test->errorString();
}

void Server::readMessage()
{
    QDataStream in(test);
    in.setVersion(QDataStream::Qt_4_0);

    if(blockSize == 0)
    {
        if(test->bytesAvailable() < (int)sizeof(quint16))
        {
            return;
        }
        in >> blockSize;
    }

    if(test->bytesAvailable() < blockSize)
    {
        return;
    }

    in >> message;

    ui->label->setText(message);

    blockSize = 0;


}
