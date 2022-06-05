#ifndef APIS_H
#define APIS_H

#include "networking/network.h"
#include "networking/routes.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class Apis : public Network
{
public:
    explicit Apis(CommonSuperClass *parent = nullptr);

public:
    void postInit(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void getStudentsStatus(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void getCoursesStatus(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void getRequestCallbacksStatus(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void getStudents(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void getStudent(const QString &studentId, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void createStudent(const QString &name, const QString &imageUrl, const QString &school, const QString &imageContainer, int age, const QString &clazz, const QString &courseId, const QString &from, const QString &to, QList<QString> &weeks, const QString &phoneNumbers, const QString &amount, const QString &per, int batchNumber, const QString &email, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void deleteStudent(const QString &studentId, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void updateStudent(const QString &studentId, const QString &name, int age, const QString &email, const QString &clazz, const QString &courseId, const QString &school, const QString &phoneNumbers, const QString &amount, const QString &per, const QString &from, const QString &to, QList<QString> &weeks, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void getRequestCallbacks(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void getRequestCallback(const QString &requestCallbackId, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void callbackRequestCreate(const QString &courseId, const QString &name, const QString &phone, const QString &school, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void callbackRequestDelete(const QString &requestCallbackId, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void callbackRequestDeleteAll(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void getCourses(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void getCourse(const QString &courseId, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void createCourse(const QJsonObject &course, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void updateCourse(const QString &courseId, const QString &title, const QString &subtitle, const QString &duration, const QString &thumbnailUrl, QList<QString> &features, float price, bool hasActive, int spaceLeft, int spaceFull, const QString &starts, const QString &ends, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void deleteCourse(const QString &courseId, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);

    void exchangeGoogleOAuthCode(QString code, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void exchangeGoogleAccessTokenForUserInfo(QString tokenType, QString accessToken, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);

 public:
    typedef struct HEADER_KEYS {
        QString raisehand_access_platform_names_array = "raisehand_access_platform_names_array";
        QString raisehand_route_caller_appname = "raisehand_route_caller_appname";
        QString raisehand_server_version = "raisehand_server_version";
        QString raisehand_app_version = "raisehand_app_version";
        QString raisehand_auth_token = "raisehand_auth_token";

        QString application_json = "application/json";
        QString url_encoded = "application/x-www-form-urlencoded";
    } raw_headers;

    raw_headers *_raw_headers;

private:
    Routes *routes;

};

#endif // APIS_H
