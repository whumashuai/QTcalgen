#include "engnum.h"
#include "ui_engnum.h"
#include "global.h"
#include "Generate.h"

engnum::engnum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::engnum)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);

}

engnum::~engnum()
{
    delete ui;
}

void engnum::receiveshow()//Receive the signal,show interface
{
    this->show();
}

void engnum::receivereturn()//Receive the signal,show interface
{
    this->show();
}


void engnum::on_pushButton_clicked()//commit
{
    QString data=ui->lineEdit->text();

    global::qs=data;
    bool ok;
    int dec=data.toInt(&ok,10);
    global::globaldata=dec;
    Generate *gn=new Generate();
    gn->GenerateExpression(global::globaldata);

    this->hide();
    emit engshow();//send the signal
}

void engnum::on_pushButton_2_clicked()//return
{
    this->hide();
    emit engnumshowmain();//send the signal
}
