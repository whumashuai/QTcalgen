#include "tranum.h"
#include "ui_tranum.h"
#include "global.h"
#include "Generate.h"

tranum::tranum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tranum)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

tranum::~tranum()
{
    delete ui;
}

void tranum::receiveshow()//Receive the signal,show the interface
{
    this->show();
}

void tranum::receivereturn()//Receive the signal,show the interface
{
    this->show();
}

void tranum::on_pushButton_clicked()//commit
{
    QString data=ui->lineEdit->text();

    global::qs=data;
    bool ok;
    int dec=data.toInt(&ok,10);
    global::globaldata=dec;
    Generate *gn=new Generate();
    gn->GenerateExpression(global::globaldata);

    this->hide();
    emit trashow();//send the signal
}

void tranum::on_pushButton_2_clicked()//return
{
    this->hide();
    emit tranumshowmain();//send the signal
}
