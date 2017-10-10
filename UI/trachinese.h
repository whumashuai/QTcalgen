#ifndef TRACHINESE_H
#define TRACHINESE_H

#include <QDialog>

namespace Ui {
class traChinese;
}

class traChinese : public QDialog
{
    Q_OBJECT

public:
    explicit traChinese(QWidget *parent = 0);
    ~traChinese();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void receiveshow();//与发射的信号关联的槽

signals:
    void trshowmain();//显示主界面
    void quit();//退出

private:
    Ui::traChinese *ui;
};

#endif // TRACHINESE_H
