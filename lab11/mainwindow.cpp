#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "barThread.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myThread1 = new MyThread(ui->label, 5);
    myThread2 = new MyThread(ui->label_2, 2);
    myThread3 = new MyThread(ui->label_3, 8);
    connect(myThread1, SIGNAL(valueChanged(QLabel*, int)), this, SLOT(updateLabel(QLabel*, int)));
    connect(myThread2, SIGNAL(valueChanged(QLabel*, int)), this, SLOT(updateLabel(QLabel*, int)));
    connect(myThread3, SIGNAL(valueChanged(QLabel*, int)), this, SLOT(updateLabel(QLabel*, int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    if (myThread1->isRunning() == false) {
        myThread1->start();
        myThread2->start();
        myThread3->start();
    }
    myThread1->go();
    myThread2->go();
    myThread3->go();
}

void MainWindow::on_pauseButton_clicked()
{
    myThread1->stop();
    myThread2->stop();
    myThread3->stop();
}


void MainWindow::updateLabel(QLabel *label, int step) {
    label->move(label->pos().x() + step, label->pos().y());
}
