#include <QtGui>
// Qt5 add:
#include <QMessageBox>

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

void zeichenFeld::serialize(QFile &file)
{
    vector<struct myPoint *>::iterator pos;

    QTextStream out(&file);

    out << "MeinZeichnungsFormat" << endl;

    for (pos=points.begin();pos!=points.end();pos++)
    {
        out  << "p "
             << (*pos)->color.red() << " " << (*pos)->color.green() << " "
             << (*pos)->color.blue() << " " << (*pos)->width << " "
             << (*pos)->point.x() << " " << (*pos)->point.y() << endl;
    }
}

void zeichenFeld::deserialize(QFile &file)
{
    struct myPoint *point;
    char c;
    QString test;
    int red, green, blue, x, y;

    QTextStream in(&file);

    in >> test;
    if (test != "MeinZeichnungsFormat")
    {
        QMessageBox::warning(this, tr("Formatfehler"),
                             tr("Das ist keine Zechnungsdatei!"),QMessageBox::Ok);
        return;
    }

    in >> c; // Leerstellen werden vom '>>' Operator 'konmsumiert';
    // Zeilenenden nicht.

    while (in.status() == QTextStream::Ok)
    {
        in >> c;
        if (in.status() == QTextStream::ReadPastEnd) break;

        if (c!='p')
        {
            QMessageBox::warning(this, tr("Objektfehler"),
                                 tr("Folgender Objekttyp ist unbekannt: ") + c,QMessageBox::Ok);
            return;
        }
        point=new struct myPoint;

        in >> red >> green >> blue;
        point->color.setRgb(red,green,blue);
        in >> point->width;
        in >> x >> y;
        point->point.setX(x);
        point->point.setY(y);

        in >> c; // Leerstellen werden vom '>>' Operator 'konmsumiert';
        // Zeilenenden nicht.

        points.push_back(point);
    }

    update();
}
