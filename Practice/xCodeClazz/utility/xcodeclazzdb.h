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

    bool login_file();
    bool saveLoginDetails(const QString &username, const QString &password);
    bool isPasswordMatched(const QString &username, const QString &password);
    QString getPassword(const QString &username);

    bool callbackRequest_file();
    bool saveCallbackRequest(const QJsonObject &o);
    bool saveCallbackRequests(const QJsonArray &o);
    QJsonArray getCallbackRequests();
    QJsonObject getCallbackRequest(const QString &requestCallbackId);

    bool deleteCallbackRequest(const QString &requestCallbackId);
    bool deleteCallbackRequests();

    bool student_file();
    bool saveStudent(const QJsonObject &o);
    bool saveStudents(const QJsonArray &o);
    QJsonArray getStudents();
    QJsonObject getStudent(const QString &studentId);

    bool deleteStudent(const QString &studentId);
    bool deleteStudents();

    // courses

signals:

private:
    xDB *x;

    // files
    QString const app_name = "xcodeclazz";
    QString const login_json = app_name + "_" + "login.json";
    QString const students = app_name + "_" + "students.json";
    QString const callback_requests = app_name + "_" + "callback_requests.json";

};

#endif // XCODECLAZZDB_H
