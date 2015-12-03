#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class window : public QWidget
{
    Q_OBJECT

public:
    window(QWidget *parent = 0);
    ~window();
};

#endif // WINDOW_H
