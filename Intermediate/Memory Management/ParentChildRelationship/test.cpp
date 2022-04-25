#include "test.h"

test::test(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Constructed";
}

test::~test()
{
    qInfo() << this << "Deconstructed";
}

void test::makeChild(QString name)
{
    test *child = new test(this);
    child->setObjectName(name);
}
