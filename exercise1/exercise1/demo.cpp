#include "demo.h"
#include "ui_demo.h"

const static double PI = 3.1415926;

DEMO::DEMO(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DEMO)
{
    ui->setupUi(this);
}

DEMO::~DEMO()
{
    delete ui;
}

void DEMO::on_countBtm_clicked()
{
    bool ok;//to give the string to int a bool value
    QString tempStr;//to store the final int to string
    QString valueStr = ui->radiusLineEdit->text();//to get the text value
    int valueInt = valueStr.toInt(&ok);//from string to int
    double area = valueInt*valueInt*PI;//calute the area
    ui->radiusLabel->setText(tempStr.setNum(area));

}



void DEMO::on_radiusLineEdit_textChanged(const QString &arg1)
{
    bool ok;//to give the string to int a bool value
    QString tempStr;//to store the final int to string
    QString valueStr = ui->radiusLineEdit->text();//to get the text value
    int valueInt = valueStr.toInt(&ok);//from string to int
    double area = valueInt*valueInt*PI;//calute the area
    ui->radiusLabel->setText(tempStr.setNum(area));

}
