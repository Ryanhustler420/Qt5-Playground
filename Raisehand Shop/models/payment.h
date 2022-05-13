#ifndef PAYMENT_H
#define PAYMENT_H

#include "models/god/modelconventions.h"

class Payment : public ModelConventions<Payment>
{
    Q_OBJECT
public:
    explicit Payment(QObject *parent = nullptr);
    Payment(const QString &id, int amount, const QString &symbol, const QString &currencyCode, const QString &userId, const QString &transactionId, const QString &planName, const QString &appName, const QString &createdAt, const QString &updatedAt);

private:
    QString _id;
    int amount;
    QString symbol;
    QString currencyCode;
    QString userId;
    QString transactionId;
    QString planName;
    QString appName;
    QString createdAt;
    QString updatedAt;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString amount = "amount";
        QString symbol = "symbol";
        QString currencyCode = "currencyCode";
        QString userId = "userId";
        QString transactionId = "transactionId";
        QString planName = "planName";
        QString appName = "appName";
        QString createdAt = "createdAt";
        QString updatedAt = "updatedAt";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Payment *> parseJSONArray(QJsonArray o) throw();
    Payment *parseJSONObject(QJsonObject o) throw();
    QList<Payment *> parseArrayString(QString o) throw();
    Payment *parseObjectString(QString o) throw();
    bool equal(Payment *o);

public:
    const QString &id() const;
    void setId(const QString &newId);
    int getAmount() const;
    void setAmount(int newAmount);
    const QString &getSymbol() const;
    void setSymbol(const QString &newSymbol);
    const QString &getCurrencyCode() const;
    void setCurrencyCode(const QString &newCurrencyCode);
    const QString &getUserId() const;
    void setUserId(const QString &newUserId);
    const QString &getTransactionId() const;
    void setTransactionId(const QString &newTransactionId);
    const QString &getPlanName() const;
    void setPlanName(const QString &newPlanName);
    const QString &getAppName() const;
    void setAppName(const QString &newAppName);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);
};

#endif // PAYMENT_H
