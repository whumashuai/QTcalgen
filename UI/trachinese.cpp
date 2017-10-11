#include "trachinese.h"
#include "ui_trachinese.h"
#include "engnum.h"
#include "global.h"
#include "fraction.h"
#include "Generate.h"
#include<QtCore>
using namespace std;
extern deque<string> C_expression;//Reference global variable
extern deque<string> C_result;//Reference global variable


int k;

trachinese::trachinese(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trachinese)
{
    ui->setupUi(this);
    ui->textEdit_2->setReadOnly(true);
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);

    tratimer = new QTimer(this);//new Timer()
    traTimeRecord =new QTime(0,0,0);
    QObject::connect(tratimer,SIGNAL(timeout()),this,SLOT(timeUpdate()));
}

trachinese::~trachinese()
{
    delete ui;
}
void trachinese::print()//show the formula
{
    string s=C_expression.front();
    QString qs=QString::fromStdString(s);
    ui->lineEdit->setText(qs);
    C_expression.pop_front();
}

void trachinese::receiveshow()//Receive the signal,show the interface
{
    this->show();
    tratimer->start(1000);
    k=1;
    QString s=QString::number(k,10);
    ui->lineEdit_3->setText(s);

    print();
}

void trachinese::timeUpdate()
{
    *traTimeRecord = traTimeRecord->addSecs(1);
    QString strTime = traTimeRecord->toString("hh:mm:ss");
    ui->lcdNumber->display(strTime);
}

void trachinese::on_pushButton_clicked()//return
{
    this->hide();
    emit trashownum();

}

void trachinese::on_pushButton_2_clicked()//exit
{
    emit quit();

}

void trachinese::on_pushButton_3_clicked()//commit
{
    //Determine the correctness
    int cnt = 100/global::globaldata;
    int cou = 0;
    QString kp="";
    QString data=ui->lineEdit_2->text();
    string re=C_result.front();
    C_result.pop_front();
    QString data2=QString::fromStdString(re);
    if(data == data2)
    {
        cou++;
        kp="正確";
        kp.append("\n");

    }
    else
    {
        kp="錯誤";
        kp.append("\n");
        QString kpl="正確答案: ";
        kp.append(kpl);
        kp.append(data2);
        kp.append("\n");
    }

    //show the conclusion
    if(k == global::globaldata)
    {
        QString kp1="本次共有 ";
        kp.append(kp1);
        int kk=global::globaldata;
        QString kp6=QString::number(kk,10);
        kp.append(kp6);
        QString kp5=" 題,總分 100 分";
        kp.append(kp5);
        kp.append("\n");
        if(cou == global::globaldata)
        {
            QString kp2="本次得分: 100 分";
            kp.append(kp2);
            kp.append("\n");
        }
        else
        {
            QString kp3="本次得分: ";
            kp.append(kp3);
            int kk=cou*cnt;
            QString str=QString::number(kk,'f',2);
            kp.append(str);
            QString kp4="分";
            kp.append(kp4);
            kp.append("\n");
        }

        tratimer->stop();

        QString strTime = traTimeRecord->toString("hh:mm:ss");
        QString kp7="總時間: ";
        kp.append(kp7);
        kp.append(strTime);
        kp.append("\n");

    }
    ui->textEdit->setText(kp);
}

void trachinese::on_pushButton_4_clicked()//next
{
    //show the next formula
    k++;
    QString nul="";
    if(k<=global::globaldata)
    {
        QString s=QString::number(k,10);
        ui->lineEdit_3->setText(s);
        ui->lineEdit_2->setText(nul);
        ui->textEdit->setText(nul);
        ui->textEdit->setReadOnly(true);

        print();
    }

}
