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

void simnum::receiveshow()
{
    this->show();
}

void simnum::receivereturn()
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
    emit simshow();
}

void simnum::on_pushButton_3_clicked()//return
{
    this->hide();
    emit simnumshowmain();
}
