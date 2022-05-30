#ifndef MONGOSERVICE_H
#define MONGOSERVICE_H

#include "utility/jsonhelper.h"
#include <QRegExpValidator>
#include <QRegExp>
#include <QDebug>

class MongoService : public QObject
{
    Q_OBJECT
public:
    explicit MongoService(QObject *parent = nullptr);

    bool hasMongoIds(QJsonArray *array);
    bool isValidMongoID(QString id);

signals:

};

#endif // MONGOSERVICE_H
