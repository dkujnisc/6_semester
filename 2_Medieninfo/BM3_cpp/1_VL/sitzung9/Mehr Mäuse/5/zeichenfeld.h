#include <vector>
using namespace std;
#include <QWidget>
#include <QFile>

struct myPoint
{
    QPoint point;
    int width;
    QColor color;
} ;

class zeichenFeld : public QWidget
{
public:
    zeichenFeld(QWidget *parent = 0);
    ~zeichenFeld();

    void setColor(QColor useColor) { color=useColor; } ;
    void setThickness(int useWidth) { width=useWidth; } ;
    void serialize(QFile &file);
    void deserialize(QFile &file);

private:
    vector<struct myPoint *> points;
    QColor color;
    int width;

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent( QMouseEvent* event);
};
