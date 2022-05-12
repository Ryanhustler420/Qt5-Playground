#include "models/user/repoproductmergerequest.h"

RepoProductMergeRequest::RepoProductMergeRequest(bool isAccepted, const QString &productRepository, const QString &senderProductRepositoryName, const QString &hostRepoProductPostFix, long hostRepoProductSnapshot, QList<long> *senderRequestingProductSnaps, const QString &createdAt)
{
    this->isAccepted = isAccepted;
    this->productRepository = productRepository;
    this->senderProductRepositoryName = senderProductRepositoryName;
    this->hostRepoProductPostFix = hostRepoProductPostFix;
    this->hostRepoProductSnapshot = hostRepoProductSnapshot;
    this->senderRequestingProductSnaps = senderRequestingProductSnaps;
    this->createdAt = createdAt;

    this->className = "RepoProductMergeRequest";
    this->fields = new _fields();
}

bool RepoProductMergeRequest::getIsAccepted() const
{
    return isAccepted;
}

void RepoProductMergeRequest::setIsAccepted(bool newIsAccepted)
{
    isAccepted = newIsAccepted;
}

const QString &RepoProductMergeRequest::getProductRepository() const
{
    return productRepository;
}

void RepoProductMergeRequest::setProductRepository(const QString &newProductRepository)
{
    productRepository = newProductRepository;
}

const QString &RepoProductMergeRequest::getSenderProductRepositoryName() const
{
    return senderProductRepositoryName;
}

void RepoProductMergeRequest::setSenderProductRepositoryName(const QString &newSenderProductRepositoryName)
{
    senderProductRepositoryName = newSenderProductRepositoryName;
}

const QString &RepoProductMergeRequest::getHostRepoProductPostFix() const
{
    return hostRepoProductPostFix;
}

void RepoProductMergeRequest::setHostRepoProductPostFix(const QString &newHostRepoProductPostFix)
{
    hostRepoProductPostFix = newHostRepoProductPostFix;
}

long RepoProductMergeRequest::getHostRepoProductSnapshot() const
{
    return hostRepoProductSnapshot;
}

void RepoProductMergeRequest::setHostRepoProductSnapshot(long newHostRepoProductSnapshot)
{
    hostRepoProductSnapshot = newHostRepoProductSnapshot;
}

QList<long> *RepoProductMergeRequest::getSenderRequestingProductSnaps() const
{
    return senderRequestingProductSnaps != nullptr ? senderRequestingProductSnaps : new QList<long>;
}

void RepoProductMergeRequest::setSenderRequestingProductSnaps(QList<long> *newSenderRequestingProductSnaps)
{
    senderRequestingProductSnaps = newSenderRequestingProductSnaps;
}

const QString &RepoProductMergeRequest::getCreatedAt() const
{
    return createdAt;
}

void RepoProductMergeRequest::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

QList<QString> RepoProductMergeRequest::getAllFields()
{

}

QString RepoProductMergeRequest::getPackageName()
{
    return this->className;
}

QList<RepoProductMergeRequest *> RepoProductMergeRequest::parseJSONArray(QJsonArray o) throw()
{

}

RepoProductMergeRequest *RepoProductMergeRequest::parseJSONObject(QJsonObject o) throw()
{

}

QList<RepoProductMergeRequest *> RepoProductMergeRequest::parseArrayString(QString o) throw()
{

}

RepoProductMergeRequest *RepoProductMergeRequest::parseObjectString(QString o) throw()
{

}

bool RepoProductMergeRequest::equal(RepoProductMergeRequest *o)
{
    return o->getHostRepoProductSnapshot() == getHostRepoProductSnapshot();
}

QString RepoProductMergeRequest::getMergeRequestDetail() const
{
    QString *repoName = new QString(getSenderProductRepositoryName());
    QByteArray assembleText;
    assembleText
            .append("Requested @")
            .append("<b>").append(repoName->replace(" ", "_")).append("</b>")
            .append(" To Merge ");

    for (int i = 0; i < getSenderRequestingProductSnaps()->size(); i++) {
        assembleText.append("<b>#").append(getSenderRequestingProductSnaps()->at(i)).append("</b>");
        if (i != getSenderRequestingProductSnaps()->size() - 1) assembleText.append(", ");
        else assembleText.append("</b>");
    }

    assembleText.append(" Inside Product ").append("<b>#").append(getHostRepoProductSnapshot());
    if (!getHostRepoProductPostFix().compare("null"))
        assembleText.append(getHostRepoProductPostFix()).append("</b>");
    else assembleText.append("</b>");
    return assembleText;
}
