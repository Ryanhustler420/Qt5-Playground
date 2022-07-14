#include "commonsuperclass.h"

CommonSuperClass::CommonSuperClass(QObject *parent) : QObject(parent)
{

}

void CommonSuperClass::listClassInfo(QObject *obj)
{
    qInfo() << obj->metaObject()->className();
    for (int var = 0; var < obj->metaObject()->classInfoCount(); ++var) {
        QMetaClassInfo c = obj->metaObject()->classInfo(var);
        qInfo() << "Property: " << c.name() << " = " << c.value();
    }
}

void CommonSuperClass::listProperties(QObject *obj) {
    for (int var = 0; var < obj->metaObject()->propertyCount(); ++var) {
        QMetaProperty p = obj->metaObject()->property(var);
        qInfo() << "Property: " << p.name() << " is a " << p.typeName();
    }
}

void CommonSuperClass::listMethod(QObject *obj) {
    for (int var = 0; var < obj->metaObject()->methodCount(); ++var) {
        QMetaMethod m = obj->metaObject()->method(var);
        qInfo() << "Method: " << m.methodSignature();
    }
}

void CommonSuperClass::listChildren(QObject *obj) {
    qInfo() << "Object: " << obj;
    foreach (QObject *c, obj->children()) {
        qInfo() << c;
        listMethod(c);
        listProperties(c);
    }
}

void CommonSuperClass::modifyProperty(QObject *parent, QString name, QVariant value) {
    foreach (QObject *child, parent->children()) {
        child->setProperty(name.toLatin1(), value);
    }
}
