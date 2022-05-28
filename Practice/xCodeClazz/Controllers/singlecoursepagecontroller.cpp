#include "controllers/singlecoursepagecontroller.h"

SingleCoursePageController::SingleCoursePageController(QObject *parent) : QObject(parent)
{
    bundle = QJsonDocument::fromJson(lc.get("Course").toByteArray()).object();

    // we will make google like design for shop keeper to check the product exstence across the city

    // get the data from the internet and emit an event which will render the data in view
    // if already present the data in local then get that in the first place

    // goal is to render the details on page after it fetchs from server
    // start loading the ui using busy indicator and when fetch emit a signal
    // and render the data

    // get the data from id
    QString _id = bundle.value("_id").toString();

    // get the data from internet
    apis.getCourse(_id, [=](QByteArray response){
        QJsonObject doc = QJsonDocument::fromJson(response).object();
        // send the data to UI
        emit dataReady(QVariant(doc));
    }, [=](QByteArray error){
        qInfo() << error;
    });

}

void SingleCoursePageController::deleteCourse(QString _id)
{
    qInfo() << _id;
    // send delete request and emit
    // update the local data
    // redirect back
}
