#include "models\user\repoaccesspasscode.h"

RepoAccessPasscode::RepoAccessPasscode(const QString &productRepositoryName, long productRepositorySnapshot, const QString &productRepositoryProfilePassword, const QString &createdAt, const QString &updatedAt)
{
    this->productRepositoryName = productRepositoryName;
    this->productRepositorySnapshot = productRepositorySnapshot;
    this->productRepositoryProfilePassword = productRepositoryProfilePassword;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    this->className = "RepoAccessPasscode";
    this->fields = new _fields();
}

const QString &RepoAccessPasscode::getUpdatedAt() const
{
    return updatedAt;
}

void RepoAccessPasscode::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

const QString &RepoAccessPasscode::getCreatedAt() const
{
    return createdAt;
}

void RepoAccessPasscode::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

const QString &RepoAccessPasscode::getProductRepositoryProfilePassword() const
{
    return productRepositoryProfilePassword;
}

void RepoAccessPasscode::setProductRepositoryProfilePassword(const QString &newProductRepositoryProfilePassword)
{
    productRepositoryProfilePassword = newProductRepositoryProfilePassword;
}

long RepoAccessPasscode::getProductRepositorySnapshot() const
{
    return productRepositorySnapshot;
}

void RepoAccessPasscode::setProductRepositorySnapshot(long newProductRepositorySnapshot)
{
    productRepositorySnapshot = newProductRepositorySnapshot;
}

const QString &RepoAccessPasscode::getProductRepositoryName() const
{
    return productRepositoryName;
}

void RepoAccessPasscode::setProductRepositoryName(const QString &newProductRepositoryName)
{
    productRepositoryName = newProductRepositoryName;
}

QList<QString> RepoAccessPasscode::getAllFields()
{

}

QString RepoAccessPasscode::getPackageName()
{
    return this->className;
}

QList<RepoAccessPasscode *> RepoAccessPasscode::parseJSONArray(QJsonArray o) throw()
{

}

RepoAccessPasscode *RepoAccessPasscode::parseJSONObject(QJsonObject o) throw()
{

}

QList<RepoAccessPasscode *> RepoAccessPasscode::parseArrayString(QString o) throw()
{

}

RepoAccessPasscode *RepoAccessPasscode::parseObjectString(QString o) throw()
{

}

bool RepoAccessPasscode::equal(RepoAccessPasscode *o)
{
    return o == this;
}
