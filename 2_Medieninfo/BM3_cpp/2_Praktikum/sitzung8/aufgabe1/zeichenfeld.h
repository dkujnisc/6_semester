#include <vector>
using namespace std;
#include <QWidget>

struct myPoint
   {
    // 3 informationen
    // punkt
   QPoint point;
   // breite
   int width;
   // farbe
   QColor color;
   } ;

class zeichenFeld : public QWidget
{
public:
    zeichenFeld(QWidget *parent = 0);
    ~zeichenFeld();

    void setColor(QColor useColor) { color=useColor; }
    void setThickness(int useWidth) { width=useWidth; }

private:
    // vector ist container, wie array
    // pointer struct von myPoint
    vector<struct myPoint *> points;
    QColor color;
    int width;

    int x;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent( QMouseEvent* event);
};
