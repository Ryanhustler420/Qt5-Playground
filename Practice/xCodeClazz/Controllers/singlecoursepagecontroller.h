#ifndef SINGLECOURSEPAGECONTROLLER_H
#define SINGLECOURSEPAGECONTROLLER_H

#include "models/course.h"
#include "database/localcache.h"

class SingleCoursePageController : public QObject
{
    Q_OBJECT
public:
    explicit SingleCoursePageController(QObject *parent = nullptr);

signals:

private:
    LocalCache lc;

};

#endif // SINGLECOURSEPAGECONTROLLER_H
