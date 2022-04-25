#include "widget.h"

Widget::Widget()
{
}

void Widget::start()
{
    server.start();
}

void Widget::quit()
{
    server.quit();
}
