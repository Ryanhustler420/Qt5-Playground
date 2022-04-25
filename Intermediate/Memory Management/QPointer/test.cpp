#include "test.h"

test::test(QObject *parent) : QObject(parent)
{

}

test::~test()
{

}

void test::useWIdget()
{
    // see if there is a pointer!
    if (!widget.data()) {
        qInfo() << "No Pointer!!!";
        return;
    }

    qInfo() << "Widget = " << widget.data();

    // Access the pointer
    widget.data()->setObjectName("used Widget!");
}
