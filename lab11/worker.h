#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT

public:
    explicit Worker(QObject *parent = 0);
    void abort();

private:
    bool _abort;
    bool _interrupt;
    QMutex mutex;



signals:
    void valueChanged(const QString &value);
    void finished();

public slots:
    void mainLoop();
};
#endif // WORKER_H
