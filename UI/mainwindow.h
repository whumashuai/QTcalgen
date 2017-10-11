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
    void on_pushButton_clicked();//simchinese

    void on_pushButton_2_clicked();//trachinese

    void on_pushButton_3_clicked();//english

    void on_pushButton_4_clicked();//exit

    void receivereturn();//The signal is associated with the slot

private:
    Ui::MainWindow *ui;

signals:
    void quit();//exit
    void signalsim();//Display Simplified Chinese interface signal
    void signaltra();//Display Traditional Chinese interface signal
    void signalEng();//Display English interface signal
};

#endif // MAINWINDOW_H
