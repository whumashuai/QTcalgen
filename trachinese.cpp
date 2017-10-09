#include "trachinese.h"
#include "ui_trachinese.h"

traChinese::traChinese(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::traChinese)
{
    ui->setupUi(this);
}

traChinese::~traChinese()
{
    delete ui;
}

void traChinese::receiveshow()//接收信号，显示界面
{
    this->show();
}

void traChinese::on_pushButton_clicked()
{
    this->hide();
    emit trshowmain();
}

void traChinese::on_pushButton_2_clicked()
{
    emit quit();
}
