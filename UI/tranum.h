#ifndef TRANUM_H
#define TRANUM_H

#include <QDialog>

namespace Ui {
class tranum;
}

class tranum : public QDialog
{
    Q_OBJECT

public:
    explicit tranum(QWidget *parent = 0);
    ~tranum();



private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void receiveshow();//与发射的信号关联的槽
    void receivereturn();//与发射的信号关联的槽

signals:
    void tranumshowmain();//显示界面
    void trashow();//show trachinese

private:
    Ui::tranum *ui;
};

#endif // TRANUM_H
