#ifndef XCODECLAZZDB_H
#define XCODECLAZZDB_H

#include "singleton/singleton_obj.h"
#include "utility/jsonhelper.h"
#include "utility/xdb.h"

class XCodeClazzDB : public OSingleton<XCodeClazzDB>
{
    Q_OBJECT
public:
    explicit XCodeClazzDB(QObject *parent = nullptr);

    bool saveLoginDetails(const QString &username, const QString &password);
    bool isPasswordMatched(const QString &username, const QString &password);
    QString getPassword(const QString &username);

    bool saveCallbackRequests(const QJsonArray &o);
    QJsonArray getCallbackRequests();

    // remove this document from that filed
    // saerch this document from that file

    // saveCallbackRequests(QVariantList list); // convert that into json first and then save into file
    // saveCallbackRequest(QVariant o);

    // QVariant getCallbackRequest()
    // QVariantList getCallbackRequests()
    // QVariant getCallbackRequestById(QString id)

    // bool deleteAllCallbackRequests()
    // bool deleteCallbackRequest(QVariant o)
    // bool containCallbackRequest(QVariant o)

    // courses
    // students

    // JSON Helper
    // QJsonObject findKey(JsonObject, key)
    // QJsonObject findKey(JsonArray, key)
    // QJsonObject index(JsonArray, index)
    // void deleteJsonObjectAt(JsonArray, index)

signals:

private:
    xDB *x;

    // files
    QString const app_name = "xcodeclazz";
    QString const login_json = app_name + "_" + "login.json";
    QString const callback_requests = app_name + "_" + "callback_requests.json";

};

#endif // XCODECLAZZDB_H
