#ifndef CLIENTJOBS_H
#define CLIENTJOBS_H

#include <QObject>
#include <QtNetwork>
#include "clientjobs.h"

class clientjobs : public QObject
{
    Q_OBJECT
public:
    explicit clientjobs(QObject *parent, QTcpSocket *client, QString strIPPort);

    //TCP LINK
    QTcpSocket *m_ClientSock;//socket
    QString m_strIPPort;

    quint16 blockSize;
    QString message;

signals:
    void CallMainWindowDeleteClient(QString m_strIPPort);
    void CallMainWindowReadData(QString strIPPort,QString data);

public slots:
    void SendBytes(QByteArray &data);
    void LostConnection();
    void ReadBytes();

};

#endif // CLIENTJOBS_H
