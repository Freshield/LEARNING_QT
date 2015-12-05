#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
//#include <QAbstractSocket>
#include <QTcpServer>
#include <QList>
#include <QtNetwork>
#include <QStringList>
#include "clientjobs.h"

class QTcpServer;

namespace Ui {
    class Server;
}

class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

private:
    Ui::Server *ui;

    //quint16 blockSize;
    //QString message;
    QTcpServer *m_server;
    QList<clientjobs*> m_ClientList;
    QStringList m_IPandPortList;



private slots:
    void on_pushButton_clicked();
    void readMessage(QString strIPandPort,QString data);

    void onNewConnection();
    void DeleteOneClient(QString strIPandPort);

    void on_setButton_clicked();
};

#endif // SERVER_H
