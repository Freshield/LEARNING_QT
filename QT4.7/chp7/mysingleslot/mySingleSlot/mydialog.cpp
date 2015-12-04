#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDebug>

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_clicked()
{

    qDebug()<<6;
    int value = ui->spinBox->value();

    qDebug()<<7;
    emit dlgReturn(value);
    qDebug()<<8;
    close();
    qDebug()<<9;
}
