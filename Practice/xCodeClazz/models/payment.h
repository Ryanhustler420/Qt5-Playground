#ifndef PAYMENT_H
#define PAYMENT_H

#include "models/god/modelconventions.h"

class Payment : public ModelConventions<Payment>
{
    Q_OBJECT
public:
    explicit Payment(QObject *parent = nullptr);
    Payment(const QString &title, const QString &date);

private:
    QString title;
    QString date;

private:
    typedef struct FIELDS {
        QString title = "title";
        QString date = "date";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Payment*> parseJSONArray(QJsonArray o);
    QVariantList parseJSONArrayToVariantList(QJsonArray o);
    Payment *parseJSONObject(QJsonObject o);
    QVariant parseJSONObjectToVariant(QJsonObject o);
    bool equal(Payment *o);
    void copy(Payment *o);
    QJsonObject getAsJson() const;
    QJsonArray getAsJsonArray(QList<Payment> *t) const;

public:
    const QString &getTitle() const;
    void setTitle(const QString &newTitle);
    const QString &getDate() const;
    void setDate(const QString &newDate);

};

#endif // PAYMENT_H
