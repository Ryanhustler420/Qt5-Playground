#include "controllers/allcoursespagecontroller.h"

AllCoursesPageController::AllCoursesPageController(QObject *parent) : QObject(parent)
{
}

void AllCoursesPageController::hold(QVariant o)
{
    emit holded(o);
    lc.save("Course", o);
}

void AllCoursesPageController::loadCourses()
{
    apis.getCourses([=](QByteArray response){
        Course *m = new Course();
        QList<Course *> list = m->parseJSONArray(QJsonDocument::fromJson(response).object().value("courses").toArray());
        QVariantList m_list = m->parseJSONArrayToVariantList(QJsonDocument::fromJson(response).object().value("courses").toArray());
        emit coursesLoaded(m_list);
    }, [=](QByteArray error){
        qWarning() << error;
    });
}
