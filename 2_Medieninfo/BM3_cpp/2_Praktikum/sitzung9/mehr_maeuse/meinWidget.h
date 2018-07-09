#include <QWidget>
#include "zeichenFeld.h"

class meinWidget : public QWidget
{
     Q_OBJECT

    private:
    zeichenFeld *meinZeichenFeld = new zeichenFeld;
 
    public:
    meinWidget(QWidget *parent = 0);

private slots:
    void saveFile (void);
    void loadFile (void);
};
