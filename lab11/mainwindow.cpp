#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "barThread.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    ui->progressBar->setRange(0, 100);
    barThread = new BarThread(semaphore);
    connect(barThread, SIGNAL(valueChanged(int)), this, SLOT(updateBar(int)));
    connect(barThread, SIGNAL(valueChanged(int)), this, SLOT(updatePercent(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_resetButton_clicked()
{
    if (semaphore->available())
        semaphore->acquire();
    ui->progressBar->setValue(0);
    barThread->reset();
    barThread->terminate();
}

void MainWindow::on_startButton_clicked()
{
    if(!semaphore->available())
        semaphore->release();
    if (!barThread->isRunning())
        barThread->start();
}

void MainWindow::on_pauseButton_clicked()
{
    if (semaphore->available())
        semaphore->acquire();
}


void MainWindow::updateBar(int cnt) {
    ui->progressBar->setValue(cnt);
}

void MainWindow::updatePercent(int cnt) {
    ui->statusPercents->setText(QString::number(cnt) + QString("%"));
}


