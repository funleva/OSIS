#ifndef COLORTHREAD_H
#define COLORTHREAD_H

#include <QMainWindow>
#include <QGraphicsScene>

class colorThread : public QObject
{
Q_OBJECT
public:
    colorThread(QGraphicsScene *scene,Qt::GlobalColor color);
    Qt::GlobalColor color;
    QGraphicsScene *sc;
public slots:
    void changeColor();
signals:
    void send();
};

#endif // COLORTHREAD_H
