#include "controllers/singlecoursepagecontroller.h"

SingleCoursePageController::SingleCoursePageController(QObject *parent) : QObject(parent)
{
    qInfo() << lc.get("Course").toString() << "Received";
}
