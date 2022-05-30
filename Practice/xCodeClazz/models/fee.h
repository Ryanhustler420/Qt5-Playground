#ifndef FEE_H
#define FEE_H

#include "models/god/modelconventions.h"

class Fee : public ModelConventions<Fee>
{
    Q_OBJECT
public:
    explicit Fee(QObject *parent = nullptr);
    Fee(double amount, const QString &per);

private:
    double amount;
    QString per;

private:
    typedef struct FIELDS {
        QString amount = "amount";
        QString per = "per";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Fee*> parseJSONArray(QJsonArray o);
    QVariantList parseJSONArrayToVariantList(QJsonArray o);
    Fee *parseJSONObject(QJsonObject o);
    QVariant parseJSONObjectToVariant(QJsonObject o);
    bool equal(Fee *o);
    void copy(Fee *o);
    QJsonObject getAsJson() const;
    QJsonArray getAsJsonArray(QList<Fee> *t) const;

public:
    double getAmount() const;
    void setAmount(double newAmount);
    const QString &getPer() const;
    void setPer(const QString &newPer);

};

#endif // FEE_H
