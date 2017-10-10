#ifndef SIMCHINESE_H
#define SIMCHINESE_H

#include <QDialog>

namespace Ui {
class SimChinese;
}

class SimChinese : public QDialog
{
    Q_OBJECT

public:
    explicit SimChinese(QWidget *parent = 0);
    ~SimChinese();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void receiveshow();//与发射的信号关联的槽
    void on_lcdNumber_overflow();//时钟

signals:
    void sishowmain();//显示主界面
    void quit();//退出

private:
    Ui::SimChinese *ui;
};

#endif // SIMCHINESE_H
