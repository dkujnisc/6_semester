// Qt5 add:
#include <QPushButton>
#include <QGridLayout>

#include <QtGui>
#include "meinWidget.h"

meinWidget::meinWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton(tr("Ende"));
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QPushButton *circleButton = new QPushButton(tr("Kreis"));
    circleButton->setFont(QFont("Times", 18, QFont::Bold));
    connect(circleButton, SIGNAL(clicked()), this, SLOT(circle()));

    QPushButton *squareButton = new QPushButton(tr("Quadrat"));
    squareButton->setFont(QFont("Times", 18, QFont::Bold));
    connect(squareButton, SIGNAL(clicked()), this, SLOT(square()));

    QPushButton *deleteButton = new QPushButton(tr("Löschen"));
    deleteButton->setFont(QFont("Times", 18, QFont::Bold));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(killer()));

    meinZeichenFeld = new zeichenFeld;

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addWidget(circleButton, 1, 0);
    gridLayout->addWidget(squareButton, 2, 0);
    gridLayout->addWidget(deleteButton, 3, 0);
    gridLayout->addWidget(meinZeichenFeld, 0, 1, 4, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);
}

void meinWidget::circle(void)
{
    meinZeichenFeld->placeObject(zeichenFeld::circle);
}

void meinWidget::square(void)
{
    meinZeichenFeld->placeObject(zeichenFeld::square);
}

void meinWidget::killer(void)
{
    meinZeichenFeld->findAndRemove();
}
