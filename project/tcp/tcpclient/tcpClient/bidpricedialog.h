#ifndef BIDPRICEDIALOG_H
#define BIDPRICEDIALOG_H

#include <QDialog>

namespace Ui {
    class BidPriceDialog;
}

class BidPriceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BidPriceDialog(QWidget *parent = 0);
    ~BidPriceDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BidPriceDialog *ui;
signals:
    void itempriceget(QString price);
};

#endif // BIDPRICEDIALOG_H
