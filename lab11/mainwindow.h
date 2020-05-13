#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QThread>
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
    QSemaphore *semaphore = new QSemaphore();

public slots:
    void on_resetButton_clicked();
private slots:
    void on_startButton_clicked();
    void on_pauseButton_clicked();
    void updateBar(int cur);
    void updatePercent(int cur);
private:
    Ui::MainWindow *ui;
    BarThread *barThread;

};
#endif // MAINWINDOW_H
