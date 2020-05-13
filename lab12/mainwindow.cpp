#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *sc = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(sc);

    color1 = new colorThread(sc, Qt::red);
    color2 = new colorThread(sc, Qt::blue);
    color3 = new colorThread(sc, Qt::green);

    color1->moveToThread(thread1);
    color2->moveToThread(thread2);
    color3->moveToThread(thread3);

    connect(thread1, SIGNAL(started()), color1, SLOT(changeColor()));
    connect(thread2, SIGNAL(started()), color2, SLOT(changeColor()));
    connect(thread3, SIGNAL(started()), color3, SLOT(changeColor()));

    connect(color1, SIGNAL(send()), this, SLOT(updateCol()));
    connect(color2, SIGNAL(send()), this, SLOT(updateCol()));
    connect(color3, SIGNAL(send()), this, SLOT(updateCol()));

    thread1->start();
    thread2->start();
    thread3->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCol() {
        qDebug() << "repaint";
        repaint();
}
