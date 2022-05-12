#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H

#include "models/product_repository/contributor.h"
#include "models/god/modelconventions.h"
#include "qr_signature/jwtencoder.h"
#include "qr_signature/iocode.h"
#include "models/currency.h"
#include "models/category.h"

class ProductRepository :
        public ModelConventions<ProductRepository>,
        public JwtEncoder,
        public IOCode
{
    Q_OBJECT
public:
    explicit ProductRepository(QObject *parent = nullptr);
    ProductRepository(int v, const QString &id, const QString &productRepositoryName, long productRepositorySnapshot, const QString &productRepositoryOwnerName, const QString &productRepositoryType, bool canProductRepositoryExpire, const QString &productRepositoryThumbnail, const QString &imageContainer, const QString &productRepositoryOverview, const QString &productRepositoryTargetAudience, const QString &productRepositoryPasswordChangedAt, const QString &productRepositoryProfilePassword, bool isProductRepositoryOpen, long likes, long totalView, QList<Contributor>* repoProductContributors, Currency* baseCurrency, QList<Category>* categories, QList<QString>* ALTCategories, const QString &lastPaymentOn, int lastPaymentPlanValidForDays, int inventoryLength, bool isProductRepositoryAlive, const QString &productRepositoryCoverage, const QString &createdAt, const QString &updatedAt);

public:
    static int const CLASS_NUMBER = 3; // please never change this...

private:
    int __v;
    QString _id;
    QString productRepositoryName;
    long productRepositorySnapshot;
    QString productRepositoryOwnerName;
    QString productRepositoryType;
    bool canProductRepositoryExpire;

    QString productRepositoryThumbnail;
    QString imageContainer;
    QString productRepositoryOverview;
    QString productRepositoryTargetAudience;
    QString productRepositoryPasswordChangedAt;
    QString productRepositoryProfilePassword;
    bool isProductRepositoryOpen;

    long likes;
    long totalView;
    QList<Contributor>* repoProductContributors;
    Currency* baseCurrency;

    // might have two form, plan string i.e IDS or Object Schema Like
    QList<Category>* categories;
    QList<QString>* ALTCategories;

    QString lastPaymentOn;
    int lastPaymentPlanValidForDays;
    int inventoryLength;
    bool isProductRepositoryAlive;
    QString productRepositoryCoverage;
    QString createdAt;
    QString updatedAt;

private:
    typedef struct FIELDS {
        QString __v = "__v";
        QString _id = "_id";
        QString productRepositoryName = "productRepositoryName";
        QString productRepositorySnapshot = "productRepositorySnapshot";
        QString productRepositoryOwnerName = "productRepositoryOwnerName";
        QString productRepositoryType = "productRepositoryType";
        QString canProductRepositoryExpire = "canProductRepositoryExpire";
        QString productRepositoryThumbnail = "productRepositoryThumbnail";
        QString imageContainer = "imageContainer";
        QString productRepositoryOverview = "productRepositoryOverview";
        QString productRepositoryTargetAudience = "productRepositoryTargetAudience";
        QString productRepositoryPasswordChangedAt = "productRepositoryPasswordChangedAt";
        QString productRepositoryProfilePassword = "productRepositoryProfilePassword";
        QString isProductRepositoryOpen = "isProductRepositoryOpen";
        QString likes = "likes";
        QString timesSendTillDate = "timesSendTillDate";
        QString totalView = "totalView";
        QString repoProductContributors = "repoProductContributors";
        QString baseCurrency = "baseCurrency";
        QString categories = "categories";
        QString ALTCategories = "ALTCategories";
        QString lastPaymentOn = "lastPaymentOn";
        QString lastPaymentPlanValidForDays = "lastPaymentPlanValidForDays";
        QString inventoryLength = "inventoryLength";
        QString isProductRepositoryAlive = "isProductRepositoryAlive";
        QString productRepositoryCoverage = "productRepositoryCoverage";
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
    QList<ProductRepository *> parseJSONArray(QJsonArray o) throw();
    ProductRepository *parseJSONObject(QJsonObject o) throw();
    QList<ProductRepository *> parseArrayString(QString o) throw();
    ProductRepository *parseObjectString(QString o) throw();
    bool equal(ProductRepository *o);

    // bool isOwner(User user);
    QString getExpireMessage();
    bool hasLimitedSpace();
    QString getFormattedLikes();
    QString getSupportedCurrencyCode();
    QString getSupportedCurrencyName();
    bool isLocalRepository();
    bool isMasterRepository();
    bool isRepositoryExpired();
    bool isNationalRepository();
    QString getFormattedTotalViews();
    bool isRepositoryNotExpired();
    QString getTotalContributorCount();
    bool isInternationalRepository();
    // ProductRepositoryExpireDetails getRepoValidityDetails();
    // bool isNoRecentPasswordChanged(RepoAccessPasscode passcode);
    // bool verifyAccessPasscode(RepoAccessPasscode pc);
    // bool verifySnapshot(RepoAccessPasscode pc);
    QString getCorrectRepoLogo();
    QString getFormattedRepositorySnapshot();
    QString getFormattedCreatedAtDate();
    bool isNotOpen();
    QString getProductRepositoryCoverageWithCoverageKeyword();

    int v() const;
    void setV(int newV);
    const QString &id() const;
    void setId(const QString &newId);
    const QString &getProductRepositoryName() const;
    void setProductRepositoryName(const QString &newProductRepositoryName);
    long getProductRepositorySnapshot() const;
    void setProductRepositorySnapshot(long newProductRepositorySnapshot);
    const QString &getProductRepositoryOwnerName() const;
    void setProductRepositoryOwnerName(const QString &newProductRepositoryOwnerName);
    const QString &getProductRepositoryType() const;
    void setProductRepositoryType(const QString &newProductRepositoryType);
    bool getCanProductRepositoryExpire() const;
    void setCanProductRepositoryExpire(bool newCanProductRepositoryExpire);
    const QString &getProductRepositoryThumbnail() const;
    void setProductRepositoryThumbnail(const QString &newProductRepositoryThumbnail);
    const QString &getImageContainer() const;
    void setImageContainer(const QString &newImageContainer);
    const QString &getProductRepositoryOverview() const;
    void setProductRepositoryOverview(const QString &newProductRepositoryOverview);
    const QString &getProductRepositoryTargetAudience() const;
    void setProductRepositoryTargetAudience(const QString &newProductRepositoryTargetAudience);
    const QString &getProductRepositoryPasswordChangedAt() const;
    void setProductRepositoryPasswordChangedAt(const QString &newProductRepositoryPasswordChangedAt);
    const QString &getProductRepositoryProfilePassword() const;
    void setProductRepositoryProfilePassword(const QString &newProductRepositoryProfilePassword);
    bool getIsProductRepositoryOpen() const;
    void setIsProductRepositoryOpen(bool newIsProductRepositoryOpen);
    long getLikes() const;
    void setLikes(long newLikes);
    long getTotalView() const;
    void setTotalView(long newTotalView);
    QList<Contributor> *getRepoProductContributors() const;
    void setRepoProductContributors(QList<Contributor> *newRepoProductContributors);
    Currency *getBaseCurrency() const;
    void setBaseCurrency(Currency *newBaseCurrency);
    QList<Category> *getCategories() const;
    void setCategories(QList<Category> *newCategories);
    QList<QString> *getALTCategories() const;
    void setALTCategories(QList<QString> *newALTCategories);
    const QString &getLastPaymentOn() const;
    void setLastPaymentOn(const QString &newLastPaymentOn);
    int getLastPaymentPlanValidForDays() const;
    void setLastPaymentPlanValidForDays(int newLastPaymentPlanValidForDays);
    int getInventoryLength() const;
    void setInventoryLength(int newInventoryLength);
    bool getIsProductRepositoryAlive() const;
    void setIsProductRepositoryAlive(bool newIsProductRepositoryAlive);
    const QString &getProductRepositoryCoverage() const;
    void setProductRepositoryCoverage(const QString &newProductRepositoryCoverage);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);
};

#endif // PRODUCTREPOSITORY_H
