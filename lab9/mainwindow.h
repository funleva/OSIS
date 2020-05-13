#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void virtual paintEvent(QPaintEvent *event);
public slots:
    void onTimeout();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
};
#endif // MAINWINDOW_H
