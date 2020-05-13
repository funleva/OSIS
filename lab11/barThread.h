#ifndef CUSTOMTHREAD_H
#define CUSTOMTHREAD_H

#include <QThread>
#include <QProgressBar>
#include <QSemaphore>

class BarThread : public QThread
{
Q_OBJECT
public:
    BarThread(QSemaphore* s);
    void run();
    void reset();
private:
    QSemaphore *semaphore;
    volatile int cnt = 0;
signals:
    void valueChanged(int);
};

#endif // CUSTOMTHREAD_H
