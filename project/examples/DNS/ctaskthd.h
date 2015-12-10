#ifndef CTASKTHD_H
#define CTASKTHD_H

#include "qt.h"
#include <QThread>
#include <QTcpSocket>
#include "cserver.h"

class cTaskThd : public QThread
{
	Q_OBJECT
public:
	explicit cTaskThd(QObject *parent, int id);
private:
	int id;
	qint32 getsocketDescriptor(cServer *ser);
	void run();
};

#endif // CTASKTHD_H
