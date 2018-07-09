#include <QtGui>

#include "zeichenFeld.h"

zeichenFeld::zeichenFeld(QWidget *parent)
    : QWidget(parent)
{
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
    setMouseTracking(false);
    color=Qt::black;
    width=3;
}

zeichenFeld::~zeichenFeld()
{
    for (vector<struct myPoint *>::iterator pos=points.begin();pos!=points.end();pos++)
        delete *pos;
}

void zeichenFeld::paintEvent(QPaintEvent * )
{
    QPainter painter;
    vector<struct myPoint *>::iterator pos,start;

    painter.begin( this );
    if (points.size()>1)
    {
        pos=points.begin();
        for(;;)
        {
            start=pos;
            pos++;
            if (pos==points.end()) break;
            painter.setPen( QPen((*start)->color, (*start)->width)  );
            painter.drawLine((*start)->point,(*pos)->point);
        }
        painter.end();
    }
}

void zeichenFeld::mouseMoveEvent(QMouseEvent *event)
{
    struct myPoint *point;

    point=new struct myPoint;
    point->point.setX(event->x());
    point->point.setY(event->y());
    point->color=color;
    point->width=width;
    points.push_back(point);

    update();
}
