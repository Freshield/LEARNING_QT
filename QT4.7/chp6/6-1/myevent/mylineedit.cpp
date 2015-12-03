#include "mylineedit.h"
#include <QKeyEvent>
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<tr("MyLineEdit press event");
    QLineEdit::keyPressEvent(event);
    event->ignore();
}
