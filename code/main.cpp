#include "mainwindow.h"
#include "english.h"
#include "simchinese.h"
#include "trachinese.h"
#include "engnum.h"
#include "tranum.h"
#include "simnum.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    English e;
    simchinese s;
    trachinese t;

    engnum en;
    tranum tn;
    simnum sn;
    w.show();

    //The signal is connected to the slot
    //mainwindow,tranum and trachinese are connected
    QObject::connect(&w,SIGNAL(signaltra()),&tn,SLOT(receiveshow()));
    QObject::connect(&tn,SIGNAL(tranumshowmain()),&w,SLOT(receivereturn()));
    QObject::connect(&tn,SIGNAL(trashow()),&t,SLOT(receiveshow()));
    QObject::connect(&t,SIGNAL(trashownum()),&tn,SLOT(receivereturn()));
    QObject::connect(&w,SIGNAL(quit()),&a,SLOT(quit()));
    QObject::connect(&t,SIGNAL(quit()),&a,SLOT(quit()));

    //mainwindow,simnum and simchinese are connected
    QObject::connect(&w,SIGNAL(signalsim()),&sn,SLOT(receiveshow()));
    QObject::connect(&sn,SIGNAL(simnumshowmain()),&w,SLOT(receivereturn()));
    QObject::connect(&sn,SIGNAL(simshow()),&s,SLOT(receiveshow()));
    QObject::connect(&s,SIGNAL(simshownum()),&sn,SLOT(receivereturn()));
    QObject::connect(&w,SIGNAL(quit()),&a,SLOT(quit()));
    QObject::connect(&s,SIGNAL(quit()),&a,SLOT(quit()));

    //mainwindow,engnum and english are connected
    QObject::connect(&w,SIGNAL(signalEng()),&en,SLOT(receiveshow()));
    QObject::connect(&en,SIGNAL(engnumshowmain()),&w,SLOT(receivereturn()));
    QObject::connect(&en,SIGNAL(engshow()),&e,SLOT(receiveshow()));
    QObject::connect(&e,SIGNAL(engshownum()),&en,SLOT(receivereturn()));
    QObject::connect(&w,SIGNAL(quit()),&a,SLOT(quit()));
    QObject::connect(&e,SIGNAL(quit()),&a,SLOT(quit()));



    return a.exec();
}
