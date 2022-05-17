#include "models/mergerequest.h"

MergeRequest::MergeRequest(bool isAccepted, long hostRepoProductSnapshot, QList<long> *senderRequestingProductSnaps, const QString &senderProductRepositoryName, const QString &hostRepoProductPostFix, const QString &productRepository, const QString &createdAt, const QString &updatedAt)
{
    this->isAccepted = isAccepted;
    this->hostRepoProductSnapshot = hostRepoProductSnapshot;
    this->senderRequestingProductSnaps = senderRequestingProductSnaps;
    this->senderProductRepositoryName = senderProductRepositoryName;
    this->hostRepoProductPostFix = hostRepoProductPostFix;
    this->productRepository = productRepository;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    this->className = "MergeRequest";
    this->fields = new _fields();
}

bool MergeRequest::getIsAccepted() const
{
    return isAccepted;
}

void MergeRequest::setIsAccepted(bool newIsAccepted)
{
    isAccepted = newIsAccepted;
}

long MergeRequest::getHostRepoProductSnapshot() const
{
    return hostRepoProductSnapshot;
}

void MergeRequest::setHostRepoProductSnapshot(long newHostRepoProductSnapshot)
{
    hostRepoProductSnapshot = newHostRepoProductSnapshot;
}

QList<long> *MergeRequest::getSenderRequestingProductSnaps() const
{
    return senderRequestingProductSnaps != nullptr ? senderRequestingProductSnaps : new QList<long>();
}

void MergeRequest::setSenderRequestingProductSnaps(QList<long> *newSenderRequestingProductSnaps)
{
    senderRequestingProductSnaps = newSenderRequestingProductSnaps;
}

const QString &MergeRequest::getSenderProductRepositoryName() const
{
    return senderProductRepositoryName;
}

void MergeRequest::setSenderProductRepositoryName(const QString &newSenderProductRepositoryName)
{
    senderProductRepositoryName = newSenderProductRepositoryName;
}

const QString &MergeRequest::getHostRepoProductPostFix() const
{
    return hostRepoProductPostFix;
}

void MergeRequest::setHostRepoProductPostFix(const QString &newHostRepoProductPostFix)
{
    hostRepoProductPostFix = newHostRepoProductPostFix;
}

const QString &MergeRequest::getProductRepository() const
{
    return productRepository;
}

void MergeRequest::setProductRepository(const QString &newProductRepository)
{
    productRepository = newProductRepository;
}

const QString &MergeRequest::getCreatedAt() const
{
    return createdAt;
}

void MergeRequest::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

const QString &MergeRequest::getUpdatedAt() const
{
    return updatedAt;
}

void MergeRequest::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

QList<QString> MergeRequest::getAllFields()
{

}

QString MergeRequest::getPackageName()
{
    return this->className;
}

QList<MergeRequest *> MergeRequest::parseJSONArray(QJsonArray o) throw()
{

}

MergeRequest *MergeRequest::parseJSONObject(QJsonObject o) throw()
{

}

QList<MergeRequest *> MergeRequest::parseArrayString(QString o) throw()
{

}

MergeRequest *MergeRequest::parseObjectString(QString o) throw()
{

}

bool MergeRequest::equal(MergeRequest *o)
{
    return o == this;
}
