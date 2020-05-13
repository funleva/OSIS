#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>

#include <QtDebug>
#include <QPixmap>

static int j=0;
static bool isDraw = true;
static QPoint point[20];


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);
    label->show();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->setInterval(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeout(){
    label->move(label->pos().x() + dx, label->pos().y() + dy);
    kol++;
    if (kol % 2 == 0) {
        QImage *image = new QImage();
        image->load("/Users/newboba/lab9/image1.png");
        label->setPixmap(QPixmap::fromImage(*image));
    } else {
        QImage *image = new QImage();
        image->load("/Users/newboba/lab9/image2.png");
        label->setPixmap(QPixmap::fromImage(*image));
    }
    if (kol == 10) {
        timer->stop();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    timer->stop();
    QPoint pos = QWidget::mapFromGlobal(QCursor::pos());
    xx = pos.x();
    yy = pos.y();
    dx = (xx - label->pos().x()) / 10;
    dy = (yy - label->pos().y()) / 10;
    kol = 0;
    timer->start();
}
