#ifndef SIGNEDBYDEVICE_H
#define SIGNEDBYDEVICE_H

#include "models/god/modelconventions.h"

class SignedByDevice : public ModelConventions<SignedByDevice>
{
    Q_OBJECT
public:
    explicit SignedByDevice(QObject *parent = nullptr);
    SignedByDevice(const QString &id, const QString &appName, const QString &loggedOutAt, const QString &deviceUUID, const QString &deviceName, bool loggedIn);

private:
    QString _id;
    QString appName;
    QString loggedOutAt;
    QString deviceUUID;
    QString deviceName;
    bool loggedIn;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString appName = "appName";
        QString loggedOutAt = "loggedOutAt";
        QString deviceUUID = "deviceUUID";
        QString deviceName = "deviceName";
        QString loggedIn = "loggedIn";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<SignedByDevice *> parseJSONArray(QJsonArray o) throw();
    SignedByDevice *parseJSONObject(QJsonObject o) throw();
    QList<SignedByDevice *> parseArrayString(QString o) throw();
    SignedByDevice *parseObjectString(QString o) throw();
    bool equal(SignedByDevice *o);

    const QString &id() const;
    void setId(const QString &newId);
    const QString &getAppName() const;
    void setAppName(const QString &newAppName);
    const QString &getLoggedOutAt() const;
    void setLoggedOutAt(const QString &newLoggedOutAt);
    const QString &getDeviceUUID() const;
    void setDeviceUUID(const QString &newDeviceUUID);
    const QString &getDeviceName() const;
    void setDeviceName(const QString &newDeviceName);
    bool getLoggedIn() const;
    void setLoggedIn(bool newLoggedIn);
};

#endif // SIGNEDBYDEVICE_H
