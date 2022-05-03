#include "serializeclass.h"

SerializeClass::SerializeClass(QObject *parent) : QObject(parent)
{

}

bool SerializeClass::saveFile(Jocker *t, QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) return false;

    QDataStream ds(&file);
    ds.setVersion(QDataStream::Qt_5_11);

    // order matters here
    // ds << t->name();
    // ds << t->map();
    // or
    ds << *t;

    file.close();
    return true;
}

bool SerializeClass::loadFile(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) return false;

    QDataStream ds(&file);
    Jocker t;
    ds >> t;

    file.close();

    qInfo() << "Name: " << t.name();
    foreach (QString key, t.map()) {
        qInfo() << key << " : " << t.map().value(key);
    }

    return true;
}
