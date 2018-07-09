#include <QWidget>

class zeichenFeld : public QWidget
{
    Q_OBJECT
public:
    zeichenFeld(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};
