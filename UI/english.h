#ifndef ENGLISH_H
#define ENGLISH_H

#include <QDialog>
#include<QtCore>
#include<QTime>


namespace Ui {
class English;
}

class English : public QDialog
{
    Q_OBJECT

public:
    explicit English(QWidget *parent = 0);
    ~English();
    void print();

private slots:
    void on_pushButton_clicked();//return

    void on_pushButton_2_clicked();//exit

    void receiveshow();//The signal is associated with the slot

    void on_pushButton_3_clicked();//commit

    void on_pushButton_4_clicked();//next

    void timeUpdate();//uodate time

signals:
    void engshownum();//show engnum
    void quit();//exit


private:
    Ui::English *ui;

    QTimer *engtimer;
    QTime *engTimeRecord;//record time

};

#endif // ENGLISH_H
