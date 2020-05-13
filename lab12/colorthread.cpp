#include "colorthread.h"
#include <unistd.h>
#include <QDebug>

colorThread::colorThread(QGraphicsScene *scene, Qt::GlobalColor color) : sc(scene)
{
    this->color = color;
}

void colorThread::changeColor() {
    forever {
        sc->setBackgroundBrush(QBrush(color));
        emit send();
        qDebug() << "send";
        usleep(1e6);
    }
}
