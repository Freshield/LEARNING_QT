#ifndef CTHREADPOLL_H
#define CTHREADPOLL_H
#include "qt.h"
#include <QThread>
#include <QTcpSocket>
#include <QTimer>

class cThreadPoll : public QThread
{
	Q_OBJECT
public:
	cThreadPoll(int socketDescriptor);
	~cThreadPoll();
public slots:
	void stop_sev();
private:
	int socketDescriptor;
	QTcpSocket *sck;
	void run();
	qint8 respond(qint32 len);
};

enum {
	CHKV = 0,
	CHKVOK,
	CHKVFAIL,
	AddNew,
	ResetPw,
	ResetPwOK,
	ResetPwFile,
	CagPw,
	CagPwOK,
	CagPwFile,
	ChkIP,
	UpIP,
	UpIPOK,
	UpIPFile
};

struct sCMD
{
	quint8 cmd;
	quint32 who;
	union{
		quint16 pw;
		quint8 IP[4];
	}arg;
};

#endif // CTHREADPOLL_H
