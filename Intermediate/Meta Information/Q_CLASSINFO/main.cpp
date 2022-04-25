#include <QCoreApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaClassInfo>
#include <QMetaMethod>
#include <QVariant>
#include "test.h"

void listClassInfo(QObject * obj) {
    qInfo() << obj->metaObject()->className();
    for (int var = 0; var < obj->metaObject()->classInfoCount(); ++var) {
        QMetaClassInfo c = obj->metaObject()->classInfo(var);
        qInfo() << "Property: " << c.name() << " = " << c.value();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test t;
    listClassInfo(&t);

    return a.exec();
}
