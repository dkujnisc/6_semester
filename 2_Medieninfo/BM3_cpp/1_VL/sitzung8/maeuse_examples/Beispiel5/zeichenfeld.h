#include <vector>
using namespace std;
#include <QWidget>

class zeichenFeld : public QWidget
{
    Q_OBJECT
public:
    zeichenFeld(QWidget *parent = 0);
    ~zeichenFeld();

private:
    vector<QPoint *> points;

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent( QMouseEvent* event);
};
