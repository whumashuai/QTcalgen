#include "simchinese.h"
#include "ui_simchinese.h"
#include "engnum.h"
#include "global.h"
#include "fraction.h"
#include "Generate.h"
#include<QtCore>
using namespace std;
extern deque<string> C_expression;
extern deque<string> C_result;


int j;

simchinese::simchinese(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::simchinese)
{
    ui->setupUi(this);
    ui->textEdit_2->setReadOnly(true);
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->textEdit->setReadOnly(true);

    simtimer = new QTimer(this);//new Timer()
    simTimeRecord =new QTime(0,0,0);
    QObject::connect(simtimer,SIGNAL(timeout()),this,SLOT(timeUpdate()));
}

simchinese::~simchinese()
{
    delete ui;
}

void simchinese::print()//show the formula
{
    string s=C_expression.front();
    QString qs=QString::fromStdString(s);
    ui->lineEdit->setText(qs);
    C_expression.pop_front();
}

void simchinese::timeUpdate()
{
    *simTimeRecord = simTimeRecord->addSecs(1);
    QString strTime = simTimeRecord->toString("hh:mm:ss");
    ui->lcdNumber->display(strTime);
}

void simchinese::receiveshow()//receive the signal,show the interface
{
    this->show();
    simtimer->start(1000);
    j=1;
    QString s=QString::number(j,10);
    ui->lineEdit_3->setText(s);

    print();
}

void simchinese::on_pushButton_clicked()//return
{
    this->hide();
    emit simshownum();

}

void simchinese::on_pushButton_2_clicked()//exit
{
    emit quit();

}

void simchinese::on_pushButton_3_clicked()//commit
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
        kp="正确";
        kp.append("\n");

    }
    else
    {
        kp="错误";
        kp.append("\n");
        QString kpl="正确答案: ";
        kp.append(kpl);
        kp.append(data2);
        kp.append("\n");
    }

    //show the conclusion
    if(j == global::globaldata)
    {
        QString kp1="本次共有";
        kp.append(kp1);
        int kk=global::globaldata;
        QString kp6=QString::number(kk,10);
        kp.append(kp6);
        QString kp5=" 题,总分100分";
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

        simtimer->stop();

        QString strTime = simTimeRecord->toString("hh:mm:ss");
        QString kp7="总时间: ";
        kp.append(kp7);
        kp.append(strTime);
        kp.append("\n");

    }
    ui->textEdit->setText(kp);

}

void simchinese::on_pushButton_4_clicked()//next
{
    //show the next formula
    j++;
    QString nul="";
    if(j<=global::globaldata)
    {
        QString s=QString::number(j,10);
        ui->lineEdit_3->setText(s);
        ui->lineEdit_2->setText(nul);
        ui->textEdit->setText(nul);

        print();
    }

}
