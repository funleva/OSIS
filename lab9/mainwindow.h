#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QImage>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void virtual mousePressEvent(QMouseEvent *event);
public slots:
    void onTimeout();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QLabel *label;
    int xx,yy,dx,dy,kol;
};
#endif // MAINWINDOW_H
