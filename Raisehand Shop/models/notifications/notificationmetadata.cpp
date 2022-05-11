#include "models/notifications/notificationmetadata.h"

NotificationMetaData::NotificationMetaData(const QString &mergeRequestID) : mergeRequestID(mergeRequestID)
{
    this->className = "NotificationMetaData";
    this->fields = new _fields();
}

const QString &NotificationMetaData::getMergeRequestID() const
{
    return mergeRequestID;
}

void NotificationMetaData::setMergeRequestID(const QString &newMergeRequestID)
{
    mergeRequestID = newMergeRequestID;
}

QList<QString> NotificationMetaData::getAllFields()
{

}

QString NotificationMetaData::getPackageName()
{
    return this->className;
}

QList<NotificationMetaData *> NotificationMetaData::parseJSONArray(QJsonArray o) throw()
{

}

NotificationMetaData *NotificationMetaData::parseJSONObject(QJsonObject o) throw()
{

}

QList<NotificationMetaData *> NotificationMetaData::parseArrayString(QString o) throw()
{

}

NotificationMetaData *NotificationMetaData::parseObjectString(QString o) throw()
{

}

bool NotificationMetaData::equal(NotificationMetaData *o)
{
    return o == this;
}
