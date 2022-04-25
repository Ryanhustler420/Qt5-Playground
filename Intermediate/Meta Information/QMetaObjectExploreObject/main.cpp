#include <QCoreApplication>
#include <QDebug>
#include <QMetaMethod>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaClassInfo>
#include <QTimer>
#include "test.h"

void listProperties(QObject *obj) {
    for (int var = 0; var < obj->metaObject()->propertyCount(); ++var) {
        QMetaProperty p = obj->metaObject()->property(var);
        qInfo() << "Property: " << p.name() << " is a " << p.typeName();
    }
}

void listMethod(QObject *obj) {
    for (int var = 0; var < obj->metaObject()->methodCount(); ++var) {
        QMetaMethod m = obj->metaObject()->method(var);
        qInfo() << "Method: " << m.methodSignature();
    }
}

void listChildren(QObject *obj) {
    qInfo() << "Object: " << obj;

    foreach (QObject *c, obj->children()) {
        qInfo() << c;
        listMethod(c);
        listProperties(c);
        qInfo("");
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject parent;
    QTimer *t = new QTimer(&parent);

    // make some children
    for (int var = 0; var < 5; ++var) {
        test *t = new test(&parent);
        t->setObjectName("Child: " + QString::number(var));
    }

    listChildren(&parent);

    return a.exec();
}
