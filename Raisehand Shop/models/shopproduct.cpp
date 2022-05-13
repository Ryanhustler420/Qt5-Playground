#include "models/shopproduct.h"

ShopProduct::ShopProduct(const QString &id, const QString &url, Location *location, const QString &repoProduct, Currency *baseCurrency, const QString &shop, const QString &shopName, bool isFreeze, bool isShopAlive, const QString &tier, long likes, long totalView, const QString &aka, double price, double quantity, const QString &secret, const QString &offer, const QString &condition, bool isPrivate, bool isShowcased, QList<Tag> *tags, const QString &name, long snapshot, const QString &postFixChar, const QString &milestone, const QString &thumbnail, const QString &description, const QString &productRepositoryName, const QString &productRepositoryThumbnail, QList<QString> *images, const QString &imageContainer, QList<Category> *categories, QList<QString> *ALTCategories, SiUnit *siUnit, const QString &ALTSiUnit, QList<RepoProduct> *bakedInside, QList<QString> *ALTBakedInside, QList<RepoProduct> *spareParts, QList<QString> *ALTSpareParts, const QString &createdAt, const QString &updatedAt)
{
    this->_id = id;
    this->url = url,
    this->location = location;
    this->repoProduct = repoProduct;
    this->baseCurrency = baseCurrency;
    this->shop = shop;
    this->shopName = shopName;
    this->isFreeze = isFreeze;
    this->isShopAlive = isShopAlive;
    this->tier = tier;
    this->likes = likes;
    this->totalView = totalView;
    this->aka = aka;
    this->price = price;
    this->quantity = quantity;
    this->secret = secret;
    this->offer = offer;
    this->condition = condition;
    this->isPrivate = isPrivate;
    this->isShowcased = isShowcased;
    this->tags = tags;
    this->name = name;
    this->snapshot = snapshot;
    this->postFixChar = postFixChar;
    this->milestone = milestone;
    this->thumbnail = thumbnail;
    this->description = description;
    this->productRepositoryName = productRepositoryName;
    this->productRepositoryThumbnail = productRepositoryThumbnail;
    this->images = images;
    this->imageContainer = imageContainer;
    this->categories = categories;
    this->ALTCategories = ALTCategories;
    this->siUnit = siUnit;
    this->ALTSiUnit = ALTSiUnit;
    this->bakedInside = bakedInside;
    this->ALTBakedInside = ALTBakedInside;
    this->spareParts = spareParts;
    this->ALTSpareParts = ALTSpareParts;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    this->className = "ShopProduct";
    this->fields = new _fields();
    this->action_type = new _action_type();
}

const QString &ShopProduct::getUpdatedAt() const
{
    return updatedAt;
}

void ShopProduct::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

const QString &ShopProduct::getCreatedAt() const
{
    return createdAt;
}

void ShopProduct::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

QList<QString> *ShopProduct::getALTSpareParts() const
{
    return ALTSpareParts != nullptr ? ALTSpareParts : new QList<QString>();
}

void ShopProduct::setALTSpareParts(QList<QString> *newALTSpareParts)
{
    ALTSpareParts = newALTSpareParts;
}

QList<RepoProduct> *ShopProduct::getSpareParts() const
{
    return spareParts != nullptr ? spareParts : new QList<RepoProduct>();
}

void ShopProduct::setSpareParts(QList<RepoProduct> *newSpareParts)
{
    spareParts = newSpareParts;
}

QList<QString> *ShopProduct::getALTBakedInside() const
{
    return ALTBakedInside != nullptr ? ALTBakedInside : new QList<QString>();
}

void ShopProduct::setALTBakedInside(QList<QString> *newALTBakedInside)
{
    ALTBakedInside = newALTBakedInside;
}

QList<RepoProduct> *ShopProduct::getBakedInside() const
{
    return bakedInside != nullptr ? bakedInside : new QList<RepoProduct>();
}

void ShopProduct::setBakedInside(QList<RepoProduct> *newBakedInside)
{
    bakedInside = newBakedInside;
}

const QString &ShopProduct::getALTSiUnit() const
{
    return ALTSiUnit;
}

void ShopProduct::setALTSiUnit(const QString &newALTSiUnit)
{
    ALTSiUnit = newALTSiUnit;
}

SiUnit *ShopProduct::getSiUnit() const
{
    return siUnit;
}

void ShopProduct::setSiUnit(SiUnit *newSiUnit)
{
    siUnit = newSiUnit;
}

QList<QString> *ShopProduct::getALTCategories() const
{
    return ALTCategories != nullptr ? ALTCategories : new QList<QString>();
}

void ShopProduct::setALTCategories(QList<QString> *newALTCategories)
{
    ALTCategories = newALTCategories;
}

QList<Category> *ShopProduct::getCategories() const
{
    return categories != nullptr ? categories : new QList<Category>();
}

void ShopProduct::setCategories(QList<Category> *newCategories)
{
    categories = newCategories;
}

const QString &ShopProduct::getImageContainer() const
{
    return imageContainer;
}

void ShopProduct::setImageContainer(const QString &newImageContainer)
{
    imageContainer = newImageContainer;
}

QList<QString> *ShopProduct::getImages() const
{
    return images != nullptr ? images : new QList<QString>();
}

void ShopProduct::setImages(QList<QString> *newImages)
{
    images = newImages;
}

const QString &ShopProduct::getProductRepositoryThumbnail() const
{
    return productRepositoryThumbnail;
}

void ShopProduct::setProductRepositoryThumbnail(const QString &newProductRepositoryThumbnail)
{
    productRepositoryThumbnail = newProductRepositoryThumbnail;
}

const QString &ShopProduct::getProductRepositoryName() const
{
    return productRepositoryName;
}

void ShopProduct::setProductRepositoryName(const QString &newProductRepositoryName)
{
    productRepositoryName = newProductRepositoryName;
}

const QString &ShopProduct::getDescription() const
{
    return description;
}

void ShopProduct::setDescription(const QString &newDescription)
{
    description = newDescription;
}

const QString &ShopProduct::getThumbnail() const
{
    return thumbnail;
}

void ShopProduct::setThumbnail(const QString &newThumbnail)
{
    thumbnail = newThumbnail;
}

const QString &ShopProduct::getMilestone() const
{
    return milestone;
}

void ShopProduct::setMilestone(const QString &newMilestone)
{
    milestone = newMilestone;
}

const QString &ShopProduct::getPostFixChar() const
{
    return postFixChar;
}

void ShopProduct::setPostFixChar(const QString &newPostFixChar)
{
    postFixChar = newPostFixChar;
}

long ShopProduct::getSnapshot() const
{
    return snapshot;
}

void ShopProduct::setSnapshot(long newSnapshot)
{
    snapshot = newSnapshot;
}

const QString &ShopProduct::getName() const
{
    return name;
}

void ShopProduct::setName(const QString &newName)
{
    name = newName;
}

QList<Tag> *ShopProduct::getTags() const
{
    return tags != nullptr ? tags : new QList<Tag>();
}

void ShopProduct::setTags(QList<Tag> *newTags)
{
    tags = newTags;
}

bool ShopProduct::getIsShowcased() const
{
    return isShowcased;
}

void ShopProduct::setIsShowcased(bool newIsShowcased)
{
    isShowcased = newIsShowcased;
}

bool ShopProduct::getIsPrivate() const
{
    return isPrivate;
}

void ShopProduct::setIsPrivate(bool newIsPrivate)
{
    isPrivate = newIsPrivate;
}

const QString &ShopProduct::getCondition() const
{
    return condition;
}

void ShopProduct::setCondition(const QString &newCondition)
{
    condition = newCondition;
}

const QString &ShopProduct::getOffer() const
{
    return offer;
}

void ShopProduct::setOffer(const QString &newOffer)
{
    offer = newOffer;
}

const QString &ShopProduct::getSecret() const
{
    return secret;
}

void ShopProduct::setSecret(const QString &newSecret)
{
    secret = newSecret;
}

double ShopProduct::getQuantity() const
{
    return quantity;
}

void ShopProduct::setQuantity(double newQuantity)
{
    quantity = newQuantity;
}

double ShopProduct::getPrice() const
{
    return price;
}

void ShopProduct::setPrice(double newPrice)
{
    price = newPrice;
}

const QString &ShopProduct::getAka() const
{
    return aka;
}

void ShopProduct::setAka(const QString &newAka)
{
    aka = newAka;
}

long ShopProduct::getTotalView() const
{
    return totalView;
}

void ShopProduct::setTotalView(long newTotalView)
{
    totalView = newTotalView;
}

long ShopProduct::getLikes() const
{
    return likes;
}

void ShopProduct::setLikes(long newLikes)
{
    likes = newLikes;
}

const QString &ShopProduct::getTier() const
{
    return tier;
}

void ShopProduct::setTier(const QString &newTier)
{
    tier = newTier;
}

bool ShopProduct::getIsShopAlive() const
{
    return isShopAlive;
}

void ShopProduct::setIsShopAlive(bool newIsShopAlive)
{
    isShopAlive = newIsShopAlive;
}

bool ShopProduct::getIsFreeze() const
{
    return isFreeze;
}

void ShopProduct::setIsFreeze(bool newIsFreeze)
{
    isFreeze = newIsFreeze;
}

const QString &ShopProduct::getShopName() const
{
    return shopName;
}

void ShopProduct::setShopName(const QString &newShopName)
{
    shopName = newShopName;
}

const QString &ShopProduct::getShop() const
{
    return shop;
}

void ShopProduct::setShop(const QString &newShop)
{
    shop = newShop;
}

Currency *ShopProduct::getBaseCurrency() const
{
    return baseCurrency;
}

void ShopProduct::setBaseCurrency(Currency *newBaseCurrency)
{
    baseCurrency = newBaseCurrency;
}

const QString &ShopProduct::getRepoProduct() const
{
    return repoProduct;
}

void ShopProduct::setRepoProduct(const QString &newRepoProduct)
{
    repoProduct = newRepoProduct;
}

Location *ShopProduct::getLocation() const
{
    return location;
}

void ShopProduct::setLocation(Location *newLocation)
{
    location = newLocation;
}

const QString &ShopProduct::getUrl() const
{
    return url;
}

void ShopProduct::setUrl(const QString &newUrl)
{
    url = newUrl;
}

const QString &ShopProduct::id() const
{
    return _id;
}

void ShopProduct::setId(const QString &newId)
{
    _id = newId;
}

QString ShopProduct::getEncryptedData()
{
    return encode();
}

QList<int> ShopProduct::getActionTypes()
{
    // Change here!! need to change in all other projects
    QList<int> actions;
    actions.append(action_type->SEARCH);
    actions.append(action_type->BOOKMARK);
    return actions;
}

QString ShopProduct::encode()
{
    // return qrSignaturePatterns.createShopQRCode(this);
}

QList<QString> ShopProduct::getAllFields()
{

}

QString ShopProduct::getPackageName()
{
    return this->className;
}

QList<ShopProduct *> ShopProduct::parseJSONArray(QJsonArray o) throw()
{

}

ShopProduct *ShopProduct::parseJSONObject(QJsonObject o) throw()
{

}

QList<ShopProduct *> ShopProduct::parseArrayString(QString o) throw()
{

}

ShopProduct *ShopProduct::parseObjectString(QString o) throw()
{

}

bool ShopProduct::equal(ShopProduct *o)
{
    return o == this;
}
