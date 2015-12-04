#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QAbstractSocket>
#include <QTcpServer>
#include <QList>

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

    QTcpSocket *test;
    quint16 blockSize;
    QString message;
    QTcpServer tcpServer;
    QList<QTcpSocket> *Socketbar;



private slots:
    void on_pushButton_clicked();
    void readMessage();
    void acceptedConnection();
    void displayError(QAbstractSocket::SocketError);
};

#endif // SERVER_H
