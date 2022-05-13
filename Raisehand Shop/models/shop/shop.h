#ifndef SHOP_H
#define SHOP_H

#include "models/god/modelconventions.h"
#include "qr_signature/jwtencoder.h"
#include "models/shop/workingtime.h"
#include "qr_signature/iocode.h"
#include "models/shopproduct.h"
#include "models/user/user.h"
#include "models/currency.h"
#include "models/category.h"
#include "models/location.h"

class Shop :
        public ModelConventions<Shop>,
        public JwtEncoder,
        public IOCode
{
    Q_OBJECT
public:
    explicit Shop(QObject *parent = nullptr);
    Shop(const QString &id, Currency *baseCurrency, Location *location, const QString &name, const QString &flavour, const QString &milestone, long indexFigure, const QString &owner, User *ALTOwner, const QString &thumbnail, QList<QString> *images, const QString &imageContainer, const QString &overview, bool isOpen, const QString &noticeBoard, const QString &address, const QString &gstNumber, const QString &phoneNumber, QList<int> *workingDays, WorkingTime *workingTime, QList<Category> *categories, QList<QString> *ALTCategories, QList<QString> *services, QList<QString> *paymentMethods, QList<ShopProduct> *showcase, QList<QString> *ALTShowcase, long likes, long totalView, long iBVerificationCode, bool isIBReceived, Shop *leftHandShop, const QString &ALTLeftHandShop, const QString &tier, const QString &lastPaymentOn, int lastPaymentPlanValidForDays, int inventoryLength, bool isAlive, bool isPrivate, int showcaseCapacity, int maxServicesCapacity, const QString &createdAt, const QString &updatedAt);

public:
    static int const CLASS_NUMBER = 1; // please never change this...

private:
    QString _id;
    Currency* baseCurrency;
    Location* location;
    QString name;
    QString flavour;
    QString milestone;
    long indexFigure;
    QString owner;
    User* ALTOwner;
    QString thumbnail;
    QList<QString>* images;
    QString imageContainer;
    QString overview;
    bool isOpen;
    QString noticeBoard;
    QString address;
    QString gstNumber;
    QString phoneNumber;
    QList<int>* workingDays;
    WorkingTime* workingTime;
    QList<Category>* categories;
    QList<QString>* ALTCategories;
    QList<QString>* services;
    QList<QString>* paymentMethods;
    QList<ShopProduct>* showcase;
    QList<QString>* ALTShowcase;
    long likes;
    long totalView;
    long iBVerificationCode;
    bool isIBReceived;
    Shop* leftHandShop;
    QString ALTLeftHandShop;
    QString tier;
    QString lastPaymentOn;
    int lastPaymentPlanValidForDays;
    int inventoryLength;
    bool isAlive;
    bool isPrivate;
    int showcaseCapacity;
    int maxServicesCapacity;
    QString createdAt;
    QString updatedAt;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString baseCurrency = "baseCurrency";
        QString location = "location";
        QString name = "name";
        QString flavour = "flavour";
        QString milestone = "milestone";
        QString indexFigure = "indexFigure";
        QString owner = "owner";
        QString ALTOwner = "ALTOwner";
        QString thumbnail = "thumbnail";
        QString images = "images";
        QString imageContainer = "imageContainer";
        QString overview = "overview";
        QString isOpen = "isOpen";
        QString noticeBoard = "noticeBoard";
        QString address = "address";
        QString gstNumber = "gstNumber";
        QString phoneNumber = "phoneNumber";
        QString workingDays = "workingDays";
        QString workingTime = "workingTime";
        QString categories = "categories";
        QString ALTCategories = "ALTCategories";
        QString services = "services";
        QString paymentMethods = "paymentMethods";
        QString showcase = "showcase";
        QString ALTShowcase = "ALTShowcase";
        QString likes = "likes";
        QString totalView = "totalView";
        QString iBVerificationCode = "iBVerificationCode";
        QString isIBReceived = "isIBReceived";
        QString leftHandShop = "leftHandShop";
        QString ALTLeftHandShop = "ALTLeftHandShop";
        QString lastPaymentOn = "lastPaymentOn";
        QString lastPaymentPlanValidForDays = "lastPaymentPlanValidForDays";
        QString inventoryLength = "inventoryLength";
        QString isAlive = "isAlive";
        QString isPrivate = "isPrivate";
        QString showcaseCapacity = "showcaseCapacity";
        QString maxServicesCapacity = "maxServicesCapacity";
        QString createdAt = "createdAt";
        QString updatedAt = "updatedAt";
    } _fields;

    _fields *fields;
    _action_type *action_type;

signals:

    // IOCode interface
public:
    QString getEncryptedData();
    QList<int> getActionTypes();

    // JwtEncoder interface
public:
    QString encode();

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Shop *> parseJSONArray(QJsonArray o) throw();
    Shop *parseJSONObject(QJsonObject o) throw();
    QList<Shop *> parseArrayString(QString o) throw();
    Shop *parseObjectString(QString o) throw();
    bool equal(Shop *o);

public:
    const QString &id() const;
    void setId(const QString &newId);
    Currency *getBaseCurrency() const;
    void setBaseCurrency(Currency *newBaseCurrency);
    Location *getLocation() const;
    void setLocation(Location *newLocation);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getFlavour() const;
    void setFlavour(const QString &newFlavour);
    const QString &getMilestone() const;
    void setMilestone(const QString &newMilestone);
    long getIndexFigure() const;
    void setIndexFigure(long newIndexFigure);
    const QString &getOwner() const;
    void setOwner(const QString &newOwner);
    User *getALTOwner() const;
    void setALTOwner(User *newALTOwner);
    const QString &getThumbnail() const;
    void setThumbnail(const QString &newThumbnail);
    QList<QString> *getImages() const;
    void setImages(QList<QString> *newImages);
    const QString &getImageContainer() const;
    void setImageContainer(const QString &newImageContainer);
    const QString &getOverview() const;
    void setOverview(const QString &newOverview);
    bool getIsOpen() const;
    void setIsOpen(bool newIsOpen);
    const QString &getNoticeBoard() const;
    void setNoticeBoard(const QString &newNoticeBoard);
    const QString &getAddress() const;
    void setAddress(const QString &newAddress);
    const QString &getGstNumber() const;
    void setGstNumber(const QString &newGstNumber);
    const QString &getPhoneNumber() const;
    void setPhoneNumber(const QString &newPhoneNumber);
    QList<int> *getWorkingDays() const;
    void setWorkingDays(QList<int> *newWorkingDays);
    WorkingTime *getWorkingTime() const;
    void setWorkingTime(WorkingTime *newWorkingTime);
    QList<Category> *getCategories() const;
    void setCategories(QList<Category> *newCategories);
    QList<QString> *getALTCategories() const;
    void setALTCategories(QList<QString> *newALTCategories);
    QList<QString> *getServices() const;
    void setServices(QList<QString> *newServices);
    QList<QString> *getPaymentMethods() const;
    void setPaymentMethods(QList<QString> *newPaymentMethods);
    QList<ShopProduct> *getShowcase() const;
    void setShowcase(QList<ShopProduct> *newShowcase);
    QList<QString> *getALTShowcase() const;
    void setALTShowcase(QList<QString> *newALTShowcase);
    long getLikes() const;
    void setLikes(long newLikes);
    long getTotalView() const;
    void setTotalView(long newTotalView);
    long getIBVerificationCode() const;
    void setIBVerificationCode(long newIBVerificationCode);
    bool getIsIBReceived() const;
    void setIsIBReceived(bool newIsIBReceived);
    Shop *getLeftHandShop() const;
    void setLeftHandShop(Shop *newLeftHandShop);
    const QString &getALTLeftHandShop() const;
    void setALTLeftHandShop(const QString &newALTLeftHandShop);
    const QString &getTier() const;
    void setTier(const QString &newTier);
    const QString &getLastPaymentOn() const;
    void setLastPaymentOn(const QString &newLastPaymentOn);
    int getLastPaymentPlanValidForDays() const;
    void setLastPaymentPlanValidForDays(int newLastPaymentPlanValidForDays);
    int getInventoryLength() const;
    void setInventoryLength(int newInventoryLength);
    bool getIsAlive() const;
    void setIsAlive(bool newIsAlive);
    bool getIsPrivate() const;
    void setIsPrivate(bool newIsPrivate);
    int getShowcaseCapacity() const;
    void setShowcaseCapacity(int newShowcaseCapacity);
    int getMaxServicesCapacity() const;
    void setMaxServicesCapacity(int newMaxServicesCapacity);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);

};

#endif // SHOP_H
