#include "models/payment.h"

Payment::Payment(const QString &id, int amount, const QString &symbol, const QString &currencyCode, const QString &userId, const QString &transactionId, const QString &planName, const QString &appName, const QString &createdAt, const QString &updatedAt)
{
    this->_id = id;
    this->amount = amount;
    this->symbol = symbol;
    this->currencyCode = currencyCode;
    this->userId = userId;
    this->transactionId = transactionId;
    this->planName = (planName);
    this->appName = (appName);
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    this->className = "Payment";
    this->fields = new _fields();
}

QList<QString> Payment::getAllFields()
{

}

QString Payment::getPackageName()
{
    return this->className;
}

QList<Payment *> Payment::parseJSONArray(QJsonArray o) throw()
{

}

Payment *Payment::parseJSONObject(QJsonObject o) throw()
{

}

QList<Payment *> Payment::parseArrayString(QString o) throw()
{

}

Payment *Payment::parseObjectString(QString o) throw()
{

}

bool Payment::equal(Payment *o)
{
    return o == this;
}

const QString &Payment::getUpdatedAt() const
{
    return updatedAt;
}

void Payment::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

const QString &Payment::getCreatedAt() const
{
    return createdAt;
}

void Payment::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

const QString &Payment::getAppName() const
{
    return appName;
}

void Payment::setAppName(const QString &newAppName)
{
    appName = newAppName;
}

const QString &Payment::getPlanName() const
{
    return planName;
}

void Payment::setPlanName(const QString &newPlanName)
{
    planName = newPlanName;
}

const QString &Payment::getTransactionId() const
{
    return transactionId;
}

void Payment::setTransactionId(const QString &newTransactionId)
{
    transactionId = newTransactionId;
}

const QString &Payment::getUserId() const
{
    return userId;
}

void Payment::setUserId(const QString &newUserId)
{
    userId = newUserId;
}

const QString &Payment::getCurrencyCode() const
{
    return currencyCode;
}

void Payment::setCurrencyCode(const QString &newCurrencyCode)
{
    currencyCode = newCurrencyCode;
}

const QString &Payment::getSymbol() const
{
    return symbol;
}

void Payment::setSymbol(const QString &newSymbol)
{
    symbol = newSymbol;
}

int Payment::getAmount() const
{
    return amount;
}

void Payment::setAmount(int newAmount)
{
    amount = newAmount;
}

const QString &Payment::id() const
{
    return _id;
}

void Payment::setId(const QString &newId)
{
    _id = newId;
}
