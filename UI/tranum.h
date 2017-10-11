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

    void on_pushButton_clicked();//commit

    void on_pushButton_2_clicked();//return

    void receiveshow();//The signal is associated with the slot

    void receivereturn();//与The signal is associated with the slot


signals:
    void tranumshowmain();//show mainWindow singal
    void trashow();//show trachinese interface singal

private:
    Ui::tranum *ui;
};

#endif // TRANUM_H
