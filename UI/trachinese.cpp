#include "trachinese.h"
#include "ui_trachinese.h"
#include "engnum.h"
#include "global.h"
#include "fraction.h"
#include "Generate.h"
using namespace std;
extern deque<string> C_expression;
extern deque<string> C_result;


int k;

trachinese::trachinese(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trachinese)
{
    ui->setupUi(this);
    ui->textEdit_2->setReadOnly(true);
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
}

trachinese::~trachinese()
{
    delete ui;
}
void trachinese::print()
{
    string s=C_expression.front();
    QString qs=QString::fromStdString(s);
    ui->lineEdit->setText(qs);
    C_expression.pop_front();
}

void trachinese::receiveshow()//接收信号，显示界面
{
    this->show();
    k=1;
    QString s=QString::number(k,10);
    ui->lineEdit_3->setText(s);

    print();
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
        }


    }
    ui->textEdit->setText(kp);
}

void trachinese::on_pushButton_4_clicked()//next
{
    k++;
    QString nul="";
    if(k<=global::globaldata)
    {
        QString s=QString::number(k,10);
        ui->lineEdit_3->setText(s);
        ui->lineEdit_2->setText(nul);
        ui->textEdit->setText(nul);

        print();
    }

}
