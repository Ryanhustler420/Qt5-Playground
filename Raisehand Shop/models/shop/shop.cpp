#include "models/shop/shop.h"

Shop::Shop(const QString &id, Currency *baseCurrency, Location *location, const QString &name, const QString &flavour, const QString &milestone, long indexFigure, const QString &owner, User *ALTOwner, const QString &thumbnail, QList<QString> *images, const QString &imageContainer, const QString &overview, bool isOpen, const QString &noticeBoard, const QString &address, const QString &gstNumber, const QString &phoneNumber, QList<int> *workingDays, WorkingTime *workingTime, QList<Category> *categories, QList<QString> *ALTCategories, QList<QString> *services, QList<QString> *paymentMethods, QList<ShopProduct> *showcase, QList<QString> *ALTShowcase, long likes, long totalView, long iBVerificationCode, bool isIBReceived, Shop *leftHandShop, const QString &ALTLeftHandShop, const QString &tier, const QString &lastPaymentOn, int lastPaymentPlanValidForDays, int inventoryLength, bool isAlive, bool isPrivate, int showcaseCapacity, int maxServicesCapacity, const QString &createdAt, const QString &updatedAt)
{
    this->_id = id;
    this->baseCurrency = baseCurrency;
    this->location = location;
    this->name = name;
    this->flavour = flavour;
    this->milestone = milestone;
    this->indexFigure = indexFigure;
    this->owner = owner;
    this->ALTOwner = ALTOwner;
    this->thumbnail = thumbnail;
    this->images = images;
    this->imageContainer = imageContainer;
    this->overview = overview;
    this->isOpen = isOpen;
    this->noticeBoard = noticeBoard;
    this->address = address;
    this->gstNumber = gstNumber;
    this->phoneNumber = phoneNumber;
    this->workingDays = workingDays;
    this->workingTime = workingTime;
    this->categories = categories;
    this->ALTCategories = ALTCategories;
    this->services = services;
    this->paymentMethods = paymentMethods;
    this->showcase = showcase;
    this->ALTShowcase = ALTShowcase;
    this->likes = likes;
    this->totalView = totalView;
    this->iBVerificationCode = iBVerificationCode;
    this->isIBReceived = isIBReceived;
    this->leftHandShop = leftHandShop;
    this->ALTLeftHandShop = ALTLeftHandShop;
    this->tier = tier;
    this->lastPaymentOn = lastPaymentOn;
    this->lastPaymentPlanValidForDays = lastPaymentPlanValidForDays;
    this->inventoryLength = inventoryLength;
    this->isAlive = isAlive;
    this->isPrivate = isPrivate;
    this->showcaseCapacity = showcaseCapacity;
    this->maxServicesCapacity = maxServicesCapacity;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    this->className = "Shop";
    this->fields = new _fields();
    this->action_type = new _action_type();
}

const QString &Shop::getUpdatedAt() const
{
    return updatedAt;
}

void Shop::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

const QString &Shop::getCreatedAt() const
{
    return createdAt;
}

void Shop::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

int Shop::getMaxServicesCapacity() const
{
    return maxServicesCapacity;
}

void Shop::setMaxServicesCapacity(int newMaxServicesCapacity)
{
    maxServicesCapacity = newMaxServicesCapacity;
}

int Shop::getShowcaseCapacity() const
{
    return showcaseCapacity;
}

void Shop::setShowcaseCapacity(int newShowcaseCapacity)
{
    showcaseCapacity = newShowcaseCapacity;
}

bool Shop::getIsPrivate() const
{
    return isPrivate;
}

void Shop::setIsPrivate(bool newIsPrivate)
{
    isPrivate = newIsPrivate;
}

bool Shop::getIsAlive() const
{
    return isAlive;
}

void Shop::setIsAlive(bool newIsAlive)
{
    isAlive = newIsAlive;
}

int Shop::getInventoryLength() const
{
    return inventoryLength;
}

void Shop::setInventoryLength(int newInventoryLength)
{
    inventoryLength = newInventoryLength;
}

int Shop::getLastPaymentPlanValidForDays() const
{
    return lastPaymentPlanValidForDays;
}

void Shop::setLastPaymentPlanValidForDays(int newLastPaymentPlanValidForDays)
{
    lastPaymentPlanValidForDays = newLastPaymentPlanValidForDays;
}

const QString &Shop::getLastPaymentOn() const
{
    return lastPaymentOn;
}

void Shop::setLastPaymentOn(const QString &newLastPaymentOn)
{
    lastPaymentOn = newLastPaymentOn;
}

const QString &Shop::getTier() const
{
    return tier;
}

void Shop::setTier(const QString &newTier)
{
    tier = newTier;
}

const QString &Shop::getALTLeftHandShop() const
{
    return ALTLeftHandShop;
}

void Shop::setALTLeftHandShop(const QString &newALTLeftHandShop)
{
    ALTLeftHandShop = newALTLeftHandShop;
}

Shop *Shop::getLeftHandShop() const
{
    return leftHandShop;
}

void Shop::setLeftHandShop(Shop *newLeftHandShop)
{
    leftHandShop = newLeftHandShop;
}

bool Shop::getIsIBReceived() const
{
    return isIBReceived;
}

void Shop::setIsIBReceived(bool newIsIBReceived)
{
    isIBReceived = newIsIBReceived;
}

long Shop::getIBVerificationCode() const
{
    return iBVerificationCode;
}

void Shop::setIBVerificationCode(long newIBVerificationCode)
{
    iBVerificationCode = newIBVerificationCode;
}

long Shop::getTotalView() const
{
    return totalView;
}

void Shop::setTotalView(long newTotalView)
{
    totalView = newTotalView;
}

long Shop::getLikes() const
{
    return likes;
}

void Shop::setLikes(long newLikes)
{
    likes = newLikes;
}

QList<QString> *Shop::getALTShowcase() const
{
    return ALTShowcase != nullptr ? ALTShowcase : new QList<QString>();
}

void Shop::setALTShowcase(QList<QString> *newALTShowcase)
{
    ALTShowcase = newALTShowcase;
}

QList<ShopProduct> *Shop::getShowcase() const
{
    return showcase != nullptr ? showcase : new QList<ShopProduct>();
}

void Shop::setShowcase(QList<ShopProduct> *newShowcase)
{
    showcase = newShowcase;
}

QList<QString> *Shop::getPaymentMethods() const
{
    return paymentMethods != nullptr ? paymentMethods : new QList<QString>();
}

void Shop::setPaymentMethods(QList<QString> *newPaymentMethods)
{
    paymentMethods = newPaymentMethods;
}

QList<QString> *Shop::getServices() const
{
    return services != nullptr ? services : new QList<QString>();
}

void Shop::setServices(QList<QString> *newServices)
{
    services = newServices;
}

QList<QString> *Shop::getALTCategories() const
{
    return ALTCategories != nullptr ? ALTCategories : new QList<QString>();
}

void Shop::setALTCategories(QList<QString> *newALTCategories)
{
    ALTCategories = newALTCategories;
}

QList<Category> *Shop::getCategories() const
{
    return categories != nullptr ? categories : new QList<Category>();
}

void Shop::setCategories(QList<Category> *newCategories)
{
    categories = newCategories;
}

WorkingTime *Shop::getWorkingTime() const
{
    return workingTime;
}

void Shop::setWorkingTime(WorkingTime *newWorkingTime)
{
    workingTime = newWorkingTime;
}

QList<int> *Shop::getWorkingDays() const
{
    return workingDays != nullptr ? workingDays : new QList<int>();
}

void Shop::setWorkingDays(QList<int> *newWorkingDays)
{
    workingDays = newWorkingDays;
}

const QString &Shop::getPhoneNumber() const
{
    return phoneNumber;
}

void Shop::setPhoneNumber(const QString &newPhoneNumber)
{
    phoneNumber = newPhoneNumber;
}

const QString &Shop::getGstNumber() const
{
    return gstNumber;
}

void Shop::setGstNumber(const QString &newGstNumber)
{
    gstNumber = newGstNumber;
}

const QString &Shop::getAddress() const
{
    return address;
}

void Shop::setAddress(const QString &newAddress)
{
    address = newAddress;
}

const QString &Shop::getNoticeBoard() const
{
    return noticeBoard;
}

void Shop::setNoticeBoard(const QString &newNoticeBoard)
{
    noticeBoard = newNoticeBoard;
}

bool Shop::getIsOpen() const
{
    return isOpen;
}

void Shop::setIsOpen(bool newIsOpen)
{
    isOpen = newIsOpen;
}

const QString &Shop::getOverview() const
{
    return overview;
}

void Shop::setOverview(const QString &newOverview)
{
    overview = newOverview;
}

const QString &Shop::getImageContainer() const
{
    return imageContainer;
}

void Shop::setImageContainer(const QString &newImageContainer)
{
    imageContainer = newImageContainer;
}

QList<QString> *Shop::getImages() const
{
    return images != nullptr ? images : new QList<QString>();
}

void Shop::setImages(QList<QString> *newImages)
{
    images = newImages;
}

const QString &Shop::getThumbnail() const
{
    return thumbnail;
}

void Shop::setThumbnail(const QString &newThumbnail)
{
    thumbnail = newThumbnail;
}

User *Shop::getALTOwner() const
{
    return ALTOwner;
}

void Shop::setALTOwner(User *newALTOwner)
{
    ALTOwner = newALTOwner;
}

const QString &Shop::getOwner() const
{
    return owner;
}

void Shop::setOwner(const QString &newOwner)
{
    owner = newOwner;
}

long Shop::getIndexFigure() const
{
    return indexFigure;
}

void Shop::setIndexFigure(long newIndexFigure)
{
    indexFigure = newIndexFigure;
}

const QString &Shop::getMilestone() const
{
    return milestone;
}

void Shop::setMilestone(const QString &newMilestone)
{
    milestone = newMilestone;
}

const QString &Shop::getFlavour() const
{
    return flavour;
}

void Shop::setFlavour(const QString &newFlavour)
{
    flavour = newFlavour;
}

const QString &Shop::getName() const
{
    return name;
}

void Shop::setName(const QString &newName)
{
    name = newName;
}

Location *Shop::getLocation() const
{
    return location;
}

void Shop::setLocation(Location *newLocation)
{
    location = newLocation;
}

Currency *Shop::getBaseCurrency() const
{
    return baseCurrency;
}

void Shop::setBaseCurrency(Currency *newBaseCurrency)
{
    baseCurrency = newBaseCurrency;
}

const QString &Shop::id() const
{
    return _id;
}

void Shop::setId(const QString &newId)
{
    _id = newId;
}

QString Shop::getEncryptedData()
{
    return encode();
}

QList<int> Shop::getActionTypes()
{
    // Change here!! need to change in all other projects
    QList<int> actions;
    actions.append(action_type->SEARCH);
    actions.append(action_type->BOOKMARK);
    return actions;
}

QString Shop::encode()
{
    // return qrSignaturePatterns.createShopProductQRCode(this);
}

QList<QString> Shop::getAllFields()
{

}

QString Shop::getPackageName()
{
    return this->className;
}

QList<Shop *> Shop::parseJSONArray(QJsonArray o) throw()
{

}

Shop *Shop::parseJSONObject(QJsonObject o) throw()
{

}

QList<Shop *> Shop::parseArrayString(QString o) throw()
{

}

Shop *Shop::parseObjectString(QString o) throw()
{

}

bool Shop::equal(Shop *o)
{
    return o == this;
}
