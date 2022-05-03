#include "serializejson.h"

SerializeJSON::SerializeJSON(QObject *parent) : QObject(parent)
{
    // Use this as
    // SerializeJSON::writeJson();
    // SerializeJSON::readJson();
}

void SerializeJSON::writeJson(Spider *obj, QString path)
{
    QVariantMap map;
    QVariantMap items;
    map["name"] = obj->name();

    foreach (QString key, obj->map().keys()) {
        items.insert(key, QVariant(obj->map().value(key)));
    }

    map["items"] = QVariant(items);

    QJsonDocument document = QJsonDocument::fromVariant(map);

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
        qCritical() << "Could not write file:";
        qCritical() << file.errorString();
        return;
    }

    file.write(document.toJson());
    file.close();
}

Spider *SerializeJSON::readJson(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Could not read file:";
        qCritical() << file.errorString();
        return nullptr;
    }
    QByteArray data = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(data);
    Spider *t = new Spider();

    t->setName(document["name"].toString());
    QVariantMap vmap = qvariant_cast<QVariantMap>(document["items"]);

    QMap<QString, QString> map;
    foreach (QString key, vmap.keys()) {
        map.insert(key, vmap[key].toString());
    }
    t->setMap(map);

    return t;
}
