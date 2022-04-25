#include "counter.h"

counter::counter(QObject *parent) : QObject(parent)
{

}

void counter::start()
{
    for (int var = 0; var < 20; ++var) {
        qInfo() << QThread::currentThread()->objectName() << " = " << var;
        auto value = static_cast<unsigned long>(QRandomGenerator::global()->bounded(500));
        QThread::currentThread()->msleep(value);
    }
    QThread::currentThread()->quit();
}
