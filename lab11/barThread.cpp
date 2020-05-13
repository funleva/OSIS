#include "barThread.h"
#include <unistd.h>
BarThread::BarThread(QSemaphore* s)
{
    semaphore = s;
}

void BarThread::run() {
    for (int i = 0; i < 100;) {
        if (semaphore->available()){
            semaphore->acquire();
            ++cnt;
            ++i;
            emit valueChanged(cnt);
            semaphore->release(); 
        }
        usleep(1e5);
    }
    cnt = 0;
}

void BarThread::reset() {
    cnt = 0;
    emit valueChanged(0);
}
