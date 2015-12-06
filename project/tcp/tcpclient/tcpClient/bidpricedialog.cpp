#include "bidpricedialog.h"
#include "ui_bidpricedialog.h"
#include <QMessageBox>

BidPriceDialog::BidPriceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BidPriceDialog)
{
    ui->setupUi(this);
}

BidPriceDialog::~BidPriceDialog()
{
    delete ui;
}

void BidPriceDialog::on_pushButton_clicked()
{
    QString itemprice = ui->lineEdit->text();
    if(itemprice == "")
    {
        QMessageBox::warning(this,tr("Price"),tr("Price can not empty"));
        return;
    }
    else
    {
        emit itempriceget(itemprice);

    }
    close();
}
