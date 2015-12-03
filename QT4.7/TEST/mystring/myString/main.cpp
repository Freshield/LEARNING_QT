#include <QtCore/QCoreApplication>
#include <QTextCodec>
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    qDebug()<<QObject::tr("below is editing string operation:")<<endl;

    QString str = "hello";
    qDebug()<<QObject::tr("str is:")<<str;
    qDebug()<<QObject::tr("the size of string is:")<<str.size();
    str[0] = QChar('H');
    qDebug()<<QObject::tr("str is:")<<str;
    qDebug()<<QObject::tr("first word is :")<<str[0];
    str.append("QT");
    qDebug()<<QObject::tr("str is:")<<str;
    str.replace(1,4,"i");
    qDebug()<<QObject::tr("str is:")<<str;
    str.insert(2,"my");
    qDebug()<<QObject::tr("str is:")<<str;
    str = str+"!!!";
    qDebug()<<QObject::tr("str is:")<<str;
    str = "  hi\r\n QT!!! \n"  ;
    qDebug()<<QObject::tr("str is:")<<str;
    QString str1 = str.trimmed();
    qDebug()<<QObject::tr("str1 is:")<<str1;
    QString str2 = str.simplified();
    qDebug()<<QObject::tr("str2 is:")<<str2;
    str = "hi,my,,QT";
    qDebug()<<QObject::tr("str is:")<<str;
    QStringList list = str.split(",",QString::SkipEmptyParts);
    qDebug()<<QObject::tr("splited str is:")<<list;
    str = list.join("");
    qDebug()<<QObject::tr("str is:")<<str;

    qDebug()<<QString().isNull();
    qDebug()<<QString().isEmpty();
    qDebug()<<QString("").isNull();
    qDebug()<<QString("").isEmpty();







    return a.exec();
}
