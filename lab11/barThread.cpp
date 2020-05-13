#include "barThread.h"
#include <unistd.h>
MyThread::MyThread(QLabel *label, int step)
{
    this->label = label;
    this->step = step;
}

void MyThread::run() {
    while (isRun) {
        emit valueChanged(label, step);
        usleep(1e5);
    }
}

void MyThread::go() {
    isRun = true;
}

void MyThread::stop() {
    isRun = false;
}
