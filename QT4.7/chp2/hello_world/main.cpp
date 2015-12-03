#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QTextCodec>

int main(int argc,char * argv[])
{
    QApplication a(argc,argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QDialog w;
    w.resize(400,300);
    QLabel label(&w);
    label.move(0,120);
    label.setText(QObject::tr("HELLO WORLD!!!��ð�~~~"));
    w.show();
    return a.exec();

}
