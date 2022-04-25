#include "cat.h"

Cat::Cat(QObject *parent) : QObject(parent)
{
    qInfo() << "test";
}

void Cat::meow()
{
    qInfo() << "meow";
}

void Cat::sleep()
{
    qInfo() << "sleep";
}

void Cat::speak(QString value)
{
    qInfo() << "speak: " << value;
}
