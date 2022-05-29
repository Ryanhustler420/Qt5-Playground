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

    _fields *field;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Fee *> parseJSONArray(QJsonArray o) throw(ExceptionThrow);
    QVariantList parseJSONArrayToVariantList(QJsonArray o) throw(ExceptionThrow);
    Fee *parseJSONObject(QJsonObject o) throw(ExceptionThrow);
    QVariant parseJSONObjectToVariant(QJsonObject o);
    bool equal(Fee *o);
    void copy(Fee *o);

public:
    double getAmount() const;
    void setAmount(double newAmount);
    const QString &getPer() const;
    void setPer(const QString &newPer);

};

#endif // FEE_H
