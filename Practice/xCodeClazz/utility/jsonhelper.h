#ifndef JSONHELPER_H
#define JSONHELPER_H

#include "parents/commonsuperclass.h"

#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>

class JsonHelper : public CommonSuperClass
{
public:
    explicit JsonHelper(CommonSuperClass *parent = nullptr);

public:
    static QJsonObject toJsonObject(QJsonDocument jsonDocument, QString key);
    static QJsonArray toJsonArray(QJsonObject jsonObject, QString key);
    static QJsonArray toJsonArray(QByteArray *byteArray, QString key);
    static QJsonDocument toJsonDocument(QByteArray *byteArray);
    static QString toString(QJsonDocument jsonDocument, QString key);
    static QJsonObject toJson(QString in);

private:
    static QJsonDocument createDummyJSON();
    static QString parseDummpyJSON();

signals:

};

#endif // JSONHELPER_H
