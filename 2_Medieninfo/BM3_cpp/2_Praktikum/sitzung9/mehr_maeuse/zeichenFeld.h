#include <QWidget>
#include <QFile>
 
class zeichenFeld : public QWidget
{
    Q_OBJECT

    public:
    zeichenFeld(QWidget *parent = 0);
    void serialize (QFile &file);
    void deserialize (QFile &file);

    private:
    int x=225, y=225;

    protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent* event);
};
