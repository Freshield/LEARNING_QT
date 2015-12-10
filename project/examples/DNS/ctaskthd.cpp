#include "ctaskthd.h"
#include "cserver.h"

cTaskThd::cTaskThd(QObject *parent, int id) : QThread(parent)
{
	this->id = id;
	this->start();
}

qint32 cTaskThd::getsocketDescriptor(cServer *ser)
{
	qint32 tmp = 0;
	while(1)
	{
		if((tmp = ser->trygetsocketDescriptor()))
			return tmp;
		else
			sleep(0);
	}
}

void cTaskThd::run()
{
	QTcpSocket sck;

	while(1)
	{
		sck.close();
		if(sck.setSocketDescriptor(getsocketDescriptor((cServer *)this->parent())))
			if (sck.waitForReadyRead(SERVICE_TIMEOUT_SEC * 1000))
			{
				qDebug() << "�߳�" << this->id << " �����ݷ��غ󽫹ر�����" ;
				sck.write(sck.readAll());
				sck.waitForBytesWritten(3000);
			}
	}
}
