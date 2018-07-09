#include <QPainter>

#include "zeichenFeld.h"

zeichenFeld::zeichenFeld(QWidget *parent)
    : QWidget(parent)
{
    setPalette(QPalette(QColor(250, 50, 200)));
    setAutoFillBackground(true);
}

void zeichenFeld::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawText(10, 10,tr("Hello World!"));
}
