#include <QtCore/QCoreApplication>
#include <QList>
#include <QMutableListIterator>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> list;
    list << "aa" << "bb" << "cc" << "dd";
    QMutableListIterator<QString> j(list);
    j.toFront();
    while(j.hasNext())
    {

        qDebug()<<j.next();
    }
    j.toBack();
    while(j.hasPrevious())
    {
        QString str = j.previous();
        if(str == "bb")
        {
            j.remove();
        }
    }
    j.toFront();
    while(j.hasNext())
    {

        qDebug()<<j.next();
    }

    j.toFront();

    j.insert("qq");
    j.toFront();
    while(j.hasNext())
    {

        qDebug()<<j.next();
    }
    j.toBack();
    if(j.hasPrevious())
    {
        j.previous() = "nn";
    }

    j.previous();
    j.setValue("mm");
    j.toFront();
    qDebug()<<"the forward is:";
    while(j.hasNext())
    {

        qDebug()<<j.next();
    }



    return a.exec();
}
