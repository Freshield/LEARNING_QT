#include "seeallbiddialog.h"
#include "ui_seeallbiddialog.h"

SeeAllBidDialog::SeeAllBidDialog(QWidget *parent,QString data) :
    QDialog(parent),
    ui(new Ui::SeeAllBidDialog)
{
    ui->setupUi(this);
    allbidinfo = data;
    int count = data.mid(data.indexOf("<ITSZ>")+6,data.indexOf("</ITS>")-data.indexOf("<ITSZ>")-6).toInt();
    for(int i = 0;i<count;i++)
    {
        QString tempbegin = tr("<ITN")+QString::number(i)+tr(">");
        QString tempend = tr("</IT")+QString::number(i)+tr(">");
        QString tempinfo = data.mid(data.indexOf(tempbegin)+6,data.indexOf(tempend)-data.indexOf(tempbegin)-6);
        ui->listWidget->addItem(tempinfo);

    }
}

SeeAllBidDialog::~SeeAllBidDialog()
{
    delete ui;
}
