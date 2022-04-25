#include <QCoreApplication>

#include <QDebug>
#include <QSharedPointer>

#include "test.h"
#include "consumer.h"

// The QSharedPointer will dlete the pointer it is holding when it goes out of scope,
// provided no other QSharedPointer objects are referencing it.

// It very similer to QScopePointer like when it goes outside scope it gets delete from memory,
// However, sometime other objects uses that pointer so it wait to see if no other objects are using that pointer,
// only in that case it wipes that out from memory

void whenDelete(test *obj) {
    qInfo() << "Deleting: " << obj;
    obj->deleteLater();
}

QSharedPointer<test> createPointer() {
    test *t = new test(); // the bad way!!! i.e (creating on the heap)
    t->setObjectName("Test Object");
    QSharedPointer<test> p(t, whenDelete);
    return p;
}

void doStuff(QSharedPointer<consumer> ptr) {
    qInfo() << "In function: " << ptr.data()->tester;
    ptr.clear(); // Does not autually deleted!, just removes the reference
}

QSharedPointer<consumer> makeConsumer() {
    QSharedPointer<consumer> c(new consumer, &QObject::deleteLater);
    QSharedPointer<test> t = createPointer();

    c.data()->tester.swap(t);
    doStuff(c);

    return c;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSharedPointer<consumer> consume = makeConsumer();
    qInfo() << "In main: " << consume.data()->tester;

    consume.clear(); // Does not autually deleted!, just removes the reference

    return a.exec();
}
