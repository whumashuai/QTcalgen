#include "english.h"
#include "ui_english.h"
#include "engnum.h"
#include "global.h"
#include "fraction.h"
#include "Generate.h"
using namespace std;
extern deque<string> C_expression;
extern deque<string> C_result;


int i,m=0;

English::English(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::English)
{
    ui->setupUi(this);
    ui->textEdit_2->setReadOnly(true);
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
}

English::~English()
{
    delete ui;
}

void English::print()
{
    string s=C_expression.front();
    QString qs=QString::fromStdString(s);
    ui->lineEdit->setText(qs);
    C_expression.pop_front();
}

void English::receiveshow()//接收信号，显示界面
{
    this->show();
    i=1;
    QString s=QString::number(i,10);
    ui->lineEdit_3->setText(s);

    print();
}

void English::on_pushButton_clicked()//return
{
    this->hide();
    emit engshownum();

}

void English::on_pushButton_2_clicked()//exit
{
    emit quit();

}

void English::on_pushButton_3_clicked()//commit
{
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
        kp="correct";
        kp.append("\n");

    }
    else
    {
        kp="error";
        kp.append("\n");
        QString kpl="The correct answer: ";
        kp.append(kpl);
        kp.append(data2);
        kp.append("\n");
        ui->textEdit->setText(kp);
    }

    if(i == global::globaldata)
    {
        QString kp1="This is a total of ";
        kp.append(kp1);
        int kk=global::globaldata;
        QString kp6=QString::number(kk,10);
        kp.append(kp6);
        QString kp5=" questions,a total of 100 points";
        kp.append(kp5);
        kp.append("\n");
        if(cou == global::globaldata)
        {
            QString kp2="The score: 100 points";
            kp.append(kp2);
        }
        else
        {
            QString kp3="The score: ";
            kp.append(kp3);
            int kk=cou*cnt;
            QString str=QString::number(kk,'f',2);
            kp.append(str);
            QString kp4="points";
            kp.append(kp4);
        }


    }
    ui->textEdit->setText(kp);

}

void English::on_pushButton_4_clicked()//next
{
    i++;
    QString nul="";
    if(i<=global::globaldata)
    {
        QString s=QString::number(i,10);
        ui->lineEdit_3->setText(s);
        ui->lineEdit_2->setText(nul);
        ui->textEdit->setText(nul);

        print();
    }

}
