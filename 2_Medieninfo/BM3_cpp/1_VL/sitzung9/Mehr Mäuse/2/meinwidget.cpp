#include <QtGui>
// Qt 5 add start
#include <QPushButton>
#include <QGridLayout>
#include <QSlider>
#include <QFileDialog>
#include <QMessageBox>
// Qt 5 add end
#include "meinWidget.h"

meinWidget::meinWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton(tr("Ende"));
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    QPushButton *redButton = new QPushButton(tr("Rot"));
    redButton->setFont(QFont("Times", 18, QFont::Bold));
    connect(redButton, SIGNAL(clicked()), this, SLOT(redColor()));
    QPushButton *greenButton = new QPushButton(tr("Grün"));
    greenButton->setFont(QFont("Times", 18, QFont::Bold));
    connect(greenButton, SIGNAL(clicked()), this, SLOT(greenColor()));
    QSlider *slider = new QSlider(Qt::Horizontal,this);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setThickness(int)));
    QPushButton *saver = new QPushButton(tr("Sichern"));
    saver->setFont(QFont("Times", 18, QFont::Bold));
    connect(saver, SIGNAL(clicked()), this, SLOT(saveFile()));

    meinZeichenFeld = new zeichenFeld;

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addWidget(redButton, 1, 0);
    gridLayout->addWidget(greenButton, 2, 0);
    gridLayout->addWidget(slider, 3, 0);
    gridLayout->addWidget(saver, 4, 0);
    gridLayout->addWidget(meinZeichenFeld, 0, 1, 5, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);
}

void meinWidget::saveFile(void)
{
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getSaveFileName(this,
                                      tr("Speichern als"), ".", tr("Zeichnungen (*.myz)"));

    if (fileName.isNull()==false)
    {
        file.setFileName(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Dateifehler"),
                                 tr("Folgende Datei kann nicht verwendet werden: ") + fileName,QMessageBox::Ok);
        }
        file.close();
        return;
    }
}
