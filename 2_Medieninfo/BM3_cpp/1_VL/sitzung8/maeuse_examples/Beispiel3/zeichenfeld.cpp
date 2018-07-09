#include <QtGui>

#include "zeichenFeld.h"

zeichenFeld::zeichenFeld(QWidget *parent)
    : QWidget(parent)
{
    lastPoint.setX(-1);
    lastPoint.setY(-1);
    newPoint.setX(-1);
    newPoint.setY(-1);
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
}

void zeichenFeld::paintEvent(QPaintEvent * )
{
    QPainter painter;

    if (lastPoint.x()>=0)
    {
        painter.begin( this );
        painter.setPen( QPen(Qt::red, 3) );
        painter.drawLine(lastPoint,newPoint);
        painter.end();
    }

    lastPoint.setX(newPoint.x());
    lastPoint.setY(newPoint.y());
}

void zeichenFeld::mousePressEvent(QMouseEvent *event)
{
    newPoint.setX(event->x());
    newPoint.setY(event->y());

    update();
}
