#include "simchinese.h"
#include "ui_simchinese.h"
#include<QTime>
#include<QTimer>

SimChinese::SimChinese(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimChinese)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(on_lcdNumber_overflow()));
    timer->start(500);
}

SimChinese::~SimChinese()
{
    delete ui;
}

void SimChinese::receiveshow()//接收信号，显示界面
{
    this->show();
}

void SimChinese::on_pushButton_clicked()
{
    this->hide();
    emit sishowmain();
}

void SimChinese::on_pushButton_2_clicked()
{
    emit quit();
}

void SimChinese::on_lcdNumber_overflow()//show time
{
    QTime time=QTime::currentTime();
    QString  txtTime=time.toString("hh:mm:ss");
    ui->lcdNumber->display(txtTime);
}
