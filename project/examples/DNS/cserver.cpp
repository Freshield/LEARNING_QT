#include "cserver.h"
#include "ctaskthd.h"
#include <QObject>

cServer::cServer(quint32 port, quint32 max_num)
{
	socketDescriptor = 0;
	setMaxPendingConnections(max_num);
	if(!listen(QHostAddress::Any, port))
		qDebug() << "端口："<< port << "开始监听失败";
	else
		qDebug() << "开始监听端口:"<< port << "最大可响应连接:" << max_num;
}

void cServer::incomingConnection(int socketDescriptor)
{
	while(1)
	{
		mutex.lock();
		if(this->socketDescriptor == 0)
		{
			this->socketDescriptor = socketDescriptor;
			mutex.unlock();
			return ;
		}
		mutex.unlock();
	}
}

qint32 cServer::trygetsocketDescriptor()
{
	qint32 tmp = 0;
	if(mutex.tryLock())
	{
		if(this->socketDescriptor != 0)
		{
			tmp = socketDescriptor;
			socketDescriptor = 0;
		}
		mutex.unlock();
	}

	return tmp;
}

