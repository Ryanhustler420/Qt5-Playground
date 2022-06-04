#ifndef ROUTES_H
#define ROUTES_H

#include "parents/commonsuperclass.h"
#include "application/manager.h"

static QString const host = Manager::instance().getCurrentHostUrl().url();

class Routes : public CommonSuperClass
{
public:
    explicit Routes(CommonSuperClass *parent = nullptr);
    // Routes() :           host("http://localhost:3002/")           {}; // https://stackoverflow.com/a/11594963

signals:

public:
    typedef struct URLS {
        QUrl *POST_API__INIT__ = new QUrl(host + "/__init__");
        QUrl *GET_API_XCODECLAZZ_STATUS_STUDENTS = new QUrl(host + "/api/xcodeclazz/status/students");
        QUrl *GET_API_XCODECLAZZ_STATUS_COURSES = new QUrl(host + "/api/xcodeclazz/status/courses");
        QUrl *GET_API_XCODECLAZZ_STATUS_REQUEST_CALLBACKS = new QUrl(host + "/api/xcodeclazz/status/request_callbacks");
        QUrl *GET_API_XCODECLAZZ_STUDENTS = new QUrl(host + "/api/xcodeclazz/students");

        QUrl *POST_API_XCODECLAZZ_STUDENT = new QUrl(host + "/api/xcodeclazz/student");
        QUrl *POST_API_XCODECLAZZ_STUDENT_CREATE = new QUrl(host + "/api/xcodeclazz/student/create");
        QUrl *POST_API_XCODECLAZZ_STUDENT_DELETE = new QUrl(host + "/api/xcodeclazz/student/delete");
        QUrl *POST_API_XCODECLAZZ_STUDENT_UPDATE = new QUrl(host + "/api/xcodeclazz/student/update");

        QUrl *GET_API_XCODECLAZZ_REQUEST_CALLBACKS = new QUrl(host + "/api/xcodeclazz/request_callbacks");
        QUrl *POST_API_XCODECLAZZ_REQUEST_CALLBACK = new QUrl(host + "/api/xcodeclazz/request_callback");
        QUrl *POST_API_XCODECLAZZ_REQUEST_CALLBACK_CREATE = new QUrl(host + "/api/xcodeclazz/request_callback/create");
        QUrl *POST_API_XCODECLAZZ_REQUEST_CALLBACK_DELETE = new QUrl(host + "/api/xcodeclazz/request_callback/delete");
        QUrl *POST_API_XCODECLAZZ_REQUEST_CALLBACK_DELETE_ALL = new QUrl(host + "/api/xcodeclazz/request_callback/delete/all");

        QUrl *GET_API_XCODECLAZZ_COURSES = new QUrl(host + "/api/xcodeclazz/courses");
        QUrl *POST_API_XCODECLAZZ_COURSE = new QUrl(host + "/api/xcodeclazz/course");
        QUrl *POST_API_XCODECLAZZ_COURSE_CREATE = new QUrl(host + "/api/xcodeclazz/course/create");
        QUrl *POST_API_XCODECLAZZ_COURSE_UPDATE = new QUrl(host + "/api/xcodeclazz/course/update");
        QUrl *POST_API_XCODECLAZZ_COURSE_DELETE = new QUrl(host + "/api/xcodeclazz/course/delete");
    } urls;

    struct Enums {
        urls _urls;
    };

    Enums *enums;

public:
    QUrl get_host_url() const;

    QUrl post_api__init__() const;
    QUrl get_api_xcodeclazz_status_students() const;
    QUrl get_api_xcodeclazz_status_courses() const;
    QUrl get_api_xcodeclazz_status_request_callbacks() const;
    QUrl get_api_xcodeclazz_students() const;

    QUrl post_api_xcodeclazz_student() const;
    QUrl post_api_xcodeclazz_student_create() const;
    QUrl post_api_xcodeclazz_student_delete() const;
    QUrl post_api_xcodeclazz_student_update() const;

    QUrl get_api_xcodeclazz_request_callbacks() const;
    QUrl post_api_xcodeclazz_request_callback() const;
    QUrl post_api_xcodeclazz_request_callback_create() const;
    QUrl post_api_xcodeclazz_request_callback_delete() const;
    QUrl post_api_xcodeclazz_request_callback_delete_all() const;

    QUrl get_api_xcodeclazz_courses() const;
    QUrl post_api_xcodeclazz_course() const;
    QUrl post_api_xcodeclazz_course_create() const;
    QUrl post_api_xcodeclazz_course_update() const;
    QUrl post_api_xcodeclazz_course_delete() const;
};

#endif // ROUTES_H
