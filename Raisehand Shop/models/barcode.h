#ifndef BARCODE_H
#define BARCODE_H

#include "models/god/modelconventions.h"

class Barcode : public ModelConventions<Barcode>
{
    Q_OBJECT
public:
    explicit Barcode(QObject *parent = nullptr);
    Barcode(const QString &id, long barcode, bool isVerified, const QString &repoProduct, const QString &createdAt, const QString &updatedAt);

private:
    QString _id;
    long barcode;
    bool isVerified;
    QString repoProduct;
    QString createdAt;
    QString updatedAt;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString barcode = "barcode";
        QString isVerified = "isVerified";
        QString repoProduct = "repoProduct";
        QString createdAt = "createdAt";
        QString updatedAt = "updatedAt";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Barcode *> parseJSONArray(QJsonArray o) throw();
    Barcode *parseJSONObject(QJsonObject o) throw();
    QList<Barcode *> parseArrayString(QString o) throw();
    Barcode *parseObjectString(QString o) throw();
    bool equal(Barcode *o);

public:
    const QString &id() const;
    void setId(const QString &newId);
    bool getIsVerified() const;
    void setIsVerified(bool newIsVerified);
    const QString &getRepoProduct() const;
    void setRepoProduct(const QString &newRepoProduct);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);
    void setBarcode(long newBarcode);
    const long &getBarcode() const;
};

#endif // BARCODE_H
