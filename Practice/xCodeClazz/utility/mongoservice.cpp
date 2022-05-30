#include "utility/mongoservice.h"



MongoService::MongoService(QObject *parent) : QObject(parent)
{   
}

bool MongoService::hasMongoIds(QJsonArray array)
{
    QList<bool> queue;
    for (int var = 0; var < array.size(); ++var) {
        queue.append(isValidMongoID(array.at(var).toString()));
    }
    return !queue.contains(false);
}

bool MongoService::isValidMongoID(QString id)
{
    // QString _id = "60bbab5c248c63298e1147a6";
    QRegularExpression re("^[0-9a-fA-F]{24}$");
    QRegularExpressionMatch match = re.match(id);
    return match.hasMatch();
}
