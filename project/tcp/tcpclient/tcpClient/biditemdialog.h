#ifndef BIDITEMDIALOG_H
#define BIDITEMDIALOG_H

#include <QDialog>
#include <QListWidget>

namespace Ui {
    class BidItemDialog;
}

class BidItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BidItemDialog(QWidget *parent,QString data);
    ~BidItemDialog();

private slots:
    void itempricegot(QString price);

    void on_listWidget_itemDoubleClicked(QListWidgetItem* item);

private:
    Ui::BidItemDialog *ui;
    QString biditeminfo;
    QString m_itemscode;
signals:
    void biditemsinfo(QString itemcode,QString price);
};

#endif // BIDITEMDIALOG_H
