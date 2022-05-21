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
