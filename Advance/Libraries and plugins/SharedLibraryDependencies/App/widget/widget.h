#ifndef WIDGET_H
#define WIDGET_H

#include "widget_global.h"
#include "server.h"

class WIDGET_EXPORT Widget
{
public:
    Widget();
    void start();
    void quit();

private:
    Server server;
};

#endif // WIDGET_H
