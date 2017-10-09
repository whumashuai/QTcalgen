#include "mainwindow.h"
#include "english.h"
#include "simchinese.h"
#include "trachinese.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    English e;
    SimChinese s;
    traChinese t;
    w.show();

    //信号与槽之间进行联系
    QObject::connect(&w,SIGNAL(signalsim()),&s,SLOT(receiveshow()));
    QObject::connect(&s,SIGNAL(sishowmain()),&w,SLOT(receivereturn()));
    QObject::connect(&w,SIGNAL(quit()),&a,SLOT(quit()));
    QObject::connect(&s,SIGNAL(quit()),&a,SLOT(quit()));

    QObject::connect(&w,SIGNAL(signaltra()),&t,SLOT(receiveshow()));
    QObject::connect(&t,SIGNAL(trshowmain()),&w,SLOT(receivereturn()));
    QObject::connect(&w,SIGNAL(quit()),&a,SLOT(quit()));
    QObject::connect(&t,SIGNAL(quit()),&a,SLOT(quit()));

    QObject::connect(&w,SIGNAL(signalEng()),&e,SLOT(receiveshow()));
    QObject::connect(&e,SIGNAL(enshowmain()),&w,SLOT(receivereturn()));
    QObject::connect(&w,SIGNAL(quit()),&a,SLOT(quit()));
    QObject::connect(&e,SIGNAL(quit()),&a,SLOT(quit()));

    return a.exec();
}
