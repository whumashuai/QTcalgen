#ifndef SIMNUM_H
#define SIMNUM_H

#include <QDialog>

namespace Ui {
class simnum;
}

class simnum : public QDialog
{
    Q_OBJECT

public:
    explicit simnum(QWidget *parent = 0);
    ~simnum();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void receiveshow();//与发射的信号关联的槽
    void receivereturn();//与发射的信号关联的槽

signals:
    void simnumshowmain();//显示界面
    void simshow();//show simchinese

private:
    Ui::simnum *ui;
};

#endif // SIMNUM_H
