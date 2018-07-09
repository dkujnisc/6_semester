#include <QWidget>

class zeichenFeld : public QWidget
{
Q_OBJECT
public:
    zeichenFeld(QWidget *parent = 0);

private:
    int x, y;
    int buttonPressed;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent( QMouseEvent* event);
};
