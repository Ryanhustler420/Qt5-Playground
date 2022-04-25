#include <QCoreApplication>

#include <QDebug>
#include "../widget/widget_global.h"
#include "../widget/widget.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Widget widget;
    widget.start();
    // widget.quit();

    return a.exec();
}
