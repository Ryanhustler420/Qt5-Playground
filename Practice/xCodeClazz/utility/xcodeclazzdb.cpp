#include "utility/xcodeclazzdb.h"

XCodeClazzDB::XCodeClazzDB(QObject *parent) : OSingleton<XCodeClazzDB>()
{
    Q_UNUSED(parent);
    x = new xDB("C:/Users/Raisehand/Desktop");
}

bool XCodeClazzDB::saveLoginDetails(const QString &username, const QString &password)
{
    // create main object for whole json data
    QJsonObject mainObject;

    // insert single datas first
    mainObject.insert("username", username);
    mainObject.insert("password", password);

    // lastly we created a JSON document and set mainObject as object of document
    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    return x->save(jsonDoc, login_json);
}

bool XCodeClazzDB::isPasswordMatched(const QString &username, const QString &password)
{

}

QString XCodeClazzDB::getPassword(const QString &username)
{

}

bool XCodeClazzDB::saveCallbackRequests(const QJsonArray &o)
{
    QJsonDocument doc;
    doc.setArray(o);
    x->save(doc, callback_requests);
}

QJsonArray XCodeClazzDB::getCallbackRequests()
{
    return x->get(callback_requests).array();
}
