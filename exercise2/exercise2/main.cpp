#include "demo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DEMO w;
    w.show();

    return a.exec();
}
