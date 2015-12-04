#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString localHostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localHostName);
    qDebug()<<"localhostname:"<<localHostName<<endl;
               qDebug()<< "IP address:"<<info.addresses();
    foreach(QHostAddress address,info.addresses())
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
        {
            qDebug()<<address.toString();
        }
    }
    QHostInfo::lookupHost("www.baidu.com",this,SLOT(lookedUP(QHostInfo)));

    int ID = QHostInfo::lookupHost("www.baidu.com",this,SLOT(lookedUP(QHostInfo)));
    QHostInfo::abortHostLookup(ID);

    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();

    foreach(QNetworkInterface interface,list)
    {
        qDebug()<<"NAME:"<<interface.name();
        qDebug()<<"HARDWAREADDRESS:"<<interface.hardwareAddress();
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();

        foreach(QNetworkAddressEntry entry,entryList)
        {
            qDebug()<<"IP ADDRESS:"<<entry.ip().toString();
            qDebug()<<"NETMASK:"<<entry.netmask().toString();
            qDebug()<<"BROADCAST:"<<entry.broadcast().toString();
        }
    }

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lookedUP(const QHostInfo &host)
{
    if(host.error() != QHostInfo::NoError)
    {
        qDebug()<<"lookup failed:"<<host.errorString();
        return;
    }
    foreach(const QHostAddress &address,host.addresses())
    {
        qDebug()<<"Found address:"<<address.toString();
    }
}
