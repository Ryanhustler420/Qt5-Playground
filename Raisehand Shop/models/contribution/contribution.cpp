#include "contribution.h"

Contribution::Contribution(QList<EachContributedProduct> *productSnapshot, QString &productRepositoryName, QString &productRepository, QString &id, QString &createdAt, QString &updatedAt)
{
    this->className = "Contribution";
    this->productSnapshot = productSnapshot;
    this->productRepositoryName = productRepositoryName,
    this->productRepository = productRepository,
    this->_id = id,
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    this->fields = new _fields();
}

const QString &Contribution::id() const
{
    return _id;
}

void Contribution::setId(const QString &newId)
{
    _id = newId;
}

const QString &Contribution::getUpdatedAt() const
{
    return updatedAt;
}

void Contribution::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

const QString &Contribution::getCreatedAt() const
{
    return createdAt;
}

void Contribution::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

const QString &Contribution::getProductRepository() const
{
    return productRepository;
}

void Contribution::setProductRepository(const QString &newProductRepository)
{
    productRepository = newProductRepository;
}

const QString &Contribution::getProductRepositoryName() const
{
    return productRepositoryName;
}

void Contribution::setProductRepositoryName(const QString &newProductRepositoryName)
{
    productRepositoryName = newProductRepositoryName;
}

QList<EachContributedProduct> *Contribution::getProductSnapshot() const
{
    return productSnapshot != nullptr ? productSnapshot : new QList<EachContributedProduct>();
}

void Contribution::setProductSnapshot(QList<EachContributedProduct> *newProductSnapshot)
{
    productSnapshot = newProductSnapshot;
}

QList<QString> Contribution::getAllFields()
{
    return QList<QString>();
}

QString Contribution::getPackageName()
{
    return this->className;
}

QList<Contribution*> Contribution::parseJSONArray(QJsonArray o) throw()
{
    return QList<Contribution*>();
}

Contribution* Contribution::parseJSONObject(QJsonObject o) throw()
{
    return this;
}

QList<Contribution*> Contribution::parseArrayString(QString o) throw()
{
    return QList<Contribution*>();
}

Contribution* Contribution::parseObjectString(QString o) throw()
{
    return this;
}

bool Contribution::equal(Contribution* o)
{
    return o == this;
}
