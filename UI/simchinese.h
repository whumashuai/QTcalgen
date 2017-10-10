#ifndef SIMCHINESE_H
#define SIMCHINESE_H

#include <QDialog>

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void receiveshow();//与发射的信号关联的槽

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

signals:
    void simshownum();//show simnum
    void quit();//退出

private:
    Ui::simchinese *ui;
};

#endif // SIMCHINESE_H
