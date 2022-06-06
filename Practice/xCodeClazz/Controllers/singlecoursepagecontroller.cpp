#include "controllers/singlecoursepagecontroller.h"

SingleCoursePageController::SingleCoursePageController(QObject *parent) : QObject(parent)
{
}

void SingleCoursePageController::pass(QVariant o)
{

}

void SingleCoursePageController::loadCourse()
{
    QJsonObject bundle = QJsonDocument::fromJson(lc.get("Course").toByteArray()).object();

    // get the data from id
    QString _id = bundle.value("_id").toString();

    // get the data from internet
    apis.getCourse(_id, [=](QByteArray response){
        QJsonObject doc = QJsonDocument::fromJson(response).object();
        emit courseLoaded(QVariant(doc));
    }, [=](QByteArray error){
        qInfo() << error;
    });
}

void SingleCoursePageController::deleteCourse(QJsonObject o)
{
    qInfo() << o;

    // qInfo() << _id;
    // send delete request and emit
    // update the local data
    // redirect back
}

void SingleCoursePageController::listViewReachedBottom(QVariant o)
{
    emit listViewReached(o);
}

void SingleCoursePageController::scrollViewReachedBottom(QVariant o)
{
    emit scrollViewReached(o);
}
