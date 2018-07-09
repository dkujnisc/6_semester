// Qt5 add:
#include <QWidget>

#include "zeichenFeld.h"

class meinWidget : public QWidget
{
    Q_OBJECT  // notwendig, da Slots enthalten sind

public:
    meinWidget(QWidget *parent = 0);

private:
    zeichenFeld *meinZeichenFeld;

private slots:
    void redColor(void)
    {
        meinZeichenFeld->setColor(Qt::red);
    }
    void greenColor(void)
    {
        meinZeichenFeld->setColor(Qt::green);
    }
    void setThickness(int value)
    {
        meinZeichenFeld->setThickness(value);
    }
    void saveFile(void);
    void loadFile(void);
};
