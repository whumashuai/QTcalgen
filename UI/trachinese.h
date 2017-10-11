#ifndef TRACHINESE_H
#define TRACHINESE_H

#include <QDialog>
#include<QtCore>

namespace Ui {
class trachinese;
}

class trachinese : public QDialog
{
    Q_OBJECT

public:
    explicit trachinese(QWidget *parent = 0);
    ~trachinese();
    void print();

private slots:
    void on_pushButton_clicked();//return

    void on_pushButton_2_clicked();//exit

    void receiveshow();//The signal is associated with the slot


    void on_pushButton_3_clicked();//commit

    void on_pushButton_4_clicked();//next

    void timeUpdate();//uodate time

signals:
    void trashownum();//show tranum interface signal
    void quit();//exit signal

private:
    Ui::trachinese *ui;

    QTimer *tratimer;
    QTime *traTimeRecord;//record time
};

#endif // TRACHINESE_H
