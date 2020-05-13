#include "worker.h"

void Worker::mainLoop()
{
    forever {

        mutex.lock();
        _interrupt = false;
        if (_abort) {
            emit finished();
            return;
        }
        progressBar->setValue(progressBar->value() + 1);
         mutex.unlock();
    }
}
