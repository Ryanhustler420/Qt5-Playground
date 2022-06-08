#include "controllers/singlecoursepagecontroller.h"

SingleCoursePageController::SingleCoursePageController(QObject *parent) : QObject(parent)
{
}

void SingleCoursePageController::pass(QVariant o)
{

}

void SingleCoursePageController::loadCourse()
{
    loaded_course = QJsonDocument::fromJson(lc.get("Course").toByteArray()).object();
    QString _id = loaded_course.value("_id").toString();

    emit showLoading(true);
    apis.getCourse(_id, [=](QByteArray response){
        doc = QJsonDocument::fromJson(response).object().value("course").toObject();
        if (doc.empty()) {
            emit goBack();
        }
        emit showLoading(false);
        emit courseLoaded(QVariant(doc));
    }, [=](QByteArray error){
        emit showLoading(false);
        emit goBack();
        qInfo() << error;
    });
}

void SingleCoursePageController::deleteCourse()
{
    emit showLoading(true);
    QString _id = doc.value("_id").toString();
    apis.deleteCourse(_id, [=](QByteArray response){
        // qInfo() << QJsonDocument::fromJson(response).object();
        emit showLoading(false);
        if (xdb.deleteCourse(_id)) {
            emit Signals::instance().deleteCourse(doc);
            emit goBack();
        }
    },[=](QByteArray error){
        emit showLoading(false);
        qInfo() << error;
    });
}

void SingleCoursePageController::listViewReachedBottom(QVariant o)
{
    emit listViewReached(o);
}

void SingleCoursePageController::scrollViewReachedBottom(QVariant o)
{
    emit scrollViewReached(o);
}

void SingleCoursePageController::updateCourse(QJsonObject o)
{
    emit showLoading(true);
    o.insert("courseId", loaded_course.value("_id").toString());
    apis.updateCourse(o, [=](QByteArray response){
        emit showLoading(false);
        if (xdb.updateCourse(o)) {
            emit goBack();
        }
    }, [=](QByteArray error){
        emit showLoading(false);
        qInfo() << error;
    });
}
