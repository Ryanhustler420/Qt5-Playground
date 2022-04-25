#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test *p = new test(nullptr); // should have a parent &a, if left nullptr  then that might cause pointer in memory and never gets removed
    p->setObjectName("parent");

    for (int var = 0; var < 5; ++var) {
        p->makeChild(QString::number(var));
    }

    // delete p;

    return a.exec();
}
