#ifndef SINGLECOURSEPAGECONTROLLER_H
#define SINGLECOURSEPAGECONTROLLER_H

#include "ipc/databridge.h"
#include "models/course.h"

class SingleCoursePageController : public QObject
{
    Q_OBJECT
public:
    explicit SingleCoursePageController(QObject *parent = nullptr);

signals:

};

#endif // SINGLECOURSEPAGECONTROLLER_H
