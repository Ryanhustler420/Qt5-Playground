#include <QCoreApplication>
#include "test.h"

// QT += concurrent

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test test;
    test.process();

    return a.exec();
}
