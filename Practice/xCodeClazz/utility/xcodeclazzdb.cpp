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
    QJsonArray old = getCallbackRequests();
    old.push_back(o);

    QJsonDocument jsonDoc;
    jsonDoc.setArray(old);

    return x->save(jsonDoc, callback_requests);
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

QJsonObject XCodeClazzDB::getCallbackRequest(const QString &requestCallbackId)
{

}

QJsonArray XCodeClazzDB::getCallbackRequests()
{
    return x->get(callback_requests).array();
}

bool XCodeClazzDB::student_file()
{
    return x->present(students);
}

bool XCodeClazzDB::saveStudent(const QJsonObject &o)
{
    QJsonArray old = getStudents();
    old.push_back(o);

    QJsonDocument jsonDoc;
    jsonDoc.setArray(old);

    return x->save(jsonDoc, students);
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
    QJsonArray s = getStudents();
    QJsonArray l;
    for (int var = 0; var < s.size(); ++var) {
        QJsonObject v = s.at(var).toObject();
        if(!v.value("_id").toString().contains(studentId)) l.push_back(v);
    }
    return saveStudents(l);
}

bool XCodeClazzDB::deleteStudents()
{
    QJsonArray l;
    return saveStudents(l);
}

bool XCodeClazzDB::course_file()
{
    return x->present(courses);
}

bool XCodeClazzDB::saveCourse(const QJsonObject &o)
{
    QJsonArray old = getCourses();
    old.push_back(o);

    QJsonDocument jsonDoc;
    jsonDoc.setArray(old);

    return x->save(jsonDoc, courses);
}

bool XCodeClazzDB::saveCourses(const QJsonArray &o)
{
    QJsonDocument doc;
    doc.setArray(o);
    return x->save(doc, courses);
}

QJsonArray XCodeClazzDB::getCourses()
{
    return x->get(courses).array();
}

QJsonObject XCodeClazzDB::getCourse(const QString &courseId)
{

}

bool XCodeClazzDB::updateCourse(const QJsonObject &o)
{
    QJsonArray s = getCourses();
    QJsonArray l;
    for (int var = 0; var < s.size(); ++var) {
        QJsonObject v = s.at(var).toObject();
        if(v.value("_id").toString().contains(o.value("_id").toString())) {
            l.push_back(o);
        } else {
            l.push_back(v);
        }
    }
    return saveCourses(l);
}

bool XCodeClazzDB::deleteCourse(const QString &courseId)
{
    QJsonArray s = getCourses();
    QJsonArray l;
    for (int var = 0; var < s.size(); ++var) {
        QJsonObject v = s.at(var).toObject();
        if(!v.value("_id").toString().contains(courseId)) l.push_back(v);
    }
    return saveCourses(l);
}

bool XCodeClazzDB::deleteCourses()
{
    QJsonArray l;
    return saveCourses(l);
}
