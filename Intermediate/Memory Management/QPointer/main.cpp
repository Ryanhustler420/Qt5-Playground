#include <QCoreApplication>

// QPointer is one step closer to use SMART POINTER

// The QPointer class is a template class that provides guarded pointer to QObject.
// Remember we might not control the pointer in the consumer class

#include <QDebug>
#include <QPointer>

#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Its a pointer on the heap which not gonna delete itself even if the program ends
    QObject *obj = new QObject(nullptr);
    obj->setObjectName("my object");

    // We wrap that pointer with QPointer class
    QPointer<QObject> p(obj);

    test t;
    t.widget = p; // we handed over / copied the QPointer to our test instance class
    t.useWIdget();

    if (p.data()) qInfo() << p.data();

    delete obj;
    t.useWIdget();

    return a.exec();
}
