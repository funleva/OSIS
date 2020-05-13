#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QColor>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    void virtual paintEvent(QPaintEvent *event);
    int figure;
    QColor* color;
public slots:
    void GetMessage(int figure, QColor* color, bool isDraw);

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
