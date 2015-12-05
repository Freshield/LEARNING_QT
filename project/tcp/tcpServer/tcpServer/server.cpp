#include "server.h"
#include "ui_server.h"
#include <QtNetwork>
#include <QMessageBox>
#include <QHostAddress>
#include <QByteArray>
#include <QDebug>
#include "clientjobs.h"


Server::Server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    m_server = new QTcpServer(this);
    //connect signal and slots
    connect(m_server,SIGNAL(newConnection()),this,SLOT(onNewConnection()));


}

Server::~Server()
{
    delete m_server;
    m_server = NULL;
    delete ui;
}
/*
void Server::acceptedConnection()
{

    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out<<(quint16)0;
    out<<tr("hello TCP!!!");
    out.device()->seek(0);
    out<<(quint16)(block.size() - sizeof(quint16));

    blockSize = 0;

    test = tcpServer.nextPendingConnection();
    connect(test,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(test,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));



    //connect(clientConnection,SIGNAL(disconnected()),clientConnection,SLOT(deleteLater()));
   // clientConnection->write(block);
    //clientConnection->disconnectFromHost();

    ui->label->setText("connected");

}
*/
void Server::on_pushButton_clicked()
{
    //find if there have client
    if(m_ClientList.count()<1)
    {
        return;
    }
    //figure out which client
    int m_Index = ui->listWidget->currentRow();
    if(m_Index<0)
    {
        return;
    }

    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out<<(quint16)0;
    out<<ui->lineEdit->text();
    out.device()->seek(0);
    out<<(quint16)(block.size() - sizeof(quint16));

    m_ClientList[m_Index]->SendBytes(block);
}

void Server::readMessage(QString strIPandPort,QString data)
{


    ui->label->setText(strIPandPort+data);


}
void Server::on_setButton_clicked()
{
    //if it is listening
    if(m_server->isListening())
    {
        return;
    }
    int portnum = ui->PortLineEdit->text().toInt();
    bool listenreturn = m_server->listen(QHostAddress::Any, portnum);
    //find if listen is successing
    if(listenreturn)
    {
        QMessageBox::information(this,tr("Listen"),tr("Listen successed"));
        return;
    }
    else
    {
        QMessageBox::warning(this,tr("Listen"),tr("Listen failed"));
        return;
    }

}

void Server::onNewConnection()
{
    //find new connection socket
    QTcpSocket *socknewer = m_server->nextPendingConnection();
    //get IP PORT
    QString strIPandPort = socknewer->peerAddress().toString()+tr("_%1").arg(socknewer->peerPort());
    m_IPandPortList.append(strIPandPort);
    //show in list
    ui->listWidget->addItem(strIPandPort);
    //begin constract new client
    clientjobs *newClientJobs = new clientjobs(this,socknewer,strIPandPort);
    //push in client list
    m_ClientList.append(newClientJobs);

    connect(newClientJobs,SIGNAL(CallMainWindowDeleteClient(QString)),this,SLOT(DeleteOneClient(QString)));

    connect(newClientJobs,SIGNAL(CallMainWindowReadData(QString,QString)),this,SLOT(readMessage(QString,QString)));

}

void Server::DeleteOneClient(QString strIPandPort)
{
    int m_Index = m_IPandPortList.indexOf(strIPandPort);
    if(m_Index<0)
    {
        return;
    }
    ui->listWidget->takeItem(m_Index);
    m_IPandPortList.removeAt(m_Index);
    m_ClientList.removeAt(m_Index);
}
