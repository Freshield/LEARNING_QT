#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget *parent = 0);

signals:

public slots:

protected:
    void keyPressEvent(QKeyEvent *event);

};

#endif // MYLINEEDIT_H
