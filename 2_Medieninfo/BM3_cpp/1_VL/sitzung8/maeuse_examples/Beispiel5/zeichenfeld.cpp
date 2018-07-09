#include <QtGui>

#include "zeichenFeld.h"

zeichenFeld::zeichenFeld(QWidget *parent)
    : QWidget(parent)
{
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
    setMouseTracking(false);
}

zeichenFeld::~zeichenFeld()
{
    for (vector<QPoint *>::iterator pos=points.begin();pos!=points.end();pos++)
        delete *pos;
}

void zeichenFeld::paintEvent(QPaintEvent * )
{
    QPainter painter;
    vector<QPoint *>::iterator pos,start;

    painter.begin( this );
    painter.setPen( QPen(Qt::red, 3) );
    if (points.size()>1)
    {
        pos=points.begin();
        for(;;)
        {
            start=pos;
            pos++;
            if (pos==points.end()) break;
            painter.drawLine(**start,**pos);
        }
        painter.end();
    }
}

void zeichenFeld::mouseMoveEvent(QMouseEvent *event)
{
    QPoint *point;

    point=new QPoint;
    point->setX(event->x());
    point->setY(event->y());
    points.push_back(point);

    update();
}
