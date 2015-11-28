#ifndef DEMO_H
#define DEMO_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class DEMO;
}

class DEMO : public QMainWindow
{
    Q_OBJECT

public:
    explicit DEMO(QWidget *parent = 0);
    ~DEMO();

private slots:
    void on_countBtm_clicked();

private:
    QLabel *label1,*label2;
    QLineEdit *lineEdit;
    QPushButton *button;
    Ui::DEMO *ui;
};

#endif // DEMO_H
