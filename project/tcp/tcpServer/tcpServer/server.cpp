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
    UID_NUM = 100;
    //create new server

    m_server = new QTcpServer(this);
    //connect signal and slots
    connect(m_server,SIGNAL(newConnection()),this,SLOT(onNewConnection()));//new connect


}

Server::~Server()
{
    delete m_server;
    m_server = NULL;
    delete ui;
}
//send slot
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
    //process the block

    QByteArray block = pickup_data(ui->lineEdit->text());
    //send block

    m_ClientList[m_Index]->SendBytes(block);
}
//read slot
void Server::readMessage(QString strIPandPort,QString data)
{


    ui->label->setText(strIPandPort+":"+data);


}
//set port number slot
void Server::on_setButton_clicked()
{
    //if it is listening
    if(m_server->isListening())
    {
        return;
    }
    //if not
    int portnum = ui->PortLineEdit->text().toInt();
    bool listenreturn = m_server->listen(QHostAddress::Any, portnum);
    //find if listen is successing
    if(listenreturn)
    {
        QMessageBox::information(this,tr("Listen"),tr("Listen successed"));
        ui->setButton->setEnabled(false);
        return;
    }
    else
    {
        QMessageBox::warning(this,tr("Listen"),tr("Listen failed"));
        return;
    }

}
//new connect slot
void Server::onNewConnection()
{
    //find new connection socket
    QTcpSocket *socknewer = m_server->nextPendingConnection();
    //get IP PORT
    QString strIPandPort = socknewer->peerAddress().toString()+tr("_%1").arg(socknewer->peerPort());
    m_IPandPortList.append(strIPandPort);

    //begin constract new client
    clientjobs *newClientJobs = new clientjobs(this,socknewer,strIPandPort);
    //push in client list
    m_ClientList.append(newClientJobs);
    //begin constract uid
    UID newuid;
    newuid.number = QString::number(UID_NUM);
    UID_NUM++;
    newuid.registed = "no";
    newuid.sockets_value = socknewer;

    uidlist.append(newuid);
    //show in list
    ui->listWidget->addItem("Client:UID-"+newuid.number);
    //tell client the uid num
    QString message = "0-YOUR UID NUMBER IS:<uidnum>"+newuid.number;
    send_to_client(newuid.sockets_value,message);



    //connect delete slot
    connect(newClientJobs,SIGNAL(CallMainWindowDeleteClient(QString)),this,SLOT(DeleteOneClient(QString)));
    //connect read slot
    connect(newClientJobs,SIGNAL(CallMainWindowReadData(QString,QString)),this,SLOT(readMessage(QString,QString)));

}

//delete slot
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

void Server::on_send_all_pushButton_clicked()
{
    //find if there have client
    if(m_ClientList.count()<1)
    {
        return;
    }

    //process the block

    QByteArray block = pickup_data(ui->lineEdit->text());
    //send block

    for(int i = 0;i<m_ClientList.size();i++)
    {
        m_ClientList[i]->SendBytes(block);

    }

}

QByteArray Server::pickup_data(QString data)
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

void Server::send_to_client(QTcpSocket *socket, QString data)
{
    QByteArray block = pickup_data(data);
    //send block

    socket->write(block);

}
