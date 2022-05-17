#ifndef COUNTER_H
#define COUNTER_H

#include "models/god/modelconventions.h"

class Counter : public ModelConventions<Counter>
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = nullptr);
    Counter(int v, long count, const QString &id, const QString &name, const QString &countryName, const QString &language, const QString &countryISOCode, const QString &currencyCode, const QString &createdAt, const QString &updatedAt);

private:
    int __v;
    long count;
    QString _id;
    QString name;
    QString countryName;
    QString language;
    QString countryISOCode;
    QString currencyCode;
    QString createdAt;
    QString updatedAt;

private:
    typedef struct FIELDS {
        QString __v = "__v";
        QString count = "count";
        QString _id = "_id";
        QString name = "name";
        QString countryName = "countryName";
        QString language = "language";
        QString countryISOCode = "countryISOCode";
        QString currencyCode = "currencyCode";
        QString createdAt = "createdAt";
        QString updatedAt = "updatedAt";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Counter *> parseJSONArray(QJsonArray o) throw();
    Counter *parseJSONObject(QJsonObject o) throw();
    QList<Counter *> parseArrayString(QString o) throw();
    Counter *parseObjectString(QString o) throw();
    bool equal(Counter *o);

public:
    int v() const;
    void setV(int newV);
    long getCount() const;
    void setCount(long newCount);
    const QString &id() const;
    void setId(const QString &newId);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getCountryName() const;
    void setCountryName(const QString &newCountryName);
    const QString &getLanguage() const;
    void setLanguage(const QString &newLanguage);
    const QString &getCountryISOCode() const;
    void setCountryISOCode(const QString &newCountryISOCode);
    const QString &getCurrencyCode() const;
    void setCurrencyCode(const QString &newCurrencyCode);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);

public:
    static QList<Counter> getAllCountersOfCountry(QList<Counter> *counters, QString countryName);
    QString getPolishedCounterName();

};

#endif // COUNTER_H
