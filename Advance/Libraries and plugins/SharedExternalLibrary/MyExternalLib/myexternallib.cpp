#include "myexternallib.h"

MyExternalLib::MyExternalLib()
{
}

void MyExternalLib::greet(QString name)
{
    qInfo() << "Ehllo, " << name;
}
