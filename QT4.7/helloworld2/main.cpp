#include "ui_hellodialog.h"

int main(int argc,char * argv[])
{
    QApplication a(argc,argv);
    //QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QDialog w;
    //w.resize(400,300);
    Ui::HelloDialog ui;
    //QLabel label(&w);
    //label.move(0,120);
    //label.setText(QObject::tr("HELLO WORLD!!!ÄãºÃ°¡~~~"));
    ui.setupUi(&w);
    w.show();
    return a.exec();

}
