#include "models/user/mycontributionofrepoproduct.h"

MyContributionOfRepoProduct::MyContributionOfRepoProduct(QList<PSnap> *productSnapshot, const QString &productRepositoryName, const QString &productRepository)
{
    this->productSnapshot = productSnapshot;
    this->productRepositoryName = productRepositoryName;
    this->productRepository = productRepository;

    this->className = "MyContributionOfRepoProduct";
    this->fields = new _fields();
}

const QString &MyContributionOfRepoProduct::getProductRepository() const
{
    return productRepository;
}

void MyContributionOfRepoProduct::setProductRepository(const QString &newProductRepository)
{
    productRepository = newProductRepository;
}

const QString &MyContributionOfRepoProduct::getProductRepositoryName() const
{
    return productRepositoryName;
}

void MyContributionOfRepoProduct::setProductRepositoryName(const QString &newProductRepositoryName)
{
    productRepositoryName = newProductRepositoryName;
}

QList<PSnap> *MyContributionOfRepoProduct::getProductSnapshot() const
{
    return productSnapshot;
}

void MyContributionOfRepoProduct::setProductSnapshot(QList<PSnap> *newProductSnapshot)
{
    productSnapshot = newProductSnapshot;
}

QString MyContributionOfRepoProduct::getAllTheProductFormattedSnapshots() const
{
    QByteArray stringBuilder;
    for (int index = 0; index < getProductSnapshot()->size(); index++) {
        if (index != getProductSnapshot()->size() - 1)
            stringBuilder.append(getProductSnapshot()->at(index).getFormattedProductSnapshot()).append(", ");
        else stringBuilder.append(getProductSnapshot()->at(index).getFormattedProductSnapshot()).append(" ");
    }
    return stringBuilder;
}

QList<QString> MyContributionOfRepoProduct::getAllFields()
{

}

QString MyContributionOfRepoProduct::getPackageName()
{
    return this->className;
}

QList<MyContributionOfRepoProduct *> MyContributionOfRepoProduct::parseJSONArray(QJsonArray o) throw()
{

}

MyContributionOfRepoProduct *MyContributionOfRepoProduct::parseJSONObject(QJsonObject o) throw()
{

}

QList<MyContributionOfRepoProduct *> MyContributionOfRepoProduct::parseArrayString(QString o) throw()
{

}

MyContributionOfRepoProduct *MyContributionOfRepoProduct::parseObjectString(QString o) throw()
{

}

bool MyContributionOfRepoProduct::equal(MyContributionOfRepoProduct *o)
{
    return o == this;
}
