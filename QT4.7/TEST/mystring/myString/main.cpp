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


    qDebug()<<"------------------------------------------------------";

    qDebug()<<QObject::tr("below is to test search operation")<<endl;
    str = "yafeilinux";
    qDebug()<<QObject::tr("string is :")<<str;
    qDebug()<<QObject::tr("include the right 5 words")<<str.right(5);
    qDebug()<<QObject::tr("include the left 5 words")<<str.left(5);
    qDebug()<<QObject::tr("include from the second word to the after 3 words")<<str.mid(2,3);
    qDebug()<<QObject::tr("find fei")<<str.indexOf("fei");
    qDebug()<<QObject::tr("the zero word of str")<<str.at(0);
    qDebug()<<QObject::tr("the counts of i")<<str.count('i');
    qDebug()<<QObject::tr("if str is begin as ya")<<str.startsWith("ya");
    qDebug()<<QObject::tr("if str is end of linux")<<str.endsWith("linux");
    qDebug()<<QObject::tr("if str include the string of lin")<<str.contains("lin");
    QString temp = "hello";
    if(temp>str)
    {

        qDebug()<<temp;
    }
    else
    {

        qDebug()<<str;
    }

    qDebug()<<"------------------------------------------------------";

    qDebug()<<QObject::tr("below is to test change operation")<<endl;
    str = "100";
    qDebug()<<QObject::tr("string to int:")<<str.toInt();
    int num = 45;
    str = QString::number(num);
    qDebug()<<QObject::tr("int to string:")<<str;













    return a.exec();
}
