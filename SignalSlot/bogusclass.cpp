#include "bogusclass.h"

BogusClass::BogusClass(QObject *parent) : QObject(parent)
{

}

void BogusClass::emitt()
{
    emit Reactive::instance().signalTwo(2500);
}
