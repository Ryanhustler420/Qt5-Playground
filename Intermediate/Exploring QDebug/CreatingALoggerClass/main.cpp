#include <QCoreApplication>
#include <QDebug>
#include "test.h"
#include "logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "File: " << logger::filename;
    logger::attach();

    qInfo() << "test!";
    logger::logging = false;

    qInfo() << "Dont log this!";
    logger::logging = true;

    test t;
    t.run();

    qInfo() << "finished!";

    return a.exec();
}
