#include <QCoreApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaClassInfo>
#include <QMetaMethod>
#include <QTimer>
#include <QVariant>

void listProperties(QObject *obj) {
    for (int var = 0; var < obj->metaObject()->propertyCount(); ++var) {
        QMetaProperty p = obj->metaObject()->property(var);
        qInfo() << "Property: " << p.name() << " is a " << p.typeName() << " = " << p.read(obj);
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

void testProp(QObject *parent, QString name, QVariant value) {
    foreach (QObject *child, parent->children()) {
        child->setProperty(name.toLatin1(), value);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject parent;
    QTimer *t = new QTimer(&parent);

    testProp(&parent, "interval", 3000);
    testProp(&parent, "remainingTime2", -2); // won't work, because there is no such property present in timer class

    listChildren(&parent);

    return a.exec();
}
