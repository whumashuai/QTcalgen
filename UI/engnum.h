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

    void on_pushButton_clicked();//commit

    void on_pushButton_2_clicked();//return

    void receiveshow();//The signal is associated with the slot
    void receivereturn();//The signal is associated with the slot

signals:
    void engnumshowmain();//show mainWindow
    void engshow();//show english

private:
    Ui::engnum *ui;
};

#endif // ENGNUM_H
