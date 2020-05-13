#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QThread>
#include <QLabel>
#include <QSemaphore>
#include <barThread.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
private slots:
    void on_startButton_clicked();
    void on_pauseButton_clicked();
    void updateLabel(QLabel *label, int step);
private:
    Ui::MainWindow *ui;
    MyThread *myThread1;
    MyThread *myThread2;
    MyThread *myThread3;

};
#endif // MAINWINDOW_H
