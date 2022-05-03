#ifndef SERIALIZEJSON_H
#define SERIALIZEJSON_H

#include <QJsonDocument>
#include <QVariantMap>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariant>
#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QMap>

#include "models/spider.h"

class SerializeJSON : public QObject
{
    Q_OBJECT
public:
    explicit SerializeJSON(QObject *parent = nullptr);

    static void writeJson(Spider *obj, QString path);
    static Spider* readJson(QString path);

signals:

};

#endif // SERIALIZEJSON_H
