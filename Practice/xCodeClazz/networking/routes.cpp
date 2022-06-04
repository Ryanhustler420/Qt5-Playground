#include "networking/routes.h"

Routes::Routes(CommonSuperClass *parent) : CommonSuperClass(parent), enums(new Enums) {}

QUrl Routes::get_host_url() const { return host; }

QUrl Routes::post_api__init__() const { return *enums->_urls.POST_API__INIT__; }
QUrl Routes::get_api_xcodeclazz_status_students() const { return *enums->_urls.GET_API_XCODECLAZZ_STATUS_STUDENTS; }
QUrl Routes::get_api_xcodeclazz_status_courses() const { return *enums->_urls.GET_API_XCODECLAZZ_STATUS_COURSES; }
QUrl Routes::get_api_xcodeclazz_status_request_callbacks() const { return *enums->_urls.GET_API_XCODECLAZZ_STATUS_REQUEST_CALLBACKS; }
QUrl Routes::get_api_xcodeclazz_students() const { return *enums->_urls.GET_API_XCODECLAZZ_STUDENTS; }

QUrl Routes::post_api_xcodeclazz_student() const { return *enums->_urls.POST_API_XCODECLAZZ_STUDENT; }
QUrl Routes::post_api_xcodeclazz_student_create() const { return *enums->_urls.POST_API_XCODECLAZZ_COURSE_CREATE; }
QUrl Routes::post_api_xcodeclazz_student_delete() const { return *enums->_urls.POST_API_XCODECLAZZ_COURSE_DELETE; }
QUrl Routes::post_api_xcodeclazz_student_update() const { return *enums->_urls.POST_API_XCODECLAZZ_COURSE_UPDATE; }

QUrl Routes::get_api_xcodeclazz_request_callbacks() const { return *enums->_urls.GET_API_XCODECLAZZ_REQUEST_CALLBACKS;  }
QUrl Routes::post_api_xcodeclazz_request_callback() const { return *enums->_urls.POST_API_XCODECLAZZ_REQUEST_CALLBACK; }
QUrl Routes::post_api_xcodeclazz_request_callback_create() const { return *enums->_urls.POST_API_XCODECLAZZ_REQUEST_CALLBACK_CREATE; }
QUrl Routes::post_api_xcodeclazz_request_callback_delete() const { return *enums->_urls.POST_API_XCODECLAZZ_REQUEST_CALLBACK_DELETE; }
QUrl Routes::post_api_xcodeclazz_request_callback_delete_all() const { return *enums->_urls.POST_API_XCODECLAZZ_REQUEST_CALLBACK_DELETE_ALL; }

QUrl Routes::get_api_xcodeclazz_courses() const { return *enums->_urls.GET_API_XCODECLAZZ_COURSES; }
QUrl Routes::post_api_xcodeclazz_course() const { return *enums->_urls.POST_API_XCODECLAZZ_COURSE; }
QUrl Routes::post_api_xcodeclazz_course_create() const { return *enums->_urls.POST_API_XCODECLAZZ_COURSE_CREATE; }
QUrl Routes::post_api_xcodeclazz_course_update() const { return *enums->_urls.POST_API_XCODECLAZZ_COURSE_UPDATE; }
QUrl Routes::post_api_xcodeclazz_course_delete() const { return *enums->_urls.POST_API_XCODECLAZZ_COURSE_DELETE; }
