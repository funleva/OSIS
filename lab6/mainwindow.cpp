#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

static QLabel *label;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionstart_triggered()
{
    if (label == nullptr) {
        label = new QLabel("text", this);
        label->setAlignment(Qt::AlignCenter);
        label->setGeometry(0, this->height() / 2, 60, 60);
        label->show();
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    }
    timer->start(100);
}

void MainWindow::on_actionstop_triggered()
{
    timer->stop();
}

void MainWindow::slotTimerAlarm() {
    label->move(label->pos().x() + 5, label->pos().y());
}
