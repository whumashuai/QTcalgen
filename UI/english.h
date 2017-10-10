#ifndef ENGLISH_H
#define ENGLISH_H

#include <QDialog>

namespace Ui {
class English;
}

class English : public QDialog
{
    Q_OBJECT

public:
    explicit English(QWidget *parent = 0);
    ~English();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void receiveshow();//与发射的信号关联的槽
signals:
    void enshowmain();//显示主界面
    void quit();//退出

private:
    Ui::English *ui;
};

#endif // ENGLISH_H
