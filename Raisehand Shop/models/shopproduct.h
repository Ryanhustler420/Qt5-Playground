#ifndef SHOPPRODUCT_H
#define SHOPPRODUCT_H

#include "models/repo_product/repoproduct.h"
#include "models/god/modelconventions.h"
#include "qr_signature/jwtencoder.h"
#include "models/repo_product/tag.h"
#include "qr_signature/iocode.h"
#include "models/location.h"
#include "models/currency.h"
#include "models/category.h"
#include "models/siunit.h"

class ShopProduct :
        public ModelConventions<ShopProduct>,
        public JwtEncoder,
        public IOCode
{
    Q_OBJECT
public:
    explicit ShopProduct(QObject *parent = nullptr);
    ShopProduct(const QString &id, const QString &url, Location *location, const QString &repoProduct, Currency *baseCurrency, const QString &shop, const QString &shopName, bool isFreeze, bool isShopAlive, const QString &tier, long likes, long totalView, const QString &aka, double price, double quantity, const QString &secret, const QString &offer, const QString &condition, bool isPrivate, bool isShowcased, QList<Tag> *tags, const QString &name, long snapshot, const QString &postFixChar, const QString &milestone, const QString &thumbnail, const QString &description, const QString &productRepositoryName, const QString &productRepositoryThumbnail, QList<QString> *images, const QString &imageContainer, QList<Category> *categories, QList<QString> *ALTCategories, SiUnit *siUnit, const QString &ALTSiUnit, QList<RepoProduct> *bakedInside, QList<QString> *ALTBakedInside, QList<RepoProduct> *spareParts, QList<QString> *ALTSpareParts, const QString &createdAt, const QString &updatedAt);

public:
    static int const CLASS_NUMBER = 2; // please never change this...

private:
    QString _id;
    QString url;
    Location* location;
    QString repoProduct;
    Currency* baseCurrency;
    QString shop;
    QString shopName;
    bool isFreeze;
    bool isShopAlive;
    QString tier;
    long likes;
    long totalView;
    QString aka;
    double price;
    double quantity;
    QString secret;
    QString offer;
    QString condition;
    bool isPrivate;
    bool isShowcased;
    QList<Tag>* tags;
    QString name;
    long snapshot;
    QString postFixChar;
    QString milestone;
    QString thumbnail;
    QString description;
    QString productRepositoryName;
    QString productRepositoryThumbnail;
    QList<QString>* images;
    QString imageContainer;
    QList<Category>* categories;
    QList<QString>* ALTCategories;
    SiUnit* siUnit;
    QString ALTSiUnit;
    QList<RepoProduct>* bakedInside;
    QList<QString>* ALTBakedInside;
    QList<RepoProduct>* spareParts;
    QList<QString>* ALTSpareParts;
    QString createdAt;
    QString updatedAt;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString url = "url";
        QString location = "location";
        QString repoProduct = "repoProduct";
        QString baseCurrency = "baseCurrency";
        QString shop = "shop";
        QString shopName = "shopName";
        QString isFreeze = "isFreeze";
        QString isShopAlive = "isShopAlive";
        QString tier = "tier";
        QString likes = "likes";
        QString totalView = "totalView";
        QString aka = "aka";
        QString price = "price";
        QString quantity = "quantity";
        QString secret = "secret";
        QString offer = "offer";
        QString condition = "condition";
        QString isPrivate = "isPrivate";
        QString isShowcased = "isShowcased";
        QString tags = "tags";
        QString name = "name";
        QString snapshot = "snapshot";
        QString postFixChar = "postFixChar";
        QString milestone = "milestone";
        QString thumbnail = "thumbnail";
        QString description = "description";
        QString productRepositoryName = "productRepositoryName";
        QString productRepositoryThumbnail = "productRepositoryThumbnail";
        QString images = "images";
        QString imageContainer = "imageContainer";
        QString categories = "categories";
        QString ALTCategories = "ALTCategories";
        QString siUnit = "siUnit";
        QString ALTSiUnit = "ALTSiUnit";
        QString bakedInside = "bakedInside";
        QString ALTBakedInside = "ALTBakedInside";
        QString spareParts = "spareParts";
        QString ALTSpareParts = "ALTSpareParts";
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
    QList<ShopProduct *> parseJSONArray(QJsonArray o) throw();
    ShopProduct *parseJSONObject(QJsonObject o) throw();
    QList<ShopProduct *> parseArrayString(QString o) throw();
    ShopProduct *parseObjectString(QString o) throw();
    bool equal(ShopProduct *o);

public:
    const QString &id() const;
    void setId(const QString &newId);
    const QString &getUrl() const;
    void setUrl(const QString &newUrl);
    Location *getLocation() const;
    void setLocation(Location *newLocation);
    const QString &getRepoProduct() const;
    void setRepoProduct(const QString &newRepoProduct);
    Currency *getBaseCurrency() const;
    void setBaseCurrency(Currency *newBaseCurrency);
    const QString &getShop() const;
    void setShop(const QString &newShop);
    const QString &getShopName() const;
    void setShopName(const QString &newShopName);
    bool getIsFreeze() const;
    void setIsFreeze(bool newIsFreeze);
    bool getIsShopAlive() const;
    void setIsShopAlive(bool newIsShopAlive);
    const QString &getTier() const;
    void setTier(const QString &newTier);
    long getLikes() const;
    void setLikes(long newLikes);
    long getTotalView() const;
    void setTotalView(long newTotalView);
    const QString &getAka() const;
    void setAka(const QString &newAka);
    double getPrice() const;
    void setPrice(double newPrice);
    double getQuantity() const;
    void setQuantity(double newQuantity);
    const QString &getSecret() const;
    void setSecret(const QString &newSecret);
    const QString &getOffer() const;
    void setOffer(const QString &newOffer);
    const QString &getCondition() const;
    void setCondition(const QString &newCondition);
    bool getIsPrivate() const;
    void setIsPrivate(bool newIsPrivate);
    bool getIsShowcased() const;
    void setIsShowcased(bool newIsShowcased);
    QList<Tag> *getTags() const;
    void setTags(QList<Tag> *newTags);
    const QString &getName() const;
    void setName(const QString &newName);
    long getSnapshot() const;
    void setSnapshot(long newSnapshot);
    const QString &getPostFixChar() const;
    void setPostFixChar(const QString &newPostFixChar);
    const QString &getMilestone() const;
    void setMilestone(const QString &newMilestone);
    const QString &getThumbnail() const;
    void setThumbnail(const QString &newThumbnail);
    const QString &getDescription() const;
    void setDescription(const QString &newDescription);
    const QString &getProductRepositoryName() const;
    void setProductRepositoryName(const QString &newProductRepositoryName);
    const QString &getProductRepositoryThumbnail() const;
    void setProductRepositoryThumbnail(const QString &newProductRepositoryThumbnail);
    QList<QString> *getImages() const;
    void setImages(QList<QString> *newImages);
    const QString &getImageContainer() const;
    void setImageContainer(const QString &newImageContainer);
    QList<Category> *getCategories() const;
    void setCategories(QList<Category> *newCategories);
    QList<QString> *getALTCategories() const;
    void setALTCategories(QList<QString> *newALTCategories);
    SiUnit *getSiUnit() const;
    void setSiUnit(SiUnit *newSiUnit);
    const QString &getALTSiUnit() const;
    void setALTSiUnit(const QString &newALTSiUnit);
    QList<RepoProduct> *getBakedInside() const;
    void setBakedInside(QList<RepoProduct> *newBakedInside);
    QList<QString> *getALTBakedInside() const;
    void setALTBakedInside(QList<QString> *newALTBakedInside);
    QList<RepoProduct> *getSpareParts() const;
    void setSpareParts(QList<RepoProduct> *newSpareParts);
    QList<QString> *getALTSpareParts() const;
    void setALTSpareParts(QList<QString> *newALTSpareParts);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);

public:
    bool isShopExpired();
    bool isShopNotExpired();
    // ShopExpireDetails getShopValidityDetails();

};

#endif // SHOPPRODUCT_H
