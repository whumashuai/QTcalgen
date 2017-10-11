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

    void on_pushButton_2_clicked();//commit

    void on_pushButton_3_clicked();//return

    void receiveshow();//The signal is associated with the slot

    void receivereturn();//The signal is associated with the slot


signals:
    void simnumshowmain();//show mainWindow signal
    void simshow();//show simchinese signal

private:
    Ui::simnum *ui;
};

#endif // SIMNUM_H
