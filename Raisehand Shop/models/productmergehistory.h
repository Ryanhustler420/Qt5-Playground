#ifndef PRODUCTMERGEHISTORY_H
#define PRODUCTMERGEHISTORY_H

#include "models/god/modelconventions.h"

class ProductMergeHistory : public ModelConventions<ProductMergeHistory>
{
    Q_OBJECT
public:
    explicit ProductMergeHistory(QObject *parent = nullptr);
    ProductMergeHistory(const QString &lastMergeRequestedTimeStamp, QList<int> *requestSnapshots, long timesSendTillDate, const QString &id);

private:
    QString _lastMergeRequestedTimeStamp;
    QList<int>* requestSnapshots;
    long timesSendTillDate;
    QString _id;

private:
    typedef struct FIELDS {
        QString _lastMergeRequestedTimeStamp = "_lastMergeRequestedTimeStamp";
        QString requestSnapshots = "requestSnapshots";
        QString timesSendTillDate = "timesSendTillDate";
        QString _id = "_id";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<ProductMergeHistory *> parseJSONArray(QJsonArray o) throw();
    ProductMergeHistory *parseJSONObject(QJsonObject o) throw();
    QList<ProductMergeHistory *> parseArrayString(QString o) throw();
    ProductMergeHistory *parseObjectString(QString o) throw();
    bool equal(ProductMergeHistory *o);

public:
    const QString &lastMergeRequestedTimeStamp() const;
    void setLastMergeRequestedTimeStamp(const QString &newLastMergeRequestedTimeStamp);
    QList<int> *getRequestSnapshots() const;
    void setRequestSnapshots(QList<int> *newRequestSnapshots);
    long getTimesSendTillDate() const;
    void setTimesSendTillDate(long newTimesSendTillDate);
    const QString &id() const;
    void setId(const QString &newId);
};

#endif // PRODUCTMERGEHISTORY_H
