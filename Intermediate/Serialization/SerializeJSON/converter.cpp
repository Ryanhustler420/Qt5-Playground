#include "converter.h"

converter::converter(QObject *parent) : QObject(parent)
{

}

void converter::writeJson(test *obj, QString path)
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

test *converter::readJson(QString path)
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
    test *t = new test();

    t->setName(document["name"].toString());
    QVariantMap vmap = qvariant_cast<QVariantMap>(document["items"]);

    QMap<QString, QString> map;
    foreach (QString key, vmap.keys()) {
        map.insert(key, vmap[key].toString());
    }
    t->setMap(map);

    return t;
}
