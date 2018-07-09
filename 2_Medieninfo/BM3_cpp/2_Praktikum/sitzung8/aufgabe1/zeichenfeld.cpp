#include <QtGui>
#include "zeichenFeld.h"

zeichenFeld::zeichenFeld(QWidget *parent)
    : QWidget(parent)
{
    setPalette(QPalette(QColor(250, 250, 200)));
    setFixedSize(500, 500);
    setAutoFillBackground(true);
    setMouseTracking(false);
    color=Qt::black;
    width=3;

    x = 225;
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

    painter.drawRect(x, 225, 50, 50);
    /*if (points.size()>1)
    {
        pos=points.begin();
        for(;;)
        {
            start=pos;
            pos++;
            if (pos==points.end()) break;
            // definition mit welchen attributen geschrieben wird
            // farbe und breite
            painter.setPen( QPen((*start)->color, (*start)->width)  );
            // definition mit welchen attributen ne linie gemalt wird
            // vom startpunkt a zu endpunkt b
            //
            painter.drawLine((*start)->point,(*pos)->point);
        } */
        painter.end();
    }

void zeichenFeld::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        x -= 25;
    }

    if (event->button() == Qt::RightButton) {
        x += 25;
    }
    /* struct myPoint *point;

    point=new struct myPoint;
    // rückgabe der koordinaten von x
    point->point.setX(event->x());
    // rückgabe der koordinaten von y
    point->point.setY(event->y());
    point->color=color;
    point->width=width;
    // methode aus container
    points.push_back(point); */

    // löscht die alten daten und macht die neuen daten hin
    update();
}
