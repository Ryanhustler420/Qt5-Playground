#include "models/repo_product/repoproduct.h"

RepoProduct::RepoProduct(const QString &id, const QString &url, const QString &barcode, bool isBarcodeVerified, bool isSearchableStandalone, const QString &productName, Currency *currency, const QString &thumbnailUrl, const QString &description, const QString &postFixChar, const QString &productRepositoryName, const QString &productRepositoryThumbnail, QList<QString> *productImages, const QString &imageContainer, double productPrice, int timesModified, long totalView, long timesClone, long productSnapshot, long productRepositorySnapshot, const QString &productRepositoryType, bool isDiscounted, bool isProductRepositoryActive, bool isPrivate, bool isFreeze, bool hasSibling, bool hasEdited, QList<Tag> *tags, QList<Category> *categories, QList<QString> *ALTCategories, const QString &createdAt, const QString &updatedAt, const QString &user, User *ALTUser, const QString &productRepository, ProductRepository *ALTProductRepository, SiUnit *recommendedSIUnit, const QString &ALTRecommendedSIUnit, QList<RepoProduct> *bakedInside, QList<QString> *ALTBakedInside, QList<RepoProduct> *spareParts, QList<QString> *ALTSpareParts)
{
    this->_id = id;
    this->url = url;
    this->barcode = barcode;
    this->isBarcodeVerified = isBarcodeVerified;
    this->isSearchableStandalone = isSearchableStandalone;
    this->productName = productName;
    this->currency = currency;
    this->thumbnailUrl = thumbnailUrl;
    this->description = description;
    this->postFixChar = postFixChar;
    this->productRepositoryName = productRepositoryName;
    this->productRepositoryThumbnail = productRepositoryThumbnail;
    this->productImages = productImages;
    this->imageContainer = imageContainer;
    this->productPrice = productPrice;
    this->timesModified = timesModified;
    this->totalView = totalView;
    this->timesClone = timesClone;
    this->productSnapshot = productSnapshot;
    this->productRepositorySnapshot = productRepositorySnapshot;
    this->productRepositoryType = productRepositoryType;
    this->isDiscounted = isDiscounted;
    this->isProductRepositoryActive = isProductRepositoryActive;
    this->isPrivate = isPrivate;
    this->isFreeze = isFreeze;
    this->hasSibling = hasSibling;
    this->hasEdited = hasEdited;
    this->tags = tags;
    this->categories = categories;
    this->ALTCategories = ALTCategories;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;
    this->user = user;
    this->ALTUser = ALTUser;
    this->productRepository = productRepository;
    this->ALTProductRepository = ALTProductRepository;
    this->recommendedSIUnit = recommendedSIUnit;
    this->ALTRecommendedSIUnit = ALTRecommendedSIUnit;
    this->bakedInside = bakedInside;
    this->ALTBakedInside = ALTBakedInside;
    this->spareParts = spareParts;
    this->ALTSpareParts = ALTSpareParts;

    this->className = "RepoProduct";
    this->fields = new _fields();
}

QList<QString> *RepoProduct::getALTSpareParts() const
{
    return ALTSpareParts != nullptr ? ALTSpareParts : new QList<QString>();
}

void RepoProduct::setALTSpareParts(QList<QString> *newALTSpareParts)
{
    ALTSpareParts = newALTSpareParts;
}

QList<RepoProduct> *RepoProduct::getSpareParts() const
{
    return spareParts != nullptr ? spareParts : new QList<RepoProduct>();
}

void RepoProduct::setSpareParts(QList<RepoProduct> *newSpareParts)
{
    spareParts = newSpareParts;
}

QList<QString> *RepoProduct::getALTBakedInside() const
{
    return ALTBakedInside != nullptr ? ALTBakedInside : new QList<QString>();
}

void RepoProduct::setALTBakedInside(QList<QString> *newALTBakedInside)
{
    ALTBakedInside = newALTBakedInside;
}

QList<RepoProduct> *RepoProduct::getBakedInside() const
{
    return bakedInside != nullptr ? bakedInside : new QList<RepoProduct>();
}

void RepoProduct::setBakedInside(QList<RepoProduct> *newBakedInside)
{
    bakedInside = newBakedInside;
}

const QString &RepoProduct::getALTRecommendedSIUnit() const
{
    return ALTRecommendedSIUnit;
}

void RepoProduct::setALTRecommendedSIUnit(const QString &newALTRecommendedSIUnit)
{
    ALTRecommendedSIUnit = newALTRecommendedSIUnit;
}

SiUnit *RepoProduct::getRecommendedSIUnit() const
{
    return recommendedSIUnit;
}

void RepoProduct::setRecommendedSIUnit(SiUnit *newRecommendedSIUnit)
{
    recommendedSIUnit = newRecommendedSIUnit;
}

ProductRepository *RepoProduct::getALTProductRepository() const
{
    return ALTProductRepository;
}

void RepoProduct::setALTProductRepository(ProductRepository *newALTProductRepository)
{
    ALTProductRepository = newALTProductRepository;
}

QString RepoProduct::getProductRepository() const
{
    return productRepository != nullptr ? productRepository : QString("");
}

void RepoProduct::setProductRepository(const QString &newProductRepository)
{
    productRepository = newProductRepository;
}

User *RepoProduct::getALTUser() const
{
    return ALTUser;
}

void RepoProduct::setALTUser(User *newALTUser)
{
    ALTUser = newALTUser;
}

const QString &RepoProduct::getUser() const
{
    return user;
}

void RepoProduct::setUser(const QString &newUser)
{
    user = newUser;
}

const QString &RepoProduct::getUpdatedAt() const
{
    return updatedAt;
}

void RepoProduct::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

const QString &RepoProduct::getCreatedAt() const
{
    return createdAt;
}

void RepoProduct::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

QList<QString> *RepoProduct::getALTCategories() const
{
    return ALTCategories != nullptr ? ALTCategories : new QList<QString>();
}

void RepoProduct::setALTCategories(QList<QString> *newALTCategories)
{
    ALTCategories = newALTCategories;
}

QList<Category> *RepoProduct::getCategories() const
{
    return categories != nullptr ? categories : new QList<Category>();
}

void RepoProduct::setCategories(QList<Category> *newCategories)
{
    categories = newCategories;
}

QList<Tag> *RepoProduct::getTags() const
{
    return tags != nullptr ? tags : new QList<Tag>();
}

void RepoProduct::setTags(QList<Tag> *newTags)
{
    tags = newTags;
}

bool RepoProduct::getHasEdited() const
{
    return hasEdited;
}

void RepoProduct::setHasEdited(bool newHasEdited)
{
    hasEdited = newHasEdited;
}

bool RepoProduct::getHasSibling() const
{
    return hasSibling;
}

void RepoProduct::setHasSibling(bool newHasSibling)
{
    hasSibling = newHasSibling;
}

bool RepoProduct::getIsFreeze() const
{
    return isFreeze;
}

void RepoProduct::setIsFreeze(bool newIsFreeze)
{
    isFreeze = newIsFreeze;
}

bool RepoProduct::getIsPrivate() const
{
    return isPrivate;
}

void RepoProduct::setIsPrivate(bool newIsPrivate)
{
    isPrivate = newIsPrivate;
}

bool RepoProduct::getIsProductRepositoryActive() const
{
    return isProductRepositoryActive;
}

void RepoProduct::setIsProductRepositoryActive(bool newIsProductRepositoryActive)
{
    isProductRepositoryActive = newIsProductRepositoryActive;
}

bool RepoProduct::getIsDiscounted() const
{
    return isDiscounted;
}

void RepoProduct::setIsDiscounted(bool newIsDiscounted)
{
    isDiscounted = newIsDiscounted;
}

const QString &RepoProduct::getProductRepositoryType() const
{
    return productRepositoryType;
}

void RepoProduct::setProductRepositoryType(const QString &newProductRepositoryType)
{
    productRepositoryType = newProductRepositoryType;
}

long RepoProduct::getProductRepositorySnapshot() const
{
    return productRepositorySnapshot;
}

void RepoProduct::setProductRepositorySnapshot(long newProductRepositorySnapshot)
{
    productRepositorySnapshot = newProductRepositorySnapshot;
}

long RepoProduct::getProductSnapshot() const
{
    return productSnapshot;
}

void RepoProduct::setProductSnapshot(long newProductSnapshot)
{
    productSnapshot = newProductSnapshot;
}

long RepoProduct::getTimesClone() const
{
    return timesClone;
}

void RepoProduct::setTimesClone(long newTimesClone)
{
    timesClone = newTimesClone;
}

long RepoProduct::getTotalView() const
{
    return totalView;
}

void RepoProduct::setTotalView(long newTotalView)
{
    totalView = newTotalView;
}

int RepoProduct::getTimesModified() const
{
    return timesModified;
}

void RepoProduct::setTimesModified(int newTimesModified)
{
    timesModified = newTimesModified;
}

double RepoProduct::getProductPrice() const
{
    return productPrice;
}

void RepoProduct::setProductPrice(double newProductPrice)
{
    productPrice = newProductPrice;
}

const QString &RepoProduct::getImageContainer() const
{
    return imageContainer;
}

void RepoProduct::setImageContainer(const QString &newImageContainer)
{
    imageContainer = newImageContainer;
}

QList<QString> *RepoProduct::getProductImages() const
{
    return productImages;
}

void RepoProduct::setProductImages(QList<QString> *newProductImages)
{
    productImages = newProductImages;
}

const QString &RepoProduct::getProductRepositoryThumbnail() const
{
    return productRepositoryThumbnail;
}

void RepoProduct::setProductRepositoryThumbnail(const QString &newProductRepositoryThumbnail)
{
    productRepositoryThumbnail = newProductRepositoryThumbnail;
}

const QString &RepoProduct::getProductRepositoryName() const
{
    return productRepositoryName;
}

void RepoProduct::setProductRepositoryName(const QString &newProductRepositoryName)
{
    productRepositoryName = newProductRepositoryName;
}

const QString &RepoProduct::getPostFixChar() const
{
    return postFixChar;
}

void RepoProduct::setPostFixChar(const QString &newPostFixChar)
{
    postFixChar = newPostFixChar;
}

const QString &RepoProduct::getDescription() const
{
    return description;
}

void RepoProduct::setDescription(const QString &newDescription)
{
    description = newDescription;
}

const QString &RepoProduct::getThumbnailUrl() const
{
    return thumbnailUrl;
}

void RepoProduct::setThumbnailUrl(const QString &newThumbnailUrl)
{
    thumbnailUrl = newThumbnailUrl;
}

Currency *RepoProduct::getCurrency() const
{
    return currency;
}

void RepoProduct::setCurrency(Currency *newCurrency)
{
    currency = newCurrency;
}

const QString &RepoProduct::getProductName() const
{
    return productName;
}

void RepoProduct::setProductName(const QString &newProductName)
{
    productName = newProductName;
}

bool RepoProduct::getIsSearchableStandalone() const
{
    return isSearchableStandalone;
}

void RepoProduct::setIsSearchableStandalone(bool newIsSearchableStandalone)
{
    isSearchableStandalone = newIsSearchableStandalone;
}

bool RepoProduct::getIsBarcodeVerified() const
{
    return isBarcodeVerified;
}

void RepoProduct::setIsBarcodeVerified(bool newIsBarcodeVerified)
{
    isBarcodeVerified = newIsBarcodeVerified;
}

const QString &RepoProduct::getBarcode() const
{
    return barcode;
}

void RepoProduct::setBarcode(const QString &newBarcode)
{
    barcode = newBarcode;
}

const QString &RepoProduct::getUrl() const
{
    return url;
}

void RepoProduct::setUrl(const QString &newUrl)
{
    url = newUrl;
}

const QString &RepoProduct::id() const
{
    return _id;
}

void RepoProduct::setId(const QString &newId)
{
    _id = newId;
}


QString RepoProduct::getEncryptedData()
{
    return encode();
}

QList<int> RepoProduct::getActionTypes()
{
    // Change here!! need to change in all other projects
    QList<int> actions;
    actions.append(action_type->IMPORT);
    actions.append(action_type->SEARCH);
    actions.append(action_type->BOOKMARK);
    return actions;
}

QString RepoProduct::encode()
{
    //return qrSignaturePatterns.createRepoProductQRCode(this);
}

QList<QString> RepoProduct::getAllFields()
{

}

QString RepoProduct::getPackageName()
{
    return this->className;
}

QList<RepoProduct *> RepoProduct::parseJSONArray(QJsonArray o) throw()
{

}

RepoProduct *RepoProduct::parseJSONObject(QJsonObject o) throw()
{

}

QList<RepoProduct *> RepoProduct::parseArrayString(QString o) throw()
{

}

RepoProduct *RepoProduct::parseObjectString(QString o) throw()
{

}

bool RepoProduct::equal(RepoProduct *o)
{
    return o == this;
}

QList<QString> *RepoProduct::onlyIDS(QList<RepoProduct> *repoProducts)
{
    QList<QString> *ids = new QList<QString>();
    for (int var = 0; var < repoProducts ->size(); ++var) {
        ids->append(repoProducts ->at(var).id());
    }
    return ids;
}

bool RepoProduct::isCreator(const User* user) const
{
    if (user == nullptr) return false;
    return getUser().compare(user->getId());
}

bool RepoProduct::isRepoOwner(User *user) const
{
    if (user == nullptr) return false;
    return getProductRepository().compare(user->getId());
}

bool RepoProduct::isParentMasterRepository()
{
    return getProductRepositoryType().compare(MASTER);
}

QString RepoProduct::getFormattedTotalViews()
{
    // return helper.formatView(getTotalView());
}

QString RepoProduct::getFormattedTimesClone()
{
    // return helper.formatView(getTimesClone());
}

QString RepoProduct::getCorrectThumbnailUrl(QString imageContainers)
{
    // return helper.decideAppropriateUrlAmong(imageContainers, getThumbnailUrl());
}

QString RepoProduct::getCurrencyName()
{
    return getCurrency()->getCurrencyName();
}

bool RepoProduct::hasPostFix()
{
    return getPostFixChar() != nullptr && !getPostFixChar().compare("null");
}

QString RepoProduct::getFormattedRepositorySnapshot()
{
    return QString("#%1").arg(getProductRepositorySnapshot());
}

QString RepoProduct::getProductProductionState()
{
    return getIsDiscounted() ? STOPPED_PRODUCTION : CONTINUED_PRODUCTION;
}

QString RepoProduct::getFormattedProductSnapshot()
{
    return hasPostFix() ?
                QString("#%1%2%3").arg(getProductSnapshot()).arg(SNAPSHOT_SEPARATOR).arg(getPostFixChar())
              : QString("#%1").arg(getProductSnapshot());
}

bool RepoProduct::isBackupStagedProduct()
{
    return getProductRepositoryType() != nullptr && isParentMasterRepository();
}

QString RepoProduct::getFormattedPrice()
{
    // Currency c;
    // return QString("%1%1").arg(c.getCurrencySymbolByCurrencyCode(getCurrency()->getCurrencyCode()).arg(helper.refineDecimalAndGroup(getProductPrice()));
}

QString RepoProduct::getFormattedTotalViewsAndTotalClones()
{
    // return QString("%1 %2, %3 %4").arg(getFormattedTotalViews()).arg(VIEWS).arg(getFormattedTimesClone()).arg(CLONES));
}

bool RepoProduct::hasCategories()
{
    return getCategories()->size() > 0;
}

bool RepoProduct::hasTags()
{
    return getTags() != nullptr && getTags()->size() > 0;
}
