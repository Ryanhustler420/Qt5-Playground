#ifndef SINGLECOURSEPAGECONTROLLER_H
#define SINGLECOURSEPAGECONTROLLER_H

#include "models/course.h"
#include "networking/apis.h"
#include "utility/jsonhelper.h"
#include "database/localcache.h"

class SingleCoursePageController : public QObject
{
    Q_OBJECT
public:
    explicit SingleCoursePageController(QObject *parent = nullptr);

    Q_INVOKABLE void deleteCourse(QString _id);

signals:
    void dataReady(QVariant o);
    void courseDeleted(QString _id);

private:
    Apis apis;
    LocalCache lc;
    QJsonObject bundle;

};

#endif // SINGLECOURSEPAGECONTROLLER_H
