#ifndef TOKEN_H
#define TOKEN_H

#include "models/god/modelconventions.h"

class Token : public ModelConventions<Token>
{
    Q_OBJECT
public:
    explicit Token(QObject *parent = nullptr);
    Token(const QString &appName, const QString &deviceUUID, const QString &token);

private:
    QString appName;
    QString deviceUUID;
    QString token;

private:
    typedef struct FIELDS {
        QString appName = "appName";
        QString deviceUUID = "deviceUUID";
        QString token = "token";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Token *> parseJSONArray(QJsonArray o) throw();
    Token *parseJSONObject(QJsonObject o) throw();
    QList<Token *> parseArrayString(QString o) throw();
    Token *parseObjectString(QString o) throw();
    bool equal(Token *o);

    const QString &getAppName() const;
    void setAppName(const QString &newAppName);
    const QString &getDeviceUUID() const;
    void setDeviceUUID(const QString &newDeviceUUID);
    void setToken(const QString &newToken);
    const QString &getToken() const;
};

#endif // TOKEN_H
