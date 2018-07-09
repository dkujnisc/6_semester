#include <QWidget>

class zeichenFeld : public QWidget
{
Q_OBJECT
public:
    zeichenFeld(QWidget *parent = 0);

private:
    QPoint lastPoint;
    QPoint newPoint;
    int buttonPressed;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent( QMouseEvent* event);
};
