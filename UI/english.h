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
    void print();

private slots:
    void on_pushButton_clicked();//return

    void on_pushButton_2_clicked();//exit

    void receiveshow();//与发射的信号关联的槽

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

signals:
    void engshownum();//show engnum
    void quit();//退出

private:
    Ui::English *ui;
};

#endif // ENGLISH_H
