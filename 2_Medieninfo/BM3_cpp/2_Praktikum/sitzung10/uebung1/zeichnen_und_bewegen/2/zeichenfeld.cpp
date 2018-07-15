#include <QtGui>
#include <math.h>

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
    for (vector<struct myDrawingObject *>::iterator pos=objects.begin();pos!=objects.end();pos++)
        delete *pos;
}

void zeichenFeld::paintEvent(QPaintEvent * )
{
    QPainter painter;
    vector<struct myDrawingObject *>::iterator pos;
    int x,y,width,height;

    painter.begin( this );
    for (pos=objects.begin();pos!=objects.end();pos++)
        switch((*pos)->type)
        {
        case circle:
            //linke obere Ecke: Breite == Hoehe == 50
            x=(*pos)->x-25;
            y=(*pos)->y-25;
            painter.drawEllipse(x,y,50,50);
            break;
        case square:
            //linke obere Ecke: Breite == Hoehe == 50
            x=(*pos)->x-25;
            y=(*pos)->y-25;
            painter.drawRect(x,y,50,50);
            break;
        }
    painter.end();
}

void zeichenFeld::mousePressEvent(QMouseEvent *event)
{
    lastX = event->x();
    lastY = event->y();
}

void zeichenFeld::placeObject(enum drawType useType)
{
    struct myDrawingObject *object;

    object=new myDrawingObject;
    object->type = useType;
    object->x=lastX;
    object->y=lastY;

    objects.push_back(object);

    update();
}

void zeichenFeld::findAndRemove(void)
{
    float minimum = 99999999, jetzt;
    int xDiff, yDiff;
    vector<struct myDrawingObject *>::iterator pos, victim;

    if (objects.size()==0) return;

    for (pos=objects.begin();pos!=objects.end();pos++)
    {
        xDiff=(*pos)->x - lastX;
        yDiff=(*pos)->y - lastY;
        // Pythagorean theorem:
        jetzt= sqrt((float) (xDiff * xDiff + yDiff * yDiff) );
        if (jetzt < minimum)
        {
            minimum=jetzt;
            victim = pos;
        }
    }

    objects.erase(victim);

    update();
}
