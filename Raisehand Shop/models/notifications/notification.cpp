#include "models/notifications/notification.h"

Notification::Notification(const QString &id, const QString &body, const QString &imageUrl, const QString &imageContainer, bool isRead, const QString &appName, const QString &n_reason, const QString &senderId, NotificationMetaData *metaData, const QString &createdAt, const QString &updatedAt)
{
    this->_id = id;
    this->body = body;
    this->imageUrl = (imageUrl);
    this->imageContainer = imageContainer;
    this->isRead = isRead;
    this->appName = appName;
    this->n_reason = n_reason;
    this->senderId = senderId;
    this->metaData = metaData;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    this->fields = new _fields();
    this->reason = new _n_reason();
}

const QString &Notification::getUpdatedAt() const
{
    return updatedAt;
}

void Notification::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

const QString &Notification::getCreatedAt() const
{
    return createdAt;
}

void Notification::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

NotificationMetaData *Notification::getMetaData() const
{
    return metaData;
}

void Notification::setMetaData(NotificationMetaData *newMetaData)
{
    metaData = newMetaData;
}

const QString &Notification::getSenderId() const
{
    return senderId;
}

void Notification::setSenderId(const QString &newSenderId)
{
    senderId = newSenderId;
}

const QString &Notification::getN_reason() const
{
    return n_reason;
}

void Notification::setN_reason(const QString &newN_reason)
{
    n_reason = newN_reason;
}

bool Notification::reasonBeingMergeRequest()
{
    return getN_reason().compare(reason->MERGE_REQUEST);
}

const QString &Notification::getAppName() const
{
    return appName;
}

void Notification::setAppName(const QString &newAppName)
{
    appName = newAppName;
}

bool Notification::getIsRead() const
{
    return isRead;
}

void Notification::setIsRead(bool newIsRead)
{
    isRead = newIsRead;
}

const QString &Notification::getImageContainer() const
{
    return imageContainer;
}

void Notification::setImageContainer(const QString &newImageContainer)
{
    imageContainer = newImageContainer;
}

const QString &Notification::getImageUrl() const
{
    return imageUrl;
}

void Notification::setImageUrl(const QString &newImageUrl)
{
    imageUrl = newImageUrl;
}

const QString &Notification::getBody() const
{
    return body;
}

void Notification::setBody(const QString &newBody)
{
    body = newBody;
}

const QString &Notification::id() const
{
    return _id;
}

void Notification::setId(const QString &newId)
{
    _id = newId;
}

QList<QString> Notification::getAllFields()
{

}

QString Notification::getPackageName()
{
    return this->className;
}

QList<Notification *> Notification::parseJSONArray(QJsonArray o) throw()
{

}

Notification *Notification::parseJSONObject(QJsonObject o) throw()
{

}

QList<Notification *> Notification::parseArrayString(QString o) throw()
{

}

Notification *Notification::parseObjectString(QString o) throw()
{

}

bool Notification::equal(Notification *o)
{
    return o == this;
}


