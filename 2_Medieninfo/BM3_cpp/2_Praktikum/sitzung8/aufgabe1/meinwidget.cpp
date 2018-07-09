#include <QtGui>
// nur notwendig, wenn Qt 5:
#include <QPushButton>
#include <QGridLayout>
#include <QSlider>
//Ende Qt 5
#include "meinWidget.h"

meinWidget::meinWidget(QWidget *parent)
    : QWidget(parent)
{
    /*
    QPushButton *quit = new QPushButton(tr("Ende"));
    quit->setFont(QFont("Arial", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QPushButton *redButton = new QPushButton(tr("Rot"));
    redButton->setFont(QFont("Arial", 18, QFont::Bold));
    connect(redButton, SIGNAL(clicked()), this, SLOT(redColor()));

    QPushButton *greenButton = new QPushButton(tr("Grün"));
    greenButton->setFont(QFont("Arial", 18, QFont::Bold));
    connect(greenButton, SIGNAL(clicked()), this, SLOT(greenColor()));

    QSlider *slider = new QSlider(Qt::Horizontal,this);
    slider->setFont(QFont("Arial", 18, QFont::Bold));
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setThickness(int)));
    */

    meinZeichenFeld = new zeichenFeld;

    QGridLayout *gridLayout = new QGridLayout;
    /*
    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addWidget(redButton, 1, 0);
    gridLayout->addWidget(greenButton, 2, 0);
    gridLayout->addWidget(slider, 3, 0);
    */
    gridLayout->addWidget(meinZeichenFeld, 0, 1, 4, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);
}
