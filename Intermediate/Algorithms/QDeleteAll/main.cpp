#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QtAlgorithms>
#include "test.h"

// qDeleteAll

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<test*> list;
    for (int var = 0; var < 10; ++var) {
        test * t =new test(); // notice there is no parent!!!
        t->setObjectName(QString::number(var));
        list.append(t);
    }

    qInfo() << list.at(0);

    // Delete them all i.e ponters in memory!
    qDeleteAll(list); // simple macro, basically a for loop, but nice one liner

    // Will crash!
    // qInfo() << list.at(0);

    // Objects are still in the list but invalid pointers - clear rhw list
    list.clear();

    return a.exec();
}
