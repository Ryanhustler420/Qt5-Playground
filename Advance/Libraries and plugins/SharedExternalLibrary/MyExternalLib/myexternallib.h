#ifndef MYEXTERNALLIB_H
#define MYEXTERNALLIB_H

#include "MyExternalLib_global.h"
#include <QDebug>

class MYEXTERNALLIB_EXPORT MyExternalLib
{
public:
    MyExternalLib();

    void greet(QString name);
};

#endif // MYEXTERNALLIB_H
