#ifndef ENGNUM_H
#define ENGNUM_H

#include <QDialog>

namespace Ui {
class engnum;
}

class engnum : public QDialog
{
    Q_OBJECT

public:
    explicit engnum(QWidget *parent = 0);
    ~engnum();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void receiveshow();//与发射的信号关联的槽
    void receivereturn();//与发射的信号关联的槽

signals:
    void engnumshowmain();//显示界面
    void engshow();//show english

private:
    Ui::engnum *ui;
};

#endif // ENGNUM_H
