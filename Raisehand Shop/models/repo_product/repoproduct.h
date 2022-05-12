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
    User ALTUser;
    QString productRepository; // has two form
    ProductRepository* ALTProductRepository;
    SiUnit recommendedSIUnit;
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
};

#endif // REPOPRODUCT_H
