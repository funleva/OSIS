#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    timer->setInterval(500);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->actionText->setText(ui->inputText->text());
}

void MainWindow::on_inputText_returnPressed()
{
    ui->actionText->setText(ui->inputText->text());
}

void MainWindow::on_startButton_clicked()
{
    stopped = false;
    timer->start();
}

void MainWindow::on_stopButton_clicked()
{

    len = abs(ui->actionText->geometry().right() - ui->actionText->geometry().left());
    hei = abs(ui->actionText->geometry().top() - ui->actionText->geometry().bottom());
    stopped = true;
    animation->stop();
}

void MainWindow::move() {
    if (!stopped){
        animation = new QPropertyAnimation(ui->actionText, "pos");
        animation->setDuration(2000);
        animation->setStartValue(ui->actionText->pos());
        switch (pos) {
            case 0:
                animation->setEndValue(QPoint(ui->moveBox->geometry().right(), ui->moveBox->geometry().top()));
                ++pos;
                break;
            case 1:
                animation->setEndValue(QPoint(ui->moveBox->geometry().right(), ui->moveBox->geometry().bottom()));
                ++pos;
                break;
            case 2:
                animation->setEndValue(QPoint(ui->moveBox->geometry().left(), ui->moveBox->geometry().bottom()));
                ++pos;
                break;
            case 3:
                animation->setEndValue(QPoint(ui->moveBox->geometry().left(), ui->moveBox->geometry().top()));
                pos = 0;
                break;
            default:
                pos = 0;
                break;
        }
        animation->start();
    }
}
