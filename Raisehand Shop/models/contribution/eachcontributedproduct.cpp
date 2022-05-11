#include "models\contribution\eachcontributedproduct.h"

EachContributedProduct::EachContributedProduct(const QString &postFix, const QString &createdAt, const QString &repoProduct, long repoProduct_Snapshot) : postFix(postFix),
    createdAt(createdAt),
    repoProduct(repoProduct),
    repoProduct_Snapshot(repoProduct_Snapshot)
{
    this->className = "EachContributedProduct";
    this->fields = new _fields();
}

long EachContributedProduct::getRepoProduct_Snapshot() const
{
    return repoProduct_Snapshot;
}

void EachContributedProduct::setRepoProduct_Snapshot(long newRepoProduct_Snapshot)
{
    repoProduct_Snapshot = newRepoProduct_Snapshot;
}

const QString &EachContributedProduct::getRepoProduct() const
{
    return repoProduct;
}

void EachContributedProduct::setRepoProduct(const QString &newRepoProduct)
{
    repoProduct = newRepoProduct;
}

const QString &EachContributedProduct::getCreatedAt() const
{
    return createdAt;
}

void EachContributedProduct::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

const QString &EachContributedProduct::getPostFix() const
{
    return postFix;
}

void EachContributedProduct::setPostFix(const QString &newPostFix)
{
    postFix = newPostFix;
}

QList<QString> EachContributedProduct::getAllFields()
{

}

QString EachContributedProduct::getPackageName()
{
    return this->className;
}

QList<EachContributedProduct *> EachContributedProduct::parseJSONArray(QJsonArray o) throw()
{

}

EachContributedProduct *EachContributedProduct::parseJSONObject(QJsonObject o) throw()
{

}

QList<EachContributedProduct *> EachContributedProduct::parseArrayString(QString o) throw()
{

}

EachContributedProduct *EachContributedProduct::parseObjectString(QString o) throw()
{

}

bool EachContributedProduct::equal(EachContributedProduct *o)
{
    return o == this;
}
