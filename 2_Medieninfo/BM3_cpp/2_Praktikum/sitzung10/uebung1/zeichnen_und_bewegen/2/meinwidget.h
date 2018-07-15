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
    void square(void);
    void circle(void);
    void killer(void);
};
