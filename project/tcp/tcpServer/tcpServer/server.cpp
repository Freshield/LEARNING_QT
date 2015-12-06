#include "server.h"
#include "ui_server.h"
#include <QtNetwork>
#include <QMessageBox>
#include <QHostAddress>
#include <QByteArray>
#include <QDebug>
#include "clientjobs.h"
#include "items.h"


Server::Server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    UID_NUM = 100;
    ITEM_NUM = 1000;
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
        ui->PortLineEdit->setEnabled(false);
        ui->lineEdit->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->send_all_pushButton->setEnabled(true);

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
    newuid.strIPandPort = strIPandPort;

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
    uidlist.removeAt(m_Index);
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


//read slot
void Server::readMessage(QString strIPandPort,QString data)
{

    QString temp = tr("\n")+ui->label->text();
    QString uidtemp;
    int listnum;

    for(listnum = 0;listnum<uidlist.size();listnum++)
    {
        if(strIPandPort == uidlist[listnum].strIPandPort)
        {
            uidtemp = uidlist[listnum].number;
            break;
        }

    }
    //safe begin
    if(data[0] == 'C' && data[1] == 'L')
    {

        //--------------------------------------------------------------//
        //----------------FIGURE OUT THE MESSAGE------------------------//
        //--------------------------------------------------------------//
        //split the message
        QString message_uid;
        QString message_header;
        QString message_data;
        message_uid = data.mid(data.indexOf("<uidnum>")+8,data.indexOf("</uidnu>")-data.indexOf("<uidnum>")-8);
        message_header = data.mid(data.indexOf("<header>")+8,data.indexOf("</heade>")-data.indexOf("<header>")-8);
        message_data = data.mid(data.indexOf("<messag>")+8,data.indexOf("</messa>")-data.indexOf("<messag>")-8);
        //figure out the header
        //regist
        if(message_header == "0")
        {
            int listnum2;
            //get the list place
            for(listnum2 = 0;listnum2<uidlist.size();listnum2++)
            {
                if(message_uid == uidlist[listnum2].number)
                {
                    uidlist[listnum2].name = message_data;
                    uidlist[listnum2].registed = "yes";
                    QString listtemp = ui->listWidget->item(listnum2)->text();
                    ui->listWidget->item(listnum2)->setText(listtemp+tr(" name:")+message_data);
                    QByteArray block = pickup_data(tr("SERVER SEND:YOUR REGISTED SUCCESS"));
                    m_ClientList[listnum2]->SendBytes(block);
                    ui->label->setText(tr("UID")+message_uid+tr(" regist success\nthe name is ")+message_data+temp);
                    break;
                }

            }

        }
        //see all bid
        else if(message_header == "1")
        {
            int listnum2;
            //get the list place
            for(listnum2 = 0;listnum2<uidlist.size();listnum2++)
            {
                //find the uid
                if(message_uid == uidlist[listnum2].number)
                {
                    //figure out if it is registed
                    if(uidlist[listnum2].registed == "no")
                    {
                        QByteArray block = pickup_data(tr("SERVER SEND:YOU ARE NOT REGISTED"));
                        m_ClientList[listnum2]->SendBytes(block);
                    }
                    //registed then see items
                    else
                    {
                        //if not have items
                        if(itemlist.size() < 1)
                        {
                            QByteArray block = pickup_data(tr("SERVER SEND:THERE HAVE NO ITEMS NOW"));
                            m_ClientList[listnum2]->SendBytes(block);
                            ui->label->setText(tr("CLIENT UID")+message_uid+tr("ASK ALL BID BUT NO ITEMS")+temp);
                        }
                        //send all items information
                        else
                        {
                            QString iteminfotemp = tr("SERVER SEND:ALL BID IS BELOW\n<ITSZ>")+QString::number(itemlist.size())+tr("</ITS>");
                            for(int i = 0;i < itemlist.size();i++)
                            {
                                QString temp = iteminfotemp+tr("\n<ITN")+QString::number(i)+tr(">");
                                iteminfotemp = temp+tr("NAME:")+itemlist[i]->m_name+tr(" PRICE:")+itemlist[i]->m_price+tr(" BUYER:")+itemlist[i]->m_buyer+tr(" OWNER:")+itemlist[i]->m_owner+tr(" ITEMCODE:")+itemlist[i]->m_itemcode+tr("</IT")+QString::number(i)+tr(">");


                            }
                            QByteArray block = pickup_data(iteminfotemp);
                            m_ClientList[listnum2]->SendBytes(block);
                            ui->label->setText(tr("CLIENT UID")+message_uid+tr("ASK ALL BID")+temp);

                        }
                    }

                    break;
                }

            }

        }
        //submit an item
        else if(message_header == "2")
        {
            int listnum2;
            //get the list place
            for(listnum2 = 0;listnum2<uidlist.size();listnum2++)
            {
                //find the uid
                if(message_uid == uidlist[listnum2].number)
                {
                    //figure out if it is registed
                    if(uidlist[listnum2].registed == "no")
                    {
                        QByteArray block = pickup_data(tr("SERVER SEND:YOU ARE NOT REGISTED"));
                        m_ClientList[listnum2]->SendBytes(block);
                    }
                    //registed then see items
                    else
                    {
                    //TO DO
                    items *newitem = new items(this,message_data,tr("NULL"),message_uid,tr("0"),QString::number(ITEM_NUM),tr("NULL"));
                    ITEM_NUM++;
                    itemlist.append(newitem);
                    QString newitemtemp = tr("NAME:")+newitem->m_name+tr(" PRICE:")+newitem->m_price+tr(" BUYER:")+newitem->m_buyer+tr(" OWNER:")+newitem->m_owner+tr(" ITEMCODE:")+newitem->m_itemcode;

                    ui->ItemlistWidget->addItem(newitemtemp);
                    QByteArray block = pickup_data(tr("SERVER SEND:YOUR ITEM ")+newitem->m_name+tr("\nSUBMIT SUCCESSED"));
                    m_ClientList[listnum2]->SendBytes(block);

                    }

                    break;
                }

            }

        }
        //bid an item
        else if(message_header == "3")
        {
            int listnum2;
            //get the list place
            for(listnum2 = 0;listnum2<uidlist.size();listnum2++)
            {
                //find the uid
                if(message_uid == uidlist[listnum2].number)
                {
                    //figure out if it is registed
                    if(uidlist[listnum2].registed == "no")
                    {
                        QByteArray block = pickup_data(tr("SERVER SEND:YOU ARE NOT REGISTED"));
                        m_ClientList[listnum2]->SendBytes(block);
                    }
                    //registed then see items
                    else
                    {
                    //TO DO
                        //if not have items
                        if(itemlist.size() < 1)
                        {
                            QByteArray block = pickup_data(tr("SERVER SEND:THERE HAVE NO ITEMS NOW"));
                            m_ClientList[listnum2]->SendBytes(block);
                            ui->label->setText(tr("CLIENT UID")+message_uid+tr("WANT A BID BUT NO ITEMS")+temp);
                        }
                        //send all items information
                        else
                        {
                            QString iteminfotemp = tr("SERVER SEND:ALL ITEM YOU CAN BID IS BELOW\n<ITSZ>")+QString::number(itemlist.size())+tr("</ITS>");
                            for(int i = 0;i < itemlist.size();i++)
                            {
                                QString temp = iteminfotemp+tr("\n<ITN")+QString::number(i)+tr(">");
                                iteminfotemp = temp+tr("NAME:")+itemlist[i]->m_name+tr(" PRICE:")+itemlist[i]->m_price+tr(" BUYER:")+itemlist[i]->m_buyer+tr(" OWNER:")+itemlist[i]->m_owner+tr(" ITEMCODE:")+itemlist[i]->m_itemcode+tr("</IT")+QString::number(i)+tr(">");


                            }
                            QByteArray block = pickup_data(iteminfotemp);
                            m_ClientList[listnum2]->SendBytes(block);
                            ui->label->setText(tr("CLIENT UID")+message_uid+tr("WANT A BID")+temp);

                        }



                    }

                    break;
                }

            }

        }
        //get the bid item
        else if(message_header == "31")
        {
            int listnum2;
            //get the list place
            for(listnum2 = 0;listnum2<uidlist.size();listnum2++)
            {
                //find the uid
                if(message_uid == uidlist[listnum2].number)
                {
                    //figure out if it is registed
                    if(uidlist[listnum2].registed == "no")
                    {
                        QByteArray block = pickup_data(tr("SERVER SEND:YOU ARE NOT REGISTED"));
                        m_ClientList[listnum2]->SendBytes(block);
                    }
                    //registed then see items
                    else
                    {
                    //TO DO
                        //if not have items
                        if(itemlist.size() < 1)
                        {
                            QByteArray block = pickup_data(tr("SERVER SEND:THERE HAVE NO ITEMS NOW"));
                            m_ClientList[listnum2]->SendBytes(block);
                            ui->label->setText(tr("CLIENT UID")+message_uid+tr("WANT A BID BUT NO ITEMS")+temp);
                        }
                        //send all items information
                        else
                        {
                        //TO DO
                            QString biditemcode = message_data.mid(message_data.indexOf("<itecod>")+8,message_data.indexOf("</iteco>")-message_data.indexOf("<itecod>")-8);
                            QString biditemprice = message_data.mid(message_data.indexOf("<itepri>")+8,message_data.indexOf("</itepr>")-message_data.indexOf("<itepri>")-8);
                            int ifgetitem = 0;
                            for(int i = 0;i < itemlist.size();i++)
                            {
                               if(itemlist[i]->m_itemcode == biditemcode)
                               {
                                   ifgetitem = 1;
                                   itemlist[i]->m_price = biditemprice;
                                   itemlist[i]->m_buyer = message_uid;

                                   QString itemtemp = ui->ItemlistWidget->item(i)->text();
                                   QString firstpart = itemtemp.mid(0,itemtemp.indexOf(" PRICE:"));
                                   QString secondpart = itemtemp.mid(itemtemp.indexOf(" OWNER:"),itemtemp.size()-itemtemp.indexOf(" OWNER:"));
                                   itemtemp = firstpart+tr(" PRICE:")+biditemprice+tr(" BUYER:")+message_uid+secondpart;

                                   ui->ItemlistWidget->item(i)->setText(itemtemp);
                                   break;
                               }
                            }
                            //see if success get the item
                            if(ifgetitem == 0)
                            {
                                QByteArray block = pickup_data(tr("SERVER SEND:YOUR BID FAILED\nCAUSE NOT FIND THE ITEM"));
                                m_ClientList[listnum2]->SendBytes(block);
                                ui->label->setText(tr("CLIENT UID")+message_uid+tr("BID FAILED\nCAUSE NOT FIND THE ITEM")+temp);
                            }
                            else
                            {
                                QByteArray block = pickup_data(tr("SERVER SEND:YOUR BID SUCCESS"));
                                m_ClientList[listnum2]->SendBytes(block);
                                ui->label->setText(tr("CLIENT UID")+message_uid+tr("BID SUCCESS")+temp);
                            }


                        }



                    }

                    break;
                }

            }

        }
        else
        {
            ui->label->setText(temp+temp);

        }


    }
    else
    {

        ui->label->setText(data+temp);

    }


}

/*
void Server::on_TestpushButton_clicked()
{
    items *newitem = new items(this,"NULL","NULL","NULL","NULL","NULL","NULL");
    testitem = newitem;
    connect(newitem,SIGNAL(CallMainWindowTimeout(QString)),this,SLOT(OneItemTimeout(QString)));

}

void Server::OneItemTimeout(QString itemcode)
{
    QMessageBox::information(this,tr("ItemTimeout"),tr("ItemCode")+itemcode+tr("Timeout"));
}

void Server::on_TestpushButton_2_clicked()
{
    testitem->SetTimeagain();
}
*/
/*
void Server::on_testpushButton_clicked()
{
    TestDialog *testdialog = new TestDialog(this);
    testdialog->show();
}
*/
