#include <QApplication>
#include "meinWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    meinWidget widget;
    widget.setGeometry(1200, 100, 500, 355);
    widget.show();
    return app.exec();
}
