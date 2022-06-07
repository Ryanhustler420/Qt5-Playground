#include "controllers/allcoursespagecontroller.h"

AllCoursesPageController::AllCoursesPageController(QObject *parent) : QObject(parent)
{
    Signals::instance().onCourseDeleted([=](QJsonObject o) {
        emit courseDeleted(o);
    });
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
        QList<Course *> list = (new Course())->parseJSONArray(QJsonDocument::fromJson(response).object().value("courses").toArray());
        QJsonArray arr;
        for (int var = 0; var < list.length(); ++var) {
            arr.push_back(list[var]->getAsJson());
        }
        xdb.saveCourses(arr);
        emit coursesLoaded(arr.toVariantList());
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
