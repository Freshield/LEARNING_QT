#include "clientjobs.h"
#include <QDataStream>

clientjobs::clientjobs(QObject *parent, QTcpSocket *client, QString strIPPort) :
    QObject(parent)
{
    m_ClientSock = client;
    m_strIPPort = strIPPort;
    blockSize = 0;

    //connect signal and slots
    connect(m_ClientSock,SIGNAL(disconnected()),this,SLOT(LostConnection()));
    connect(m_ClientSock,SIGNAL(readyRead()),this,SLOT(ReadBytes()));
}

void clientjobs::SendBytes(QByteArray &data)
{
    m_ClientSock->write(data);
}

void clientjobs::LostConnection()
{
    emit CallMainWindowDeleteClient(m_strIPPort);
}

void clientjobs::ReadBytes()
{
    QDataStream in(m_ClientSock);
    in.setVersion(QDataStream::Qt_4_0);

    if(blockSize == 0)
    {
        if(m_ClientSock->bytesAvailable() < (int)sizeof(quint16))
        {
            return;
        }
        in >> blockSize;
    }

    if(m_ClientSock->bytesAvailable() < blockSize)
    {
        return;
    }

    in >> message;

    emit CallMainWindowReadData(m_strIPPort,message);

    blockSize = 0;
}
