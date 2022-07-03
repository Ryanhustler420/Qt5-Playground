#include "apis.h"

Apis::Apis(CommonSuperClass *parent) : Network(parent)
{
    mNetReply = nullptr;
    routes = new Routes();
    mDataBuffer = new QByteArray();
    _raw_headers = new raw_headers();
    cookie_jar = new QNetworkCookieJar();
    mNetMan = new QNetworkAccessManager(parent);
}

void Apis::postInit(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QJsonObject mainObject;
    mainObject.insert("name", "Anjali Gupta");
    mainObject.insert("surname", "Gupta");
    mainObject.insert("age", 24);
    QJsonObject address;
    address.insert("city", "Istanbul");
    address.insert("country", "TURKEY");
    mainObject.insert("address", address);
    QJsonArray phones;
    phones.push_back("0555555555");
    phones.push_back("01111111111");
    mainObject.insert("phone", phones);
    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(routes->post_api__init__());
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->application_json);
    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::getStudentsStatus(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QNetworkRequest request(routes->get_api_xcodeclazz_status_students());
    QNetworkReply *mNetReply = mNetMan->get(request);

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::getCoursesStatus(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QNetworkRequest request(routes->get_api_xcodeclazz_status_courses());
    QNetworkReply *mNetReply = mNetMan->get(request);

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::getRequestCallbacksStatus(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QNetworkRequest request(routes->get_api_xcodeclazz_status_request_callbacks());
    QNetworkReply *mNetReply = mNetMan->get(request);

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::getStudents(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QNetworkRequest request(routes->get_api_xcodeclazz_students());
    QNetworkReply *mNetReply = mNetMan->get(request);

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::getStudent(const QString &studentId, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QJsonObject mainObject;
    mainObject.insert("studentId", studentId);
    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(routes->post_api_xcodeclazz_student());
    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::createStudent(const QString &name, const QString &imageUrl, const QString &school, const QString &imageContainer, int age, const QString &clazz, const QString &courseId, const QString &from, const QString &to, QList<QString> &weeks, const QString &phoneNumbers, const QString &amount, const QString &per, int batchNumber, const QString &email, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QJsonObject mainObject;
    mainObject.insert("name", name);
    mainObject.insert("imageUrl", imageUrl);
    mainObject.insert("school", school);

    mainObject.insert("imageContainer", imageContainer);
    mainObject.insert("age", age);
    mainObject.insert("clazz", clazz);
    mainObject.insert("courseId", courseId);

    QJsonObject timeSlot;
    timeSlot.insert("from", from);
    timeSlot.insert("to", to);

    QJsonArray _weeks;
    for (QString e: weeks) _weeks.push_back(e);
    timeSlot.insert("weeks", _weeks);

    mainObject.insert("timeSlot", timeSlot);

    mainObject.insert("phoneNumbers", phoneNumbers);

    QJsonObject fees;
    fees.insert("amount", amount);
    fees.insert("per", per);
    mainObject.insert("fees", fees);

    mainObject.insert("batchNumber", batchNumber);
    mainObject.insert("email", email);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(routes->post_api_xcodeclazz_student_create());
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->application_json);
    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::deleteStudent(const QString &studentId, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QJsonObject mainObject;
    mainObject.insert("studentId", studentId);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(routes->post_api_xcodeclazz_student_delete());
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->application_json);
    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::updateStudent(const QString &studentId, const QString &name, int age, const QString &email, const QString &clazz, const QString &courseId, const QString &school, const QString &phoneNumbers, const QString &amount, const QString &per, const QString &from, const QString &to, QList<QString> &weeks, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QJsonObject mainObject;
    mainObject.insert("studentId", studentId);
    mainObject.insert("name", name);
    mainObject.insert("school", school);

    mainObject.insert("age", age);
    mainObject.insert("clazz", clazz);
    mainObject.insert("courseId", courseId);

    QJsonObject timeSlot;
    timeSlot.insert("from", from);
    timeSlot.insert("to", to);

    QJsonArray _weeks;
    for (QString e: weeks) _weeks.push_back(e);
    timeSlot.insert("weeks", _weeks);

    mainObject.insert("timeSlot", timeSlot);

    mainObject.insert("phoneNumbers", phoneNumbers);

    QJsonObject fees;
    fees.insert("amount", amount);
    fees.insert("per", per);
    mainObject.insert("fees", fees);

    mainObject.insert("email", email);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(routes->post_api_xcodeclazz_student_update());
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->application_json);
    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::getRequestCallbacks(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QNetworkRequest request(routes->get_api_xcodeclazz_request_callbacks());
    QNetworkReply *mNetReply = mNetMan->get(request);

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::getRequestCallback(const QString &requestCallbackId, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QJsonObject mainObject;
    mainObject.insert("requestCallbackId", requestCallbackId);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(routes->post_api_xcodeclazz_request_callback());
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->application_json);
    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::callbackRequestCreate(const QString &courseId, const QString &name, const QString &phone, const QString &school, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QJsonObject mainObject;
    mainObject.insert("courseId", courseId);
    mainObject.insert("name", name);
    mainObject.insert("phone", phone);
    mainObject.insert("school", school);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(routes->post_api_xcodeclazz_request_callback_create());
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->application_json);
    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::callbackRequestDelete(const QString &requestCallbackId, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QJsonObject mainObject;
    mainObject.insert("requestCallbackId", requestCallbackId);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(routes->post_api_xcodeclazz_request_callback_delete());
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->application_json);
    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::callbackRequestDeleteAll(std::function<void (QByteArray)> response, std::function<void (QByteArray)> error)
{
    clearResponse();
    QJsonObject mainObject;

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(routes->post_api_xcodeclazz_request_callback_delete_all());
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->application_json);
    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::getCourses(std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QNetworkRequest request(routes->get_api_xcodeclazz_courses());
    QNetworkReply *mNetReply = mNetMan->get(request);

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::getCourse(const QString &courseId, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QJsonObject mainObject;
    mainObject.insert("courseId", courseId);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(routes->post_api_xcodeclazz_course());
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->application_json);
    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::createCourse(const QJsonObject &course, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QJsonDocument jsonDoc(course);

    QNetworkRequest request(routes->post_api_xcodeclazz_course_create());
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->application_json);
    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::updateCourse(const QJsonObject &course, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QJsonDocument jsonDoc(course);

    QNetworkRequest request(routes->post_api_xcodeclazz_course_update());
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->application_json);
    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::deleteCourse(const QString &courseId, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QJsonObject mainObject;
    mainObject.insert("courseId", courseId);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(routes->post_api_xcodeclazz_course_delete());
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->application_json);
    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

// NOTE: the code=? is valid for one call only, please make sure you mention this before user hit the oauth button
void Apis::exchangeGoogleOAuthCode(QString code, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    clearResponse();
    QByteArray postData;
    postData.append(QString("code=%1").arg(code));
    postData.append("&");
    postData.append(QString("client_id=%1").arg("926313063462-r1ua8s90db0tgghvpaitt7t96vku7svi.apps.googleusercontent.com"));
    postData.append("&");
    postData.append(QString("client_secret=%1").arg("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"));
    postData.append("&");
    postData.append(QString("redirect_uri=%1").arg("http%3A%2F%2F127.0.0.1:3003%2Fgoogle_oauth%2F"));
    postData.append("&");
    postData.append(QString("grant_type=%1").arg("authorization_code"));

    QNetworkRequest request(QUrl("https://oauth2.googleapis.com/token"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->url_encoded);

    QNetworkReply *mNetReply = mNetMan->post(request, postData);
    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

void Apis::exchangeGoogleAccessTokenForUserInfo(QString tokenType, QString accessToken, std::function<void (QByteArray)> response, std::function<void (QByteArray)> error)
{
    clearResponse();
    QNetworkRequest request(QUrl("https://www.googleapis.com/oauth2/v2/userinfo"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->url_encoded);
    request.setRawHeader("Authorization", QString("%1 %2").arg(tokenType).arg(accessToken).toLatin1());

    QNetworkReply *mNetReply = mNetMan->get(request);
    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=](/*OK*/){ response(*mDataBuffer); }, [=](QByteArray res){ error(res); });
    });
}

#include <QBuffer>
#include <QImage>
#include <QFile>

void Apis::uploadImages()
{
    QBuffer imgBuffer;
    imgBuffer.open(QIODevice::WriteOnly);

    QImage qp("C:/Users/Raisehand/Desktop/zzz/download.jpg");
    qp.save(&imgBuffer, "PNG");

    QBuffer fileBuffer;
    fileBuffer.open(QIODevice::WriteOnly);

    QFile *ff = new QFile("D:/Tutorials.txt");
    ff->open(QIODevice::ReadOnly);

    clearResponse();
    QJsonObject mainObject;
    mainObject.insert("image", (QString) imgBuffer.data().toBase64());
    mainObject.insert("text", (QString) ff->readAll().toBase64());

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(routes->post_test());
    request.setHeader(QNetworkRequest::ContentTypeHeader, _raw_headers->application_json);

    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());
    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        handleAllStatusCode(mNetReply, mDataBuffer, [=]( /*OK*/ ){
            qInfo() << *mDataBuffer;
        }, [=](QByteArray res){
            qInfo() << res;
        });
    });
}
