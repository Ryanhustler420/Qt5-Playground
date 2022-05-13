#ifndef SECRETKEY_H
#define SECRETKEY_H

#include "models/god/modelconventions.h"

class SecretKey : public ModelConventions<SecretKey>
{
    Q_OBJECT
public:
    explicit SecretKey(QObject *parent = nullptr);
    SecretKey(const QString &key, const QString &value);

private:
    QString key;
    QString value;

private:
    typedef struct FIELDS {
        QString key = "key";
        QString value = "value";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<SecretKey *> parseJSONArray(QJsonArray o) throw();
    SecretKey *parseJSONObject(QJsonObject o) throw();
    QList<SecretKey *> parseArrayString(QString o) throw();
    SecretKey *parseObjectString(QString o) throw();
    bool equal(SecretKey *o);

};

#endif // SECRETKEY_H
