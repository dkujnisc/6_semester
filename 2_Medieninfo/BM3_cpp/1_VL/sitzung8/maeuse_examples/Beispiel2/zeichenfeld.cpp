#include <QtGui>

#include "zeichenFeld.h"

zeichenFeld::zeichenFeld(QWidget *parent)
    : QWidget(parent)
{
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
}

void zeichenFeld::paintEvent(QPaintEvent *event )
{
    QPainter painter;

    painter.begin( this );
    if( buttonPressed == Qt::LeftButton ) painter.setPen( QPen(Qt::red, 3) );
    else painter.setPen( QPen(Qt::blue, 3) );
    painter.drawPoint(x, y);
    painter.end();
}

void zeichenFeld::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        x = event->x();
        y = event->y();
        buttonPressed = Qt::LeftButton;
        update();
    }

    if (event->button() == Qt::RightButton)
    {
        x = event->x();
        y = event->y();
        buttonPressed = Qt::RightButton;
        update();
    }
}
