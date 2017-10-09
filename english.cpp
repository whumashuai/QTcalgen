#include "english.h"
#include "ui_english.h"

English::English(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::English)
{
    ui->setupUi(this);
}

English::~English()
{
    delete ui;
}

void English::receiveshow()//接收信号，显示界面
{
    this->show();
}

void English::on_pushButton_clicked()
{
    this->hide();
    emit enshowmain();
}

void English::on_pushButton_2_clicked()
{
    emit quit();
}

