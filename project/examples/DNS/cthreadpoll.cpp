#include "cthreadpoll.h"
#include "cserver.h"

cThreadPoll::cThreadPoll(int socketDescriptor)
{
	QTimer::singleShot(10000, this, SLOT(stop_sev()));
	this->socketDescriptor = socketDescriptor;
	this->start();
}

cThreadPoll::~cThreadPoll()
{
	delete sck;
}

void cThreadPoll::stop_sev()
{
	terminate();
	this->~cThreadPoll();
	delete this; //???????????
}

void cThreadPoll::run()
{
	qint64 len;
	sck->setSocketDescriptor()   //   = new QTcpSocket(socketDescriptor);
	while(1)
	{
		len = sck->bytesAvailable();
		if(len)
		{
			//if len > 256
			respond(len);
		}
	}
}

