#include "models/product_repository/repositoryjoinrequest.h"

RepositoryJoinRequest::RepositoryJoinRequest(const QString &id, const QString &uid, const QString &email, const QString &isReviewed, const QString &isAllowed, const QString &createdAt, const QString &updatedAt)
{
    this->_id = id;
    this->uid = uid;
    this->email = email;
    this->isReviewed = isReviewed;
    this->isAllowed = isAllowed;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    this->className = "RepositoryJoinRequest";
    this->fields = new _fields();
}


bool RepositoryJoinRequest::equal(RepositoryJoinRequest *o)
{
    return o == this;
}

const QString &RepositoryJoinRequest::getUpdatedAt() const
{
    return updatedAt;
}

void RepositoryJoinRequest::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

const QString &RepositoryJoinRequest::getCreatedAt() const
{
    return createdAt;
}

void RepositoryJoinRequest::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

const QString &RepositoryJoinRequest::getIsAllowed() const
{
    return isAllowed;
}

void RepositoryJoinRequest::setIsAllowed(const QString &newIsAllowed)
{
    isAllowed = newIsAllowed;
}

const QString &RepositoryJoinRequest::getIsReviewed() const
{
    return isReviewed;
}

void RepositoryJoinRequest::setIsReviewed(const QString &newIsReviewed)
{
    isReviewed = newIsReviewed;
}

const QString &RepositoryJoinRequest::getEmail() const
{
    return email;
}

void RepositoryJoinRequest::setEmail(const QString &newEmail)
{
    email = newEmail;
}

const QString &RepositoryJoinRequest::getUid() const
{
    return uid;
}

void RepositoryJoinRequest::setUid(const QString &newUid)
{
    uid = newUid;
}

const QString &RepositoryJoinRequest::id() const
{
    return _id;
}

void RepositoryJoinRequest::setId(const QString &newId)
{
    _id = newId;
}

QList<QString> RepositoryJoinRequest::getAllFields()
{

}

QString RepositoryJoinRequest::getPackageName()
{
    return this->className;
}

QList<RepositoryJoinRequest *> RepositoryJoinRequest::parseJSONArray(QJsonArray o) throw()
{

}

RepositoryJoinRequest *RepositoryJoinRequest::parseJSONObject(QJsonObject o) throw()
{

}

QList<RepositoryJoinRequest *> RepositoryJoinRequest::parseArrayString(QString o) throw()
{

}

RepositoryJoinRequest *RepositoryJoinRequest::parseObjectString(QString o) throw()
{

}
