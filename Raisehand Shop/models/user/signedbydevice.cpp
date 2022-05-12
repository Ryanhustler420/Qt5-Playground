#include "models/user/signedbydevice.h"

SignedByDevice::SignedByDevice(const QString &id, const QString &appName, const QString &loggedOutAt, const QString &deviceUUID, const QString &deviceName, bool loggedIn)
{
    this->_id = id;
    this->appName = appName;
    this->loggedOutAt = loggedOutAt;
    this->deviceUUID = deviceUUID;
    this->deviceName = deviceName;
    this->loggedIn = loggedIn;

    this->className = "SignedByDevice";
    this->fields = new _fields();
}

bool SignedByDevice::getLoggedIn() const
{
    return loggedIn;
}

void SignedByDevice::setLoggedIn(bool newLoggedIn)
{
    loggedIn = newLoggedIn;
}

const QString &SignedByDevice::getDeviceName() const
{
    return deviceName;
}

void SignedByDevice::setDeviceName(const QString &newDeviceName)
{
    deviceName = newDeviceName;
}

const QString &SignedByDevice::getDeviceUUID() const
{
    return deviceUUID;
}

void SignedByDevice::setDeviceUUID(const QString &newDeviceUUID)
{
    deviceUUID = newDeviceUUID;
}

const QString &SignedByDevice::getLoggedOutAt() const
{
    return loggedOutAt;
}

void SignedByDevice::setLoggedOutAt(const QString &newLoggedOutAt)
{
    loggedOutAt = newLoggedOutAt;
}

const QString &SignedByDevice::getAppName() const
{
    return appName;
}

void SignedByDevice::setAppName(const QString &newAppName)
{
    appName = newAppName;
}

const QString &SignedByDevice::id() const
{
    return _id;
}

void SignedByDevice::setId(const QString &newId)
{
    _id = newId;
}

QList<QString> SignedByDevice::getAllFields()
{

}

QString SignedByDevice::getPackageName()
{
    return this->className;
}

QList<SignedByDevice *> SignedByDevice::parseJSONArray(QJsonArray o) throw()
{

}

SignedByDevice *SignedByDevice::parseJSONObject(QJsonObject o) throw()
{

}

QList<SignedByDevice *> SignedByDevice::parseArrayString(QString o) throw()
{

}

SignedByDevice *SignedByDevice::parseObjectString(QString o) throw()
{

}

bool SignedByDevice::equal(SignedByDevice *o)
{
    return o == this;
}
