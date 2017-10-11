#ifndef SIMCHINESE_H
#define SIMCHINESE_H

#include <QDialog>
#include<QtCore>

namespace Ui {
class simchinese;
}

class simchinese : public QDialog
{
    Q_OBJECT

public:
    explicit simchinese(QWidget *parent = 0);
    ~simchinese();
    void print();

private slots:
    void on_pushButton_clicked();//return

    void on_pushButton_2_clicked();//exit

    void receiveshow();//The signal is associated with the slot


    void on_pushButton_3_clicked();//commit

    void on_pushButton_4_clicked();//next

    void timeUpdate();//uodate time

signals:
    void simshownum();//show simnum signal
    void quit();//exit signal

private:
    Ui::simchinese *ui;

    QTimer *simtimer;
    QTime *simTimeRecord;//record time
};

#endif // SIMCHINESE_H
