#include "controllers/allcoursespagecontroller.h"

AllCoursesPageController::AllCoursesPageController(QObject *parent) : QObject(parent)
{
}

void AllCoursesPageController::pass(QVariant o)
{
    emit passed(o);
    lc.save("Course", o);
}

void AllCoursesPageController::loadCourses()
{
    emit showLoading(true);
    apis.getCourses([=](QByteArray response){
        Course *m = new Course();
        QList<Course *> list = m->parseJSONArray(QJsonDocument::fromJson(response).object().value("courses").toArray());
        QVariantList m_list = m->parseJSONArrayToVariantList(QJsonDocument::fromJson(response).object().value("courses").toArray());
        emit coursesLoaded(m_list);
        emit showLoading(false);
    }, [=](QByteArray error){
        emit showLoading(false);
        qWarning() << error;
    });
}

void AllCoursesPageController::createNewCourse(QJsonObject o)
{
    emit showLoading(true);
    o.insert("imageContainer", "raisehand");
    apis.createCourse(o, [=](QByteArray response){
        QJsonObject doc = QJsonDocument::fromJson(response).object().value("document").toObject();
        xdb.saveCourse(doc);
        emit showLoading(false);
        emit newCourseCreated(doc);
    }, [=](QByteArray error){
        emit showLoading(false);
        qWarning() << error;
    });
}

void AllCoursesPageController::listViewReachedBottom(QVariant o)
{
    emit listViewReached(o);
}

void AllCoursesPageController::scrollViewReachedBottom(QVariant o)
{
    emit scrollViewReached(o);
}
