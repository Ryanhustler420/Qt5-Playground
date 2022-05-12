#include "models/user/token.h"

Token::Token(const QString &appName, const QString &deviceUUID, const QString &token)
{
    this->appName = appName;
    this->deviceUUID = deviceUUID;
    this->token = token;

    this->className = "Token";
    this->fields = new _fields();
}

void Token::setToken(const QString &newToken)
{
    token = newToken;
}

const QString &Token::getToken() const
{
    return token;
}

const QString &Token::getDeviceUUID() const
{
    return deviceUUID;
}

void Token::setDeviceUUID(const QString &newDeviceUUID)
{
    deviceUUID = newDeviceUUID;
}

const QString &Token::getAppName() const
{
    return appName;
}

void Token::setAppName(const QString &newAppName)
{
    appName = newAppName;
}

QList<QString> Token::getAllFields()
{

}

QString Token::getPackageName()
{
    return this->className;
}

QList<Token *> Token::parseJSONArray(QJsonArray o) throw()
{

}

Token *Token::parseJSONObject(QJsonObject o) throw()
{

}

QList<Token *> Token::parseArrayString(QString o) throw()
{

}

Token *Token::parseObjectString(QString o) throw()
{

}

bool Token::equal(Token *o)
{
    return o == this;
}
