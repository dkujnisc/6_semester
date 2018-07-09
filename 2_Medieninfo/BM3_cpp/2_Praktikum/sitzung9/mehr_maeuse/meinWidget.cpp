#include <QtGui>
#include <QPushButton>
#include <QGridLayout>
#include <QFileDialog>
#include <QMessageBox>
#include "meinWidget.h"

meinWidget::meinWidget(QWidget *parent) : QWidget(parent)
{
    // hier nur erstellen der buttons
    QPushButton *quit = new QPushButton(tr("Ende"));
    quit->setFont(QFont("Arial", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QPushButton *speicherButton = new QPushButton(tr("Speichern"));
    speicherButton->setFont(QFont("Arial", 18, QFont::Bold));
    connect(speicherButton, SIGNAL(clicked()), this, SLOT(saveFile()));

    QPushButton *oeffnenButton = new QPushButton(tr("Öffnen"));
    oeffnenButton->setFont(QFont("Arial", 18, QFont::Bold));
    connect(oeffnenButton, SIGNAL(clicked()), this, SLOT(loadFile()));

    // hier nur erstellen des zeichenfeldes
    meinZeichenFeld->setFixedSize(500, 500);

    // alle formen, buttons, striche etc. werden hier ins Widget gepackt
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(speicherButton, 1, 0);
    gridLayout->addWidget(oeffnenButton, 2, 0);
    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addWidget(meinZeichenFeld,1, 2, 1, 1);
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

        meinZeichenFeld->serialize(file);
        file.close();
        return;
    }
}

void meinWidget::loadFile(void)
{
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getOpenFileName(this,
                                      tr("Speichern als"), ".", tr("Zeichnungen (*.myz)"));

    if (fileName.isNull()==false)
    {
        file.setFileName(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Dateifehler"),
                                 tr("Folgende Datei kann nicht geöffnet werden: ") + fileName,QMessageBox::Ok);
        }

        meinZeichenFeld->deserialize(file);
        file.close();
        return;
    }
}
