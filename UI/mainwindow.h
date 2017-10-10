#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

     void receivereturn();//与发射的信号关联的槽

private:
    Ui::MainWindow *ui;

signals:
    void quit();//退出信号
    void signalsim();//显示中文简体界面信号
    void signaltra();//显示中文繁体界面信号
    void signalEng();//显示英文界面信号
};

#endif // MAINWINDOW_H
