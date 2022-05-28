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
    // we will make google like design for shop keeper to check the product exstence across the city

    // get the data from the internet and emit an event which will render the data in view
    // if already present the data in local then get that in the first place

    apis.getCourses([=](QByteArray response){
        Course *m = new Course();
        QList<Course *> list = m->parseJSONArray(QJsonDocument::fromJson(response).object().value("courses").toArray());
        QVariantList m_list = m->parseJSONArrayToVariantList(QJsonDocument::fromJson(response).object().value("courses").toArray());
        emit coursesLoaded(m_list);
    }, [=](QByteArray error){
        qWarning() << error;
    });
}
