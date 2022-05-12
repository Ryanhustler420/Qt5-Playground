#include "models/product_repository/productrepository.h"

ProductRepository::ProductRepository(int v, const QString &id, const QString &productRepositoryName, long productRepositorySnapshot, const QString &productRepositoryOwnerName, const QString &productRepositoryType, bool canProductRepositoryExpire, const QString &productRepositoryThumbnail, const QString &imageContainer, const QString &productRepositoryOverview, const QString &productRepositoryTargetAudience, const QString &productRepositoryPasswordChangedAt, const QString &productRepositoryProfilePassword, bool isProductRepositoryOpen, long likes, long totalView, QList<Contributor> *repoProductContributors, Currency *baseCurrency, QList<Category> *categories, QList<QString> *ALTCategories, const QString &lastPaymentOn, int lastPaymentPlanValidForDays, int inventoryLength, bool isProductRepositoryAlive, const QString &productRepositoryCoverage, const QString &createdAt, const QString &updatedAt)
{
    this->__v = v;
    this->_id = id;
    this->productRepositoryName = productRepositoryName;
    this->productRepositorySnapshot = productRepositorySnapshot;
    this->productRepositoryOwnerName = productRepositoryOwnerName;
    this->productRepositoryType = productRepositoryType;
    this->canProductRepositoryExpire = canProductRepositoryExpire;
    this->productRepositoryThumbnail = productRepositoryThumbnail;
    this->imageContainer = imageContainer;
    this->productRepositoryOverview = productRepositoryOverview;
    this->productRepositoryTargetAudience = productRepositoryTargetAudience;
    this->productRepositoryPasswordChangedAt = productRepositoryPasswordChangedAt;
    this->productRepositoryProfilePassword = productRepositoryProfilePassword;
    this->isProductRepositoryOpen = isProductRepositoryOpen;
    this->likes = likes;
    this->totalView = totalView;
    this->repoProductContributors = repoProductContributors;
    this->baseCurrency = baseCurrency;
    this->categories = categories;
    this->ALTCategories = ALTCategories;
    this->lastPaymentOn = lastPaymentOn;
    this->lastPaymentPlanValidForDays = lastPaymentPlanValidForDays;
    this->inventoryLength = inventoryLength;
    this->isProductRepositoryAlive = isProductRepositoryAlive;
    this->productRepositoryCoverage = productRepositoryCoverage;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    this->className = "ProductRepository";
    this->action_type = new _action_type();
    this->fields = new _fields();
}

QString ProductRepository::getEncryptedData()
{
    return encode();
}

QList<int> ProductRepository::getActionTypes()
{
    // Change here!! need to change in all other projects
    QList<int> actions;
    actions.append(action_type->SEARCH);
    actions.append(action_type->BOOKMARK);
    return actions;
}

QString ProductRepository::encode()
{
    // return qrSignaturePatterns.createProductRepositoryQRCode(this);
}

QString ProductRepository::getExpireMessage()
{
    return getProductRepositoryName() + " Has been expired, You can't push product to this repository";
}

bool ProductRepository::hasLimitedSpace()
{
    return getInventoryLength() != INFINITY;
}

QString ProductRepository::getFormattedLikes()
{
    // return new HelperService().formatView(getLikes());
}

QString ProductRepository::getSupportedCurrencyCode()
{
    return getBaseCurrency()->currencyCodeSupport(isNationalRepository() || isLocalRepository());
}

QString ProductRepository::getSupportedCurrencyName()
{
    return getBaseCurrency()->currencySupport(isNationalRepository() || isLocalRepository());
}

bool ProductRepository::isLocalRepository()
{
    return getProductRepositoryCoverage().compare(LOCAL);
}

bool ProductRepository::isMasterRepository()
{
    return getProductRepositoryType().compare(MASTER);
}

bool ProductRepository::isRepositoryExpired()
{
    // return getRepoValidityDetails().isExpired;
}

bool ProductRepository::isNationalRepository()
{
    return getProductRepositoryCoverage().compare(NATIONAL);
}

QString ProductRepository::getFormattedTotalViews()
{
    // return new HelperService().formatView(getTotalView());
}

bool ProductRepository::isRepositoryNotExpired()
{
    // return !getRepoValidityDetails().isExpired;
}

QString ProductRepository::getTotalContributorCount()
{
    // new HelperService().formatView(getRepoProductContributors().size());
}

bool ProductRepository::isInternationalRepository()
{
    return getProductRepositoryCoverage().compare(INTERNATIONAL);
}

QString ProductRepository::getCorrectRepoLogo()
{
    //    if (!getProductRepositoryThumbnail().compare("null"))
    //        return new HelperService().decideAppropriateUrlAmong(getImageContainer(), getProductRepositoryThumbnail());
    //    return new HelperService().decideAppropriateUrlAmong(getImageContainer(), Constants.NO_IMAGE_PLACEHOLDER_URL);
}

QString ProductRepository::getFormattedRepositorySnapshot()
{
    // return String.format("#%s", new HelperService().formatView(getProductRepositorySnapshot()));
}

QString ProductRepository::getFormattedCreatedAtDate()
{
    //  return new HelperService().getDateFromCreatedAt(getCreatedAt());
}

bool ProductRepository::isNotOpen()
{
    return !getIsProductRepositoryOpen();
}

QString ProductRepository::getProductRepositoryCoverageWithCoverageKeyword()
{
    // return String.format("%s Coverage", new HelperService().capitalize(getProductRepositoryCoverage()));
}

const QString &ProductRepository::getUpdatedAt() const
{
    return updatedAt;
}

void ProductRepository::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

const QString &ProductRepository::getCreatedAt() const
{
    return createdAt;
}

void ProductRepository::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

const QString &ProductRepository::getProductRepositoryCoverage() const
{
    return productRepositoryCoverage;
}

void ProductRepository::setProductRepositoryCoverage(const QString &newProductRepositoryCoverage)
{
    productRepositoryCoverage = newProductRepositoryCoverage;
}

bool ProductRepository::getIsProductRepositoryAlive() const
{
    return isProductRepositoryAlive;
}

void ProductRepository::setIsProductRepositoryAlive(bool newIsProductRepositoryAlive)
{
    isProductRepositoryAlive = newIsProductRepositoryAlive;
}

int ProductRepository::getInventoryLength() const
{
    return inventoryLength;
}

void ProductRepository::setInventoryLength(int newInventoryLength)
{
    inventoryLength = newInventoryLength;
}

int ProductRepository::getLastPaymentPlanValidForDays() const
{
    return lastPaymentPlanValidForDays;
}

void ProductRepository::setLastPaymentPlanValidForDays(int newLastPaymentPlanValidForDays)
{
    lastPaymentPlanValidForDays = newLastPaymentPlanValidForDays;
}

const QString &ProductRepository::getLastPaymentOn() const
{
    return lastPaymentOn;
}

void ProductRepository::setLastPaymentOn(const QString &newLastPaymentOn)
{
    lastPaymentOn = newLastPaymentOn;
}

QList<QString> *ProductRepository::getALTCategories() const
{
    return ALTCategories != nullptr ? ALTCategories : new QList<QString>();
}

void ProductRepository::setALTCategories(QList<QString> *newALTCategories)
{
    ALTCategories = newALTCategories;
}

QList<Category> *ProductRepository::getCategories() const
{
    return categories != nullptr ? categories : new QList<Category>();
}

void ProductRepository::setCategories(QList<Category> *newCategories)
{
    categories = newCategories;
}

Currency *ProductRepository::getBaseCurrency() const
{
    return baseCurrency;
}

void ProductRepository::setBaseCurrency(Currency *newBaseCurrency)
{
    baseCurrency = newBaseCurrency;
}

QList<Contributor> *ProductRepository::getRepoProductContributors() const
{
    return repoProductContributors;
}

void ProductRepository::setRepoProductContributors(QList<Contributor> *newRepoProductContributors)
{
    repoProductContributors = newRepoProductContributors;
}

long ProductRepository::getTotalView() const
{
    return totalView;
}

void ProductRepository::setTotalView(long newTotalView)
{
    totalView = newTotalView;
}

long ProductRepository::getLikes() const
{
    return likes;
}

void ProductRepository::setLikes(long newLikes)
{
    likes = newLikes;
}

bool ProductRepository::getIsProductRepositoryOpen() const
{
    return isProductRepositoryOpen;
}

void ProductRepository::setIsProductRepositoryOpen(bool newIsProductRepositoryOpen)
{
    isProductRepositoryOpen = newIsProductRepositoryOpen;
}

const QString &ProductRepository::getProductRepositoryProfilePassword() const
{
    return productRepositoryProfilePassword;
}

void ProductRepository::setProductRepositoryProfilePassword(const QString &newProductRepositoryProfilePassword)
{
    productRepositoryProfilePassword = newProductRepositoryProfilePassword;
}

const QString &ProductRepository::getProductRepositoryPasswordChangedAt() const
{
    return productRepositoryPasswordChangedAt;
}

void ProductRepository::setProductRepositoryPasswordChangedAt(const QString &newProductRepositoryPasswordChangedAt)
{
    productRepositoryPasswordChangedAt = newProductRepositoryPasswordChangedAt;
}

const QString &ProductRepository::getProductRepositoryTargetAudience() const
{
    return productRepositoryTargetAudience;
}

void ProductRepository::setProductRepositoryTargetAudience(const QString &newProductRepositoryTargetAudience)
{
    productRepositoryTargetAudience = newProductRepositoryTargetAudience;
}

const QString &ProductRepository::getProductRepositoryOverview() const
{
    return productRepositoryOverview;
}

void ProductRepository::setProductRepositoryOverview(const QString &newProductRepositoryOverview)
{
    productRepositoryOverview = newProductRepositoryOverview;
}

const QString &ProductRepository::getImageContainer() const
{
    return imageContainer;
}

void ProductRepository::setImageContainer(const QString &newImageContainer)
{
    imageContainer = newImageContainer;
}

const QString &ProductRepository::getProductRepositoryThumbnail() const
{
    return productRepositoryThumbnail;
}

void ProductRepository::setProductRepositoryThumbnail(const QString &newProductRepositoryThumbnail)
{
    productRepositoryThumbnail = newProductRepositoryThumbnail;
}

bool ProductRepository::getCanProductRepositoryExpire() const
{
    return canProductRepositoryExpire;
}

void ProductRepository::setCanProductRepositoryExpire(bool newCanProductRepositoryExpire)
{
    canProductRepositoryExpire = newCanProductRepositoryExpire;
}

const QString &ProductRepository::getProductRepositoryType() const
{
    return productRepositoryType;
}

void ProductRepository::setProductRepositoryType(const QString &newProductRepositoryType)
{
    productRepositoryType = newProductRepositoryType;
}

const QString &ProductRepository::getProductRepositoryOwnerName() const
{
    return productRepositoryOwnerName;
}

void ProductRepository::setProductRepositoryOwnerName(const QString &newProductRepositoryOwnerName)
{
    productRepositoryOwnerName = newProductRepositoryOwnerName;
}

long ProductRepository::getProductRepositorySnapshot() const
{
    return productRepositorySnapshot;
}

void ProductRepository::setProductRepositorySnapshot(long newProductRepositorySnapshot)
{
    productRepositorySnapshot = newProductRepositorySnapshot;
}

const QString &ProductRepository::getProductRepositoryName() const
{
    return productRepositoryName;
}

void ProductRepository::setProductRepositoryName(const QString &newProductRepositoryName)
{
    productRepositoryName = newProductRepositoryName;
}

const QString &ProductRepository::id() const
{
    return _id;
}

void ProductRepository::setId(const QString &newId)
{
    _id = newId;
}

int ProductRepository::v() const
{
    return __v;
}

void ProductRepository::setV(int newV)
{
    __v = newV;
}

QList<QString> ProductRepository::getAllFields()
{

}

QString ProductRepository::getPackageName()
{
    return this->className;
}

QList<ProductRepository *> ProductRepository::parseJSONArray(QJsonArray o) throw()
{

}

ProductRepository *ProductRepository::parseJSONObject(QJsonObject o) throw()
{

}

QList<ProductRepository *> ProductRepository::parseArrayString(QString o) throw()
{

}

ProductRepository *ProductRepository::parseObjectString(QString o) throw()
{

}

bool ProductRepository::equal(ProductRepository *o)
{
    return o == this;
}
