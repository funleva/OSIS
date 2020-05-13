#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

//! [0]
class RenderArea : public QWidget
{
    Q_OBJECT

public:
    enum Shape { Line, Points, Polyline, Polygon, Rect, RoundedRect, Ellipse, Arc,
                 Chord, Pie, Path, Text, Pixmap, Clear };

    RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;
};
//! [0]

#endif // RENDERAREA_H
