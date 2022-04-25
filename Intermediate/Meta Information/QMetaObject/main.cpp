#include <QCoreApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaClassInfo>
#include <QTimer>
#include "test.h"

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

    foreach (QObject *c, parent.children()) {
        qInfo() << c;
        qInfo() << c->metaObject()->className();
        qInfo() << "Inherits: " << c->inherits("test");

        for (int var = 0; var < c->metaObject()->methodCount(); ++var) {
            qInfo() << "Method: " << c->metaObject()->method(var).methodSignature();
        }
        qInfo("");
    }

    return a.exec();
}
