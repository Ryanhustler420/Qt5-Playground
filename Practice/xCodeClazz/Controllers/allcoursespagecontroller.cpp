#include "controllers/allcoursespagecontroller.h"

AllCoursesPageController::AllCoursesPageController(QObject *parent) : QObject(parent)
{
}

void AllCoursesPageController::hold(QString title, QString subtitle, QString duration, QString thumbnailUrl, QString imageContainer, QList<QString> features, int price, bool hasActive, int spaceLeft, int spaceFull, QString starts, QString ends)
{
    Course course;
    course.setTitle(title);
    course.setSubtitle(subtitle);
    course.setDuration(duration);
    course.setThumbnailUrl(thumbnailUrl);
    course.setImageContainer(imageContainer);
    course.setFeatures(&features);
    course.setPrice(price);
    course.setHasActive(hasActive);
    course.setSpaceLeft(spaceLeft);
    course.setSpaceFull(spaceFull);
    course.setSession(new Session(starts, ends));

    DataBridge::instance().setCourse(&course);
}

void AllCoursesPageController::loadCourses()
{
    // get the data from the internet and emit an event which will render the data in view
    // if already present the data in local then get that in the first place.

    // we will make google like design for shop keeper to check the product exstence across the city

    apis.getCourses([=](QByteArray response){
        qInfo() << QJsonDocument::fromJson(response).object();
        emit coursesLoaded(QVariantList());
    }, [=](QByteArray error){
        qWarning() << error;
    });
}
