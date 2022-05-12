#ifndef REPOPRODUCT_H
#define REPOPRODUCT_H

#include "models/product_repository/productrepository.h"
#include "models/god/modelconventions.h"
#include "qr_signature/jwtencoder.h"
#include "models/repo_product/tag.h"
#include "qr_signature/iocode.h"
#include "models/user/user.h"
#include "models/currency.h"
#include "models/category.h"
#include "models/siunit.h"

class RepoProduct :
        public ModelConventions<RepoProduct>,
        public JwtEncoder,
        public IOCode
{
    Q_OBJECT
public:
    explicit RepoProduct(QObject *parent = nullptr);
    RepoProduct(const QString &id, const QString &url, const QString &barcode, bool isBarcodeVerified, bool isSearchableStandalone, const QString &productName, Currency *currency, const QString &thumbnailUrl, const QString &description, const QString &postFixChar, const QString &productRepositoryName, const QString &productRepositoryThumbnail, QList<QString> *productImages, const QString &imageContainer, double productPrice, int timesModified, long totalView, long timesClone, long productSnapshot, long productRepositorySnapshot, const QString &productRepositoryType, bool isDiscounted, bool isProductRepositoryActive, bool isPrivate, bool isFreeze, bool hasSibling, bool hasEdited, QList<Tag> *tags, QList<Category> *categories, QList<QString> *ALTCategories, const QString &createdAt, const QString &updatedAt, const QString &user, User *ALTUser, const QString &productRepository, ProductRepository *ALTProductRepository, SiUnit *recommendedSIUnit, const QString &ALTRecommendedSIUnit, QList<RepoProduct> *bakedInside, QList<QString> *ALTBakedInside, QList<RepoProduct> *spareParts, QList<QString> *ALTSpareParts);

public:
    static int const CLASS_NUMBER = 4; // please never change this...

private:
    QString _id;
    QString url;
    QString barcode;
    bool isBarcodeVerified;
    bool isSearchableStandalone;
    QString productName;
    Currency* currency;
    QString thumbnailUrl;
    QString description;
    QString postFixChar;
    QString productRepositoryName;
    QString productRepositoryThumbnail;
    QList<QString>* productImages;
    QString imageContainer;
    double productPrice;
    int timesModified;
    long totalView;
    long timesClone;
    long productSnapshot;
    long productRepositorySnapshot;
    QString productRepositoryType;
    bool isDiscounted;
    bool isProductRepositoryActive;
    bool isPrivate;
    bool isFreeze;
    bool hasSibling;
    bool hasEdited;
    QList<Tag>* tags;
    QList<Category>* categories;
    QList<QString>* ALTCategories;
    QString createdAt;
    QString updatedAt;
    QString user; // has two form
    User* ALTUser;
    QString productRepository; // has two form
    ProductRepository* ALTProductRepository;
    SiUnit* recommendedSIUnit;
    QString ALTRecommendedSIUnit;
    QList<RepoProduct>* bakedInside;
    QList<QString>* ALTBakedInside;
    QList<RepoProduct>* spareParts;
    QList<QString>* ALTSpareParts;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString url = "url";

        QString barcode = "barcode";
        QString isBarcodeVerified = "isBarcodeVerified";
        QString isSearchableStandalone = "isSearchableStandalone";
        QString productName = "productName";
        QString currency = "currency";
        QString thumbnailUrl = "thumbnailUrl";
        QString description = "description";
        QString postFixChar = "postFixChar";
        QString productRepositoryName = "productRepositoryName";
        QString productRepositoryThumbnail = "productRepositoryThumbnail";
        QString productImages = "productImages";
        QString imageContainer = "imageContainer";
        QString productPrice = "productPrice";
        QString timesModified = "timesModified";
        QString totalView = "totalView";
        QString timesClone = "timesClone";
        QString productSnapshot = "productSnapshot";
        QString productRepositorySnapshot = "productRepositorySnapshot";
        QString productRepositoryType = "productRepositoryType";
        QString isDiscounted = "isDiscounted";
        QString isProductRepositoryActive = "isProductRepositoryActive";
        QString isPrivate = "isPrivate";
        QString isFreeze = "isFreeze";
        QString hasSibling = "hasSibling";
        QString hasEdited = "hasEdited";
        QString tags = "tags";
        QString categories = "categories";
        QString ALTCategories = "ALTCategories";
        QString createdAt = "createdAt";
        QString updatedAt = "updatedAt";
        QString user = "user";
        QString ALTUser = "ALTUser";
        QString productRepository = "productRepository";
        QString ALTProductRepository = "ALTProductRepository";
        QString recommendedSIUnit = "recommendedSIUnit";
        QString ALTRecommendedSIUnit = "ALTRecommendedSIUnit";
        QString bakedInside = "bakedInside";
        QString ALTBakedInside = "ALTBakedInside";
        QString spareParts = "spareParts";
        QString ALTSpareParts = "ALTSpareParts";
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
    QList<RepoProduct *> parseJSONArray(QJsonArray o) throw();
    RepoProduct *parseJSONObject(QJsonObject o) throw();
    QList<RepoProduct *> parseArrayString(QString o) throw();
    RepoProduct *parseObjectString(QString o) throw();
    bool equal(RepoProduct *o);

public:
    const QString &id() const;
    void setId(const QString &newId);
    const QString &getUrl() const;
    void setUrl(const QString &newUrl);
    const QString &getBarcode() const;
    void setBarcode(const QString &newBarcode);
    bool getIsBarcodeVerified() const;
    void setIsBarcodeVerified(bool newIsBarcodeVerified);
    bool getIsSearchableStandalone() const;
    void setIsSearchableStandalone(bool newIsSearchableStandalone);
    const QString &getProductName() const;
    void setProductName(const QString &newProductName);
    Currency *getCurrency() const;
    void setCurrency(Currency *newCurrency);
    const QString &getThumbnailUrl() const;
    void setThumbnailUrl(const QString &newThumbnailUrl);
    const QString &getDescription() const;
    void setDescription(const QString &newDescription);
    const QString &getPostFixChar() const;
    void setPostFixChar(const QString &newPostFixChar);
    const QString &getProductRepositoryName() const;
    void setProductRepositoryName(const QString &newProductRepositoryName);
    const QString &getProductRepositoryThumbnail() const;
    void setProductRepositoryThumbnail(const QString &newProductRepositoryThumbnail);
    QList<QString> *getProductImages() const;
    void setProductImages(QList<QString> *newProductImages);
    const QString &getImageContainer() const;
    void setImageContainer(const QString &newImageContainer);
    double getProductPrice() const;
    void setProductPrice(double newProductPrice);
    int getTimesModified() const;
    void setTimesModified(int newTimesModified);
    long getTotalView() const;
    void setTotalView(long newTotalView);
    long getTimesClone() const;
    void setTimesClone(long newTimesClone);
    long getProductSnapshot() const;
    void setProductSnapshot(long newProductSnapshot);
    long getProductRepositorySnapshot() const;
    void setProductRepositorySnapshot(long newProductRepositorySnapshot);
    const QString &getProductRepositoryType() const;
    void setProductRepositoryType(const QString &newProductRepositoryType);
    bool getIsDiscounted() const;
    void setIsDiscounted(bool newIsDiscounted);
    bool getIsProductRepositoryActive() const;
    void setIsProductRepositoryActive(bool newIsProductRepositoryActive);
    bool getIsPrivate() const;
    void setIsPrivate(bool newIsPrivate);
    bool getIsFreeze() const;
    void setIsFreeze(bool newIsFreeze);
    bool getHasSibling() const;
    void setHasSibling(bool newHasSibling);
    bool getHasEdited() const;
    void setHasEdited(bool newHasEdited);
    QList<Tag> *getTags() const;
    void setTags(QList<Tag> *newTags);
    QList<Category> *getCategories() const;
    void setCategories(QList<Category> *newCategories);
    QList<QString> *getALTCategories() const;
    void setALTCategories(QList<QString> *newALTCategories);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);
    const QString &getUser() const;
    void setUser(const QString &newUser);
    User *getALTUser() const;
    void setALTUser(User *newALTUser);
    QString getProductRepository() const;
    void setProductRepository(const QString &newProductRepository);
    ProductRepository *getALTProductRepository() const;
    void setALTProductRepository(ProductRepository *newALTProductRepository);
    SiUnit *getRecommendedSIUnit() const;
    void setRecommendedSIUnit(SiUnit *newRecommendedSIUnit);
    const QString &getALTRecommendedSIUnit() const;
    void setALTRecommendedSIUnit(const QString &newALTRecommendedSIUnit);
    QList<RepoProduct> *getBakedInside() const;
    void setBakedInside(QList<RepoProduct> *newBakedInside);
    QList<QString> *getALTBakedInside() const;
    void setALTBakedInside(QList<QString> *newALTBakedInside);
    QList<RepoProduct> *getSpareParts() const;
    void setSpareParts(QList<RepoProduct> *newSpareParts);
    QList<QString> *getALTSpareParts() const;
    void setALTSpareParts(QList<QString> *newALTSpareParts);

public:
    static QList<QString>* onlyIDS(QList<RepoProduct>* repoProducts);
    bool isCreator(const User* user) const;
    bool isRepoOwner(User* user) const;
    bool isParentMasterRepository();
    QString getFormattedTotalViews();
    QString getFormattedTimesClone();
    QString getCorrectThumbnailUrl(QString imageContainers);
    QString getCurrencyName();
    bool hasPostFix();
    QString getFormattedRepositorySnapshot();
    QString getProductProductionState();
    QString getFormattedProductSnapshot();
    bool isBackupStagedProduct();
    QString getFormattedPrice();
    QString getFormattedTotalViewsAndTotalClones();
    bool hasCategories();
    bool hasTags();

};

#endif // REPOPRODUCT_H
