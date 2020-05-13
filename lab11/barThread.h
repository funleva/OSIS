#ifndef CUSTOMTHREAD_H
#define CUSTOMTHREAD_H

#include <QThread>
#include <QProgressBar>
#include <QSemaphore>
#include <QLabel>

class MyThread : public QThread
{
Q_OBJECT
public:
    MyThread(QLabel *label, int step);
    void run();
    void go();
    void stop();
private:
    QLabel *label;
    int step = 0;
    volatile bool isRun = false;
signals:
    void valueChanged(QLabel *label, int step);
};

#endif // CUSTOMTHREAD_H
