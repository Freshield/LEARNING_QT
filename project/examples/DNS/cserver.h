#ifndef CSERVER_H
#define CSERVER_H

#include "qt.h"
#include <QTcpServer>
#include <QMutex>

class cServer : public QTcpServer
{
	Q_OBJECT
public:
	explicit cServer(quint32 port, quint32 max_num);
	qint32 trygetsocketDescriptor();
private:
	QMutex mutex;
	qint32 socketDescriptor;
	void incomingConnection(int socketDescriptor); //连接请求事件
};

#endif // CSERVER_H
