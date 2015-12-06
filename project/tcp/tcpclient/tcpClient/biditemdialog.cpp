#include "biditemdialog.h"
#include "ui_biditemdialog.h"

#include "bidpricedialog.h"
#include <QDebug>

BidItemDialog::BidItemDialog(QWidget *parent,QString data) :
    QDialog(parent),
    ui(new Ui::BidItemDialog)
{
    ui->setupUi(this);
    biditeminfo = data;
        int count = data.mid(data.indexOf("<ITSZ>")+6,data.indexOf("</ITS>")-data.indexOf("<ITSZ>")-6).toInt();
        for(int i = 0;i<count;i++)
        {
            QString tempbegin = tr("<ITN")+QString::number(i)+tr(">");
            QString tempend = tr("</IT")+QString::number(i)+tr(">");
            QString tempinfo = data.mid(data.indexOf(tempbegin)+6,data.indexOf(tempend)-data.indexOf(tempbegin)-6)+";";

            ui->listWidget->addItem(tempinfo);

        }

        connect(this,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_listWidget_itemDoubleClicked(QListWidgetItem*)),Qt::QueuedConnection);
}

BidItemDialog::~BidItemDialog()
{
    delete ui;
}


void BidItemDialog::itempricegot(QString price)
{

    emit biditemsinfo(m_itemscode,price);
    close();
}


void BidItemDialog::on_listWidget_itemDoubleClicked(QListWidgetItem* item)
{
    QString itemtemp = item->text();
    QString theitemcode = itemtemp.mid(itemtemp.indexOf(tr("ITEMCODE:"))+9,itemtemp.indexOf(";")-itemtemp.indexOf(tr("ITEMCODE:"))-9);
    m_itemscode = theitemcode;
    BidPriceDialog *newbidprice = new BidPriceDialog(this);
    connect(newbidprice,SIGNAL(itempriceget(QString)),this,SLOT(itempricegot(QString)),Qt::QueuedConnection);
    newbidprice->show();
}
