#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receivereturn()//Receive the signal,show the interface
{
    this->show();
}

void MainWindow::on_pushButton_clicked()//simchinese
{
    this->hide();
    emit signalsim();
}

void MainWindow::on_pushButton_2_clicked()//trachinese
{
    this->hide();
    emit signaltra();

}

void MainWindow::on_pushButton_3_clicked()//english
{
    this->hide();
    emit signalEng();

}

void MainWindow::on_pushButton_4_clicked()//exit
{
    emit quit();

}
