#include "simnum.h"
#include "ui_simnum.h"
#include "global.h"
#include "Generate.h"

simnum::simnum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::simnum)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

simnum::~simnum()
{
    delete ui;
}

void simnum::receiveshow()//Receive the signal,show the interface
{
    this->show();
}

void simnum::receivereturn()//Receive the signal,show the interface
{
    this->show();
}

void simnum::on_pushButton_2_clicked()//commit
{
    QString data=ui->lineEdit_2->text();

    global::qs=data;
    bool ok;
    int dec=data.toInt(&ok,10);
    global::globaldata=dec;
    Generate *gn=new Generate();
    gn->GenerateExpression(global::globaldata);

    this->hide();
    emit simshow();//send the signal
}

void simnum::on_pushButton_3_clicked()//return
{
    this->hide();
    emit simnumshowmain();//send the signal
}
