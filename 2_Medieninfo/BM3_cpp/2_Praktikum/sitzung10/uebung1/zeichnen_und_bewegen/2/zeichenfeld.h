#include <vector>
using namespace std;
#include <QWidget>


class zeichenFeld : public QWidget
{
public:
    zeichenFeld(QWidget *parent = 0);
    ~zeichenFeld();

    enum drawType { square, circle };

    void placeObject(enum drawType useType);
    void findAndRemove(void);

private:
    vector<struct myDrawingObject *> objects;
    int lastX;
    int lastY;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent( QMouseEvent* event);
};

struct myDrawingObject
{
    zeichenFeld::drawType type;
    int x;
    int y;
} ;
