#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <secondwindow.h>
#include <QtDebug>
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
public slots:
    void onTimeout();
signals:
    void sendMessage(int figure, QColor* color, bool isDraw);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    SecondWindow *sw;
};
#endif // MAINWINDOW_H
