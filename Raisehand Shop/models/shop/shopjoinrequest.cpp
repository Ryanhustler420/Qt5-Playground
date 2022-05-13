#include "models/shop/shopjoinrequest.h"

ShopJoinRequest::ShopJoinRequest(const QString &id, const QString &uid, const QString &email, bool isReviewed, bool isAllowed, const QString &createdAt, const QString &updatedAt)
{
    this->_id = id;
    this->uid = uid;
    this->email = email;
    this->isReviewed = isReviewed;
    this->isAllowed = isAllowed;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    this->className = "ShopJoinRequest";
    this->fields = new _fields();
}

const QString &ShopJoinRequest::getUpdatedAt() const
{
    return updatedAt;
}

void ShopJoinRequest::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

const QString &ShopJoinRequest::getCreatedAt() const
{
    return createdAt;
}

void ShopJoinRequest::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

bool ShopJoinRequest::getIsAllowed() const
{
    return isAllowed;
}

void ShopJoinRequest::setIsAllowed(bool newIsAllowed)
{
    isAllowed = newIsAllowed;
}

bool ShopJoinRequest::getIsReviewed() const
{
    return isReviewed;
}

void ShopJoinRequest::setIsReviewed(bool newIsReviewed)
{
    isReviewed = newIsReviewed;
}

const QString &ShopJoinRequest::getEmail() const
{
    return email;
}

void ShopJoinRequest::setEmail(const QString &newEmail)
{
    email = newEmail;
}

const QString &ShopJoinRequest::getUid() const
{
    return uid;
}

void ShopJoinRequest::setUid(const QString &newUid)
{
    uid = newUid;
}

const QString &ShopJoinRequest::id() const
{
    return _id;
}

void ShopJoinRequest::setId(const QString &newId)
{
    _id = newId;
}

QList<QString> ShopJoinRequest::getAllFields()
{

}

QString ShopJoinRequest::getPackageName()
{
    return this->className;
}

QList<ShopJoinRequest *> ShopJoinRequest::parseJSONArray(QJsonArray o) throw()
{

}

ShopJoinRequest *ShopJoinRequest::parseJSONObject(QJsonObject o) throw()
{

}

QList<ShopJoinRequest *> ShopJoinRequest::parseArrayString(QString o) throw()
{

}

ShopJoinRequest *ShopJoinRequest::parseObjectString(QString o) throw()
{

}

bool ShopJoinRequest::equal(ShopJoinRequest *o)
{
    return o == this;
}
