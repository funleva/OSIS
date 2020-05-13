#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_inputText_returnPressed();

    void on_startButton_clicked();

    void on_stopButton_clicked();
    void move();

private:
    bool stopped = false;
    int len;
    int hei;
    QTimer *timer;
    int pos = 0;
    QPropertyAnimation *animation;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
