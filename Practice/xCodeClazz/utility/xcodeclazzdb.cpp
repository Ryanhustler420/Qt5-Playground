#include "utility/xcodeclazzdb.h"

XCodeClazzDB::XCodeClazzDB(QObject *parent) : OSingleton<XCodeClazzDB>()
{
    Q_UNUSED(parent);
    x = new xDB("C:/Users/Raisehand/Desktop");
}

bool XCodeClazzDB::login_file()
{
    return x->present(login_json);
}

bool XCodeClazzDB::saveLoginDetails(const QJsonObject &o)
{
    QJsonDocument jsonDoc;
    jsonDoc.setObject(o);
    return x->save(jsonDoc, login_json);
}

QJsonObject XCodeClazzDB::getLoginDetails()
{
    return x->get(login_json).object();
}

bool XCodeClazzDB::deleteLoginDetails()
{
    QJsonDocument jsonDoc;
    return x->save(jsonDoc, login_json);
}

bool XCodeClazzDB::callbackRequest_file()
{
    return x->present(callback_requests);
}

bool XCodeClazzDB::saveCallbackRequest(const QJsonObject &o)
{

}

bool XCodeClazzDB::saveCallbackRequests(const QJsonArray &o)
{
    QJsonDocument doc;
    doc.setArray(o);
    x->save(doc, callback_requests);
}

bool XCodeClazzDB::deleteCallbackRequest(const QString &callbackRequestId)
{
    QJsonArray s = getCallbackRequests();
    QJsonArray l;
    for (int var = 0; var < s.size(); ++var) {
        QJsonObject v = s.at(var).toObject();
        if(!v.value("_id").toString().contains(callbackRequestId)) l.push_back(v);
    }
    return saveCallbackRequests(l);
}

bool XCodeClazzDB::deleteCallbackRequests()
{
    QJsonArray l;
    return saveCallbackRequests(l);
}

bool XCodeClazzDB::student_file()
{
    return x->present(students);
}

bool XCodeClazzDB::saveStudent(const QJsonObject &o)
{

}

bool XCodeClazzDB::saveStudents(const QJsonArray &o)
{
    QJsonDocument doc;
    doc.setArray(o);
    x->save(doc, students);
}

QJsonArray XCodeClazzDB::getStudents()
{
    return x->get(students).array();
}

QJsonObject XCodeClazzDB::getStudent(const QString &studentId)
{

}

bool XCodeClazzDB::deleteStudent(const QString &studentId)
{

}

bool XCodeClazzDB::deleteStudents()
{
    QJsonArray l;
    return saveStudents(l);
}

QJsonArray XCodeClazzDB::getCallbackRequests()
{
    return x->get(callback_requests).array();
}

QJsonObject XCodeClazzDB::getCallbackRequest(const QString &requestCallbackId)
{

}
