#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>

#include <QtDebug>

static int j=0;
static bool isDraw = true;
static QPoint point[20];


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->setInterval(10);
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeout(){

    j = (j + 2) % 255;

    QPoint pos = QWidget::mapFromGlobal(QCursor::pos()) - QPoint(16,16);
    for (int i = 19; i >= 1; i--){
        point[i] = point[i-1];
    }
    point[0] = pos;
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event) {
    if(isDraw)
    {
        QPainter *paint = new QPainter(this);

        paint->setPen(QPen(Qt::black, 0));
        paint->setRenderHint(QPainter::Antialiasing, true);

        paint->setBrush(QBrush(QColor::fromHsv(j,255, 255), Qt::SolidPattern));

        for ( int i = 0; i < 20; i++){
            paint->drawEllipse(point[i].x(), point[i].y(), 32, 32);
        }
        paint->end();
    }
}
