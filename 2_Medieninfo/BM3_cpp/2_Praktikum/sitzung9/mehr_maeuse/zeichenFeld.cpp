#include <QtGui>
#include <QMessageBox>
#include "zeichenFeld.h"

QPainter painter;
 
zeichenFeld::zeichenFeld(QWidget *parent) : QWidget(parent)
{
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
}

void zeichenFeld::paintEvent(QPaintEvent *event)
{
    painter.begin(this);
    painter.setPen(QPen(Qt::red, 3));
    painter.drawRect(x, y, 50, 50);
    painter.end();
}

void zeichenFeld::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if(x>=25)
          x = x - 25;
        update();
    }

    if (event->button() == Qt::RightButton)
    {
        if(x<450)
          x = x + 25;
        update();
    }
}

// anlegen der methode serialize
void zeichenFeld::serialize(QFile &file)
{
    // aus dem programm in eine datei
    QTextStream out(&file);
    out << "MeinZeichnungsFormat" << endl;
    out  << "p "
             << x << " " << y << endl;

}

// anlegen der methode deserialize
void zeichenFeld::deserialize(QFile &file)
{
    char c;
    QString test;

    // von der datei in das programm
    QTextStream in(&file);

    in >> test;
    if (test != "MeinZeichnungsFormat")
    {
        QMessageBox::warning(this, tr("Formatfehler"),
                             tr("Das ist keine Zeichnungsdatei!"),QMessageBox::Ok);
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

        in >> x >> y;

        in >> c; // Leerstellen werden vom '>>' Operator 'konmsumiert';
        // Zeilenenden nicht.

    }

    update();
}
