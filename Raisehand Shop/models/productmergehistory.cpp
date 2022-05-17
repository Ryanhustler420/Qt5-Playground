#include "models/productmergehistory.h"

ProductMergeHistory::ProductMergeHistory(const QString &lastMergeRequestedTimeStamp, QList<int> *requestSnapshots, long timesSendTillDate, const QString &id)
{
    this->_lastMergeRequestedTimeStamp = lastMergeRequestedTimeStamp;
    this->requestSnapshots = requestSnapshots;
    this->timesSendTillDate = timesSendTillDate;
    this->_id = id;

    this->className = "ProductMergeHistory";
    this->fields = new _fields();
}

QList<int> *ProductMergeHistory::getRequestSnapshots() const
{
    return requestSnapshots != nullptr ? requestSnapshots : new QList<int>();
}

void ProductMergeHistory::setRequestSnapshots(QList<int> *newRequestSnapshots)
{
    requestSnapshots = newRequestSnapshots;
}

long ProductMergeHistory::getTimesSendTillDate() const
{
    return timesSendTillDate;
}

void ProductMergeHistory::setTimesSendTillDate(long newTimesSendTillDate)
{
    timesSendTillDate = newTimesSendTillDate;
}

const QString &ProductMergeHistory::id() const
{
    return _id;
}

void ProductMergeHistory::setId(const QString &newId)
{
    _id = newId;
}

QList<QString> ProductMergeHistory::getAllFields()
{

}

QString ProductMergeHistory::getPackageName()
{
    return this->className;
}

QList<ProductMergeHistory *> ProductMergeHistory::parseJSONArray(QJsonArray o) throw()
{

}

ProductMergeHistory *ProductMergeHistory::parseJSONObject(QJsonObject o) throw()
{

}

QList<ProductMergeHistory *> ProductMergeHistory::parseArrayString(QString o) throw()
{

}

ProductMergeHistory *ProductMergeHistory::parseObjectString(QString o) throw()
{

}

bool ProductMergeHistory::equal(ProductMergeHistory *o)
{
    return o == this;
}

const QString &ProductMergeHistory::lastMergeRequestedTimeStamp() const
{
    return _lastMergeRequestedTimeStamp;
}

void ProductMergeHistory::setLastMergeRequestedTimeStamp(const QString &newLastMergeRequestedTimeStamp)
{
    _lastMergeRequestedTimeStamp = newLastMergeRequestedTimeStamp;
}
