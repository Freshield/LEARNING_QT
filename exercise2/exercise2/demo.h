#ifndef DEMO_H
#define DEMO_H

#include <QMainWindow>

namespace Ui {
class DEMO;
}

class DEMO : public QMainWindow
{
    Q_OBJECT

public:
    explicit DEMO(QWidget *parent = 0);
    ~DEMO();

private:
    Ui::DEMO *ui;
};

#endif // DEMO_H
