#include "qt.h"
#include "cserver.h"
#include "ctaskthd.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
	cServer aa(52302, 100);
	for(int i=0; i<2; i++)
		new cTaskThd(&aa, i);
	return a.exec();
}
