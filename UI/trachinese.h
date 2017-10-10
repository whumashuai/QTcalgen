#ifndef TRACHINESE_H
#define TRACHINESE_H

#include <QDialog>

namespace Ui {
class trachinese;
}

class trachinese : public QDialog
{
    Q_OBJECT

public:
    explicit trachinese(QWidget *parent = 0);
    ~trachinese();
    void print();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void receiveshow();//与发射的信号关联的槽

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

signals:
    void trashownum();//show tranum
    void quit();//退出

private:
    Ui::trachinese *ui;
};

#endif // TRACHINESE_H
